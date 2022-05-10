from machine import Pin, PWM
import time

class Motor:
    def __init__(self):
        
    # 모터 속도 입력하면 핀 pwm 설정
    def set(self, speed): 
          
class SpeedMotor:
    def __init__(self):
        self.motor = Motor()
        
        self.kp = 0.0001
        #self.ki = 0.5
        
        self.t0 = time.ticks_ms()
        
        # PWM 클래스 사용
    
    def get_speed(self):
        # 인코더 펄스 가져오기
        # 인코더 펄스 세기
        # 펄스 센거에 low pass 필터 적용
        # 적용한 값 리턴
        
    def set(self, target_speed):
        curr_speed = self.get_speed()
        
        error = target_speed - curr_speed
        
        t = time.ticks.ms()
        
        delta_t = time.ticks_diff(t, self.t0)
        proportional = error 
        integral += error * delta_t 
        #speed = self.kp * proportional + self.ki * integral
        speed = self.kp * proportional 
        
        self.motor.set(speed)
        
        self.prev_speed = curr_speed 
        self.t0 = t
        
class SteerMotor:
    def __init__(self):
        self.motor = Motor()
        
        self.kp = 0.0001
        #self.ki = 0.5
        
        # ADC 클래스 사용
        
        self.t0 = time.ticks_ms()

        self.prev_steering = get_angle()
        self.integral = 0
        
    def get_angle(self):
        
    def set(self, steering):
        curr_steering = self.get_angle()
        
        # pid 제어
        error = target_steering - curr_steering
        
        t = time.ticks_ms()
        delta_t = time.ticks_diff(t, self.t0)
        
        proportional = error 
        self.integral += curr_steering * delta_t
        derivative = (curr_steering - self.prev_steering) / delta_t
        
        #speed = self.kp * proportional + self.ki * self.integral + self.kd * derivative
        speed = self.kp * proportional


        # 모터 속도 설정
        self.motor.set(speed)
        
        self.prev_steering = curr_steering
        self.t0 = t
    
# 시리얼 통신으로 모터 속도와 조향각 받아오기
#bcd - led pin으로 확인하기
#blocking 추가하기

def get_cmd():
    return 1.0, 0.0

speed_motor = SpeedMotor()
steering_motor = SteerMotor()
while True:
    # 시리얼 통신에서 모터 속도랑 조향각 가져오기
    speed, steering = get_cmd()
    # 모터 속도 설정하기
    speed_motor.set(speed)
    # 조향각 설정하기
    steering_motor.set(steering)
