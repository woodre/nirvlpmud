inherit "obj/monster.c";
   init() {
    add_action("enter", "enter");
    add_action("leave", "leave");
     ::init();
      add_object();
add_action("z", "z");
add_action("s","s");
 add_action("see","see");
      }
   reset(arg) {
     ::reset(0);
         set_name("range rover");
       set_wc(0);
       set_hp(9990);
       set_ac(999);
       set_alias("rover");
       set_level(10);
     }
catch_tell(str) {
   object rider;
       rider=first_inventory(this_object());
   tell_object(rider, str);

     return 1;
     }
z(str) {
    call_other(this_object(), "init_command", str);
    if (str == "east" || str == "west" || str == "north" || str == "south" || str == "up" || str == "down") {
   see();
}
 return 1;
}
short() {
  init();
   return "A dark green range rover";
  }
see() {
   object where;
   where = environment(this_object());
   call_other(where, "long", 0);
   return 1;
}
s(str){
   say("The range rover broadcasts: " + str + "\n");
   tell_object(this_player(), "rover says: " + str + "\n");
  return 1;
}
add_object() {
    object fill;
if(!present("button")) {
   fill = clone_object("players/boltar/things/button");
   move_object(fill, this_object());
}
  return 1;
}
enter(str) {
   string name;
  if (str !="rover") {
   return 1;
   }
  move_object(this_player(), this_object());
  name = call_other(this_player(), "query_name", 0);
  say(name + " enters the range rover.\n");
  return 1;
}
leave() {
 move_object(this_player(), environment(this_object()));
  say(call_other(this_player(), "query_name", 0)+ " leaves the range rover.\n");
  return 1;
  }
long() {
  write("The inside of the range rover.\n");
 }
