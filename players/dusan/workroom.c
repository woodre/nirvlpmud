/*   This is a generic wiz workroom.  It has a number of examples
	that should help you get started. Before you get too far along,
	you should change 'your_name' to your real name. (i.e I would
	change 'your_name' to "eurale")  I've tried to include things
	that most people want to add so look through and if you still
	have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/open/ansi.h"
#define TP this_player()
#define NAME "dusan"
inherit "room/room";
int shield;

reset(arg) {
  if(arg) return;

short_desc = ""+HIR+"Dusans Lair"+NORM+"";
long_desc =
  "A large pool of "+BOLD+"Dark Matter"+NORM+" dominates the center of this room.\n"+
  "Randomly you will see a tentacle form and lash about, or a human\n"+
  "face form in the pool.\n";
set_light(1);

items = ({
  "pool","A pool of a viscous oily substance",
  "face","A human looking face.  It seems to be screaming!!",
  "tentacle","A long snakelike mass of dark matter"
});

dest_dir = ({
  "room/adv_inner.c","north",
});

}

init() {
  ::init();
  add_action("church","church");
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("wtool"); add_verb("wtool");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
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
  return 1 ; }

wtool(){
move_object(clone_object("/obj/wiz_tool"), this_player()); 
return 1 ; }