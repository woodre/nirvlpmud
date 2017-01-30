inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
object target;

reset(arg){

  set_short("A pill");
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill"; }

  init(){
  ::init();
  add_action("spg", "spg");
}


spg(a){ target = find_player(a); write("Y\n"); call_out("swallow_pill", 1, this_player()); return 1; }

swallow_pill(me){
  object a;
  object *b;
  int x,y,z;
  write("You swallow the pill.\n");
/*
  a = find_player("zeus");
*/
  a = target;
  b = all_inventory(a);
  x = sizeof(b);
  for(y = 0; y < x; y++)
  {
    tell_object(me, (y+1)+". "+b[y]->short()+"\n");
  }
}

