#define MOV_RATE 15
inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
  ob = clone_object("/players/saber/weapons/battleaxe.c");
move_object(ob,this_object());
   if (!arg){
     set_name( "barbarian" );
    set_gender("male");
      set_short("A huge Barbarian");
     set_race( "human");
     set_alt_name("saber_barbarian");
     set_long("A hulking man with impressive muscles.\n");
     set_level(10);
     set_ac(7);
     set_wc(12);
     set_hp(130);
     set_al(-200);
     set_aggressive(1);
     set_a_chat_chance(15);
    load_a_chat("Barbarian punches you.\n");
     load_a_chat("Barbarian bites you.\n");
     load_a_chat("Barbarian bellows loudly.\n");
     load_a_chat("Barbarian growls.\n");
     load_a_chat("Barbarian bellows: Where is my ale!\n");
     load_a_chat("Barbarian bellows: Where is my wench!\n");
     load_a_chat("Barbarian hurls a chair across the room.\n");
     load_a_chat("Barbarian yells: More Ale!\n");
     set_spell_mess1("Barbarian smashes a chair over his opponents head.");
     set_spell_mess2("Barbarian smashes a chair over your head!");
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
