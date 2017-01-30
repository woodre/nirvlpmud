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
 R = random(5);
  if(R == 0) shortdesc = "A Wraith";
  if(R == 1) shortdesc = "A wispy Wraith";
  if(R == 2) shortdesc = "A black Wraith";
  if(R == 3) shortdesc = "A floating Wraith";
  if(R == 4) shortdesc = "A large Wraith";
 
  ob = clone_object("/players/snow/shadows/stuff/cloak");
move_object(ob,this_object());
  if(R == 2) {  ob2 = clone_object("/players/snow/shadows/stuff/sgem");
  move_object(ob,TO); }
 
     set_name("shadow wraith");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("wraith");
     set_long(
"This appears to be some sort of shadow spirit. It wanders the plains\n"+
"in search of rest. The soul of a warrior, shadow wraiths are to be feared.\n");
     set_level(random(3)+15);
init_command("wear cloak");
     set_ac(random(6)+6);
     set_wc(random(20)+15);
     set_hp(random(60)+80);
     set_heal(2,1);
     set_al(-300);
     set_aggressive(random(2));
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Wraith chills your blood with its dark gaze.\n");
     load_chat("The Wraith moves without making a sound.\n");
     load_a_chat("The Wraith screams in silent rage!\n");
     load_a_chat("The Wraith moves in a blur!\n");
set_chance(30);
set_spell_mess1("The Wraith phase-shifts!\n");
set_spell_mess2("The Wraith phase-shifts!\n");
set_spell_dam(30);
   }
}
 
