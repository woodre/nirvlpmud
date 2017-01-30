/*	The guidlines in /doc/build/RULES/heals/heal3 say these potency heals
*	should be priced:  tang.c - 1650, toast.c - 1650, and beer.c 1950
*	I randomized the prices, since I feel it encourages players to 
*	search the mud to find good deals.  The average prices are:
*    tang.c - 1660, toast.c - 1660, and beer.c - 1965
*/
inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int a;
int b;
int c;
realm() { return "NT"; }
reset(arg) {
a = 1350+random(620);
b = 1350+random(620);
c = 1650+random(630);
    if(arg) return;
    set_light(1);
short_desc=(BLU+"BUNDYLAND "+YEL+"HEAL "+GRN+"SHOP"+NORM);

long_desc=
"This is the BundyLand Heal shop.  This is where you can\n"+
 "buy just a few of the food items that the Bundy's use\n"+
"to sustain their meager existence.\n"+
"Type "+RED+"list"+NORM+" for heals you can buy.\n";

dest_dir = ({
"/players/jenny/bundy/rooms/m3c","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("list","list");
add_action("heals","buy");
add_action("heals","purchase");


}
list()  {

write(
       ""+HIB+"        ()()()()()()()()()()()()()()()()()()()()()()()()()\n"+
              "        ()                                              ()\n"+
              "        ()      "+WHT+"1.  Toaster Shakins     "+a+" coins"+HIB+"      ()\n"+
              "        ()                                              ()\n"+
              "        ()      "+WHT+"2.  Tang                "+b+" coins"+HIB+"      ()\n"+
              "        ()                                              ()\n"+
              "        ()      "+WHT+"3.  Beer                "+c+" coins"+HIB+"      ()\n"+
              "        ()                                              ()\n"+

              "        ()()()()()()()()()()()()()()()()()()()()()()()()()"+NORM+"\n"); 
return 1; }

heals(arg) {
if(!arg) { return 0; }
if(arg == "1" || arg == "toaster shakins") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that.\n");
return 1; }
if(this_player()->query_money() < a) {
write("You can't afford that!\n");
return 1; }
TP->add_money(-a);
write("You buy some toaster shakins.\n");
say(TPN+" buys some toaster shakins.\n");
MOCO("/players/jenny/bundy/items/toast.c"),TP);
return 1; }
if(arg == "2" || arg == "tang") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that.\n");
return 1; }
if(this_player()->query_money() < b) {
write("You can't afford that!\n");
 return 1; }
TP->add_money(-b);
write("You buy some tang.\n");
say(TPN+" buys some tang.\n");
MOCO("/players/jenny/bundy/items/tang.c"),TP);
return 1; }
if(arg == "3" || arg == "beer") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that.\n");
return 1; }
if(this_player()->query_money() < c) {
write("You can't afford that!\n");
return 1; }
TP->add_money(-c); 
write("You buy some beer.\n");
say(TPN+" buys some beer.\n");
MOCO("/players/jenny/bundy/items/beer.c"),TP);
return 1; }
}
