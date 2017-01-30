inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int COST;
int SALE;
reset(arg) {
SALE = random(7);
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear Def Leopard over the store's stereo."+NORM);
set_search(BOLD+"You notice a sign above the register."+NORM);
long_desc=
"This is a small t-shirt shop.  It specializes in the shirts of popular\n"+
"musical artists.  This shop looks kind of seedy.  The floor tile may\n"+
"have been white at one time, but now is a yellowish color, with\n"+
"pieces of bubble gum stuck to it.  There are several racks through-\n"+
"out the store, with a decent selection of shirts.  The register near\n"+
"the side wall has a sign above it.\n";
short_desc=(HIB+"A T-shirt shop"+NORM);
items = ({
"racks","There are several circular racks containing a decent selection of t-shirts",
"gum","Bubble gum that has been stuck to the floor for a while",
"shirts","A nice selection of t-shirts featuring popular 80's bands",
"floor","This yellowing stained floor is an example of what happens when you\n"+
              "never mop or sweep",
"register","An electric cash register.  You pay for the shirts here",
"sign","A light blue sign which lists the prices.  You could read it",
});
dest_dir = ({
 "/players/jenny/80s/rooms/11","exit",
});
}
init() { 
    ::init(); 
add_action("sign","read");
add_action("shirts","buy");
}
shirts(arg) {
if(SALE > 5) {COST = 40;}
if(SALE < 6) {COST = 50;}
if(!arg) { return 0; }
if(arg == "1" || arg == "2" || arg == "3" || arg == "4" || arg == "5" || arg == "6" || arg == "7" || arg == "8" || arg == "9" || arg == "10" || arg == "11" || arg == "12" || arg == "13" || arg == "14" || arg == "15") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that.\n");
return 1; }
if(this_player()->query_money() < COST) {
write("You can't afford a shirt.\n");
return 1; }
TP->add_money(-COST); 
write("You buy a t-shirt.\n");}
if(arg == "1") { MOCO("/players/jenny/80s/items/tshirts/bangles.c"),TP);}
if(arg == "2") { MOCO("/players/jenny/80s/items/tshirts/bramma.c"),TP);}
if(arg == "3") { MOCO("/players/jenny/80s/items/tshirts/jovi.c"),TP);}
if(arg == "4") { MOCO("/players/jenny/80s/items/tshirts/dleopard.c"),TP);}
if(arg == "5") { MOCO("/players/jenny/80s/items/tshirts/duran.c"),TP);}
if(arg == "6") { MOCO("/players/jenny/80s/items/tshirts/newkids.c"),TP);}
if(arg == "7") { MOCO("/players/jenny/80s/items/tshirts/petshop.c"),TP);}
if(arg == "8") { MOCO("/players/jenny/80s/items/tshirts/prince.c"),TP);}
if(arg == "9") { MOCO("/players/jenny/80s/items/tshirts/riot.c"),TP);}
if(arg == "10") { MOCO("/players/jenny/80s/items/tshirts/speedwagon.c"),TP);}
if(arg == "11") { MOCO("/players/jenny/80s/items/tshirts/tears.c"),TP);}
if(arg == "12") { MOCO("/players/jenny/80s/items/tshirts/tsister.c"),TP);}
if(arg == "13") { MOCO("/players/jenny/80s/items/tshirts/wangchung.c"),TP);}
if(arg == "14") { MOCO("/players/jenny/80s/items/tshirts/wham.c"),TP);}
if(arg == "15") { MOCO("/players/jenny/80s/items/tshirts/halen.c"),TP);}
return 1; }
sign(arg) {
if(SALE > 5) {COST = 40;}
if(SALE < 6) {COST = 50;}
if(!arg) { return 0; }
if(arg == "sign") {
write(HIC+"\n"+
"		*****************************************\n"+
"		*	   "+WHT+"Buy shirts by the #"+HIC+"		*\n"+
"		*		"+COST+" coins		*\n"+
"		*					*\n"+
"		*	1	The Bangles		*\n"+
"		*	2	Bananaramma		*\n"+
"		*	3	Bon Jovi		*\n"+
"		*	4	Def Leppard		*\n"+
"		*	5	Duran Duran		*\n"+
"		*	6	New Kids on The Block	*\n"+
"		*	7	Pet Shop Boys		*\n"+
"		*	8	Prince			*\n"+
"		*	9	Quiet Riot		*\n"+
"		*	10	REO Speedwagon		*\n"+
"		*	11	Tears for Fears		*\n"+
"		*	12	Twisted Sister		*\n"+
"		*	13	Wang Chung		*\n"+
"		*	14	Wham!			*\n"+
"		*	15	Van Halen		*\n"+
"		*****************************************"+NORM+"\n");
return 1;}}
