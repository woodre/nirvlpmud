inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("Melko's cloak");
   set_long("This is the cloak of Melko, a purple and long cloak, ancient and forgotten runes\n"+
            "are embroidered on it with gold threads. It seems extremely protective.\n");
   set_ac(2);
   set_weight(1);
   set_value(15500);
   set_alias("purple cloak");
   set_name("cloak");
   set_type("cloak");
}
