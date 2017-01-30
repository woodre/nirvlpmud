#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A campsite";
  long_desc="     The path appears to end here, or perhaps become so \n"+
            "overgrown that it simply ceases. The sun beats down yet\n"+
            "is slightly filtered by some trees overhanging the small\n"+
            "clearing. There is what seems to be a regular campsite here\n"+
            "so well used, it almost appears to be a permanent residence.\n";
  items=({
    "path", "The dusty path ends here, though it looks as if it once went on",
    "sun",  "Large and angry red, the sun beats down slightly less fiercely",
    "campsite", "Seems to be more a home than a temporary residence",
    "clearing", "A small area perfect for a campsite",
    "trees", "Somewhat scrawny, the trees offer some shade",
  });
  dest_dir=({
    FROOM+"path3", "north",
  });

if(!present("dmerchant"))
{
move_object(clone_object(FMON+"merchant"),TO);
}
}
