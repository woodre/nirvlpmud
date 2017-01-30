inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object horn;
   horn = clone_object("players/persephone/obj/horn.c");
   move_object(horn, TOB);
   init_command("wield horn");
   set_name("goat");
   set_alias("chamois");
   set_short("An Impressive Mountain Goat");
   set_long("This is one of the largest mountain goats you have\n" +
            "ever seen with majestic horns\n\n");
   set_level (5);
   set_wc(9);
   set_ac(5);
   set_hp(75);
   set_al(-100);
   set_aggressive(0);
   set_gender(0);
   set_chance(5);
   set_spell_dam(5);
   set_spell_mess1("The goat charges furiously with his horns lowered");
   set_spell_mess2("The goat buts you with his horns gashing you severely");

  }
}
