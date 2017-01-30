#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) 
{
    if(arg) return;
    found = 0;
    set_light(-1);
    short_desc = "Square Room of Stone (Obscure)";
    long_desc =
"   Obscure stone walls form a box-like room.  Frozen within each wall,\n"+
"motionless warriors grip long handled axes and heavy mace-like weapons.\n"+
"They wear bands of gold and silver on each forearm, signifying rank or\n"+
"status.  The still warriors stare without expression and silently strain\n"+
"to escape the imprisoning walls.  A square stone 'ter'angreal' hangs in\n"+
"the center of the room without support.  Three square doorways slowly spin\n"+
"counter clock-wise within the stone walls.\n";
items = ({
"room",         "A square room with walls of obscure stone",
"walls",        "Square in design, with sharp corners. They are made of obscure stone",
"warriors",     "Broad shouldered and well built, with bands of gold and silver around each arm",
"bands",        "Precious gold and silver bands, hammered thin and braided for strength",
"ter'angreal",  "A square, stone ter'angreal once imbued with strange magics.\n"+
                "It is now fractured and broken...its magic gone.\n"+
                "You may try to 'turn' the ter'angreal if you wish",
"stone",        "Once glowing with a strange magic, the stone is now dark",
"doorways",     "Square, open doors that spin counter clock-wise at a slow but steady pace",
});

dest_dir = ({
"/players/fakir/genji/rm1d","door1",
"/players/fakir/genji/rm3d","door2",
"/players/fakir/genji/rm5d","door3",
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
      notify_fail("\nA harsh voice rumbles:\n\n"+
                  BROWN+"You have much to learn.  I pity you.\n"+OFF);
      return 0; 
    }
    if(found==0) 
    { 
      write("You turn the square.\n");
      say(this_player()->query_name() + " turns the square.\n");
      call_out("turn_square2", 2); 
       /* call the function 'turn_square2' in 2 seconds */
      found = 1;
    }
    else
    {
      write("You turn the square and nothing happens.\n");
      say(this_player()->query_name() + " turns the square.\n");
    }
      return 1;
}

turn_square2(object who)
{
    tell_room(this_object(),
     "\nA harsh voice rumbles...\n\n" +
BROWN+"      'The square was broken in some past age.  Its magic is lost and\n"+
"       will never return.  You may leave as you came...  Now begone.'\n\n\n"+
    OFF);
    
    call_out("turn_square3", 9);
}

turn_square3()
{
    tell_room(this_object(), BOLD+RED+ "\
        'I SAID BEGONE!  ELSE I SHALL TAKE THAT WHICH YOU HAVE GAINED!'\n\n" + OFF);

    call_out("turn_square4", 9);
}

turn_square4()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    A dark mist begins to form within the room...\n\n\n"+OFF);

    call_out("turn_square5", 5);
}

turn_square5()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    The mist begins to develop into fingers, climbing up\n"+
"\t    your legs toward your armors...searching...grasping...\n\n\n"+OFF);    

     call_out("turn_square6", 5);
}

turn_square6()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    You feel the cold fingers of mist grasp the straps of your armor..\n\n\n"+OFF);

     call_out("turn_square7", 5);
}
turn_square7()
{
    tell_room(this_object(), BOLD+MAGENTA+"\
\t    The fingers shrink back to mist...it swirls once about your feet and departs.\n\n\n"+OFF);

}