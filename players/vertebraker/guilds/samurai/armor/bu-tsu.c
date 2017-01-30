#include <ansi.h>
inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("bu-tsu");
  set_alias("bu");
  SetMultipleIds(({"tsu"}));

  set_short(HIW+"Bu-Tsu"+NORM);
  set_long("The heavy boots of a Samurai.\n");
  set_type("boots");
  set_ac(2);
/* 07/15/07 Earwax
  set_params("physical",2,5,"do_special");
*/
  set_res(1);
  set_weight(1);
}
