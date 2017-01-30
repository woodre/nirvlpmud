inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if (!present("npc"))
    MOND->populate_monsters(this_object());

  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    GRN+"###########     "+NORM+"   \n"+
    GRN+"#"+NORM+"X-|--|---"+GRN+"#   "+NORM+DESCD->get_long_desc(1)+
    GRN+"###"+NORM+HIM+"S"+NORM+GRN+"##"+NORM+"|"+NORM+GRN+"####   "+NORM+DESCD->get_long_desc(2)+
    GRN+"######"+NORM+"|"+NORM+GRN+"####   "+NORM+DESCD->get_long_desc(3)+
    GRN+"######"+NORM+"|"+NORM+GRN+"####   "+NORM+DESCD->get_long_desc(4)+
    GRN+"######"+NORM+"|"+NORM+GRN+"####"+NORM+"   \n"+ 
    GRN+"######"+NORM+"|"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
 "/players/jareel/areas/chaos/woods3/wood8","east",
  });
}
