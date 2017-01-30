inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("pentagram");
   set_alt_name("pentagram");
   set_alias("pentagram");
   set_short("Sebastian's pentagram");
   set_long("A nice looking pentagram , it could hurt if thrown on your face.\n");
   set_class(10);
   set_weight(2);
   set_type("exotic");
   set_value(200);
}
