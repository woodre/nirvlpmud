
#include "/obj/user/junk_only.c"
object load;

short()
{
     return "A SCUD missile";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
  write("One of those very poorly made SCUD missiles.\n");
}

init() {
     add_action("launch", "launch");
     add_action("fire", "fire");
     add_action("chem", "chem");
     add_action("load", "scudload");
}

id(str) {
    return str == "SCUD" || str == "missile";
}

launch(str) {
   object target;
       if (!str) {
         write("no target entered.\n");
         return 1;
         }
   target = find_living(str);
   if (!target) {
     write("The SCUD's radar cannot find the target.\n");
     return 1;
     }
   write ("The SCUD lifts off towards its target.\n");
   chan_msg ("You see a SCUD missile fly accross the sky.\n");
    if(load) {
   chan_msg(load->short() + " separates from the SCUD.\n");
   tell_object(target, load->short() + " leaves the SCUD and falls on your head.\n");
   tell_room(environment(target), load->short()+" falls on "+target->query_name()+"'s head.\n");
   move_object(load,environment(target));
  load = 0;
}
   tell_object (target, "The SCUD missile heads towards you, however it misses by about 1 mile.\n");
    chan_msg ("There is a loud explosion, a SCUD has landed.\n");
    destruct (this_object());
     return 1;

}

get() {
    return 1;
}
fire() {
   chan_msg("A SCUD missile flys through the sky.\n");
   chan_msg("There is a streak of light and large explosion.\n");
   chan_msg("A patriot missile has shot down the incoming SCUD.\n");
   write("SCUD fired.\n");
   destruct(this_object());
 return 1;
 }
chem(str) {
    object targ;
   if (!str) {
      write("no target!!!\n");
   return 1;
    }
   targ = find_living(str);
   if (!targ){ 
    write("cannot find target.\n");
     return 1;
     }
    tell_object(targ, "A SCUD missile lands near you and the chemical warfare warhead \n explodes\n");
       tell_object(targ,"That poison gas hurts!\n");
        call_other(targ, "add_hit_point", -2);
       write("SCUD missile fired with Chemical Warhead.\n");
        destruct(this_object());
        return 1;
   }
load(str) {
if(load) {write("The SCUD is loaded.\n"); return 1;}
if(!present(str,this_player())) return 0;
load=present(str,this_player());
write("You load the scud missile.\n");
tell_room(environment(this_player()), this_player()->query_name()+" loads a SCUD missile with a "+str+"\n");
move_object(load,this_object());
return 1;
}
