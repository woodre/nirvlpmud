#pragma strong_types

inherit "room/room";

int found;

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("A tidy sleepingroom");
  set_long(
"A tidy sleeping room, it has a feminine look and a large pink bed.\n");
  dest_dir = ({
    "players/kantele/kitiaras_innerhall", "east"
  });
  items = ({
    "bed", "The bed is covered with clean silken sheets, it smells of roses"
  });
}

void
populate() {
  found = found-1;
}

void
init() {
  ::init();
  add_action("search", "search");
}

status
search(string arg) {
  if (arg == "bed") {
    if (found < 1) {
      found =3;
      move_object(clone_object("players/kantele/ring"), this_object());
      write("You found a small ring.\n");
      return 1;
    } else {
      write("You found nothing.\n");
      return 1;
    }
  }
  return 0;
}
