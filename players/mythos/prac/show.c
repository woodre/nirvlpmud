
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("poster");
  set_short("A Poster depicting a new area");
  set_long("You see a new area 1s and all the way\n"+
    "east of the church.  It is a low to high mid\n"+
    "level range and exists in the land of Ancient\n"+
    "Japan.  Pass the wall and enter a new land.\n"+
    "Look at everything- for much is hidden.\n");
set_weight(1000000);
  set_value(0);
}
