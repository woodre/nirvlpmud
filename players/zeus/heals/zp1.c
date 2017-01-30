/* single shot, 50/50 3 stuff / 3 soak */

inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
int val;

reset(arg){
  if(arg) return;

  val = 500;
  set_short("A white pill labeled 'zp1'");
  set_weight(1);
  set_info("zp1");
  set_long(
"This is a small white pill.  It has an oval shape with the tiny\n"+
"characters 'zp1' written in black on the center of it.  To make\n"+
"use of its healing properties, you should 'pop' it.\n");
}

id(str){ return str == "pill" || str == "zp1"; }
is_heal(){			return 1;   }
query_value(){  return val; }
set_val(x){ val = x; }

void init(){ ::init();	add_action("pop_cmd", "pop"); }

pop_cmd(str){
  int NM;
  if(environment(TO) != TP) return 0;
  if(str != "zp1" && str != "pill") return 0;
  if(!TP->eat_food(3) || !TP->drink_soft(3)) return 1;
  if(TP->checkNM())	  NM = 1;
  write(HIW+"You pop the pill labeled zp1.  "+BOLD+BLK);
  this_player()->heal_self(50);
  write("HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
	 write("SP [???/"+TP->query_msp()+"]\n"+NORM);
  else {
     write("SP ["+TP->query_spell_point()+"/"+
     TP->query_msp()+"]\n"+NORM); 
  }
  say(TP->QN+" pops a pill.\n");
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}
