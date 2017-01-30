#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("kabuto");
  set_short(HIW+"Kabuto"+NORM);
  set_long("The helmet of a Samurai.\n");
  set_type("helmet");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,5,"do_special");
*/
  set_res(1);
  set_weight(1);
}
