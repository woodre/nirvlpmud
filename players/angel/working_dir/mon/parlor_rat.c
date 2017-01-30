/*
 parlor_rat.c
*/
 
inherit "obj/monster";

object rat;

int rat_count;

init() {
  ::init();

  set_heart_beat(1);
}

heart_beat() {
  ::heart_beat();

  if (rat_count < 5) {
    say("Another rat enters the room through the hole in the corner.\n");
    rat=clone_object("/obj/monster");
    rat->set_name("rat");
    rat->set_alt_name("nooneelserat");
    rat->set_level(4);
    rat->set_hp(25);
    rat->set_wc(7);
    rat->set_ac(2);
    rat->set_ep(700);
    rat->set_al(0);
    rat->set_short("a rat");
    rat->set_long("It's a huge, ugly, hungry, rat.\n");
    rat->set_whimpy(1);
    rat->set_aggressive(1);
    move_object(rat, environment(this_object()));
    rat_count++;
  }
}

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;

  if (arg) return;
  ::reset(arg);

  set_name("rat");
  set_alt_name("nooneelseparlorrat");
  set_level(4);
  set_hp(25);
  set_wc(7);
  set_ac(2);
  set_ep(700);
  set_al(0);
  set_short("a rat");
  set_long("It's a huge, ugly, hungry, rat.\n");
  set_whimpy(0);
  set_aggressive(1);
  enable_commands();
  set_heart_beat(1);
}
