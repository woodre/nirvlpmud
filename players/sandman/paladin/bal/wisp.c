/*
 * WISP (95/02/13)
 * For the guild track command. Used by "follow.c"
 * See description in "wisp.txt"
 */

/* to be called "paladin_wisp" or something more obscure */
#define WISPNAME "wisp"

object leader;
object follower;
string lastdone;
int lost;

id( str) {
  return str == WISPNAME;
}

/* for debugging purposes. remove short() for invisibility */
short() {
  return WISPNAME;
}

long() {
  write( "Paranoid?\n");
}

init() {
  if (leader && this_player() == leader) {
    add_action( "follow"); add_xverb( "");
  }
}

follow( str) {
  if (!lastdone)
    call_out( "move_me", 1);
  lastdone= str;

  return 0;
}

move_me() {
  string temp;

  if (!leader || !follower) {
    destruct( this_object());
    return;
  }

  /* if lastdone isn't cleared, wisp freezes. This way, the wisp */
  /* will still work, if something, i.e. an error, occurs */
  temp= lastdone;
  lastdone= 0;
  if (!present( leader, environment())) {

    if (present( follower, environment())) {
      move_object( this_object(), environment( leader));
      command( temp, follower);
    }
    else {
      lost++;
      move_object( this_object(), environment( leader));
    }
  }
}

setup( object lead, object follow) {
  leader= lead;
  follower= follow;
}

wisp_stats() {
  if (leader)
    write( "Leader:   " + leader->query_real_name() + "\n");
  if (follower)
    write( "Follower: " + follower->query_real_name() + "\n");

  write( "Lost for: " + lost + "\n");
  write( "Last cmd: " + lastdone + "\n");
}
