inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("signet ring");
   set_short("A signet ring");
   set_alias("ring");
   set_long("A signet ring of the Bardic guild.\n"+
       "It has a Bardic rune upon it.\n");
   set_type("ring");
   set_ac(1);
   set_weight(1);
   set_value(50);
}
