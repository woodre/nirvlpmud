inherit "room/room";

reset(arg) {
  if (arg) return;
  short_desc = "A room";
  long_desc = "The guild is closed. Go up to get to the church.\n";
  dest_dir = ({ "room/church", "up" });
  set_light(1);
}
