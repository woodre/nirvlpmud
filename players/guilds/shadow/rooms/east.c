inherit"room/room";
#include "/players/guilds/shadow/lib/shadsecure.h"

reset(arg) {
   if(!arg) {
  
   short_desc = "East Room";
   long_desc = 
   "You are in a medium sized room, with a deep burgundy carpet and several\n"+
   "comfortable couches.  There is a lot of floor space here, so it could\n"+
   "be a good place to drop any extra equitment you have so that other\n"+
   "shadows could use it. The rest of the room matches well with the\n"+
   "the meeting room.\n";
   dest_dir = ({"/players/guilds/shadow/rooms/meeting.c","west"});
   }
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
    write("Beautiful, hand crafted wood chairs with black leather cushions.\n");
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

