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
  set_level(14);
  set_hp(210);
  set_al(-500);
  set_wc(18);
  set_ac(11);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("Trolloc grunts and shifts his feet.\n");
  load_chat("Scratching behind one ear, the Trolloc seems distracted.\n");
  load_chat("The Trolloc picks a bug out of its matted fur.\n");
  set_a_chat_chance(15);
  load_a_chat("The trolloc blocks your attack with its shield.\n");
  load_a_chat("Trolloc rasps: 'You are not such an easy kill.'\n");
  set_chance(10);
  set_spell_dam(5);
  set_spell_mess1("The trolloc snorts and coughs blood. \n");
  set_spell_mess2("The trolloc snorts and sprays you with blood. \n");
  add_money(450);
armor=clone_object("/players/fakir/ways/ARM/wshield.c");
move_object(armor,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "The trolloc falls first to his knees, then sprawls on the ground.\n");
  return 0; }
