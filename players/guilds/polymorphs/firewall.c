#include "/players/mizan/esc.h"

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

object trackee;
object trackee_room;
object trackee_old_room;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A giant fuzzy blue sphere");
   set_long_desc("You look into the sphere and see a giant blue thing\n"+
  "staring back at you.\n"+
  "It contains the matrix of regeneration for\n"+
  "your current polymorph as a firewall.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("firewall");
   set_deathtime(2000);
   set_block_killcmd();
} 

init() 
{
   add_action("firewall_sponge","sponge");
   add_action("firewall_evaluate","evaluate");
   add_action("firewall_track","track");
   add_action("firewall_halt","halt");
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to be a big blue filtering sponge\n)";
}

firewall_sponge(arg) { return MASTER_R->sponge_sponge(arg); }
firewall_evaluate(arg) { return MASTER_R->sponge_evaluate(arg); }
firewall_halt() { return MASTER_R->firewall_halt(); }

firewall_track(arg)
{
  if(!arg)
  {
     write("Radar tracking turned off.\n");
     remove_call_out("do_tracking");
     return 1;
  }
  
  trackee = find_player(arg);
  if(trackee && trackee->query_level() > 20) return 0;
  if(!trackee) trackee = find_living(arg);
   if(!trackee)
  {
     write("You ponder hard, but could not locate '" + arg + "'.\n");
     return 1;
  }

  if(environment(trackee))
  {
     trackee_room = environment(trackee);
  }
  else return 0;

  write("You ponder biggly and being to track " + lower_case(trackee->short()) + ".\n");

  call_out("do_tracking",1);
  return 1;
}

do_tracking() 
{
  if(!trackee)
  {
     command("vibe " + "Target disappeared.\n", environment(this_object()));
     return 1;
  }
  else 
  {
    if(environment(trackee))
    {
       trackee_room = environment(trackee);
    }
    else 
    {
       trackee_room = 0;
       return;
    }
    
    if(trackee_room != trackee_old_room) 
    {
       if(environment(this_object())->query_sp() < 3)
       {
          command("vibe " + "Radar turned off.\n", environment(this_object()));
          return 1;
       }
       else
       {
          if(trackee_room->short())
             command(("vibe Tracking " + (trackee->query_name()) + " in ->>" + trackee_room->short()),
                 environment(this_object()));
          else
             command(("vibe Tracking " + (trackee->query_name()) + " in ->> (location unknown)"),
                 environment(this_object()));
          environment(this_object())->add_spell_point(-3);
       }
    }

    trackee_old_room = trackee_room;

  }
  remove_call_out("do_tracking");
  call_out("do_tracking", 2);
}

