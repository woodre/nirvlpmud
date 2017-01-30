#include <ansi.h>
inherit "obj/monster";
object ownb;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("serpent");
  set_alt_name("serpent_from_wep");
  set_race("creature");
  set_short(HIR+"The Serpent of Corruption"+NORM);
  set_long("  Before you lies a huge red scaled serpent.  It is nearly\n"+
           "30 feet in length, and has terrible fangs protruding from\n"+
           "its powerful jaws.\n");
  set_hp(250);
  set_level(1);
  set_al(-1000);
  set_wc(28);
  set_ac(5);
  set_aggressive(0);
  set_a_chat_chance(10);
  load_a_chat("The serpent hisses!");
  ownb = 0;
  set_dead_ob(this_object());
  no_exp_value = 1;
  call_out("check",3);
}

check() {
  object weapon;
  if(!environment()) return 1; 
  if(!ownb) { destruct(this_object()); return 1; }
   if(!(this_object()->query_attack()) || !ownb->query_attack()) {
   tell_room(environment(this_object()),"The Serpent hisses and fades into mist!\n");
   destruct(this_object());
   return 1;}
  weapon = ownb->query_weapon();
  if(!weapon || !weapon->id("pet_allow_wep") ) {
   tell_room(environment(this_object()),"The Serpent hisses and fades into mist!\n");
   destruct(this_object());
   return 1;}
call_out("check",3);
return 1;}

set_owner(object ob) { ownb =  ob; }
query_npc(){ return 0; }

monster_died() {
object corpse;
tell_room(environment(),
HIR+"\n\nThe Serpent gives a rattling hiss and fades into nothingness!\n\n"+NORM);
if(corpse = present("corpse", environment())){
 destruct(corpse);
 }
return 0;
}

