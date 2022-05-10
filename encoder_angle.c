//encoder 각도

void setup() 
{
  Serial.begin(9600);
  }

void loop()
{
  int Encoder = analogRead(0);                  // 지정한 아날로그 핀에서 값을 읽음으로 0에서 5V 사이의 입력 전압을 0에서 1024 사이의 정수 값으로 대응
  int val = map(Encoder, 0, 1023, 0, 360);      // map 함수를 이용하여 0~1023 값을 0~360으로 범위 수정 (각도를 도 단위로 나올 수 있게 변환)
  Serial.println(Encoder);                      // Encoder degree 값 반환 
}