#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Foyer"+NORM;
long_desc = "   "+HIY+"A grand entrance "+NORM+""+YEL+"hall"+HIY+" lays out before you. "+HIB+"Bellhops\n"+
            ""+HIY+"and "+HIG+"clerks"+HIY+" snap to attention greeting you with a smile\n"+
            "and quick service. The "+HIC+"ceiling"+HIY+" is enlayed with awesome\n"+ 
            ""+HIR+"m"+HIY+"u"+HIG+"r"+HIB+"a"+HIC+"l"+HIM+"s"+HIY+" of far away planes and strange dimensions.  The\n"+
            ""+HIB+"walls"+HIY+" are covered with fine "+HIB+"p"+HIG+"a"+HIR+"i"+HIB+"n"+HIG+"t"+HIR+"i"+HIB+"n"+HIG+"g"+HIR+"s"+HIY+" and the "+NORM+""+CYN+"floor"+HIY+" in"+HIC+"\n"+
            "mystical "+NORM+""+RED+"r"+YEL+"u"+GRN+"n"+CYN+"e"+MAG+"s"+HIY+". There is a"+HIC+" sign"+HIY+" here."+NORM+""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/customer1.c",2);
    add_object("/players/tallos/7tigers/mobs/bellhop1.c",2);  
    add_smell("main","The wonderful smell of "+HIR+"roses"+NORM+" is in the air");
    add_smell("roses","The whole hall seems to produce this wonderful "+HIR+"f"+HIY+"l"+HIG+"o"+HIB+"w"+NORM+""+MAG+"e"+HIR+"r"+HIY+"y"+NORM+" odor");
    add_listen("main","You hear the sounds of a busy hotel, from the quick movement of Inn staff to\n"+
                      "customers talking in the lounge.");     
items = ({
  "ceiling",
  "Beautiful "+HIR+"m"+HIY+"u"+HIG+"r"+HIB+"a"+HIC+"l"+HIM+"s"+NORM+" cover the entire ceiling",
  "bellhops",
  "They move about quickly carrying baggages for guests",
  "runes",
  "Several different runes of magic inscribed on the floor seem to pulse\n"+
  "with magical energy",
  "paintings",
  "A wonderful seletion of paintings from artists all over the multiverse",
  "hall",
  "It is the very pinacle of perfection. A tall vaulted ceiling with paintings\n"+
  "and murals like you have never seem before.",
  "walls",
  "Covered in fine paintings and wonderful artwork form all over the planes.",
  "floor",
  "Made of large marbel slabs, it is covered in runes.",
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here", 
  "clerks",
  "Standing behind a front desk they are ready to serve your every command",
  "murals",
  "The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence",
  "sign",
  "Welcome to the 7 Tigers Inn. Enjoy your stay with us\n"+
  ">  Bar\n"+
  "<  Lounge\n"+
  "^  Hotel, Grand Ballroom, and Restaurant",
  });


dest_dir = ({
    PATH+"/portalroom.c","out",
    PATH+"/bar.c","east",
    PATH+"/lounge.c","west",
    PATH+"/mainhall.c","north",
  });
set_light(1);
}
