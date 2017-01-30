/*
 *  The save files of the mini guilds.  (v2.0)
 *
 */

save_me()  {
string file;
  file = "players/saber/closed/new_mini/stats/"+this_player()->query_real_name();
/*
  if(!save_object(file))  {
  write("Error in saving mini guild stats!!!  Tell Saber.\n");
  }  else  {
  Changed for 3.2 Driver -Bp.
*/
  save_object(file);
  write(
      "Your mini guild stats have been saved.\n");
/*
        }
*/
  return 1;
        }
