#define NAME "nooneelse"
#define DEST "room/mine/tunnel_room"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return (str=="castle" || str=="tunnel"); }

is_castle() { return 1; }

short() { return "A side tunnel in the mine"; }

long() {
  write("You see a side tunnel leading to the west.  It 'looks' safe.\n");
  return 1;
}

init() {
  add_action("enter", "west");
}

enter(str) {
  say(this_player()->query_name()+" walks into the side tunnel.\n");
  write("You walk slowly into the side tunnel and emerge in a forest\n"+
        "on the other side of the mountains.\n");
  call_other(this_player(), "move_player",
             "west#players/nooneelse/entryforest/e_forest0");
  return 1;
}

reset(arg) {
  object obj;
  if (arg) {
    call_other("players/nooneelse/workroom", "???");
    find_object("players/nooneelse/workroom")->move_cult_gloves("move");
    return;
  }

/*
  if (!present("bishops_ring", find_object("room/quest_room.c"))) {
    obj=clone_object("obj/quest_obj");
    obj->set_name("bishops_ring");
    obj->set_hint(
         "Destroy the master vampire and return the Bishop's ring.\n"+
         "Listen to Von Helsing.  He may have some idea what weapons\n"+
         "and protections you will need to do the job.\n"+
         "(This is a very dangerous quest.  Bring lots of help.  You're\n"+
         " gonna need it.)\n");
    move_object(obj, "room/quest_room");
  }
*/

  move_object(this_object(), DEST);
}
