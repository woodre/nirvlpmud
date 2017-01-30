	/* Realm entrance. At present this will be the way to get into my areas */
	/* Later once more of the areas are finished I'll likely make it link   */
        /* to the Forest and have the entrances to the other areas from there   */

#include <ansi.h>


inherit "room/room";

reset(arg)  {
   if(arg) 
      return ;


   set_light(1);
   short_desc = "Place between worlds";
   long_desc = 
"Strange ribbons of energy ripple around you. This seems to be a \n"+
"crossing point of some kind. Energy and matter coalesce around the\n"+
"central axis. Some sort of ancient power seems to have been at \n"+
"work here. Points where the lights cross appear to be gates.\n"+
"Whatever powers built this had an advanced understanding of spatial\n"+
"mechanics and temporal probability. The gates appear to be stable \n"+
"and worth investigating. From here many places are accessible.\n";

      items=({
           "energy","Vast amounts of mystic potential flow here like water",
           "ribbon","Streams of energy flow across each other",
           "matter","Blobs of protomatter form and change near the axis",
           "axis","Everything seems to circle this singularity.",
           "gates","Portals form where energy ribbons cross."
            });

        
      dest_dir = ({
          "/players/wren/Area/starbug/rooms/airlock","starbug",
          "/players/wren/Area/redbank/rooms/front","jersey",
          "/room/farmroad1","nirvana"
/*
          "/players/wren/Area/evilcircus/ ","circus", 
          "/players/wren/Area/darkkeep/ ","keep",
          "/players/wren/Area/ninjaworld/ ","ninjas" 
*/
                  });
}

  init() {
    ::init();
    add_action("search_room","search");
          }

  search_room()  {
        write("You search but find nothing in this realm to take.\n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

