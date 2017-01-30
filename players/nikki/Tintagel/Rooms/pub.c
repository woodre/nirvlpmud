#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!present("gargoyle")) {
     move_object(clone_object("/players/nikki/Tintagel/Mobs/shopmob.c"),this_object());
   if(arg) return;
   
set_light(1);
short_desc = HIB+"_"+HIG+"Athanasius' Tavern"+HIB+"_"+NORM;
long_desc = HIB+
 "   A wave of warmth escapes the entrance from this darkly lit commoner\n"+
 "pub.  The mumbling of whispered conversations buzz around the room.\n"+
 "The smell of spiced ale and soured alcohol waft through the air.  The\n"+
 "bartender seems to be keeping a constant eye on the clientel of his\n"+
 "establishment.\n"+NORM; 

items = ({
  "entrance",HIB+"The entrance is small and you will have to watch your head"+NORM,
  "room",HIB+"The room is full of smoke and people sitting at tables drinking"+NORM,
  "bartender",HIB+"He looks like he won't put up with any trouble in his pub"+NORM,

});

dest_dir = ({
    "players/nikki/Tintagel/Rooms/street1.c","out",

});
}}

init() {
  ::init();
    add_action("smell","smell");

}

smell(str) {
  if(str != "air" && !str){
    write("What are you trying to smell?\n");
    return 1;
    }
  if(str == "air"){
    write(GRY+"The sharp stench of alcohol assaults your nostrils!\n"+NORM);
    say(capitalize(TP->query_name())+" breathes in and wrinkles"+TP->query_possessive()+" nose.\n");
    return 1;
    }
}




