#include <ansi.h>
#define ME capitalize(attacker->query_real_name())
inherit "obj/monster";
 object attacker;
reset(arg){
 object gold;
 ::reset(arg);
 if(arg) return;
 set_name("Hzsade");
 set_race("dragon");
 set_alias("hzsade");
 set_short(MAG+"Hzsade the Ancient Dragon"+NORM);
 set_level(41);
 set_hp(1000);
 set_al(-1000);
 set_wc(32);
 set_ac(24);
 set_aggressive(5);
 gold = clone_object("obj/money");
 gold->set_money(random(5000)+1000);
 move_object(gold, this_object());
 call_out("fake_beat", 3);
}

fake_beat(){
  int ranx;

  if(!this_object()->query_attack()){
    call_out("fake_beat", 5);
    return 1;
    }

  attacker = this_object()->query_attack();

  if(!present(attacker, environment(this_object()))){
    tell_object(attacker, MAG+"Hzsade"+NORM+" tells you: "+
    "You won't get away so easily next time!\n"+
    "The ancient dragon's evil laughter echoes through you head.\n");
    this_object()->stop_fight();
    this_object()->stop_fight();
    call_out("fake_beat", 5);
    return 1;
    }

  ranx = random(15);
  if(ranx == 1){
    tell_room(environment(this_object()), MAG+"Hzsade"+NORM+
    " slashes "+ME+" across the throat with his wicked talons!\n");
    attacker->hit_player(20);
  } else if(ranx == 3){ incinerate();
  } else if(ranx == 5){
    tell_room(environment(this_object()), MAG+"Hzsade"+NORM+
    " swings his mighty tail and SMASHES "+ME+" into the ground!\n");
    attacker->hit_player(random(50));
  } else if(ranx == 7){
    tell_room(environment(this_object()), 
    ME+" grows weak as "+MAG+"Hzsade"+NORM+" steals his life away!\n");
    attacker->add_spell_point(-20+random(30));
    this_object()->add_hit_point(20+random(50));
  } else if(ranx == 8 || ranx == 9){
    if(random(100)+1 == 13){
    tell_room(environment(this_object()), HIR+
      "Hzsade grabs "+ME+" around the neck and rips his head from his body!!!!\n"+
      "Hzsade drops "+ME+"'s shattered corpse into the dust.\n");
      attacker->hit_player(10001);
    } else {
      tell_room(environment(this_object()), MAG+"Hzsade"+NORM+
      " just misses "+ME+" with a swiping claw.\n");
    }
  } else if(ranx == 11){ ice_death();
  } else if(ranx == 13){
    tell_room(environment(this_object()), MAG+"Hzsade"+NORM+
    " grabs "+ME+" in his maw and shakes him like a ragdoll!\n");
    attacker->hit_player(random(100));
  } else if(ranx == 14){
    tell_room(environment(this_object()), MAG+"Hzsade"+NORM+
    " casts a magical spell and his talons glow with deathly power!\n");
    this_object()->set_wc(this_object()->query_wc() + 1);
  }
  call_out("fake_beat", 5);
}

incinerate(){
  object obj;
  int cont;
  cont = 0;
  obj = first_inventory(attacker);
    tell_room(environment(this_object()), MAG+"Hzsade"+NORM+
    " draws a deep breath and "+HIR+"BLASTS "+NORM+ME+" with a murderous "+
    HIR+"storm of fire"+NORM+"!!!\n");
  while(obj && cont == 0){
    object cur;
    cur = obj;
    obj = next_inventory(obj);
    if(!cur->drop() && random(3)==1){
    tell_object(attacker, "Hzsade's breath weapon incinerate's "+
    cur->query_name()+"!\n");
    destruct(cur);
    cont = 1;
    }
  }
}

icy_death(){
}
