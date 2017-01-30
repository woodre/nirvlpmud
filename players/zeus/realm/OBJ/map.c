inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A tattered map");
  set_long(
"This is a tattered old map.  The corners are ripped and curling in\n"+
"numerous places, and it even looks as though there are some burn\n"+
"marks on it.  Even still, you could 'read' this ancient map.\n");
  set_weight(1);
  set_value(0);
}

  init(){
  ::init();
  add_action("read_cmd", "read");
}

id(str){ return str == "map" || str == "zeus_map"; }

status read_cmd(string str){
 if(!present(TO, TP)) return 0;
 if(str != "map") return 0;
 cat("/players/zeus/realm/doc/MAP");
 return 1; 
}
