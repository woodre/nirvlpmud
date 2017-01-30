trans(str) {   /* transport a player to a specified destination */
object target;
object destination;
string tname, whereto;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %s",tname,whereto)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) {
      write("Could not find "+tname+"\n");
      return 1;
   }
   if(whereto == "back") {
      if(target != summoned_object) {
      write("The target was not the last one summoned.\n");
      return 1;
      }
      move_object(target,summoned_origin);
      return 1;
   }
   if(whereto == "here") {
      say(capitalize(target->query_name()) + " suddenly vanishes"+
         " into thin air.\n", target);
      summoned_origin = environment(target);
      summoned_object = target;
     move_object(target,environment(this_player()));
      call_other(target, "command", "look");
      tell_object(target, "*POOF* Your surroundings have changed....\n");
      return 1;
   }
   destination = valid_read(whereto);
   if(!destination) {
      write("Cannot find "+whereto+"\n");
      return 1;
   }
   move_object(target,destination);
    return 1;
}
