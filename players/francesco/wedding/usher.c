inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("usher");
   set_race("human");
   set_alias("usher");
      set_short("An usher");
     set_long("This young guy is wearing an elegant ceremony suit with a pin \n"+
              "reading 'Fantasy/Ceres wedding'. On his right hand he holds a \n"+
              "list where all the invitees are supposed to be reported.  He \n"+
              "mostly smiles and acts very kindly to everyone. \n");
   set_level(12);
   set_hp(180);
   set_al(100);
   set_wc(16);
   set_ac(9);
   set_chat_chance(20);
   load_chat("The usher checks his list.\n");
   load_chat("The usher smiles and looks around for the invitees.\n");
   load_chat("The usher smiles: Show me the invite, I will call a limousine to bring you up.\n");

}

