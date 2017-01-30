inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("fudo");
  set_race("avatar");
  set_short("Fudo- The Enforcer of Justice");
  set_long("An avatar of Budda, here stands Fudo.  He is a tall muscular\n"+
           "man with an aura of might around him.  You notice something\n"+
           "is wrong- he wields a snake and his leg is tied to the\n"+
           "staircase by his own Rope of Binding!\n");
  set_hp(1000);
  set_level(25);
  move_object(clone_object("/players/mythos/awep/forest/snake.c"),this_object());
init_command("wield snake");
  set_al(0);
  set_wc(55);
  set_ac(18);
  set_dead_ob(this_object());
  set_heal(3,10);
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(15);
  load_chat("Fudo looks angry- very angry.\n");
  load_chat("The Avatar glares at you.\n");
  load_a_chat("Fudo bellows: Hunter you shall die!\n");
  load_a_chat("A large fist knocks you back!\n");
  move_object(clone_object("/players/mythos/amisc/forest/rope.c"),this_object());
}


monster_died() {
write_file("/players/mythos/logs/tower",ctime(time())+" "+
  (this_object()->query_attack())->query_real_name()+"  FUDO-snake\n");
return 0;
}


heart_beat() {
  if(random(3)) {
     set_wc(55);
  set_ac(18);
} else {
  set_wc(80);
  set_ac(15);
}
  ::heart_beat();
}
