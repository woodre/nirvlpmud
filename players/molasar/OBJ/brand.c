
string short, monster, owner;

id(str) { return str == "brand" || str == short; }

init_arg() {
   set_heart_beat(1);
   return 1;
}

short() { return short; }

set_short(sh) { short = sh; }

set_owner(ow) { owner = ow; }


set_monster(mo) { monster = mo; }

get() { destruct(this_object()); }


heart_beat() {
   if(find_player(monster)->query_hp() < 40) {
     tell_object(find_player(owner), "Your monster is dead.\n");
     set_heart_beat(0);
     destruct(this_object());
     return 1;
   }
}

