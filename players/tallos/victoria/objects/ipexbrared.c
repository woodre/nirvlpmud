#include "/players/fred/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("bra");
  set_alias("underwear");
  set_short(BOLD+"An "+HIB+"<"+HIR+"IPEX"+HIB+">"+NORM+""+HIR+" Bra and Panties"+NORM);
  set_long(
  "         This set of "+HIR+"bra"+NORM+" and"+HIR+" panties"+NORM+" is from the "+HIM+"Victoria's\n"+
  "Secret"+HIB+" <"+HIR+"IPEX"+HIB+">"+NORM+""+NORM+" series.  It is often known as the worlds most\n"+
  "advanced "+HIR+"bra"+NORM+". It's virtually weightless, has maximum "+NORM+""+RED+"nipple"+NORM+"\n"+
  "coverage, and minimal "+HIY+"padding"+NORM+". Far considered to be amongst\n"+
  "the most comfortable and best fitting of all "+HIR+"bras"+NORM+".\n");
  set_type("underwear");
  set_type("underwear");
  set_ac(1);
  set_weight(0);
  set_value(10000);
/*  WHY - Bp
  set_save_flag();
*/
}

