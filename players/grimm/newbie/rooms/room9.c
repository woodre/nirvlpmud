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
         "players/grimm/newbie/rooms/room2","north",
         "players/grimm/newbie/rooms/room10","south"
       });
}

monster() {
  dude=clone_object("players/grimm/newbie/monsters/orc_s");
  move_object(dude,this_object());
  return 1;
}
