inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("Unholy symbol");
   set_short("An unholy symbol of Arate");
   set_alias("symbol");
   set_long("An unholy symbol of Arate.\n"+
       "It is forged from dark iron, and pulses with an evil aura.\n");
   set_type("amulet");
   set_ac(1);
   set_weight(1);
   set_value(200);
}
quest_ob() { return 1; }
query_save_flag() { return 1; }
