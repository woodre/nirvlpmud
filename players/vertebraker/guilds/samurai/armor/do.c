#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("do");
  set_short(HIW+"Do"+NORM);
  set_long("The upper-body armor of the Samurai.\n");
  set_type("armor");
  set_ac(5);
/* 07/15/07 Earwax
  set_params("physical",5,10,"do_special");
*/
  set_res(10);
  set_weight(1);
}
