#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Bar"+NORM;
long_desc = "  "+HIY+""+BLK+"A long counter runs along the left side of the room.\n"+
            "Behind it are several "+NORM+""+NORM+""+YEL+"bartenders"+HIY+""+BLK+" that are busy pouring\n"+
            ""+NORM+""+NORM+""+RED+"drinks"+HIY+""+BLK+" for travellers and cleaning the bar.    Several\n"+ 
            "patrons and "+HIB+"adventurers"+HIY+""+BLK+" frequent this part of the "+HIY+"inn"+BLK+".\n"+
            "There is a"+NORM+" "+NORM+""+YEL+"door"+HIY+""+BLK+" to a backroom behind the bar."+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/bartender1.c"); 
    add_object("/players/tallos/7tigers/mobs/patron1.c", 2);                
items = ({
  "drinks",
  "Several types from all over the planes. Mmmm beer...",
  "bar",
  "A long counter with chairs along the length. Drinks line the top",
  "door",
  "A back door into a private room. Perhaps you could enter it?",
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here", 
  "bartenders",
  "They seem to be busy pouring ales and mixing drinks for customers",
  "adventurers",
  "Since this is port for all people of the planes, adventurers travel\n"+
  "here to seek employement and recreation",
  "drinks",
  "Behind the bar are several thousand bottles and flasks full of wonderful\n"+
  "beverages of all kinds",
  });
  add_smell("main","The smell of beer is in the air. It doesn't surprise you.");
dest_dir = ({
    PATH+"/foyer.c","west",
    PATH+"/restaurant.c","north",
  });
set_light(1);
}
init() {
  ::init();
  add_action("enter","enter");
}
enter() {
  string str3;
  str3= PATH+"/privateroom.c";
  move_object(this_player(), PATH+"/privateroom.c");
  command("look",this_player());
  return 1;
}