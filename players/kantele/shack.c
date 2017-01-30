#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("The gardneres shack");
  set_long(
"This is the gardeners shack, it is small dark and dirty.\n");
  dest_dir = ({
    "players/kantele/courtyard", "west"
  });
}

void
populate() {
  if (!present("gardener")) {
    object gardener, bag, money;
    gardener = clone_object("obj/monster");
    gardener->set_name("gardener");
    gardener->set_level(6);
    gardener->set_wc(10);
    gardener->set_ac(5);
    gardener->set_hp(90);
    gardener->set_al(100);
    gardener->set_short("The old bent gardener is here");
    move_object(gardener, this_object());
    bag = clone_object("obj/bag");
    move_object(bag, gardener);
    money = clone_object("obj/money");
    money->set_money(random(250));
    move_object(money, bag);
  }
}
