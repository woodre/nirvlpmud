inherit "obj/armor";
reset(arg) 
{
   ::reset(arg);
if (arg) return;
   set_name("amulet");
   set_short("Black and silver amulet");
   set_long("This is an amulet worn by the Drow who are of noble birth.\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(500);
   set_alias("amulet");
}
