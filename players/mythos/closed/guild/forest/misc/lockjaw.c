/*
 *    The disease lockjaw...  - mythos
 *
 *    To destory, simply <dest lockjaw>
 *
 */

#include "/obj/clean.c"
#include "/players/mythos/closed/guild/def.h"

string name;
int time;

id(str)  { return str == "lockjaw" || str == "infection";  }

get()    { return 0;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/mythos/closed/guild/forest/misc/lockjaw.c:"; }

reset(arg) {
if(arg) return;
call_out("disease_check",3);
}

init()  {
if(tl > 20 || !living(tp) || tp->query_npc()  || present(fear,tp))  { 
destruct(this_object()); return 1;}
name = epn;

if(!restore_object("players/mythos/closed/guild/forest/misc/loc/"+name)) {
  time = 0; }
  
if(time > 20) { add_action("eee","eat"); 
                add_action("eee","feedme");
                add_action("eee","sip");
                add_action("eee","drink"); 
                add_action("eee","say");
                add_action("eee","tell");
                add_action("eee","risque");
                add_action("eee","gossip");
#ifndef __LDMUD__
                add_action("eee");add_xverb("farsong");
                add_action("eee");add_xverb("'");
#else
	add_action("eee", "gossip", 3);
	add_action("eee", "", 3);
#endif
                add_action("eee",";");
                add_action("eee","kiss");
                add_action("eee","dkiss");
                add_action("eee","french");
                add_action("eee","lick");
                add_action("eee","whisper");
                add_action("eee","converse");
                add_action("eee","babble");
                add_action("eee","shout");}
}

eee() {
  write("The lockjaw has progressed too far!\n"+
        "You can no longer speak, eat, nor drink!\n");
return 1;}

disease_check()  {
if(ep->query_ghost()) { rm("/players/mythos/closed/guild/forest/misc/loc/"+name+".o");
                      destruct(this_object()); return 1;}
if(time > 1 && time < 6) { ep->add_hit_point(-1); }
if(time > 5 && time < 10) { ep->add_hit_point(-3-random(3)); }
if(time > 9) { ep->add_hit_point(-10 - random(10)); }
if(time == 1) { tell_object(ep,"Your jaw muscles spasm.\n"); }
if(time == 5) { tell_object(ep,"You find it hard to swallow.\n"); }
if(time == 9) { tell_object(ep,"You have tetanus!\n"+
                               "Treatment may be a good idea!\n"); }
time = time + 1;
save_object("players/mythos/closed/guild/forest/misc/loc/"+name);
move_object(this_object(),ep);
call_out("disease_check",90);
return 1;}
