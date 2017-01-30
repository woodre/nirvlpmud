inherit "room/room";
object ob, ob1, ob2;
reset(arg) {
  if(arg) return;
    ob = clone_object ("players/beren/Monsters/Gdemia/miner.c");
    move_object (ob, this_object ());
  if(arg) return;
    set_light(0);
    short_desc = "Gdemia Cavern";
    long_desc = "You are in the great Gdemia Cavern. It's very dark here"+
                ", so\nyou can lose your way very simple.\n";
    dest_dir = ({"players/beren/Rooms/Gdemia/groom17", "east"});
}
