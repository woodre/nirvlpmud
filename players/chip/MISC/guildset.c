inherit "/obj/treasure.c";
#include "/players/fred/ansi.h";

reset (arg) {
 set_id("thingy");
 set_short("Guild Changer Thingy");
 set_long("This is a little tool that you can use to change\n"+
          "your guild name.  To use it just 'title_me'.\n");
}

init() {
 ::init();
 add_action("titler","title_me");
 }


titler() {
  this_player()->set_guild_name("");
  return 1;
}

drop() { return 1;}
