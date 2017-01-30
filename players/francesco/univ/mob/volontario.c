inherit "obj/monster";
   object gold;
   object suit;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("Volunteer");
   set_race("human");
   set_alias("volunteer");
      set_short("A volunteer");
     set_long("   A very sad smile on this man face makes you think\n"+
              "that he accepted this dangerous work only because he is\n"+
              "really broke.  He must earn some coins in order to keep\n"+
              "his family up.  Fortunately, he is wearing a suit, a kevlar\n"+
              "suit, which should protect him adequately from the gunshots.\n");

   set_level(20);
   set_hp(700);
   set_al(500);
   set_wc(25);
   set_ac(25);
 gold = clone_object("obj/money");
 gold->set_money(3000+random(150));
 move_object(gold,this_object());
 suit = clone_object("/players/francesco/univ/items/kevlar_suit.c"); 
 move_object(suit,this_object()); 
   set_spell_mess1("The poor volunteer aims the gun at you.");
   set_spell_mess2("The poor volunteer aims the gun at you.");
   set_spell_dam(30);
   set_chance(30);

}
