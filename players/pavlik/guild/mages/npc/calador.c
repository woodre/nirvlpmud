#include "/players/pavlik/guild/mages/defs.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Calador");
  set_alias("calador");
  set_short(HIC+"Calador "+NORM+CYN+"the Archmage"+NORM);
  set_long(
	"Calador is an "+CYN+"Archmage"+NORM+" of the Mage's Tower.  The old wizard has\n"+
	"been the "+HIC+"tutor"+NORM+" of young magic-users since time unknown.  His long\n"+
	"white beard nearly brushes the floor when he moves.  His intense\n"+
	GRN+"green eyes"+NORM+" speak of the "+HIC+"immense power"+NORM+" this wizard has accumlated\n"+
	"over the ages.\n");
  set_level(30);
  set_ac(80);
  set_wc(80);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}


