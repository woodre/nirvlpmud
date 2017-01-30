/* pcrenew - Get a new Player Channel object */

#include <ansi.h>

int pcrenew(){
   destruct(present("player_channel", this_player()));
   move_object(clone_object("/players/rumplemintz/PC/pc.c"), this_player());
   write(HIW+"Your Player Channel membership has been renewed!"+NORM+"\n");
   return 1;
}
