/* path2.c: continuing pathway */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
object me;
reset(arg) {
  if(arg)
    return ;
  short_desc = "A dark pathway";
  long_desc  = "The looming trees prevent only but the slightest amount of light from shining on\n"
              +"the pathway. Staring around, you have trouble finding the path, or any other\n"
              +"nearby paths, for that matter. A cold chill, probably from the darkness, begins\n"
              +"to eat away at your strength.\n"
              +"A faint light can be seen to the west.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path1", "east",
    ROOT_DIR+"rooms/forest2", "northwest",
    ROOT_DIR+"rooms/path3", "west"
  });
  objects    =
  ({
    ROOT_DIR+"mons/shadow"
  });
  load_room();
}
init() {
  ::init();
  me = this_player();
  call_out("loose_sta", 6);
}
loose_sta() {
  if(me)
  {
  if(environment(me) != this_object())
    return (me = 0);
  tell_object(me, "The cold eats away at your strength.\n");
  me->add_hit_point(-5);
  return 1;
 }
}
