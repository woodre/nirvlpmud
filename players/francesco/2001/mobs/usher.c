inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("usher");
   set_race("human");
   set_alias("usher");
      set_short("An usher");
     set_long("This young guy is wearing a simple uniform with a pin of the \n"+
              "University.  He mostly smiles and acts very kindly to everyone.\n"+  
              "He is likely a student who is trying to make some money for\n"+
              "his studies.\n");
   set_level(12);
   set_hp(180);
   set_al(100);
   set_wc(16);
   set_ac(9);
}
