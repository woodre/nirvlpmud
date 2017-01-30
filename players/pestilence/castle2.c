#define NAME "Pestilence"
#define DEST "room/south/sforst7"
#include <ansi.h>
#define TP this_player()

id(str) { return str == "hall" || str == "hall of images"; }

short() {
    return ""+HIR+"Hall of Images"+NORM+"";
}

long() {
    write("The "+HIR+"Hall"+NORM+" is a large building with no windows\n");
    write("on the outside. There is only a door on the outside of the building.\n");
    write("Great adventures await those who will enter this hall.\n");


}
init () {
     add_action ("enter_hall","enter");
     }

enter_hall(str) {
   if(str != "hall") { write("Enter what?\n");
       return 1;}
     write("The "+HIR+"Hall of Images"+NORM+" is under construction.\n");
     return 1;}

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);

/*  Add autoload objects  */
/*
     ------ 9-19 verte commented out, it's buggy -----
*/
clone_object("/players/pestilence/closed/dark/dark.c");
"/players/pestilence/closed/dark/dark.c"->load_it();


}
is_castle(){return 1;}
