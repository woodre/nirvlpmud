#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";


reset(arg){
    if (arg) return;
   

set_id("flier");
  set_alias("flier");
set_short(HIW+"A flier from Francesco"+NORM);
set_long("The flier is made by one single page, you can read it.\n");

}


init() {
  ::init();
    add_action("read_book","read");
    add_action("application","apply");
if(this_player() != environment(this_object())) 
  return; 
}

read_book(stri) {
     if (!stri) {write("Read what?\n");return 1;}
     if(stri == "flier") {
     write("   A new tournament is launched!  \n"+
           "It is based on the largest number of kaleidoscopes gotten within a reboot.\n"+
           "As you might know already, nobody knows the exact number of the kaleido-\n"+
           "scopes within the area, neither is known the quality of those items (either\n"+
           "white, blue or yellow).  So, i wondered what would be the maximum attainable.\n"+
           "And then, why not make it a challenge?  Those three who will get the most\n"+
           "kaleidoscopes within one reboot will share the money coming from the other\n"+
           "competitors in the tournament (plus some more gifted by the administrators).\n"+
           "In the evaluation of the personal scores, both the number and the type of\n"+
           "the kaleidoscopes gotten _within_ one reboot will be taken in to account.\n"+
           "You can 'apply tournament' here, for the small fee of 2000 coins.  You can\n"+
           "put mutiple applications during the week, but only the best performance will\n"+
           "be considered for the prizes.\n"+
           "The tournament will be held on a weekly basis, starting from Monday morning\n"+
           "reboot through the next Monday, same time.  Prizes will be awarded later.  \n"+
           "During the tournament some info will be posted on a regular basis in this room.\n"+
           "Hope you enjoy this new challenge brought to you on Nirvana.\n"+
           "\n                                       fran\n");
     return 1; }
return 1;}


apply(str){return 1;}

get(stri) {
    if(stri == "flier") {
        notify_fail("Please, dont remove the flier from this room.  It would fail its goal.\n");
        return 0;
    }
    return 0;
}
