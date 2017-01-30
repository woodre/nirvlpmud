inherit "obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())


reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold,armor;
gold = clone_object("obj/money");
gold->set_money(10000+random(15000));
move_object(gold,this_object());
move_object(clone_object("/players/pain/NEW/weap/soulcrusher"),this_object());
armor = clone_object("/players/pain/NEW/arm/helm2");
move_object(armor,this_object());
move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());
	set_name("Cha'gr DeathBringer");
    set_short("Cha'gr DeathBringer, the Head of the Blood Fisted Clan");
    set_race( "orc");
    set_alias("deathbringer");
    set_long(
"This is the legendary Cha'gr DeathBringer of the Blood Fisted Clan.\n"+
"His armor is caked in blood and gore. He snears at you, mocking your\n"+
"knock-kneed reaction to his immense size and strength. His fangs gleem\n"+
"in the torch light of the room and you hope they don't find a way to sink\n"+
"into your flesh. You can see why he has the respect and loyalty of those\n"+
"who have sworn their fealty to him.\n");
    set_level(30);
    set_hp(2500);
    set_al(-1000);
    set_aggressive(1);
    set_dead_ob(this_object());
    set_chat_chance(7);
    set_a_chat_chance(7);
    load_chat("DeathBringer says: I'll never allow you to see Mortus.\n");
    load_chat("DeathBringer waves his huge mace at you.\n");
    load_a_chat("DeathBringer says: Stupid fool, I'll kill you for that!\n");
    load_a_chat("DeathBringer pounds you mercilessly.\n");
    set_chance(35);
    set_spell_mess1("DeathBringer smacks you upside the head in a rage!\n");
    set_spell_mess2("DeathBringer pummels you with SoulCrusher.\n");
    set_spell_dam(80);
	init_command("wear helm");
	init_command("wield mace");
	set_ac(25+random(10));
	set_wc(40+random(20));
    set_wc_bonus( 25 );
    call_out("rebeat",10);
   }
}

heart_beat() {
  ::heart_beat();
    if(MEAT)
	fearsome(MEAT);
return 1;
}

flap() {
  int X;

X = random(15);
call_other(TO,"heal_self",X);
  if(X > 10) {
    say("DeathBringer's takes a swig of his ale and feels better.\n");
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
    "DeathBringer mauls "+ob->query_name()+" with SoulCrusher!\n");
  tell_object(ob, "DeathBringer mauls you with SoulCrusher and laughs.\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(50)+10)); return 1; }
  ob->hit_player(random(50)+50);
  return 1;
}

widow(object ob) {
  tell_room(environment(ob),
    "DeathBringer slashs at "+ob->query_name()+" with SoulCrusher, the mace of the Blood Fisted.\n");
  tell_object(ob,
    "SoulCrusher tears your flesh from your bones.\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(20)+10)); return 1; }
  ob->hit_player(random(40)+50);
  return 1;
}

cast_wide() {
  object dest, list;
  int i;
  dest = environment(TO);
  tell_room(dest,
"DeathBringer sweeps the rooms with his mace, SoulCrusher!\n\n"+
"As SoulCrusher reduces you to a bloody pulp you catch a glimpse of infinity.\n");
  list = all_inventory(dest);
  for(i = 0; i < sizeof(list); i++) {
    if(present(list[i],dest)) {
      if(list[i]->is_player()) list[i]->add_hit_point(-(random(40)+5));
      if(living(list[i]) && !list[i]->is_player() && list[i]->id() != "deathbringer") list[i]->hit_player(30);
    }
  }
  return 1;
}



rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); return 1; }
