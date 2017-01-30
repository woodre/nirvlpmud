/*
 *	The restore function of the Storm Bards of Ryllian
 *	By Saber / Geoffrey - thanks origionally to Blue
 *	v3.0
 *
 */

restore_me(name)  {

object player;

  if(!name)  {
    if(!environment(this_object()) ||  !environment(this_object())->query_name())  return 0;
  name = environment(this_object())->query_real_name();
        }
  
  player = find_player(name);
  
  if(!player) return 0;
  
  tell_object(player, HIM+"Your mind fills with music."+NORM+"\n");
  restore_object("players/saber/closed/bard/stats/" + name);
  
   if(guild_status == -1)  {
     write("You have been banished from the Bards.\n"+
           "Send mail Saber if you don't agree.\n");
     destruct(TO);
        }
        
  if(guild_status == -2)  {
      write("You have been placed on suspension from the Bards.\n"+
            "Send mail Saber is you don't agree.\n");
      destruct(TO);
        }
        
  environment(this_object())->set_guild_name("bards");
  return 1;
        }
