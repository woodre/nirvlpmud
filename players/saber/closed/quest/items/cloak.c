inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("cloak of fire");
   set_short("A cloak of blazing fire");
   set_alias("cloak");
   set_long("A cloak woven from the strands of hellfire.\n"+
      "You feel an evil presence oozing from within it.\n");
   set_type("misc");
   set_ac(2);
   set_weight(1);
   set_value(5000);
}

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
