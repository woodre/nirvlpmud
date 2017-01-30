#define MOV_RATE 15
inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(400);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/bknuckles.c");
move_object(ob,this_object());
   if (!arg){
     set_name( "man" );
    set_gender("male");
      set_short("A large Man");
     set_race( "human");
      set_long("A large man looking for a fight.\n");
     set_level(9);
     set_ac(7);
     set_wc(12);
     set_hp(130);
     set_al(-200);
     set_aggressive(1);
     set_a_chat_chance(15);
    load_a_chat("Man punches you.\n");
     load_a_chat("Man kicks you.\n");
     load_a_chat("Man hurls a chair across the room.\n");
     load_a_chat("Man yells: More Ale!\n");
     load_a_chat("Man bleeds.\n");
     set_spell_mess1("Man smashes a chair over his opponents head.");
     set_spell_mess2("Man smashes a chair over your head!");
     set_chance(5);
     set_spell_dam(6);
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
