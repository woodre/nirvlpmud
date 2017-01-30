#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/fire_mephit.c"),this_object());
move_object(clone_object(ROOT+"mon/fire_mephit.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Ruined"+RED+" Pyromancer "+BOLD+BLK+"Guildhall"+NORM);
long_desc=
"The former guildhall has completly collapsed upon itself, the upper levels of\n"+
"the building having fallen over and landed outside the tower's base. Charred\n"+
"and twisted wooden beams are everywhere, evidence of a large magical\n"+
"explosion that took place decades ago. The floor has also caved in, making\n"+
"decending into the underground levels impossible.\n";

items=({
"clearing","This clearing was probably made by a magical battle, given the destruction\n"+
     "that is all around you",
"stumps","Blackened stumps of trees that were blown away during the magical battle are everywhere",
"plateau","The plateau rises up, looming overhead. A small trail starts up to the south",
"rocks","The rock in the area is sorched by magical flames",
"tower","The tower has fallen upon its side, another casualty of the magical\n"+
     "warfare that rocked Gundar years ago. You believe you can enter\n"+
     "the tower's remains",
    });

    dest_dir=({
  ROOT+"north_stop.c","exit",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The wood and stone within the ruins is blackened and heavily sorched.\n");
  say(tp +" searches the ruins.\n");
 return 1;
}

realm() {return "NT"; }
