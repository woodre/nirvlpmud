#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  if (arg) return;
  short_desc="Old Street";
  long_desc="As you walk futher into the town you do seem to see some people\n"
    + "on the side of the streets.  These are the people who have lost\n"
    + "homes or never had one, in other words...the bums and beggars.\n"
    + "There is a rather interesting building to the north.\n";
  dest_dir=({ROOT(street1),"west",
             ROOT(street3),"east",
             ROOT(street4),"north"});
  set_light(0);
}
