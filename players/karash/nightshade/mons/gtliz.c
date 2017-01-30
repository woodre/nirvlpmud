inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Lizard");
   set_alias("lizard");
   set_short("Giant Lizard");
   set_long("You are looking at a ten foot lizard. Two inch teeth" +
" line its maw and sharp claws adorn its feet.\n");
   set_level(7);
set_aggressive(1);
   set_hp(105);
   set_al(0);
   set_wc(11);
   set_ac(6);
   set_chance(30);
   set_spell_dam(15);
   set_spell_mess1("The lizard whips his tail out!");
   set_spell_mess2("You are crushed by the beasts large tail.");
   gold=clone_object("obj/money");
   gold->set_money(300);
   move_object(gold,this_object());
}

/* money was rnd(200) + 300 - mythos <6-17-96> */
