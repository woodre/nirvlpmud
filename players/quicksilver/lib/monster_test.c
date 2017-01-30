#include "/players/quicksilver/666/include/std.h"

inherit "obj/monster.c";
inherit "players/quicksilver/lib/mob_script2.c";

/* This provides for an intelligent method of random monster movement. */

int move_chance, moveable;
string restrict_domain,valid_moves;
object talking_object;

set_moveable(i) { moveable=i; }
set_move_chance(i) { move_chance=i; }
set_domain(str) { restrict_domain=str; }
set_talking_object(ob) { talking_object=ob; }

query_moveable() { return moveable; }
query_move_chance() { return move_chance; }
query_domain() { return restrict_domain; }
query_valid_moves() { return valid_moves; }

reset(arg) {
   ::reset(arg);
   if(!gender) gender="creature";
   if(!race) race="creature";
   if(!moveable) { return 1; }
   if(!arg) {
      call_out("move_me",5);
      return 1;
   } else {
      remove_call_out("move_me");
      call_out("move_me",5);
      return 1;
   }

}

init() { ::init(); }

move_me() {
   int i, tmp;
   string dirs, tmpstr;

   if(random(100)>move_chance) {
      call_out("move_me",5);
      return 1;
   }
   if(ENVTO) {
      dirs=ENVTO->query_dest_dir();
      valid_moves=0;
      if(restrict_domain) {
         for(i=1; i<sizeof(dirs); i+=2) {
            if(objectp(dirs[i-1])) tmpstr=file_name(dirs[i-1]);
            else tmpstr=dirs[i-1];
            if(sscanf(tmpstr,restrict_domain+"%s",tmpstr))
               if(valid_moves)
                  valid_moves+=({dirs[i]});
               else
                  valid_moves=({dirs[i]});
         }
      } else { 
         for(i=1; i<sizeof(dirs); i+=2) {
            if(valid_moves)
               valid_moves+=({dirs[i]});
            else
               valid_moves=({dirs[i]});
         }
      }   
      if(!valid_moves) {
         moveable=0;
         remove_call_out("move_me");
         return 1;
      }
      tmp=member_array(valid_moves[random(sizeof(valid_moves))], dirs)-1;
      say(capitalize(name)+" "+msgout+" "+dirs[(tmp+1)]+".\n");
      move_object(this_object(), dirs[tmp]); 
      say(capitalize(name)+" "+msgin+".\n");
   } else {
      moveable=0;
      remove_call_out("move_me");
      return 1;
   }
   call_out("move_me",5);
   return 1;
}

mwrite(str) {
     tell_object(talking_object, str);
}

msay2(str) {
     int i;
     object ob;
     
     ob = first_inventory(environment(talking_object));
     while(ob) {
          if(ob != talking_object) tell_object(ob, str);
          ob = next_inventory(ob);
     }
}

msay_out(str) {
     msay2(format(capitalize(name) + " says: " + str, 75));
}

msay(str, delay) {
     if(!str || !name || !talking_object) return;
     if(!delay) return msay_out(str);
     call_out("msay_out", delay, str);
}

memote_out(str) {
     msay2(format(str, 75));
}

memote(str, delay) {
     if(!str || !name || !talking_object) return;
     if(!delay) return memote_out(str);
     call_out("memote_out", delay, str);
}

other_living(ob) {
     object o;
     
     o = first_inventory(ENVTO);
     while(o) {
          if(o->query_level() && (o != TO) && (o != ob)) return 1;
          o = next_inventory(o);
     }
     return;
}
