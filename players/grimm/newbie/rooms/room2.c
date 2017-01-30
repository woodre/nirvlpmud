inherit "room/room";
object dude;
reset(arg) {
  monster();  /* Moved this up here - Rumplemintz */
    if (arg) return;
/* Instead of here
    monster();
*/
    set_light(1);
    short_desc = "A killing hallway";
    long_desc = 
        "A hallway in the killing grounds.\n";
    dest_dir = 
        ({
         "players/grimm/newbie/rooms/room3","east",
         "players/grimm/newbie/rooms/room9","south",
       });
}

monster() {
  dude=clone_object("players/grimm/newbie/monsters/elf1");
  move_object(dude,this_object());
  return 1;
}
