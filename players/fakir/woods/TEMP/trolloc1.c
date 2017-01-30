inherit "/obj/monster";
int ack,qq,q,kkk;
object envir;
reset(arg)  {
  object armor;
  ::reset(arg);
  if(arg) return;
  set_name("trolloc");
  set_alias("troll");
  set_race("creature");
  set_short("Trolloc");
  set_long(
"   Creature of the Dark One, created during the war of the shadow.\n"+
"Huge in stature, vicious in the extreme, he is a twisted blend of\n"+
"animal and human stock, and he kills for the sheer pleasure of\n"+
"killing.  Sly, deceitful, and treacherous, he can be trusted\n"+
"only by those he fears. \n");
  set_level(15);
  set_hp(225);
  set_al(-600);
  set_wc(20);
  set_ac(12);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("The trolloc licks his lips and drools. \n");
  set_a_chat_chance(15);
  load_a_chat("The trolloc sidesteps and bites your shoulder. \n");
  set_chance(10);
  set_spell_dam(5);
  set_spell_mess1("The trolloc snorts and coughs blood. \n");
  set_spell_mess2("The trolloc snorts and gouges your eye. \n");
  add_money(500);
armor=clone_object("/players/fakir/ways/ARM/cape.c");
move_object(armor,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "The trolloc whistles to his tribe with his last breath. \n");
  return 0; }
