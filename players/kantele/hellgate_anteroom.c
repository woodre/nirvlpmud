#pragma strong_types

inherit "room/room";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("You are in a anteroom");
  set_long(
"You are in a anteroom, you can feel the power of\n"+
"magic, and you are sure there is a great power nearby.\n");
  dest_dir = ({
    "players/kantele/west_bridge", "south",
    "players/kantele/hellgate", "north"
  });
}
