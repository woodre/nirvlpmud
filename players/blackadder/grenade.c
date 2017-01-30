id(str) { return str == "grenade"; }

reset() {}

long() { write("A hand grenade.\n");
   write("To use it type 'throw grenade at <monster>'.\n");
   write("Be careful!!!!\n");
}

short() { return "A hand grenade"; }

init() {
   add_action("throw","throw");
}

throw(str) {
   string who;
   object env,mnstr;
   
   if (sscanf(str,"grenade at %s",who) != 1) {
      return 0;
   }
   env = first_inventory(environment(this_player()));
   while(env) {
      if (call_other(env,"id",who))
         mnstr = env;
      env = next_inventory(env);
   }
   if (!mnstr) {
      write("at who?\n");
      return 1;
   }
  if(!mnstr->query_npc()) {
   write("You are not allowed to use the grenade at that!\n"); return 1; }
   if (!call_other(this_player(),"valid_attack",mnstr)) {
      write("You are not allowed to attack " + who + ".\n");
      return 1;
   }
   write("You throw a hand grenade at " + who + "!\n");
   say(call_other(this_player(),"query_name") + " throws a grenade at " + who + "!\n");
   tell_room(environment(this_player()),"*** BOOM ***\n");
   call_other(mnstr,"attacked_by",this_player());
   call_other(mnstr,"hit_player",random(50)+10);
   destruct(this_object());
   return 1;
} 

get() { return 1; }

query_weight() {return 1; }
query_save_flag() {return 1; }

query_value() {return 500; }

