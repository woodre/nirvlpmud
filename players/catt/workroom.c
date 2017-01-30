
/***********************GENERIC WORKROOM***********************************
                  by Deathmonger (elof.iit.edu 3500)
                  email florste@karl.iit.edu

This is intended to be a simple workroom for wizards who have never
seen LPC before.
******************************************************************************/
#include "std.h"
#include "/players/catt/AREAS/base_defines.c"
/*  Refers the program to a "std.h" file, a basic room set up   */

reset(arg){
     if(!arg){ set_light(3);}
                 
}
/*  Sets what the room will do at reset(In this case, make it a lighted room)  )*/

init(){
/*  A very important basic function.  All of the actions that this room
does are put in this function.  */

     add_action("exit_castle1","portal");
     add_action("exit_shop","shop");

/*   This links a command (In this case, an exit) with a function.  When
you type "shop", the room goes to the init() function, looks for "shop",
and then goes to the function which is defined later in the program.
*/
     add_action("exit_guard_room1","stairs");
     add_action("exit_church","church");
     add_action("exit_wendys","wendys");
    add_action("exit_buddha","buddha");
}
/*    You can add more exits and functions later by adding an add_action()
line in the init() function and defining the function later.
*/

exit_shop(){
     call_other(this_player(), "move_player",
       "shop#room/shop");
     return 1;
}
exit_buddha() {
   call_other(this_player(), "move_player",
     "buddha#players/buddha/workroom.c");
   return 1;
}
exit_wendys() {
      call_other(this_player(), "move_player", 
      "wendys#players/wendy/workroom");
  return 1;
}
exit_castle1() {
      call_other(this_player(), "move_player",
         "valley1#"+VALLEY+"valley1");
      return 1;
}
exit_guard_room1() {

     call_other(this_player(), "move_player",
                  "guard_room1#/players/catt/guard_room1");

     return 1;

}

exit_church(){
     call_other(this_player(), "move_player",
       "church#room/church");
     return 1;
}


/*  Above, we see the init() functions defined.    */
short(){ return "catts study"; }

/*   You can change it     */
long(){
     write("this is catt's study and workroom. It is situated a top\n");
     write("a great tower of immense size. \n");
     write("There are only 3 ways to leave: shop, church, stairs, portal\n");
}
/*    I'm sure you'll want to change that    */
