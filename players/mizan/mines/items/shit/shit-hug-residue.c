#include "/players/mizan/esc.h"

id(str) { return str == "stains" || str == "stains-shit-huggedon"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + "'s chest and face have fecal brown hug-marks";
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
