#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;

  set_name("Necromantic Guardian");
  set_alias("guard");
  set_alt_name("guardian");
  set_race("undead");
  set_short("A Dark Guardian");
  set_long("The Dark Guardian stands tall before you, its powerful torso fading\n"+
           "out into mist. It does not seem to be carrying a weapon, \n"+
           "although it does stand here protecting something.\n");
  set_hp(1200);
  set_level(22);
  set_al(-1200);
  set_wc(38);
  set_ac(22);
  set_heal(8,15);
  set_aggressive(0);
  
  set_dead_ob(this_object());

  set_chat_chance(20);
  set_a_chat_chance(35);
  load_chat("The Dark Guardian bellows: BEGONE!!!!\n");
  load_chat("The Dark Guardian states: Only a Necromancer may pass!!!!\n");
  load_a_chat("Dark Guardian slashes at you with a mystical weapon.\n");

  set_chance(35);
  set_spell_dam(50+random(100));
  set_spell_mess1("The Dark Guardian crushes its foe!\n");
  set_spell_mess2("The guardian tears into you with a mystical weapon.\n");

  set_mult(2);
  set_mult_chance(40);
  set_mult_dam1(20);
  set_mult_dam2(13);

}

monster_died() {
object ob;
/* Fixed the path.  -Feldegast 12-22-00 */
ob=clone_object("/players/daranath/qualtor/wep/dark_blade.c");
  move_object(ob,this_object());
return 0;
}
