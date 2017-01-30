inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("sally");
   set_race("human");
   set_alias("clerk");
      set_short("Sally, a clerk");
     set_long("This clerk must have gotten a business administration degree in order to\n"+
              "control all the money movements of this Depatment.  What she is wearing\n"+
              "shows she is used to working in an executive environment:  a gray jacket\n"+
              "on a pale blue skirt that make a nice contrast with her blond hair.\n");

   set_level(9);
   set_hp(150);
   set_al(100);
   set_wc(14);
   set_ac(7);
   set_chance(14);
   set_spell_mess2("The clerk kindly says:  why dont you go messing somewhere else?");
   set_spell_mess1("The clerk kindly says:  why dont you go messing somewhere else?");
   set_spell_dam(10);
 gold = clone_object("obj/money");
 gold->set_money(490+random(70));
 move_object(gold,this_object());
}
