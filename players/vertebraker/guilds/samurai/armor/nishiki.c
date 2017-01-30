#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("nishiki");
  set_short(HIW+"Nishiki"+NORM);
  set_long("The silky undergarments of a Samurai.\n");
  set_type("underwear");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,3,"do_special");
*/
  set_res(1);
  set_weight(1);
}
