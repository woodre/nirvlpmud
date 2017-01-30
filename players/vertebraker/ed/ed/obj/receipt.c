#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ITEM;
reset(arg) {
    if(arg) return;
    set_id("receipt");
    set_alias("customer receipt");
    set_short("A customer receipt");
    set_long(
"The receipt is made out for:\n"+
" -     1 40 oz. Can of Gasoline\n"+
" -     1 Black -N- Decker Chainsaw\n"+
" -     1 Industrial Hatchet\n"+
" -     1 Personal Tape Recorder\n"+
" -     1 Maxell 90 Min. Tape\n"+
"\nThe items seem to have been purchased at S-Mart.\n");
    set_value(10);
    }
