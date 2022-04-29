import math
import serial
from machine import ADC, Pin, PWM, UART
import utime


ENC_IN = Pin() #아두이노 인터럽트 핀

MOTOR_A = PWM(Pin(28))
MOTOR_B = PWM(Pin(7))

count = 0

def pulse_counter():
    count += 1

def map(x, input_min, input_max, output_min, output_max):
    return (x - input_min) * (output_max - output_min) / (input_max - input_min) + output_min  # map()함수 정의.

#셋업
uart = UART(baudrate = 9600)

ENC_IN.irq(handler=pulse_counter, trigger=Pin.IRQ_RISING)

adc = ADC(Pin(28, Pin.IN))

while True:
    reading_angle = adc.read_u16()  # 0,65535

    #pid 제어

