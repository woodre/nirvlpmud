#include <ansi.h>

#define RNUM 501
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "a large glacier";
set_light(1);
rtype = "glacier";
long_desc = 
"                [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m \n"+
"                [1;36m@[0m [1;36m@[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    N\n"+
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mX[0m [36m#[0m [36m#[0m [1;37mn[0m   /|\n"+
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m [1;37mn[0m [47;1mM[0m    | \n"+
"                [1;36m@[0m [1;36m@[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [1;37mn[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/469.c","north",
"/players/vertebraker/cont/frostgard/470.c","northeast",
"/players/vertebraker/cont/frostgard/468.c","northwest",
"/players/vertebraker/cont/frostgard/533.c","south",
"/players/vertebraker/cont/frostgard/534.c","southeast",
"/players/vertebraker/cont/frostgard/532.c","southwest",
"/players/vertebraker/cont/frostgard/502.c","east",
"/players/vertebraker/cont/frostgard/500.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
