#include <esc.h>

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

object drag_ob;
object burrow_ob;
object room;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A furry brown sphere");
   set_long_desc("You look into the sphere and see a happy, pudgy, brown furry face.\n"+
      "The sphere contains the matrix of regeneration for\n"+
      "your current polymorph as a wombat.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("wombat");
} 

init() {

   add_action("wombat_dig","burrow"); 
   add_action("block_sell","sell");
   add_action("block_sell","sel");

/*   add_action("wombat_burrow","burrow"); */
/*   add_action("wombat_drag","drag");     */   
   add_action("wombat_forage","forage");
   add_action("wombat_sniff","sniff");

   ::init();
}

extra_look() 
{
  if(ENV) return (ENV->query_name()) + " is a fat furry wombat.\n"+
    (ENV->query_name()) + " looks exceptionally good at digging holes and foraging";
}

set_drag_ob(arg) { drag_ob = arg; }
query_drag_ob() { return drag_ob; }
set_burrow(arg) { burrow_ob = arg; }
query_burrow() { return burrow_ob; }

wombat_dig() { 
	   object here;
	   string here_realm;
	   
           here=environment(this_player());
           here_realm=here->realm();
           if(here_realm=="NT") {
               write("You can't burrow here.\n");
               return 1;
           }

      return MASTER_R->wombat_dig(); 
    }

wombat_sniff(str) { return MASTER_R->wombat_sniff(str); }
wombat_forage() { return MASTER_R->wombat_forage(); }
wombat_burrow(arg) { return MASTER_R->wombat_burrow(arg); }
wombat_drag(str) { return MASTER_R->wombat_drag(str); }

fake_beat() 
{
    if(ENV && drag_ob) update_drag();
    if(ENV && ENV->query_weapon()) ENV->stop_wielding();
    ::fake_beat();
}

block_sell()
{
   /* had to add this in after quicksilver and salmonella
      found a potential problem with /room/store */
   write("You can't sell as a wombat.\n");

   return 0;
}

update_drag() 
{
   object thingo;
   if(environment(ENV) == environment(drag_ob)) return 0;
   ENV->say((drag_ob->short()) + " is dragged out by " + (ENV->query_name()) + ".\n");

   move_object(drag_ob, environment(ENV));
   tell_room(environment(ENV), (drag_ob->short()) + " is dragged in by " + (ENV->query_name()) + ".\n"); 
   if(environment(ENV)->query_realm() == "NT" || environment(ENV)->realm() == "NT" ) 
   {
      tell_object(ENV, "Something in this room negates your drag.\n");
      tell_object(drag_ob, "Something in this room negates the drag. You are no longer being dragged.\n");
      thingo = present("drag_device", drag_ob);
      if(thingo) destruct(thingo);
      drag_ob = 0;
   }
}

