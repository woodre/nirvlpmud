#include "/players/jenny/define.h"
main(string name) {
    object ob;
    if(TPL < 40) {write("Fuck you.  You're not a wiz.\n"); return 1; }
if(!name) {notify_fail("huh?\n"); return 0; }
    ob = find_living(name);
        if (!ob) {
        write("They are not here.\n");
        return 1; }
call_other("/obj/partymaster.c","PartyStatus",name);
return 1; }
