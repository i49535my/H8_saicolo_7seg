#include "3664.h"

#define LED17 0x01   //P80    LED1��        ��LED5
#define LED26 0x02   //P81            LED4
#define LED35 0x04   //P82    LED2��   ��   ��LED6
#define LED4  0x08   //P83
                     //       LED3��        ��LED7


#define SEGa  0x01 //P50  7seg P1            ____
#define SEGb  0x02 //P51  7seg P2         f | a  | b
#define SEGc  0x04 //P52  7seg P4           |____|
#define SEGd  0x08 //P53  7seg P6         e | g  | c
#define SEGe  0x10 //P54  7seg P7           |____|
#define SEGf  0x20 //P55  7seg P9             d
#define SEGg  0x40 //P56  7seg P10

#define 

#define P1IN 0x2     //���̓|�[�gP11

void saicolo( int i ){    //LED�����点��֐�saicolo
	
	switch( i ){
		
		case 1: PDR8 = LED17 | LED26 | LED35 ;	//1�̎��A���点�Ȃ�LED
		        break;
	
	    case 2: PDR8 = LED26 | LED35 | LED4 ;	//2�̎��A���点�Ȃ�LED
	   		    break;

        case 3: PDR8 = LED26 | LED35 ;			//3�̎��A���点�Ȃ�LED
                break;
        
        case 4: PDR8 = LED4 | LED26 ;			//4�̎��A���点�Ȃ�LED
   		        break;
        
        case 5: PDR8 = LED26 ;					//5�̎��A���点�Ȃ�LED
      	        break;
        
        case 0: PDR8 = LED4 ;					//6�̎��A���点�Ȃ�LED
                break;
	}
	
}

void moji( int i ){    //7segment�֐�
	
	switch(i){
		
		case 1: PDR5 = SEGa | SEGd | SEGe | SEGf | SEGg ; //1�̎��A���点�Ȃ�LED
		        break;
	
	    case 2: PDR5 = SEGc | SEGf;                       //2�̎��A���点�Ȃ�LED
	            break;
	    
	    case 3: PDR5 = SEGe | SEGf;                       //3�̎��A���点�Ȃ�LED
	            break;
	    
	    case 4: PDR5 = SEGa | SEGd | SEGe ;               //4�̎��A���点�Ȃ�LED
	            break;
	    
	    case 5: PDR5 = SEGb | SEGe ;                      //5�̎��A���点�Ȃ�LED
	            break;
	    
	    case 0: PDR5 = SEGb ;                             //6�̎��A���点�Ȃ�LED
	            break;
	            
	}
	
}
int main(){
	
	int i = 0 ;  //�T�C�R���̖� 1�`6
	int k ;      //�x�����Ԃ𐔂���ϐ�
	
	PMR1 = 0x00 ;	// �ėp���o�̓|�[�g�ɐݒ�
	PCR1 = 0x00 ;	// �|�[�g1��S�r�b�g���͗p�Ɏg�p

	PMR5 = 0x00 ;  	//�ėp���o�̓|�[�g�ɐݒ�
	PCR5 = 0xff ;  	//�|�[�g5��S�r�b�g�o�͗p�ɐݒ�
	PDR5 = 0xff ;  	//�|�[�g5���N���A
	
	PCR8 = 0xff ;  	//�|�[�g8��S�r�b�g�o�͗p�ɐݒ�
	PDR8 = 0xff ;  	//�|�[�g8���N���A
	
	while( 1 ) { 
		
		if( (PDR1 & P1IN) == 0 ){       //�X�C�b�`�������Ă��鎞
			
			++i;
			i=i%6;
			
			saicolo( i ) ;
			moji( i ) ;
			
			for( k = 0 ; k <= 100000 ; ++k ){   //�x��
				NOP();
			}
					
		}
		
	}
}