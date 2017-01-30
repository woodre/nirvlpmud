inherit "obj/monster.c";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object skin;
   skin = clone_object("players/persephone/armour/alliskin");
   move_object(skin, TOB);
   init_command("wear skin");
   set_name("alligator");
   set_alias("crock");
   set_short("A Savage Sewer Alligator");
   set_long("A Savage looking alligator with large teeth. Perhaps it would\n" +
            "be safer to leave him alone\n" +
            "\n");
   set_level(16);
   set_wc(22);
   set_ac(13);
   set_hp(355);
   set_al(0);
   set_aggressive(0);
   set_gender(0);
   set_race("animal");
   set_chance(10);
   set_spell_dam(20);
   set_spell_mess1("The Alligator snarls savagely snapping its teeth.\n");
   set_spell_mess2("The Alligator clamps its jaws around you squeezing your breath away.\n");
  }
}
