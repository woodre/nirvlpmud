#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object creature, gutripper;
  object master, creat, workrm;

  workrm=find_object("players/angmar/workroom");
  if (workrm)
    master = present("master-palantir", workrm);
  if (!master || !workrm) {
    master = clone_object("players/angmar/o/master");
    move_object(master,"players/angmar/workroom");
  }
  if (!present("creator",this_object())) {
    creat=clone_object("players/angmar/o/creator");
    creat->set_master(master);
    move_object(creat,this_object());
  }
 if (!present("creature", this_object())) {
    creature = clone_object("obj/monster");
    creature->set_name("creature");
    creature->set_level(15);
    creature->set_hp(200);
    creature->set_wc(10);
    creature->set_ac(5);
    creature->set_al(-150);
    creature->set_short("A loathesome creature");
    creature->set_long("A disgusting malformed thing, who perhaps was a " +
      "human once.\nAngmar was probably in a bad mood when he created this\n" +
      "indescribable being.  Take care!\n");
    creature->set_spell_mess1("The creature casts a spell");
    creature->set_spell_mess2("The creature casts a spell at you");
    creature->set_chance(30);
    creature->set_spell_dam(20);
    move_object(creature, this_object());
    gutripper = clone_object("obj/weapon");
    gutripper->set_name("gutripper");
    gutripper->set_alias("ripper");
    gutripper->set_short("Gutripper");
    gutripper->set_long("You can only guess what devishly deeds this nasty" +
      "tool was used for.\nIt should serve very well as a weapon though.\n");
    gutripper->set_class(15);
    gutripper->set_weight(2);
    gutripper->set_value(1000);
    move_object(gutripper,creature);
    creature->init_command("wield gutripper");
  }
  
  if (arg)
    return;
  set_light(1);

  set_light(1);
  short_desc = "Angmar's castle";
  long_desc =
"You are inside the gates of Angmar the Necromancer's castle.  The castle\n" +
"was abandoned a long time ago when Angmar was driven from this world by\n" +
"the Istari, and is now quite ruined.  Angmar's workroom is to the east.\n" +
"You can see a forge to the west.\n";
  dest_dir = ({
    "room/southroad3", "north",
    "players/angmar/castle/stairs", "south",
    "players/angmar/castle/forge", "west",
  });
  items = ({
    "gates", "The gates are covered with rust, since they have not been used in ages",
    "rust", "The rust on the gates is thinck.  The metal has oxidized over the years",
    "castle", "The castle looms over you.  You shiver as you think of the death inside",
    "workroom", "The portal is shadowy.  You see a few blurs inside",
    "portal", "The portal consists of a dark oval.  You cannot see within",
    "oval", "The oval is a two-dimensional object.  You are always facing it",
    "blurs", "You cannot distinguish anything about the blurs",
    "forge", "In the forge, you see a smith, sitting quietly",
    "smith", "You can't make out any details about him",
    "sign", "The sign points south, and says, 'This way to Fairyland'",
    "south", "The way south is in darkness.  You cannot see",
  });
}

void
init() {
  room::init();
  add_action("east","east");
}

status east() {
  if ((string)this_player()->query_real_name() != "angmar" &&
      (string)this_player()->query_real_name() != "rumplemintz") {
    write("You start to shiver. You dare not enter.\n");
    say(this_player()->query_name() + " tried to enter the workroom.\n");
    return 1;
  }
  write("You enter Angmar's monsterlab\n");
  this_player()->move_player("east#players/angmar/workroom");
  return 1;
}
