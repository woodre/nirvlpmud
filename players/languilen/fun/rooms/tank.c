#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
      if(arg) return;
   set_light(1);
   if( !present("tank") ) move_object(clone_object(OBJ+"thetank.c"),this_object());
   if( !present("attendant") ) move_object(clone_object(MON+"tattendant.c"),this_object());
   short_desc = "At the Dunk Tank";
   long_desc =
"   There are flashing lights, whistles and bells going off all over\n\
the place.  The black and white square tiles where the children run\n\
only serve to highten the sense of meyham.  There is a large tank here\n\
with a glass front that you may want to look at.  The tank has a target\n\
attached to it by a metal arm and is surrounded by a short fence to keep\n\
people from getting too close to the tank or target.  On the wall is a\n\
small sign.\n";

   items = ({
      "lights","Strobes of all different colors flash from above",
      "tiles","The tiles are a checkered pattern and look a bit used but not warn",
      "target","The target is suspended on a metal arm that sticks out from\n\
the side of the tank", 
      "arm","This supports the target seems to be some sort of lever",
      "glass","This is so you may easily see the contents of the tank",
      "fence","A short metal fence",
      "sign","An informative sign that you can read",
   });

   dest_dir = ({
	AREA+"hill.c","east",
   });
}
init(){
     ::init();
     add_action("read_sign","read");
     add_action("listening","listen");
}
read_sign(str){
     if(!str || str != "sign"){
        notify_fail("Are you trying to 'read' the 'sign'?\n");
        return 0;
     }
     write("\n"+
        HIB+"   /\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+NORM+"\n"+
        HIW+"   *                                        *"+NORM+"\n"+
        HIW+"   *        3 softballs for 30 coins!       *\n"+
        HIW+"   *    Please '"+HIB+"pay"+HIW+"' the tank '"+HIB+"attendant"+HIW+"'   *\n"+
        HIW+"   *                                        *"+NORM+"\n"+
        HIB+"   /\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+HIW+"__"+HIB+"/\\"+NORM+"\n"+
        "\n");
     return 1;
}

listening(){
     write("Shrill whistles and clamouring bells make hearing much else a chore.\n");
     return 1;
}

query_no_fight() { return 1; }
realm(){ return "NT"; }
