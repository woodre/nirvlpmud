inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("gellor");
   set_alias("bard");
   set_short("Gellor the Troubadour");
   set_long("The man before you has only one eye.  His other eye is covered\n"+
            "by an eyepatch with sigils covering it.  Upon his back he \n"+
            "carries his kanteel, the sign of the bards.  His moustache \n"+
            "adds much character to his face and you know you can trust\n"+
            "this person entirely...unless you betray him.\n");
   set_level(27);
   set_hp(850);
   set_al(200);
   set_wc(44);
   set_ac(24);
   set_chance(50);
   set_spell_dam(random(30));
   set_spell_mess1("Gellor summons a horde of insects to fight for him!\n");
   set_spell_mess2("You are set upon by a horde of insects!\n");
   set_chat_chance(3);
   load_chat("Gellor takes out his kanteel and begins to play a ballad.\n");
   load_chat("Gellor says: Greetings my friends!\n");
   set_a_chat_chance(4);
   load_a_chat("Gellor exclaims: You fool, You cannot beat me!\n");
   load_a_chat("Gellor uses his kanteel as a weapon!\n");
   gold=clone_object("obj/money");
   gold->set_money(12000);
   move_object(gold,this_object());
}
