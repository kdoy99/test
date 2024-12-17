## 1. 성적표 출력하기

# import random
#
# print("%25s" %"성적표")
# name=["박선후", "황은비", "김승수", "조세빈"]
# test={1:0, 2:0, 3:0, 4:0}
# i=0
# j=1
# k=0
# sum_person=0
# sum_index=[0,0,0,0]
# average_total=0
# Last=0
# print("-"*50)
# print("이름     국어     영어     수학     파이썬     평균")
# print("-"*50)
#
#
# while i<4:
#     print("{0:<6}".format(name[i]), end=" ")
#     while j<5:
#         test[j] = random.randint(0, 100)
#         print("{0:<7.0f}".format(test[j]), end=" ")
#         sum_person+=test[j]
#         sum_index[j-1]+=test[j]
#         j+=1
#     print(sum_person/4)
#     j=1
#     sum_person=0
#     i+=1
#
# print("-"*50)
# print("{0:<6}".format("평균"), end=" ")
# while k<4:
#     print("{0:<7.2f}".format(sum_index[k]/4), end=" ")
#     average_total+=sum_index[k] / 4
#     k+=1
# Last = average_total / 4
# print("{0:0.2f}".format(Last))
# print("-"*50)


## 2. 로또 자동 판매기 만들기

# import random
#
# numbers=[0,0,0,0,0,0]
# numbers_bag={}
# i=0
# j=0
# n_count=0
# while True:
#     game = int(input("로또를 몇판 하시겠습니까? (최대 5판) : "))
#     if game > 5 or game < 1:
#         print("1에서 5 사이의 숫자를 입력해주세요.")
#         continue
#     else:
#         break
#
# while True:
#     money = int(input("금액을 입력해주세요 (한판 당 천원) : "))
#     if game * 1000 > money:
#         print("금액이 부족합니다.")
#         continue
#     else:
#         print("거스름돈은 %d원 입니다." %(money-game*1000))
#         break
#
# while True:
#     choose_auto = input("수동, 자동 중에 하나를 선택해주세요 : ")
#     if choose_auto=="수동":
#         while i<game:
#             print("%d번째 게임 시작합니다." %(i+1))
#             while j<6:
#                 numbers[j]=int(input("%d번째 번호를 입력해주세요 (1~45) : " %(j+1)))
#                 if numbers[j]>45 or numbers[j]<1:
#                     print("1부터 45까지의 숫자를 입력해주세요.")
#                     continue
#                 if numbers.count(numbers[j])==2:
#                     print("중복된 숫자를 피해주세요")
#                     continue
#                 j+=1
#             numbers_bag["%d번째 게임" %(i+1)]=numbers
#             numbers=[0,0,0,0,0,0]
#             i+=1
#             j=0
#         print("고르신 숫자들을 출력합니다.")
#         print(numbers_bag)
#         break
#
#     elif choose_auto=="자동":
#         while i < game:
#             while j<6:
#                 numbers[j]=random.randint(1,45)
#                 if numbers.count(numbers[j])==2:
#                     continue
#                 j+=1
#             numbers_bag["%d번째 게임" %(i+1)]=numbers
#             numbers=[0,0,0,0,0,0]
#             i+=1
#             j=0
#         print("자동으로 숫자를 골랐습니다. 결과를 출력합니다.")
#         print(numbers_bag)
#         break
#     else:
#         print("수동과 자동 중에 입력해주세요.")
#         continue

# 3. 당첨 결과 유무

import random

numbers=[0,0,0,0,0,0]
numbers_bag={}

# 랜덤 당첨번호 생성
gotcha=[0,0,0,0,0,0]
l=0
while l < 6:
    gotcha[l] = random.randint(1,45)
    if gotcha.count(gotcha[l])==2:
        continue
    l+=1



i=0
j=0
n_count=0
while True:
    game = int(input("로또를 몇판 하시겠습니까? (최대 5판) : "))
    if game > 5 or game < 1:
        print("1에서 5 사이의 숫자를 입력해주세요.")
        continue
    else:
        break

while True:
    money = int(input("금액을 입력해주세요 (한판 당 천원) : "))
    if game * 1000 > money:
        print("금액이 부족합니다.")
        continue
    else:
        print("거스름돈은 %d원 입니다." %(money-game*1000))
        break

while True:
    choose_auto = input("수동, 자동 중에 하나를 선택해주세요 : ")
    if choose_auto=="수동":
        while i<game:
            print("%d번째 게임 시작합니다." %(i+1))
            while j<6:
                numbers[j]=int(input("%d번째 번호를 입력해주세요 (1~45) : " %(j+1)))
                if numbers[j]>45 or numbers[j]<1:
                    print("1부터 45까지의 숫자를 입력해주세요.")
                    continue
                if numbers.count(numbers[j])==2:
                    print("중복된 숫자를 피해주세요")
                    continue
                j+=1
            numbers_bag["%d번째 게임" %(i+1)]=numbers
            numbers=[0,0,0,0,0,0]
            i+=1
            j=0
        print("고르신 숫자들을 출력합니다.")
        print(numbers_bag)
        break

    elif choose_auto=="자동":
        while i < game:
            while j<6:
                numbers[j]=random.randint(1,45)
                if numbers.count(numbers[j])==2:
                    continue
                j+=1
            numbers_bag["%d번째 게임" %(i+1)]=numbers
            numbers=[0,0,0,0,0,0]
            i+=1
            j=0
        print("자동으로 숫자를 골랐습니다. 결과를 출력합니다.")
        print(numbers_bag)
        break

    else:
        print("수동과 자동 중에 입력해주세요.")
        continue

# 당첨 유무 확인
game_confirm={}
Lstack=0
a=0
result=""
while a < game:
    for b in range(0,6):
        for c in range(0,6):
            if gotcha[b]==numbers_bag['%d번째 게임' %(a+1)][c]:
                Lstack+=1
    if Lstack >= 3:
        result="축하합니다! 당첨입니다."
    else:
        result="당첨되지 않았습니다."

    game_confirm["%d번째 게임 결과" %(a+1)]=result

    result=""
    Lstack=0
    a+=1

print("당첨 번호는 %s입니다." %gotcha)
print(game_confirm)
