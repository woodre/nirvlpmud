#include <ansi.h>

#define RNUM 557
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "a frozen bridge";
set_light(1);
rtype = "a frozen bridge";
long_desc = 
"                [1;36m@[0m [1;36m@[0m [36m#[0m [36m#[0m [36m#[0m [34m~[0m [34m~[0m \n"+
"                [1;36m@[0m [1;36m@[0m [36m#[0m [34m~[0m [34m~[0m [34m~[0m [36m#[0m    N\n"+
"                [36m#[0m [36m#[0m [36m#[0m [1;37mX[0m [36m#[0m [1;36m@[0m [1;36m@[0m   /|\n"+
"                [1;37mn[0m [34m~[0m [34m~[0m [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m    | \n"+
"                [34m~[0m [34m~[0m [34m~[0m [36m#[0m [36m#[0m [34m~[0m [36m#[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/524.c","northwest",
"/players/vertebraker/cont/frostgard/590.c","southeast",
"/players/vertebraker/cont/frostgard/558.c","east",
"/players/vertebraker/cont/frostgard/556.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
