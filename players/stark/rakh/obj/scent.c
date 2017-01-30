#include "/players/stark/defs.h"
inherit "/obj/treasure.c"/
string number;
object owner;

reset(arg) {
  if(arg) return;
  set_id("rakh_scent");
  number="";
  owner=TO;
}

get(){return 1;}
short(){
if(TP==owner){ return "Your scent has been left here"+number; }
if(present("rakh_guild",TP) && TP!=owner){ return "A Rakhene scent has been left here"+number; }
}
set_number(string num){ number=num; }
set_owner(object ob){ owner=ob; }
