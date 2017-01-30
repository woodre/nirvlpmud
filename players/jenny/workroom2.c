/*   This is a generic wiz workroom.  It has a number of examples
        that should help you get started. Before you get too far along,
        you should change 'your_name' to your real name. (i.e I would
        change 'your_name' to "eurale")  I've tried to include things
        that most people want to add so look through and if you still
        have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/open/ansi.h"
#define TP this_player()
#define NAME "jenny"
#include "/players/jenny/define.h"
inherit "/players/jenny/room";
int shield;

reset(arg) {
  if(arg) return;

long_desc =
  "This is a small closed off area along the ice surface of Joe Louis\n"+
  "Arena.  There is a small bench, which has room for about 3 players\n"+
  "to sit comfortably.  Through the plexiglass, you have a perfect\n"+
   "view of the game.\n";
set_light(1);
set_smell(""+YEL+"You breathe in the musty smell of the penalty box."+NORM+"");
set_listen(""+RED+"You hear the crowd erupt in joy as a goal is scored."+NORM+"");

items = ({
  "bench","An uncomfortable wooden bench",
  "plexiglass","This keeps you from getting hit by an errant puck",
  "game","Fedorov just scored.  Detroit is up 3-1",
});


}
short() {
#include "/players/jenny/randomcolors.h"
return BOLD+""+x+"The "+y+"Penalty "+z+"Box"+NORM; }

init() {
if(TP->query_real_name() !="jenny")  {
command("hug jenny",TP); }
  ::init();

  add_action("church","church");
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
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
  return 1; }
