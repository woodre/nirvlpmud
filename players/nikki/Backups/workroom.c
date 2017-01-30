/*   This is a generic wiz workroom.  It has a number of examples
	that should help you get started. Before you get too far along,
	you should change 'your_name' to your real name. (i.e I would
	change 'your_name' to "eurale")  I've tried to include things
	that most people want to add so look through and if you still
	have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/players/nikki/ansi.h"
#define TP this_player()
#define NAME "nikki"
inherit "room/room";
int shield;

reset(arg) {
  if(arg) return;

short_desc = HIY+"A Cardboard Box"+NORM;
      
long_desc = HIC+
    "   You have entered a large shadowy room.  A pungent sweet smell of\n"+
    "incense dances upon the air.  The music of INXS is singing thru the\n"+
    "room.  As you glance around the room you notice an intricate black\n"+
    "ink mural drawn with such skill, like spiderwebs on the white plaster\n"+
    "walls.  The ceiling is a molded frieze of prancing demons and hags\n"+
    "on broomsticks circling around the moon.  Towards the rightside of\n"+
    "the room you notice two large pillars made of black marble and\n"+
    "between the pillars stands a coffin made of mahogany. Many large\n"+
    "embroidered feather pillows are laying in the center of marble floor.\n"+GRY+
    "A set of large double doors (closed)\n\n"+NORM;
set_light(1);

items = ({
  "mural","The mural depicts a ruined castle on a cliff, dark and towering above\n"+
          "a graveyard with a circle of beings in black robes dancing to the\n"+
          "violin music of the devil, who is sitting on the moon.",
  "chair","A creaky old wooden chair",
  "desk","A scarred old desk with the intial 'B' carved in it",
});

dest_dir = ({
  "players/nikki/workroom.c","sidewalk",
  "players/nikki/workroom.c","starve",
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
  write(HIG+"You feel an intense pressure in your brain as a single thought\n");
  write("enters your mind. 'I wouldn't suggest doing that again.'\n"+NORM);
  this_player()->move_player("Mystified#room/police");
  return 1; }
 }

north() {
  TP->move_player("north#room/vill_green");
  command("look",this_player());
  return 1; }

static on() {
  write(HIG+"The Mist has formed...\n"+NORM);
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write(CLR+"\n\n\n\n\n\t\t\t"+BLINK+HBRED+HIW+"LEAVE MY MIST ALONE!"+NORM+"\n\n\n\n\n\n"+NORM);
  return 1; }
  write(HIW+"The Mist has dissipated...\n"+NORM);
  shield = 0;
  return 1; }

post(){
  TP->move_player("to the post office#room/post");
  return 1; }

west() {
  TP->move_player("west#room/adv_inner.c");
  command("look",this_player());
  return 1; }
