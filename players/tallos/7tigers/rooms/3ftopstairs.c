#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Top of a "+BLK+"Sta"+HIR+"ir"+BLK+"case"+NORM;
long_desc = "    "+HIR+"This is the top of the stairs to the hotel.  While\n"+
            "the "+HIC+"rooms"+HIR+" might stop here you were sure you counted 10\n"+
            ""+NORM+""+NORM+""+GRN+"floors"+HIR+" from the outside, how odd?   Large double "+NORM+""+NORM+""+CYN+"doors"+HIR+"\n"+ 
            "lead off to rooms to the "+HIG+"east "+HIR+"and "+HIY+"west"+HIR+".  The beautiful\n"+
            ""+HIR+"m"+HIY+"u"+HIG+"r"+HIB+"a"+HIC+"l"+HIR+" is at it's closest here. A small"+NORM+""+NORM+" "+YEL+"golden "+HIB+"fountain"+HIR+"\n"+
            "is set against the south wall."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/customer1.c", 2); 
   add_object("/players/tallos/7tigers/mobs/bellhop1.c");             
items = ({
  "rooms",
  "This seems to be the final floor for the hotel rooms",
  "doors",
  "They are large and made of "+HIR+""+BLK+"iron"+NORM+""+NORM+""+YEL+"wood"+NORM+"",
  "floors",
  "Yes there was diffenately 10 floors or more from the outside. Thats odd..",
  "east",
  "The east hallway contains rooms from the hotel right through the large double doors",
  "west",
  "The west hallway contains rooms fromt he hotel left through the large double doors",
  "fountain",
  "This amazing "+HIY+"golden "+HIB+"fountain"+NORM+" seems to spring "+HIB+"water"+NORM+" from no pipe or basin",
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
  "mural",
  "The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence.  Here you can\n"+
  "see a large "+HIC+"a"+NORM+"n"+HIC+"g"+NORM+"e"+HIC+"l"+NORM+" with it's wings stretched wide. It's arms are open as if\n"+
  "to welcome you into them. There is also a large "+HIR+"demonic"+NORM+" creature painted\n"+
  "next to the angel.",
  "demon",
  "A "+HIR+"demonic"+NORM+" figure who holds his hand out as if to grasp yours and take you\n"+
  "OUT of this world",
  "angel",
  "A breathtaking painting of a "+HIC+"celestial being"+NORM+" that captivates your very soul\n"+
  "The "+HIC+"a"+NORM+"n"+HIC+"g"+NORM+"e"+HIC+"l"+NORM+" seems to be inviting you to "+HIB+"enter"+NORM+" it's arms",
  "carpet",
  "It is "+HIR+"red"+NORM+" and goes down the center of the steps all the way down the staircase",
  "staircase",
  "A beautiful "+BLK+"marble sta"+HIR+"irc"+BLK+"ase"+NORM+" that starts here and circles down into the "+HIY+"Bal"+HIR+"co"+HIY+"ny"+NORM+"\n"+ 
  "A beautiful "+HIR+"red"+NORM+" carpet goes down the center of the steps",
  });

dest_dir = ({
    PATH+"/3frighthall.c","east",
    PATH+"/3flefthall.c","west",
    PATH+"/balcony.c","down",
  });
set_light(1);
}
init() {
  ::init();
  add_action("enter","enter");
  add_action("out","out");
}
enter() {
  string str3;
  str3= PATH+"/cqhall.c";
  move_object(this_player(), PATH+"/cqhall.c");
  command("look",this_player());
  return 1;
}
out() {
  string str2;
  str2= PATH+"/demonhall.c";
  move_object(this_player(), PATH+"/demonhall.c");
  command("look",this_player());
  return 1;
}
