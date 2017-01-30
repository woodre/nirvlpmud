/*  Random Gloves */

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
set_name("gloves");
set_short("a pair of leather gloves.");
set_long(
"  This is a pair of leather gloves. They seem to be in\n"+
""+condition+" condition, and capable of withstanding some\n"+
"damage.\n"); 
set_ac(1);
set_type("ring");  
set_weight(1);
set_value(50 / modifier);
break;
case 29..59:
set_name("gauntlets");
set_short("a pair of steel gauntlets.");
set_long(
"This is a pair of heavy steel gauntlets. They seem to be in\n"+
""+condition+" shape, and built to withstand direct attacks.\n");
if(random(100) > 94){
set_ac(2);
}
else{
set_ac(1);
}
set_type("ring");  
if(random(100) > 20){
set_weight(1);
}
else{
set_weight(2);
}
set_value(150 / modifier);
break;
case 10..28:
set_name("gloves");
set_short("a pair of iron bracers.");
set_long(
"These are a pair of heavy iron bracers, which protect\n"+
"the tops of the hands, as well as the forearms. They\n"+
"are in "+condition+" shape, and seem ready to take some\n"+
"damage.\n");
set_ac(1);
set_type("ring");  
if(random(100) > 20){
set_weight(1);
}
else{
set_weight(2);
}
set_value(200 / modifier);
break;
case 0..9:
set_name("gloves");
set_short("a pair of spiked gloves.");
set_long(
"This is a pair of heavy spiked gloves, capable of resisting\n"+
"damage, and dealing it to those who dare get close enough. They\n"+
"seem to be in "+condition+" condition.\n");
if(random(100) > 75){
set_ac(2);
}
else{
set_ac(1);
}
set_type("ring");  
set_weight(2);
set_value(400 / modifier);
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
