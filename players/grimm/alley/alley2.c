#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc="Dark Alley";
  long_desc="This is a dark and dreary alley.\n";
  dest_dir=({ROOT(alley3),"north",
             ROOT(alley1),"west",
             ROOT(street1),"east"});
  set_light(1);
}
