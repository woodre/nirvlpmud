#include <ansi.h>

#define RNUM 409
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "a large glacier";
set_light(1);
rtype = "glacier";
long_desc = 
"                [47;1mM[0m [47;1mM[0m [47;1mM[0m [1;37mn[0m [1;37mn[0m [47;1mM[0m [47;1mM[0m \n"+
"                [1;37mn[0m [47;1mM[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [47;1mM[0m    N\n"+
"                [1;37mn[0m [1;37mn[0m [1;37mn[0m [1;37mX[0m [36m#[0m [36m#[0m [1;37mn[0m   /|\n"+
"                [1;36m@[0m [1;36m@[0m [1;37mn[0m [1;36m@[0m [1;36m@[0m [36m#[0m [36m#[0m    | \n"+
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m [1;36m@[0m [36m#[0m [36m#[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/377.c","north",
"/players/vertebraker/cont/frostgard/378.c","northeast",
"/players/vertebraker/cont/frostgard/376.c","northwest",
"/players/vertebraker/cont/frostgard/441.c","south",
"/players/vertebraker/cont/frostgard/442.c","southeast",
"/players/vertebraker/cont/frostgard/440.c","southwest",
"/players/vertebraker/cont/frostgard/410.c","east",
"/players/vertebraker/cont/frostgard/408.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
