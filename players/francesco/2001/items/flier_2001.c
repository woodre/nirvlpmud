#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";


reset(arg){
    if (arg) return;
   

set_id("flier");
  set_alias("flier");
set_short(HIW+"A flier from Francesco"+NORM);
set_long("The flier is made by one single page, you can view it.\n");

}


init() {
  ::init();
    add_action("read_book","view");
if(this_player() != environment(this_object())) 
  return; 
}

read_book(stri) {
     if (!stri) {notify_fail("Read what?\n");return 0;}
     if(stri == "flier") {
     write("As you might know already, I am not native english and this makes it\n"+
           "difficult to write fluent, clear, gramatically correct descriptions\n"+
           "of the things I did code.  To the aim of improving this area, I would \n"+
           "gratefully acknowledge whomever would be so kind to submit revised \n"+
           "descriptions of the items in the area, of the rooms, of the narrations, \n"+
           "of the actions made, whatever you might find changeable and improvable, \n"+
           "including bugs, typoes, obscure sentences etc etc.  I can promise that \n"+
           "every advices will be read and evaluated, with the sole limit that the\n"+
           "proposals must still fit the theme of the area.  Those who will be \n"+
           "accepted will be acknowledged in a plaque in the cinema lobby.\n"+
           "Thank you.\n"+
           "Fran\n");
     return 1; }
return 1;}

get(stri) {
    if(stri == "flier") {
        notify_fail("Please, dont remove the flier from this room.  It would fail its goal.\n");
        return 0;
    }
    return 0;
}
