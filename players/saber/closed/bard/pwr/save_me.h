/*
 *	The save function of the Storm Bards of Ryllian
 *	By Saber / Geoffrey - thanks origionally to Blue
 *	v3.0
 *
 */

save_me()  {

string file;

  file = "players/saber/closed/bard/stats/" + this_player()->query_real_name();
  
  if(!save_object(file))  {
  tell_object(environment(INSTR), "Error in saving guild score!\n");
 
   }  else   {
   
  tell_object(environment(INSTR),
    HIM+"Your Bardic stats have been saved.\n"+
    "Party on!\n"+NORM);
        }
        
  environment(INSTR)->set_guild_name("bard");
  return 1;
        }
