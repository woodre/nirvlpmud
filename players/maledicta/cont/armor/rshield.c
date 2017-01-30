/*  Random Shields */

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
set_name("shield");
set_short("small wooden shield");
set_long(
"This is a small lightweight shield.  It is made of wood and\n"+
"bound by iron strips of metal.  It seems to be in "+condition+"\n"+
"condition, and capable of withstanding some damage.\n");
if(!random(100)){
set_ac(2);
}
else{
set_ac(1);
}
set_type("shield");  
set_weight(1);
set_value(100 / modifier);
break;
case 29..59:
set_name("shield");
set_short("kite shield");
set_long(
"This is a large kite shield. Its frame is in the shape of\n"+
"an arrow's head, and is reinforced by a steel border. It is\n"+
"in "+condition+" condition, and capable of withstanding some\n"+
"damage.\n");
if(random(100) > 85){
set_ac(2);
}
else{
set_ac(1);
}
set_type("shield");  
if(random(100) > 20){
set_weight(2);
}
else{
set_weight(3);
}
set_value(500 / modifier);
break;
case 10..28:
set_name("shield");
set_short("steel round shield");
set_long(
"This is a heavy steel shield.  It is in the shape of a\n"+
"circle, and seems capable of resisting a lot of damage.\n"+
"It is in "+condition+" condition.\n");
if(random(100) > 70){
set_ac(2);
}
else{
set_ac(1);
}
set_type("shield");  
if(random(100) > 20){
set_weight(2);
}
else{
set_weight(3);
}
set_value(700 / modifier);
break;
case 0..9:
set_name("shield");
set_short("a buckler shield");
set_long(
" This is a very small buckler shield.  It is made of\n"+
"wood and steel, and fits easily over the fist of the\n"+
"wearer. It is in "+condition+" shape.\n");
set_ac(1);
set_type("shield");  
set_weight(1);
set_value(100 / modifier);
break;
default:
set_name("gloves");
set_short("a pair of leather gloves.");
set_long(
"  This is a pair of very worn out gloves.  They are made of\n"+
"leather, and might have at one time been nice, but now are\n"+
"delapidated and torn.\n");
set_ac(1);
set_type("ring");  
set_weight(1);
set_value(10);
break;
}
}
