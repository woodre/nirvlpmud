inherit "room/room";
reset(arg) {
object h;
if(!present("pedane", this_object())) {
h = clone_object ("players/beren/Monsters/Olgyo/pedane.c");
move_object (h, this_object ());
}
if(arg) return;

    set_light(1);
    short_desc = "Village of Zgama";
    long_desc =
"You can see a great fire in this room. There is a man standing\n"+
"in it's center and you don't believe your eyes! Fire cause no\n"+
"harm to him! You hear some Olgyo women voices: Pedane! Pedane!\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom15", "east"});

}
