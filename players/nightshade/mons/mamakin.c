inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("mamakin");
   set_alias("dragon");
   set_short("Mamakin");
set_long("Mamakin is an old dragon even by the standards of"+
" dragon-kind. She knows her lair and its treasure like the"+
" back of her tail. Her black scales even out-dark the darkness"+
" . Her tail is tipped with a poisonous stinger that could do some"+
" major damage to the unfortunate one who gets in its way.\n");
   set_level(19);
   set_hp(3000);
   set_al(-1000);
   set_wc(20);
   set_ac(12);
   set_chance(30);
   set_spell_dam(20);
   set_spell_mess1("Mamakin lashes out with her tail!\n");
set_spell_mess2("Mamakin's tail impales you and injects its poison!");
   gold=clone_object("obj/money");
   gold->set_money(random(2000)+2000);
   move_object(gold,this_object());
   wep=clone_object("/players/nightshade/weap/razor");
   move_object(wep,this_object());
}
