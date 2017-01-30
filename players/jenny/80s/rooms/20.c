inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int cash, randomchance, money;
reset(arg) {
randomchance = random(5);
money = 1;
if(!present("cyndi lauper"))  {
MOCO("/players/jenny/80s/mobs/lauper.c"),this_object()); }
if(!present("boy george"))  {
MOCO("/players/jenny/80s/mobs/boyg.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_smell(BOLD+"It smells like spilt beer."+NORM);
set_listen(BOLD+"Boy George and Cyndi Lauper are both performing!"+NORM);
long_desc=
"This is a trendy nightclub, which features live entertainment.  The\n"+
"floor beneath your feet is made of hardwood, and good for dancing.\n"+
"The strobe lighting makes it difficult to see, but the stage near the\n"+    
"back of the room is hard to miss.  Looking through the maze of\n"+
"people who are dancing and having a good time, you spot the bar.\n";
short_desc=(HIR+"A niteclub"+NORM);
items = ({
"stage","This is a modest wooden stage which has hosted some of the biggest\n"+
              "names in the music industry",
"people","Most of these people look kind of punkish.  Many of the women have\n"+
               "purple or blue streaks in their hair",
"strobe lights","These are blue strobe lights which flicker on and off.  They\n"+
"make it hard to see, but provide an exciting atmosphere",
"floor","This is a beautiful hardwood floor.  There are not as many stains\n"+
              "as you might expect",
"bar","A long wooden bar with a very impressive liquor selection",
});
dest_dir = ({
 "/players/jenny/80s/rooms/16","out",
});
}
init() { 
    ::init();
add_action("coins","search");
}
coins(arg)  {
int cash;
cash = 30+random(20);
if(money == 1 && randomchance == 1) {
write(BOLD+"You find "+cash+" coins."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }
}
