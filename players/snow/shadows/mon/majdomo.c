#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TR tell_room
 
inherit "/obj/monster";
 
int bribed;
 
query_bribed() { return bribed; }

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(3000)+4000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/shadows/stuff/sgem");
  move_object(ob,TO);
 
     set_name("major domo");
     set_short("The Major Domo");
     set_race("shadowcreature");
     set_alias("domo");
     set_long(
"A tall, snotty-looking shadow man, the Major Domo considers his position\n"+
"to be the most important in the realm. He seems to be very rich...\n");
     set_level(20);
     set_ac(5); /* He has 2 bodyguards who defend him + healing */
     set_wc(30);
     set_hp(500);
     set_heal(1,1);
     set_al(-100);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Major Domo clears his throat...\n");
     load_chat("The Major Domo holds out his hand...\n");
     load_a_chat("The Major Domo smiles wickedly.\n");
     load_a_chat("The Major Domo moves in a blur.\n");
set_chance(35);
set_spell_mess1("The Major Domo strikes with skill!\n");
set_spell_mess2("The Major Domo strikes with skill!\n");
set_spell_dam(30);
   }
}
 
init() {
  ::init();
add_action("bribe_me","bribe");
}
 
bribe_me(arg) {
  if(!arg) { write("Bribe who?\n"); return 1; }
  if(!(arg == "major domo" || arg == "domo")) {
    tell_room(environment(TP),
      "The Major Domo holds out his hand toward "+TPN+".\n");
    tell_object(TP,"You think he wants you to bribe him.\n");
  return 1;
  }
  if(TP->query_money() < 1000) {
    write("You don't seem to have enough money to satisfy the Major Domo.\n");
    tell_room(environment(TP),
      "The Major Domo gestures and "+TPN+" flies from the room!\n");
    tell_object(TP,"You are magically transferred elewhere.\n");
    TP->move_player("/players/snow/shadows/hilltop");
    command("look",TP);
  return 1;
  }
  TP->add_money(-1000);
  bribed = 1;
  tell_room(environment(TP),"The Major Domo smiles happily\n");
return 1;
}
 
