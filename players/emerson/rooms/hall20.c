inherit "room/room";
 
reset(arg) {
object customer,cooler;
    check_object(this_player());
    if(arg) return;
    set_light(1);
    long_desc = "A short back hallway\n";
   short_desc = "Back Hall";
    dest_dir = ({ "/players/emerson/rooms/wait.c","north",
    "/players/emerson/rooms/room21.c","south"});

     customer=clone_object("players/emerson/dis.c");
     move_object(customer,this_object());
}
 check_object (arg) {
   if(arg->query_level()>20) {
   write(
   "\nYou hear a voice whisper: Psst! You're not suppose to be in\n" +
   "here, but since you're a wizard we'll be nice and let you stay.\n\n");
  return 0;
}
if (!not present ("ntag",this_player()) {
   tell_object(arg,
    "You're not an employee!!\n");
call_other("/players/emerson/rooms/wait","???");
arg->move("/players/emerson/rooms/wait");
return 1;
}
return 0;
}
