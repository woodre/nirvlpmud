#include "/players/tallos/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
  if(arg) return;
set_short(HIY+"7 Tigers Inn"+NORM+": "+HIM+"A Private Room"+NORM);
set_long("   "+HIG+"This is a private room in the back of the bar. Its\n"+
            "very comfortable, with a set of "+HIB+"couches"+HIG+", a "+NORM+""+YEL+"table"+HIG+", and\n"+
            "its own private door to the "+HIR+"kitchen"+HIG+".   It is reserved\n"+
            "usually for the V.I.P.'s of the "+HIY+"Inn"+HIG+"."+NORM+"\n");
   add_object("/players/tallos/7tigers/mobs/horcb.c"); 
   add_object("/players/tallos/7tigers/mobs/halforcbarb1.c",3);   
   add_exit(PATH+"/bar.c","out");
   add_smell("main","The smell of food. Its very pleasing to the senses.");
   add_smell("food","Its coming from the kitchen area. It makes you hungry.");

   add_item("couches","Comfortable and long. These couches provide and excellent\n"+
                      "place to sit and relax.");
   add_item("table","A place to put food and drinks it looks like.");
   add_item("kitchen","Its off limit to guests. But there it is.");
   add_item("drinks","Several are sitting on the table.");
   add_item("food","There is a rack of half eaten ribs on the table.");
set_light(1);
}
