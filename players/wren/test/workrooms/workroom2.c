/* First room attempt. First piece of code actually.
 * Hopefully will turn into a spiffy workroom.
 * Include some extra books, and EvilOverlord List on a poster
 * Derived heavily from the ryllian.c, valley.c, and Feld's example room,
 * and the starting workroom.c
 * Aerie or Lair
 */


#include "/open/ansi.h"
#define TP this_player()
#define NAME "wren"


inherit "room/room";
int shield;



reset(arg) {
  if(arg) return;


short_desc = "Wren's Lair";
long_desc = 
	"The exact location cannot be surmised but you have a suspicion that you are \n"+
	"outside the realm of normal space time. The walls are paneled in smooth dark \n"+
	"marble. Hickory logs crackle and pop in the large hearth that is situated in the \n"+
	"center of the east wall. Large redwood shelves stand on either side of the cheery \n"+
	"blaze. Upon them leather bound tomes and folios mingle with busts of literary \n"+
	"figures. Before the fire are two well upolstered chairs for light reading. \n"+
	" \n"+
	"A massive oak desk extends from the west wall into the center of the room \n"+
	"with scrolls covering every flat surface. Weapons hang above on ornate hardwood \n"+
	"racks. Diagrams on old parchment of various strikes and katas are tacked to the wall. \n"+
	"Firelight glints off metal in several locations around the room. Above the door \n"+
	"you notice a strange metal porticullis has been added. Barely percievable in the shadows  \n"+
	"of the northwest corner swirls a pulsing magic rift. \n";

set_light(1);

items = ({
	"rift","Mystical energy swirls and coaleses. A wrinkle in time and space or something else",
	"hearth","The large fireplace seems to naturally flow from the marble walls around it",
	"busts","The cast faces of Homer, Shakespeare, and Mark Twain",
	"glint","Several heavy crossbows are mounted in the walls. Armed and rigged to fire it seems",
	"porticullis","It is built like a cage and could probably serve in that function",
	"books","Vast and various titles of sci fi, fantasy, and classical works scattered about the shelves",
	"folios","You see one of the rare original folios of Shakespeare and Chaucer",
});

dest_dir = ({
	"room/adv_inner.c","north",
});

}

init() {
    ::init();
add_action("church","church");
add_action("on");add_verb("on");
add_action("off");add_verb("off");
add_action("post");add_verb("post");

if(this_player()->query_real_name() != NAME && shield ==1) {
    write("You feel an eletric shock and see a FLASH of white light \n"+
	  "as you rebound off some defensive shield. \n");
this_player()->move_player("off the shields#room/church");
return 1;}
}

church()  {
   TP->move_player("church#room/church.c");
   command("look",this_player());
   return 1; }

static on()  {
   write("You"+BOLD+"activate"+NORM+"the shield. \n");
   shield = 1;
   return 1; }

static off()  {
   if(TP->query_real_name() !=NAME)  {
   write("Access denied.\n");
   return 1;  }
   write("You"+BOLD+"deactivate"+NORM+"the shield. \n");
   shield = 0;
   return 1; }

post() {
   TP->move_player("post office#room/post.c");
   return 1; }	






