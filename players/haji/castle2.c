#define NAME "haji"
#define DEST "room/jetty"
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

id(str) { return str == "land"||str=="path"||str=="haji"||str=="land of wonder"; }

short() {
  return "A path leading north into Haji's Land of Wonder";
}

long() {
    write("This is a path leading north into Haji's Land of Wonder.\n");
}

init() {
      object ob,ob1,test;
/*
     if(!present("wand")) {
        ob=clone_object("players/haji/wand.c");
        move_object(ob,this_object());
        return 1;
      }
    test=find_object("room/quest_room");
       if(!present("grail",test)) {
          ob1=clone_object("obj/quest_obj");
           call_other(ob1,"set_name","grail");
           call_other(ob1,"set_hint","Search out and find the holy grail.\n");
           move_object(ob1,test);
     }
*/
  add_action("enter", "north");
}

enter() {
   call_other(this_player(),"move_player","leaves north #players/haji/e1.c");
    return 1;
}

reset(arg) {
   object ob1;

    if (arg)
	return;
    move_object(this_object(), DEST);
/* quest replaced but kept for quest points - Eurale
   if (!present("grail", find_object("room/quest_room"))) {
      ob1 = clone_object("obj/quest_obj");
      call_other(ob1, "set_name", "grail");
      call_other(ob1, "set_hint", "Search out and find the holy grail.\n");
      move_object(ob1, find_object("room/quest_room"));
   }
*/
/* error in pri.c blocking from loading. -Bp
       call_other("players/haji/closed/pri","set_up");
*/
       call_other("players/rich/castle","???");
}
is_castle() {return 1;}
