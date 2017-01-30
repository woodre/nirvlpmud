#pragma strong_types

inherit "room/room";

void populate();

int payed, bridge_is_down, rope;

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("Besides a rickety wooden bridge");
  set_long(
"A rickety wooden bridge extends across the chasm to the west\n"+
"vanishing into the darkness.  A sign posted on the bridge reads:\n"+
"'stop! pay troll!'\n");
  dest_dir = ({
    "players/kantele/dirty_temple", "east",
    "players/kantele/west_bridge", "west"
  });
}

void
populate() {
  object troll;
  payed = 1;
  bridge_is_down = 0;
  rope = 0;
  if (!present("troll", this_object())) {
    troll  = clone_object("obj/monster");
    troll->set_name("troll");
    troll->set_level(17);
    troll->set_al(-300);
    troll->set_short("A large Troll is here");
    troll->set_wc(24);
    troll->set_ac(14);
    troll->set_hp(350);
    troll->add_money(1000 + random(1100));
    move_object(troll, this_object());
  }
}

void
init() {
  ::init();
  "players/kantele/bottom_chasm"->reset(0);
  add_action("pay_troll", "pay");
  add_action("west", "west");
  add_action("tie", "tie");
  add_action("untie", "untie");
  add_action("jump_down", "jump");
}

status
pay_troll(string str) {
  if (str && str == "troll" && present("troll", this_object())) {
    write("The troll don't want your stinking money !\n");
    return 1;
  }
}

status
west() {
  if (this_player()->query_level() < 20) {
    if (bridge_is_down == 1) {
      write("The bridge is down.\n");
      return 1;
    } else {
      if (present("troll", this_object()) && payed ==1) {
        write("The Troll bars your way !\n");
        return 1;
      }
    }
  }
  return 0;
}

status
tie(string str) {
  if (str == "rope to bridge") {
  if (present("rope", this_player())) {
    rope = 1;
    write("You tie a rope to the bridge.\n");
    say(this_player()->query_name()+" ties a rope to the bridge.\n");
    move_object(present("rope", this_player()), this_object());
    destruct(present("rope", this_object()));
    set_long(
"A rickety wooden bridge extends across the chasm to the west\n"+
"vanishing into the darkness.  There is a rope tied to the bridge.\n"+
"A sign posted on the bridge reads: 'stop! pay troll!'\n");
    add_exit("players/kantele/bottom_chasm", "down");
    "players/kantele/bottom_chasm"->add_exit("players/kantele/on_bridge","up");
    "players/kantele/bottom_chasm"->set_long(
"You are in the bottom of the chasm, it seems impossible to get out!!\n"+
"There is a rope hanging down from the bridge.\n");
  ::init();
  return 1;
  }
  write("You do not have a rope!\n");
  return 1;
}
  return 0;
}

status
untie(string str) {
  if (str != "rope from bridge" && str != "rope")
    return 0;
  if (!rope) {
    write("There is no rope tied to the bridge.\n");
    return 1;
  }
  rope = 0;
  write("You untie the rope from the bridge.\n");
  say(this_player()->query_name()+" unties the rope from the bridge.\n");
  move_object(clone_object("obj/rope"), this_object());
  set_long(
"A rickety wooden bridge extends across the chasm to the west\n"+
"vanishing into the darkness.  A sign posted on the bridge read: \n"+
"'stop! pay troll!'\n");
  remove_exit("down");
  "players/kantele/bottom_chasm"->remove_exit("up");
  "players/kantele/bottom_chasm"->set_long(
"You are in the bottom of the chasm, it seems impossible to get out!!\n");
  ::init();
  return 1;
}

status query_rope() { return rope; }

status
jump_down(string str) {  /* This makes no sense, but meh - Rump */
  if (str != "down")  {
    write("You throw yourself into the chasm !\n");
    write("You hit the dirt hard......\n");
    this_player()->hit_player(20);
    this_player()->move_player("jump_down#players/kantele/bottom_chasm");
  }
  return 0;
}
