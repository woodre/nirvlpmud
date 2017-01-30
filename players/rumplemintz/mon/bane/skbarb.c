inherit "/obj/monster";

void reset(int arg){
   object gold,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Skull Barbarian");
   set_race("undead");
   set_alias("barbarian");
   set_short("A Skull Barbarian");
   set_long("This is a servant who has achieved a higher degree of training.\n");
   set_level(11);
   set_hp(165);
   set_al(-500);
   set_wc(15);
   set_ac(9);
   gold=clone_object("obj/money");
   gold->set_money(random(100)+150);
   move_object(gold,this_object());
   weapon=clone_object("/players/rumplemintz/weapon/bonclub");
   move_object(weapon,this_object());
   init_command("wield club");
}
