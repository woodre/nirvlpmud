#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
reset(arg) {
  if(!present("guard"))
    move_object(clone_object("/players/xiu/tour/mobs/guard"), this_object());
  if(arg) return;
set_light(1);
short_desc = "Nirvana Music Festival";
long_desc =
" A little farther to the north lies the stage.\n"+
" Steel iron gates block entry all along the stage.\n"+
" The only way in is past the security guard at a small opening.\n";
" Dust fills the air, creating sheens of light that scatter all about.\n"+
" Music thumps in the background and the contageous beat gives people a hop\n"+
" to their step.\n";

items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
  });

dest_dir = ({
 "/players/xiu/tour/rms/7.c","north",
"/players/xiu/tour/rms/5.c","south",
  });
}

init()
{
  ::init();
add_action("cmd_north", "north", 1);
}

cmd_north()
{
if(present("guard", environment(this_player())))
  {
 write("A security guard laughs and blocks your exit.\n");
 say("A security guard laughs and blocks "+tpn+"'s exit.\n");
    return 1;
  }
}
