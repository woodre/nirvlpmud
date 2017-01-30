
#include "std.h"

string name;
int leave_time, loan, rank, level, guild_exp;

reset(arg) {
     if(arg)
       return;
/*
     extra_reset();
*/
     set_light(1);
}

object sign;

/*
extra_reset() {
     if(!present("sign")) {
       sign = clone_object("players/sandman/masons/sign");
       move_object(sign, this_object());
     }
}
*/

init() {
     add_action("south","south");
     add_action("east","east");
     add_action("north", "north");
     add_action("join_guild", "join");
     add_action("leave_guild","leave");
}

leave_guild() {
     string me;
     object guild;
     int pgexp,exp,minus;
     me = this_player()->query_real_name();
     guild = present("seal", this_player());

     if(!guild) {
       write("You are not a member of the Guild.\n");
       return 1;
     }
     rank = guild->query_guild_rank();
     pgexp = this_player()->query_guild_exp();
     this_player()->add_guild_exp(-pgexp);
     write("You are now no longer a member of the Guild.\n");
     say(capitalize(me)+" has left the Guild.\n");
     write_file("/players/sandman/masons/BANISHED/BANISH",
          capitalize(me)+"(rank "+rank+")"+
          " left the Guild "+ctime(time())+"\n");
     if(this_player()->query_level() < 20) {
     name = me;
     level = this_player()->query_level();
     guild_exp = guild->query_guild_exp();
     leave_time = ctime(time());
     loan = guild->query_guild_loan();
     save_object("players/sandman/masons/BANISHED/"+me);
     }
     exp = this_player()->query_exp();
     minus = exp/6;
     this_player()->add_exp(-minus);
     destruct(guild);
     return 1;
}


join_guild() {
     string me;
     me = this_player()->query_real_name();

     if(present("seal", this_player())) {
       write("You are already a member.\n");
       return 1;
     }
     if(restore_object("players/sandman/masons/BANISHED/"+me)) {
       write("You have been banished from the Guild.\n");
       write("If you wish to re-enter you must petition the Guildmasters.\n");
       return 1;
     }
     if(this_player()->query_guild_exp() > 0) {
       write("You may only be a member of one guild!\n");
       return 1;
     }
     if(this_player()->query_level() < 3) {
       write("You must be third level to join.\n");
       return 1;
     }
     move_object(clone_object("players/sandman/masons/seal"), this_player());
     this_player()->add_guild_exp(1);
     write("You have now joined the Guild.\n");
     write("Type 'seal' for information on your new abilities.\n");
     say(capitalize(me)+" has joined the Guild.\n");
     write_file("/open/GIULDLOGS/RECRUIT",
          capitalize(this_player()->query_real_name())+"("+
          this_player()->query_level()+") joined the Guild "+ctime(time())+"\n");
     return 1;
}

north() {
     if(!present("seal", this_player())) {
       write("The area to the north is for guildmembers only.\n");
       return 1;
     }
     call_other(this_player(), "move_player",
                    "north#players/sandman/masons/guild_lodge");
     return 1;
}

south() {
     call_other(this_player(), "move_player",
                    "south#players/sandman/ad_room");
     return 1;
}

east() {
   this_player()->move_player("east#players/sandman/masons/stable");
   return 1;
}

short() { return "The Guild Hall"; }

long() {
     write("You have entered the Guild Hall.  This is a richly furnished\n");
     write("lobby.  Many accoutrements line the walls of the room, mostly\n");
      write("tapestries depicting the rise of the Guild.  The guild meeting\n");
      write("room lies to the north.\n");
     write("A stable lies to the east.\n");
     write("COMMANDS:  join, leave\n");
     write("   There are three obvious exits:  north, south and east\n");
}

