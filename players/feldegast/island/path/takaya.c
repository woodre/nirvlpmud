#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

object skybeast;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("takaya");
  set_alias("witch");
  set_short("Takaya the Witch (Dark Heart)");
  set_long(
"Takaya is easily the most disgusting creature you've ever\n"+
"seen.  Her hair slithers with snakes and worms and maggots.\n"+
"Her skin is mottled and slimy like a toad's.  Her fingers\n"+
"are like sausages with fingernails like sharp blades dipped\n"+
"in poison.  And her eyes...Like twin ponds swirling with the\n"+
"slimiest, loathsome creatures ever to stalk the night.\n"
  );
  set_gender("female");
  set_race("spirit");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(160);
  set_al(-1000);
  add_money(500);
  enable_commands();
}

init() {
  add_action("block","east");
  add_action("block","north");
  call_out("script",1);
}
script() {
  if(!skybeast) {
  say("\nTakaya cackles loudly, a sound akin to a legion of fingernails\n"+
      "scratching across a chalkboard.\n"+
      "Takaya screeches: Ignorant mortal!  You would dare intrude into my\n"+
      "  jungle haven??  For your impudence, you shall know "+HIR+"FIRE"+NORM+"!\n");
  skybeast=clone_object("/players/feldegast/island/path/skybeast");
  move_object(skybeast,environment(this_object()));
  move_player("east#players/feldegast/island/path/path6");
  }
}
block() {
  write("Takaya says: Turn back while you still can!\n");
  return 1;
}
