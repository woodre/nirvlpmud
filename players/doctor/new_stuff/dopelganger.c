#include "living.h"
reset(arg)
{
    if (arg) {
       return;
       }
    max_hp = 200;
    hit_point = 200;
    level = 10;
    experience = 39000;
    weapon_class = 5;
    is_npc = 1;
    name = "dopelganger";
    cap_name = "Dopelganger";
    alignment = 0;
    enable_commands();
    move_object(this_object(),"players/doctor/workroom");
}

short() {
   return call_other(this_player(),"query_name");
}

long() {
    call_other(this_player(),"long");
}

id(str) { return str == name; }
