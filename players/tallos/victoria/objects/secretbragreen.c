#include "/players/fred/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("bra");
  set_alias("underwear");
  set_short(BOLD+"A "+HIB+"<"+HIC+"Secret Embrace"+BLU+">"+NORM+""+GRN+" Bra and Panties"+NORM);
  set_long(
  "        This set of "+GRN+"bra"+NORM+" and"+GRN+" panties"+NORM+""+NORM+" is from the "+HIM+"Victoria's\n"+
  "Secret"+HIB+" <"+HIC+"Secret Embrace"+HIB+">"+NORM+""+NORM+" collection.  The "+GRN+"bra"+NORM+" is seam free,\n"+
  "lable free, and stitch free. It feels silky smooth against\n"+
  "the skin and provides excellent comfort and support.\n");
  set_type("underwear");
  set_ac(1);
  set_weight(1);
  set_value(2000);
/*  WHY - Bp
  set_save_flag();
*/
}

