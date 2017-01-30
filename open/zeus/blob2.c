inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int togo;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  togo = 0;
  set_name("Boul-Goruk");
  set_alias("blob");
  set_alt_name("king");
  set_short(0);
  set_long(
      "You are inside the green blob.  You find that breathing is\n"+
      "almost impossible, and your blesh is being burned away!  You\n"+
      "had better get out of here as fast as possible.\n");
  set_wc(1);
  set_ac(22);
  set_hp(1100);
}}

setogo(x){ togo = x; }

status lower_hp(int x){    hit_point -= x;   }

out_ya_go(){
  string ya, pa;
  if(!environment()) return;
  if(present("corpse", environment()))
    destruct(present("corpse", environment()));
  if(!sscanf(object_name(environment()),
    "%smuseum/NPC/blob%s", ya,pa)) return;
  tell_object(attacker_ob,
    "\n\tBoul-Goruk spits you out in disgust!\n"+
    "\tGreen slime slowly oozes from his body...\n\n");
  attacker_ob->hit_player(59);
  environment()->setk(0);
  move_object(attacker_ob, environment(environment()));
  environment()->attack_object(attacker_ob);
  destruct(this_object());
}

void heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(hit_point <= togo)
    out_ya_go();
}

