inherit "obj/monster";
#include "/players/illarion/dfns.h"

reset(arg) {
  object wep;
  if(!present("weapon",this_object())) {
    wep=clone_object("players/illarion/herc/bweap");
    wep->set_type(({"sword","mace"})[random(2)]);
    move_object(wep,this_object());
  }
  ::reset(arg);
  if(arg) return;

  set_name("Goon #1");
  set_race("human");
  set_gender("male");
  set_short("A large, beefy goon");
  set_long(
"Receding hair shows a sloping forehead over bushy eyebrows and slightly\n"+
"dull eyes.  Solidly built, this man undoubtedly has a bit of muscle\n"+
"underneath the flab he's gotten from too many fatty foods.  He\n"+
"is wearing jeans, and what looks like a surplus military shirt.\n");
  set_level(15);
  set_al(-200);
  set_hp(200+random(50));
  add_money(800);
  set_wc(20);
  set_ac(12);
  set_chat_chance(7);
  load_chat("The big goon scratches himself.\n");
  load_chat("You catch a very undesired whiff of armpits...\n");
  set_a_chat_chance(7);
  load_a_chat("The big goon tries to knee you in the crotch.\n");
  load_a_chat("You rebound off the goon's fat.\n");
}
id(str) { return ::id(str) || str == "goon" || str == "neandrithal"; }
