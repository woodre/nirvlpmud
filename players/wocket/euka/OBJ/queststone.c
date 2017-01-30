#include "/players/wocket/closed/ansi.h"
string COLOR;
int number;

id(str){ return (str == "stone" || str == "stone"+number || str == "euka_quest_stone"); }
short(){
return COLOR+"A glowing stone"+OFF;
}
long(){
  write("This is one of the three stones of Euka.  When placed with its brothers\n"+
        "legend has it that it will guard and protect the forest from danger.  This\n"+
        "stone seems to "+COLOR+"glow"+OFF+" with a gentle brightness.\n");
}
get(){ return 1; }
drop(){ return 0; }
query_weight(){ return 1;}
query_value(){ return 1000; }
set_number(i){
number = i;
switch(number){
case 0:  COLOR = HIR; break;
case 1:  COLOR = HIC; break;
case 2: COLOR = HIY; break;
}
}
