import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic

#UI파일 연결
#단, UI파일은 Python 코드 파일과 같은 디렉토리에 위치해야한다.
form_class = uic.loadUiType("main_window.ui")[0]

#화면을 띄우는데 사용되는 Class 선언
class WindowClass(QMainWindow, form_class) :
    def __init__(self) :
        super().__init__()
        self.setupUi(self)
        self.btn_1.clicked.connect(self.button1Function)
        self.btn_2.clicked.connect(self.button2Function)

    def button1Function(self):
        self.let_id.setText("btn_1이 클릭 되었습니다.")
        QMessageBox.warning(self,"경고","취소 버튼입니다.")
        self.let_id.setText("")
        self.let_pw.setText("")
        self.let_nick.setText("")

    def button2Function(self):
        id = self.let_id.text()
        pw = self.let_pw.text()
        name=self.let_nick.text()
        result= f"id:{id}, pw:{pw}, name:{name}"
        print(result)
        QMessageBox.information(self,"가입을 환영합니다.",result)

if __name__ == "__main__" :
    #QApplication : 프로그램을 실행시켜주는 클래스
    app = QApplication(sys.argv)

    #WindowClass의 인스턴스 생성
    myWindow = WindowClass()

    #프로그램 화면을 보여주는 코드
    myWindow.show()

    #프로그램을 이벤트루프로 진입시키는(프로그램을 작동시키는) 코드
    app.exec_()