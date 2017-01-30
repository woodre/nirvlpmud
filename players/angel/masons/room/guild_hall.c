#include "../defs.h"

inherit "/room/room.c";

string name;
int leave_time, loan, rank, level, guild_exp;

reset(arg) {
  if(arg)
    return;
  set_light(1);
  
  if (!present("sign"))
    move_object(clone_object(OBJPATH+"sign"), this_object());

  long_desc = "\
You have entered the Guild Hall.  This is a richly furnished\n\
lobby.  Many accoutrements line the walls of the room, mostly\n\
tapestries depicting the rise of the Guild.  The guild meeting\n\
room lies to the south.\n\
A stable once stood to the east, but has been destroyed by the\n\
ravages of time.\nCOMMANDS:  join, leave\n\
   There are two obvious exits: up and south.\n";
  short_desc = "The Masons' Guild Hall";
  dest_dir = ({
	RPATH+"pub", "up",
    RPATH+"guild_lodge", "south",
  });
}

/* It'd be nice if we could find this somewhere */
east() {
   this_player()->move_player("east#players/sandman/masons/stable");
   return 1;
}

status try_south(string arg) {
  if(!present(MGOB_ID, this_player())) {
    write("The area to the north is for guildmembers only.\n");
    return 1;
  }
  this_player()->move_player("south#"+RPATH+"guild_lodge");
  return 1;
}

void init() {
  ::init();
  add_action("try_south", "south");
  add_action("join_guild", "join");
  add_action("leave_guild","leave");
}

status leave_guild(string arg) {
  string me;
  object guild;
  
  int pgexp,exp,minus;
  me = (string)this_player()->query_real_name();
  guild = present(MGOB_ID, this_player());
     
  if(!guild) {
    write("You are not a member of the Guild.\n");
    return 1;
  }
  
  rank =  (int)guild->query_glevel(me);
  pgexp = (int)guild->query_gexp(me);
  rm("/"+DATAPATH+me+".o");
  write("You are now no longer a member of the Guild.\n");
  say(capitalize(me)+" has left the Guild.\n");
  write_file(LOG_LEAVE, ctime()+ ": "+
    capitalize(me)+" (rank "+rank+", exp "+pgexp+") left the Guild.\n");
  if (loan = (int)guild->query_guild_loan()) 
    write_file(LOG_LEAVE, "  They defaulted on a loan of: "+loan+".\n");
    
  write("Note: in the old days you would have lost 1/6 of your exp,\n");
  write("which would amount to: ");
  exp = (int)this_player()->query_exp();
  minus = exp/6;
  write(minus+" experience points being subracted from you.\n");
  write("You also would have been banished from rejoining.\n");
  write("Neither will happen, as this is purely a mini-guild now.\n");
  /* this_player()->add_exp(-minus); */
  destruct(guild);
  return 1;
}


status join_guild(string arg) {
  string me;
  
  me = (string)this_player()->query_real_name();

  if(present("seal", this_player())) {
    write("You are already a member.\n");
    return 1;
  }
  if(this_player()->query_level() < 3) {
    write("You must be third level to join.\n");
    return 1;
  }
  move_object(clone_object(MGOB), this_player());
  write("You have now joined the Masons Mini-Guild.\n");
  write("Type 'seal' for information on your new abilities.\n");
  say(capitalize(me)+" has joined the Guild.\n");
  write_file(LOG_JOIN, ctime()+": "+
    capitalize(me)+"("+
    (int)this_player()->query_level()+") joined the Guild.\n");
  return 1;
}




