inherit"obj/monster";
int i;
reset(arg) {
  ::reset(arg); /* verte */
  if(arg) return;
if(!present("nucleus")) {
  move_object(clone_object("players/hippo/heals/nucleus"),this_object()); }

set_name("thrombo");
set_alias("thrombocyte");
set_short("A thrombocyte");
set_alias("thrombocyte");
money = 400;
set_long(
  "A thrombocyte, or thrombo.  The blood cell that can cope with nearly\n"+
  "any intruder.\n");
set_level(20);
set_wc(30);
set_ac(17);
/* Now aggressive 50% from non-aggressive  -Snow */
set_aggressive(random(2));
set_hp(500);

  }

/*
#include "/players/mythos/amon/hb_ag.h"
*/
