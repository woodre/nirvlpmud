#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("obi");
  set_short(HIW+"Obi"+NORM);
  set_long("The belt of a Samurai.\n");
  set_type("belt");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,3,"do_special");
*/
  set_res(1);
  set_weight(1);
}
