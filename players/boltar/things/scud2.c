

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
   shout ("You see a SCUD missile fly accross the sky.\n");
   tell_object (target, "You see a SCUD missile heading towards you, however it misses by about 1 mile.\n");
   tell_object (target, "The SCUD came from "+call_other(this_player(), "query_real_name", 0));
   tell_object (target, "\n");
    shout ("There is a loud explosion, a SCUD has landed.\n");
    destruct (this_object());
     return 1;

}

get() {
    return 1;
}
