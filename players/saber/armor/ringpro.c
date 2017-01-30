inherit "obj/armor";
reset(arg){
   ::reset(arg);
    set_name("ring of protection");
    set_short("A ring of protection");
   set_alias("ring");
    set_long("A slim ring with a wonderful soft blue glow.\n");
   set_type("ring");
   set_ac(2);
   set_weight(1);
   set_value(100);
}

quest_ob()  { return 1; }
