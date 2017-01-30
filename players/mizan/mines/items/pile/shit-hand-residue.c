#include "/players/mizan/esc.h"

id(str) { return str == "shit-hand-residue"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + " has shit stains all over " + 
                     environment()->query_possessive() + " hands";
}

reset()
{
    remove_call_out("erase_me");
    call_out("erase_me", 200);
}

erase_me()
{
    destruct(this_object());
    return 1;
}