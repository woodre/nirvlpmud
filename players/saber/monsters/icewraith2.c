#define MOV_RATE 10
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
  ob = clone_object("/players/saber/gems/ruby.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/armor/overload.c");
move_object(ob2,this_object());
     set_name( "ice wraith" );
     set_short("A shadowy Ice Wraith");
     set_alias("wraith");
     set_race( "spirit");
     set_long("A shadowy wraith of a figure cloaked in an aura of icy air.\n"+
        "Its eyes gleam out from the dark shadows of its hood like fiery gems.\n");
     set_level(19);
     set_ac(16);
     set_wc(28);
     set_hp(475);
     set_al(-1000);
     set_aggressive(1);
     set_a_chat_chance(15);
     load_a_chat("Ice Wraith howls wickedly.\n");
     load_a_chat("Ice Wraith hisses: Youuuussss areeeee mineeeesssssss.\n");

     set_spell_mess2("The Ice Wraith reaches out an ice cold hand and freezes your soul.");
     set_spell_mess1("The Ice Wraith places its hand INTO its foes chest."+
       "Ice Wraith howls wickedly.");
     set_chance(15);
     set_spell_dam(20);
     call_out("random_move",MOV_RATE);
   }
}

status random_move(){
int n;
n = random(6);
switch(n) {
case 0 : command("north"); break;
case 1 : command("east"); break;
case 2 : command("west"); break;
case 3 : command("south"); break;
case 4 : command("up"); break;
case 5 : command("down"); break;
}
call_out("random_move",MOV_RATE);
return 1;
}
