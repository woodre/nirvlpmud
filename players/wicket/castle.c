#define NAME "Wicket"
#define DEST "room/south/sforst18"

#if 1 /* 0 to disable quest, 1 to enable - Rumplemintz */
#define NINJA_TURTLE_QUEST
#endif

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

id(str) { return str == "tv" || str == "television" || str== "set"; }

short() { return "A Television Set"; }

long() {
  write("This is the small televison set with a knob to turn the channel to\n");
  write("An antennae sticks out of the top of the televison and it seems to\n");
  write("be powered by some unkown source. Why not ENTER the TV.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
  if(!str){
    write("What would you like to enter?\n");
    return 1;
  }
  if(str != "tv" && str != "set" && str != "television"){
    write("You can only enter the tv.\n");
    return 1;
  }
  write("You are sucked into the television!\n");
  say(this_player()->query_name() + " gets sucked into the television\n");
  this_player()->move_player("into the television#players/wicket/" +
                                                  "wicketentrance.c");
  return 1;
}

reset(arg) {
#ifdef NINJA_TURTLE_QUEST /* Rumplemintz */
  object qob, elementalists;

  if (!present("ninja_turtles", find_object("room/quest_room.c"))) {
    qob = clone_object("obj/quest_obj");
    qob->set_name("ninja_turtles");
    qob->set_hint("The Pizza Hut Manager is having issues with her service.\n"+
                  "Inquire to see if you can help.\n");
    move_object(qob, "room/quest_room");
  }
#endif
    if (arg)
	return;
    move_object(this_object(), DEST);
    
    elementalists = clone_object("/players/wicket/guild/gob.c");
    move_object(elementalists, this_object());
    destruct(elementalists);
}
is_castle(){return 1;}
