/*
 *  The restore files of the mini guilds.  (v2.0)
 *
 */

int mini_status;

restore_me(name)  {
object player;
  if(!name)  {
    if(!environment(this_object()) || !environment(this_object())->query_name()) return 0;
  name = environment(this_object())->query_real_name();
        }
  player = find_player(name);
  if(!player) return 0;
  /* So this isn't called by kids. -Feldegast 12-31-00 */
  if(player!=this_player()) return;
  tell_object(player, "Restorin your mini guild stats...\n");
  restore_object("players/saber/closed/new_mini/stats/"+name);
    if(mini_status == -1)  {
    write("You have been banished from all mini guilds.\n"+
        "Write Saber if you have a problem with this.\n");
    destruct(this_object());
        }
  return 1;
        }
