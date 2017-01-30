inherit "room/room";
#include <ansi.h>
#define TP this_player()
int opened;

reset(arg){
    if(arg) return;
set_light(1);
set_short(BLU+"Yeroc's kitchen"+NORM);
set_long(
"  The kitchen is spotless.  Hanging from the ceiling are various cooking\n"+
"pots and pans.  In the back of the kitchen is a large fire pit with a large\n"+
"kettle hanging above the fire.  Shelves line the walls covered with bottles\n"+
"of many different food items.  A block of knives sits on one of the shelves\n"+
"waiting to be used in making a delicious stew.\n");

items = ({
	"pots",
	"Heavy cast iron cooking pots and pans",
	"pans",
	"Heavy cast iron cooking pots and pans",
	"pit",
	"A large opening in the wall with a fire blazing",
	"fire",
	"The fire appears almost magical in nature",
	"opening",
	"A large opening in the wall with a fire blazing",
	"kettle",
	"The kettle bubbles away as the fire boils the liquid",
	"shelves",
	"The shelves are filled with different bottles of food, except for one",
	"shelf",
	"The shelf is void of all items, making it appear out of place",
	"food",
	"Different vegetables and roots are contained within the bottles",
	"bottles",
	"Different vegetables and roots are contained within the bottles",
	"walls",
	"The walls are covered in shelves",
	"block",
	"A simple block of wood with holes filled with knives",
	"knives",
	"All the knives but one is placed in the wooden block",
	"knife",
	"The knife looks out of place, maybe you should 'place' the knife in the block"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Shelter1.c","out",
	});
opened = 0;
}
init(){
  ::init();
      add_action("PlaceShit","place");
      add_action("Eureka","enter");  
  }

PlaceShit(str)
{
  if (opened = 1)
  {
	write("The tunnel is already open, enter it already.\n");
	return 1;
  }
  if (str != "knife")
  {
	write("What?\n");
	return 1;
  }
  else
  {
  	write("You place the knife in the block of wood and the empty shelf\n"+
      	  "slowly slides behind the others and a tunnel is revealed, perhaps\n"+
	  "you could 'enter' the tunnel.\n");
  	say("A shelf slowly slides behind the others revealing a tunnel.\n");
	opened = 1;
  	return 1;
  }
}
Eureka(str)
{
  if (opened != 1)
  {
	write("What?\n");
	return 1;
  }
  if (str != "tunnel")
  {
	write("Try enter tunnel.\n");
	return 1;
  }
  else
  {
	write("You enter into the dark tunnel.\n");
	TP->move_player("enter#players/catacomb/MF/rooms/tunnel.c");
	return 1;
  }
}
