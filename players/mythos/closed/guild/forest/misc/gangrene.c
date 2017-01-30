/*
 *    The disease gangrene...  - mythos
 *
 *    To destory, simply <dest gangrene>
 *
 */

#include "/obj/clean.c"
#include "/players/mythos/closed/guild/def.h"

string name;
int time;

id(str)  { return str == "gangrene" || str == "infection";  }

get()    { return 0;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/mythos/closed/guild/forest/misc/gangrene.c:"; }

reset(arg) {
if(arg) return;
call_out("disease_check",3);
}

init()  {
if(tl > 20 || !living(tp) || tp->query_npc() || present(fear,tp))  { 
destruct(this_object()); return 1;}
name = epn;
if(!restore_object("players/mythos/closed/guild/forest/misc/gan/"+name)) {
time = 0; }
if(time > 20) { add_action("wwie","wield"); 
                add_action("wwie","wear");}
}

wwie() {
  write("Your wounds have festered too much! \n"+
        "You no longer can wield nor wear anything!\n"+
        "You need treatment fast for you have gangrene!\n");
return 1;}

disease_check()  {
if(ep->query_ghost()) { rm("/players/mythos/closed/guild/forest/misc/gan/"+name+".o");
                      destruct(this_object()); return 1;}
if(time > 1 && time < 6) { ep->add_hit_point(-1); }
if(time > 5 && time < 10) { ep->add_hit_point(-3-random(3)); }
if(time > 9) { ep->add_hit_point(-10 - random(10)); }
if(time == 1) { tell_object(ep,"Your wounds dont appear too healthy...\n"); }
if(time == 5) { tell_object(ep,"Your wounds look very very bad!\n"); }
if(time == 9) { tell_object(ep,"The smell of decay fumes from your wounds!\n"+
                               "Treatment may be a good idea!\n"); }
time = time + 1;
save_object("players/mythos/closed/guild/forest/misc/gan/"+name);
move_object(this_object(),ep);
call_out("disease_check",90);
return 1;}
