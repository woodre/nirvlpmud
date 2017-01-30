/*
 sitting.c
*/

inherit "room/room";

object rat, dog, coins;

string chat_str, a_chat_str;


reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "sitting room";
  no_castle_flag=1;
  long_desc =
    "The windows of this chamber are tightly shuttered, and the air\n"
    + "has a stale and musty quality.  Several chairs and small tables\n"
    + "occupy the center of the room, facing the tightly sealed windows.\n";
  items =
    ({
      "windows", "They are covered by stout wooden shutters.",
      "window", "They are covered by stout wooden shutters.",
      "shutters", "They are made of stong wood.",
      "shutter", "It is made of stong wood.",
      "tables", "There are several small tables around the room.",
      "chairs", "You see several large comfortable chairs.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/hall", "west",
    });
  if (!find_living("nooneelsevonhelsing"))
    move_object(clone_object("/players/nooneelse/mon/von_helsing"),
                this_object());
  if (!present("dog") && !present("rat")) {
    make_dogs();
    make_dogs();
    make_rats();
    make_rats();
    make_rats();
  }
}

make_rats() {
  rat=clone_object("obj/monster");
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
  coins=clone_object("obj/money");
  coins->set_money(6+random(10));
  move_object(coins, rat);
  move_object(rat, this_object());
}

make_dogs() {
  dog=clone_object("obj/monster");
  dog->set_name("dog");
  dog->set_alt_name("nooneelsedog");
  dog->set_level(4);
  dog->set_hp(25);
  dog->set_wc(10);
  dog->set_ac(4);
  dog->set_ep(700);
  dog->set_al(0);
  dog->set_short("a dog");
  dog->set_long("It's a mangy, ugly, nasty looking, dog.\n");
  dog->set_whimpy(1);
  dog->set_aggressive(1);
  coins=clone_object("obj/money");
  coins->set_money(6+random(20));
  move_object(coins, dog);
  move_object(dog, this_object());
}
