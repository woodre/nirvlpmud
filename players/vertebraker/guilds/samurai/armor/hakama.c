#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("hakama");
  set_short(HIW+"Hakama"+NORM);
  set_long("The heavy leggings of a Samurai.\n");
  set_type("pants");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,5,"do_special");
*/
  set_res(1);
  set_weight(1);
}
