inherit "obj/armor";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("orc shield");
   set_alias("shield");
   set_short("Orc Shield");
   set_long("A small iron shield used by orc warriors. It has a clenched fist\n"+
            "surrounded by a swarm of wasps emblazoned on the face.\n");
   set_weight(1);
   set_value(25+random(25));
   set_ac(1);
   set_type("shield");
}
