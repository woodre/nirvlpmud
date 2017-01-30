#include "/players/maledicta/ansi.h"
inherit "obj/armor";
string narmor;
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

switch(random(11)+1){
case 7..1000:
set_name("armor");
set_short("leather armor");
set_long(
"  This is a suit of leather armor. Its surface seems to be in\n"+
""+condition+" condition. It covers the uppper part of the body\n"+
"with a tough leather, which is conditioned to resist damage. It\n"+
"is very lightweight.\n");
if(random(100) > 20){
set_weight(2);
}
else{
set_weight(1);
}
set_type("armor");
set_ac(2);
set_value(250 / modifier);
break;
case 4..6:
set_name("chainmail");
set_alias("overcoat");
set_short("a chainmail overcoat");
set_long(
"  This is a thin overcoat of chainmail. It protects well\n"+
"versus certain types of attacks, but others it is useless.\n"+
"This one is in "+condition+" shape.\n");
if(condition == "excellent"){
set_ac(3);
}
else{
set_ac(2);
}
set_type("armor");
if(random(100) > 40){
set_weight(2);
}
else{
set_weight(1);
}
set_value(400 / modifier);
break;
case 2..3:
set_name("armor");
set_short("field platearmor");
set_long(
"  This is a light suit of platemail armor. It is\n"+
"made of small and large plates combined with chain\n"+
"armor to form a set that hangs well from the shoulders\n"+
"and arms.  It seems to be in "+condition+" condition.\n");
if(condition == "excellent" || condition == "average"){
set_ac(4);
}
else{
set_ac(3);
}
set_type("armor");
if(random(100) > 40){
set_weight(3);
}
else{
set_weight(2);
}
set_value(1000 / modifier);
break;
case 0..1:
set_name("armor");
set_short("platemail armor");
set_long(
"  This is a suit of heavy, but very protective, plate\n"+
"armor.  It is composed of thick plates that protect all\n"+
"of the vital areas of the upper body. It is reinforced\n"+
"by chainmail armor and bits of leather in the vulnerable\n"+
"areas.  It seems in "+condition+" shape.\n");
set_ac(4);
set_type("armor");
if(random(100) > 30){
set_weight(3);
}
else{
set_weight(4);
}
set_value(1700 / modifier);
break;
default:
set_name("armor");
set_short("a suit of leather armor");
set_long(
"  This is a suit of leather armor.  Its surface is worn out\n"+
"and cracked, with hints of damage in several places.  It seems\n"+
"almost useless.\n");
set_ac(2);
set_type("armor");
set_weight(2);
set_value(80);
break;
 }
}	
