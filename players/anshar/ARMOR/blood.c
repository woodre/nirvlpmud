#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "/obj/monster";
 
reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_name(HIR+"BLOOD"+NORM);
    set_short(HIR+"BLOOD"+NORM);
    set_race( "blood");
    set_long("Blood\n");
    set_level(100);
    set_ac(1000);
    set_wc(1000);
    set_hp(10000);
    set_al(0);
    set_aggressive(0);
  }
}
