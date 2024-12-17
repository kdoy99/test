import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic

#UI파일 연결
#단, UI파일은 Python 코드 파일과 같은 디렉토리에 위치해야한다.
form_class = uic.loadUiType("CoffeeKiosk.ui")[0]

#화면을 띄우는데 사용되는 Class 선언
class WindowClass(QMainWindow, form_class) :
    def __init__(self) :
        super().__init__()
        self.setupUi(self)
        self.stackedWidget.setCurrentIndex(0)
        self.OP_g=0
        self.SC=[]
        self.Stamp_id_total=[] #입력 받은 신규 스탬프 아이디 저장, 인덱스값 돌려받아서 딕셔너리에 집어넣으면 스탬프 개수 확인 가능
        self.Stamp_id_stamp={} #스탬프 아이디 별 스탬프 개수 딕셔너리
        self.SN_number=[] #현재 스탬프 아이디
        self.ResearchPass=0 # 스탬프 조회 여부, 1일시에 통과한 것
        self.OrderNumber = 1 # 포장 주문번호
        self.In_OrderNumber = 1 # 매장 이용 주문번호
        self.Takeout_List = 0 # 포장 고를시 변수 저장
        self.Inside_List = 0 # 매장 고를시 변수 저장

#버튼 클릭 함수
        # 페이지 1
        self.btn_inside.clicked.connect(self.move1_Inside)
        self.btn_takeout.clicked.connect(self.move1_takeout)
        self.btn_home.clicked.connect(self.move0)
        self.btn_ice_coffee.clicked.connect(self.icecoffeeBasket)
        self.btn_hot_coffee.clicked.connect(self.hotcoffeeBasket)
        self.btn_ice_latte.clicked.connect(self.icelatteBasket)
        self.btn_hot_latte.clicked.connect(self.hotlatteBasket)
        self.btn_ice_vanilla.clicked.connect(self.icevanillaBasket)
        self.btn_hot_vanilla.clicked.connect(self.hotvanillaBasket)
        self.btn_ice_ssangtea.clicked.connect(self.icessangteaBasket)
        self.btn_hot_ssangtea.clicked.connect(self.hotssangteaBasket)
        self.btn_ice_daechutea.clicked.connect(self.icedaechuteaBasket)
        self.btn_hot_daechutea.clicked.connect(self.hotdaechuteaBasket)
        self.btn_ade.clicked.connect(self.adeBasket)
        self.btn_misutgaru.clicked.connect(self.misutgaruBasket)
        self.btn_plain.clicked.connect(self.plainBasket)
        self.btn_strawberry.clicked.connect(self.strawberryBasket)
        self.btn_blueberry.clicked.connect(self.blueberryBasket)
        self.btn_mango.clicked.connect(self.mangoBasket)
        self.btn_ggal.clicked.connect(self.ggalBasket)
        self.btn_lime.clicked.connect(self.limeBasket)
        self.btn_shu.clicked.connect(self.shuBasket)
        self.btn_icecream.clicked.connect(self.icecreamBasket)
        self.btn_salad.clicked.connect(self.saladBasket)
        self.btn_burn.clicked.connect(self.burnBasket)
        self.btn_sand.clicked.connect(self.sandBasket)
        self.btn_sausage.clicked.connect(self.sausageBasket)

        # 페이지 2
        self.btn_home.clicked.connect(self.goHome)
        self.btn_cancel.clicked.connect(self.chooseCancel)
        self.btn_payment.clicked.connect(self.paymentPage)

        # 페이지 3
        self.spinBox_shot.valueChanged.connect(self.OptionPrice)
        self.spinBox_syrup.valueChanged.connect(self.OptionPrice)
        self.spinBox_pall.valueChanged.connect(self.OptionPrice)
        self.spinBox_1shot.valueChanged.connect(self.OptionPrice)
        self.spinBox_icetoping.valueChanged.connect(self.OptionPrice)
        self.spinBox_excount.valueChanged.connect(self.OptionPrice)
        self.btn_choose_cancel.clicked.connect(self.move1)
        self.btn_choose_complete.clicked.connect(self.BasketList)

        # 페이지 4
        self.btn_home_2.clicked.connect(self.HomePage)
        self.btn_undo.clicked.connect(self.undoPage)
        self.btn_input_stampnumber.clicked.connect(self.UseStampForPayment)
        self.spinBox_stamp_value.valueChanged.connect(self.UseStampCount)
        self.btn_final_payment.clicked.connect(self.StampMove)

        # 페이지 5
        self.btn_number0.clicked.connect(self.Stamp0)
        self.btn_number1.clicked.connect(self.Stamp1)
        self.btn_number2.clicked.connect(self.Stamp2)
        self.btn_number3.clicked.connect(self.Stamp3)
        self.btn_number4.clicked.connect(self.Stamp4)
        self.btn_number5.clicked.connect(self.Stamp5)
        self.btn_number6.clicked.connect(self.Stamp6)
        self.btn_number7.clicked.connect(self.Stamp7)
        self.btn_number8.clicked.connect(self.Stamp8)
        self.btn_number9.clicked.connect(self.Stamp9)
        self.btn_delete_number.clicked.connect(self.StampDelete)
        self.btn_delete_all.clicked.connect(self.StampClear)
        self.btn_stamp_pass.clicked.connect(self.Pass_Stamp)
        self.btn_stamp_complete.clicked.connect(self.StampComplete)
        self.btn_use_stamp.clicked.connect(self.UseStampForDiscount)

        # 페이지 6
        self.last_page_home.clicked.connect(self.HomePage)
        self.last_page_plus.clicked.connect(self.HomePage2)


        self.total_price=[] # 고른 메뉴 결제금액
        self.total_count=0 # 고른 메뉴 개수
        self.menu_count=1 # 토핑 메뉴

