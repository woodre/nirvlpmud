#define NAME "Martha"
#define DEST "room/south/sforst3"
#include "/players/martha/define.h"

id(str) { return (str == "store" || str == "media" || str == "madness" || str == "a store"); }

short() {
return HIB+"M"+HIM+"e"+HIB+"d"+HIM+"i"+HIB+"a "+HIM+"M"+HIB+"a"+HIM+"d"+HIB+"n"+HIM+"e"+HIB+"s"+HIM+"s"+NORM;
}

long(str) {
write(
"Come on in for the GRAND OPENING of Media Madness!  There is\n\
a bigger variety inside than in any other store on the MUD!\n\
Perhaps one could 'enter' the 'store' and see for oneself?\n");
   }

init() {
  add_action("enter", "enter");
}

enter(string str) {
   if (!str || str != "store"){
      notify_fail("What would you like to enter?\n");
      return 0;
   }
   
write("You push open the door and enter the marvelous new store!\n");
   say(this_player()->query_name()+" leaves into the store.\n");
move_object(this_player(),"/players/martha/store.c");
tell_room("players/martha/store.c", this_player()->query_name()+" arrives.\n");
   write_file("/players/martha/log/area",
      this_player()->query_real_name()+"   "+ ctime()[4..15]+"\n");
   command("look",this_player());
   return 1;
}

reset(arg) {
   move_object(this_object(),DEST);
   if(arg) return;
}

is_castle(){return 1;}
