inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"

int healMode;
#define COFFERCOST 1000

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - healing room");
   set_long("clan hall healing room.\nRoom will heal you at an accelerated rate up to 3/4ths of your max hp.\n1,000 coins will be deducted from the clan coffers per heal tick.");
   add_property("NT");
   restore_me();
}

init(){
   ::init();
   
   check_valid_entry();
   
   if(this_player() && healMode != 1) {
      
      healMode = 1;
      call_out("healPeople",4);
      
   }
   
}



healPeople() {
   
   object inventoryItem, cobject;
   int people;
   
   inventoryItem = first_inventory(this_object());
   people = 0;
   
   while(inventoryItem) {
      
      if(inventoryItem->is_player()) {
         
         people++;
         
         /* Stop healing at 3/4ths of max health */
         if(inventoryItem->query_hp() >= (inventoryItem->query_mhp() / 4 * 3)) {
            
            tell_object(inventoryItem,"You are unable to receive more healing.\n");
            
         } else {
            
            cobject = present("clan_object",inventoryItem);
            
            /* Make sure they can cover the cost of the heal */
            if(cobject && (int)cobject->query_private_coffer() < COFFERCOST) {
               
               tell_object(inventoryItem,"Coffer balance too low to heal.\n");
               
              } else {
               
               /* Take coins from coffer and heal player */
               cobject->add_private_coffer(-COFFERCOST);
               inventoryItem->heal_self(1 + random(10));
               tell_object(inventoryItem,"The room converts 1,000 coffer coins to healing eneregy.\n");
               
              }
            
         }
         
         }
      
      inventoryItem = next_inventory(inventoryItem);
      
   }
   
   /* If we still have people in the room, repeat call_out */
   if(people > 0)
      call_out("healPeople", 4);
   else
      healMode = 0;
   
}

query_cost() { return 5000000; }
