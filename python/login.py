import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5.QtGui import *


#UI파일 연결
#단, UI파일은 Python 코드 파일과 같은 디렉토리에 위치해야한다.
form_class = uic.loadUiType("login.ui")[0]

#화면을 띄우는데 사용되는 Class 선언
class WindowClass(QWidget, form_class) :
    def __init__(self) :
        super().__init__()
        self.setupUi(self)
        self.stackedWidget.setCurrentIndex(3)
        self.btn_join.clicked.connect(self.moveJoinPage)
        self.btn_cancel.clicked.connect(self.moveLoginPage)
        self.btn_login.clicked.connect(self.bt1F)
        self.btn_create.clicked.connect(self.bt2F)
        self.go_zero.clicked.connect(self.moveLoginPage)


        #버튼클릭 이벤트와 함수 연결
        self.btn_add.clicked.connect(self.addListWidget)
        self.btn_insert.clicked.connect(self.insertListWidget)
        self.btn_clear.clicked.connect(self.clearListWidget)
        self.btn_remove.clicked.connect(self.removeListWidget)
        self.btn_print.clicked.connect(self.printCurrentItem)
        self.btn_printM.clicked.connect(self.printMultiItem)

        self.btn_PTE.clicked.connect(self.PTE)
        self.btn_CTE.clicked.connect(self.CTE)
        self.btn_SF.clicked.connect(self.SF)
        self.btn_SFI.clicked.connect(self.SFI)
        self.btn_SFCR.clicked.connect(self.SFCR)
        self.Spin_FS.valueChanged.connect(self.FS)

    def FS(self):
        self.fontSize = self.Spin_FS.value()
        self.textEdit.setFontPointSize(self.fontSize)

    def SFCR(self):
        colorvar = QColor(255,0,0)
        self.textEdit.setTextColor(colorvar)

    def SFI(self):
        self.textEdit.setFontItalic(True)

    def SF(self):
        fontvar = QFont("Ubuntu Condensed", 10)
        self.textEdit.setCurrentFont(fontvar)

    def PTE(self):
        print(self.textEdit.toPlainText())

    def CTE(self):
        self.textEdit.clear()

    def printCurrentItem(self):
        print(self.listWidget.currentItem().text())


    def printMultiItem(self):
        self.selectedItems = self.listWidget.selectedItems()
        for item in self.selectedItems:
            print(item.text())

    #ListWidget에 LineEdit에서 입력한 text를 추가하는 함수
    def addListWidget(self):
        self.led_addText = self.let_add.text()
        self.listWidget.addItem(self.led_addText)

    def insertListWidget(self):
        self.insertRow = self.spin_insertRow.value()
        self.insertText = self.let_insert.text()
        self.listWidget.insertItem(self.insertRow, self.insertText)

    def clearListWidget(self):
        self.listWidget.clear()

    def removeListWidget(self):
        self.listRow = self.listWidget.currentRow()
        self.listWidget.takeItem(self.listRow)


    def moveJoinPage(self):
        self.stackedWidget.setCurrentIndex(1)

    def moveLoginPage(self):
        self.stackedWidget.setCurrentIndex(0)

    def bt1F(self):
        put_id = self.guard_id.text()
        put_pw = self.guard_pw.text()
        if id == put_id:
            if pw == put_pw:
                self.stackedWidget.setCurrentIndex(2)
            else:
                QMessageBox.warning(self, "오류", "비밀번호가 틀렸습니다.")
        else:
            QMessageBox.warning(self, "오류", "없는 아이디 입니다.")

    def bt2F(self):
        global id
        global pw
        id = self.let_id.text()
        pw = self.let_pw.text()
        name=self.let_nick.text()
        result= f"id:{id}, pw:{pw}, name:{name}"
        print(result)
        QMessageBox.information(self,"가입을 환영합니다.",result)
        self.stackedWidget.setCurrentIndex(0)

if __name__ == "__main__" :
    #QApplication : 프로그램을 실행시켜주는 클래스
    app = QApplication(sys.argv)

    #WindowClass의 인스턴스 생성
    myWindow = WindowClass()

    #프로그램 화면을 보여주는 코드
    myWindow.show()

    #프로그램을 이벤트루프로 진입시키는(프로그램을 작동시키는) 코드
    app.exec_()