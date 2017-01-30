inherit "obj/monster";
#include "/players/persephone/rooms.h"
object grunge;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      grunge=clone_object("players/persephone/closed/key3");
       move_object(grunge, TOB);
      set_name("ooze");
      set_alias("slime");
      set_short("A Brownish Ooze");
      set_long("An amorphic mass of brown ooze that seems to spread\n"+
               "out to fill the area that is available\n");
      set_level (18);
      set_wc (26);
      set_ac (15);
      set_hp(450);
      set_al(-500);
      set_aggressive(1);
      set_gender (0);
      set_chance(20);
      set_spell_dam(random(20));
      set_spell_mess1("The Slime forms a shape\n");
      set_spell_mess2("The Slime begins to eat through your armour\n");
}

