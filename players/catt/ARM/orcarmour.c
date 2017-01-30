inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
   set_name("orc armour");
   set_alias("armour");
   set_short("Orc armour");
   set_long("This is a set of ring mail used by orc warriors. It is of poor quality\n"+
             "material, but still very servicable.\n");
   set_value(150+random(50));
set_ac(2);
set_type("armor");
}
