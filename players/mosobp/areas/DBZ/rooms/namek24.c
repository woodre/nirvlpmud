inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
    set_light(1);
    set_short("The Throne room");
    set_long(
      "This is the throne room. As you look around the room you see various anti
quities won in battles by King Vegeta. On one wall you notice a very unusual swo
rd.");
    add_item("sword","The sword on the wall is an exact replica of King Vegeta's
 Z sword that he got for killing the Grand Kai.");
    add_item("wall","The walls hold King Vegeta's most prized possessions.");
    add_item("throne","The chair King Vegeta sits in.");
    add_item("antiquities","Items that King Vegeta won when he was conquering la
nds.");
    add_exit("/players/gohan/namek/namek27.c","south");
    add_object("/players/gohan/learning/Kingvegeta.c");
}
