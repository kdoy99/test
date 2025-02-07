import matplotlib.pyplot as plt
import numpy as np

font1 = {'family': 'serif',
         'color': 'b',
         'weight': 'bold',
         'size': 14
         }

font2 = {'family': 'serif',
         'color': 'deeppink',
         'weight': 'normal',
         'size': 'xx-large'
         }

plt.plot([2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023],[3164650,2696538,2820914,1771852,242710,277777,89299,81963,159001,325170]
         , 'o-', label='exports',  solid_capstyle='round', color='C0', linewidth=3) # 순서대로 선의 종류, 마커, 축 이름, 선 스타일, 색깔, 선 두께
plt.xlabel('year',labelpad=5, fontdict=font1, loc='right')
plt.plot([2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023],[4446231,3555278,3710778,3778051,2600774,2967167,773673,631371,1426607,2443948]
         , 'o--', label='imports', solid_capstyle='butt', color='C1', linewidth=3)
plt.ylabel('exports',labelpad=15, fontdict=font2, loc='top')
plt.xlim([2013, 2024])      # X축의 범위: [xmin, xmax]
plt.ylim([0, 5000000])     # Y축의 범위: [ymin, ymax]
# plt.legend(loc=(0.0, 0.0))
# plt.legend(loc=(0.5, 0.5))
plt.legend(loc='best', ncol=1, fontsize=10, frameon=True, shadow=True)

# 범위 출력
# x_range, y_range = plt.xlim(), plt.ylim()
# print(x_range, y_range)
#
# axis_range = plt.axis('scaled')
# print(axis_range)

# 텍스트 추가
plt.text(2019, 2500000, 'COVID 19', rotation=-75)
plt.text(2017, 1000000, 'Export Sanctions', rotation=-70)

# 타이틀 추가
plt.title('North Korea of exports/imports (1000$)')

plt.show()

