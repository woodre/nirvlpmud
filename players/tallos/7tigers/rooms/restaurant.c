#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
	if(!present("patron",this_object()))
  move_object(clone_object("/players/tallos/7tigers/mobs/patron1.c"),this_object());
  move_object(clone_object("/players/tallos/7tigers/mobs/patron1.c"),this_object());
  move_object(clone_object("/players/tallos/7tigers/mobs/patron1.c"),this_object());
  if(arg) return;
    if(!present("halflingrogue",this_object()))
  move_object(clone_object("/players/tallos/7tigers/mobs/halflingrogue1.c"),this_object());
  
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Restaurant"+NORM;
long_desc = "  "+HIR+"The smell of a multitude of different pleasures hits\n"+
            "your nose. The "+HIY+"Taste of the "+HIB+"Planes"+HIY+" restaurant"+HIR+" boasts a\n"+
            ""+HIB+"menu"+HIR+" that is without end. Anything you wish is here to\n"+ 
            "order. "+HIC+"Waitresses"+NORM+""+HIR+" move quickly about bringing "+NORM+""+CYN+"platters"+HIR+"\n"+
            "full of delicous smelling "+NORM+""+NORM+""+RED+"food "+HIR+"to the hungry "+BLK+"people"+HIR+" of\n"+
            "the establishment.  There is a "+BLK+"chalkboard"+NORM+""+HIR+" right inside\n"+
            "the door with "+HIR+"c"+HIY+"o"+HIG+"l"+HIB+"o"+HIM+"r"+BLK+"f"+HIR+"u"+HIY+"l"+NORM+""+HIR+" writing on it."+NORM+"\n";
  add_smell("main","A wonder blend of smells of food of all types.");
items = ({
  "people",
  "Several hundred people sit and dine. The number of tables needed and the space.\n"+
  "always increases or decreases depending on the crowd. There is never a wait for\n"+
  "a table in this restaurant.",
  "platters",
  "Full of food of various varieties. Everything you could possibly imagine is here.",
  "menu",
  "The menu is several hundred pages long, but it feels very light in your hands.\n"+
  "It must be extra dimensional in nature.",
  "waitresses",
  "They move quickly about taking orders and delivering food to patrons",
  "food",
  "Wonderful tasty delights being eaten by the patrons",
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here", 
  "chalkboard",
  "Welcome to \"Tastes of the Planes\"\n"+
  ""+HIM+"@~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~@"+NORM+"\n"+
  "Todays specials are:\n"+
  ""+HIG+"Appetizer: "+HIR+"Fiendish"+NORM+" Spearfish "+HIY+""+BLK+"caviar"+NORM+" with "+HIY+""+BLK+"Drow"+NORM+""+NORM+" flat "+YEL+"bread"+NORM+"\n"+ 
  " \n"+
  ""+HIB+"1st Course: "+NORM+""+NORM+"Celestial"+GRN+" Watercresh"+HIG+" salad"+NORM+" with Vinaigrette\n"+
  " \n"+
  ""+HIM+"2nd Course: "+NORM+""+NORM+""+CYN+"Gnomish"+HIY+" cheese"+NORM+""+NORM+" and "+RED+"radish "+HIY+"so"+NORM+""+NORM+""+RED+"up"+NORM+"\n"+
  " \n"+
  ""+HIR+"Main Course: "+NORM+""+NORM+""+RED+"Roast"+WHT+" White Dragon in "+NORM+""+NORM+""+RED+"G"+HIB+"o"+RED+"o"+HIB+"d"+RED+"b"+HIB+"e"+RED+"r"+HIB+"r"+RED+"y"+NORM+" Sauce\n"+
  " \n"+
  ""+HIC+"Dessert: "+NORM+"Chilled "+HIB+"Aurian"+NORM+""+NORM+""+YEL+" Moose"+NORM+" on "+RED+"Dwarven Pound Cake"+NORM+"\n"+ 
  " \n"+
  ""+NORM+"Beverage of Choice: 1262 "+HIG+"Dalelands Vintage"+NORM+""+NORM+" "+GRN+"Elven"+WHT+" White"+NORM+"\n"+
  " \n"+
  ""+HIM+"@~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~@"+NORM+"",
  });

dest_dir = ({
    PATH+"/mainhall.c","west",
    PATH+"/bar.c","south",
  });
set_light(1);
}
