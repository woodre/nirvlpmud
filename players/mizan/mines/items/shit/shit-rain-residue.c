#include "/players/mizan/esc.h"
string chat_msgs;

id(str) { return str == "shit-rain-residue"; }

reset()
{
    remove_call_out("erase_me");
    remove_call_out("random_chat");

    call_out("erase_me", 20);
    call_out("random_chat", 4);
}

erase_me()
{
   say("It appears that the fecal storm has ended.\n");
    destruct(this_object());
    return 1;
}

random_chat()
{

    if(!chat_msgs)
    {
        chat_msgs = ({
            "Sput. Sput. Sput.\n\nFist sized chunks of fecal goodness fall from the sky around you.",
            "Sput. Sput. Sput.",
            "You cringe as the remnants of a shower of semi-liquid buttsauce splatter\nlike little used jelly doughnut symphony in surround sound.",
            "Sput. Sput.",
            "You narrowly dodge a baby-head sized lump of fecal asteroid.\nIt explodes on impact.",
            "Fragments of molten shit rain from the sky.",
        });
    }

    if(1 == random(3) && environment())
    {
       move_object(clone_object("/players/mizan/etheriel/items/shit.c"), environment());      
    }

    if(environment(this_object()))
    {
        say(chat_msgs[random(sizeof(chat_msgs))] + "\n\n");
    }


     remove_call_out("random_chat");
     call_out("random_chat", 4);

}