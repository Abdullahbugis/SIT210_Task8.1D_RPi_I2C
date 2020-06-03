import smbus
import time
slaveAddr = 0x05
bus = smbus.SMBus(1)


while True:
    data = bus.read_byte(slaveAddr) 
    
    if data >= 190:
        level = 'Too bright Light'
    elif data < 160 and data >= 120:
        level = 'bright Light'
    elif data < 130 and data >= 70:
        level = 'medium Light'
    elif data <40 and data >= 30:
        level = 'dark Light'
    else:
        level = 'too dark Light'
    print(level)
    time.sleep(1.5)