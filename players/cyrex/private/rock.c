id(str) { return str == "rock"; }

short() { return "a hard rock"; }

long() {
   write("This is a rock. It looks hard. You can throw it.\n");
   write("Usage is 'throw at <target>'.\n");
   return 1; }

drop() { return 1; }

get() { return 1; }

init() {
   add_action("throw", "throw");
}

throw(str) {
   string vict;
   object target;
   if(!str) {
      write("Who do you want to throw the rock at?\n");
      return 1; }
   sscanf(str, "at %s", vict);
   if(sscanf(str, "at %s", vict) != 1) { return 0; }
   target=find_living(lower_case(vict));
   if(!target || !living(target)) {
      write("That target not here.\n");
      return 1; }
   target->add_hit_point(-5);
   this_player()->add_spell_point(-10);
   tell_object(target, "You are hit by a rock thrown by "+
      capitalize(this_player()->query_real_name())+".\n\n");
   write("You throw the rock at "+capitalize(vict)+".\n");
   destruct(this_object());
   return 1;
}

query_value() { return 10; }

query_weight() { return 2; }
