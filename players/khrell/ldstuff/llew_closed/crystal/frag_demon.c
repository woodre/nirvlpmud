#define NAME_OF_GHOST "some mist"
#include "/players/llew/closed/ansi.h"

inherit "obj/monster";

string target;

reset(arg) {
   ::reset(arg);
if(!arg) {
   call_out("follow",2);
   set_name("xetra");
   set_level(20);
   set_race("demon");
   set_hp(random(300)+450);
   set_al(-1000);
   set_short(RED+"An enraged Xetra"+NORM);
   set_wc(45);
   set_ac(15);
   set_chance(15);
   set_spell_mess1("The Xetra fires red energy.\n\n"+
      RED+pad("",20)+pad("",40,'~')+"\n\n"+pad("",12)+pad("",56,'~')+"\n\n"+pad("",20)+pad("",40,'~')+"\n\n\n"+NORM);
   set_spell_mess2("The Xetra fires red energy at you!\n\n"+
      RED+pad("",20)+pad("",40,'~')+"\n\n"+pad("",12)+pad("",56,'~')+"\n\n"+pad("",20)+pad("",40,'~')+"\n\n\n"+NORM);
   set_spell_dam(40);
   set_a_chat_chance(10);
   load_a_chat("The Xetra screams in rage!\n");
   load_a_chat("Xetra yells,\"Hurocdt rufk tri!\"\n");
   load_a_chat("The Xetra licks the blood from its claws.\n");
   load_a_chat("The Xetra reaches for your soul.\n");
   set_dead_ob(this_object());
   set_message_hit(({HIR+"mutilates"+NORM," with blood dripping claws",RED+"devastates"+NORM," with blood dripping claws","slashed"," spraying the room with blood","sliced"," cleanly","cut","","grazed","","scratched"," a glancing blow"}));
}
}

monster_died() {
   write_file("/players/llew/closed/logs/frag_demon_summon",attacker_ob->query_name()+" killed Xetra.\n");
}
init() {
   ::init();
   add_action("ward","ward");
   add_action("prevent","north");
   add_action("prevent","south");
   add_action("prevent","east");
   add_action("prevent","west");
   add_action("prevent","northeast");
   add_action("prevent","northwest");
   add_action("prevent","southeast");
   add_action("prevent","southwest");
   add_action("prevent", "down");
   add_action("prevent", "up");
   add_action("prevent", "in");
   add_action("prevent", "out");
}

stop_fight() {
   if(!attacker_ob->query_interactive() && !attacker_ob->query_npc()) {
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
   }
}

heart_beat() {
   int X;
   ::heart_beat();
   X=2;
  if(!environment(this_object())) return;
   while(!random(X)) {
      already_fight=0;
      attack();
      X++;
   }
   if(!target) return;
   if(target == "") return;
   if(!find_player(target)) { die(); return; }
   if(find_player(target)->query_ghost()) {
      die();
      return;
   }
   if(!present(target)) {
      if(!(find_player(target)->query_interactive())) {
         die(); return;
      }
      tell_room(environment(),"The Xetra leaves in fury after "+capitalize(target)+".\n");
      move_object(this_object(),environment(find_player(target)));
      tell_room(environment(),"A Xetra enters after "+capitalize(target)+".\n");
      if(environment() == "players/mythos/closed/guild/death/death") { die(); return; }
      attack_object(find_player(target));
   }
   if(!random(20)) {
      tell_object(find_player(target),"Long claws plunge into your heart.  Cold energy freezes\nthe life out of your body.  The xetra laughs, absorbing it all.\n"+HIR);
      say("The Xetra reaches its claws into the heart of "+capitalize(target)+"and slowly slides them out in agonizing pain.\n",find_player(target));
      find_player(target)->raise_stamina(-1);
      tell_object(find_player(target),NORM);
   }
}

summoner(who) {
   target=who->query_real_name();
   attack_object(who);
   long_desc="A demon with eight inch claws, razor sharp.  It towers ten feet\n"+
   "up, destroying anything in its path.  Red skin burns hot, evaporating\n"+
   "any moisture in the air.  The Xetra is exacting revenge upon "+capitalize(target)+".\n";

}

die() {
   if(environment())
   tell_room(environment(),"The Xetra cackles maniacally.\n"+
      "The Xetra says,\"I pity the wretched soul.\"\n"+
      "The Xetra fades away.\n");
   destruct(this_object());
return 1;
}

ward(str) {
   write("The Xetra prevents you from casting any wards.\n");
   return 1;
}

prevent() {
int CH;
  if(query_attack()) {
      if(this_player() == query_attack()) CH = 35;
    else CH = 15;
}
  else CH = 10;
  if(random(100) < CH) {
     write("The Xetra prevents you from leaving!\n");
   return 1; }
}
