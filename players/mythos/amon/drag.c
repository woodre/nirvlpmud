#define dester "/players/mythos/dmon/dd.c"

inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("dragon");
  set_alias("dragon");
  set_race("dragon");
  set_short("Black Dragon");
  set_long(""+
     "\n");
  set_level(25);
  set_hp(1500);
  set_al(-1200);
  set_wc(40);
  set_ac(20);
  set_aggressive(0);
  set_mult(2);
  set_mult_chance(100);
  set_mult_dam1(30);
  set_mult_dam2(0);
  set_chance(30);
  set_spell_dam(30+random(20));
  set_spell_mess1(""+
     "\n");
  set_spell_mess2(""+
     "\n");
  gold=clone_object("obj/money");
  gold->set_money(random(2000)+3000);
  move_object(gold,this_object());
}


heart_beat() {
  ::heart_beat();
  if(query_attack()) breath();
}

breath() {
object ob,ob2,who;
int j,k,g;
  if(!environment(this_object())) return 1;
  who = all_inventory(environment(this_object()));
  for(j=0;j<sizeof(who);j++) {
     if(who[j]) if(living(who[j])) {
      if((g = sizeof(all_inventory(who[j]))) > 40) {
        ob = clone(dester);
        ob->set_max(40);
        ob2 = clone(dester);
      ob2->set_min(40);  ob2->set_max(g);
    move_object(ob,who[j]);
    move_object(ob2,who[j]);
        }
     else {
    ob = clone_object(dester);
   ob->set_max(g);
   move_object(ob,who[j]);
    }
     }
  }
return 1;
}
