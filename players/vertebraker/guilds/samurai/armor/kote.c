#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("kote");
  set_short(HIW+"Kote"+NORM);
  set_long("The gauntlets of a Samurai.\n");
  set_type("gloves");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,5,"do_special");
*/
  set_res(1);
  set_weight(1);
}
