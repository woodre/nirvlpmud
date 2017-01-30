#define MOV_RATE 15
inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(275);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/sclub.c");
move_object(ob,this_object());
   if (!arg){
     set_name( "orc" );
    set_gender("male");
      set_short("An ugly Orc");
     set_race( "orc");
     set_alt_name("saber_orc");
     set_long("An ugly orc with a case of the hiccups.\n");
     set_level(10);
     set_ac(7);
     set_wc(12);
     set_hp(130);
     set_al(-200);
     set_aggressive(1);
     set_a_chat_chance(15);
    load_a_chat("Orc punches you.\n");
     load_a_chat("Orc kicks you.\n");
     load_a_chat("Orc hurls a chair across the room.\n");
     load_a_chat("Orc yells: More Ale!\n");
     load_a_chat("Orc hiccups.\n");
     load_a_chat("Orc hiccups.\n");
     load_a_chat("Orc hiccups.\n");
     load_a_chat("Orc burps loudly.\n");
     load_a_chat("Orc bleeds.\n");
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
