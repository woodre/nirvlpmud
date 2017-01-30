#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int GATES;
int close;
int open;
int button;
reset(arg) {
   open = 0;
   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     Huge gates are set in a high stone wall, which surrounds the\n"+
   "dreamland often referred to as Kadath.  The golden colored gates\n"+
   "are curved at the top and nearly 15 feet tall.  Huge boulders,\n"+
   "piled on top of one another make this beautiful wall.  The wall\n"+
   "extends from the ground and disappears into the clouds.  Grass\n"+
   "and wild flowers grow all around the base.  There is a sign on\n"+
   "the gates.\n";
   
   items = ({
         "gates","The solid gold gates are curved at the top and about\n"+
         "15 feet tall and set in a high stone wall, also you see a\n"+
         "button embedded into the wall",
         "solid gates","The solid gold gates are curved at the top and about\n"+
         "15 feet tall and set in a high stone wall, also you see a\n"+
         "button embedded into the wall",
         "huge gates","The solid gold gates are curved at the top and about\n"+
         "15 feet tall and set in a high stone wall",
         "grass","The grass is tall and have stalks of dryness in some spots",
         "wild flowers","The flowers have a yellow disk and white rays, some of\n"+
         "them are wilted",
         "sign","The sign is made of metal and attached to the gates\n"+
         "with some bolts, maybe you could 'read' it",
         "flowers","The flowers have a yellow disk and white rays, some of\n"+
         "them are wilting",
         "base","At the base of the wall, grass and wild flowers are growing",
         "ground","Tall grass and wild flowers covers the ground",
         "huge boulders","The boulders are carved at one end to stack on top of\n"+
         "one another",
         "boulders","The boulders are carved at one end to stack on top of\n"+
         "one another",
         "clouds","The clouds are dark and gloomy",
         "button","There is a button on the wall, next to the gates",
         "wall","The wall is made of boulders stacked on top of one another",
         "stone wall","The wall is made of boulders stacked on top of one another",
          });

   dest_dir = ({
         "/players/brittany/globe.c","out",
              });
}

init() {
   add_action("in","in");
   add_action("open","open");
   add_action("push","push");
   add_action("search","search");
   add_action("read","read");
   add_action("out","out");
}

push(str){
if(!str || str!="button"){
return 1; }

  write("The wind whispers...\n\n"+
   "  Beyond the gates of sleep lie a dreamland, a world of strange\n"+
   "beauty and dark terror.  Somewhere, within their ever-shifting\n"+
   "geographies is Kadath, city of the Great One, a place beyond\n"+
   "mortal description.  While humans have visited the dreamland\n"+
   "since the dawn of time, none have ever been known to reach\n"+
   "Kadath.  Enter through the gates and seek out the elusive\n"+
   "city and all of its inhabitants that lie ahead.\n\n"+
   "The wind settles..\n");
return 1; }

in(str) {
   if(!open) {
      write("You bump your head on the closed gates.\n");
      return 1;
   }
write("You  E N T E R  through the gates into a dreamland realm.\n\n");
  say(tpn+"  enters through the gates.\n\n");
    tp->move_player("through the gates#/players/brittany/kadath/k2.c");
    return 1;
}

open(str) {
   if(!str) {
      write("Open what?\n");
      return 1;
   }
   if(str == "gates" && !open) {
      write("The gates squeak as you open them.\n");
      GATES = 0;
      open = 1;
      return 1;
   }
   if(str == "gates" && open) {
      write("The gates are already open.\n");
      return 1;
   }
}
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

read(str) {
    if(!str || str != "sign") {
        notify_fail("What do you want to read?\n");
        return 0; }
 
    write(
     "The sign reads:  Welcome to Kadath - Please come 'In'.\n\n");
     return 1;
}

out(str){
tp->move_player("out#/players/brittany/globe.c");
return 1; }
