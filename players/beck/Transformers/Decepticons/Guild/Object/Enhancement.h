string Name;
status Online;
object Base;
int Energon;

SName(string name){
   Name = name;
}
QName(){
   return Name; 
}
SBase(object base){
   Base = base;
}

QBase(){
   return Base;
}
SOnline(status online){
   Online = online;
}

QOnline(){
   return Online;
}
AEnergon(arg){
Energon += arg;
}

QEnergon(){
return Energon;
}
