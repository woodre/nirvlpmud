inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice a small sign on the counter."+NORM);
long_desc=
"This is a small souvenir shop, which sells Red Wings merchandise.\n"+
"Calling it a shop is kind of a stretch, it is a small room full of items\n"+
"behind a counter.  There is no room for customers inside.  A clerk\n"+ 
"standing behind the counter gets whatever items you point at.\n"; 
items = ({
"items","Behind the counter is a large assortment of Red Wings merchandise",
"counter","A red counter separating you from the merchandise.  There is a\n"+
                "small sign on it",
"sign","A small red sign telling you the items that are for sale.  You could\n"+
                    "read it",
"clerk","The clerk is a friendly looking old man with grey hair and a red\n"+
             "blazer.  He asks you what you'd like to buy",
});
dest_dir = ({
 "/players/jenny/wings/rooms/c3","west",
});
}
short() {
return BOLD+RED+"Souvenir Shop"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("sign","read");
add_action("junk","buy");
}
junk(arg) {
if(!arg) { return 0; }
if(arg == "1" || arg == "2" || arg == "3" || arg == "4") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that.\n"); return 1; }
 if(TP->query_money() < 75) { write("You can't afford that.\n"); return 1; }
}
if(arg == "5") {
 if(!this_player()->add_weight(2)) {
    write("You can't carry that.\n"); return 1;}
 if(TP->query_money() < 250) {write("You can't afford that.\n"); return 1; }
}
if(arg == "1") { MOCO("/players/jenny/wings/items/wingshat.c"),TP);
                 write("The clerk hands you the hat and thanks you for your business.\n");
                 TP->add_money(-75);}
if(arg == "2") { MOCO("/players/jenny/wings/items/wingsscarf.c"),TP);
                 write("The clerk hands you the scarf and thanks you for your business.\n");
                 TP->add_money(-75);}
if(arg == "3") { MOCO("/players/jenny/wings/items/puck2.c"),TP);
                 write("The clerk hands you the puck and thanks you for your business.\n");
                 TP->add_money(-75);}
if(arg == "4") { MOCO("/players/jenny/wings/items/octopus.c"),TP);
                 write("The clerk hands you the stuffed octopus and thanks you for your business.\n");
                 TP->add_money(-75);}
if(arg == "5") { MOCO("/players/jenny/wings/items/wingsjacket.c"),TP);
                 write("The clerk hands you the jacket and thanks you for your business.\n");
                 TP->add_money(-250);}
return 1; }
sign(arg) {
if(!arg) { return 0; }
if(arg == "sign") {
write(HIR+"\n"+
"	* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"+
"	*							*\n"+
"	*		Buy stuff by the number.		*\n"+
"	*							*\n"+
"	*	1	Red Wings Hat		 75 coins	*\n"+
"	*	2	Red Wings Scarf		 75 coins	*\n"+
"	*	3	Souvenir Puck		 75 coins	*\n"+
"	*	4	Stuffed Octopus		 75 coins	*\n"+
"	*	5	Red Wings Jacket	250 coins	*\n"+
"	*							*\n"+
"	*							*\n"+
"	*							*\n"+
"	* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"+NORM+"\n");
return 1;}}
