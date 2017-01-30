#include <ansi.h>

#define RNUM 345
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "ice hill";
set_light(1);
rtype = "icy hill";
long_desc = 
"                [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m \n"+
"                [47;1mM[0m [34m~[0m [47;1mM[0m [47;1mM[0m [47;1mM[0m [47;1mM[0m [34m~[0m    N\n"+
"                [47;1mM[0m [47;1mM[0m [47;1mM[0m [1;37mX[0m [1;37mn[0m [47;1mM[0m [47;1mM[0m   /|\n"+
"                [1;37mn[0m [47;1mM[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [47;1mM[0m    | \n"+
"                [1;37mn[0m [1;37mn[0m [1;37mn[0m [36m#[0m [36m#[0m [36m#[0m [1;37mn[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/377.c","south",
"/players/vertebraker/cont/frostgard/378.c","southeast",
"/players/vertebraker/cont/frostgard/376.c","southwest",
"/players/vertebraker/cont/frostgard/346.c","east",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
