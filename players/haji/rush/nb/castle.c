#define NAME "haji"
#define DEST "room/orc_dump"
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

id(str) { return str == "road"||str=="path"||str=="haji"||str=="land of wonder"; }

short() {
  return "A road which leads southwest to a run down base from poor funding";
}

long() {
    write("The road to the southwest leads to a run down military base.\n");
    write("This is due to poor funding we are trying to fix this ASAP.\n");
}

init() {
      add_action("enter","southwest");
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
}

enter() {
   call_other(this_player(),"move_player","leaves south #players/haji/rush/nb/ent.c");
    return 1;
}

reset(arg) {
   object ob1;

    if (arg)
	return;
    move_object(this_object(), DEST);
   if (!present("grail", find_object("room/quest_room"))) {
      ob1 = clone_object("obj/quest_obj");
      call_other(ob1, "set_name", "grail");
      call_other(ob1, "set_hint", "Search out and find the holy grail.\n");
      move_object(ob1, find_object("room/quest_room"));
   }
/* modified 3/1/97 by wizardchild 
       call_other("players/haji/closed/pri","set_up");
       call_other("players/rich/castle","???");
*/
if(!find_object("/players/haji/tx/castle.c"))
  call_other("/players/haji/tx/castle","id","a");
}
is_castle() {return 1;}
