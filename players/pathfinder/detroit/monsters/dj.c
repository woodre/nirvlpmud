inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("dj");
   set_race("human");
   set_alias("disc_jockey");
   set_short("A hip DJ");
   set_long("\n"+
"  A DJ, he is mixing it up as you look at him.  He looks at you without\n"+
"skipping a beat.  He has multitudes of CD's laying around all over the place\n"+
"and a set of turntables to his front.\n");   
   set_level(17);
   set_hp(300+ random(200));
   set_al(-100);
   set_wc(25);
   set_ac(12);
   set_chance(20);
   set_spell_dam(11);
   set_spell_mess1("DJ slices you with a compact disc!\n");
   set_spell_mess2("DJ hurls a CD at you!\n");
   set_chat_chance(2);
   load_chat("DJ tells you: Get into the groove 'g!\n");
   load_chat("You see DJ put out the funky beat.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1500)+2000);
   move_object(gold,this_object());
}

