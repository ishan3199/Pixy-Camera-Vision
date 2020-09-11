
//x ranges from 0 to 315
// y ranges from 0 to 100 around


  
#include <Pixy2.h>
#include<SPI.h>

Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  pinMode(13,OUTPUT);
  pixy.init();
}


int x(int c){

  int value1;
  value1=c;
  return Serial.println(value1);
}

int y(int d){

  int value2;
  value2=d;
  return Serial.println(value2);  
}

void loop()
{ 
  int i; 
  uint16_t blocks;
  uint16_t a;
  uint16_t b;
  
  // grab blocks!
  blocks=pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (blocks)
  {

    
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.println(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
      a=pixy.ccc.blocks[i].m_x;
      b=pixy.ccc.blocks[i].m_y;
      Serial.println("x is:");  
      x(a);
      Serial.println("y is:");  
      y(b);
      delay(1000);
    }
  }  
}
