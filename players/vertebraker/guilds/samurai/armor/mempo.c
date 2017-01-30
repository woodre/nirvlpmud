#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("mempo");
  set_alias("mempo");
  set_short(HIW+"Mempo"+NORM);
  set_long("The mask of a samurai.\n");
  set_type("mask");
  set_ac(0);
/* 07/15/07 Earwax
  set_params("physical",2,3,"do_special");
*/
  set_res(1);
  set_weight(1);
}
