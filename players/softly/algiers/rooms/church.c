#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";
int i;
reset(arg){
  if(arg) return;
  set_light(1);

  short_desc = "Fellowship Church of the River";
  long_desc ="\n"+
    "  A small solidly built concrete block building newly painted a\n"+
    "clean white has a tall square steeple rising from the center of\n"+
    "the roof.  The dark asphalt shingle roof covers the top of the\n"+
    "steeple, the building, and a small space over the plain front door.\n"+
    "In front of the building a small white sign proudly stands.  Bright\n"+
    "green indoor/outdoor carpeting creates an inviting space before\n"+
    "the open double doors.\n";

  items = ({
    "doors",
    "Wooden double doors stand open, inviting entry",
    "sign",
    "Fellowship Church of the River\n"+
    " The Reverend Albert Johnson",
    "building", 
    "The cinderblock building is modest but well kept",
    "roof",
    "The dark roof stands in sharp contrast to the white building",
    "space",
    "A roof overhang protects those who are entering the\n"+
    "front door",
    "doors",
    "A wooden doouble doors are polished and worn from many hands opening it",
    "steeple",
    "The square white steeple is topped by a grey asphalt roof",
    "carpeting",
    "Bright green indoor/outdoor carpeting covers the entryway",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road8.c","north",
    "/players/softly/algiers/rooms/churchmain.c","enter",
  });
}




  
  
  
