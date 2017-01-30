inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("dragon");
   set_alias("skeleton");
   set_short("A huge skeleton dragon");
   set_long("The Master raised this monster from the dead to guard his most\n"+
            "precious treasures.  This monster blocks the other way out of\n"+
            "the room so you must kill it.\n");
   set_level(7);
   set_hp(105);
   set_wc(11);
   set_ac(6);
   set_al(-100);
   set_a_chat_chance(2);
   load_a_chat("The dragon lashes out at you with its great tail!\n");
   weapon=clone_object("/players/dersharp/weapons/bone");
   move_object(weapon,this_object());
}
