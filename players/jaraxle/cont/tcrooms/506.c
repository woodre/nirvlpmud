#include "/players/jaraxle/ansi.h"
#define RNUM 506
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [1;32m@[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    N\n"+
"                [32m#[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;31mX[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m   /|\n"+
"                [33mn[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [32m#[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/474.c","north",
"/players/jaraxle/cont/tcrooms/475.c","northeast",
"/players/jaraxle/cont/tcrooms/473.c","northwest",
"/players/jaraxle/cont/tcrooms/538.c","south",
"/players/jaraxle/cont/tcrooms/539.c","southeast",
"/players/jaraxle/cont/tcrooms/537.c","southwest",
"/players/jaraxle/cont/tcrooms/507.c","east",
"/players/jaraxle/cont/tcrooms/505.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