#페이지 이동 함수
    def move0(self):
        self.stackedWidget.setCurrentIndex(0)
        self.Takeout_List = 0
        self.Inside_List = 0

    def move1(self):
        self.stackedWidget.setCurrentIndex(1)

    def move1_takeout(self):
        self.stackedWidget.setCurrentIndex(1)
        self.Takeout_List = 1

    def move1_Inside(self):
        self.stackedWidget.setCurrentIndex(1)
        self.Inside_List = 1

    def StampMove(self):
        self.stackedWidget.setCurrentIndex(4)
        self.SN_number=[]
        self.stampnumber_list.clear()

    def paymentPage(self):
        self.stackedWidget.setCurrentIndex(3)
        self.ResearchPass=0
        self.total_result.clear() # 결제창 들어올 때마다 창 비워주기
        self.show_stampcount.clear() # 결제창 들어올 때마다 창 비워주기
        self.input_stampnumber.clear() # 결제창 들어올 때마다 창 비워주기
        self.real_total_result.clear() # 결제창 들어올 때마다 창 비워주기
        self.total_result.addItem(f"주문하신 음료는 총 {self.total_count}잔 입니다.")
        TP=0
        for TP_i in self.total_price:
            TP+=TP_i
        self.total_result.addItem(f"결제하실 금액은 총 {TP}원 입니다.")
        real_TP=TP-1500*self.spinBox_stamp_value.value()
        self.real_total_result.addItem(f"최종 결제 금액은 {real_TP}원 입니다.")

    def UseStampForPayment(self): #결제창에서 스탬프 개수만큼 할인적용하기 위한 함수
        self.InputStampNumber = list(self.input_stampnumber.text())
        self.ResearchPass=0
        if self.InputStampNumber in self.Stamp_id_total:
            self.USFP_A = self.Stamp_id_total.index(self.InputStampNumber)+1 # stamp id의 index값
            self.USFP_B = self.Stamp_id_stamp[f"{self.USFP_A}"] # stamp id의 스탬프 개수
            self.show_stampcount.addItem(f"보유하신 스탬프는 {self.USFP_B}개 입니다.")
            self.ResearchPass=1

        else: # 없는 번호거나 잘못된 값을 입력했을 때
            QMessageBox.warning(self, "경고", "존재하지 않는 번호입니다.")
            self.input_stampnumber.clear()

    def UseStampCount(self):
        if self.ResearchPass == 1: # 스탬프가 있을 때만 이 버튼 손댈 수 있게
            if self.spinBox_stamp_value.value() > self.USFP_B//10: # 밸류값이 스탬프 // 10보다 안 커지게
                QMessageBox.warning(self, "경고", "보유하신 스탬프를 초과한 값을 입력하지 말아주세요.")
                self.spinBox_stamp_value.setValue(0)
                return
        else:
            QMessageBox.warning(self, "경고", "먼저 스탬프 조회를 해주세요.")
            self.spinBox_stamp_value.setValue(0)
            return

    def UseStampForDiscount(self):
        if self.ResearchPass == 1:
            TP = 0
            for TP_i in self.total_price:
                TP += TP_i
            real_TP=TP-1500*self.spinBox_stamp_value.value()
            self.real_total_result.clear()
            self.real_total_result.addItem(f"최종 결제 금액은 {real_TP}원 입니다.")

    def Pass_Stamp(self):
        self.stackedWidget.setCurrentIndex(5)
        if self.Takeout_List == 1:
            self.label_ordernumber.setText(f"주문번호 {self.OrderNumber}번 입니다.")
            self.Takeout_or_Inside.setText("포장")
            self.OrderNumber += 1
        elif self.Inside_List == 1:
            self.label_ordernumber.setText(f"주문번호 {self.In_OrderNumber}번 입니다.")
            self.Takeout_or_Inside.setText("매장")
            self.In_OrderNumber += 1



    def undoPage(self):
        self.stackedWidget.setCurrentIndex(1)
        self.total_result.clear()
        self.real_total_result.clear()
        self.input_stampnumber.clear()
        self.show_stampcount.clear()

    def HomePage(self):
        self.stackedWidget.setCurrentIndex(0)
        self.total_result.clear()
        self.basket.clear()
        self.basket_option.clear()
        self.real_total_result.clear()
        self.input_stampnumber.clear()
        self.show_stampcount.clear()
        self.total_price=[]
        self.total_count=0
        self.spinBox_stamp_value.setValue(0)
        self.Takeout_List = 0
        self.Inside_List = 0

    def HomePage2(self): #마지막 페이지에서 추가결제창으로 이동, 리스트들 초기화
        self.stackedWidget.setCurrentIndex(1)
        self.total_result.clear()
        self.basket.clear()
        self.basket_option.clear()
        self.real_total_result.clear()
        self.input_stampnumber.clear()
        self.show_stampcount.clear()
        self.total_price=[]
        self.total_count=0
        self.spinBox_stamp_value.setValue(0)

