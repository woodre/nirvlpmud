inherit "obj/armor";
reset(arg) 
{
   ::reset(arg);
if (arg) return;
set_name("shield");
   set_short("Nameless shield");
set_long("An ordinary shield that you could perhaps name is you want too\n");
   set_type("shield");
   set_ac(1);
   set_weight(1);
   set_value(500);
   set_alias("shield");
}
init()
{
add_action("new_short", "name");
add_action("new_type", "type");
}
new_short(str)
{
set_short(str);
set_name(str);
return 1;
}
