inherit "/obj/monster";
object ob;

object armor;
int sequencer;

init(arg) {
  add_action("open", "open");
}

open(arg) {
  write("You hack the chest open and treasure spills out!\n");
  say(this_player()->query_name() + " hacks open a chest.\n");
  destruct(this_object());
  return(1);
}
long(arg) {
     write("This is a deep, mehogany chest, with a lock on one side, ... you think\n"+
              "that you could open it up with one slice of your sword.\n");
}

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "chest" );
     set_alias("box");
     set_short("A large, wooden chest");
     set_level(1);
     set_ac(0);
     set_wc(0);
     set_hp(1);
     set_al(0);
     set_aggressive(0);
   }
}

load(str)
{
  ob = clone_object(str);
  move_object(ob, this_object());
}
