/*
 alarm_bat.c
*/

#define TPRN this_player()->query_real_name()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
string bat_owner_name,message,str;

reset(arg) {
  ::reset(arg);
  if (arg) return;

set_name("bat");
set_alias("fruit bat");
set_alt_name("mbat");
set_short("large "+BOLD+"fruit bat"+NORM);
set_long(
  "A large fruit bat whose lips seem to curve up in a smile. It has\n"+
  "sharp, pointed fangs but seems to be friendly.\n");

set_race("creature");
set_al(0);
set_level(4);
set_hp(60);
set_wc(30);
set_ac(8);
set_ep(1);
set_aggressive(0);
set_heal(5,2);
set_dead_ob(this_object());

}

clean_up() { return 0; }

init() {
  ::init();
  bat_speak();
}

bat_speak() {
if(!find_player(bat_owner_name)) {
tell_room(environment(this_object()),
  "The bat flaps its wings and flutters away.\n\n");
  destruct(this_object());
  return 1; }
tell_room(environment(this_object()),
  capitalize(bat_owner_name)+"'s bat squeaks: "+HIR+
    "'"+capitalize(message)+NORM+".'\n\n");
  return 1;
}

set_message(str) { message = str; }
set_bat_owner(str) { bat_owner_name = str; }

monster_died() {
tell_object(find_player(bat_owner_name),BOLD+
  capitalize(query_attack()->query_real_name())+
    " just killed your bat!"+NORM+"\n");
return 0; }
