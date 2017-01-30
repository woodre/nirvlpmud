#define MOV_RATE 15
inherit "/obj/monster";
object ob, ob2, gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(50);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/sclub.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/armor/wshield.c");
move_object(ob2,this_object());
   if (!arg){
     set_name( "goblin" );
    set_gender("male");
      set_short("An ugly goblin");
     set_race( "orc");
     set_long("A small humanoid with a flat face, broad nose, pointed ears, a\n"+
 "wide mouth and small, sharp fangs.  It has dull black skin and\n"+
 "oily black hair, and is wearing tattered bits of leather armor.\n");
     set_level(6);
     set_ac(5);
     set_wc(10);
     set_hp(90);
     set_al(-200);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("Goblin cowers.\n");
    load_a_chat("Goblin punches you.\n");
     load_a_chat("Goblin kicks you.\n");
     load_a_chat("Goblin burps loudly.\n");
     load_a_chat("Goblin bleeds.\n");
call_out("random_move",MOV_RATE);
   }
}

status random_move(){
int n;
n=random(5);
switch(n) {
case 0 : command("east"); break;
case 1 : command("north"); break;
case 2 : command("west"); break;
case 3 : command("west"); break;
case 4 : command("west"); break;
}
call_out("random_move",MOV_RATE);
  return 1;
}
