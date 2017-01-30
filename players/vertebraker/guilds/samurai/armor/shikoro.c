#include "../def.h"

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shikoro");
  set_short(HIW+"Shikoro"+NORM);
  set_long("The neckguard of a Samurai.\n");
  set_type("necklace");
  set_ac(0); /* Earwax: it's a necklace, no ac */
/* 07/15/07 Earwax
  set_ac(2);
  set_params("physical",2,5,"do_special");
*/
  set_res(1);
  set_weight(1);
}
