from locale import DAY_1
import matplotlib.pyplot as plt
import japanize_matplotlib
import numpy as np

s = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
d1 = [0.1672136667, 0.7551030000, 1.6833023333, 3.0701570000, 4.9452946667, 6.9832763333, 9.3866890000, 12.4432116667, 15.7174583333, 19.4513056667]
d2 = [0.1682680000, 0.7156306667, 1.6343856667, 3.0731833333, 4.7914646667, 6.8324520000, 9.5472353333, 12.3676940000, 15.9077776667, 19.4500330000]
d3 = [0.1724513333, 0.7516126667, 1.6527926667, 2.9295033333, 4.6217376667, 6.8138506667, 9.6483693333, 12.2941503333, 15.6764556667, 19.5392556667]
d4 = [0.0000473333, 0.0000730000, 0.0000943333, 0.0001136667, 0.0001493333, 0.0001546667, 0.0001766667, 0.0001983333, 0.0002503333, 0.1939496667]
d5 = [0.7635390000, 1.7623576667, 3.0366640000, 4.8062156667, 7.0819746667, 9.6063510000, 11.9922670000, 15.1848796667, 19.6548093333, 18.6681320000]
d6 = [0.4437610000, 1.0010570000, 1.8092310000, 2.8355343333, 4.0438496667, 5.5100306667, 7.1681966667, 9.0714730000, 11.1900883333, 11.6196190000]
d7 = [0.1696863333, 0.6844046667, 1.5263706667, 2.7729710000, 4.4241803333, 6.3209913333, 8.5569030000, 11.2416353333, 14.1046316667, 17.4439566667] 

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
