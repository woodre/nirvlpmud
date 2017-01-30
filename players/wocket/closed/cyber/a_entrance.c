#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;
short_desc = HIY+"CyberNinja Lounge"+NORM;
long_desc = "   "+
"This is the lounge room for the CyberNinja arena.  Many couches and\n"+
"plush chairs line the walls.  You can see a set of stairs that arch to the\n"+
"balcony to the left and right.  In the center of the west wall, a large\n"+
"set of double doors leads into the arena.  The lighting here is comfortable\n"+
"yet slightly dim.  Large paintings hang upon the walls, depicting battles\n"+
"of previous warriors.\n";
items = ({
"couches","They look very soft and very expensive",
"chairs","Made of dark wood and plush cushions they appear comfortable",
"stairs","With dark wood railing and red carpeting, they lead to the balcony",
"balcony","It is up the stairs",
"wall","They are covered with paintings and made of wood panels",
"paintings","They are oil based paintings depicting great battles",
"lighting","It is slightly dim yet very comfortable",
"doors","They are large wooden doors, exquisitively carved, leading to the arean",
});

listens = ({
"default","You hear casual chit chat in the background",
});
smells = ({
"default","The room smells of old tradition",
});

dest_dir = ({
  "/players/dune/closed/guild/rooms/teleport.c","surface",
  "/players/wocket/closed/cyber/newarena.c","arena",
  "/players/wocket/closed/cyber/a_balcony.c","balcony",
});
set_light(1);
}

init(){
::init();
  add_action("sit","sit");
}

sit(str){
  if(!str){ 
    notify_fail("Where would you like to sit?\n");
    return 0;
  }
if(str == "couch"){
    write("You sit down on a couch.\n");
    say(this_player()->query_name()+" sits down on a couch.\n");
 return 1;
}
if(str == "chair"){
    write("You sit in a chair.\n");
    say(this_player()->query_name()+" sits in a chair.\n");
 return 1;
}
notify_fail("That is not here to sit down on.\n");
return 0;
}

/* attition because of change in player.c ... 
   i cant beleive i had to add this.. grumble */
query_no_fight(){ return 1; }
query_spar_area(){ return 1; }

exit(){
if(this_player()->is_player()){
if(query_verb() && query_verb() == "arena")
  return 1;
this_player()->rm_spar();
}
  return 1;
}
