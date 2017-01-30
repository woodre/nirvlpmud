
/***********************GENERIC WORKROOM***********************************
                  by Deathmonger (elof.iit.edu 3500)
                  email florste@karl.iit.edu

This is intended to be a simple workroom for wizards who have never
seen LPC before.
******************************************************************************/
#include "std.h"
/*  Refers the program to a "std.h" file, a basic room set up   */

reset(arg){
     if(!arg){
     set_light(1);
     }
}
/*  Sets what the room will do at reset(In this case, make it a lighted room)  )*/

init(){
/*  A very important basic function.  All of the actions that this room
does are put in this function.  */

     add_action("exit_shop","shop");
/*   This links a command (In this case, an exit) with a function.  When
you type "shop", the room goes to the init() function, looks for "shop",
and then goes to the function which is defined later in the program.
*/
     add_action("exit_church","church");
}
/*    You can add more exits and functions later by adding an add_action()
line in the init() function and defining the function later.
*/

exit_shop(){
     call_other(this_player(), "move_player",
       "shop#room/shop");
     return 1;
}

exit_church(){
     call_other(this_player(), "move_player",
       "church#room/church");
     return 1;
}


/*  Above, we see the init() functions defined.    */
short(){ return "Bagera's Den"; }

/*   You can change it     */
long(){
	write("This is the den of a great Panthyre. You can see that\n");
	write("the walls are made of a black obsidian. The floor is\n");
	write("made of a black marble. On the far wall you\n");
	write("see an immense fireplace that is lit and glowing bright.\n");
	write("The fire seems to be alive dancing and popping, casting\n");
	write("shadows on the dark walls. There are various size\n");
	write(" pillows strewn over the floor. You see two huge\n");
	write("panthers pacing in depths of the shadows. They are\n");
	write("here to guard and protect their mistress from harm.\n");
     write("There are two obvious exits: shop and church\n");
}
/*    I'm sure you'll want to change that    */
