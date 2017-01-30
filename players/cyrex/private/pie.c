inherit "obj/treasure";

string name;

reset(arg) {
   if (arg) return;
    name = "Cream pie";
}

id(str) { return str == "pie"; }
short() {
   return(name);
}
init() {
   add_action("throw", "throw");
}

long() {
   write("A delicious looking fruit pie. Especially useful for throwing at players.\n");
}

get() { return 1; }
query_value() { return 1; }
query_weight() { return 0; }

throw(str) {
   string target;

   if (!str) {
      write("Throw at who?\n");
      return 1;
   }
   target = (find_player(str));
   if (target->query_level() >= 100) {
      write("I wouldn't if I were you....\n");
      return 1;
   }
   if (!target) {
      write("Sorry, that player is not on right now.\n");
      return 1;
   }

   tell_object(target, "SPLAT!!! You are hit on the face by a "+name+". You know it could\n"+
         "only come from "+ this_player()->query_name()+"!\n");
   tell_room(environment(target), target->query_name()+" gets hit on the face by a "+name+".\n");
   destruct(this_object());
   return 1;
}

ren(str) {
   name = str+" pie";
   return 1;
}
