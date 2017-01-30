/* traveler stands a bridge.c in dar/outside
   He will eventually check for items or weapons that belonged to the cabal
   and attack whoever is carrying them, once I figure out how to code that */

#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/outside/"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;

move_object(clone_object(ROOT+"wep/cutter.c"),this_object());
move_object(clone_object(ROOT+"obj/strawhat.c"),this_object());
move_object(clone_object(ROOT+"obj/jerkin.c"),this_object());

  set_name("Bokaru Togashi");
  set_alias("bokaru");
  set_alt_name("traveler");
  set_race("human");
  set_short("A lone traveler stands upon the bridge");
  set_long("descript of traveler here");
  set_hp(1000+random(250));
  set_level(25);
  set_al(1000);
  set_wc(42+random(7));
  set_ac(25);
  set_heal(9,18);
  set_aggressive(0);
  
  set_dead_ob(this_object());

  set_chat_chance(20);
  set_a_chat_chance(35);
  load_chat("The Earth Elemental bellows:  BEGONE!!!!\n");
  load_chat("The Earth Elemental bellows: He is NOT to be disturbed!\n");
  load_a_chat("The elemental slams you with a powerful fist.\n");

  set_chance(40);
  set_spell_dam(50+random(80));
  set_spell_mess1("\nBokaru slashes at his foe!\n\n");
  set_spell_mess2("\nBokaru slashes at you!\n\n");

  set_mult(2);
  set_mult_chance(40);
  set_mult_dam1(20);
  set_mult_dam2(13);

}

monster_died() {
object ob;
ob=clone_object("/players/daranath/items/earth_eye.c");
  move_object(ob,this_object());
return 0;
}
