#include "../defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=CYN+"The Misty Tower"+OFF;
  long_desc=
"  The marble steps end here at the top of the tower.  You can easily\n\
tell how far the servants of the tower dare to dread by a line of\n\
dust; on one side of it a coat of dust, on the other polished marble.\n\
A steel door, embossed with runes and a hideous draconian face is on\n\
the landing.  Past it, a flight of wooden stairs leads through a hatch\n\
and onto the roof.\n";
  items=({
    "steps","You start counting them: 1, 2, 3, 4, 5, 6, 7, 8, ..",
    "marble","The usual green and blue marble that seems so popular here",
    "door","The steal door is decorated with incredibly strong runes of\n"+
           "protection and animation.  At eye height in the door is a\n"+
           "draconian face made out of silver and with ruby eyes",
    "runes","As near as you can tell, they are runes of protection and\n"+
            "animation.  Apparently the master does not wish to be disturbed",
    "face","A silver face, like that of a dragon and of incredible craftsmanship.\n"+
           "It's ruby eyes seem to follow you",
  });
  dest_dir=({
    ROOMDIR+"tower_top.c","up",
    ROOMDIR+"tower5.c","down",
    ROOMDIR+"masters_study.c","north"
  });
}

void init() {
  ::init();
  add_action("cmd_north","north");
}

int cmd_north(string str) {
  write(GRN+"The draconian face upon the door suddenly comes to life and says:\n"+NORM+
       "\"The Master does not wish to see you at this time!\"\n"+
       RED+"It emphasizes this by blowing a gout of flame at your face.\n"+NORM);
  this_player()->hit_player(random(20));
  return 1;
}
