#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";
int x=0;
reset(int arg) {
    if(arg) return;
    set_id("ring_piece5");
    set_alias("stone");
    set_short("A small stone");
    set_long("This is a stone from a shattered ring.\n"+
             "If you had all five parts you might be\n"+
             "able to "+HIW+"piece"+NORM+" a full "+HIW+"ring together"+NORM+".\n");
set_value(900);
}
init() {
    ::init();
add_action("make_it","piece");
}
make_it(arg) {
  if(!arg) { write("Piece what?\n"); return 1; }
  if(arg == "ring together") {
        if(present("ring_piece1",this_player()) ) {
        x=x+1; }
        if(present("ring_piece2",this_player()) ) {
        x=x+1; }
        if(present("ring_piece3",this_player()) ) {
        x=x+1; }
        if(present("ring_piece4",this_player()) ) {
        x=x+1; }
        
if(x !=4) {
x=0;
write("What?\n");
return 1; }
if(x ==4) {
object blah, blah2, blah3, blah4, blah5;
blah = present("ring_piece1",TP);
blah2 = present("ring_piece2",TP);
blah3 = present("ring_piece3",TP);
blah4 = present("ring_piece4",TP);
write("You carfully place all the pieces together.\n"+
      "The pieces meld themselves into a ring!\n");
MOCO("/players/jaraxle/3rd/silence/items/ring.c"), this_player());
destruct(blah);
destruct(blah2);
destruct(blah3);
destruct(blah4);
destruct(this_object()); 
return 1; }
    }
}

