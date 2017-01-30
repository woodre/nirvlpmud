#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(!present("fountain",this_object()))
move_object(clone_object(PATH+"/OBJ/fountain.c"),this_object());
/* Added by Snow 5/99 */
if(!present("a fruit stand"))
move_object(clone_object("/players/wocket/turtleville/OBJ/stand.c"),this_object());
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
}
    if(arg) return;

short_desc = HIG+"The Turtleville Fountain"+NORM;
long_desc = "   Small shops litter the roads that intercept here.  Green shelled\n"+
            "rooftops with bamboo walls decorate the stores and houses.  The\n"+
            "streets are nice and clean, paved with smooth stones.  The sky is nice\n"+
            "and blue with puffy white clouds blowing gently across the it.  A\n"+
            "fountain rests in the middle forming a circle in the crossroads making\n"+
            "a nice little area to rest and relax.\n";

items = ({
  "shops","They line the streets with their green roofs and bamboo walls",
  "roads","They are paved with soft smooth stones, ground down by the passing of time",
  "roofs","They are green and look similar to turtle shells",
  "streets","They are paved with soft smooth stones, ground down by the passing of time",
  "clouds","They accent the blue sky with there pure white puffy outlines",
  "houses","They line the street with there green roofs and bamboo walls",
  "walls","They are the walls of the shops and houses.  Made of bamboo \nthe give off a nice yellow",
  "rooftops","They are green and look similar to turtle shells",
  "tops","They are green and look similar to turlte shells",
  "coins","They cover the bottom of the fountain, glinting in the light",
  "fish","Little orange fish that swim around piles of coins in the fountain",

});
  dest_dir = ({
    PATH+"/tnpath1.c","north",
    PATH+"/twpath1.c","west",
    PATH+"/tspath1.c","south",
    PATH+"/tepath1.c","east",
  });
set_light(1);
}
