#include <ansi.h>
#define MM capitalize(drag->query_name())
#define II capitalize(drag->query_attack()->query_name())
dragon_klaw(drag){
 int dmg;
 if(drag->query_sp() < 0) return 1;
 dmg = random(10)+1;
 if(dmg >= 8) tell_room(environment(drag),
 MM+" snarls and rips "+II+" wide open with his deadly claws!\n");
 else if(dmg >= 4) tell_room(environment(drag),
 MM+" slices into "+II+"'s soft flesh with his razor-like claws!\n");
 else tell_room(environment(drag),
 MM+" scratches "+II+"'s skin with his claws.\n");
 drag->query_attack()->hit_player(dmg);
 drag->add_spell_point(-5);
 return 1;
}

breath_fire(drag){
 int dmg;
 if(drag->query_sp() < 0) return 1;
 dmg = 6+random(15);
 if(drag->query_sp() < 10) return 1;
 if(dmg >= 16) tell_room(environment(drag),
 MM+" draws a deep breath and "+HIR+"BLASTS "+NORM+II+" with a "+HIR+
 "pillar of fire!!!\n"+NORM);
 else if(dmg >= 10) tell_room(environment(drag),
 MM+" breathes a blazing stream of "+HIR+"fire"+NORM+" at his enemy!\n");
 else tell_room(environment(drag),
 MM+" burps up a small fireball and singes "+II+".\n");
 drag->query_attack()->hit_player(dmg, "other|fire");
 drag->add_spell_point(-15);
 return 1;
}

breath_acid(drag){
 int dmg;
 if(drag->query_sp() < 0) return 1;
 dmg = 6+random(15);
 if(drag->query_sp() < 10) return 1;
 if(dmg >= 16) tell_room(environment(drag),
 MM+" draws a deep breath and "+HIG+"BURNS "+NORM+II+" with a "+HIG+
 "deadly blast of acid!!!\n"+NORM);
 else if(dmg >= 10) tell_room(environment(drag),
 MM+" breathes a stream of "+HIG+"acid"+NORM+" at his enemy!\n");
 else tell_room(environment(drag),
 MM+" spits a tiny puddle of acid onto "+II+".\n");
 drag->query_attack()->hit_player(dmg, "other|poison");
 drag->add_spell_point(-15);
 return 1;
}

breath_ice(drag){
 int dmg;
 if(drag->query_sp() < 0) return 1;
 dmg = 6+random(15);
 if(drag->query_sp() < 10) return 1;
 if(dmg >= 16) tell_room(environment(drag),
 MM+" draws a deep breath and "+HIB+"BLASTS "+NORM+II+" with a deadly "+
 HIB+"cone of cold!!!\n"+NORM);
 else if(dmg >= 10) tell_room(environment(drag),
 MM+" breathes a stream of chilling "+HIB+"frost"+NORM+" at his enemy!\n");
 else tell_room(environment(drag),
 MM+" breathes some cold air down "+II+"'s back.\n");
 drag->query_attack()->hit_player(dmg,"other|ice");
 drag->add_spell_point(-15);
 return 1;
}

heal_spell(drag){
 int heal;
 heal = random(40);
 if(drag->query_sp() < 20) return 1;
 tell_room(environment(drag),
 MM+" casts a spell of healing and a silver aura surrounds "+MM+" and\n"+
      capitalize(drag->query_owner()->query_real_name())+" for a moment.\n");
 tell_object(drag->query_owner(),
 "Your dragon casts a "+HIB+"spell of healing"+NORM+" and you feel rejuvantated\n"+
 "as the magic replenishes your soul.\n");
  drag->query_owner()->heal_self(heal);
 drag->add_hit_point(heal);
 drag->add_spell_point(-25);
 return 1;
}

/* picks either ACID ARROW or WIIHER spell */
acid_arrow(drag){
  string dtype;
 if(drag->query_sp() < 20) return 1;
 if(random(4) >= 2){  /* acid arrow emotes */
 dtype="other|poison";
 if(random(2)==0) tell_room(environment(drag),
 MM+" conjures an "+HIG+" arrow of deadly acid "+NORM+" and fires it at "+II+"!\n"+
 "The acid splatters over "+II+" and "+HIG+"sizzles"+NORM+" into his flesh!\n");
 else tell_room(environment(drag),
 MM+" casts a "+HIG+"hissing arrow of acid"+NORM+" at "+II+"!\n"+
 "The toxic arrow "+HIR+"burns"+NORM+" "+II+"'s flesh!\n");
 } else {  /* wither emotes */
  dtype="other|dark";
 tell_room(environment(drag),
 MM+" casts a spell of "+GRN+"withering"+NORM+" on "+II+".\n");
 tell_room(environment(drag),
 MM+" creates an ominous black aura around his enemy.\n"+
 II+" feels tired and feeble.\n");
 }
 drag->query_attack()->hit_player(15, dtype);
 drag->add_spell_point(-25);
 return 1;
}
 
/* picks either MAGIC MISSILLE or LIGHTNING BOLT */
lightning_bolt(drag){
 int dmg, missiles;
 if(drag->query_sp() < 25) return 1;
 if(random(4) >= 2){
  missiles = drag->query_level() / 5;
  tell_room(environment(drag),
  MM+" casts a "+HIC+"Magic Missile"+NORM+" spell ... \n");
  if(missiles < 2) tell_room(environment(drag),
  "A blazing arrow of magic shoots forth from "+MM+"'s fingertip!\n");
  else tell_room(environment(drag),
  "A blazing volley of magic arrows shoot forth from "+II+"'s fingertips!\n");
  while(missiles > 0){
   dmg = random(10);
   if(dmg >= 5) tell_room(environment(drag),
   MM+" missile flies straight into "+II+", "+HIC+"a direct hit!\n"+NORM);
   else if(dmg > 0) tell_room(environment(drag),
   MM+"'s missile thuds into "+II+"'s body!\n");
   else tell_room(environment(drag),
   MM+"'s missile barely misses "+II+".\n");
   missiles--;
   drag->query_attack()->hit_player(dmg,"magical");
   drag->add_spell_point(-7);
   if(!drag->query_attack()) missiles = -1;
  }
 } else {
  tell_room(environment(drag),
  "A deafening CLAP OF THUNDER shakes the room!!!\n"+
  "A crackling bolt of lightning shoots from "+MM+"'s open hand!\n");
  tell_room(environment(drag),
  "The deadly bolt of energy flashes across the room and thunders into "+II+"!\n"+
  II+" spasms as millions of volts are poured into its body!\n"+
  "The smell of charred flesh taints the air.\n");
  drag->query_attack()->hit_player(10+random(20), "other|electric");
  drag->add_spell_point(-35);
 }
 return 1;
}
