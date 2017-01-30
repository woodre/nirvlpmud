inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("Ringer's gloves");
   set_long("This is a pair of gloves , you can see some bloodstains on them but maybe you\n"+
      "can deal deal with it , they seem protective.\n");
   set_ac(1);
   set_weight(1);
   set_value(150);
   set_alias("gloves");
   set_name("gloves");
   set_type("gloves");
}
