inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

object trackee;
object trackee_room;
object trackee_old_room;

object destn;
int snooptime;
int snooptime_tl;


reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A shiny blue sphere");
   set_long_desc("You look into the sphere and see an amorphous blue blob.\n"+
  "The sphere contains the matrix of regeneration for\n"+
  "your current polymorph as a blobel.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("blobel");
   set_deathtime(3200);
} 

init() 
{
   add_action("blobel_confusion","confusion");
   add_action("blobel_unfrog","unfrog");
   add_action("blobel_deepsurvey","deepsurvey");
   add_action("blobel_tuck","tuck");
   add_action("blobel_radar","radar");
   add_action("blobel_gate_set","memorize");
   add_action("blobel_Blink","Blink");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to be somewhat caffienated";
}

blobel_confusion(arg) { return MASTER_R->blobel_confusion(arg); }
blobel_unfrog(arg) { return MASTER_R->blobel_unfrog(arg); }
blobel_deepsurvey() { return MASTER_R->blobel_deepsurvey(); }
blobel_tuck(arg) { return MASTER_R->blobel_tuck(arg); }

blobel_radar(arg)
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
if(trackee->query_invis()){
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
    if(trackee->query_invis()){
           command("vibe " + "Radar turned off.\n", environment(this_object()));
           return 1;
     }
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


blobel_gate_set() 
{
  object ob;
  ob = environment(this_player());
  if(ob->query_realm() == "NT") 
  {
    write("Something in the room is preventing you from memorizing it.\n");
    return 1;
  }
  destn = ob;
  write("You study your surroundings and memorize them to the best of your ability.\n");
  this_player()->remote_say((this_player()->query_name()) + " ponders thoughtfully about the room.\n");
  return 1;
}

blobel_Blink() 
{
 if(!destn) {
   write("You have nowhere memorized!\n");
   return 1;
  }
  if(this_player()->query_sp() < 50) {
    write("You feel too drained to attempt this.\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    write("You are too busy fighting!\n");

    return 1;
  }

  this_player()->add_spell_point(-50);
  write("You blink loudly and travel phased to your memorized location.\n");
  this_player()->remote_say((this_player()->query_name()) + " fades from view.\n"); 
  move_object(this_player(), destn);
  this_player()->remote_say((this_player()->query_name()) + " fades into view.\n");
  command("look", this_player());
  return 1;
}

/*
blobel_dreamscape() 
{
  if(snooptime_tl) {
    write("You are already in a state of thoughtless awareness!\n");
    return 1;
  }
  if(this_player()->query_sp() < 60) {

    write("You feel too drained to attempt this.\n");
    return 1;
  }
  this_player()->add_spell_point(-60);
  write("You lapse into intense concentration, and drift into\n"+
  "a dreamy state of thoughtless awareness.\n");
  say((this_player()->query_name()) + " drifts into a state of thoughtless awareness.\n");
  snooptime = 55 + random(this_player()->query_attrib("sta"));
  remove_call_out("spr_force_return");
  snooptime_tl = 1;
  call_out("spr_force_return", snooptime);
  return 1;
}
*/

spr_force_return() 
{
  snooptime_tl = 0;
  if(ENV) {
    tell_object(ENV, "You feel your sensitivity to ambient vibes fading, and the chatterbuzz\n"+
    "of a heightened reality fades away.\n");
    ENV->remote_say((ENV)->query_name() + " blinks loudly.\n");
    return 1;
  }
}

