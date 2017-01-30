#include <ansi.h>
inherit "obj/treasure";
string COLOR;
reset(arg) {
   COLOR = END;
   if (arg) return;
   set_short("A title fixer");
   set_alias("fixer");
   set_weight(0);
   set_value(0);
set_long("A title fixer.  Type \"colors\" to choose a color and then type\neither titlefix <str>, prefix <str>, or setalfix <str> to change those in your\ntitle.\n");
}
init() {
  add_action("colors","colors");
  add_action("tfix","titlefix");
  add_action("pfix","prefix");
  add_action("sfix","setalfix");
}
colors() {
write("The choices are:\n");
write("1. "+WHITE+"White"+END+"\n");
write("2. "+RED+"Red"+END+"\n");
write("3. "+GREEN+"Green"+END+"\n");
write("4. "+BROWN+"Brown"+END+"\n");
write("5. "+BLUE+"Blue"+END+"\n");
write("6. "+PURPLE+"Purple"+END+"\n");
write("7. "+LIGHT_BLUE+"Light Blue"+END+"\n");
write("8. "+REV_RED+"Reversed Red"+END+"\n");
write("9. "+REV_GREEN+"Reversed Green"+END+"\n");
write("10."+REV_BROWN+"Reversed Brown"+END+"\n");
write("11."+REV_BLUE+"Reversed Blue"+END+"\n");
write("12."+REV_L_BLUE+"Reversed Light Blue"+END+"\n");
write("13."+REV_PURPLE+"Reversed Purple"+END+"\n");
write("\nEnter your choice now: ");
input_to("data");
write("\n");
return 1;
}
data(str) {
int x;
if(!str) {
 write("\nYou need to supply a number.\n");
 return 1;
}
sscanf(str,"%d",x);
if(x<1 || x>13) {
  write("\nThat number is out of my range.\n");
  return 1;
}
if(x==1) COLOR = WHITE;
if(x==2) COLOR = RED;
if(x==3) COLOR = GREEN;
if(x==4) COLOR = BROWN;
if(x==5) COLOR = BLUE;
if(x==6) COLOR = PURPLE;
if(x==7) COLOR = LIGHT_BLUE;
if(x==8) COLOR = REV_RED;
if(x==9) COLOR = REV_GREEN;
if(x==10) COLOR = REV_BROWN;
if(x==11) COLOR = REV_BLUE;
if(x==12) COLOR = REV_L_BLUE;
if(x==13) COLOR = REV_PURPLE;
write("\nDone.\n");
return 1;
}


tfix(str) {
if(!str) {
  write("Please supply a title for the fixit.\n");
  return 1;
}
this_player()->set_title(COLOR+str+END);
write("Done.\n");
return 1;
}

sfix(str) {
if(!str) {
  write("Please supply a title.\n");
  return 1;
}
this_player()->set_al_title(COLOR+str+END);
write("Done.\n");
return 1;
}

pfix(str) {
if(!str) {
  write("Please supply a title.\n");
  return 1;
}
this_player()->set_pretitle(COLOR+str+END);
write("Done.\n");
return 1;
}
