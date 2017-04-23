#include "3664.h"

#define LED17 0x01   //P80    LED1○        ○LED5
#define LED26 0x02   //P81            LED4
#define LED35 0x04   //P82    LED2○   ○   ○LED6
#define LED4  0x08   //P83
                     //       LED3○        ○LED7


#define SEGa  0x01 //P50  7seg P1            ____
#define SEGb  0x02 //P51  7seg P2         f | a  | b
#define SEGc  0x04 //P52  7seg P4           |____|
#define SEGd  0x08 //P53  7seg P6         e | g  | c
#define SEGe  0x10 //P54  7seg P7           |____|
#define SEGf  0x20 //P55  7seg P9             d
#define SEGg  0x40 //P56  7seg P10

#define 

#define P1IN 0x2     //入力ポートP11

void saicolo( int i ){    //LEDを光らせる関数saicolo
	
	switch( i ){
		
		case 1: PDR8 = LED17 | LED26 | LED35 ;	//1の時、光らせないLED
		        break;
	
	    case 2: PDR8 = LED26 | LED35 | LED4 ;	//2の時、光らせないLED
	   		    break;

        case 3: PDR8 = LED26 | LED35 ;			//3の時、光らせないLED
                break;
        
        case 4: PDR8 = LED4 | LED26 ;			//4の時、光らせないLED
   		        break;
        
        case 5: PDR8 = LED26 ;					//5の時、光らせないLED
      	        break;
        
        case 0: PDR8 = LED4 ;					//6の時、光らせないLED
                break;
	}
	
}

void moji( int i ){    //7segment関数
	
	switch(i){
		
		case 1: PDR5 = SEGa | SEGd | SEGe | SEGf | SEGg ; //1の時、光らせないLED
		        break;
	
	    case 2: PDR5 = SEGc | SEGf;                       //2の時、光らせないLED
	            break;
	    
	    case 3: PDR5 = SEGe | SEGf;                       //3の時、光らせないLED
	            break;
	    
	    case 4: PDR5 = SEGa | SEGd | SEGe ;               //4の時、光らせないLED
	            break;
	    
	    case 5: PDR5 = SEGb | SEGe ;                      //5の時、光らせないLED
	            break;
	    
	    case 0: PDR5 = SEGb ;                             //6の時、光らせないLED
	            break;
	            
	}
	
}
int main(){
	
	int i = 0 ;  //サイコロの目 1～6
	int k ;      //遅延時間を数える変数
	
	PMR1 = 0x00 ;	// 汎用入出力ポートに設定
	PCR1 = 0x00 ;	// ポート1を全ビット入力用に使用

	PMR5 = 0x00 ;  	//汎用入出力ポートに設定
	PCR5 = 0xff ;  	//ポート5を全ビット出力用に設定
	PDR5 = 0xff ;  	//ポート5をクリア
	
	PCR8 = 0xff ;  	//ポート8を全ビット出力用に設定
	PDR8 = 0xff ;  	//ポート8をクリア
	
	while( 1 ) { 
		
		if( (PDR1 & P1IN) == 0 ){       //スイッチを押している時
			
			++i;
			i=i%6;
			
			saicolo( i ) ;
			moji( i ) ;
			
			for( k = 0 ; k <= 100000 ; ++k ){   //遅延
				NOP();
			}
					
		}
		
	}
}