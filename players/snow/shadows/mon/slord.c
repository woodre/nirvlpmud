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
 
object gold,ob,ob2;
string shortdesc;
int R;
  R = random(6);
  if(R == 0) shortdesc = "A tall Shadow Lord";
  if(R == 1) shortdesc = "A proud Shadow Lord";
  if(R == 2) shortdesc = "An arrogant Shadow Lord";
  if(R == 3) shortdesc = "A handsome Shadow Lord";
  if(R == 4) shortdesc = "A Shadow Lord";
  if(R == 5) shortdesc = "A thin Shadow Lord";
 
  gold = clone_object("obj/money");
  gold->set_money(random(1000)+2000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/shadows/stuff/ring");
move_object(ob,this_object());
  ob2 = clone_object("/players/snow/shadows/stuff/sgem");
  move_object(ob2,TO);
 
     set_name("shadow lord");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("lord");
     set_long(
"Standing about 3 meters in height, the Shadow Lord is wreathed in an aura\n"+
"of dark power. A powerful ruler used to being obeyed, it might be best if\n"+
"you were to leave him alone.\n");
     set_level(20);
init_command("wear ring");
     set_ac(random(10)+10);
     set_wc(random(10)+25);
     set_hp(random(150)+400);
     set_heal(1,1);
     set_al(-10);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Shadow Lord says: Begone, light people!\n");
     load_chat("The Shadow Lord paces thoughtfully.\n");
     load_a_chat("The Shadow Lord weaves fluidly through combat.\n");
     load_a_chat("The Shadow Lord moves in a blur!\n");
set_chance(25);
set_spell_mess1("The Shadow Lord attacks masterfully!\n");
set_spell_mess2("The Shadow Lord attacks masterfully!\n");
set_spell_dam(25);
   }
}
 
heart_beat() {
  object king;
  ::heart_beat();
  if(!environment()) return;
  king = present("shadow king", environment(this_object()));
  if(!king) return;
  if(king->query_attack()) this_object()->attack_object(king->query_attack());
  return; }
