#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dancing weapon");
  set_race("weapon");
  set_alt_name("dancing");
  set_short("weapon");
  set_long("\n");
  set_hp(120);
  set_level(8);
  set_al(0);
  set_wc(12);
  set_ac(10);
  set_exx(0);
  set_can_kill(1);
  set_dead_ob(this_object());
  set_a_chat_chance(15);
  load_a_chat("The "+short()+" strikes with great speed!\n");
  load_a_chat("The "+short()+" smashes "+
             (this_object()->query_attack())->query_name()+
             " with a bone crushing sound!\n");
  call_out("scheck",3);
}

monster_died() {
  move_object(present("dark weapon"),find_player(owner));
  present("dark weapon",find_player(owner))->set_count(20);
  present("dark weapon",find_player(owner))->weapon_breaks();
  destruct(this_object());
return 1;}

is_pet() { return 1;}

norm() {
  move_object(present("dark weapon"),find_player(owner));
  present("dark weapon",find_player(owner))->set_count(10);
  tell_room(environment(ep),"The Dancing Weapon reverts to its master.\n");
  destruct(this_object());
return 1;}

scheck() {
object own;
own = find_player(owner);
  if(!own) { destruct(this_object()); return 1;}
  if(!present(owner,ep)) { tell_room(ep,short()+" leaves after its master.\n");
                           move_object(this_object(),environment(own)); 
                           tell_room(ep,short()+" enters after its master.\n");}
  if(own->query_attack()) { this_object()->attack_object(own->query_attack()); }
call_out("scheck",3);
return 1;}
