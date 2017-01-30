inherit "room/room";
 
reset(arg) {
object customer,cooler;
    check_gender(this_player());
    if(arg) return;
    set_light(1);
    long_desc = "This is the men's room, there are several urnals on the\n" +
"wall and a few stalls, there is also a condom dispenser here.\n";
   short_desc = "Men's room";
    dest_dir = ({ "/players/emerson/rooms/mstall1.c","stall1",
     "/players/emerson/rooms/mstall2.c","stall2",
     "/players/emerson/rooms/mstall3.c","stall3",
      "/players/emerson/rooms/mstall4.c","stall4",
     "/players/emerson/rooms/room5.c","south"});

     customer=clone_object("players/emerson/obj/dis.c");
     move_object(customer,this_object());
}
check_gender (arg) {
    if(!arg) return;
   if(arg->query_level()>=20 && arg->query_gender()!="male") {
   write(
   "\nYou hear a voice whisper: Psst! You're not suppose to be in\n" +
   "here, but since you're a wizard we'll be nice and let you stay.\n\n");
  return 0;
}
 if (arg->query_gender()!="male") {
   tell_object(arg,
    "Check your genitals! You're not a male!\n");
call_other("/players/emerson/rooms/room5","???");
move_object(arg, "/players/emerson/rooms/room5");
return 1;
}
return 0;
}
