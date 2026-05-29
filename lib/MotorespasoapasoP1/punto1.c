#include "punto1.h"

int pasos_normal[4][4]={
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1},
  
};

int pasos_completo[4][4]={
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},
  
};

int pasos_medio[8][4]={
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,1},
    {0,0,0,1},
    {1,0,0,1},
  
};





void pasoNormal_init(int IN0, int IN1, int IN2, int IN3){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int pines[4]={IN0, IN1, IN2, IN3};
    for(int i=0; i<7; i++){
        if(pines[i]<8){ 
            GPIOA->CRL&=~(0xf<<(pines[i]*4));
            GPIOA->CRL|=(0x1<<pines[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(pines[i]%8)*4);
            GPIOA->CRH|=(0x1<<(pines[i]%8)*4);
        }
    }
}

void pasoNormal(int IN0, int IN1, int IN2, int IN3, int pasos){
    int pines[4]={IN0, IN1, IN2, IN3};

    for(int i; i < pasos; i++){
        for(int j; j<4; j++){
            if(pasos_normal[i%4][j])GPIOA->BSRR|=(1<<pines[j]);
            else GPIOA ->BSRR |=(1<<(pines[j]+16)); 
        }
    }
}









void pasoCompleto_init(int IN0, int IN1, int IN2, int IN3){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int pines[4]={IN0, IN1, IN2, IN3};
    for(int i=0; i<7; i++){
        if(pines[i]<8){ 
            GPIOA->CRL&=~(0xf<<(pines[i]*4));
            GPIOA->CRL|=(0x1<<pines[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(pines[i]%8)*4);
            GPIOA->CRH|=(0x1<<(pines[i]%8)*4);
        }
    }
}

void pasoCompleto(int IN0, int IN1, int IN2, int IN3, int pasos){
      int pines[4]={IN0, IN1, IN2, IN3};

    for(int i; i < pasos; i++){
        for(int j; j<4; j++){
            if(pasos_normal[i%4][j])GPIOA->BSRR|=(1<<pines[j]);
            else GPIOA ->BSRR |=(1<<(pines[j]+16)); 
        }
    }
}








void pasoMedio_init(int IN0, int IN1, int IN2, int IN3){
       RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int pines[4]={IN0, IN1, IN2, IN3};
    for(int i=0; i<7; i++){
        if(pines[i]<8){ 
            GPIOA->CRL&=~(0xf<<(pines[i]*4));
            GPIOA->CRL|=(0x1<<pines[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(pines[i]%8)*4);
            GPIOA->CRH|=(0x1<<(pines[i]%8)*4);
        }
    }
}
 

void pasoMedio(int IN0, int IN1, int IN2, int IN3, int pasos){
      int pines[4]={IN0, IN1, IN2, IN3};

    for(int i; i < pasos; i++){
        for(int j; j<8; j++){
            if(pasos_normal[i%8][j])GPIOA->BSRR|=(1<<pines[j]);
            else GPIOA ->BSRR |=(1<<(pines[j]+16)); 
        }
    }
}

