inherit "obj/monster.talk";
#include "security.h"
#include "living.h"
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("man");
set_short("man");
set_long("This old man is built like a brick and a lot tougher than he looks.\n");
set_al(0);
set_level(8);
set_wc(12);
set_hp(375);
set_ac(7);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(300+(random(20)));
move_object(coins,this_object());
}
catch_tell(str){
object from;
string a;
string b;
string c;
object next_dest;
string next_out;
from = this_player();
if (!from)
return;
        if (sscanf(str, "%s gives %s to Man.", a, b) == 2){
        object ob;
        ob = present(b, this_object());
        if (!ob || !call_other(ob,"id", "chisel"))
                return;
        write("Man says: I was wondering where I put that.  You solved the quest.\n");
        next_dest = from;
        set_heart_beat(1);
        call_other(from, "set_quest", "chisel");
        destruct(ob);
        return;
}
}