#리스트 함수

    def BasketList(self):
        self.stackedWidget.setCurrentIndex(1)
        a_price = self.OP_g
        self.total_count+=self.menu_count
        self.total_price.append(a_price)
        self.basket.addItem(f"{self.label_choose_menu.text()}    ₩ {a_price}")
        self.basket_option.addItem(f"샷 추가 {self.spinBox_shot.value()}회, 헤이즐넛 시럽 {self.spinBox_syrup.value()}회, 펄 추가 {self.spinBox_pall.value()}회, 연하게 {self.spinBox_1shot.value()}회, 아이스크림 토핑 {self.spinBox_icetoping.value()}회, 수량 {self.spinBox_excount.value()}개")
# count 개수로 집계, option에서 배수 늘린거 정상 집계되게


    def icecoffeeBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 아메리카노")
        self.label_choose_price.setText("2000")
        self.label_price_result.setText("₩ 2000")
        self.OP_g=2000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def hotcoffeeBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(HOT) 아메리카노")
        self.label_choose_price.setText("1500")
        self.label_price_result.setText("₩ 1500")
        self.OP_g=1500
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def icelatteBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 빽's 카페라떼")
        self.label_choose_price.setText("3000")
        self.label_price_result.setText("₩ 3000")
        self.OP_g=3000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def hotlatteBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(HOT) 빽's 카페라떼")
        self.label_choose_price.setText("3000")
        self.label_price_result.setText("₩ 3000")
        self.OP_g=3000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def icevanillaBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 바닐라라떼")
        self.label_choose_price.setText("3700")
        self.label_price_result.setText("₩ 3700")
        self.OP_g=3700
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def hotvanillaBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(HOT) 바닐라라떼")
        self.label_choose_price.setText("3700")
        self.label_price_result.setText("₩ 3700")
        self.OP_g=3700
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def icessangteaBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 쌍화차")
        self.label_choose_price.setText("3000")
        self.label_price_result.setText("₩ 3000")
        self.OP_g=3000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def hotssangteaBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(HOT) 쌍화차")
        self.label_choose_price.setText("3000")
        self.label_price_result.setText("₩ 3000")
        self.OP_g=3000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def icedaechuteaBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 대추차")
        self.label_choose_price.setText("3000")
        self.label_price_result.setText("₩ 3000")
        self.OP_g=3000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def hotdaechuteaBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(HOT) 대추차")
        self.label_choose_price.setText("3000")
        self.label_price_result.setText("₩ 3000")
        self.OP_g=3000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def adeBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 청포도에이드")
        self.label_choose_price.setText("4000")
        self.label_price_result.setText("₩ 4000")
        self.OP_g=4000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def misutgaruBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("(ICE) 미숫가루")
        self.label_choose_price.setText("2700")
        self.label_price_result.setText("₩ 2700")
        self.OP_g=2700
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def plainBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("플레인요거트스무디")
        self.label_choose_price.setText("3500")
        self.label_price_result.setText("₩ 3500")
        self.OP_g=3500
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def strawberryBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("딸기요거트스무디")
        self.label_choose_price.setText("4300")
        self.label_price_result.setText("₩ 4300")
        self.OP_g=4300
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def blueberryBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("블루베리요거트스무디")
        self.label_choose_price.setText("5300")
        self.label_price_result.setText("₩ 5300")
        self.OP_g=5300
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def mangoBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("망고패션스무디")
        self.label_choose_price.setText("4000")
        self.label_price_result.setText("₩ 4000")
        self.OP_g=4000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def ggalBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("깔라만시스무디")
        self.label_choose_price.setText("4000")
        self.label_price_result.setText("₩ 4000")
        self.OP_g=4000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def limeBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("쿨라임스무디")
        self.label_choose_price.setText("4000")
        self.label_price_result.setText("₩ 4000")
        self.OP_g=4000
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def shuBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("완전 초코 빽스치노")
        self.label_choose_price.setText("3500")
        self.label_price_result.setText("₩ 3500")
        self.OP_g=3500
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def icecreamBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("완전 딸기 빽스치노")
        self.label_choose_price.setText("3500")
        self.label_price_result.setText("₩ 3500")
        self.OP_g = 3500
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def saladBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("원조 빽스치노")
        self.label_choose_price.setText("3300")
        self.label_price_result.setText("₩ 3300")
        self.OP_g = 3300
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def burnBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("민트초코 빽스치노")
        self.label_choose_price.setText("3800")
        self.label_price_result.setText("₩ 3800")
        self.OP_g = 3800
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def sandBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("완전 초코바나나 빽스치노")
        self.label_choose_price.setText("3500")
        self.label_price_result.setText("₩ 3500")
        self.OP_g = 3500
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def sausageBasket(self):
        self.stackedWidget.setCurrentIndex(2)
        self.label_choose_menu.setText("쿠키크런치 빽스치노")
        self.label_choose_price.setText("3800")
        self.label_price_result.setText("₩ 3800")
        self.OP_g = 3800
        self.spinBox_shot.setValue(0)
        self.spinBox_syrup.setValue(0)
        self.spinBox_pall.setValue(0)
        self.spinBox_1shot.setValue(0)
        self.spinBox_icetoping.setValue(0)
        self.spinBox_excount.setValue(1)

    def chooseCancel(self):
        self.listCancel = self.basket.currentRow()
        self.basket.takeItem(self.listCancel)
        self.basket_option.takeItem(self.listCancel)
        self.total_count -= self.menu_count
        self.total_price.pop(self.listCancel)

    def goHome(self):
        self.total_count=0
        self.total_price=0
        self.basket.clear()
        self.basket_option.clear()


    def OptionPrice(self):
        self.stackedWidget.setCurrentIndex(2)
        self.menu_count = 1
        self.label_price_result.setText("0")
        self.OP_a = self.spinBox_shot.value() * 500
        self.OP_b = self.spinBox_syrup.value() * 500
        self.OP_c = self.spinBox_pall.value() * 1200
        self.OP_d = self.spinBox_1shot.value() * 1
        self.OP_e = self.spinBox_icetoping.value() * 800
        self.OP_f = self.spinBox_excount.value()
        self.menu_count = self.menu_count * self.OP_f
        self.OP_ff = int(self.label_choose_price.text())
        self.OP_g = self.OP_f * (self.OP_a + self.OP_b + self.OP_c + self.OP_e + self.OP_ff)
        self.label_price_result.setText(f"₩ {self.OP_g}")

    def Stamp0(self):
        self.SN_number.append("0")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp1(self):
        self.SN_number.append("1")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp2(self):
        self.SN_number.append("2")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp3(self):
        self.SN_number.append("3")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp4(self):
        self.SN_number.append("4")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp5(self):
        self.SN_number.append("5")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp6(self):
        self.SN_number.append("6")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp7(self):
        self.SN_number.append("7")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp8(self):
        self.SN_number.append("8")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))

    def Stamp9(self):
        self.SN_number.append("9")
        self.stampnumber_list.setText(''.join(self.SN_number))
        if len(self.SN_number)>11:
            QMessageBox.warning(self, "경고", "11자 이내로 작성해주세요.")
            self.stampnumber_list.clear()
            self.SN_number.pop()
            self.stampnumber_list.setText(''.join(self.SN_number))


    def StampDelete(self):
        self.SN_number.pop()
        self.stampnumber_list.clear()
        self.stampnumber_list.setText(''.join(self.SN_number))

    def StampClear(self):
        self.stampnumber_list.clear()
        self.SN_number=[]

    def StampComplete(self):
        self.total_result.addItem(f"주문하신 음료는 총 {self.total_count}잔 입니다.")
        TP = 0
        for TP_i in self.total_price:
            TP += TP_i
        self.total_result.addItem(f"결제하실 금액은 총 {TP}원 입니다.")
        if len(self.SN_number) == 11:
            if self.SN_number in self.Stamp_id_total:
                self.id_index = self.Stamp_id_total.index(self.SN_number)+1
                self.Stamp_id_stamp[f"{self.id_index}"] += self.total_count

            else:
                self.Stamp_id_total.append(self.SN_number)
                self.Stamp_index=len(self.Stamp_id_total)
                self.Stamp_id_stamp[f"{self.Stamp_index}"] = self.total_count

        else:
            QMessageBox.warning(self, "입력 오류", "정확히 11자리를 입력해주세요.")

        if self.Takeout_List == 1:
            self.label_ordernumber.setText(f"주문번호 {self.OrderNumber}번 입니다.")
            self.Takeout_or_Inside.setText("포장")
            self.OrderNumber += 1
        elif self.Inside_List == 1:
            self.label_ordernumber.setText(f"주문번호 {self.In_OrderNumber}번 입니다.")
            self.Takeout_or_Inside.setText("매장")
            self.In_OrderNumber += 1

        self.stackedWidget.setCurrentIndex(5)



if __name__ == "__main__" :
    #QApplication : 프로그램을 실행시켜주는 클래스
    app = QApplication(sys.argv)

    #WindowClass의 인스턴스 생성
    myWindow = WindowClass()

    #프로그램 화면을 보여주는 코드
    myWindow.show()

    #프로그램을 이벤트루프로 진입시키는(프로그램을 작동시키는) 코드
    app.exec_()