inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("troglodyte");
   set_alias("trog");
   set_short("A nasty troglodyte");
   set_long("This evil denizen heard of the work of the Shadow Master and \n"+
            "came to serve under him.  They are said to have a special\n"+
            "attack which can kill their enemies....BEWARE!\n");
   set_level(4);
   set_hp(60);
   set_ac(4);
   set_wc(8);
   set_al(-100);
   set_chance(10);
   set_spell_dam(10);
   set_spell_mess1("Suddenly the Troglodyte's stomach opens up releasing\n"+
                   "a foul odor which hurts you!\n");
   gold=clone_object("obj/money");
   gold->set_money(150);
   move_object(gold,this_object());
}
