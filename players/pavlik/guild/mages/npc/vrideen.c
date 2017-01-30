#include "/players/pavlik/guild/mages/defs.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Vrideen");
  set_alias("vrideen");
  set_short(GRN+"Vrideen "+NORM+HIBLK+"the Dragon Trainer"+NORM);
  set_long(
	"Vrideen is an old wrinkled lump of flesh.  However you can read strength\n"+
	"and awesome power in his dark "+BLU+"dark eyes"+NORM+".  The Dragon Master has been working\n"+
	"with dragons since he was a small child, and he has the "+RED+"scars"+NORM+" to prove it!\n");
  set_level(30);
  set_ac(10);
  set_wc(30);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}

