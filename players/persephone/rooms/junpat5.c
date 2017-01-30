inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(arg) return;
  set_light(0);
  short_desc="Disused Path";
  long_desc="After struggling through thick undergrowth you feel that continuing\n" +
            "on to the east would be a big mistake especially since to the east\n" +
            "you see a dark and forboding den. All around you there are bone\n" +
            "fragments of all sizes. Perhaps the safest way would be west\n" +
            "\n";
  items=({"undergrowth","Small plants that cannot grow to their full height\n" +
                       "and many different forms of ivy and some strange looking\n" +
                       "mushrooms",
         "bones","They appear to be bones of a bipedal creature and some look very\n" +
                 "fresh",
         "fragments","It is very difficult to tell what these bone fragments came\n" +
                     "from but you think it might be hominid",
         "mushrooms","These look like very strange mushrooms they are green with" +
                     "purple spots",
         "den","It looks like the den is inhabited but you cannot be sure",
         "path","I definately would not call this a path it looks more like a track",
         "trees","Trees are trees but these are very black and seem almost alive",
        });
  dest_dir=({"players/persephone/rooms/junpat6","west",
             "players/persephone/rooms/wwden","east",
           });
}
