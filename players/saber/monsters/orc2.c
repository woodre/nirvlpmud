inherit "/obj/monster";
object ob, ob2, gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(50);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/sword.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/armor/orcboots.c");
move_object(ob2,this_object());
   if (!arg){
     set_name( "orc" );
    set_gender("male");
      set_short("An ugly Orc");
     set_race( "orc");
     set_long("An ugly looking humanoid with grey-green skin and\n"+
     "dark coarse hair.  It seems to have more of a snout\n"+
     "than a nose, and exhibits large looking canine teeth.\n"+
     "Orc has a stupid expression on its face.\n");
  command("wield sword");
  command("wear boots");
     set_level(8);
     set_ac(7);
     set_wc(12);
     set_hp(120);
     set_al(-500);
     set_chat_chance(3);
     load_chat("Orc stands there with a stupid expression on its face.\n");
     load_chat("The crowd cheers.\n");
     set_a_chat_chance(15);
    load_a_chat("Orc punches you.\n");
     load_a_chat("Orc kicks you.\n");
     load_a_chat("Orc hiccups.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Orc burps loudly.\n");
     load_a_chat("Orc bleeds.\n");
   }
}

void heart_beat(){
  object r, c, m;
 if(root()) {
  set_heart_beat(0);
  return;
 }
  ::heart_beat();
  if(query_attack() || random(4)) return;
  r = environment();
  c = present("crusher", r);
 if(!c) return;
 if(m = (object)c->query_attack())
 {
   tell_room(r,
  "\n\t"+query_name()+" leaps to Captain "+(string)c->query_name()
 +"'s aid!\n\n");
  attack_object(m);
 }
}
