import sys,json
from PyQt6.QtWidgets import QApplication, QMainWindow, QWidget, QGridLayout, QPushButton, QVBoxLayout, QMessageBox,QColorDialog,QFileDialog,QLabel,QHBoxLayout,QLineEdit
from PyQt6.QtCore import QSize,Qt
from PyQt6.QtGui import QAction,QPixmap
class SmallGrid(QWidget):
    def __init__(self, parent, row, col):
        super().__init__(parent)
        self.layout = QGridLayout()
        self.buttons = [[QPushButton() for _ in range(3)] for _ in range(3)]
        self.parent = parent
        self.winner = None
        self.row = row
        self.col = col
        self.button1 = QPushButton()
        self.button1.setFixedSize(QSize(150,150))
        self.button1.setVisible(False)
        self.layout.addWidget(self.button1)
        for i in range(3):
            for j in range(3):
                button = self.buttons[i][j]
                button.setFixedSize(QSize(50, 50))
                button.setStyleSheet("font-size: 20px;")
                button.clicked.connect(lambda _, row=i, col=j: self.handle_click(row, col))
                self.layout.addWidget(button, i, j)
        self.setLayout(self.layout)
        self.setEnabled(False)

    def handle_click(self, row, col):
        if self.buttons[row][col].text() == "" and self.winner is None:
            if self.parent.active_grid is None or self.parent.active_grid == (self.row, self.col):
                self.buttons[row][col].setText(self.parent.current_player)
                self.buttons[row][col].setStyleSheet(f"color: {self.parent.get_current_player_color()}; font-size: 20px;")
                if self.check_winner(row, col):
                    self.winner = self.parent.current_player
                    self.delete_grid()
                    self.disable_grid()
                    self.parent.check_overall_winner()
                elif self.check_draw(row, col):
                    msg = QMessageBox()
                    msg.setText(f"No one wins!")
                    msg.exec()
                    self.parent.reset_game()

                self.parent.switch_player()
                self.parent.set_next_active_grid(row, col)

    def delete_grid(self):
        for i in range(3):
            for j in range(3):
                if self.winner:
                    self.buttons[i][j].setVisible(False)
        self.button1.setVisible(True)
        self.button1.setText(self.winner)
        self.button1.setEnabled(False)
        self.button1.setStyleSheet(f"color: {self.parent.get_color(self.winner)}; font-size: 60px;")
        

    def update_grid(self):
        for i in range(3):
            for j in range(3):
                if self.winner:
                    self.buttons[i][j].setText(self.winner)
                    self.buttons[i][j].setStyleSheet(f"color: {self.parent.get_color(self.winner)}; font-size: 20px;")

    def check_empty(self):
        for i in range (3):
            if not all(self.buttons[i][j].text() for j in range (3)):
                return True
        return False

    def check_winner(self, row, col):
        player = self.parent.current_player
        if all(self.buttons[row][i].text() == player for i in range(3)):
            return True
        if all(self.buttons[i][col].text() == player for i in range(3)):
            return True
        if row == col and all(self.buttons[i][i].text() == player for i in range(3)):
            return True
        if row + col == 2 and all(self.buttons[i][2-i].text() == player for i in range(3)):
            return True
        return False


    def check_draw(self, row, col):
        if not self.check_winner(row, col) and not self.check_empty():
            return True
        return False
    
    
    def disable_grid(self):
        for i in range(3):
            for j in range(3):
                self.buttons[i][j].setEnabled(False)

    def enable_grid(self):
        for i in range(3):
            for j in range(3):
                if self.buttons[i][j].text() == "":
                    self.buttons[i][j].setEnabled(True)
    



