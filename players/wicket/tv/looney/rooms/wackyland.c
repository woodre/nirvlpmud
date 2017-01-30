inherit"/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);
if(!present("dodo", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/dodo.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = HIR+"Entr"+HIY+"ance"+NORM+" to "+HIY+"Wa"+HIR+"cky"+HIG+" Land "+NORM;
  long_desc = " Cartoon creatures of all kinds run around this place. Things of unknown\n\
  race that have never been seen before. Objects zip by all around the area\n\
  as if there is no gravity. Things run upside down on steps in the sky.\n\
  Signs point every which direction that seem to make no sense at all. The sky\n\
  is multiple colors. Sounds of horns, laughter, screaming and all kinds of\n\
  madness echo through the air.\n";
  items = 
  ({
    "signs",
    "Signs that point this way and that way that lead to no direct destination",
    "steps",
    "Upside down steps that seem to be floating in mid air",
    "objects",
    "Pencils with legs and all kinds of weird things floating around here",
    "creatures",
    "Walking bicycle horns with legs running around and all other things of that sort",
  });

    dest_dir=({
  "/players/wicket/tv/looney/rooms/tinyentrance.c","out",
  });
}
