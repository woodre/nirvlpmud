#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) 
{
    if(arg) return;
    found = 0;
    set_light(-1);
    short_desc = "Crystal Oblong (Shadowed)";
    long_desc =
"   Shadowed crystal forms an oblong room without seam or joint.  Within the\n"+
"crystal walls, or perhaps as part of it, giant warriors stand in stationary\n"+
"relief.  Each warrior has become as stone, unmoving and frozen....shadowed as\n"+
"the wall which holds them.  A small, oblong 'crystal' floats in the center of\n"+
"the room.  Five doors glide in random motion about the wall.\n";

items = ({
"room",    "An oblong room with walls of shadowed crystal",
"warriors","Giant fighters with huge hands and towering bodies",
"walls",   "Really a single oblong wall of shadowed crystal which surrounds you on all sides",
"wall",    "Really a single oblong wall of shadowed crystal which surrounds you on all sides",
"crystal", "A small, floating oblong crystal. It is dark and cold to the touch.\n"+
           "You may 'invoke' the crystal if you desire, but it looks broken",
"doors",   "Oblong openings which glide about the wall in random directions",
});

dest_dir = ({
"/players/fakir/genji/rm5e","door1",
"/players/fakir/genji/rm3e","door2",
"/players/fakir/genji/rm2e","door3",
"/players/fakir/genji/rm6e","door4",
"/players/fakir/genji/rm5a","door5",
});
}

init()  
{
    ::init();
    add_action("invoke_crystal","invoke");
}

invoke_crystal(arg)  
{
    if(!arg || arg != "crystal") 
    {
      notify_fail(MAGENTA+"Try to invoke the crystal.\n"+OFF);
      return 0; 
    }
    if(found==0) 
    { 
      write("You invoke the crystal.\n");
      say(this_player()->query_name() + " invokes the crystal.\n");
      call_out("invoke_crystal2", 2); 
      found = 1;
    }
    else
    {
      write("You invoke the crystal and nothing happens.\n");
      say(this_player()->query_name() + " invokes the crystal.\n");
    }
      return 1;
}

invoke_crystal2(object who)
{
    tell_room(this_object(),
     "\nMany voices echo...\n\n" +
MAGENTA+"     'Our crystal was broken in some past age.  Its magic is lost, and\n"+
"      and lest we find a new warrior for our wall, will never return.'\n\n\n"+
    OFF);
    
    call_out("invoke_crystal3", 5);
}

invoke_crystal3()
{
    tell_room(this_object(), MAGENTA+ "\
     'We are sad now. Our enjoyment of the battles we watched are now only memories.'\n\n\n" + OFF);

    call_out("invoke_crystal4", 5);
}

invoke_crystal4()
{
    tell_room(this_object(), MAGENTA+"\
\     'Some were so grand!  If only our crystal had not gone dark...'\n\n\n"+OFF);

    call_out("invoke_crystal5", 5);
}

invoke_crystal5()
{
    tell_room(this_object(), MAGENTA+"\
\     'We could perhaps place you in our crystal wall, amongst the shadows,\n"+
"      to do battle with those who might come after....Are you a great warrior?'\n\n\n"+OFF);    

     call_out("invoke_crystal6", 5);
}

invoke_crystal6()
{
    tell_room(this_object(), MAGENTA+"\
     'No, you are not like the giants we enjoyed so much.  We shall let you go.'\n\n\n"+OFF);

     call_out("invoke_crystal7", 5);
}
invoke_crystal7()
{
    tell_room(this_object(), "\
The voices fade and become lost in the sounds of the tower.\n\n\n");

}