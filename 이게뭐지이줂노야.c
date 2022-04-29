/*
 Gearmotor Rotary Encoder Test
 motor-encoder-rpm.ino
 Read pulses from motor encoder to calculate speed
 Displays results on Seral Monitor
 Use Cytron MD10C PWM motor controller
 DroneBot Workshop 2019
 https://dronebotworkshop.com
*/

// encoder 속도

// Motor encoder ouput pulse per ratation (change as required)
#define ENC_COUNT_REV 372 // 모터 회전에 대한 숫자 변경

// Encoder ouput to Arduino Interrupt pin
#define ENC_IN 3 // 인코더 연결 핀으로 변경

//MD10C PWM connected to pin 10
#define PWM 10 // pwm 핀(속도 제어)
//MD10C DIR connected to pin 12
#define PWM 12 // derp 핀(방향 제어)

//Analog pin for potentiometer
int speedcontrol = 0; // 가변저항(앞뒤 or 양옆)

// Pulse count from encoder
volatile long encoderValue = 0; // 1ms

// One-second interval for measurements
int interval = 1000; // 1ms * 1000 = 1s

//Counters for milliseconds during interval
long previousMillis = 0; // 변수 처음엔 0
long correntMillis = 0; // 변수 처음엔 0

//Variable for RPM measurement
int rpm = 0; // 변수 처음엔 0

//Variable for PWM motor speed output
int motorPwm = 0: // 변수 처음엔 0

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600); // 시리얼 번호 변경

  // Set encoder as input with internal pullup - 인코더 연결 핀 기입, input_pullup 함수는 LOW값만 표시됨
  pinMode(ENC_IN, INPUT_PULLUP);

  // Set PWM and DIR connections as outputs 핀번호 2개 기입, output으로 받겠다
  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);

  // Attach interrupt - 인터럽트에 접근해 RISING의 주파수로 시간을 계산
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);

  // Setup initial values for timer - 초기 시간 값 1ms
  previousMillis = millis();
}

void loop()
{
    // Control motor with potentiometer
    motorPwm = map(analogRead(speedcontrol), 0, 1023, 0, 255);

    // Write PWM to controller
    analogWrite(PWM, motorPwm);

  // Update RPM value every second
  currentMillis = millis();
  if curretMillis - previousMillis > interval)  {
   previousMillis = currentMillis;

    // Calculate RPM
    rpm = (float)(encoderValue * 60 / ENC_COUNT_REV); // 60을 더하는 이유 : 초당 받은 펄수 수를 분당으로 바꾸기 위해

    // Only update display when there is a reading
    if (motorPwm > 0 || rpm > 0) {
      Serial.print("PWM VALUE: ");
      Serial.print(motorPwm);
      Serial.print('\t');
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print('\t');
      Serial.print(" SPEED: ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }

    encoderValue = 0;
  }
}

void updateEncoder()
{
  // Increment value for each pulse from encoder
  endcoderValue++;
}