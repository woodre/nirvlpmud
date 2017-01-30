inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("soft minotaur leather");
set_short("Soft minotaur leather");
set_alias("leather");
set_long("A suit of soft leather armor, cut to accomodate a Minotaur's large\n"+
         "frame. Provides decent protection in battle.\n");
set_type("armor");
set_ac(3);
set_weight(2);
set_value(650+random(100));
}
