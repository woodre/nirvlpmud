#include "/players/quicksilver/666/include/std.h"
inherit "obj/monster";

/* This provides for an intelligent method of random monster movement. */

int move_chance, moveable;
string restrict_domain,valid_moves;

set_moveable(i) { moveable=i; }
set_move_chance(i) { move_chance=i; }
set_domain(str) { restrict_domain=str; }

query_moveable() { return moveable; }
query_move_chance() { return move_chance; }
query_domain() { return restrict_domain; }
query_valid_moves() { return valid_moves; }

reset(arg) {
   ::reset(arg);
   if(!moveable) { return 1; }
   if(!arg) {
      move_me();
      return 1;
   } else {
      remove_call_out("move_me");
      move_me();
      return 1;
   }

}

init() { ::init(); }

create_valid_movement_list() {
   
   return 1;
}

move_me() {
   int i;
   string dirs;
   object roomob;

   if(ENVTO) {
      dirs=ENVTO->query_dest_dir();
      valid_moves=0;
      if(restrict_domain) {
         for(i=0; i<sizeof(dirs); i+2) {
            roomob=find_object(dirs[i]);
            if(sscanf(dirs[i],restrict_domain+"%s")&&roomob->query_dest_dir())
               if(valid_moves)
                  valid_moves+=({dirs[i+1]});
               else
                  valid_moves=({dirs[i+1]});
         }
      } else { 
         for(i=0; i<sizeof(dirs); i+2) {
            roomob=find_object(dirs[i]);
            if(roomob->query_dest_dir())
               if(valid_moves)
                  valid_moves+=({dirs[i+1]});
               else
                  valid_moves=({dirs[i+1]});
         }
      }   

      if(!valid_moves) {
         moveable=0;
         remove_call_out("move_me");
         return 1;
      }
      if(random(100)<move_chance) 
         command(valid_moves[random(sizeof(valid_moves))]);
   } 
   call_out("move_me",5);
   return 1;
}
