#pragma strong_type

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("You are at a landing in the stairway");
  set_long(
"You are on a landing in the stairway, the stairway continues up\n"+
"and down, you can go north into the hall. on the east wall you\n"+
"can se a large painting of Kantele and her sister on a dragon-\n"+
"hunt they had on one of the outher planes.\n");
  dest_dir = ({
    "players/kantele/stairway", "down",
    "players/kantele/stairway_top", "up",
    "players/kantele/upper_hall", "north"
  });
  items = ({
    "painting", "The large painting covers the wall from ceiling to the \n"+
                "floor. It is fastened to the wall with some large nails \n"+
                "and it looks almost impossible to get loose."
  });
}
