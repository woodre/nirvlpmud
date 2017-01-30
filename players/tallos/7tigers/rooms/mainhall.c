#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Main Hall"+NORM;
long_desc = "      "+HIY+"The main "+NORM+""+YEL+"hall"+HIY+" of the "+NORM+""+NORM+""+YEL+"Inn"+HIY+" can be found here. Many\n"+
            ""+HIM+"doors"+HIY+" lead off to the inner part of the "+HIB+"hotel"+HIY+".  As you\n"+
            "move you are passed by busy Inn "+HIC+"employees"+HIY+" on their way\n"+ 
            "to do the tasks that they are assigned.  In the center\n"+
            "of the "+HIB+"room"+HIY+" is a large "+HIB+"HOTEL DIRECTORY"+HIY+".  A huge "+BLK+"marble\n"+
            "sta"+HIR+"irc"+BLK+"ase"+HIY+" starts here and goes up."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/customer1.c", 2);
   add_object("/players/tallos/7tigers/mobs/bellhop1.c", 1);             
items = ({
  "doors",
  "Several large oak doors lead to the restaurant and to the grandballroom as well as\n"+
  "back into the foyer.",
  "hall",
  "A large directory is in the center of this room, and several doors lead to other\n"+
  "places in the hotel. A staircase goes to the upper floors from here.",
  "hotel",
  "The finest in all the planes. The 7 Tigers Inn is the best in all things.",
  "room",
  "The main hall of the Inn, From here all areas branch off.",
  "employees",
  "Bellhops and hotel clerks move about doing odd tasks. They seem to be\n"+
  "travelling in and out from a roped off area to the north",
  "north",
  "A hallway aside from the main hotel. It's roped off by red cord",
  "rope",
  "A "+HIR+"red cord"+NORM+" that blocks off the north hallway. You might be able to "+HIB+"pass"+NORM+"\n"+
  "by it without being seen"+NORM+"",
  "bellhops",
  "They move about quickly carrying baggages for guests",
  "runes",
  "Several different runes of magic inscribed on the floor seem to pulse\n"+
  "with visible energy",
  "paintings",
  "A wonderful seletion of paintings from artists all over the multiverse",
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here", 
  "clerks",
  "standing behind a front desk they are ready to serve your every command",
  "murals",
  "The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence",
  "carpet",
  "It is "+HIR+"red"+NORM+" and goes up the center of the steps all the way up the staircase",
  "staircase",
  "A beautiful "+BLK+"marble sta"+HIR+"irc"+BLK+"ase"+NORM+" that starts here and circles up into the "+HIY+"Bal"+HIR+"co"+HIY+"ny"+NORM+"\n"+ 
  "A beautiful "+HIR+"red"+NORM+" carpet goes up the center of the steps",
  "directory",
  ""+HIB+"HOTEL DIRECTORY"+NORM+"\n"+
  ""+HIC+"--------------------------------------------------------------------"+NORM+"\n"+
  ""+HIY+"@"+NORM+" The "+HIY+"Foyer"+NORM+" and "+HIM+"P"+HIB+"o"+HIR+"r"+HIG+"t"+HIY+"a"+BLK+"l"+NORM+""+HIC+" Room"+NORM+" are located to the south\n"+
  " \n"+
  ""+HIG+"@"+NORM+" The "+BLK+"Bar"+NORM+" can be located east in the "+HIY+"Foyer"+NORM+"\n"+
  " \n"+
  ""+HIB+"@"+NORM+" The "+HIM+"Lounge"+NORM+" can be located west in the "+HIY+"Foyer"+NORM+"\n"+
  " \n"+
  ""+HIM+"@"+NORM+" Continue up the "+BLK+"sta"+HIR+"irc"+BLK+"ase"+NORM+" to the 2nd floor "+NORM+""+HIY+"Bal"+HIR+"co"+NORM+""+HIY+"ny"+NORM+"\n"+
  " \n"+
  ""+HIC+"@"+NORM+""+NORM+" The "+YEL+"Ballroom"+NORM+" can be located to the west of this location\n"+
  " \n"+
  ""+HIR+"@"+NORM+" Go east from here to sample foods from all over in our famous\n"+
  "  \""+HIR+"Taste"+NORM+" of the "+HIB+"Planes"+NORM+" "+HIY+"Restaurant"+NORM+"\"",
  });
  add_smell("main","The wonderful smell of "+HIR+"roses"+NORM+" is in the air.");
  add_smell("roses","The whole hall seems to produce this wonderful "+HIR+"f"+HIY+"l"+HIG+"o"+HIB+"w"+NORM+""+MAG+"e"+HIR+"r"+HIY+"y"+NORM+" odor.");


dest_dir = ({
    PATH+"/restaurant.c","east",
    PATH+"/foyer.c","south",
    PATH+"/grandballroom.c","west",
    PATH+"/balcony.c","staircase",
  });
set_light(1);

}
init() {
  ::init();
  add_action("pass","pass");
}

pass() {
  string str;
  str= PATH+"/backroom.c";
  move_object(this_player(), PATH+"/backroom.c");
  command("look",this_player());
  return 1;
}

