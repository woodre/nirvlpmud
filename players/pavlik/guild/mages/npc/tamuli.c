#include "/players/pavlik/guild/mages/defs.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Tamuli");
  set_alias("tamuli");
  set_short(HIB+"Tamuli "+NORM+"the "+HIY+"Registrar"+NORM);
  set_long(
	"Tamuli is the "+HIY+"head registrar"+NORM+" for the "+HIC+"Mages Guild"+NORM+".  Tamuli is a\n"+
	"tiny man whos balding head bobs up and down as he talks.  The\n"+
	"old wizard's ceaseless tapping can wear on a person's nerves.\n");
  set_level(30);
  set_ac(80);
  set_wc(80);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}

