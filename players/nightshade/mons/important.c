inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Important");
set_long("Mr. Important is the head honcho all Impland. Hes even harder than Imperial. Watch out!\n");
   set_level(8);
   set_hp(120);
   set_al(100);
   set_wc(12);
   set_ac(7);
   gold=clone_object("obj/money");
   gold->set_money(350);
   move_object(gold,this_object());
wep=clone_object("players/nightshade/weap/power");
move_object(wep, this_object());
init_command("wield power");
}

/* money was 3000 - mythos <6-17-96> */
