#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "Somewhere in Darkwood";
  long_desc = 
"You are walking somewhere in Darkwood.  You jump at the sound\n" +
"of a twig snapping.\n";
  dest_dir = ({
    "players/angmar/fairyland/dw_path2", "west",
  });
  items = ({
    "twig", "A small piece of wood. If you were trying to be silent, " +
            "you blew it",
  });
}

string realm() { return ("fairyland"); }
