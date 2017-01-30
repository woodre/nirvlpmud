inherit "room/room";
 
reset(arg) {
object customer,cooler;
    check_gender(this_player());
    if(arg) return;
    set_light(1);
    long_desc = "This is the women's room, there are several sinks on the\n" +
"wall and a few stalls, there is also a tampon dispenser here.\n";
   short_desc = "Women's room";
    dest_dir = ({ "/players/emerson/rooms/fstall1.c","stall1",
     "/players/emerson/rooms/fstall2.c","stall2",
    "/players/emerson/rooms/fstall3.c","stall3",
      "/players/emerson/rooms/fstall4.c","stall4",
     "/players/emerson/rooms/room5.c","north"});

     customer=clone_object("players/emerson/obj/tdis.c");
     move_object(customer,this_object());
}
check_gender (arg) {
    if(!arg) return;
   if(arg->query_level()>=20 && arg->query_gender()!="female") {
   write(
   "\nYou hear a voice whisper: Psst! You're not suppose to be in\n" +
   "here, but since you're a wizard we'll be nice and let you stay.\n\n");
  return 0;
}
 if (arg->query_gender()!="female") {
   tell_object(arg,
    "Check your genitals! You're not a female!\n");
call_other("/players/emerson/rooms/room5","???");
move_object(arg, "/players/emerson/rooms/room5");
return 1;
}
return 0;
}
