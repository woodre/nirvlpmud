#include "ansi.h"
inherit "room/room";

   void reset(status arg) {
   if (arg) return;
   set_light(1);
   short_desc = HIG+"Gumdrop Mountains"+NORM;
   items = ({
       "range","A pastel colored, sugar crested range",
       "crest","The highest point of the sugar coated mountain",
       "sugar","Thick layers of sugar coat the mountains",
       "view","A wonderous view of Candy Land",
       "mountain","A pastel colored, sugar crested peak",
       "mountains","A pastel colored, sugar crested peak"});
       
   long_desc =
"  High above Candy Land are the Gumdrop Mountains.  The range is pastel\n\
colored and sugar crested and affords the most wonderous view of Candy\n\
Land that anyone has ever seen!  Rumor has it there is a giant gumdrop\n\
walking around welcoming those who pass through his mountains.\n";
   dest_dir = ({"players/martha/area/rooms/gpass","north",
                "players/martha/area/rooms/gmtn2","northwest",
                "players/martha/area/rooms/pforest","west"}); 
}
   