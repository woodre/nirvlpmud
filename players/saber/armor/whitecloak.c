inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("cloak");
   set_short("A flowing white cloak");
   set_long("A flowing white full body cloak.\n"+
     "It is made of a fine elvish cloth.\n");
   set_type("cloak");
   set_ac(1);
   set_weight(1);
   set_value(200);
}
