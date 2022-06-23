from locale import DAY_1
import matplotlib.pyplot as plt
import japanize_matplotlib
import numpy as np

s = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
d1 = [0.0003442000, 0.0004942000, 0.0006320000, 0.0007282000, 0.0007825000, 0.0008367000, 0.0008885000, 0.0009510000, 0.0010119000, 0.0010686000]
d2 = [0.0003426000, 0.0004917000, 0.0006282000, 0.0007208000, 0.0008114000, 0.0008569000, 0.0009322000, 0.0009557000, 0.0010338000, 0.0010567000]
d3 = [0.0003335000, 0.0004839000, 0.0006203000, 0.0007052000, 0.0007708000, 0.0008240000, 0.0008841000, 0.0009395000, 0.0010010000, 0.0010660000]
d4 = [0.0002550000, 0.0003388000, 0.0004223000, 0.0005062000, 0.0005909000, 0.0006759000, 0.0007624000, 0.0008534000, 0.0009361000, 0.0010264000]
d5 = [0.0002543000, 0.0003384000, 0.0004258000, 0.0005065000, 0.0005944000, 0.0006762000, 0.0007656000, 0.0008548000, 0.0009368000, 0.0010187000]
d6 = [0.0002632000, 0.0003461000, 0.0004336000, 0.0005183000, 0.0006122000, 0.0006898000, 0.0007786000, 0.0008685000, 0.0009504000, 0.0010312000]
d7 = [0.0003313000, 0.0004839000, 0.0006179000, 0.0007116000, 0.0007695000, 0.0008306000, 0.0008853000, 0.0009441000, 0.0009943000, 0.0010518000]

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

plt.legend(loc="lower right", fontsize=15) # (3)凡例表示
# plt.xticks(x, ["0.0234375", "0.046875", "0.09375", "0.1875", "0.375", "0.75"])

plt.xlabel("データ数 [個]") # x軸ラベル
plt.ylabel("実行時間 [s]") # y軸ラベル

plt.show()
