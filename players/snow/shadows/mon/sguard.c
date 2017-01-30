#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TR tell_room
 
string guarded;
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
string shortdesc;
int R;
 R = random(6);
  if(R == 0) shortdesc = "A solemn Shadow Guard";
  if(R == 1) shortdesc = "A burly Shadow Guard";
  if(R == 2) shortdesc = "A tall Shadow Guard";
  if(R == 3) shortdesc = "A powerful Shadow Guard";
  if(R == 4) shortdesc = "A frowning Shadow Guard";
  if(R == 5) shortdesc = "A fearless Shadow Guard";
 
  gold = clone_object("obj/money");
  gold->set_money(random(500)+200);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/shadows/stuff/axe");
move_object(ob,this_object());
 
     set_name("shadow guard");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("guard");
     set_long(
"Raised and trained to be royal guards, these shadow soldiers are not to\n"+
"be taken lightly. They serve their lord to the death.\n");
     set_level(random(4)+15);
     set_ac(random(7)+5);
init_command("wield axe");
     set_wc(random(20)+20);
     set_hp(random(100)+200);
     set_heal(1,1);
     set_al(-10);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Shadow Guard stands at attention.\n");
     load_chat("The Shadow Guard looks over the room.\n");
     load_a_chat("The Shadow Guard fights bravely.\n");
     load_a_chat("The Shadow Guard moves in a blur!\n");
set_chance(30);
set_spell_mess1("The Shadow Guard strikes in a fury!\n");
set_spell_mess2("The Shadow Guard strikes in a fury!\n");
set_spell_dam(20);
   }
}
 
heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  guard_guard(); }

guard_guard() {
  object lord, domo;
  lord = present("shadow lord", environment(this_object()));
  domo = present("domo", environment(this_object()));
  if(lord) {
    if(lord->query_attack() && !this_object()->query_attack()) {
    attack_object(lord->query_attack()); return 1; }
  }
  if(domo) {
    if(domo->query_attack() && !this_object()->query_attack()) {
    attack_object(domo->query_attack()); return 1; }
  }
  return; }
