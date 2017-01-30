#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(arg) return;
  set_light(1);

  short_desc = "Soft Forest";
  long_desc ="\n"+
    "  The damp trail widens and becomes indistinct.  Movement is easy\n\
as the forest becomes thin and open.  The trail leads north to an\n\
intersection.  To the south bright grey light is visible.\n";


  items = ({
    "trees",
    "The forest has many pine and oak trees",
    "intersection",
    "To the north two roads cross one another",
    "trail", "A leafy forest trail, it continues upward to north and south",
    "forest","The forest has many pine and oak trees.  It seems\n"+
    "very old",
    "light","In contrast to the dim forest, the bright grey light is blinding\n",
  });


  dest_dir = ({
    "/players/softly/winter/rooms/for2.c","north",
    "/players/softly/algiers/rooms/road2.c","south",
  });
}

init()
{ 
  ::init(); 
  if(!this_player()) return; 
/*
  write_file("/players/softly/logs/algiers_enter", this_player()->query_real_name()+" entered Algiers on "+ctime(time())+".\n"); 
*/
}
