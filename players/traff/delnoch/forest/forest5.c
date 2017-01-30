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
"The forest here may have been worked by woodcutters at one\n"+
"time.  The trees are not quite as big as in most areas.\n"+
/**************************/
"The forest thins out a bit, for the moment.  The ground here\n"+
"slopes downhill to the north for a bit, but you can see ahead\n"+
"that it starts to rise more steeply than before.  The few\n"+
"city sounds that you hear are very faint.  They could be\n"+
"from Delnoch, or maybe somewhere else.  A gentle breeze blows\n"+
"and it will probably be much cooler as you near the mountains\n"+
"\n"+NORM);

items=({
"ground","The ground is covered with pine needles",
"pine","Pine trees predominate here and are quite tall",
"pine needles","On the trees they are quite green, and on the ground they are very brown",
"needles","On the trees they are quite green, and on the ground they are very brown",
"needle","Do you mean the pine needles?",
"trees","These trees seem quite old, they are tall and green",
"leaves","There are just a few leaves here",
"growth","There are some bushes and vines here",
"bushes","Some short variety, you're not sure what kind",
"vines","They look like grape vines, but there is no fruit",
"mountains","Mostly you can see the steep incline ahead.  If you look\n"+
"way up you can see peaks far off",
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
  call_other(this_player(),"move_player","up a trail#"+FR+"forest7.c");
  return 1; }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
  trail = 1;
  write("You search the "+str+" and find a trail.\n");
  write("Perhaps the 'trail' leads somewhere.\n");
  return 1;  }
