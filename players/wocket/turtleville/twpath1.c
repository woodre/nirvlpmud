#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = ""+
"   The sun is shining bright upon the cityscape.  Houses line the street\n"+
"with there green shell like roofs.  The street is paved with soft worn stones\n"+
"that have been walked upon by many feet. To the east is the center\n"+
"of town while west leads out to the country side.\n";

items = ({
  "sun","It is very bright and blinds you as you look upon it",
  "cityscape","You see many turtillian buildings set upon a forest backdrop",
  "houses","There are many small, yellow houses with turtleshell roofs\nlining the street",
  "street","It is paved with very soft rounded stones",
  "stones","They are soft to the touch and look worn by much travel",
  "roofs","The are bright green and have the markings of turtles",
  "center","That is to the east",

});

listens = ({
  "default","You hear the sounds of a bright day",
});
smells = ({
  "default","You smell the fresh air",
});

  dest_dir = ({
    PATH+"/tville_kennel.c","north",
    PATH+"/twpath2.c","west",
    PATH+"/tville_fount.c","east",
     PATH+"/tville_church.c","south",
  });
set_light(1);
}
