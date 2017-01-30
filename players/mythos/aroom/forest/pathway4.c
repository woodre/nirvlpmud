/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-1);
    short_desc = "Forest pathway4";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The trees are creepy\n"+
    "and seem to move in the dim light. The path ends in a mass of trees...\n"+
    "no way except back - or so it seems. You look around and you notice \n"+
    "that the 'trees' look funny.\n";
  items = ({
    "southeast","The path returns to the forest",
    "trees","There is something beyond these horrid trees. Maybe you can 'pass' beyond them",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/pathway3.c", "southeast",
  });
  set_realm_name("Ancient");
  set_lot_size(6);
  set_cost(750000);
  setup_land();
} }


init() {
  ::init();
  add_action("pass","pass");
}

pass() {
  call_other(this_player(),"move_player","pass#players/mythos/aroom/forest/bridge.c");
  say(this_player()->query_name()+" vanishes into the forest.\n");
return 1;
}
