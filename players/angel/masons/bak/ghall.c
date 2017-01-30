#include <ansi.h>

inherit "/room/room";

int leave_time, loan, rank, level, guild_exp;

int name;

int me;

reset(arg)
{
  ::reset(arg);
  if(!present("sign"))
     move_object(clone_object("/players/angel/masons/sign"), this_object());
  if(!present("board"))
     move_object(clone_object("/players/angel/masons/aboard"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "The Guild Hall";
  long_desc =
"  You have entered the Guild Hall. This is a richly furnished\n\
lobby. Many accoutrements line the walls of the room, mostly\n\
tapestries depicting the rise of the Guild. The guild meeting\n\
room lies to the south.\n";

  items =
  ({
  });
  dest_dir =
  ({
    "/players/angel/masons/glodge",  "south",
    "/players/angel/masons/pub2",     "up",
  });
}
init() {
  ::init();
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
       write("You are not a member of the Mini-Guild.\n");
       return 1;
     }
     rank = guild->query_guild_rank();
     pgexp = this_player()->query_guild_exp();
     this_player()->add_guild_exp(-pgexp);
     write("You are now no longer a member of the Mini-Guild.\n");
     say(capitalize(me)+" has left the Guild.\n");
     write_file("/players/angel/masons/BANISHED",
          capitalize(me)+"(rank "+rank+")"+
          " left the Guild "+ctime(time())+"\n");
     if(this_player()->query_level() < 20) {
     name = me;
     level = this_player()->query_level();
     guild_exp = guild->query_guild_exp();
     leave_time = ctime(time());
     loan = guild->query_guild_loan();
     save_object("players/angel/masons/BANISHED"+me);
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
     if(restore_object("players/angel/masons/BANISHED"+me)) {
       write("You have been banished from the Guild.\n");
       write("If you wish to re-enter you must petition the Guild Masters.\n");
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
     move_object(clone_object("players/angel/masons/seal"), this_player());
     this_player()->add_guild_exp(1);
     write("You have now joined the Mini-Guild.\n");
     write("Type 'seal' for information on your new abilities.\n");
     say(capitalize(me)+" has joined the Mini-Guild.\n");
     write_file("/players/angel/log/recruit",
          capitalize(this_player()->query_real_name())+"("+
          this_player()->query_level()+") joined the Mini-Guild "+ctime(time())+"\n");
     return 1;
}