
/*
 * WISP (95/02/13)
 * For the guild track command. Used by "follow.c"
 * See description in "wisp.txt"
 */

#define MAXLOST 5		/* max lost value before track is lost */
#define WISPNAME "paladin_wisp"	/* an obscure name */
#define ENV environment

object leader;
object follower;
string lastdone;		/* last command leader did */
int lost;			/* increased when follower is !present */

id( str) {
  return str == WISPNAME;
}

long() {
  if (this_player()->query_level() > 19)
    wisp_stats();
  else
    write( "Paranoid?");
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

  if (!leader || !follower || !ENV( leader)) {
    if (follower)
      tell_object( follower, "You have lost the trail.\n");
    destruct( this_object());
    return;
  }

  /* if lastdone isn't cleared, wisp freezes. This way, the wisp */
  /* will still work, if something, i.e. an error, occurs */
  temp= lastdone;
  lastdone= 0;
  if (ENV() != ENV( leader)) {

    if (ENV() == ENV( follower)) {
      lost= 0;
      move_object( this_object(), ENV( leader));
      command( temp, follower);
    }
    else {
      lost++;
      if (lost > MAXLOST) {
        tell_object( follower, "You have lost the trail.\n");
        destruct( this_object());
      }
      else
        move_object( this_object(), ENV( leader));
    }
  }
}

void setup( object l, object f) {
  leader= l;
  follower= f;
}

wisp_stats() {
  if (leader)
    write( "Leader:   " + leader->query_real_name() + "\n");
  if (follower)
    write( "Follower: " + follower->query_real_name() + "\n");

  write( "Lost for: " + lost + "\n");
  write( "Last cmd: " + lastdone + "\n");
}
