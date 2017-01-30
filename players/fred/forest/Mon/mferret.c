#include "/players/fred/ansi.h"
inherit "obj/monster";
object ownb;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("mini-ferret");
  set_race("creature");
  set_short("A mini-ferret");
  set_long(" A mini-ferret called to by the power of the overlord\n"+
           "to help in his continued battles.\n");
  set_hp(50);
  set_level(2);
  set_al(0);
  set_wc(14);
  set_ac(5);
  set_aggressive(0);
  set_a_chat_chance(10);
  load_a_chat("A mini-ferret tackles it's foe!\n");
  load_a_chat("The mini-ferret growls.\n");
   ownb = 0;
  call_out("check",3);
}

check() {
  object weapon;
  if(!environment(this_object()) ) return 1; 
  if(!ownb) { destruct(this_object()); return 1; }
   if(!(this_object()->query_attack()) || !ownb->query_attack()) {
   tell_room(environment(this_object()),"A mini-ferret scurries away laughing.\n");
   destruct(this_object());
   return 1;}
  weapon = ownb->query_weapon();
  if(!weapon || !weapon->id("remains") ) {
   tell_room(environment(this_object()),"A mini-ferret scurries away laughing.\n");
   destruct(this_object());
   return 1;}
call_out("check",3);
return 1;}
set_owner(object ob) { ownb =  ob; }
query_npc(){ return 0; }
