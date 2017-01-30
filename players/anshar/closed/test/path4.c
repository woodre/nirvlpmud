
#include "/players/anshar/closed/ansi.h"
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
            "so well used, it almost appears to be a permanent residence.\n"+
            "There is a glowing portal here as well.\n";
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
init() {
   ::init();
     add_action ("enter_portal", "enter");
   }
enter_portal(str) {
     if(!str) return 0;
     if(str != "portal") { write("enter what?\n"); return 1;}
     if (this_player()->query_level() < 15) {
     write("Waves of fear assail you and drive you back.\n");
     return 1;}
     write("You enter the portal and  light assails you. When your vision clears "+
         "you are someplace else.\n");
   this_player()->move_player("portal#"+HROOM+"hall1");
     return 1;
}
