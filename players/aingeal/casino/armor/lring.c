/* Liberace's diamond ring */

inherit "obj/armor";

reset(arg) {

if(arg) return;
    ::reset();
set_name("Liberace's ring");
set_alias("ring");
set_short("Diamond Ring");
set_ac(2);
set_type("ring"); 
set_weight(1);
set_value(1000);
set_long("Liberace's favorite bauble is an enormous diamond-encrusted\n"+
         "ring in the shape of a grand piano.  It sparkles and glitters\n"+
         "almost blindingly in the light.\n");

}

