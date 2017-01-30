#include "std.h"
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
extra_init() {
     add_action("find","find"); }
 
ONE_EXIT("players/mistress/sci_fi/read.c","south",
   "Ex-jaws",
   "\n" +
   "Looks like a disaster has struck this part of the library.  The carpet\n" +
   "appears to be permanently water damaged and there seems to evidence of\n" +
   "some kind of fighting (though how old one can`t tell).  From the books\n" +
   "scattered about you make a fair guess that you could might be able to FIND\n" +
   "SHARKS [yes, try typing that] in the vicinity.\n",1)
 
find(str) {
    if(str == "sharks") {
       write("\nNow you've done it!  Are you prepared for this?\n\n");
       call_other(this_player(),"move_player"," to find sharks#players/mistress/sci_fi/shark/enter.c");
       return 1; }
    }
