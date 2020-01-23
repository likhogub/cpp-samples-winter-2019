print('Miner started')

import socket
import json
import time
import hashlib


#data = reciever.recv(1024)


server = ('localhost', 12345)
wallet = input('Your wallet: ')
reciever = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
reciever.bind(('', 0))
reciever.sendto((f'{wallet}:connected').encode('utf-8'), server)

def SendShare(wallet, number):
    reciever.sendto(f'{wallet}:{number}'.encode('utf-8'), server)
    data = reciever.recv(1024)
    data = data.decode('utf-8')
    data = json.loads(data)
    return data[0], data[1], data[2]

xrange = 1
hashes = 0
delta = 0

speeds = [0]
calculated = {}
def md5(number):
    if calculated.get(number) != None:
        return calculated.get(number)
    calculated[number] = _md5(number)
    return calculated.get(number)


def _md5(number):
    return hashlib.md5(bytes(number)).hexdigest()


result, diff, target = SendShare(wallet, 0)

while True:
    if hashes % 10 == 0:
        start_time = time.time()
    for i in range(diff + 1):
        if md5(i) == target:
            result, diff, target = SendShare(wallet, i)
            if result:
                break
    if hashes % 10 == 0:
        delta = (delta + (time.time() - start_time)) / 2
        if delta != 0:
            speed = 10 / delta
            speed = round(speed / 1000, 2)
            speeds.append(speed)
            if len(speeds) > 100:
                speeds.pop(0)
            if hashes % 100 == 0:
                print(round(sum(speeds)/len(speeds), 2), 'kH/s', diff)
    hashes += 1
