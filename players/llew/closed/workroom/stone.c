#include "/players/llew/closed/ansi.h"
string *allowed;
int shield;

reset(arg) {
   if(arg) return;
   allowed= ({"llew","llywelyn"});
   restore_object("players/llew/closed/workroom/stone");
   shield=0;
}

id(str) {
   return str == "stone" || str == "shieldstone";
}

long() {
   write("A small gray stone, seemingly insignificant, rests\n");
   write("gently in a bed of green grass.\n");
   if(this_player()->query_real_name() == "llew") {
      write("The rock shield is set to "+shield+"\n");
      write("Currently allowed are: "+implode(allowed,", ")+"\n");
   }
}

short() {
   return "A small gray stone";
   check_shield();
}

init() {
   add_action("shield_on","on");
   add_action("shield_on","off");
   add_action("member","add");
   add_action("member","sub");
   add_action("sweep","");
   check_shield();
   sweep();
}

check_shield() {
   if(!shield) return;
   if(member_array(this_player()->query_real_name(),allowed) == -1 &&
      member_array(this_player(),deep_inventory(environment())) > -1) {
      write(HIB+"A blue arc of lighnting crashes from the stone, knocking you across the mud.\n"+NORM);
      this_player()->move_player("off the shield#room/church");
   }
}

static shield_on() {
   if(this_player()->query_real_name() != "llew") return 0;
   if(query_verb() == "on") {
      shield=1;
/*
*/
      sweep();
   }
   else shield=0;
   write("Shield set to "+shield+"\n");
   return 1;
}

static member(str) {
   if(this_player()->query_real_name() != "llew") return 0;
   if(!str) {
      write("Add or sub who?\n");
   }
   else if(query_verb() == "add") {
      allowed+= ({str});
      write(capitalize(str)+" was added.\n");
   }
   else {
      if(member_array(str,allowed) > -1) {
         allowed -= ({str});
         write(capitalize(str)+" was removed.\n");
      }
      else {
         write(capitalize(str)+" was not allowed.\n");
      }
   }
   save_object("players/llew/closed/workroom/stone");
   return 1;
}

get() { return 1; }

sweep() {
   if(!shield) return;
   if(environment()) {
      object sweepinv;
      int sweepcount;
      sweepcount=0;
      move_object(this_object(),first_inventory("players/llew/workroom"));
      sweepinv=all_inventory("/players/llew/workroom");
      for(;sweepcount<sizeof(sweepinv);sweepcount++) {
         string fn,junk;
         sscanf(file_name(sweepinv[sweepcount]),"%s#%s",fn,junk);
         if(fn != "players/llew/closed/workroom/stone" ||
            fn != "players/saber/closed/bards/pool" ||
            member_array(sweepinv[sweepcount]->query_real_name(),allowed) == -1) {
            if(living(sweepinv[sweepcount])) {
               move_object(sweepinv[sweepcount],"room/church");
            }
            else destruct(sweepinv[sweepcount]);
         }
      }
   }
   return 0;
}
