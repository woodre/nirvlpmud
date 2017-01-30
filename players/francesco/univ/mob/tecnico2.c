inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("andrew");
   set_race("human");
   set_alias("technician");
      set_short("Andrew, the impact test technician");
     set_long("This technician has only one duty:  he must manage the data\n"+
              "acquisition system when the gun shots the bullets.  The main\n"+
              "parameters to be acquired are the the impact force and the\n"+ 
              "bullet speed.\n");

   set_level(15);
   set_hp(225);
   set_al(30);
   set_wc(20);
   set_ac(12);
 gold = clone_object("obj/money");
 gold->set_money(744+random(500));
 move_object(gold,this_object());
}
