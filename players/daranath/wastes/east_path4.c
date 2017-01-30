#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/croaker.c"),this_object());
move_object(clone_object(ROOT+"mon/croaker.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"Finally having cleared the huge boulder that blocked its origonal path, the \n"+
"roadway turns back torwards the mountain to the east. The mountain itself is\n"+
"clearly a plateau from this viewpoint, making an excellent place for both\n"+
"people and/or monsters to live.\n";

items=({
"boulder","The boulder is finally behind you, slightly to the north",
"road","The road leads east up to the plateau",
"roadway","The roadway leads east up to the plateau",
"mountain","Now that you have gotten closer to the mountain, you can clearly see\n"+
     "that it is actually a plateau, sitting here within the Gundar Wastes",
"plateau","The plateau would make an excellent place to build a fortress or castle",
    });

    dest_dir=({
  ROOT+"east_path3.c","north",
  ROOT+"east_path5.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("There seems to be an abundance of footprints and tracks crossing the road.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
