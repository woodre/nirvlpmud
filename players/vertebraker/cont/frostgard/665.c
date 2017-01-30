#include <ansi.h>

#define RNUM 665
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "a large glacier";
set_light(1);
rtype = "glacier";
long_desc = 
"                [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m \n"+
"                [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [34m~[0m [36m#[0m    N\n"+
"                [36m#[0m [36m#[0m [36m#[0m [1;37mX[0m [36m#[0m [36m#[0m [34m~[0m   /|\n"+
"                [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m    | \n"+
"                [36m#[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [34m~[0m [34m~[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/633.c","north",
"/players/vertebraker/cont/frostgard/634.c","northeast",
"/players/vertebraker/cont/frostgard/632.c","northwest",
"/players/vertebraker/cont/frostgard/697.c","south",
"/players/vertebraker/cont/frostgard/698.c","southeast",
"/players/vertebraker/cont/frostgard/696.c","southwest",
"/players/vertebraker/cont/frostgard/666.c","east",
"/players/vertebraker/cont/frostgard/664.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
