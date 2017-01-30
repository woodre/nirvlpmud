#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int num;
array *rooms;

reset(arg)  {
object gold;
     num = random(sizeof(rooms));
     rooms = ({ "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3","tree","tree2","tree3","treew","treew2","treew3","treee","treee2","treee3" });
  ::reset(arg);
  if(arg) return;

call_out("move_me", 7);
call_out("bye_bye", 6300);
set_name("Forest Boy");
set_alias("boy");
set_alt_name("forest");
set_race("human");
set_short("A lost boy");
set_long(
  "A scrawny looking boy.  He is very dirty and smells bad.\n");

set_level(12);
set_hp(300);
set_al(0);
set_wc(19);
set_ac(15);
set_aggressive(0);

set_dead_ob(this_object());

set_chat_chance(13);
  load_chat("The boy grunts.\n");
load_chat("The boy grunts, 'stupid. . . '\n");
load_chat("The boy looks at you and laughs.\n");
load_chat("The boy looks at you and laughs.\n");
load_chat("The boy grunts, 'stupid. . . '\n");
load_chat("The boy pokes you in the ribs.\n");
set_a_chat_chance(15);
  load_a_chat("The boy gnaws on your arm!\n");

gold = clone_object("obj/money");
gold->set_money(200+random(200));
move_object(gold,this_object());
}
id(str){ return (str == "boy" || str == "lost boy" || str == "lost_boy_of_forest"); }
monster_died() {
write_file("/players/jaraxle/3rd/warrior/b_kill.log",ctime(time())+" "+HIY+""+this_player()->query_name()+""+NORM+" killed Boy.\n");
  tell_room(environment(this_object()),
       "The lost boy screams loudly as you land the final blow.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/machete.c"),TO);
return 0; }

bye_bye(){
say("The boy dives into the forest.\n");
destruct(this_object());
return 1; }

move_me(){
     num = random(sizeof(rooms));
rooms = ({ "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3","tree","tree2","tree3","treew","treew2","treew3","treee","treee2","treee3" });
    if(!environment()) return;
say("A boy runs from the room.\n");
move_object(this_player(),"/players/jaraxle/3rd/warrior/rooms/"+rooms[num]+"");
say("A boy runs into the room.\n");
call_out("move_me", 40);
}

