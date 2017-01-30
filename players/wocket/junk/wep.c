#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";
reset(arg){
  set_short("The darkblade of tarkis");
  set_weight(1);
  set_value(200);
  set_class(10);
}
id(str){ return str == "blade"; }
query_gsave(){ return 1; }
query_dwep(){ return 1; }
query_sac(){ return 10000; }
