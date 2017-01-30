/*
  I'm still working on this.  It is a LONG way from done.
  It is not well commented yet, but I'm starting to add
  comments.  While I plan to add quite a bit more to this
  file, what is here now, does work and has been tested.
*/
#include "/players/traff/closed/ansi.h"
#define FR "/players/traff/delnoch/forest/"
inherit "players/traff/delnoch/forest/forest2";

reset(arg){

  if(!arg){
  set_light(1);
  long_desc=(GRN+
"The forest seems even thicker here.  You can only see a short\n"+
"distance.  You can hear some sounds from the town of Delnoch\n"+
"but they seem quite distant.  There is little breeze now and\n"+
"you don't see any motion.  You have the feeling that forest\n"+
"creatures are watching you, just out of your range of vision.\n"+
"\n"+NORM);

items=({
"ground","The ground is covered with pine needles",
"pine","Pine trees predominate here and are quite tall",
"pine needles","On the trees they are quite green, and on the ground they are very brown",
"needles","On the trees they are quite green, and on the ground they are very brown",
"needle","Do you mean the pine needles?",
"trees","These trees seem quite old, they are tall and green",
"leaves","There are just a few leaves here",
"growth","There is not as much undergrowth as before",
"mountains","The mountains are hard to glimpse from here.  You see snow capped peaks",
"creature","You don't see a creature here, but you think one could be right behind you",
"creatures","There are no creatures here, but you feel they are watching you",
 });

  dest_dir=({
"/players/traff/delnoch/work/forest1.c","north",
"/players/traff/delnoch/work/forest1.c","south",
"/players/traff/delnoch/work/forest1.c","east",
"/players/traff/delnoch/work/forest1.c","west",
      });
  }   }

short() { return HIG+"Skoda Forest"+NORM;}

init() {
  ::init();
    add_action("search","search");
    add_action("trail","trail");
}

trail() {
  if(!trail) {
    write("What?\n");
    return 1; }
  trail = 0 ;
  write("You move off, up the trail.\n");
  call_other(this_player(),"move_player","up a trail#"+FR+"forest5.c");
  return 1; }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
  trail = 1;
  write("You search the "+str+" and find a trail.\n");
  write("Perhaps the 'trail' leads somewhere.\n");
  return 1;  }
