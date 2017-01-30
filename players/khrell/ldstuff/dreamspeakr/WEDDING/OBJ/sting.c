#include "/players/dreamspeakr/closed/ansi.h"
string own;

int id (string str ) { return str == "sting";}

reset(arg){
   if(arg) return;
   call_out("loose_it",500);
}
   
string extra_look() {
   return (own+" has some pretty "+HIR+"red stripes"+NORM+" on "+environment(this_object())->query_possessive()+" bottom.  It appears that "+environment(this_object())->query_pronoun()+" has been whipped with a cat of nine tails recently.\n");
   }

loose_it() {
   destruct(this_object());
}

void init(){
  if ( !own ) {
       own= (string)this_player()->query_real_name();
       own = capitalize(own);
     }
}
query_save_flag() { return 1; }