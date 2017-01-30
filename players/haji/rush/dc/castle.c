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

id(str) { return str == "road"||str=="path"||str=="haji"||str=="road of wonder"; }

short() {
  return "An extremely run down road which gives you a feeling of great despair";
}

long() {
    write("The road to the south leads south to Washington D.C.,\n");
    write("which is home to the worst thing that ever happened to the U.S., Bill Clinton.\n");
    write("The roads are closed to this city in an effort by\n");
    write("liberals to block your views from coming across in any\n");
    write("way.  We will remedy this as soon as possible.\n");
}

init() {
/* 3/1/97 modified by wizardchild to cause less runtimes */
   object ob; 
      if(!find_object("/players/haji/rush/nb/castle"))
       call_other("/players/haji/rush/nb/castle", "id", "a");
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
    add_action("enter","south");
*/
}

enter() {
   call_other(this_player(),"move_player","leaves south #players/haji/e1.c");
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
/* removed by wizardchild 3/1/97
       call_other("players/haji/closed/pri","set_up");
       call_other("players/rich/castle","???");
*/
}
is_castle() {return 1;}
