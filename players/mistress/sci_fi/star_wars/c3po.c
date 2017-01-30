#include "std.h"
#include "living.h"
int found;
object robot;
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/star_wars/exit.c","west",
    "C3PO",
    "\n" +
    "You've found an obscure little hallway.  It seems to be a good place\n" +
    "to hide...  Maybe the golden one (what's his name??  Oh yeah,  C3PO)\n" +
    "likes to hide here.\n",1)
 
extra_init() {
     add_action("search","search");
     add_action("enter","enter");
     }
 
search(a) {
     if (a == "carefully") {found = 1;
     write("The back wall slowly fades away to reveal a secret passage. \n");
     write("You can probably enter the room from here. \n"); 
     return 1;}
     else
     write("You have found a secret room to the north.\n");
         add_action("north","north");
         add_action("north","n");
     return 1; }
 
north() {
     call_other(this_player(),"move_player"," the room#players/mistress/other/wrong.c"); 
     return 1; }
 
enter(a) {
     if ((a=="room"||a=="the room") && found==1) {
     call_other(this_player(),"move_player"," the room#players/mistress/other/heal.c");}
     found = 0;
     return 1; }
 
extra_reset()
{
if (!robot || !living(robot) )
{
 
robot = clone_object("obj/monster");
call_other(robot, "set_name", "C3PO");
call_other(robot, "set_ac", 5);
call_other(robot, "set_wc", 11);
call_other(robot, "set_hp", 200);
call_other(robot, "set_al", 1);
call_other(robot, "set_short", "C3PO");
call_other(robot, "set_alias", "c3po");
call_other(robot, "set_long", "The Golden One.\n");
call_other(robot, "set_race", "robot");
call_other(robot, "set_alt_name", "robot");
call_other(robot, "set_aggressive", 0);
call_other(robot, "add_money", 200);
call_other(robot, "set_whimpy",1);
call_other(robot, "set_level", 6);
move_object(robot, this_object() );
}
}
