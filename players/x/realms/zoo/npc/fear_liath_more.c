#include <ansi.h>

inherit "/obj/monster";

void reset(int x){
  ::reset(x);
  if(x) return;
  set_name("something");
  set_alias("fear liath more");
  set_alt_name("fear liath more");
  set_long("\
Vast, dark blurs obscure the sky, occasionally manifesting in\n\
the form of a 10-foot tall, broad shouldered \"Grey Man\"\n\
with long, waving arms, then phasing back out of sight.\n");
  set_chat_chance(50);
  load_chat("You hear loud crunching noises.\n");
  load_chat("You hear the sound of footsteps following you.\n");
  load_chat("You feel an icy presence in the area.\n");
  load_chat("Something gets a cold grip on your flesh!\n");
  load_chat(".........hummmmmmmmmmmmmmmmmm............\n");
  set_level(26);
  set_wc(46);
  set_ac(24);
  set_hp(1200);
  set_light(-1);
  set_message_hit(({
    HIR+"ANNIHILATED"+NORM, ", splattering gore and meat all over the area",
    RED+"CRUSHED"+NORM, " with a strange force",
    HIK+"obliterated"+NORM, " with the power of darkness",
    RED+"rended"+NORM, "'s sternum",
    YEL+"assaulted"+NORM, " with an odd power",
    "whacked"," hard",
    "struck at","",
   }));
  set_wc_bonus(100);
  set_dead_ob(this_object());
}

void heart_beat(){
  ::heart_beat();
  if(attacker_ob){
    if(hit_point < 400){
      if(!random(4)){
        if((object)attacker_ob->query_attack() != attacker_ob) {
          tell_room(environment(), "\n\
"+(string)attacker_ob->query_name()+" attacks "+objective(attacker_ob)+"self!\n");
          attacker_ob->attack_object(attacker_ob);
        }
      }
    }
    if(!random(4)){
      tell_object(attacker_ob, "You feel a "+HIR+"sharp pain"+NORM+" in your head!\n");
      attacker_ob->hit_player(25+random(25), "other|mental");
    }
    if(!random(4)){
      tell_object(attacker_ob, "You feel "+HIC+"ice"+NORM+" running through your veins!\n");
      attacker_ob->hit_player(25+random(25), "other|ice");
    }
    if(!random(6)){
      attacker_ob->run_away();
    }
  }
  else if(!random(20)) {
    object ob, oc;
    ob = first_inventory(environment());
    while(ob) {
      oc = next_inventory(ob);
      if(ob != this_object()) {
        attack_object(ob);
      }
      ob = oc;
    }
  }   
}

status monster_died(){
  tell_room(environment(),
  "\n\tThe "+HIK+"Fear Liath More"+NORM+" disappears into the shadows...\n\n");
  destruct(present("corpse", environment()));
  if(attacker_ob){
    tell_object(attacker_ob,
      "The powers of the "+HIK+"Fear Liath More"+NORM+" flood into your unconsciousness!\n");
    command("scream", attacker_ob);
    tell_room(environment(),
      (string)attacker_ob->query_name()+"'s head looks like it will explode.\n",
       ({ attacker_ob }));
  }
  return 0;
}

string short(){
  return 0;
}