#include "/players/llew/closed/ansi.h"
#define MC NORM+YEL

int room_number;
int locked;
string *items;
string long_desc;

id(str) {
    int i;
    if (!items)
	return;
    while(i < sizeof(items)) {
	if (items[i] == str)
	    return 1;
	i += 2;
    }
    return 0;
}


reset(arg) {
   if(arg) return;
   locked=2;
   set_light(1);
   long_desc="\tThe booth is lit by a single large candle flickering\n"+
      "slightly in the warm air.   The smooth wooden table is carved\n"+
      "from one large oak, oiled to preserve.  A small sign rests against\n"+
      "the wall, with a menu sitting beside it. A small silver bell sits\n"+
      "in a small alcove.  ";
   items=({
      "candle","The wax drips slowly on the long burning candle",
      "sign","A small sign carved of fine oiled oak",
      "alcove", "The alcove is just big enough to hold the small bell",
      "bell", "The silver bell rests gently in the alcove ready to ring\n"+
              "for the service of the proprietor",
      "menu", "The menu is a replica of the large sign in the bar",
   });
}

long(str) {
   int i;
   if(!str) {
	write(long_desc);
   if(locked == 2)
      write("The booth is open to all.\n");
   else
      write("The booth is closed.\n");
   write("The only exit is out.\n");
   return;
   }
    if (!items)
	return;
    i = 0;
    while(i < sizeof(items)) {
	if (items[i] == str) {
	    write(items[i+1] + ".\n");
	    return;
	}
	i += 2;
    }
}

short() {
   return GRN+"Lazy Llew's Bar"+HIW+" [Booth "+room_number+"]"+NORM;
}

init() {
   add_action("out","out");
   add_action("lock","lock");
   add_action("read","read");
   add_action("ring","ring");
}

read(str) {
   if(str == "menu") {
      "players/llew/Other/misc/lazy-sign"->long();
      return 1;
   }
   if(str == "sign") {
      write("\n"+
         HIY+"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
             "\t\t|" +  "                                    "   +  "|\n"+
             "\t\t|"+MC+" The booth may be closed to others  "+BOLD+"|\n"+
             "\t\t|"+MC+"   by typing \"lock\".  The same    "+BOLD+"  |\n"+
             "\t\t|"+MC+" command will open the booth again. "+BOLD+"|\n"+
             "\t\t|" +  "                                    "   +  "|\n"+
             "\t\t|"+MC+" Please ring the bell for service.  "+BOLD+"|\n"+
         HIY+"\t\t|" +  "                                    "   +  "|\n"+
             "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"+NORM);
      return 1;
   }
   else {
      notify_fail("Read what?\n");
      return 0;
   }

}

ring(str) {
   if(!str || str != "bell") {
      notify_fail("Ring what?\n");
      return 0;
   }
   say(this_player()->query_name()+" rings the bell for service.\n");
   write("You ring the bell for service.\n");
   call_out("get_service",5);
   return 1;
}

get_service() {
   if("players/llew/Other/monsters/llew"->wait_table(room_number)) {
      say("Llew seems to be occupied at the moment.\n"+
          "Perhaps you should try again in a minute.\n");
   }
}

out() {
   if(locked == 2) {
      this_player()->move_player("out#players/llew/Other/rooms/lazy");
      return 1;
   }
   write("You can't leave the locked booth.\n");
   return 1;
}

lock() {
   if(locked == 2) {
      write("You lock the booth.\n");
      say(this_player()->query_name()+" locks the booth.\n");
      locked=1;
      return 1;
   }
   if(environment(this_player()) == this_object()) {
      write("You unlock the booth.\n");
      say(this_player()->query_name()+" unlocks the booth.\n");
   }
   locked=2;
   return 1;
}

realm() { return "NT"; }
query_no_fight() { return 1; }
query_locked() { return locked; }
