/*
 vampire_corpse.c
*/

inherit "players/nooneelse/mon/nooneelse_monster";

object bloodgem, coins, bishops_ring, enemy_obj, obj, who;
string this_command, str;
int staked, death_time;

id(str) { return (str=="vampire corpse" ||
                  str=="vampirecorpse" ||
                  str=="vampire"); }

init() {
  ::init();

  add_action("stake", "stake");
  add_action("stake", "pound");
  add_action("stake", "drive");
  add_action("kill",  "kill");
  add_action("kill",  "flare");
  add_action("kill",  "fireball");
  add_action("kill",  "shock");
  add_action("kill",  "missile");
  add_action("kill",  "backstab");
  set_heart_beat(1);
}


reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_name("corpse");
  set_alias("vampirecorpse");
  set_alt_name("nooneelsevampirecorpse");
  set_level(19);
  set_hp(450);
  set_ep(700000);
  set_al(-700);
  set_wc(0);
  set_ac(20);
  set_short("the corpse of a young man");
  set_long("The hacked up, bloodied corpse of an aristocratic, young man.\n");
  set_whimpy(0);
  set_aggressive(0);
  enable_commands();
  set_heart_beat(1);
  death_time=time() + 30;
}

set_enemy(obj) { enemy_obj=obj; }

heart_beat() {
  ::heart_beat();

  if (time() < death_time) return;

  say("You see the corpse fade into a red mist and reform into the creature!\n"+
      "He stands there laughing at you!\n");
  if (enemy_obj)
    tell_object(enemy_obj,
                "You hear the vampire laughing as he whispers to you:\n"+
                "    Maybe next time mortal...\n");
  call_other("players/nooneelse/red/coffin_room", "???", 0);
  move_object(clone_object("/players/nooneelse/mon/vampire"),
              "/players/nooneelse/red/coffin_room");
  destruct(this_object());
}

stake(str) {
  if (!str) { return 0; }
  this_command=query_verb();
  if (this_command=="stake" && str!="vampire") return;
  if ((this_command=="pound" || this_command=="drive") &&
      (!str=="stake" && !str=="stake into vampire")) return;
  if (!present("stake", this_player()) || !present("hammer", this_player())) {
    say("With what?\n");
    return 1;
  }
  staked=1;
  say("As you pound the stake into the corpse, it screams and claws at you,\n"+
      "then falls back lifeless.\n");
  say("As "+this_player()->query_name()+" pounds a stake into the corpse,\n"+
      "it screams and claws at "+this_player()->query_objective()+
      ", then falls back lifeless.\n" +
      "The body then dissolves away into nothing, leaving behind a few\n"+
      "coins, a dark red gem and a ring.\n");
  call_other(this_player(), "add_exp", experience / 35);
  coins=clone_object("/obj/money");
  coins->set_money(15000);
  move_object(coins, environment(this_object()));
  bloodgem=clone_object("/players/nooneelse/obj/vampire_bloodgem");
  move_object(bloodgem, environment(this_object()));
  bishops_ring=clone_object("/players/nooneelse/obj/bishops_ring");
  bishops_ring->set_quest_solver(lower_case(this_player()->query_real_name()));
  move_object(bishops_ring, environment(this_object()));
  destruct(present("stake", this_player()));
  destruct(this_object());
  return 1;
}

kill(str) {
  if (str=="corpse" || str=="vampirecorpse") {
    write("You don't really want to hit a corpse do you?\n");
    return 1;
  }
}

init_command(cmd) { command(cmd); }

query_undead() { return 1; }
