#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("Kitchen");
  set_long(
"A hot very hot kitchn, it looks very clean, you can see a store \n" +
"room to the south, to the north you can see the dining room.\n");
  dest_dir = ({
    "players/kantele/dining_room", "north",
    "players/kantele/store_room", "south"
  });
}

void
populate() {
  object matilda;
  if (!present("matilda", this_object())) {
    object poker;
    matilda = clone_object("obj/monster");
    matilda->set_name("matilda");
    matilda->set_level(9);
    matilda->set_wc(13);
    matilda->set_ac(7);
    matilda->set_hp(135);
    matilda->set_al(100);
    matilda->set_aggressive(1);
    matilda->add_money(400);
    matilda->set_short("Matilda the fat old cook is here");
    poker = clone_object("obj/weapon");
    poker->set_name("poker");
    poker->set_value(10);
    poker->set_class(14);
    move_object(poker, matilda);
    command("wield poker", matilda);
    move_object(matilda, this_object());
  }
}
