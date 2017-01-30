#include "ansi.h"
inherit "room/room";

reset (arg) {
      if(!present("jolly",this_object())) {
        move_object (clone_object("/players/martha/area/mobs/jolly"), this_object());
    }
    
    if (arg) return;
    set_light(1);
    short_desc = HIG+"Gumdrop Mountains"+NORM;
    items = ({
        "range","A pastel colored, sugar crested range",
        "view","A wonderous view of Candy Land",
        "crest","Snow glistens and shines",
        "footprint","A large gumdrop shaped footprint",
        "large footprints","Large gumdrop shaped footprints",
        "large footprint","A large gumdrop shaped footprint",
        "footprints","Large gumdrop shaped footprints",
        "mountains", "A pastel colored, sugar crested peak",
        "mountain","A pastel colored, sugar crested peak"});
    
    long_desc =
"   High above Candy Land are the Gumdrop Mountains.  The range is pastel\n\
colored and sugar crested and affords the most wonderous view of Candy\n\
Land that anyone has ever seen!  Circling the crest of the mountain are\n\
large footprints that are gumdrop shaped.\n";
    dest_dir = ({"players/martha/area/rooms/road", "northwest",
                 "players/martha/area/rooms/gmtn", "southeast"});
} 
        