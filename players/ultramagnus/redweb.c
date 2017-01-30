#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("east","east");
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
int i;
object spider;
       if(!present("spider")){
         while(i<3){
              i += 1;
               spider = clone_object("obj/monster");
               call_other(spider, "set_name", "spider");
               call_other(spider, "set_alias", "red spider");
               call_other(spider, "set_level", 4);
               call_other(spider, "set_short", "A Large Spider");
             call_other(spider, "set_long", "A Large Spider with Red Eyes and Red Fangs!\n");
               call_other(spider, "set_wc", 5);
               call_other(spider, "set_ac", 3);
               call_other(spider, "set_hp", 60);
               call_other(spider, "set_al", -100);
               call_other(spider, "set_aggressive", 1);
               move_object(spider, this_object());
            }
         }
}
ONE_EXIT("players/ultramagnus/redtree.c", "down",
        "Red Web",
        "This IS a Spiders Web!  All around you see Red Webbing with\n" +
        "threads that are a 1/2 inch in diamter!  It must be a rather\n" +
        "HUGE Spider around that could spin such a web.  All around are\n" +
        "corpses...big and small...some human..some elven or dwarfisf...hanging\n" +
       "from tree limbs or in webbing!  This is NOT a very cheerful place.\n" +
       "There is a stream of webbing leading toward the East.\n", 1)
east()
{
       call_other(this_player(), "move_player", "east#players/ultramagnus/spiderden.c");
      return 1;
}
