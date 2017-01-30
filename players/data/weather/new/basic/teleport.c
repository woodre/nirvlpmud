/*
 *  basic/teleport, foslay
 */

#include <prop/room.h>

varargs int
teleport_player (mixed dest, object player, int flag)
{
  object from;
  int ok;
    
  if (!player)
    player = this_player();
  
  from = environment (player);

  if (flag)
    ok = player->move_living(1, dest);
    // changed move() to move_living(), Coogan, 15-Mar-1999
  else
    ok = player->move_living("X", dest);
	
  if (ok) {
    catch(from->notify_teleport(player, 0));
    catch(dest->notify_teleport(player, 1));
  }
  return ok;
}

/*  teleport_ok() should be called every time a
 *  player object is teleported to verify if the
 *  involved rooms accept this.
 */
varargs int
teleport_ok (mixed from, mixed to, object player)
{
  if (!player) player = this_player ();

  if (from) {
    if (from->query_property(P_NO_TELEPORT) ||
        from->query_property(P_NO_TELEPORT_FROM))
    return 0;
  }
  if (to) {
    if (to->query_property(P_NO_TELEPORT) ||
        to->query_property(P_NO_TELEPORT_TO))
    return 0;
  }
  if (from && to) {
    if (from->query_no_teleport(from, to, player) ||
        to->query_no_teleport(from, to, player))
    return 0;
  }
  else if (from) {              // arguments by Ugh Feb-29-1996
    if (from->query_no_teleport(from, to, player))
      return 0;
  }
  else {                        // arguments by Ugh Feb-29-1996
    if (to->query_no_teleport(from, to, player))
      return 0;
  }
  return 1;
}

