/*  Random Boots */

#include "/players/maledicta/ansi.h"
inherit "obj/armor";
string condition;
int modifier;

reset(arg) {
switch(random(10) + 1){
case 6..1000:
condition = "average";
modifier = 3;
break;
case 4..5:
condition = "below average";
modifier = 4;
break;
case 2..3:
condition = "above average";
modifier = 2;
break;
case 1:
condition = "excellent";
modifier = 1;
break;
default:
condition = "average";
modifier = 3;
break;
}

switch(random(100) + 1){
case 60..1000:
set_name("shoes");
set_short("leather shoes");
set_long(
"This is a pair of lightweight leather shoes. They are\n"+
"made to be low with a tie at the top.  They seem to\n"+
"be in "+condition+" condition, although they don't seem\n"+
"to protect well at all.\n");
if(random(100) > 90){
set_ac(0);
}
else{
set_ac(1);
}
set_type("boots");  
set_weight(1);
set_value(30 / modifier);
break;
case 29..59:
set_name("boots");
set_short("leather boots");
set_long(
"A lightweight pair of leather boots.  They are constructed\n"+
"with a heavy leather lace that binds the front of each \n"+
"boot. They seem to be in "+condition+" shape.\n");
set_ac(1);
set_type("boots");  
set_weight(1);
set_value(100 / modifier);
break;
case 10..28:
set_name("boots");
set_short("steel reinforced boots");
set_long(
"These boots are leather and covered with lightweight\n"+
"plates of steel.  They seem capable of protecting\n"+
"against heavy damage.  The boots are in "+condition+"\n"+
"condition.\n");
if(random(100) > 90){
set_ac(2);
}
else{
set_ac(1);
}
set_type("boots");  
if(random(100) > 60){
set_weight(2);
}
else{
set_weight(1);
}
set_value(300 / modifier);
break;
case 0..9:
set_name("boots");
set_short("heavy steel boots, with shin-guards");
set_long(
"This pair of heavy boots is covered with plates of\n"+
"steel, with large iron guards rising up over the\n"+
"tops and protecting the shins. The boots are in\n"+
""+condition+" condition.\n");
if(random(100) > 80){
set_ac(2);
}
else{
set_ac(1);
}
set_type("boots");
if(random(100) > 30){  
set_weight(2);
}
else{
set_weight(3);
}
set_value(500 / modifier);
break;
default:
set_name("boots");
set_short("heavy steel boots, with shin-guards");
set_long(
"This pair of heavy boots is covered with plates of\n"+
"steel, with large iron guards rising up over the\n"+
"tops and protecting the shins. The boots are in\n"+
""+condition+" condition.\n");
if(random(100) > 80){
set_ac(2);
}
else{
set_ac(1);
}
set_type("boots");
if(random(100) > 30){  
set_weight(2);
}
else{
set_weight(3);
}
set_value(500 / modifier);
break;
}
}
