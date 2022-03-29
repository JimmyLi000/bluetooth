#include<SoftwareSerial.h>    
#include<Wire.h>             
SoftwareSerial BT(10,11);  //RX,TX   設定RX=10  TX=11     板子RX=11  TX=10
//Arduino的 TX要接藍牙模組的RX, 反之亦然

void setup(){
  Serial.begin(9600);  
  BT.begin(9600); 
  pinMode(7, OUTPUT); //設定pin7為輸出,realy1 就接在這
  pinMode(6, OUTPUT); //設定pin6為輸出,realy2 就接在這
  pinMode(5, OUTPUT); //設定pin5為輸出,realy3 就接在這
  pinMode(4, OUTPUT); //設定pin4為輸出,realy4 就接在這
  //預設全部relay在常閉NC
  digitalWrite(7,LOW);  //一開始不通電
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
 
}
  void loop(){

    byte cmmd[20];
    int insize;
    while(1){
      if((insize=(BT.available())) >0){ //判斷是否有訊息傳入訊息
        Serial.print("input size =");
        Serial.println(insize);
        for(int i=0; i<insize; i++){
          Serial.print(cmmd[i]=char(BT.read())); //顯示訊息
          Serial.print(" ");
        }
      }
      switch (cmmd[0]){   //讀取第一個字
        case 97: digitalWrite(7,LOW); //97為ASCII Code ="a"  relay常開 斷電
        Serial.println(" 0"); 
        break;
        case 98: digitalWrite(7,HIGH); //97為ASCII Code ="b"  relay常開 通電
        Serial.println(" 1");
        break;

        
        case 99: digitalWrite(6,LOW); 
        break;
        case 100: digitalWrite(6,HIGH); 
        break;
        case 101: digitalWrite(5,HIGH); 
        break;
        case 102: digitalWrite(5,HIGH); 
        break;
        case 103: digitalWrite(4,LOW); 
        Serial.println(" 0");
        break;
        case 104: digitalWrite(4,HIGH);
         Serial.println(" 1");
         break;
         
      }  //Switch
    }    //while
  }      //loop
