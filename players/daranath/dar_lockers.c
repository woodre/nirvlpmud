#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"The Phoenix Inn"+NORM+")");
long_desc =
"A small, octagonal chamber used to store armor and weapons here within the City\n"+
"of Qual'tor. A variety of lockers line the walls, each with a small tag\n"+
"showing ownership of the items within.\n"+
"A small sign on the far wall shows how to use the lockers.\n";

dest_dir = ({
"/players/daranath/qualtor/newstuff/pheonix.c","west",
});

}

init(){
::init();
add_action("withdraw","withdraw");
add_action("list", "list");
add_action("deposit","deposit");
add_action("buylocker","buy");
add_action("read_stuff","read");
add_action("search","search");
}

deposit(str){
"/players/catwoman/tl.c"->deposit_item(str);
return 1;
}
buylocker(str){
"/players/catwoman/tl.c"->buy_locker(str);
return 1;
}
list(){
"/players/catwoman/tl.c"->list();
return 1;
}
withdraw(str){
"/players/catwoman/tl.c"->withdraw_item(str);
return 1;
}
  
read_stuff(str) {
  if(!str) {write("What do you want to read? (sign/disclaimer)\n"); return 1; }

if(str == "disclaimer") {
write("Locker code property of Catwoman and placed here by Daranath for the\n"+
      "convinience of players across the land.\n");
write("Items stored here will appear within all other locker rooms throughout Nirvana.\n");
write("You can only have a maximum of 10 spaces, no matter how many locker rooms\n"+
      "     you find across Nirvana.\n");
return 1; }
if(str == "sign") {
write("Instructions for using the locker room:\n\n");
write("buy locker        - purchase a new locker if you don't already have one,\n");
write("                    or purchase one more item of storage space, up to 10.\n");
write("withdraw <item>   - withdraws <item> from your locker.\n");
write("deposit <item>    - deposits <item> from your inventory into your locker.\n");
write("clear <item>      - clears out locker space.\n");
write("list              - lists all items in your locker.\n");
write("\n");
write("There is a small disclaimer on the bottom of the sign.\n");
write("\n");
return 1; }
return 0; 
}

search() {
write("There is not much to search with the Phoenix Inn.\n");
return 1; 
}

