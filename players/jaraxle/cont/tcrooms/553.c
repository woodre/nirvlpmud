#include "/players/jaraxle/ansi.h"
#define RNUM 553
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m \n"+
"                [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m    N\n"+
"                [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;31mX[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m   /|\n"+
"                [1mM[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n"+
"                [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/521.c","north",
"/players/jaraxle/cont/tcrooms/522.c","northeast",
"/players/jaraxle/cont/tcrooms/520.c","northwest",
"/players/jaraxle/cont/tcrooms/585.c","south",
"/players/jaraxle/cont/tcrooms/586.c","southeast",
"/players/jaraxle/cont/tcrooms/554.c","east",
"/players/jaraxle/cont/tcrooms/552.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
