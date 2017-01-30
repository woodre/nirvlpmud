inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("dwarven chainmail");
   set_short("Dwarven chainmail");
   set_alias("chainmail");
   set_long("A suit of dwarven made chainmail.\n"+
       "It looks very well made.\n");
   set_ac(4);
   set_weight(3);
   set_value(400); /*dwarfs might pay more*/
}
