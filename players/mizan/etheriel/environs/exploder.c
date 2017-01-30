/**
 * exploder.c
 * 
 * This is the simplest 'storm effect' object in the jello.
 * If basically goes off, and sends everything flying...
 *
 *
 */

int done_tl;
#include "/players/boltar/things/esc.h"

#define BLINK esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"
#define UNBLINK esc+"[0m"

id(str) { return str == "singularity"; }

short() { return 0; }

long() 
{
   write("There appears to be something wrong with the continuum of the\n"+
      "ether-muck here...\n");
}

init() 
{
   if(!done_tl) 
   {
      call_out("explodey", random(40));
   }
   
   done_tl=1;
}

explodey()
{
   object room,ob2,oc2;
   object ob;
   string destination;
   room=environment(this_object());

   if(!room) 
   {
      destruct(this_object());
      return 1; 
   }
  
   ob = first_inventory(room);
   
   say("An anomaly twists and expands from nowhere...\n\n"+
      "...Suddenly, it collapses on itself and "+BLINK+"explodes!"+UNBLINK+"\n\n"+
      "There is a violent explosion that sends shockwaves reeling everywhere...\n");

   call_other("players/mizan/closed/LiquidRoomDM", "bleat",
    "(bleat) A current surge is felt within the ether-muck.\n");
   
   
   while(ob) 
   {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      if(living(oc))
      {
         if(oc->query_npc() !=1)
         {
            
            if((oc->query_name()) == "Mizan") 
            {
               say((oc->query_name())+" fades from view.\n");
               move_object(oc, "room/void");
            }
            else
            {
               destination = call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
               say((oc->query_name())+" is catapulted to somewhere else.\n");
               oc->move_player(destination+"#players/mizan/etheriel/ROOMS/"+destination);
            }
         }

         if(oc->query_npc() == 1 && oc->query_level() < 20) 
         {
            if((oc->query_name()) == "Summerhead")
            {
               /* if we are summerhead, move to void. */
               oc->move_player("elsewhere#room/void");
            }
            else
            {
               /* otherwise if we are just a normal monster... we might get blown up */
               if(1 == random(10))
               {
                  oc->transfer_all_to("room/store");
                  say((oc->query_name())+" is blown to bits.\n");
                  destruct(oc);
               }
               else
               {
                 destination = call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
                 say((oc->query_name())+" is catapulted to somewhere else.\n");
                 oc->move_player(destination+"#players/mizan/etheriel/ROOMS/"+destination);
          
               }
                  
            }
         }
      }
   }
 
   /* clean ourselves up */
   destruct(this_object());
   return 1;
}
