#define MOV_RATE 15
inherit "/obj/monster";
object ob, ob2,gold;

reset(arg) {
  if(arg) return;
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(50);
move_object(gold,this_object());
ob = clone_object("/players/saber/armor/skinleather.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/ssword.c");
move_object(ob2,this_object());
   if (!arg){
     set_name( "amazon" );
    set_gender("female");
      set_short("A dangerous looking Amazon");
     set_race( "human");
     set_alt_name("saber_amazon");
     set_long("A buxom woman with an evil glint in her eyes.\n");
     set_level(9);
     set_ac(8);
   set_wc(12);
     set_hp(125);
     set_al(-200);
     set_aggressive(1);
     set_a_chat_chance(15);
    load_a_chat("Amazon punches you.\n");
     load_a_chat("Amazon kicks you.\n");
     load_a_chat("Amazon yells: I'm more of a man than you are!\n");
     load_a_chat("Amazon bites you!\n");
     load_a_chat("Amazon yells: Wench, bring me Ale!\n");
     load_a_chat("Amazon winks at you.\n");

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
