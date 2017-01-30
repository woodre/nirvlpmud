inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
string creator;
reset(arg){

  creator = "test";
  set_short("A piece of an ancient talisman");
  set_long(
"This is a piece of a very ancient talisman.  It has some strange\n"+
"carvings in its surface which make no sense to you.\n");
  set_weight(0);
  set_value(4862);
}

id(str){ return str == "piece" || str == "talisman" ||
           str == "zeus_talisman_piece"; }

fk(){ destruct(this_object()); }

set_creator(x){ creator = x; }
query_creator(){ return creator; }
query_save_flag(){    return 1; }

