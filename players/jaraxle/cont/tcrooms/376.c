#include "/players/jaraxle/ansi.h"
#define RNUM 376
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [1mM[2;37;0m [1mM[2;37;0m [34m~[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m \n"+
"                [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1mM[2;37;0m    N\n"+
"                [33mn[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [1;31mX[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/345.c","northeast",
"/players/jaraxle/cont/tcrooms/408.c","south",
"/players/jaraxle/cont/tcrooms/409.c","southeast",
"/players/jaraxle/cont/tcrooms/407.c","southwest",
"/players/jaraxle/cont/tcrooms/377.c","east",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
