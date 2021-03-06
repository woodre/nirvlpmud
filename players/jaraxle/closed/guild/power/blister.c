/*
 * spell : Blister   (evocation)
 * level : 6
 * effect: spell_object: random(Evoc)  (max:50)
 * cost  : (2 * Evoc) / 3
 * spec  : 
 * files : 
 */

blister(str){
  object obj;
  int dmg;

  if(!KNOW("blister")){
    write("What?\n");
    return 1;
  }

  obj = PAV->valid_spell(str);
  if(!obj) return 1;

  if(guild->query_next_dmg() > time()) {
    write("You cannot cast this spell yet.\n");
    return 1;
  }

  write("You cast a "+HIR+"Blister"+NORM+" spell on "+IT+" ...\n");
  say(ME+" casts a "+HIR+"Blister"+NORM+" spell on "+IT+" ...\n");
 
  if(spell_fail2(6, "evoc", "int")){
    write("You miscast the spell and it "+HIR+"backfires!\n"+NORM);
    say(ME+" miscasts the spell and it backfires!\n");
    tell_room(env, ME+"'s skin boils and pops painfully!\n");
    tp->hit_player(random(40));
    tp->add_spell_point(-15);
    return 1;
  }

  dmg = random(guild->query_total_evoc());

  if(dmg >= 65){
    tell_room(env,
    "A "+HIR+"volcano of flames"+NORM+" erupts inside "+IT+"'s body!!!\n"+
    "Smoke pours from "+IT+"'s ears and fire from its eyes as it is\n"+
    HIR+" burned alive"+NORM+" from the inside!\n");
  } else if(dmg >= 40){
    tell_room(env,
    IT+"'s blood begins to boil and its skin blisters and pops painfully!\n"+
    ME+"'s spell "+HIR+"roasts"+NORM+" "+IT+"'s body from the inside!\n");
  } else if(dmg >= 20){
    tell_room(env,
    IT+"'s skin blisters and scars painfully as "+ME+"'s spell burns its body!\n");
  } else {
    tell_room(env,
    IT+" flinches as "+ME+"'s spell causes a few heat blisters on its skin.\n");
  }

  tp->add_spell_point(-(2 * guild->query_evocation() / 3));

  PAV->tell_damage(dmg, obj);
  if(dmg > 50) dmg = 50;
  tp->set_spell_dam(dmg);

  return 1;
}
