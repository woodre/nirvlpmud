#include "/players/llew/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(arg) return;
   short_desc=BOLD+"Sacred Circle"+NORM;
   long_desc="\tSurrounded in sylvan beauty, this clearing is a\n"+
      "haven of peace and tranquility.  The grass is soft, the air\n"+
      "is cool and comfortable.  Protecting the clearing is a circle\n"+
      "of great oaks, beckoning prosperity.  The leaves whisper\n"+
      "gently letting in the overhead moonlight.   There are no exits,\n"+
      "but you know you can somehow make it back to the church.\n";
   dest_dir=({"room/church","church"});
   set_light(1);
}

init()
{
   ::init();
   if (this_player()->query_real_name() == "llew")
      add_action("test","test");
}

realm() { return "NT"; }
query_no_fight() { return 1; }

test()
{
   this_player()->move_player("in a wisp of smoke#players/llew/Other/rooms/testing_room");
   return 1;
}
