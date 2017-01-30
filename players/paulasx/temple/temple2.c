inherit "room/room";
reset(arg) {
  if (!arg){
    set_light(1);
    short_desc = "Entrance hallway in the Temple of Bishamon";
    long_desc = 
        "This hallway is longer than you thought.. however, the figures in \n" +
        "the darkness ahead are definitely coming closer.  Maybe you should\n" +
        "turn back now.  Evil can always be fought another day, why do you\n" +
        "want to risk your life just for a little peace?\n\n";
    dest_dir = 
        ({
        "players/paulasx/temple/temple_warning.c" ,"north",
        "players/paulasx/temple/temple1.c", "south",
        });
  }
}
