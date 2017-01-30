inherit "room/room";
#include "/players/sparkle/ansi.h"
#define TP this_player()
#define NAME "sparkle"
int shield,i;


reset(arg) {
      if(arg) return;
          
     short_desc=("Private Garden");
     long_desc=
       "     This private garden is where Sparkle comes to just get\n"+
       "away and relax. It overlooks a beautiful valley forest that\n"+
       "is said to be home to many mystical creatures. The sounds of\n"+
       "birds chirping and the waterfall down below makes the garden\n"+
       "a very serene place where one can sit and think about the many\n"+
       "things that bring them joy in their lives. At night the stars\n"+
       "shine so brightly here one would think they've reached heaven.\n";
     items = ({
       "forest","It is rumored that this forest is home to many beautiful creatures including unicorns and pegasus.",
});

     dest_dir = ({
       "/players/sparkle/office.c","south", /* lets you walk back to your study  */
       "/players/sparkle/wroom.c","north", /* lets you walk back to your bedroom */
});
}

init() {
  ::init();
  add_action("Search","search");
  add_action("on"); add_verb("on");
  add_action("off"); add_verb("off");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
}

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
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
