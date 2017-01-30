inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("brigand leader");
   set_race("human");
   set_alias("brigand");
   set_short("Brigand Leader");
   set_long("This is the Head Brigand.  He is a bit tougher than his counterparts!\n");
   set_level(12);
   set_hp(40);
   set_al(0);
   set_wc(12);
   set_ac(6);
   set_chat_chance(2);
   load_chat("Brigand says: 'Is gold is mine!\n");
   load_chat("Head Brigand waits for his chance to backstab you!\n");
   gold=clone_object("obj/money");
   gold->set_money(200);
   move_object(gold,this_object());
}
