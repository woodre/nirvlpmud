#include "/players/jaraxle/ansi.h"
#define RNUM 408
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1mM[2;37;0m \n"+
"                [33mn[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31mX[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/376.c","north",
"/players/jaraxle/cont/tcrooms/377.c","northeast",
"/players/jaraxle/cont/tcrooms/440.c","south",
"/players/jaraxle/cont/tcrooms/441.c","southeast",
"/players/jaraxle/cont/tcrooms/439.c","southwest",
"/players/jaraxle/cont/tcrooms/409.c","east",
"/players/jaraxle/cont/tcrooms/407.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
