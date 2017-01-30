inherit "obj/monster";
   object gold;
   object cert;

reset(arg){
   ::reset(arg);
   set_name("prof");
   set_race("human");
   set_alias("prof");
   set_short("Prof. HeinenTsi-Ho-Cheng, the Head of the Department");
   set_long("Professor Heinen is a tall man in his late twenties.  He has long \n"+
             "black hair and covering his eyes with a large pair of eyeglasses.\n"+
             "The man is wearing a pair of gauntlets in his hands and carrying a\n"+
             "small book.  He is dressed in a black funny looking uniform and a \n"+
             "white long robe on top.  An id card is attached to his robe.  On a \n"+
             "closer look, you notice that the picture on the id doesnt look much \n"+
             "like him.\n");
   set_level(16);
   set_hp(40);
   set_al(0);
   set_wc(33);
   set_ac(10);
   load_chat("Professor Heinen checks his clock.\n");
   load_chat("The man seems to be on waiting  for someone.\n");
   load_chat("The Professor looks around nervously.\n");

   set_chance(25);
   set_spell_mess2("Prof. Tsi-Ho-Cheng quotes:  no room here for people like you,  drop it.");
   set_spell_mess1("Prof. Tsi-Ho-Cheng quotes:  no room here for people like you,  drop it.");
   set_spell_dam(40);
 gold = clone_object("obj/money");
 gold->set_money(random(99)+800);
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate.c");
 move_object(cert,this_object());

}
