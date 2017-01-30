inherit "room/room";
object h, h1, h2;

reset(arg) {
  if(arg) return;
    h = clone_object ("players/beren/Monsters/Olgyo/fishman.c");
    move_object (h, this_object());
/*
h1 = clone_object ("players/beren/Monsters/Olgyo/fishman.c");
move_object (h1, this_object ());
h2 = clone_object ("players/beren/Monsters/Olgyo/fishman.c");
move_object (h2, this_object ());
*/
    if (arg) return;

    set_light(1);
    short_desc = "Olgyo Fishman's domain";
    long_desc =
"You are near the beatiful river. The water is very clear and you can see\n"+
"some fish swimming in it. If there is a fish there must be a fishman too.\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom5", "north"});
}
