string Name;
status Online;
object Base;
int Power;

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
   return "/players/beck/Rangers/CommandCenter/CommandCenter";
}
SOnline(status online){
   Online = online;
}

QOnline(){
   return Online;
}
APower(arg){
Power += arg;
}

QPower(){
return Power;
}
