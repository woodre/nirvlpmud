#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("In a strange room");
  set_long(
"You are in a strange room, the room is small and totaly without\n"+
"furniture of any kind. It looks like some kind of meditation\n"+
"room, a large blackboard stands against the north wall.\n");
  dest_dir = ({
    "players/kantele/kitiaras_livingroom", "east"
  });
  items = ({
    "blackboard", "There is a message on the blackboard the message reads:\n"+
                  "Dear Kit !\n\n"+
                  "Can you visit me tomorow ?\n"+
                  "Please bring my gift !\n"+
                  "unless you want to visit my pets!\n"+
                  "\n /K"
  });
}
