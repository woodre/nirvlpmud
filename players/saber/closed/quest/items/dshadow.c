inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("demon's shadow");
   set_short("A demon's shadow");
   set_alias("shadow");
   set_long("The shadow of a demon.  It pulses with an evil aura.\n");
   set_type("misc");
   set_ac(2);
   set_weight(0);
   set_value(500);
}

quest_ob()  { return 1; }
