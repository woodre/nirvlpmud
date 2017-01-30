/* forest1.c: inside the dark forest */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
object me;
reset(arg) {
  if(arg)
    return ;
  short_desc = "The middle of a dark forest";
  long_desc  = "As your eyes slowly adjust to your new, dark environment, you notice how\n"
              +"unstable the ground is beneath your feet. As you attempt to stand up, your feet\n"
              +"begin to slip on the wet roots and break through the branches, slicing your\n"
              +"legs. To make matters worse, you notice that the ground sinks into a nearby pit.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path1", "south"
  });
  load_room();
}
init() {
  ::init();
  me = this_player();
  call_out("fall_down", 6);
}
fall_down() {
  if(!me) return;
  if(environment(me) != this_object())
    return (me = 0);
  tell_object(me,"You finally can hold your footing no longer, and fall down into the pit.\n");
  say(me->query_name()+" slips and falls into the pit.\n", me);
  me->move_player("into the pit#players/wizardchild/darkwood/rooms/pitentry");
  me = 0;
  return 1;
}
