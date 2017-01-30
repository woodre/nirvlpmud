#include "/players/mythos/closed/ansi.h"
id(str) {return str == "prevent"; }
		
get() {return 0; }
drop() {return 1;}

query_weight() {return 0;}
query_value() {return 0; }

init() {
  add_action("nope","applaud");
  add_action("nope","blush");
  add_action("nope","bounce");
  add_action("nope","bow");
  add_action("nope","cackle");
  add_action("nope","chuckle");
  add_action("nope","clap");
  add_action("nope","cuddle");
  add_action("nope","curtsey");
  add_action("nope","dance");
  add_action("nope","french");
  add_action("nope","groan");
  add_action("nope","hiccup");
  add_action("nope","kick");
  add_action("nope","knee");
  add_action("nope","sing");
  add_action("nope","slap");
  add_action("nope","snap");
  add_action("nope","twiddle");
  add_action("nope","whistle");
  add_action("nope","dkiss");
  add_action("nope","grope");
  add_action("nope","flash");
  add_action("nope","point");
  add_action("nope","spank");
  add_action("nope","high5");
  add_action("nope","goose");
  add_action("nope","noogie");
  add_action("nope","headlock");
  add_action("nope","flipoff");

  call_out("check",50);
}

nope() { 
write("You can not do that while shapechanged!\n"); return 1;}

check() {
if(environment(this_object()))
move_object(this_object(),environment(this_object()));
else return 1;
 call_out("check",50);
return 1;} 
