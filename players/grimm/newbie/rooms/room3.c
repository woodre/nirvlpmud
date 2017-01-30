inherit "room/room";
object dude;
reset(arg) {
    if (arg) return;
    monster();
    set_light(1);
    short_desc = "A killing hallway";
    long_desc = 
        "A hallway in the killing grounds.\n";
    dest_dir = 
        ({
         "players/grimm/newbie/rooms/room1","north",
         "players/grimm/newbie/rooms/room4","east",
         "players/grimm/newbie/rooms/room2","west"
       });
}

monster() {
    dude=clone_object("players/grimm/newbie/monsters/gnome");
    move_object(dude,this_object());
  return 1;
}
