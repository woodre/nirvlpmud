inherit "obj/treasure";

#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/caves/NEWCAVES/"

#ifdef 0
void reset(status arg){
   if(arg) return;
#endif
void reset() {
   set_id("dpath");
   call_out("removeme",60);
}

void init(){
   add_action("down","d");
   add_action("down","down");
}

int down(){
   object newroom;
   newroom = clone_object(PATH+"virt_room.c");
   newroom -> add_exit("/room/south/sforst45","up");
   newroom -> add_exit("","north");
   newroom -> add_exit("","south");
   newroom -> add_exit("","east");
   newroom -> add_exit("","west");
   newroom -> set_direxit("north");
   newroom -> set_direxit("south");
   newroom -> set_direxit("east");
   newroom -> set_direxit("west");
   newroom -> set_long(""+
      MAG+"    The walls are covered in a slimy mucus which gives off a soft \n"+
      "violet grow.  The light casts shadows against the rocky surface\n"+
      "giving refuge for the dark loving plants who grow in abundance here.\n"+
      "Loose rocks accumulate in the corners of the cavern, knocked off from\n"+
      "the walls.  A small shaft of light beams down from a hole in the \n"+
      "ceiling giving access to the outside.\n"+NORM);
   newroom -> add_item("hole", "A hole in the ceiling giving an exit to the outside world");
   newroom -> add_item("ceiling", "Looking much like the walls except with a small hole in it");
   this_player()->move_player("down#"+file_name(newroom));
   return 1;
}

status removeme(){
   if(!environment(this_object())){
      destruct(this_object());
      return 1;
   }
   tell_room(environment(this_object()),"The passageway down closes.\n");
   destruct(this_object());
   return 1;
}
