/* single shot, 50/50 intox - intox 6 */

inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
int val;

reset(arg){

  val = 500;
  set_short("A red pill labeled 'zp2'");
  set_weight(1);
  set_info("zp2");
  set_long(
"This is a small, oblong pill.  It has a somewhat clear, red shell,\n"+
"and is filled with a thick looking red liquid.  On the outside the\n"+
"characters 'zp2' are written in black.  You can 'pop' this pill.\n");
}

id(str){ return str == "pill" || str == "zp2"; }
is_heal(){			return 1; }
query_value(){  return val; }
set_val(x){ val = x; }

void init(){ ::init();	add_action("pop_cmd", "pop"); }

pop_cmd(str){
  int NM;
  if(environment(TO) != TP) return 0;
  if(str != "zp2" && str != "pill") return 0;
  if(!call_other(TP,"drink_alcohol", 6)) return 1;
  if(TP->checkNM())	  NM = 1;
  write(HIW+"You pop the pill labeled zp2.  "+BOLD+BLK);
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
