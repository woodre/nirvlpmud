inherit "obj/monster";
object wep, elf, gold;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("man");
   set_alias("man");
   set_short("Old, blind, white-haired oriental man");
set_long(
"This is an oriental man that you always see in the old movies. Ya\n"
+ "know the ones that reall kick ass. The blind, deaf, old ones.\n"
+ "Fear the old men!!\n");
   set_level(16);
set_wc(30);
   set_hp(500);
   set_al(1000);
   set_ac(13);
   set_chance(20);
   set_spell_dam(20);
set_spell_mess1("The old man disappears. He reforms right behind you.\n");
set_spell_mess2("The blind, old man slices down with his cane and amazingly hits you!\n");
   gold = clone_object("obj/money");
   gold->set_money(890);
   move_object(gold, this_object());
elf=clone_object("players/nightshade/weap/cane");
move_object(elf, this_object());
}
