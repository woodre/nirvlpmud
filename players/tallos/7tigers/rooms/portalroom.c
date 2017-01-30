#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
#define DEST "/room/south/"
inherit "/players/fred/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" "+HIM+"P"+HIB+"o"+HIR+"r"+HIG+"t"+HIY+"a"+BLK+"l"+NORM+""+HIC+" Room"+NORM;
long_desc = "      "+HIB+"This is the inner chamber of the "+HIY+"7 Tigers"+NORM+""+HIC+" portal\n"+
            "room"+HIB+"."+NORM+""+NORM+""+HIB+"  Many strange "+NORM+""+NORM+""+YEL+"doors"+NORM+""+NORM+""+HIB+" leading to several different\n"+
            "types of "+HIM+"w"+HIB+"o"+HIR+"r"+HIG+"l"+HIY+"d"+BLK+"s"+NORM+""+NORM+""+HIB+" are all around this lavishly decorated\n"+ 
            "room. The door to the "+HIY+"Inn"+NORM+""+HIB+" is here as well or you could\n"+
            "travel back to "+HIR+"Nirvana"+NORM+""+HIB+".\n"+
            "<"+HIR+"look at monsters"+HIB+"> for special information."+NORM+"\n"+
            " "+HIM+"Portal:"+HIY+" Inn"+HIM+"   Portal:"+HIG+" Nirvana"+NORM+"\n";
items = ({
  "inn",
  ""+HIY+"7 Tigers Inn"+NORM+" is one of the most famous hotels in all of the "+HIB+"Forgotten\n"+
  "Realms"+NORM+".  It links itself to many different planes and appears there as it\n"+
  "does here. Maybe you could go in and chat with fellow travellers?", 
  "portal",
  "A "+HIB+"s"+HIC+"h"+HIB+"i"+HIC+"m"+HIB+"m"+HIC+"e"+HIB+"r"+HIC+"i"+HIC+"n"+HIB+"g"+NORM+""+NORM+" oval of light pulsing with brilliant "+HIY+"e"+HIB+"n"+HIY+"e"+HIB+"r"+HIY+"g"+HIB+"y"+NORM+""+NORM+"",
  "doors",
  "Each "+YEL+"door"+NORM+" has a list of names for that dimension on the side in many different\n"+
  "languages. It opens up to a shimmering portal",
  "worlds",
  "Many planes of reality that are linked here by several "+YEL+"doors"+NORM+"",
  "nirvana",
  "The portal from which you came. It glows with a faint "+HIG+"green aura"+NORM+"",   
  "shadows",
  "The "+BLK+"shadows"+NORM+" seem to follow you as you enter. How odd?",
  "monsters",
  "The NPCs in "+HIB+"T"+HIC+"a"+HIB+"l"+HIC+"l"+HIB+"o"+HIC+"s'"+NORM+" realms are color coded by difficulty for your convience.\n"+
  " \n"+
  "White colored NPCs are:  Newbie level\n"+
  ""+HIB+"Blue"+NORM+" colored NPCs are:   Low level\n"+
  ""+HIG+"Green"+NORM+" colored NPCs are:  Medium level\n"+
  ""+HIR+"Red"+NORM+" colored NPCs are:    High level\n"+
  ""+HIM+"Purple"+NORM+" colored NPCs are: Epic level", 
  });
set_light(1);
}
init() {
  ::init();
  add_action("inn","inn");
  add_action("nirvana","nirvana");
}
inn() {
  string str2;
  str2= PATH+"/foyer.c";
  move_object(this_player(), PATH+"/foyer.c");
  command("look",this_player());
  return 1;
}
nirvana() {
  string str3;
  str3= "/room/south/sforst9";
  move_object(this_player(),  "/room/south/sforst9");
  command("look",this_player());
  return 1;
}  