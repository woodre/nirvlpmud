#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg){

 if(!arg){

 set_light(1);
 short_desc="Up in the Air";

 long_desc="\n"+
     "                             You stand upon a large platform of stable\n"+
BOLD+"            ____             "+NORM+"air.  In the middle of the platform rests\n"+
BOLD+"        ....|  |......       "+NORM+"a rift leading back into the Wizards Club.\n"+
BOLD+"      .     |  |      .      "+NORM+"Warm thermals breeze about you, rising up\n"+
BOLD+"      ...............        "+NORM+"from the stretch of mountains tiny in the\n"+
     "                             distance below.\n\n";


items=({
 "platform","A large platform constructed from stable air",
 "rift","A door sized rift leading back into the Wizard's Club",
 "thermals","Warm breezes drift up from the mountains below",
 "thermal","Warm breezes drift up from the mountains below",
 "breeze","Warm breezes drift up from the mountains below",
 "mountains","A long stretch of young mountains lie below you",
 });


dest_dir=({
 "/players/pain/ryllian/hero.c","rift",
 "/players/saber/mr/mr2.c","jump",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("jump","jump");
        }


jump()  {
 say(tp+" jumps off the platform!\n"+
     "You watch as "+tp+" falls from sight...\n");
 write("You jump off the platform!\nYou fall\n\n"+
    "    Down\n\n"+
    "           dOwn\n\n"+
    "                  doWn\n\n"+
    "                         dowN\n\n");
 }

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
