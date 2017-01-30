#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor.c";

reset(arg){
  if(arg) return;
  set_id("teddy");
  set_alias("lace teddy");
  set_short("A "+HIR+"red lace "+OFF+"teddy ("+HIR+get_adjective()+OFF+")");
  set_long(""+
    "This is a very nice red lace teddy.  It has a sheer bodice\n"+
    "and ties up in the back.  A small rose pattern has been woven\n"+
    "into the lace proficing minimal coverage.  The cups are full and\n"+
    "supportive and seem very form fitting.  This would make anyone\n"+
    "look very alluring.\n");
  set_weight(0);
  set_ac(3);
  set_type("armor");
}

extra_look(){
  write(HIR+environment()->query_name()+" is very seductive in "+environment()->query_possessive()+" lace teddy.\n"+OFF);
}

get_adjective(){
string adj;
  switch(random(5)){
  case 0:  adj = "seductive"; break;
  case 1:  adj = "sexy"; break;
  case 2:  adj = "irresitable"; break;
  case 3:  adj = "provocative";
  case 4:  adj = "delicate"; break;
  default: adj = "alluring"; break;
  }
  return adj;
}

do_special(owner){
  if(random(20) == 1){
    tell_object(owner,HIR+"Your sexiness has distracted "+owner->query_attacker()->query_name()+OFF+".\n");
    return 3;
  }
  return 0;
}
