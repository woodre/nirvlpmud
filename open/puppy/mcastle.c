#define NAME "Martha"
#define DEST "room/south/sforst3"
#include "/players/martha/define.h"

id(str) { return (str == "puppy" || str == "a puppy" || str == "memorial" || str == "a memorial"); }

short() {
return "A store.\n";
}

long(str) {
write("Some description.\n");
   }

init() {
   add_action("enter"); add_verb("enter");
}

enter(string str) {
   if (!str || str != "store"){
      notify_fail("What would you like to enter?\n");
      return 0;
   }
   
write("Some kewl message here.\n");
   say(this_player()->query_name()+" steps into the store.\n");
move_object(this_player(),"/players/martha/area/rooms/ptrees.c");
tell_room("players/martha/area/rooms/ptrees.c", this_player()->query_name()+" arrives.\n");
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
