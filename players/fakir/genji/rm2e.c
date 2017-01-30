#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) 
{
    if(arg) return;
    found = 0;
    set_light(1);
    short_desc = "Square Room of Stone (Irridecent)";
    long_desc =
"   Walls of irridecent stone form a large, square, box-like room.  Within\n"+
"each wall, horned, fur coverd beings grapple in a frozen parody of combat.\n"+
"The still warriors stare without expression and silently strain to escape\n"+
"the imprisoning walls.  A stone 'square' hangs without support in the center\n"+
"of the room, and drips a thick fluid on the floor.  Two square doorways stand\n"+
"open within the stone walls.\n";
items = ({
"room",    "A large square room with walls of irridecent stone",
"wall",    "Built entirely of stone glowing irridecently.  Warriors are trapped inside",
"walls",   "Square in design, with sharp corners. They are made of irridecent stone",
"beings",  "Fur covered beings with large curved horns.",
"square",  "A square stone.  It flickers off and on with a dim light.\n"+
           "The square is cracked and drips an irridecent fluid on the stone floor.\n"+
           "You may try to 'turn' the square if you wish",
"stone",   "The stone glows dimmly irridecent, flickering with magic",
"doorways","Square doors that lead elsewhere",
});

dest_dir = ({
"/players/fakir/genji/rm5e","door1",
"/players/fakir/genji/rm2d","door2",
});
}

init()  
{
    ::init();
    add_action("turn_square","turn");
}

turn_square(arg)  
{
    if(!arg || arg != "square") 
    {
      notify_fail("\nMany voices speak as one:\n\n"+
                  BROWN+"You did not turn that which was intended.  Try again.\n"+OFF);
      return 0; 
    }
    if(found==0) 
    { 
      write("You turn the square and a small amount of fluid sticks to your fingers.\n");
      say(this_player()->query_name() + " turns the square.\n");
      call_out("turn_square2", 5); 
      found = 1;
    }
    else
    {
      write("You turn the square and a drop of fluid sticks to the tip of your finger.\n");
      say(this_player()->query_name() + " turns the square.\n");
    }
      return 1;
}

turn_square2(object who)
{
    tell_room(this_object(),
     "\nA bell chimes and many voices speak as one...\n\n" +
BROWN+"      'The square has been damaged.  Its magic flows from within\n"+
"       and cannot be replaced.  You must leave now, lest it harm you.'\n\n\n"+
    OFF);
    
    call_out("turn_square3", 6);
}

turn_square3()
{
    tell_room(this_object(), BOLD+MAGENTA+ "\
        A creeper of mist swirls out from within the square and circles your feet...\n\n" + OFF);

    call_out("turn_square4", 8);
}

turn_square4()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    The mist grows dark and thickens into the shape of a snake...\n\n\n"+OFF);

    call_out("turn_square5", 8);
}

turn_square5()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    The mist-snake coils about your leg, inching up your body...\n\n"+
"\t    You feel an enormous pressure begin to build in your muscles...\n\n\n"+OFF);    

     call_out("turn_square6", 8);
}

turn_square6()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    The mist-snake tightens its coils, curling in upon itself...\n\n"+
"\t    Your breath comes in ragged gasps...\n\n\n"+OFF);

     call_out("turn_square7", 10);
}

turn_square7() 
{
    tell_room(this_object(), "\
A bell chimes and many voices speak as one...\n\n"+
BROWN+"  'You did not run.  You are either very brave or very foolish...at any\n"+
"   rate, WE shall reward you.  To ascend the tower stairway, you must remember...'\n\n"+OFF);

      call_out("turn_square8", 5);
}

turn_square8()
{
     tell_room(this_object(), "\
A bell chimes and many voices speak a final time...\n\n"+
BROWN+"  'The key word is 'valor'.  Speak it and the terangreal shall allow\n"+
"   you to pass by unharmed.  To forget the key word is certain death...'\n\n"+OFF);

}