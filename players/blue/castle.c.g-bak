#include "/players/blue/closed/lib/color.h"

#define DEST "room/plane2"
#define GUILD3_0 "/players/guilds/shadow/shadow.c"
#define GUILD_ENTER "/players/guilds/shadow/rooms/guild_enter.c"
#define MEETING "/players/guilds/shadow/rooms/meeting.c"
#define SERVANT "/players/guilds/shadow/obj/servant.c"
#define CASTLE_ENTER "/players/blue/castle_enter.c"
#define SHADES "/players/guilds/shadow/shades.c"

id(str) { return str=="pool"; }

short() { return BOLD+"A Pool of Darkness"+NOSTYLE; }

long() {
   write("This is the entrance to the Shadow Guild.\n");
   write("To enter the pool, type 'enter pool'.\n");
}

get() { return 0; }
drop() { return 1; }
value() { return 0; }
weight() { return 100000; }

reset(arg) {
  
   if(arg) return;

   move_object(this_object(),DEST);
   load(CASTLE_ENTER);
   load(GUILD3_0);
   load(MEETING);
   load(SERVANT);
      load(SHADES);
   
}

load(str) {
 /*
   write("Loading "+str+".\n");
   */
   call_other(str, "????", 0);
   return 1;
}

init() {
   add_action("enter_here","enter");
}

enter_here(str) {
   if(str == "castle") {
      this_player()->move_player("castle#players/blue/castle/entrance");
      write_file("/players/blue/ENTRY.LOG", this_player()->query_name() +
            " arrived at " + ctime(time()) + " with " + this_player()->query_money()+
            " coins\n    and " +this_player()->query_exp() +" exps.\n");
      return 1;
   }
   if(id(str)) {
     string who;
     who = this_player()->query_real_name();
     if(who != "boltar" && who != "bardock" && who != "tara" &&
        who != "zeppelin" && who != "anthrax" && who!= "unseen")
     {
        write("Shadow guild is in beta, please try later.\n");
        return 1;
    }
      this_player()->move_player("guild#"+GUILD_ENTER);
      return 1;
   }
}

is_castle() { return 1; }
