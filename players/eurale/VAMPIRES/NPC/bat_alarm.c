/*
 alarm_bat.c
*/

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
string bat_owner_name,str;

reset(arg) {
  ::reset(arg);
  if (arg) return;

set_name("bat");
set_alias("alarm bat");
set_alt_name("abat");
set_short("small "+GRY+"grey bat"+NORM);
set_long(
  "A small, furry grey bat with beady little eyes.  Its head slowly\n"+
  "moves back and forth as it watches the goings on of the room.\n");

set_race("creature");
set_al(0);
set_level(4);
set_hp(60);
set_wc(35);
set_ac(10);
set_ep(1);
set_aggressive(0);
set_heal(5,2);
set_dead_ob(this_object());

}

clean_up() { return 0; }

init() {
  ::init();
bat_speak(this_player());
}

bat_speak(object who) {
if(!find_player(bat_owner_name)) {
  say("The bat flaps its wings and flutters away.\n\n");
  destruct(this_object());
  return 1; }
if(who->query_invis() < find_player(bat_owner_name)->query_level())
  tell_object(find_player(bat_owner_name),HIR+
    "~o~ squeaks: "+who->query_name()+" just entered my room!"+NORM+"\n");
  return 1;
}

set_bat_owner(str) { bat_owner_name = str; }

monster_died() {
tell_object(find_player(bat_owner_name),BOLD+
  capitalize(query_attack()->query_real_name())+
    " just killed your bat!"+NORM+"\n\n");
return 0; }
