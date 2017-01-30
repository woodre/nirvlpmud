#include <ansi.h>
inherit "/obj/treasure.c";

reset (arg) {
 set_id("thingy");
 set_short("Title Changer Thingy");
 set_long("This is a little tool that you can use to change\n"+
          "your guild name.  To use it just 'title_me'.\n");
}

init() {
 ::init();
 add_action("titler","title_me");
 }


titler() {
   this_player()->set_guild_name("Creatures");
  return 1;
}

drop() { return 1;}
