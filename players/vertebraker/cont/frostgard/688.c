#include <ansi.h>

#define RNUM 688
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "ice hill";
set_light(1);
rtype = "icy hill";
long_desc = 
"                [36m#[0m [36m#[0m [34m~[0m [36m#[0m [1;36m@[0m [34m~[0m [34m~[0m \n"+
"                [34m~[0m [34m~[0m [36m#[0m [1;37mn[0m [36m#[0m [36m#[0m [34m~[0m    N\n"+
"                [34m~[0m [1;37mn[0m [36m#[0m [1;37mX[0m [1;37mn[0m [1;37mn[0m [34m~[0m   /|\n"+
"                [34m~[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [34m~[0m [34m~[0m    | \n"+
"                [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/656.c","north",
"/players/vertebraker/cont/frostgard/657.c","northeast",
"/players/vertebraker/cont/frostgard/655.c","northwest",
"/players/vertebraker/cont/frostgard/720.c","south",
"/players/vertebraker/cont/frostgard/721.c","southeast",
"/players/vertebraker/cont/frostgard/719.c","southwest",
"/players/vertebraker/cont/frostgard/689.c","east",
"/players/vertebraker/cont/frostgard/687.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
