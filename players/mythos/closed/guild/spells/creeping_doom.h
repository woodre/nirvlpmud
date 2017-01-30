/*
 *
 *  This spell costs 200 sp, half of the current hp
 *  1000 sacrifice, and freezes caster for a limited time
 *  plus a lower_attrib call (if this is not severe enough
 *  i have commented out an xp loss- that comment can be moved)
 *  in return this is the most damaging spell on the mud
 *  random(500) damage without a corpse, with a corpse damage
 *  includes a combination of stats.      - mythos
 *
 */
 
#include "/players/mythos/closed/guild/def.h"
int damm;
object obb, doer;
creeping_doom()
{
  int j, n;
  if(qtf < 13) { write("Your control over fae is not enough!\n"); return 1;}
  if(tsp < 200) { write("You do not have enough energy!\n"); return 1;}
  if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
  n = damm = 0;
  
  obb = all_inventory(environment(tp));
  for(j=0;j<sizeof(obb);j++)
  {
    if(obb[j]->query_npc()) { n = n + 1; }
  }
  if(n == 0) { write("Dont you feel foolish.\n"); return 1;}
  if(present("corpse",tp))
  { 
      damm = tp->query_attrib("sta") + tp->query_attrib("mag") +
            tp->query_attrib("wil") + tp->query_attrib("luc") +
            tp->query_attrib("int") + tp->query_attrib("str") +
            tp->query_attrib("pie") + tp->query_attrib("ste") + 
            tp->query_attrib("dex") + tp->query_attrib("cha") +
            (qtf*10);
     tp->add_weight(-(present("corpse",tp)->query_weight()));
     destruct(present("corpse",tp));
   }
     damm = (damm + random(500))/n;
     doer = tp;
     write("Targets?  <all or specify name>  : ");
     input_to("targets");
return 1;}

targets(str) { 
int f;
object vic;
  if(!str) { 
    tell_object(doer,"Targets?  <all or specify name>  : ");
     input_to("targets");
  return 1;}
  if(str == "all") {
   tell_room(environment(doer),
      "\n"+capitalize(doer->query_real_name())+" gestures....\n\n"+HIR+
      "                          F L A S H\n\n"+NORM+
      "Insects crawl out of the ground, fly through the air.\n"+
      "Every bug swarms and attacks the foe!\n");
    for(f=0;f<sizeof(obb);f++) {
      if(obb[f]->query_npc() && !(obb[f]->id("messenger"))) { 
      tell_room(environment(doer),obb[f]->short()+" is covered by insects!\n");
      tell_room(environment(doer),obb[f]->short()+" screams in terror and pain!\n");
      obb[f]->attack_object(doer);
      obb[f]->hit_player(100+random(100),"other|dark");
      }
    }
    cost();
  return 1;}
  else {
    vic = present(str,environment(doer));
    if(!vic) { write("Not here.\n"); return 1;}
    if(vic->is_player() && !(present(fear,doer)->query_defence())) { 
      write("May not use this on a player at this time.\n"); return 1;}
      tell_room(environment(doer),
      "\n"+capitalize(doer->query_real_name())+" gestures....\n\n"+HIR+
      "                          F L A S H\n\n"+NORM+
      "Insects crawl out of the ground, fly through the air.\n"+
      "Every bug swarms and attacks the foe!\n");
      tell_object(vic,"You feel great pain as millions of bugs bite and cut you!\n");
      tell_room(environment(doer),vic->short()+" screams in terror and pain!\n");
      vic->attack_object(doer);
      vic->hit_player(100+random(100),"other|dark");
      cost();
   }
return 1;}

cost() {
  tell_object(doer,"You are frozen as the bugs drain you...\n");
  move_object(clone_object("/players/mythos/closed/guild/spells/freeze2.c"),doer);
  doer->lower_attrib();
  
  doer->add_exp(-500-random(4000));
  present(fear,doer)->add_sacrifice(-1000);
  doer->add_spell_point(-200);
  doer->add_hit_point(-(doer->query_hp())/2);
  doer->save_me();
return 1;}
