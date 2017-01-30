inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Bernard the singing tree");
   set_race("tree");
   set_alias("bernard");
   set_short("Bernard the singing tree");
set_long("This is Bernard, the singing tree. You know because it.. no.. um..\n"+
"he? Ah.. yes.. 'He' has a button pinned to his bark (skin) and it has\n"+
"his name emblazoned on it. He apparently thinks that he is some famous\n"+
"singer...\n");
   set_level(15);
   set_hp(500);
   set_al(100);
   set_wc(14);
   set_ac(14);
   set_chance(15);
   set_spell_dam(19);
set_spell_mess1("Bernard cries: Hey! That's no way to treat a star!");
set_spell_mess2("Bernard screams: Let me finish my song at least!");
   set_chat_chance(15);
load_chat("Bernard sings: 'I just want a place I can call my own,\n"+
	"	have a conversation on the tele-phone,\n"+
	" ");
load_chat("Bernard sings: 'Maybe i've forgotten... the name and the address.. \n"+
	"	of everyone i've ever known, it's nothing i regret...\n");
load_chat("Bernard sings: '...wake up every morning that would be a start,\n"+
	"	I just want a place for my wounded heart...'\n");
load_chat("Bernard sings: '...I was upset you see... waiting all the time...\n"+
	"	You were a total stranger.. and now you are mine...\n"+
	" ");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+150);
   move_object(gold,this_object());
	weapon=clone_object("players/mizan/etheriel/heals/rice-crispy.c");
	move_object(weapon, this_object());
}
