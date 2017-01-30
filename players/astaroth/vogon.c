inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "You see the Vogons looming overhead";
  long_desc = 
   "This is the same path you used to get to the pub, but something \n"+
   "has changed - there is a Vogon constructor fleet looming over your \n"+
   "head.  The planet is in trouble now.\n";
  dest_dir = ({"players/astaroth/pubfront", "west",
               "players/astaroth/tractor", "east"});
  }
}
 
hitchhike() {
object x, place, next_x;
 
   x = first_inventory(this_object());
   while (x) {
      next_x = next_inventory(x);
      move_object(x,"players/astaroth/hhg/hold");
      x = next_x;
   }
   call_other("players/astaroth/hhg/hold","telesay");
   return 1;
}
 
telesay() {
   tell_room(this_object(),"Forms shimmer out of existance.\n");
   return 1;
}
