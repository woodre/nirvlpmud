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
  set_short("Deformed Trolloc");
  set_long(
"   Creature of the Dark One, created during the war of the shadow.\n"+
"Huge in stature, vicious in the extreme, he is a twisted blend of\n"+
"animal and human stock, and he kills for the sheer pleasure of\n"+
"killing.  Sly, deceitful, and treacherous, he can be trusted\n"+
"only by those he fears. \n");
  set_level(11);
  set_hp(165);
  set_al(-400);
  set_wc(15);
  set_ac(9);
  set_dead_ob(this_object());
  add_money(400 +random(150));
}

monster_died() {
  tell_room(environment(this_object()),
  "The deformed trolloc succumbs to your blows.\n");
  return 0; }
