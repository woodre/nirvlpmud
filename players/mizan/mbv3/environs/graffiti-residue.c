#include "/obj/ansi.h"

id(str)
{
   return str == "graffiti" || str =="paint" || str == "splotch"; 
}

short()
{
   return HIG + "Some graffiti sprayed on the ground" + NORM; 
}

long() 
{
   write("This a truly large and hideously tagged out array of text done in\n"+
         "a very bright and gaudy green Krylon paint. It reads:\n\n"+
         HIG + "Monsters' Guild Owns This Place.\n" + NORM);
}

reset()
{
    remove_call_out("erase_me");
    call_out("erase_me", 1800);
}

erase_me()
{
    say("The green graffit fades away in the wind.\n");
    destruct(this_object());
    return 1;
}

get()
{
    return 0;
}