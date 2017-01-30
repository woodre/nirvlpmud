#include "/players/jaraxle/ansi.h"
#define RNUM 519
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [34m~[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m \n"+
"                [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;31mX[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m    | \n"+
"                [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/487.c","north",
"/players/jaraxle/cont/tcrooms/488.c","northeast",
"/players/jaraxle/cont/tcrooms/486.c","northwest",
"/players/jaraxle/cont/tcrooms/552.c","southeast",
"/players/jaraxle/cont/tcrooms/520.c","east",
"/players/jaraxle/cont/tcrooms/518.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
