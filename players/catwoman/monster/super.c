inherit "obj/monster.talk";
#include "security.h"
#include "living.h"
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("superman");
set_short("Superman");
set_long("This Is Superman. he carries money for pay phone booths\n");
set_al(1000);
set_level(25);
set_wc(35);
set_hp(1000);
set_ac(20);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(4000 + random(1000));
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
        if (sscanf(str, "%s gives %s to Superman.", a, b) == 2){
        object ob,ob2;
	ob2 = this_object();
        ob = present(b, this_object());
        if (!ob || !call_other(ob,"id", "krypto"))
                return;
        write("Superman screams in pain.\n");
        next_dest = from;
        set_heart_beat(1);
        call_other(from, "set_quest", "super");
        destruct(ob);
	destruct(ob2);
/*	write_file("/players/catwoman/closed/quest_log",from->query_name()+" solved the quest on "ctime(time())+".\n");*/
        return;
}
}
