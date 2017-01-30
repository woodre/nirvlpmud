inherit "room/room";
object ob, ob1, ob2;
reset(arg) {
  if(arg) return;
  if(arg) return;
    set_light(0);
    short_desc = "Gdemia Cavern";
    long_desc = "You are in the great Gdemia Cavern. It's very dark here"+
                ", so\nyou can lose your way very simple.\n";
    dest_dir = ({"players/beren/Rooms/Gdemia/groom12", "east",
                 "players/beren/Rooms/Gdemia/groom6", "west"});
}
