inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("ice ring");
   set_alias("ring of ice");
   set_short("An ice crystal ring");
   set_long("A chilled ring of ice crystal.\n"+
      "It makes your soul feel a little bit detatched.\n");
   set_type("ring");
   set_ac(1);
   set_weight(1);
   set_value(750);
}

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
