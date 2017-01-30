
/*
 * FOLLOW (95/02/19)
 * For the guild track command. Uses "obj/wisp.c"
 * These are just commands for starting the wisp.
 */

#define WISP "players/sandman/paladin/obj/wisp"
#define MAXDIF 10			/* maximum difference in level */
#define EXPLORE 20

track( string str, object wisp) {
  object leader;

  if (!verify_use( 0, 1, 0))
    return 1;
  if (!str)
    notify_fail( "Who do you want to track?");
  if (wisp)
    notify_fail( "You are already tracking someone.");

  leader= present( str, environment( this_player()));
  if (!leader)
    notify_fail( capitalize( str) + " must be present.");
  if (!living(leader))
    notify_fail( "The challenge of tracking a dead thing is not great.");

  if ((leader->query_level() >= EXPLORE && 
       this_player()->query_level() < EXPLORE) ||
      (leader->query_level() - this_player()->query_level() > MAXDIF))
    notify_fail( "You may as well give up right away.");

  write( "You are now tracking " + capitalize( str) + ".\n");
  wisp= clone_object( WISP);
  wisp->setup( leader, this_player());
  move_object( wisp, environment( this_player()));
  return wisp;
}

lose( str, wisp) {
  if (str != "track")
    return 0;
  if (!wisp)
    notify_fail( "You are not tracking anybody!");

  destruct( wisp);
  write( "You are no longer tracking anybody.\n");
  return 1;
}
