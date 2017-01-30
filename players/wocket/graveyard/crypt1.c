#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/groom.c";

reset(arg){
  ::reset(arg);
if(!present("mummy"))
if(random(2) == 1){
move_object(clone_object("/players/wocket/graveyard/mummy.c"),this_object());
}
  if(arg) return ;

set_light(1);
short_desc = BLU+"A Dryant Crypt"+NORM;
long_desc = ""+
"   There are bodies of dead dryants laying everywhere.  A horrible stench\n"+
"fills the air.  Some bodies have been layed to rest and positioned properly\n"+
"while others have merely been tossed upon the heap of others.  The room\n"+
"itself is made of stone but dirt has since covered the walls giving\n"+
"almost a cave like appearance.\n";

items = ({
  "bodies","They are partially decomposed, with torn clothes",
  "walls","They are made of stone and covered with dirt",
"dirt","It is grey in color and covers the walls and floors",
  "heap","Many killed dryants have been tossed in the crypt with no proper burial, forming\na heap of bodies",
  "stone","The stone can barely be seen through the encrusted dirt",
});
dest_dir = ({
  PATH+"crypt2.c","down",
  PATH+"gr13.c","out",
});

smells = ({
  "default","A horrible stench fills the air",
  "stench","It is a foul stench that is emmitted from the rotting flesh of the\nexposed dryants",
});
}

init(){
  ::init();
    add_action("search","search");
remove_call_out("getweather");
}

search(){
  write("You find nothing of interest.\n");
return 1;
}
