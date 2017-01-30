#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/mons/earth_ele.c"),this_object());
 if(!arg){

  set_light(1);
  short_desc="Wizard's Entrance";
  long_desc=
   "A smokey scent fills the air as you come to the end of this tunnel.\n"+
   "The tunnel has been cleaned out and is rather well kept, with a pair\n"+
   "of torches mounted on the southern wall. The most striking feature of\n"+
   "this area, however, is the large set of iron double doors set into\n"+
   "the wall between the torches. A small brass plaque is mounted above\n"+
   "the doors. The tunnels run from here to the east.\n";

items=({
 "doors", "The large iron set of doors leads southwards into the\n"+
           "unknown, a small brass plaque is set in the wall above them",
 "plaque", "The small brass plaque has an inscription set into it.\n"+
           "Perhaps you could "+HIY+"<"+NORM+"read"+HIY+">"+NORM+" the plaque",
 "torches", "The torches are mounted here on the wall, burning smokily\n"+
             "and giving off a faint light",
 "torch", "Each torch is set into an iron sconce",
 "wall", "The southern wall has the large double doors set into it",
 "tunnel", "The tunnel has been cleaned out in this area",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/g,8.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("read","read");
  add_action("enter","enter");
}

search() {
write("You find nothing amongst the dirt.\n");
say (tp +" searches the area\n");
 return 1;
}

read() {
write("The plaque reads: "+HIY+"<"+NORM+"enter"+HIY+">"+NORM+" if you dare.\n");
say (tp +" reads the plaque\n");
 return 1;
}

enter() {
  if(!present("elemental",this_object())) {
this_player()->move_player("into the wizard's domain#/players/daranath/underdark/level1/wiz_entry.c");
  return 1;
  }
  if(present("elemental"));  {
write("The elemental bars your way!!!\n");
say(tp +"tries to open the doors, but the elemental stands in the way.\n");
  return 1;
  }
}

arate() { return "YES"; }
