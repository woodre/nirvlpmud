#include "/players/guilds/shadow/lib/shadsecure.h"
#define BOARD "/players/guilds/shadow/obj/cboard.c"
#define CLERK "/players/guilds/store/clerk.c"
#define STORAGE "/players/guilds/store/storage.c"

inherit"/room/room";

reset(arg) {
   object board;
   if(arg) return;

   short_desc = "Shadow Commanders Room";
   long_desc = 
"You are in the depths are darkness....but yet you can see.Great evils\n"+ 
"have been planned here, many more to come.  This is where the shadows,\n"+ 
"the Lords of Darkness, delve into the arcane world of magic and death.\n"+ 
"May your imagination be your limit...This room is much like the last,\n"+
"with a high arched ceiling and red granite materials around.\n";

   dest_dir = ({"/players/guilds/shadow/rooms/meeting.c","south"});
   if(!present("board", this_object()))  {
      board = clone_object(BOARD);
      if(board) move_object(board, this_object());
   }
   if(!present("clerk", this_object())) {
      move_object(clone_object(CLERK), this_object());
   }
   if(!present("desk", this_object()))
      move_object(clone_object(STORAGE), this_object());

}
init() {
   ::init();
    add_action("look", "look");
    add_action("look", "l");
    add_action("look", "examine");
    add_action("look", "search");
    add_action("look"); add_verb("look");
    add_action("look"); add_verb("l");
    add_action("look"); add_verb("examine");
    add_action("sit","sit");
    filter_room();
}

look(str) {
  if (!str) { return 0; }
  if (str == "at pillar" || str== "at pillars") {
    write("Towering red granite pillars support the ceiling.\n");
    return 1;
  }
  if (str=="at ceiling"||str=="at fine engravings"||str=="engravings"){
    write("The lofty ceiling is crowded with large stone artwork in\n"+
          "shadowy colors depicting gargoyles and creatures of the dark.\n");
    return 1;
  }
  if(str == "at table" || str == "at tables") {
    write("A large, highly polished, black, rectangular table.\n");
    return 1;
  }
  if (str== "at chair" || str=="at chairs") {
    write("Beautiful, hand crafted wood chairs with black leather cusions.\n");
    return 1;
  }
  if (str=="at couch"||str=="at couches"||str=="at sofa"||str=="at sofas"){
    write("Large over stuffed couches with a black leather cusions.\n");
    return 1;
    }
  if(str=="at rug"||str=="at rugs"||str=="at fine rugs"||str=="at floor"){
    write("The dark red rugs cover select areas of the red granite floor.\n");
    return 1;
  }
  return 0;
}
sit(str) {
  string stra;
  if (str!="on chair" && str!="on sofa" && str!="on table" && str!="on couch")
    return 0;
  write("You sit.\n");
  sscanf(str,"on %s",stra);
  tell_room(this_object(),this_player()->query_name()+" sits on a "+stra+".\n");
  return 1;
}


