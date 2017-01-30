inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A pill");
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill" || str == "kill_check_object"; }

  init(){
  ::init();
  add_action("swallow_pill", "swallow");
}



swallow_pill(){
int a,b,c,d;
for(a =0, b=1; a < 100; a++, b++){
if(random(2)){ write("H "); c++; } else { write("T "); d++; }
if(b > 8){ write("\n"); b = 0; }
}
write("Total H: "+c+"\nTotal T: "+d+"\n");
  write("You swallow the pill.\n");
  say(TP->QN+" pops a pill.\n");
return 1;
}

