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
  set_short("Large Trolloc");
  set_long(
"   Creature of the Dark One, created during the war of the shadow.\n"+
"Huge in stature, vicious in the extreme, he is a twisted blend of\n"+
"animal and human stock, and he kills for the sheer pleasure of\n"+
"killing.  Sly, deceitful, and treacherous, he can be trusted\n"+
"only by those he fears. \n");
  set_level(16);
  set_hp(400);
  set_al(-600);
  set_wc(22);
  set_ac(13);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("Trolloc grunts and shifts his feet.\n");
  load_chat("Scratching behind one ear, the Trolloc seems distracted.\n");
  load_chat("The Trolloc picks a bug out of its matted fur.\n");
  set_a_chat_chance(15);
  load_a_chat("The large trolloc moves to block access to the bridge nearby.\n");
  load_a_chat("Trolloc rasps: 'You are such a small target!  Come back when you grow.'\n");
  add_money(1500);
}

monster_died() {
  tell_room(environment(this_object()),
  "The trolloc falls with a loud 'THUMP'.\n");
  return 0; }
