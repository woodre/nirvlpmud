#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Kantele's trophy room");
  set_long(
"This is the room Kantele places some of her trophies, on a\n" +
"table in the center of the room, you can see a human head !\n" +
"On the north wall you can see the head of the 'Great Wyrm' th \n" +
"famous Gold Dragon Kantele slayed on her 18'th years birtday. \n" +
"To the north you can see the bar and to the south there is some \n" +
"sort of workroom.\n");
  dest_dir = ({
    "players/kantele/bar", "north",
    "players/kantele/office", "south"
  });
  items = ({
    "head", "This is the head of 'Alf the black knight'\n"+
            "It is in premium conditino, and exactly as Kanteley slayed\n"+
            "him. head is an Item Kantele likes, so it is not possible to\n"+
            "steal, even if you would like to...."
  });
}
