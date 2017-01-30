/*  Random Helmet */

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
case 80..1000:
set_name("cap");
set_short("a leather cap");
set_long(
"This is a lightweight leather cap. It is more commonly\n"+
"used to block the sun or a chill wind than a weapon. It\n"+
"seems to be in "+condition+" condition.\n");
if(random(100) < 90){
set_ac(0);
}
else{
set_ac(1);
}
set_type("helmet");  
set_weight(1);
set_value(30 / modifier);
break;
case 29..79:
set_name("helm");
set_short("a small helm");
set_long(
"This is a lightweight steel helm. It covers the top\n"+
"of the head, and some of the sides, offering decent\n"+
"protection against attacks. The helm is in "+condition+"\n"+
"condition.\n");
set_ac(1);
set_type("helmet");  
set_weight(1);
set_value(100 / modifier);
break;
case 10..28:
set_name("helm");
set_short("great helm");
set_long(
"This is a large helm. It covers the top and sides of\n"+
"the head with good protection, while also covering\n"+
"the upper half of the face. It is in "+condition+"\n"+
"shape.\n");
if(random(100) > 90){
set_ac(2);
}
else{
set_ac(1);
}
set_type("helmet");  
if(random(100) > 60){
set_weight(2);
}
else{
set_weight(1);
}
set_value(300 / modifier);
break;
case 0..9:
set_name("helmet");
set_short("large visored helmet");
set_long(
"This is a large helmet, which covers the head fully,\n"+
"as well as the face. It is made of a heavy steel, and\n"+
"seems to be in "+condition+" condition.\n");
if(random(100) > 70){
set_ac(2);
}
else{
set_ac(1);
}
set_type("helmet");
if(random(100) > 30){  
set_weight(2);
}
else{
set_weight(3);
}
set_value(600 / modifier);
break;
default:
set_name("helmet");
set_short("large visored helmet");
set_long(
"This is a large helmet, which covers the head fully,\n"+
"as well as the face. It is made of a heavy steel, and\n"+
"seems to be in "+condition+" condition.\n");
if(random(100) > 70){
set_ac(2);
}
else{
set_ac(1);
}
set_type("helmet");
if(random(100) > 30){  
set_weight(2);
}
else{
set_weight(3);
}
set_value(600 / modifier);
break;
}
}
