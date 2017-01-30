#include <ansi.h>
#define NAME "Dreamspeakr"
#define DEST "room/forest9"

id(str) { return str == "stairway"; }

short() {
    return "A stairway up to the "+HIB+"heavens"+NORM+"\n"+
             "A memorial to Dreamspeakr";
}

long() {
    write("A stairway that seems to go on forever.  Maybe you should \n"+
          "'"+HIB+"climb"+NORM+" it.\n");
}

init() {
    add_action("climb","climb");
    add_action("memorial","look");
    add_action("memorial","l");
    add_action("memorial","examine");
    add_action("memorial","exa");
    add_action("getin","enter");
}
getin(arg) {
if(!arg) { return 0;}
if(arg == "memorial" || arg == "the memorial") {
write("You start walking towards the memorial.\n");
this_player()->move_player("towards the memorial#players/jenny/memorial/field.c"); 
return 1;}}
memorial(arg) {
if(!arg) {return 0;}
if(arg == "memorial" || arg == "at memorial") {
write("A memorial in honor of dreamspeakr.  You can enter it and take\n"+
         "a look around.\n");
return 1;}}
climb(string str) {
    if (!str || str != "stairway"){
    notify_fail("What would you like to climb?\n");
    return 0;
    }

   write("\n"+
          "\n"+
          "You place your foot onto the stairway.....\n"+
          "     You begin climbing upwards...\n"+
          "\n"+
          "         Higher and higher....\n"+
          "\n"+
          "           The air becomes thinner....\n"+
          "               Beautiful "+HIW+"white clouds"+NORM+" surround you.....\n"+
          "\n"+
          "                    You arrive in a bright city in the heavens...\n"+
          "\n");
   say(this_player()->query_name()+" begins climbing the stairway.\n");
   move_object(this_player(),"/players/dreamspeakr/CASTLE/entrance.c");
   command("look",this_player());
   say(this_player()->query_name()+" climbs the stairway.\n");
   return 1;
   }

reset(arg) {
  move_object(this_object(),DEST);
  if(arg) return;
  call_other("/players/dreamspeakr/WEDDING/OBJ/wedding_ring.c","???");
}

is_castle(){return 1;}
