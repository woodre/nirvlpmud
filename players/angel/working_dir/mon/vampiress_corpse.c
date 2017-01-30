/*
 vampiress_corpse.c
*/

inherit "players/nooneelse/mon/nooneelse_monster";

object coins, vampiress_ring, enemy_obj, obj, who;

string this_command, str;

int staked, death_time;

id(str) { return (str=="vampiress corpse" ||
                  str=="vampiresscorpse" ||
                  str=="vampire corpse" ||
                  str=="vampirecorpse" ||
                  str=="vampiress"); }

init() {
  ::init();

  add_action("stake", "stake");
  add_action("stake", "pound");
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
  set_alias("vampiresscorpse");
  set_alt_name("nooneelsevampiresscorpse");
  set_level(15);
  set_hp(350);
  set_ep(500000);
  set_al(-500);
  set_wc(0);
  set_ac(20);
  set_short("the corpse of a young woman");
  set_long(
    "The hacked up, bloodied corpse of an extremely attractive young woman.\n");
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

  say("You see the corpse fade into a blue mist and reform into the "+
      "creature!\n"+
      "She stands there laughing at you!\n");
  if (enemy_obj)
    tell_object(enemy_obj,
                "You hear the vampiress laughing as she whispers to you:\n"+
                "    Maybe next time mortal...\n");
  call_other("players/nooneelse/red/cellar8", "???", 0);
  move_object(clone_object("players/nooneelse/mon/vampiress"),
              "players/nooneelse/red/cellar8");
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
  say("As "+this_player()->query_name()+" pounds a stake into the corpse,\n" +
      "it screams and claws at "+this_player()->query_objective()+
      ", then falls back lifeless.\n" +
      "The body then dissolves away into nothing, leaving behind only a few\n"+
      "coins and a small ring.\n");
  call_other(this_player(), "add_exp", experience / 35);
  coins=clone_object("obj/money");
  coins->set_money(10000);
  move_object(coins, environment(this_object()));
  vampiress_ring=clone_object("/players/nooneelse/obj/vampiress_ring");
  vampiress_ring->set_owner_of_ring(this_player()->query_real_name());
  move_object(vampiress_ring, environment(this_object()));
  destruct(this_object());
  return 1;
}

kill(str) {
  if (str=="corpse" || str=="vampiresscorpse") {
    write("You don't really want to hit a corpse do you?\n");
    return 1;
  }
}

init_command(cmd) { command(cmd); }

query_undead() { return 1; }
