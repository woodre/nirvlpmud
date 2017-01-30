#define tp this_player()->query_name()

inherit "room/room";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

int TAKEN, gem, number;
object ELEMENTAL;

reset(int arg){
 TAKEN = 0;
 if(!arg){

 set_light(1);
 short_desc="Free Falling";

 long_desc="\n"+
"Floating upon the thermals, you "+HIB+BOLD+"   / \\    "+NORM+
"see a strange sight.  Before\n"+
"you drifts a huge azure crystal,"+HIB+BOLD+" <  o  >  "+NORM+
"gleaming as the moon.  Below,\n"+
"the heat swirls the clouds into "+HIB+BOLD+"   \\ /    "+NORM+
"chaotically ordered patterns.\n\n";


items=({
 "thermals","Warm breezes drift up from the mountains below",
 "thermal","Warm breezes drift up from the mountains below",
 "breeze","Warm breezes drift up from the mountains below",
 "wind","Warm breezes drift up from the mountains below",
 "crystal","A huge azure crystal floats here.\n"+
           "You could try to take it, if you want",
 "mountains","A long stretch of young mountains lie below you",
 "peeks","A long stretch of young mountains lie below you",
 "cloud","Hazy clouds swirl below you",
 "clouds","Hazy clouds swirl below you",
 });


dest_dir=({
 "/players/saber/mr/mr2.c","up",
 "/players/saber/mr/mr6.c","down",
           });
  }   }


init(){
 ::init();
  add_action("search","search");
  add_action("down","d");
  add_action("down","down");
  add_action("up","u");
  add_action("up","up");
  add_action("crystal_get","get");
  add_action("crystal_get","take");
        }


crystal_get(str)  {
 if(str == "crystal")  {
  if(TAKEN < 1)  {
  TAKEN = 1;
  move_object(clone_object("/players/saber/gems/sapphire.c"), this_player());
  write("You reach out and take a bit of the crystal.\n"+
        "Hay, this is a diamond!\n");
  say(tp+" reaches out and takes part of the crystal.\n");
  tell_room(environment(this_player()), "\n"+
  "The crystal suddenly flares with ELEMENTAL light!\n\n");

  number = random(3) + 3;
  for(gem = 0; gem < number; gem++)  { 
  move_object(clone_object("/players/saber/monsters/mr/airelemental.c"),this_object()); 
   }

  ELEMENTAL = present("elemental");
  ELEMENTAL->attack_object(this_player());
  return 1;
 
        }
  say(tp+" reaches out towards the crystal.\n"+
      tp+"'s hand passes through the crystal.\n");
  write("Your hand passes through the crystal.\n");
  return 1;
        }
        }

down()  {
 say(tp+" rotates into a head dive.\n"+
     "You watch as "+tp+" falls from sight...\n");
 write("You rotate your body into a head dive and go\n\n"+
    "    Down\n\n"+
    "           dOwn\n\n"+
    "                  doWn\n\n"+
    "                         dowN\n\n");
call_other(this_player(), "move_player", "down#players/saber/mr/mr6.c");
return 1;
 }

up()  {
 say(tp+" spreads "+this_player()->query_possessive()+" body eagle and catches an updraft.\n"+
     "You watch as "+tp+" rises into the sky...\n");
 write("                                   Up  up\n"+
       "                           up  UP \n"+
       "                         UP\n"+
       "                   up  Up\n"+
       "            Up   UP\n"+
       "     Up  up\n"+
       "  up\n\n"+
       "You spread your body eagle and catch an updraft.\n\n");
call_other(this_player(), "move_player", "up#players/saber/mr/mr2.c");
return 1;
 }

search() {
 write("Well, there is that big gem hanging there.  You might want to look at it.\n");
 say (tp +" searches the area.\n");
 return 1;  
        }
