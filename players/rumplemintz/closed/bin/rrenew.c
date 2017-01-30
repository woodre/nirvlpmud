int rrenew(){
   object staff;
   staff = present("rumpstick", this_player());
   destruct(staff);
   move_object(clone_object("/players/rumplemintz/closed/staff.c"), this_player());
   write("Walking Stick Updated.\n");
   return 1;
}
