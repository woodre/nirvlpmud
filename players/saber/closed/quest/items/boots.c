inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("boots of mist");
   set_short("Boots of Mist");
   set_alias("boots");
   set_long("A pair of silver boots.  They appear to be made from some sort\n"+
      "of mist like substance.  They feel very light.\n");
   set_type("boots");
   set_ac(1);
   set_weight(0);
   set_value(100);
}

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
