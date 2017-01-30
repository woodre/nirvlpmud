#include "/players/mizan/esc.h"

id(str) { return str == "stains"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + " is covered completely with a a nasty green stain";
}

reset()
{
    remove_call_out("erase_me");
    call_out("erase_me", 2000);
}

erase_me()
{
    destruct(this_object());
    return 1;
}