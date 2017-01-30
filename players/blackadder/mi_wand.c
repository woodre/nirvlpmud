int charges;
id(str) { return str == "wand" || str == "blackwand1"; }
reset() {}
long() { write("A magic wand.\n");
   write("To use it type wave wand <monster name>.\n");
}
short() { return "A magic wand"; }
init() {
   add_action("wave","wave");
}
set_charge(c) {
    charges = c;
    return;
}
wave(str) {
   string who;
   object env,mnstr;
   
   if (str == "wand") {
      mnstr = call_other(this_player(),"query_attack");
      if (!mnstr) {
         write("You are not attacking anyone right now.\n");
         return 1;
      }
who = call_other(mnstr,"query_name");
   }
   if (str != "wand") {
      if (sscanf(str,"wand %s",who) != 1)
         return 0;
      env = first_inventory(environment(this_player()));
      while(env) {
         if (call_other(env,"id",who))
            mnstr = env;
         env = next_inventory(env);
      }
   }
   if (!mnstr) {
      write("That is not a valid target.\n");
      return 1;
   }
    if(!mnstr->query_npc()) { write("You may not attack that.\n"); return 1; }
   if (!call_other(this_player(),"valid_attack",mnstr)) {
      write("You are not allowed to attack " + who + ".\n");
      return 1;
   }
   if (charges == 0) {
      write ("The wand has ceased to function.\n");
      return 1;
   }
   write("The wand casts a magic missile at " + who + "!\n");
   say(call_other(this_player(),"query_name") + " waves a magic wand at " + who + "!\n");
   tell_room(environment(this_player()),"Sparks fly from the wand and hit the target.\n");
   call_other(mnstr,"attacked_by",this_player());
   call_other(mnstr,"hit_player",random(20));
   charges -= 1;
   return 1;
} 
get() { return 1; }
query_weight() {return 1; }
query_value() {return (charges*40) + 50; }
