/*   This is a generic wiz workroom.  It has a number of examples
	that should help you get started. Before you get too far along,
	you should change 'your_name' to your real name. (i.e I would
	change 'your_name' to "eurale")  I've tried to include things
	that most people want to add so look through and if you still
	have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/players/snakespear/closed/ansi.h"
int colors;
#define TP this_player()
#define NAME "snakespear"
inherit "room/room";
int shield;
string color;
string colors;

choose_color();

short () { return GRY+"The "+colors+"Angry"+GRY+" Chair"+NORM;  }
reset(arg) { 
  choose_colors();
  choose_color();
  if(arg) return;


long_desc=BLU+"\n"+
 "   This wonderous place is decorated with contemporary furnishings, along\n"+
 "with impressionistic paintings, placed selectively around the room.  The\n"+
 "room is much larger than it appears.  Perhaps this is because of the many\n"+
 "areas around the room.  The lighting for the room appears to be coming from\n"+
 "the large number of candles, delicately positioned around the room.  Large\n"+
 "Persian rugs lay around the room, covering what should be a floor, yet seems\n"+
 "to be more of a mass of swirling matter.  Gazing down into the floor, one can\n"+
 "see it's everchanging nature, much like the mind of the one whom created such\n"+
 "a place of beauty.  Soft music flows gently through the air, mixing with scents\n"+
 "of cinnamon and vanilla.\n"+NORM;

set_light(1);

items = ({ 
  "furnishings",color+"A black leather couch adorned with throw pillows and an ox-blood recliner\n"+
                      "are just a few of the furnishings"+NORM,
  "couch",color+"A soft, Italian leather couch that looks well used"+NORM,
  "pillows",color+"Small pillows with a paisely pattern lay on the couch"+NORM,
  "recliner",color+"A large, comfortable recliner that is Snakespear's throne"+NORM,
  "paintings",color+"Many original paintings from artists such as Van Gogh and Monet"+NORM,
  "candles",color+"Candles of many sizes are burning around the room"+NORM,
  "rugs",color+"Tapestries with many intricate designs amplify the rooms beauty"+NORM,
  "matter",color+"A very magical looking floor.  Perhaps it is Snakespear's power base"+NORM,
  "floor",color+"A swirling matter of energy or power shifts constantly beneath your feet"+NORM,
});

choose_color();

dest_dir = ({
  "room/church","rise",
  "/players/snakespear/tools/hub.c","hub",
  "/players/eurale/VAMPIRES/RMS/vguild_hall","guild",
});
}

init() {
  ::init();
  add_action("north","north");
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("west"); add_verb("west");
  if(this_player()->query_real_name() != NAME && shield == 1) {
  write(HIR+BLINK+"\n\n\n\n\n\n\n\t\tThat was pretty rude, don't YOU think??\n\n\n\n\n\n\n\n\n\n"+NORM);
  this_player()->move_player("by forces unknown#room/sea");
  write("Snakespear tells you: Feel welcome in my home, but don't abuse the privelage..\n");
  return 1; }
 }

north() {
  TP->move_player("towards the Village Green#room/vill_green");
  command("look",this_player());
  return 1;
}

static on() {
  write(colors+"Snakespear gestures slowly with his hands....\n"+NORM);
  write(colors+"The room suddenly gets much colder.\n"+NORM);
  shield = 1;
  return 1;
}

static off() {
if(TP->query_real_name() != NAME) {
  write(CLR+"\n\n\n\n\n\t\t\t"+BLINK+HBRED+HIW+"Wrong answer....."+NORM+"\n\n\n\n\n\n"+NORM);
  return 1; }
  write(HIW+"An eerie sound is heard and the room warms up.\n"+NORM);
  shield = 0;
  return 1;
}

post(){
  TP->move_player("to the post office#room/post");
  return 1;
}

west() {
  TP->move_player("to the wiz hall#room/adv_inner.c");
  command("look",this_player());
  return 1;
}


realm() { return "NT"; }

choose_color() {
   int blah;
   blah = random(14);
   switch(blah) {
   case 0:	color = RED; break;
   case 1:      color = GRN; break;
   case 2:      color = YEL; break;
   case 3:	color = BLU; break;
   case 4:	color = MAG; break;
   case 5:	color = CYN; break;
   case 6:      color = BOLD+BLK; break;
   case 7:      color = HIR; break;
   case 8:	color = HIG; break;
   case 9:	color = HIY; break;
   case 10:	color = HIB; break;
   case 11:	color = HIM; break;
   case 12:	color = HIC; break;
   case 13:     color = HIW; break;
   }
   return 1;
}

choose_colors() {
call_out("choose_colors",4);
switch(random(7)) {
   case 0:     colors = RED; break;
   case 1:     colors = BLU; break;
   case 2:     colors = MAG; break;
   case 3:     colors = BOLD+BLK; break;
   case 4:     colors = HIR; break;
   case 5:     colors = HIB; break;
   case 6:     colors = HIM; break;
return 1; 
}
}
