#include "/players/beck/esc.h"
#include "/players/beck/rangers/Defs.h"

id(str) { return str=="gold's gym" || str=="gym"; }
reset () {}
short() {
   return ""+YELLOW+"Gold's Gym"+OFF+"";
}
long() {
   write("Enter gym to workout.\n"+
      ""+BOLD+RED+"MEMBERS ONLY"+OFF+"\n"+
"");
}
init() {
   add_action("enter","enter");
}
get() {
   tell_object(this_player(), "There's no way you can pick up a building.\n");
   return 0;
}
enter(arg) {
if(TP->query_guild_name() != "rangers" && TP->query_guild_name() != "dark rangers"){
write("Only Power Rangers can use Gold's Gym.\n");
      return 1;
   }
   if(!arg){ write("Where do you want to enter?\n"); return 1;}
   if(arg != "gym"){
      write("You can only enter the gym.\n");
      return 1;
   }
   call_other(this_player(),"move_player","enter#/players/beck/room/golds_gym.c");
   return 1;
}
query_weight() { return 0; }
query_value() { return 5000; }
apply(str) {
   object membership;
write("Sorry...can't join anymore.\n");
return 1;
   if(str=="for membership") {
      if(!present("gym_membership", this_player())){
         if(!restore_object("players/beck/save/golds_gym/"+this_player()->query_real_name())){
            if(this_player()->query_money() < 40000) {
               write("You don't have enough gold coins!\n");
               return 1;
            }
            this_player()->add_money(-40000);
            membership = clone_object("/players/beck/object/golds_gym_member.c");
            move_object(membership, this_player());
            membership->set_stat("strength",1);
            membership->set_stat("speed",1);
            membership->set_stat("endurance",1);
            membership->save_membership();
            write("Congatulations!  You are now a member of Golds Gym.\n");
            return 1;
         }
         write("A new membership will be issued for free.\n");
         move_object(clone_object("/players/beck/object/golds_gym_member.c"), this_player());
         present("gym_membership", this_player())->restore_membership();
         return 1;
      }
      write("You are already a member.\n");
      return 1;
   }
   write("What do you want to apply for?\n");
   return 1;
}
