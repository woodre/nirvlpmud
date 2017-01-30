/*
 *  The save files of the mini guilds.  (v2.0)
 *
 */

save_me()  {
string file;
/* This was added to allow guilds to prevent miniguilds.  -Feld 4-27-00 */
  object ob;
  if(environment())
    ob=present("no_mini",environment());
  if(ob) {
    mixed name;
    name=file_name(this_object());
    name=explode(name,"#");
    name=name[0];
    name=explode(name,"/");
    name=name[4];
    call_other(ob,"mini_dest",name);
    destruct(this_object());
  }
/* End of Changes */
  file = "players/saber/closed/new_mini/stats/"+this_player()->query_real_name();
  if(this_player()->is_npc() || this_player()->is_pet() || this_player()->is_kid()) return 1;
  /*needs above, Bp. */
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
