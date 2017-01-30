muzzle(str) {
   object target_obj;
   if (!str) return 0;
   if(str)
   {
     write("This has been removed.  Fred.\n");
     return 1;
   }
   target_obj = find_living(str);
   if (!target_obj || target_obj==this_player()) {
      write("You try to muzzle someone that is not here and fail!\n");
      return 0;
   }
   write("You strap a muzzle on "+capitalize(str)+".\n");
if(!present("muzzle",this_player())) 
   move_object(clone_object("players/saber/closed/new_mini/canine_muzzle.c"), target_obj);
   tell_object(target_obj,
      "\n\n"+this_player()->query_name()+
      " muzzles you!\n\n");
   return 1;
}
