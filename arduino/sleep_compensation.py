# import matplotlib.pyplot as plt
import numpy as np

expected_sleep_time = np.array([2, 4, 6, 8]) * 3600 * 1000
actual_sleep_time = np.array(
    [
        (6 * 3600 + 8 * 60 + 14) / 3,
        (8 * 3600 + 10 * 60 + 52) / 2,
        6 * 3600 + 8 * 60 + 13,
        8 * 3600 + 11 * 60 + 3,
    ]
) * 1000

current_compensation = 0.0447
actual_sleep_time = actual_sleep_time / (1 - current_compensation)

coeff = np.sum(actual_sleep_time * expected_sleep_time) / np.sum(expected_sleep_time**2)
print(coeff)

# plt.plot(expected_sleep_time, actual_sleep_time)
# plt.show()
