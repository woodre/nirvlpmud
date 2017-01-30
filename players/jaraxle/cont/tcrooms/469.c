#include "/players/jaraxle/ansi.h"
#define RNUM 469
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m \n"+
"                [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31mX[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1mM[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/437.c","north",
"/players/jaraxle/cont/tcrooms/438.c","northeast",
"/players/jaraxle/cont/tcrooms/436.c","northwest",
"/players/jaraxle/cont/tcrooms/501.c","south",
"/players/jaraxle/cont/tcrooms/502.c","southeast",
"/players/jaraxle/cont/tcrooms/500.c","southwest",
"/players/jaraxle/cont/tcrooms/470.c","east",
"/players/jaraxle/cont/tcrooms/468.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
