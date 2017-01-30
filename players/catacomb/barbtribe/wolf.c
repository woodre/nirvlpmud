#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object claw;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("wolf");
set_race("creature");
set_short("A rabid wolf");
set_long(
  "  A growling wolf crouches before you, its green eyes glowing\n"+
  "eerily.  From the size of the creature, it appears to be the\n"+
  "leader of its pack.  It growls deeply warning you not to come\n"+
  "any closer\n");
 
set_level(10);
set_hp(150);
set_al(100);
set_ac(8);
set_wc(14);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(7);
  load_chat("The wolf lets out a deep growl.\n");
}
 
monster_died(){
  tell_object(attacked,
    "As the wolf dies you rip out its claws\n");
  claw = clone_object("/players/catacomb/barbtribe/wclaw.c");
    move_object(claw, this_object());
}   