import numpy as np
from datetime import datetime
import sys

zerotime = datetime(1900, 1, 1)
converters = {0: lambda x: (datetime.strptime(str(x), "%m-%d") - zerotime).days,
              1: lambda x: (datetime.strptime(str(x), "%H-%M") - zerotime).seconds}
times = np.loadtxt(sys.argv[-1], dtype=object, skiprows=1)
day = [converters[0](x) for x in times[:, 0]]  # #days from new year
sunrise = [converters[1](x) for x in times[:, 1]]
sunset = [converters[1](x) for x in times[:, 2]]

a1 = np.polyfit(day, sunrise, 2)
a2 = np.polyfit(day, sunset, 2)

np.savetxt('{}_out'.format(sys.argv[-1]), np.concatenate((a1[::-1], a2[::-1])).reshape((-1, 1)), fmt='%f')
# input as days and output as seconds for sunrise and sunset

# import matplotlib.pyplot as plt
# plt.plot(day, sunrise, day, sunset)
# plt.plot(day, np.polyval(a1, day), day, np.polyval(a2, day))
# plt.legend(['sunrise', 'sunset', 'est sunrise', 'est sunset'])
# plt.show()
