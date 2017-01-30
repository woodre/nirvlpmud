#pragma strong_types

inherit "room/room";

int eyes;

status summon_avatar(object ob);

void
reset(status arg) {
  ::reset(arg);
  eyes = 2;
  remove_item("statue");
  add_item("statue", "The statue has two burning eyes, perhaps you could "+
                     "pry them?");
  if (arg)
    return;
  set_light(1);
  set_short("You are Behind the alter");
  set_long(
"You are behind the altar, a passage leads west and you can go into\n"+
"the temple proper to the north. The Statue of Kali looks at you with two\n"+
"burning diamond eyes.\n");
  dest_dir = ({
    "players/kantele/dirty_temple", "north",
    "players/kantele/robing_room", "west"
  });
  items = ({
    "statue", "The statue has two burning eyes, perhaps you could pry them?"
  });
}

void
init() {
  ::init();
  add_action("get_diamond", "pry");
}

status
get_diamond(string str) {
  object diamond;
  if (str == "eye" || str == "eyes" || str == "diamond" || str == "diamonds"
                     || str == "of eye" || str == "of eyes") {
    if (eyes > 0) {
      eyes = eyes-1;
      write("You pry off a diamond eye.\n");
      write(this_player()->query_name()+" prys off a diamond eye.\n");
      diamond = clone_object("obj/treasure");
      diamond->set_id("diamond");
      diamond->set_short("A huge glittering diamond");
      diamond->set_weight(1);
      diamond->set_value(random(2000));
      diamond->set_alias("gem");
      move_object(diamond, this_object());
      if (eyes == 1) {
        remove_item("statue");
        add_item("statue", "The statue has one burning eye, perhaps you could"+
                           " pry it?");
        set_long(
"You are behind the altar, a passage leads west and you can go into\n"+
"the temple proper to the north. The Statue of Kali looks at you with one\n"+
"diamond eye.\n");
      } else if (eyes == 0) {
        remove_item("statue");
        add_item("statue", "The statue looks at you with two empty eye "+
                           "sockets");
        set_long(
"You are behind the altar, a passage leads west and you can go into\n"+
"the temple proper to the north. The Statue of Kali looks at you with two\n"+
"empty eye sockets.\n");
      }
      if (eyes == random(3))
        summon_avatar(this_player());
      return 1;
    }
    write("There is nothing to pry off.\n");
    return 1;
  }
}

status
summon_avatar(object ob) {
  object shagath;
  if (!present("shagath", this_object())) {
    tell_room(this_object(),
      "The Whole Temple shakes as you feel the Wreath of Kali !\n");
    tell_room(this_object(),
      "Shagath the avatar of Kali arrives in a puff of smoke !\n");
    shagath  = clone_object("obj/monster");
    shagath->set_name("shagath");
    shagath->set_alias("avatar");
    shagath->set_level(20);
    shagath->set_al(-300);
    shagath->set_short("Shagath the avatar of Kali is here");
    shagath->set_wc(30);
    shagath->set_ac(17);
    shagath->set_hp(500);
    shagath->add_money(random(1000));
    shagath->set_aggressive(1);
    shagath->set_chance(40);
    shagath->set_spell_mess1("Shagath throws Hellfire.");
    shagath->set_spell_mess2("You are hit by the Hellfire");
    shagath->set_spell_dam(60);
    move_object(shagath, this_object());
    shagath->attack_by(ob);
    return 1;
  }
}
