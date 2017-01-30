#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
int atte;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("terror");
  set_race("avatar");
  set_short(HIR+"Terror"+NORM);
  set_long("A naked beautiful woman with great "+HIR+"Blood"+NORM+" wings\n"+
           "standing out from her back- a "+HIR+"BLOOD ANGEL"+NORM+".\n");
  set_hp(300);
  set_level(30);
  set_al(-1000);
  set_wc(20);
  set_ac(10);
  set_heal(3,6);
  set_can_kill(1);
  set_aggressive(0);
  set_a_chat_chance(2);
  load_a_chat("Terror fills you!\n");   
  load_a_chat("Terror strikes!\n");
  set_mult(2);
  set_mult_chance(20);
  set_mult_dam1(5);
  set_mult_dam2(10);
  call_out("check",3);
}

check() {
if(!present(owner,ep)) {
  tell_room(ep,HIR+"Terror leaves following "+capitalize(owner)+".\n"+NORM);
  move_object(this_object(),environment(find_player(owner)));
  tell_room(ep,HIR+"Terror enters the room.\n"+NORM);
}
if(present(owner,ep)->query_attack()) {
if((present(owner,ep)->query_attack())->query_attack() != this_object()) {
  tell_room(ep,HIR+"Terror steps in between "+capitalize(owner)+" and "+
    (present(owner,ep)->query_attack())->short()+".\n"+NORM);
  tell_room(ep,(present(owner,ep)->query_attack())->short()+" turns and attacks TERROR!\n");
  (present(owner,ep)->query_attack())->attack_object(this_object());
  } }
call_out("check",3);
return 1;}
