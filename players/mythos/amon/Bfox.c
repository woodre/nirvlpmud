inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("wolf");
  set_race("spirit");
  set_short("A Big Wolf");
  set_long("A Big Bad Wolf.  The wolf seems viscious, there seems to be a \n"+
           "glint of intelligence in those eyes.\n");
  set_hp(120);
  set_level(8);
  set_al(-350);
  set_wc(12);
  set_ac(7);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The wolf seems to grin- saliva dribbles from its mouth.\n");
  load_chat("The wolf growls.\n");
  load_a_chat("The wolf howls and hungers for your flesh.\n");
  load_a_chat("The wolf grins.\n");
  move_object(clone_object("/players/mythos/amisc/mirror.c"),this_object());
}

monster_died() {
  object ob;
  tell_room(environment(this_object()),
    "\nThe wolf HOWLS a howl of utter hatred.\n"+
    "\nAs the wolf dies a great dark A U R A seems \n"+
    "to float out of the wolf's body.\n\n\n");
  ob = clone_object("/players/mythos/amon/change.c");
  move_object(ob,environment(this_object()));
return 0;
}
