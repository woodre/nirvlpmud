#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
int been_here;

reset(int arg){
been_here = 0;
  if(!arg){
move_object(clone_object("/players/daranath/mons/dark_naga.c"),this_object());
    
    set_light(-1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "Darkness reminescient of the UnderDark presses in all about you\n"+
      "as you stay within this small cave. Rough walls rise up on three\n"+ 
      "sides of you, blocking any further progress into the mountainside.\n"+
      "The cave mouth opens to the south of here.\n";

    items=({
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "walls", "The rocky walls are typical for this area",
      "mouth", "The entrance of the cave serves as the exits as well",
      "darkness", "The darkness engulfs everything within this small cave",
    });

    dest_dir=({
      "/players/daranath/clearing/mtrail7.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search(){
object KEY;
 if(been_here < 1) {
 write("You find a small steel key!\n");
 say(tp+" searches the area.\n");
KEY=clone_object("/players/daranath/items/key_steel.c");
  move_object(KEY, this_player());
been_here=been_here + 1;
return 1;
}
write("You find nothing about the darkened cave.\n");
say (tp +" searches the area.\n");
return 1;  }


