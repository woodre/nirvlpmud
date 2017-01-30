inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short(HIY+"A FallenShout[pill]"+NORM);
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill"; }

  init(){
  ::init();
  add_action("swallow_pill", "fc");
}


swallow_pill(str){
object *a;
int b,c;
a = users();
b = sizeof(a);
if(TP->query_level() < 50) return 0;
if(!str) return 0;
for(c = 0; c < b; c++){
  if(environment(a[c]) && a[c]->query_guild_name() == "fallen")
    tell_object(a[c], TP->QN+" FallenShouts: "+HIY+str+NORM+"\n");
}
  write("You FallenShout: "+HIY+str+NORM+"\n");
return 1; }
