inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Deep Forest)");
    long_desc=
"Darkness overwhelms you as you walk about the evil forest known only as\n"+
"the DarkenWood. The trees are sparse here, giving way to a small gateway made\n"+
"from marble stone and iron. A wall extends both east and west, making the \n"+
"iron gate the only way to continue southwards.\n";

items=({
"gate","A large iron gateway sits in the wall, allowing further passage south",
"gateway","A large iron gateway sits in the wall, allowing further passage south",
"wall","The marble wall is dirty and unkempt, yet intact",
"trees","The trees are sparse here, having been cut to make room for the wall",
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
  "shadows", "The shadows move as the wind moves the trees.\n",
  "floor", "The forest floor is covered with a thick layer of leaves and\n"+
           "other such debris",
 });


dest_dir=({
 "/players/daranath/clearing/dwood4.c","north",
 "/players/daranath/magus/rooms/entry.c","south",
 "/players/daranath/clearing/dwood14.c","east",
 "/players/daranath/clearing/dwood16.c","west",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
  add_action("dar_south","south");
}

search() {
write("The iron gateway is old and rusty.\n");
say (tp +" searches the area.\n");
  return 1;
}

dar_south() {
write("The iron gate has rusted shut over the years, not allowing anyone to\n"+
      "continue southwards torwards what looks to be a tower.\n");
return 1;
}

