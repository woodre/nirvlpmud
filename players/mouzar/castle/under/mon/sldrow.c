inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("slave");
set_alias("elf");
set_short("Slave drow");
set_long(
"There isn't much left of this slave drow.  Was probally kick out of his\n"
+ "house when he stepped on a spider.  Now he is hiding from what he used\n"
+ "to be, a proud and deadly drow warrior.  He has been left with only his\n"
+ "hands to fight and nothing to protect his black skin but rags.  He is \n"
+ "very skinny and desperate.  He is so desperate he attacks you for hope that\n"
+ "you have food on you.\n");
set_level(10);
set_al(-200);
set_race("drow");
set_hp(150);
set_wc(10);
set_ac(5);
set_chance(10);
set_spell_dam(5);
  move_object(clone_object("/players/mouzar/castle/under/obj/dshield.c"),this_object());
}
