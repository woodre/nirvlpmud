/*
 * FOLLOW (95/02/13)
 * For the guild track command. Uses "wisp.c"
 * These are just commands for starting the wisp.
 */

#define WISP "players/sandman/paladin/bal/wisp"
#define WISPNAME "wisp"

static object wisp;

id( str) { return str == "tracker";}
short() { return "A wisp tracker";}

long() {
  write( "\
A device for testing the 'wisp' way of tracking.\n\
You have the following commands:\n\
\ttrack <somebody>\n\
\tlose track\n\
\tquery track\n");
}

get() { return 1;}
init() {
  add_action( "track", "track");
  add_action( "lose", "lose");
  add_action( "query", "query");
}

track( str) {
  object leader;

  if (!str) return 0;

  if (wisp) {
    write( "You are already tracking someone.\n");
    return 1;
  }

  leader= present( str, environment( this_player()));
  if (!leader) {
    write( "There is no " + capitalize( str) + " present.\n");
    return 1;
  }

  if (!living(leader)) {
    write( "The challenge of tracking a dead thing is not great.\n");
    return 1;
  }

  if ((this_player()->query_level() < 20 && leader->query_level() > 19) ||
      leader->query_level() - this_player()->query_level() > 10) {
    write( "You may as well give up right away.\n");
    return 1;
  }

  write( "You are now tracking " + capitalize( str) + "\n");
  wisp= clone_object( WISP);
  wisp->setup( leader, this_player());
  move_object( wisp, environment( this_player()));
  return 1;
}

lose(str) {
  if (wisp && str == "track") {
    destruct( wisp);
    write( "You are no longer tracking anybody.\n");
    return 1;
  }
}

query(str) {
  if (str != "track") return 0;
  if (!wisp) {
    write( "You are not tracking anybody.\n");
    return 1;
  }

  write( "Wisp data: ");
  wisp->wisp_stats();
  return 1;
}
