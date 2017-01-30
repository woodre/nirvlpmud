/*   This is a generic wiz workroom.  It has a number of examples
	that should help you get started. Before you get too far along,
	you should change 'your_name' to your real name. (i.e I would
	change 'your_name' to "eurale")  I've tried to include things
	that most people want to add so look through and if you still
	have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/open/ansi.h"
#define TP this_player()
#define NAME "brittany"
inherit "room/room";
int shield;
reset(arg) {
  if(arg) return;

short_desc = MAG+"NeTHerWorlDs"+NORM;
long_desc =
"A large office with a huge desk and chair in the middle of the room.\n"+
"One side of the room is lined with a bookshelf, filled with books.  On\n"+
"the opposite side you see a sitting area, a couch, table w/ lamp, and a\n"+
"a coffee table.  The scent of fresh flowers fill the air.  You hear the\n"+
"sound of soft music coming from a radio sitting on the desk.  You may\n"+
"turn your privacy shield (on/off).  There are also hidden exits to the\n"+
"'post' office.\n";
set_light(1);

items = ({
"chair","An executive chair with a high back",
"desk","An executive desk with a nameplate on it",
"couch","A soft plush couch",
"table","end table with a lamp sitting on it",
"bookshelf","Books are lined perfectly on every shelf",
});
dest_dir = ({
"room/adv_inner.c","north",
"room/church","church",
"players/brittany/inferno/infenter.c","east",
"players/brittany/kadath/k1.c","ne",
});

}

init() {
  ::init();
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }

    add_action("listen","listen");
    add_action("smell","smell");
    add_action("search","search");
 }

church() {
  TP->move_player("church#room/church.c");
  command("look",this_player());
  return 1; }

static on() {
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write("You are not allowed to do that!!!!!!!\n");
  return 1; }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
  return 1; }

post(){
  TP->move_player("post office#room/post.c");
  return 1; }

search(){
  notify_fail("You find nothing of intrest.\n");
  return 0;
}
