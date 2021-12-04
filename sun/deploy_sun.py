import numpy as np
import re

re_functions = [
    lambda data, x: re.sub(r'a0 = (.*);', 'a0 = {};'.format(x), data),
    lambda data, x: re.sub(r'a1 = (.*);', 'a1 = {};'.format(x), data),
    lambda data, x: re.sub(r'a2 = (.*);', 'a2 = {};'.format(x), data),
    lambda data, x: re.sub(r'b0 = (.*);', 'b0 = {};'.format(x), data),
    lambda data, x: re.sub(r'b1 = (.*);', 'b1 = {};'.format(x), data),
    lambda data, x: re.sub(r'b2 = (.*);', 'b2 = {};'.format(x), data)
]
def to_file(f, params):
    with open(f, 'r+') as tf:
        data = tf.read()
        for i in range(len(params)):
            data = re_functions[i](data, params[i])
        tf.seek(0)
        tf.write(data)
        tf.truncate()

def deploy_sun_params(f, in_file=None):
    if in_file is None:
        in_file = f
    params_file = '{}_out'.format(in_file)
    params = np.loadtxt(params_file).flatten()
    arduino_file = '../arduino/{}/{}.ino'.format(f, f)
    web_file = '../web/{}.php'.format(f)

    to_file(arduino_file, params)
    to_file(web_file, params)

if __name__ == '__main__':
    deploy_sun_params('la_jument')
    deploy_sun_params('simpnasklubb')
    deploy_sun_params('falsterbo')
    deploy_sun_params('drogden', 'falsterbo') # has the same sun as falsterbo
