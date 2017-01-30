#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();

  if (arg)
    return;

  set_short("silent workroom");
  set_long("Kitiaras silent workroom.\n");
  dest_dir = ({
    "/room/pub2", "pub",
    "/players/kantele/store", "south"
  });
}

void
populate() {
  if (!present("money")) {
    object money;
    money = clone_object("obj/money");
    money->set_money(100000);
    move_object(money, this_object());
  }
  if (!present("torch")) {
    object torch;
    torch = clone_object("obj/torch");
    torch->set_name("torch");
    torch->set_fuel(9999);
    torch->set_weight(1);
    move_object(torch, this_object());
  }
}
