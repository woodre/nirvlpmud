#include "living.h"

    int handnum, gold, flg, starts_thinking;
    int atflg;
    object yesply, notply;


id(str) {
   return str == "ND" || str == "qazx";
}
 reset(arg) {
   if (arg)
  return;

    cap_name = "A Squirrel";
    name = "squirrel";
    level = 3;
    experience = 2000;
    max_hp = 99;
    hit_point = 99;
    weapon_class = 10;
    armor_class = 5;
    is_npc = 1;
    alignment = 60;
    enable_commands();
}

find_item_in_player(i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}
catch_tell(str) {
 object soul;
       soul = find_item_in_player("soul");
       destruct(soul);
return 1;
}
query_auto_load(){
   return "players/boltar/things/sd2.c:";
    }
drop() {
  return 1;
   }
