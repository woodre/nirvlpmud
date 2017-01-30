#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TR tell_room
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
string shortdesc;
int R;
 R = random(5);
  if(R == 0) shortdesc = "A burly Hunter";
  if(R == 1) shortdesc = "A tall Hunter";
  if(R == 2) shortdesc = "A short Hunter";
  if(R == 3) shortdesc = "An arogant Hunter";
  if(R == 4) shortdesc = "An agile Hunter";
 
  gold = clone_object("obj/money");
  gold->set_money(random(400)+300);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/shadows/stuff/spear");
move_object(ob,this_object());
 
     set_name("shadow hunter");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("hunter");
     set_long(
"A denizen of the shadow plane, these shadowy human forms look like\n"+
"village hunters in search of game. They appear to be reasonably strong\n"+
"but constantly scan the shadow horizons in anxiety.\n");
     set_level(random(4)+14);
     set_ac(random(5)+4);
init_command("wield spear");
     set_wc(random(10)+20);
     set_hp(random(150)+200);
     set_heal(1,1);
     set_al(-10);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Hunter looks fearfully at you.\n");
     load_chat("The Hunter moves without making a sound.\n");
     load_a_chat("The Hunter looks around in fear.\n");
     load_a_chat("The Hunter moves in a blur!\n");
set_chance(20);
set_spell_mess1("The Hunter attacks with surprising strength!\n");
set_spell_mess2("The Hunter attacks with surprising strength!\n");
set_spell_dam(15);
   }
}
