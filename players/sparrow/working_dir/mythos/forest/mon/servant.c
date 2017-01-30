#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
int hel;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("amoril");
  set_alias("servant");
  set_race("hunters_servant");
  set_short(HIW+"Amoril: "+HIY+"the Servant"+NORM);
  set_long("A tall, lanky man.  He wears white furs, covering most of\n"+
           "his pale skin.  Mean, beady pink eyes stare back at you and\n"+
           "he gives you an evil grin.  An aura of CONTROL surrounds him.\n"+
           "Beware...\n");
  set_hp(1500);
  set_level(27);
  set_al(-1000);
  move_object(clone_object("/players/mythos/closed/guild/forest/wep/whip2.c"),this_object());
  init_command("wield whip");
  set_wc(50);
  set_ac(15);
  set_aggressive(1);
  set_chat_chance(4);
  set_a_chat_chance(4);
  load_chat("Amoril smiles a cold smile...\n");
  load_chat("The Servant of the Hunter looks you over with a piercing gaze.\n");
  load_a_chat("Amoril smiles...\n");
  load_a_chat("The Servant of the Hunter laughs...\n"); 
  add_spell("dread",
            "You feel a sense of DREAD.....\n\n"+BOLD+
            "  -------------->  P\n"+
            "                         A  <-------------\n"+
            " ----------->  I\n"+
            "                       N  <-------------\n\n"+NORM,
            "The Forbidden shakes around you!\n",
            40,({50,50}),({"other|evil",0}),0);
  hel = 0;
  call_out("grim",3);
  set_wc_bonus(100);
  set_ac_bonus(25);
}

query_prevent_shadow() { return 1; }

grim() {
int n,mm;
object attr, pett, shat;
hel = hel + 1;
n = 0;
attr = query_attack();
  if(hel > 10) { heal_self(30); hel = 0; }
  if(this_object()->query_ac() < 15) { this_object()->set_ac(15); } 
  if(this_object()->query_wc() < 50) { this_object()->set_wc(50); }
  if(attr) if(attr->query_npc()) attr->hit_player(100); 
  if(alt_attacker_ob) if(alt_attacker_ob->query_npc()) 
    alt_attacker_ob->hit_player(100); 
  pett = all_inventory(ep);
  for(mm=0;mm<sizeof(pett);mm++) {
    if(pett[mm] != attacker_ob && pett[mm] != alt_attacker_ob &&
       pett[mm] != this_object()) {
      if(!find_player(pett[mm]->query_real_name())) {
        tell_room(ep,"Amoril screams and deals a devastating blow to "+
                      pett[mm]->short()+"!!\n");
        pett[mm]->hit_player(80);
      } else {
         tell_room(ep,"Amoril screams and deals a devastating blow to "+
                      pett[mm]->short()+"!!\n");
        pett[mm]->heal_self(-random(60));
        pett[mm]->hit_player(50);
      }
    }
 }
    if(random(15) == 0 && query_attack()) {  
      tell_room(ep,"Weapons shatter...  For COLD DEATH has arrived!\n");
      if(query_attack()->query_weapon()) {
        shat = clone_object("/obj/treasure.c");
        shat->set_id((query_attack()->query_weapon())->query_name());
        shat->set_short((query_attack()->query_weapon())->short()+"  <<SHATTED>>");
        shat->set_long("The shattered remains of "+
                (query_attack()->query_weapon())->short());
        shat->set_value(10);
        shat->set_weight(3);
        destruct(query_attack()->query_weapon());
        move_object(shat,query_attack()); }
    attr->set_wc(3); }
call_out("grim",3);
return 1;}

query_attrib(str) {
  if(str == "pie") return 50; 
  if(str == "ste") return 100;
  if(str == "wil") return 40; 
  return 30;
}

heal_self(n) {
  int mm;
   mm = n;
   if(mm < -5) mm = -mm;
   tell_room(ep,"Amoril grins as the negative energy directed at him heals him\n");
   ::heal_self(mm);
}