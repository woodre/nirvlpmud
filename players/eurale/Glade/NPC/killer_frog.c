#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("killer frog");
set_alias("frog");
set_race("creature");
set_short("Name");
set_long(
  "  This is a killer frog.  Although resembling its ordinary cousins\n"+
  "it has a light green back and striped back legs.  Its long, sticky\n"+
  "tongue secreets a poisonous substance and it will attack with both\n"+
  "its sharp teeth and pointed front talons.\n");

set_level(16);
set_hp(400);
set_al(-25);
set_wc(22);
set_ac(13);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("The frogs sides heave in and out as he breathes.\n");

set_chance(20);
set_spell_dam(25);

set_spell_mess1(
  "\nThe little frog "+HIG+"LEAPS and STICKS"+NORM+
  " its tongue to the flesh of its foe.\n");
set_spell_mess2(
  "\nThe little frog "+HIG+"LEAPS and STICKS"+NORM+
  " its tongue to your flesh.......STINGS!\n");

}

monster_died() {
  move_object(clone_object("players/eurale/Glade/OBJ/froglegs.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
    "\nWith a final blow, you smash the life out of the "+BOLD+
    "killer frog"+NORM+".\n");
return 0; }

short(){ return HIG+"a killer frog"+NORM; } /* by x 7-30-2005*/
