inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int cash, randomchance, money;
reset(arg) {
randomchance = random(8);
money = 1;
if(!present("girl"))  {
MOCO("/players/jenny/80s/mobs/bgirl.c"),this_object()); }
if(!present("a boy with spiked hair"))  {
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); }
if(!present("a boy with feathered hair"))  {
MOCO("/players/jenny/80s/mobs/fboy.c"),this_object()); }
    if(arg) return;
    set_light(0);
set_listen(BOLD+"You hear the south of video games to the south."+NORM);
long_desc=
"S&L Road stretches out towards the far end of town.  The street lights have\n"+
"been broken for a few days, which is a good indication that this is not one\n"+
"of the nicer parts of the city.  This street is a mix of residential and\n"+
"business.  There are modest homes, and seedy businesses on each side of\n"+
"the street.  The pavement of the street itself is full of cracks and potholes.\n"+
"Maintaining this road does not seem to be a priority.\n";
short_desc=(CYN+"S&L Road"+NORM);
items = ({
"lights","The street lights are broken.  It looks as if some kids have thrown rocks\n"+
              "at them.",
"road","The pavement has lots of cracks and potholes",
"potholes","Holes in the street that have been formed through erosion and lack of repairs",
"cracks","Cracks which have formed in the pavement due to erosion",
"pavement","The pavement has lots of cracks and potholes",
"street","The pavement has lots of cracks and potholes",
"homes","Some modest one story homes are on this street.  Many of them could\n"+
               "use a new coat of paint",
"businesses","This road has many seedy businesses.  You notice an arcade, gas station\n"+
                      "and a K-mart",
});
dest_dir = ({
 "/players/jenny/80s/rooms/6","north",
 "/players/jenny/80s/rooms/18","south",
 "/players/jenny/80s/rooms/11","west",
 "/players/jenny/80s/rooms/13","east",
});
}
init() { 
    ::init();
add_action("coins","search");
}
coins(arg)  {
int cash;
cash = 25+random(18);
if(money == 1 && randomchance == 1) {
write(BOLD+"You find "+cash+" coins in the street."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }
}
