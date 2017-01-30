inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("balek");
   set_race("balek");
   set_alias("ghost");
	set_aggressive(1);
   set_short("ghost of Balek the sorcerer");
set_long("	Balek is the ghost of a once powerful sorcerer. He strikes you down\n"+
"  with the blade of fear when you first see him. You are actually curious\n"+
"  about what he was like when he was alive, since he is already imposing\n"+
"  enough as a ghost...\n");
   set_level(18);
   set_hp(418);
   set_al(-1000);
   set_wc(28);
   set_ac(16);
   set_chance(20);
   set_spell_dam(30);
   set_spell_mess1("Raw energy courses from the undead sorceror as he strikes you down with a bolt!");
   set_spell_mess2("Balek casts iceblade! You are raked by icy shards!");
   set_chat_chance(9);
load_chat("Balek moans: You... you're a mortal...\n");
load_chat("Balek spits on the ground.\n");
load_chat("Balek cries: I want to live again!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(500)+3400);
   move_object(gold,this_object());
}
