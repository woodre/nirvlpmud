#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
a = random(4);
if(a == 0) {
move_object(clone_object(ROOT+"mon/mino_glad.c"),this_object()); }
if(a == 1) {
move_object(clone_object(ROOT+"mon/mino_glad.c"),this_object()); }
if(a == 2) {
move_object(clone_object(ROOT+"mon/mino_glad.c"),this_object()); 
move_object(clone_object(ROOT+"mon/mino_glad.c"),this_object()); }
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Arena Pathway"+NORM+" (west)\n"+
"The old arena within the ancient city of Qual'tor was once a place of\n"+
"festival and fanfare, a great walled monument to the strength of the\n"+
"warriors of the city. Nothing remains now, just the stone archway\n"+
"that used to lead south into the arena itself.\n";

    items=({
"arena","The great walls of the former arena lie in ruins",
"city","The city of Qual'tor lies to the south and west from its former arena",
"stone","The stone of the archway is dark in color",
"archway","The huge stone archway stands silent and alone",
    });

    dest_dir=({
  ROOT+"arena_way3.c","west",
/*
  ROOT+"arena/entry.c","enter",
*/
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_enter","enter");
    }

    search(){
write("You find nothing of interest under the shadow of the archway.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_enter(){
write("The Dark arena is currently under construction.\n   -Dar\n");
return 1;
}

