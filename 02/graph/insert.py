from locale import DAY_1
import matplotlib.pyplot as plt
import japanize_matplotlib
import numpy as np

s = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
d1 = [0.0888534000, 0.3554186000, 0.8038930000, 1.4243825000, 2.2213042000, 3.1972039000, 4.3636452000, 5.6779963000, 7.2044825000, 8.8662586000]
d2 = [0.0886210000, 0.3545722000, 0.7930055000, 1.4134156000, 2.2080360000, 3.1845736000, 4.3493537000, 5.6547190000, 7.2193063000, 8.9333873000] 
d3 = [0.0878081000, 0.3543866000, 0.7983683000, 1.4081037000, 2.1894604000, 3.1569338000, 4.3634012000, 5.7014135000, 7.2071090000, 8.8329121000] 
d4 = [0.0000266000, 0.0000507000, 0.0000753000, 0.0000998000, 0.0001237000, 0.0001482000, 0.0001733000, 0.0001969000, 0.0002205000, 0.0002450000] 
d5 = [0.1764419000, 0.7083938000, 1.5963428000, 2.8440483000, 4.4333247000, 6.3842588000, 8.7066945000, 11.3658150000, 14.3929274000, 17.7750315000] 
d6 = [0.0885053000, 0.3557021000, 0.8001941000, 1.4477330000, 2.2428672000, 3.2321183000, 4.4251128000, 5.7467632000, 7.3602307000, 9.0739016000]
d7 = [0.0873503000, 0.3526469000, 0.8022000000, 1.4270348000, 2.2263931000, 3.1939696000, 4.3626976000, 5.7115532000, 7.2286238000, 8.9245646000] 

x = np.array(s)
y1 = np.array(d1)
y2 = np.array(d2)
y3 = np.array(d3)
y4 = np.array(d4)
y5 = np.array(d5)
y6 = np.array(d6)
y7 = np.array(d7)

plt.grid(True)
# plt.tick_params(labelsize = 10) # 目盛線ラベルサイズ

# グラフ描画
plt.plot(x, y1, color='b', marker="o", markeredgewidth=1, label="data1.dat (ランダムデータ)")
plt.plot(x, y2, color='r', marker="o", markeredgewidth=1, label="data2.dat (ランダムデータ)")
plt.plot(x, y3, color='y', marker="o", markeredgewidth=1, label="data3.dat (ランダムデータ)")
plt.plot(x, y4, color='g', marker="o", markeredgewidth=1, label="data4.dat (昇順データ)")
plt.plot(x, y5, color='k', marker="o", markeredgewidth=1, label="data5.dat (降順データ)")
plt.plot(x, y6, color='m', marker="o", markeredgewidth=1, label="data6.dat (バイトニックデータ)")
plt.plot(x, y7, color='c', marker="o", markeredgewidth=1, label="data7.dat (ジグザグデータ)")

plt.legend(loc="upper left", fontsize=15) # (3)凡例表示
# plt.xticks(x, ["0.0234375", "0.046875", "0.09375", "0.1875", "0.375", "0.75"])

plt.xlabel("データ数 [個]") # x軸ラベル
plt.ylabel("実行時間 [s]") # y軸ラベル

plt.show()
