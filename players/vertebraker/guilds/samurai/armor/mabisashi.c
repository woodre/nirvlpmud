#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("mabisashi");
  set_short(HIW+"Mabisashi"+NORM);
  set_long("A visor that protrudes from the Kabuto.\n");
  set_type("misc");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,5,"do_special");
*/
  set_res(1);
  set_weight(1);
}
