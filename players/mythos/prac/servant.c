#define MOV_RATE 15
inherit "/obj/monster";
object ob, ob2, gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
ob2 = clone_object("/players/saber/armor/lgloves.c");
move_object(ob2,this_object());
ob = clone_object("/players/saber/armor/blackcloak.c");
move_object(ob,this_object());
   if (!arg){
     set_name( "thief" );
    set_gender("male");
      set_short("A shady looking Thief");
     set_race( "human");
     set_alt_name("THIEF");
     set_long("A shady looking character.\n"+
          "He seems to be eyeing your money pouch.\n");
     set_level(10);
     set_ac(7);
     set_wc(12);
     set_hp(130);
     set_al(-200);
     set_aggressive(1);
     set_a_chat_chance(15);
    load_a_chat("Thief punches you.\n");
     load_a_chat("Thief kicks you.\n");
     load_a_chat("Thief grins evilly at you.\n");
     load_a_chat("Thief says: You don't mind if I borrow this, do you?\n");
     load_a_chat("Thief yells: More Ale!\n");
     load_a_chat("Thief bleeds.\n");

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
