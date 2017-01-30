inherit "/obj/monster";
int ack,qq,q,kkk;
object envir;
reset(arg)  {
  object weapon;
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
  set_level(14);
  set_hp(210);
  set_al(-500);
  set_wc(18);
  set_ac(11);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("The trolloc looks at your fearsome weapon.\n");
  load_chat("Trolloc grips his club tightly and waits.\n");
  set_a_chat_chance(15);
  load_a_chat("The trolloc swings his club in a wide arc.\n");
  load_a_chat("Trolloc rasps: 'The dark one commands, and I obey.'\n");
  set_chance(10);
  set_spell_dam(5);
  set_spell_mess1("The trolloc snorts and coughs blood. \n");
  set_spell_mess2("The trolloc snorts and sprays you with blood. \n");
  add_money(450);
weapon=clone_object("/players/fakir/ways/WEP/club.c");
move_object(weapon,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "The trolloc falls first to his knees, then sprawls on the ground.\n");
  return 0; }
