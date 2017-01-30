/*
  I'm still working on this.  It is a LONG way from done.
  It is not well commented yet, but I'm starting to add
  comments.  While I plan to add quite a bit more to this
  file, what is here now, does work and has been tested.
   2-29-00
   Getting closer to being done.  Still need to code items for
   the monsters, and want to try and add some movement to the
   monsters.
*/
#include "/players/traff/closed/ansi.h"
#define FR "/players/traff/delnoch/forest/"
inherit "room/room";
string fr,fc;
/*
object monster;
*/
int m,mc,r,path,trail;

reset(arg){
  if(!arg){

  set_light(1);
  long_desc=(GRN+
"You have wandered into the Skoda forest.  This forest covers\n"+
"hundreds of square miles of the lower part of the Skoda mountains\n"+
"You are surounded by trees that all look pretty much alike.\n"+
"It would be easy to get lost here.\n"+NORM);

items=({
"ground","The ground is cover with pine needles",
"trees","Mostly conifers, they are tall and green",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
 });

  dest_dir=({
"/players/traff/delnoch/work/forest1.c","north",
"/players/traff/delnoch/work/forest1.c","south",
"/players/traff/delnoch/work/forest1.c","east",
"/players/traff/delnoch/work/forest1.c","west",
      });
  }   }

short() { return HIG+"Skoda Forest"+NORM;}

init()  {
 ::init();
  add_action("roam","north");
  add_action("roam","south");
  add_action("roam","east");
  add_action("roam","west");
  add_action("flee","flee");
/* Change path to trail in odd number rooms */
  add_action("path","path");
  add_action("search","search");
  add_action("count","count");
}

realm() { return "NT"; }

roam()  {

    if(!fr) {
      fr = allocate(10);
      fr[0]=FR+"forest2.c";
      fr[1]=FR+"forest3.c";
      fr[2]=FR+"forest4.c";
      fr[3]=FR+"forest5.c";
      fr[4]=FR+"forest6.c";
      fr[5]=FR+"forest7.c";
      fr[6]=FR+"forest8.c";
      fr[7]=FR+"forest9.c";
      fr[8]=FR+"forest10.c";
      fr[9]=FR+"forest11.c";
    }

    if(!fc) {
      fc = allocate(10);
      fc[0]="fc0.c";
      fc[1]="fc1.c";
      fc[2]="fc2.c";
      fc[3]="fc3.c";
      fc[4]="fc4.c";
      fc[5]="fc5.c";
      fc[6]="fc6.c";
      fc[7]="fc7.c";
      fc[8]="fc8.c";
      fc[9]="fc9.c";
    }
  r = random(10);
  call_other(this_player(),"move_player","through the trees#"+fr[r]);
    if(!(this_player()->is_player())) { return 1; }
  path = 0;
  m += 1;
  mc += 1;
    if (m < 21) {
      r = random(10);
      write_file("/players/traff/delnoch/forest/CRITTERS",ctime()+" fc"+r+".c Cloned\n");
      move_object(clone_object("/players/traff/delnoch/mon/"+fc[r]),this_object());
      return 1;}
  return 1;
         }

flee() {
  if(this_player()->query_level()<6) {
    call_other(this_player(),"move_player","running wildly#"+FR+"forest1.c");
    path = 0;
    return 1; }
  write("You can't do that!\n");
  return 1; }

path() {
  if(!path) {
    write("What?\n");
    return 1; }
  path = 0 ;
  write("You move off, down the path.\n");
  call_other(this_player(),"move_player","down a path#"+FR+"forest1.c");
  return 1; }

search(str)  {

  if(!str)  {
    write("Search what?\n");
    return 1;  }
   
  path = 1;
  write("You search the "+str+" and find a path.\n");
  write("Perhaps the 'path' leads somewhere.\n");
  return 1;  }

count() {
  write("Monsters cloned = "+mc+" Current = "+m+"\n");
  return 1; }

dead_mon() {
  m -= 1;
  return 1; }
