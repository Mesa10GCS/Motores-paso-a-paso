#include "punto1.h"
#include "punto2.h"
int main(){
pasoMedio_init(0, 1, 2, 3);
MotorPaP_init(0, 1, 2, 3);

while(1){
pasoMedio(0, 1, 2, 3, 5);
MotorPaP(0, 1, 2, 3, 'n', 5);
}
}