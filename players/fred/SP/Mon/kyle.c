#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("kyle");
set_race("human");
set_short("Kyle");
set_long(
  "  Kyle is the little Jewish boy that is harrassed by Cartman all\n"+
  "the time.  He also has frequent visions of Mr. Hankey the Christmas\n"+
  "Poo.\n");

add_money(350);
set_level(8);
set_hp(120);
set_al(0);
set_wc(12);
set_ac(7);
set_aggressive(0);

}


