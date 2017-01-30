#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#include "/players/tristian/lib/ansi.h"
inherit "room/room";
int cig;


reset(arg) {
	if(arg) return;
  
cig = 0;

set_light(1);

short_desc = HIR+"Club Fed"+NORM+" cellblock "+HIG+"'A' "+NORM+" cell "+HIY+"#101"+NORM; 

long_desc =
	" This is a standard cell in Club Fed, the minimum security\n"+
	"facility where white collar criminals and celebrities come\n"+
	"to serve thier sentances for thier crimes verse society.  Its\n"+
	"nicer than some hotels in the land, with a double bed, a full\n"+
	"window and a bathroom shared with the adjacent cell.\n";

items = ({

"window", 
	"A full double hung window that is bolted shut and is still covered with 'bars' however\n",
"bars",
	HIK+"---------------------------------------------------\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"---------------------------------------------------\n"+NORM,
"bed",
	"Its a sealy posturpedic mattress on a metal bed frame",
"sealy",
	"xxxx",
   
});

/*
if(!present("wccriminal",this_object()))
	move_object(
	clone_object("/players/tristian/realms/ClubFed/mon/criminal.c"),
	this_object());
*/

dest_dir = ({
  "/players/tristian/realms/ClubFed/rooms/hall1",    "south",
});
}

init() {
  ::init();
    add_action("Smell","smell");
    add_action("Search","search");
    add_action("Listen","listen");
    add_action("Toss","toss");
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Search() {
    write("You find nothing special. Perhaps 'toss'ing the cell would be more appropriate.\n");
	 return 1;
}

Toss(str) {
  if(str == "cell" && cig == 0){
    write("You search behind the bed, in the closet and just as your about to give up\n"+
    "you find a single cigarette behind the picture.\n");
    say (TPN +" tosses the cell and finds a cigarette.\n");
      	
    cig=clone_object("/players/tristian/realms/goblin/obj/wolfpelt.c");
    move_object(cig,this_object());
    cig = 1;
    return 1;
  }
      		
  else{
    write("Toss what?\n");
    return 1;
  }
	
  if(str == "cell" && cig == 1){
    write("You toss the cell and don't find anything.\n");
    say (TPN +" tosses the cell but doesn't find anything.\n");
    return 1;
  }
}
Toss_ill(str) {
  if(str=="cell") {
    if(cig==0) {
      write("You search behind the bed, in the closet and just as your about to give up\n"+
      "you find a single cigarette behind the picture.\n");
      say (TPN +" tosses the cell and finds a cigarette.\n");
      	
      cig=clone_object("/players/tristian/realms/goblin/obj/wolfpelt.c");
      move_object(cig,this_object());
      cig = 1;
      
      return 1;
    } else {
      write("You toss the cell and don't find anything.\n");
      say (TPN +" tosses the cell but doesn't find anything.\n");
      return 1;
    }
  } else {
    write("Toss what?\n");
    return 1;
  } 
}   
   

Listen() {
    write("The sounds of a somewhat atypical prison, The guard walking up\n"+
    "and down the hall, and a slightly mechanical buzz are in the air.\n");
    return 1;
}



