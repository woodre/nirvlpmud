#include "/players/jareel/define.h"
#define TP this_player()
#define NAME "jareel"
#include <ansi.h>
inherit "room/room";
int shield;

     reset(arg) {
       if(!present("display"))  {
         MOCO("/players/cosmo/hslist/svds_new.c"),this_object()); }
       if(arg) return;

     set_light(1);
     short_desc = ""+HIK+"Mondar's Forge"+NORM+"";
     long_desc =

""+BLU+"============================="+HIK+"The Tracker"+NORM+BLU+"==============================\n"+
"|     "+HIK+"Commands           Cost             Function                   "+NORM+BLU+"| \n"+
"|====================================================================| \n"+
"|                                                                    "+NORM+BLU+"| \n"+
"|      "+HIK+"twho              Free         Tracker Who                    "+NORM+BLU+"| \n"+
"|      "+HIK+"tl                Free         Tracker line                   "+NORM+BLU+"| \n"+
"|      "+HIK+"tle               Free         Tracker Emote                  "+NORM+BLU+"| \n"+
"|      "+HIK+"tth               Free         Tracker History                "+NORM+BLU+"| \n"+
"|      "+HIK+"thush             Free         Stop listening                 "+NORM+BLU+"| \n"+ 
"|      "+HIK+"ttitle            Free         Set your Tracker title         "+NORM+BLU+"| \n"+
"|      "+HIK+"tpretitle         Free         Set your Tracker pretitle      "+NORM+BLU+"| \n"+
"|      "+HIK+"tbest             Free         See the Tracker's top 10       "+NORM+BLU+"| \n"+
"|      "+HIK+"tlegends          Free         See Nirvana's Legends          "+NORM+BLU+"| \n"+
"|      "+HIK+"tlist             Free         See your player kills          "+NORM+BLU+"| \n"+
"|      "+HIK+"tdeaths           Free         See who has killed you         "+NORM+BLU+"| \n"+
"|      "+HIK+"tw <player>       100          See where a player is          "+NORM+BLU+"| \n"+
"|                                                                    "+NORM+BLU+"| \n"+
"======================================================================"+NORM+" \n";
;

     dest_dir = ({
       "players/jareel/areas/chaos/cave/grid1/hall1.c","south",
       "/players/jareel/areas/chaos/forest1.c","west",
       "/players/jareel/test/bon.c","east",
       "room/adv_inner.c","north",
});
   
}
