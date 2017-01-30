#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int num;
array *rooms;

reset(arg)  {
    num = random(sizeof(rooms));
    rooms = ({ "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3" });
  ::reset(arg);
  if(arg) return;
call_out("move_me", 20);
call_out("bye_bye", 4500);
set_name("Rabbit");
set_alias("rabbit");
set_alt_name("white rabbit");
set_race("creature");
set_short("Rabbit");
set_long(
   "A cute, fuzzy white rabbit.\n");

set_level(3);
set_hp(40+random(15));
set_al(0);
set_wc(7);
set_ac(3);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(25);
  load_chat("The rabbit wiggles its nose.\n");
set_a_chat_chance(15);
  load_a_chat("The rabbit gnaws on you!\n");

}


bye_bye(){
say("The rabbit quickly hops into a bush.\n");
destruct(this_object());
return 1; }

move_me(){
     num = random(sizeof(rooms));
     rooms = ({ "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3" });
    if(!environment()) return;
say("The rabbit hops away.\n");
move_object(this_player(),"/players/jaraxle/3rd/warrior/rooms/"+rooms[num]+"");
say("A rabbit hops into the room.\n");
call_out("move_me", 5);
}

monster_died() {
  tell_room(environment(this_object()),
        "The rabbit falls lifeless to the ground.\n");
MOCO("/players/jaraxle/3rd/warrior/weaps/foot2.c"),environment());
return 0; }


