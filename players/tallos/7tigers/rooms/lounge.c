#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Lounge"+NORM;
long_desc = "      "+HIC+"The"+NORM+""+NORM+""+CYN+" Lounge"+HIC+" is comfortable and pleasant.  The air\n"+
            "is filled with the gentle "+NORM+""+NORM+""+GRN+"music"+HIC+" of a "+HIB+"band of "+HIR+"bards"+HIC+" and\n"+
            ""+HIY+"minstrels"+HIC+" playing in the southwest corner. "+HIY+"Inn "+NORM+""+NORM+""+YEL+"workers"+HIC+"\n"+ 
            "move about tending to the every need of each guest.  A\n"+
            "group of "+NORM+""+NORM+""+CYN+"chairs"+HIC+" and "+NORM+""+NORM+""+CYN+"couches"+HIC+" sits around a large "+NORM+""+NORM+""+YEL+"coffee"+NORM+"\n"+
            ""+YEL+"table"+HIC+" in the center of the room."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/patron1.c", 2);
   add_object("/players/tallos/7tigers/mobs/customer1.c", 1);               
items = ({
  "band",
  "A band of 4 with a vocalist, a harpsicordist, a guitarist, and a drummer.",
  "bard",
  "She is sexy and winks at you suggestively as you enter and continues to sing.",
  "minstrel",
  "One of a group playing a gentle tune for the guests.",
  "chairs",
  "Severel soft ones its seems. They look very inviting.",
  "couchs",
  "One of many in the room, it is soft to the touch and would be a good place\n"+
  "for a nap.",
  "table",
  "It sits in the center of the room and holds the drinks of the guests sitting\n"+
  "around it.",
  "workers",
  "They move about quickly tending to the needs of each guest",
  "runes",
  "Several different runes of magic inscribed on the floor seem to pulse\n"+
  "with magical energy.",
  "paintings",
  "A wonderful seletion of paintings from artists all over the multiverse.",
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here.", 
  "murals",
  "The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence.",
  });
  add_listen("main","The sound of beautiful bardic music.");
  add_listen("music","It's gentle melody is soothing and gentle. The band is very well trained.");
  add_smell("main","The wonderful smell of "+HIR+"roses"+NORM+" is in the air.");
  add_smell("roses","The whole hall seems to produce this wonderful "+HIR+"f"+HIY+"l"+HIG+"o"+HIB+"w"+NORM+""+MAG+"e"+HIR+"r"+HIY+"y"+NORM+" odor.");

dest_dir = ({
    PATH+"/foyer.c","east",
    PATH+"/grandballroom.c","north",
  });
set_light(1);
}