class MainGame(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Metal Gear Rising: Revengeance")
        self.current_player = "X"
        self.colors = {"X": "black", "O": "black"}
        self.nick1 = ""
        self.nick2 = ""
        self.central_widget = QWidget()
        self.main_layout = QHBoxLayout(self.central_widget)
        self.game_layout = QVBoxLayout()
        self.grid_layout = QGridLayout()
        self.small_grids = [[SmallGrid(self, i, j) for j in range(3)] for i in range(3)]
        for i in range(3):
            for j in range(3):
                self.grid_layout.addWidget(self.small_grids[i][j], i, j)
        self.game_layout.addLayout(self.grid_layout)
    
        self.left_layout = QVBoxLayout()   
        self.input1nickname = QLineEdit()
        self.input1nickname.setFixedWidth(150)
        self.nickname1button=QPushButton("Set nickname")
        self.nickname1button.clicked.connect(self.get1nick)
        self.player1button=QPushButton("Load an image")
        self.player1button.clicked.connect(self.load1image)
        self.player1image = QLabel()
        self.player1image.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.player1image.setFixedSize(200, 200)
        self.left_layout.addWidget(self.player1button)
        self.left_layout.addWidget(self.player1image)
        self.left_layout.addWidget(self.input1nickname, alignment= Qt.AlignmentFlag.AlignCenter) 
        self.left_layout.addWidget(self.nickname1button)

        self.right_layout = QVBoxLayout() 
        self.input2nickname = QLineEdit()
        self.input2nickname.setFixedWidth(150)   
        self.nickname2button=QPushButton("Set nickname")
        self.nickname2button.clicked.connect(self.get2nick)
        self.player2button=QPushButton("Load an image")
        self.player2button.clicked.connect(self.load2image)
        self.player2image = QLabel()
        self.player2image.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.player2image.setFixedSize(200, 200)
        self.right_layout.addWidget(self.player2button)
        self.right_layout.addWidget(self.player2image)
        self.right_layout.addWidget(self.input2nickname, alignment= Qt.AlignmentFlag.AlignCenter) 
        self.right_layout.addWidget(self.nickname2button)

        self.start_button = QPushButton("Start")
        self.start_button.clicked.connect(self.start_game)
        self.game_layout.addWidget(self.start_button)
        self.game_layout.addLayout(self.grid_layout)


        self.main_layout.addLayout(self.left_layout)
        self.main_layout.addLayout(self.game_layout)
        self.main_layout.addLayout(self.right_layout)
        
        self.setCentralWidget(self.central_widget)
        self.active_grid = None
        
        self.set_all_grids_active()
        menu=self.menuBar()

        self.button_action1 = QAction("&Save", self)
        self.button_action1.triggered.connect(self.savegame)

        self.button_action2 = QAction("&Load", self)
        self.button_action2.triggered.connect(self.loadgame)

        self.button_action3=QAction("&Change X colour",self)
        self.button_action3.triggered.connect(self.change_x_color)
        self.button_action4=QAction("&Change O colour",self)
        self.button_action4.triggered.connect(self.change_o_color)

        file_menu1 = menu.addMenu("&File")
        file_menu1.addAction(self.button_action1)
        file_menu1.addAction(self.button_action2)

        file_menu2 = menu.addMenu("&Style")
        file_menu2.addAction(self.button_action3)
        file_menu2.addAction(self.button_action4)

    def load1image(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Open Image", "", "Image Files (*.png *.jpg *.bmp)")
        if file_name:
            pixmap = QPixmap(file_name)
            self.player1image.setPixmap(pixmap.scaled(self.player1image.size(), Qt.AspectRatioMode.KeepAspectRatio))
    
    def get1nick(self):
        self.nick1=self.input1nickname.text()
    
    def get2nick(self):
        self.nick2=self.input2nickname.text()

    def load2image(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Open Image", "", "Image Files (*.png *.jpg *.bmp)")
        if file_name:
            pixmap = QPixmap(file_name)
            self.player2image.setPixmap(pixmap.scaled(self.player2image.size(), Qt.AspectRatioMode.KeepAspectRatio))

    def set_grids_enabled(self, enabled):
        for row in self.small_grids:
            for grid in row:
                grid.setEnabled(enabled)

    
    def start_game(self):
        self.active_grid = None
        self.update_active_grids()
        self.set_grids_enabled(True)
        

        self.start_button.setEnabled(False)   
        self.player1button.setEnabled(False)
        self.nickname1button.setEnabled(False)
        self.nickname2button.setEnabled(False)
        self.input1nickname.setEnabled(False)
        self.input2nickname.setEnabled(False)
        self.player2button.setEnabled(False)
        self.button_action3.setEnabled(False)
        self.button_action4.setEnabled(False)
        

    def change_x_color(self):
        color = QColorDialog.getColor()
        if color.isValid():
            self.colors["X"] = color.name()  

            
    def get_current_player_color(self):
        return self.colors[self.current_player]

    def get_color(self, player):
        return self.colors[player]

    def change_o_color(self):
        color = QColorDialog.getColor()
        if color.isValid():
            self.colors["O"] = color.name()        

    def set_all_grids_active(self):
        for row in self.small_grids:
            for grid in row:
                grid.enable_grid()

    def set_next_active_grid(self, row, col):
        if self.small_grids[row][col].winner is None and not self.is_grid_full(self.small_grids[row][col]):
            self.active_grid = (row, col)
        else:
            self.active_grid = None
        self.update_active_grids()

    def update_active_grids(self):
        if self.active_grid:
            for i in range(3):
                for j in range(3):
                    if (i, j) == self.active_grid:
                        self.small_grids[i][j].enable_grid()
                    else:
                        self.small_grids[i][j].disable_grid()
        else:
            self.set_all_grids_active()


    def switch_player(self):
        self.current_player = "O" if self.current_player == "X" else "X"

    def check_overall_winner(self):
        for i in range(3):
            if self.small_grids[i][0].winner == self.small_grids[i][1].winner == self.small_grids[i][2].winner and self.small_grids[i][0].winner is not None:
                self.declare_winner(self.small_grids[i][0].winner)
                return
            if self.small_grids[0][i].winner == self.small_grids[1][i].winner == self.small_grids[2][i].winner and self.small_grids[0][i].winner is not None:
                self.declare_winner(self.small_grids[0][i].winner)
                return
        if self.small_grids[0][0].winner == self.small_grids[1][1].winner == self.small_grids[2][2].winner and self.small_grids[0][0].winner is not None:
            self.declare_winner(self.small_grids[0][0].winner)
            return
        if self.small_grids[0][2].winner == self.small_grids[1][1].winner == self.small_grids[2][0].winner and self.small_grids[0][2].winner is not None:
            self.declare_winner(self.small_grids[0][2].winner)
            return

    def declare_winner(self, winner):
        msg = QMessageBox()
        if self.nick1=="" :
            self.nick1="X"
        if self.nick2=="":
            self.nick2="O"    
        msg.setText(f"Player {self.nick1 if winner == 'X' else self.nick2} wins!")
        msg.exec()
        self.reset_game()

    def reset_game(self):
        self.current_player = "X"
        for row in self.small_grids:
            for grid in row:
                grid.button1.setVisible(False)
                for i in range(3):
                    for j in range(3):
                        grid.buttons[i][j].setVisible(True)
                        grid.buttons[i][j].setText("")
                        grid.buttons[i][j].setEnabled(True)
                grid.winner = None
        
        self.active_grid = None
        self.set_all_grids_active()
        self.set_grids_enabled(False)
        self.start_button.setEnabled(True)  
        self.player1button.setEnabled(True)
        self.nickname1button.setEnabled(True)
        self.nickname2button.setEnabled(True)
        self.input1nickname.setEnabled(True)
        self.input2nickname.setEnabled(True)
        self.player2button.setEnabled(True)

    def loadgame(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Load Game", "", "JSON Files (*.json)")
        if file_name:
            with open(file_name, 'r') as file:
                saved = json.load(file)
                self.reset_game()
                self.current_player=saved["player"]
                self.colors=saved["colors"]
                self.nick1=saved["nick1"]
                self.nick2=saved["nick2"]
                self.active_grid=saved["active"] 
                self.update_active_grids()
                self.set_grids_enabled(True)
                self.start_button.setEnabled(False)   
                self.player1button.setEnabled(False)
                self.nickname1button.setEnabled(False)
                self.nickname2button.setEnabled(False)
                self.input1nickname.setEnabled(False)
                self.input2nickname.setEnabled(False)
                self.player2button.setEnabled(False)
                self.xcolor=saved["colors"]["X"]
                self.ocolor=saved["colors"]["O"]
                self.set_next_active_grid(self.active_grid[0],self.active_grid[1])
                for i in range(3):
                    for j in range(3):
                        self.small_grids[i][j].button1.setText(saved["grids"][i][j]["button1"])
                        self.small_grids[i][j].winner=saved["grids"][i][j]["winner"]
                        if self.small_grids[i][j].button1.text()=="X":
                            self.small_grids[i][j].button1.setStyleSheet(f"color:{ self.xcolor}; font-size: 60px;")
                        if self.small_grids[i][j].button1.text()=="O":
                            self.small_grids[i][j].button1.setStyleSheet(f"color: {self.ocolor}; font-size: 60px;")
                        for l in range(3):
                            for m in range(3):
                                self.small_grids[i][j].buttons[l][m].setText(saved["grids"][i][j]["buttons"][l][m])
                                if self.small_grids[i][j].buttons[l][m].text()=="X":
                                    self.small_grids[i][j].buttons[l][m].setStyleSheet(f"color:{ self.xcolor}; font-size: 20px;")
                                if self.small_grids[i][j].buttons[l][m].text()=="O":
                                    self.small_grids[i][j].buttons[l][m].setStyleSheet(f"color: {self.ocolor}; font-size: 20px;") 
                        if saved["grids"][i][j]["button1"]!="":
                            self.small_grids[i][j].button1.setVisible(True)
                            self.small_grids[i][j].button1.setEnabled(False)
                            for l in range(3):
                                for m in range(3):
                                    self.small_grids[i][j].buttons[l][m].setVisible(False)

                self.update()


    def savegame(self):
        saved = {
            "nick1": self.nick1,
            "nick2": self.nick2,
            "colors": self.colors,
            "player": self.current_player,
            "grids": [[self.gridstate(grid) for grid in row] for row in self.small_grids],
            "active": self.active_grid
        }
        file_name, _ = QFileDialog.getSaveFileName(self, "Save Game", "", "JSON Files (*.json)")
        if file_name:
            with open(file_name, 'w') as file:
                json.dump(saved, file)



    def gridstate(self,grid):
        return {
            "winner": grid.winner,
            "buttons": [[btn.text() for btn in row] for row in grid.buttons],
            "button1": grid.button1.text(),
        }

    def is_grid_full(self, grid):
        for i in range(3):
            for j in range(3):
                if grid.buttons[i][j].text() == "":
                    return False
        return True


app = QApplication(sys.argv)
main_game = MainGame()
main_game.show()
sys.exit(app.exec())