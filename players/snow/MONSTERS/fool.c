/*
Snow's court jester. Has a few cursed items and a sword that uses
low intelligence to determine extra_hit stuff (it's not very good).
*/
 
#define MEAT this_object()->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob,ob2,ob3;
  gold = clone_object("obj/money");
  gold->set_money(random(1000) + 200);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/armor/jester_cap.c");
move_object(ob,this_object());
  ob2 = clone_object("/players/snow/armor/fool_cloak.c");
move_object(ob2,this_object());
  ob3 = clone_object("/players/snow/WEAPONS/fool_sword.c");
move_object(ob3,this_object());
 
     set_name("fool");
     set_short("Fool, the jester");
     set_race("man");
     set_alias("jester");
     set_long(
"This is Fool, Snow's court jester. He looks weak and probably is.\n");
     set_level(10);
     set_ac(6);
     set_wc(10);
     set_hp(200);
     set_heal(1,1);
     set_al(0);
     set_aggressive(0);
init_command("wear cap");
init_command("wear cloak");
init_command("wield sword");
     set_chat_chance(20);
     set_a_chat_chance(7);
     load_chat("Fool says: Hey! Wanna play?\n");
     load_chat("Fool juggles a few scarves.\n");
     load_chat("Fool adjusts his cap and cloak.\n");
     load_chat("Fool wiggles around and falls down.\n");
     load_a_chat("Fool yells: Snow protect me!\n");
     load_a_chat("Fool screams in pain and fear!\n");
set_chance(80);
set_spell_mess1("Fool blasts "+MEATN+" with colored streamers!\n");
set_spell_mess2("Fool blasts you with colored streamers!\n");
set_spell_dam(5);
   }
}
