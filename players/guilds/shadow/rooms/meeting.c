inherit"/room/room.c";
#include "/players/guilds/shadow/lib/shadsecure.h"

reset(arg) {
  if(arg) return;
/*   set_heart_beat(1); */
  set_light(0);
  short_desc = "The Shadow Meeting Room";
long_desc = "Your eyes quickly adjust to the dark lighting...\n"+
  "You are in a large room, with a high gothic ceiling arching far over\n"+
  "head. Everything is made of a deep red granite, with fine engravings\n"+
  "detailing beautiful people and objects.  The floors are covered with\n"+
  "fine rugs, and couches are placed generously throughout the room.\n"+
  "There is a dark black passageway to the north.\n";

  dest_dir = ({
      "/players/catwoman/tl", "lockers",
      "/players/guilds/shadow/rooms/advance.c","west",
      "/players/guilds/shadow/rooms/east.c","east",
      "/room/plane2", "leave",
      "/room/church","church"
});
      move_object(clone_object("/players/guilds/shadow/obj/board"),
      this_object());
}

heart_beat() {
   filter_room();
}

init() {
   ::init();
   add_action("move_north","north");
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

move_north(str) {
   object mark;
   if(str) return;
   mark = present("shadow-mark",TP);
   if(mark->query_shlevel() < 13) {
      write("The darkness does not allow you to pass.\n");
      write("That room is only for the commanders.\n");
      return 1;
   }
   TP->move_player("north#players/guilds/shadow/rooms/comm_room.c");
   return 1;
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

