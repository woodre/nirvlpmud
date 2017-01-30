inherit "obj/armor";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Pirate Hat");
   set_short("A black lego pirate hat");
   set_long("The black hat belonging to the Pirate Captain strangly fits\n"+
            "any sized head.  The skull and cross bones blaze menacingly\n"+
            "across the brim.\n");
   set_value(50);
   set_weight(1);
   set_ac(1);
   set_alias("pirate hat");
   set_type("helmet");
}

id(str) {
   return str == name || str == alias || str == type || str == "hat";
}
