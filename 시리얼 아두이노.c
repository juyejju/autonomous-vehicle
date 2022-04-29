//시리얼 아두이노

#pragma pack(push, 1)
typedef struct packet_
{
    unsigned char start_sign; // 시작 사인 : 1
    unsigned char data_type;  // 데이터 타입 : 1
    uint32_t data;            // 데이터 : 4
    unsigned short checksum;  // 체크섬 : 2
}PACKET;
#pragma pack(pop)

//또는 
//unsigned char packet[8];

// 데이터를 받을 버퍼 선언
PACKET data = {0, };
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // 시리얼에 읽을 데이터가 있다면
    if(Serial.available())
    {
        // packet 사이즈만큼 읽어옴
        Serial.readBytes((char*)&data, sizeof(data));
        // 데이터 값에 + 1을 한 뒤에 다시 전송
        data.data += 1;
        Serial.write((char*)&data, sizeof(data));
    }
}