#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object elfking, we;

  if (!present("elfking")){
    elfking = clone_object("obj/monster");
    elfking->set_name("elfking");
    elfking->set_level(17);
    elfking->set_hp(300 + random(100));
    elfking->set_wc(24);
    elfking->set_ac(14);
    elfking->set_short("The elfking");
    elfking->set_alias("king");
    elfking->set_al(200);
    elfking->set_gender("male");
    elfking->set_long(
"This is the King of the Elves.  Though small in stature, he\n" +
"exudes a charisma and sense of capability that places you in awe.\n" +
"He is mature, by elf standards, yet you get the feeling that he is\n" +
"hundreds of years older than you are.  He has a determined look on his face.\n");
    we = clone_object("obj/weapon");
    we->set_name("elfsword");
    we->set_short("An elfsword");
    we->set_long("It looks very sharp.\n");
    we->set_alias("sword");
    we->set_class(17);
    we->set_value(1500);
    we->set_weight(4);
    move_object(we, elfking);
    we = clone_object("obj/money");
    we->set_money(random(600));
    move_object(we, elfking);
    move_object(elfking, this_object());
    command("wield sword", elfking);
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "The beech woods";
  long_desc = 
"You are in the beech woods. The birds are singing.\n";
  dest_dir = ({
    "players/angmar/fairyland/beech1", "north",
  });
  items = ({
    "woods", "The woods consist of a huge number of beech trees",
    "trees", "Beech trees, which have been here for years",
    "beech trees", "Beech trees, which have been here for years",
    "birds", "They flit away before you can glimpse them",
  });
}

string realm() { return ("fairyland"); }

void
init() {
  room::init();
  add_action("climb", "climb");
  add_action("listen", "listen");
}

status
climb(string str) {
  if (!str)
    return 0;
  if (str == "trees" || str == "tree") {
    write("The branches are too high for you to reach.\n");
    say(this_player()->query_name() + 
      " reaches for a few branches, but misses.\n");
    return 1;
  }
  return 0;
}

status
listen() {
  write("You hear the sounds of content birds.\n");
  say(this_player()->query_name() + " listens to the birds.\n");
  return 1;
}
