 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(15000) + 10000);
  move_object(gold,this_object());
move_object(clone_object("/players/pain/closed/weapons/widow"),this_object());
/*  Please check out the orb before it's put back into play - Eurale
move_object(clone_object("/players/pain/closed/wands/orb"),this_object());
*/
	init_command("wield widowmaker");
	init_command("ready orb");
     set_name("mortus");
     set_short("Mortus, the Necromancer");
     set_race( "human");
     set_alias("necromancer");
     set_long(
"This is the legendary Mortus the necromancer.\n"+
"There is an aura of death about him. He is cloaked in fear and pain.\n"+
"In his hand he holds a dark onyx orb that seems to suck the light out\n"+
"of the room. he wields a bright blade made of gleaming silver that is \n"+
"well worn, yet razor sharp. He has the face of death.\n");
     set_level(50);
     set_ac(random(25)+15);
     set_wc(random(30)+80);
     set_hp(2000);
     set_heal(5,1);
     set_al(-1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Mortus sends a few hard nogs out in your direction.\n");
     load_chat("Mortus says: Prepare to meet your maker mortal!\n");
     load_chat("Mortus brandises his blade in preperation for battle.\n");
     load_a_chat("Mortus says: Foolish mortal, now you die!\n");
     load_a_chat("Mortus snickers foreseeing your imminent demise.\n");
     set_chance(35);
     set_spell_mess1("Mortus attacks in a rage!\n");
     set_spell_mess2("Mortus attacks in a rage!\n");
     set_spell_dam(80);
     call_out("rebeat",10);
   }
}
 
heart_beat() {
  ::heart_beat();
    if(TO->query_hp() < 1800) 
	flap();
    if(MEAT) 
	fearsome(MEAT);
return 1;
}
 
flap() {
  int X;

X = random(15);
call_other(TO,"heal_self",X);
  if(X > 10) {
    say("Mortus's calls on dark spirits to heal himself.\n");
  }
return 1;
}
 
fearsome(object ob) {
  int lev;
  object meat;
  lev = ob->query_level();
  meat = present(ob,environment(TO));
  if(meat) {
    if(random(130) < lev) { 
	cast(ob); 
	return 1; 
	}
    if(random(80) < lev) { 
	widow(ob); 
	return 1; 
	}
    if(random(150) < lev) { 
	cast_wide(); 
	return 1; 
	}
  }
  return 1;
}
 
cast(object ob) {
  tell_room(environment(ob),
    "Mortus casts a deathball at "+ob->query_name()+"!\n");
  tell_object(ob,
    "Mortuss nogs as a Deathball engulfs you!\nYou are hit by a Deathball!\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(50)+50)); return 1; }
  ob->hit_player(random(50)+100);
  return 1;
}

widow(object ob) {
  tell_room(environment(ob),
    "Mortus slashs at "+ob->query_name()+" with Widowmaker, the sword of the Berseker.\n");
  tell_object(ob,
    "Widowmaker rends your flesh from your bones.\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(20)+10)); return 1; }
  ob->hit_player(random(40)+50);
  return 1;
}

cast_wide() {
  object dest, list;
  int i;
  dest = environment(TO);
  tell_room(dest,
"Mortus casts a Deathball that engulfs the entire area!\n\n"+
"As the Deathball engulfs you, you catch a glimpse of infinity.\n");
  list = all_inventory(dest);
  for(i = 0; i < sizeof(list); i++) {
    if(present(list[i],dest)) {
      if(list[i]->is_player()) list[i]->add_hit_point(-(random(60)+50));
      if(living(list[i]) && !list[i]->is_player() && list[i]->id() != "mortus") list[i]->hit_player(100);
    }
  }
  return 1;
}
 
 

rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); return 1; }
