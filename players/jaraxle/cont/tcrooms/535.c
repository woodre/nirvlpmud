#include "/players/jaraxle/ansi.h"
#define RNUM 535
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m \n"+
"                [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31mX[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/503.c","north",
"/players/jaraxle/cont/tcrooms/504.c","northeast",
"/players/jaraxle/cont/tcrooms/502.c","northwest",
"/players/jaraxle/cont/tcrooms/567.c","south",
"/players/jaraxle/cont/tcrooms/568.c","southeast",
"/players/jaraxle/cont/tcrooms/566.c","southwest",
"/players/jaraxle/cont/tcrooms/534.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
