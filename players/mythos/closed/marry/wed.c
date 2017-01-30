#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
if(!arg) {
  set_light(1);
    short_desc = HIR+"The Elemental Plane of Fire  "+NORM;
    long_desc =
    "The instense heat in this area is almost overwhelming.\n"+
    "You stand on a large plateau of stone, which is jutting out \n"+
    "of a sea of magma...  All around you the sky itself seems to \n"+
    "be on fire, making the air thin and difficult to breathe. \n"+
    "Welcome to the elemental plane of "+HIR+"Fire"+NORM+".\n";
  items = ({
    "church","Leads back to the church",

  });

  dest_dir = ({
    "/room/church.c","church",
  });
} }

