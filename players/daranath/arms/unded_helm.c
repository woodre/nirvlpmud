inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("darkened helmet");
   set_short("A darkened helmet");
   set_alias("helmet");
   set_long("Once a magnificent silver helm, the armor has been\n"+
            "corrupted by evil over time.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(600);
}
