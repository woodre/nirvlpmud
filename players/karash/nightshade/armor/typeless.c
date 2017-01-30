inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_ac(1);
set_type("armor");
set_weight(1);
set_name("typeless");
set_value(300);
set_short("Typeless armor");
set_long(
"This armor is typeless armor. This means it has no type and you can\n"+
"set it it to whatever type you need. You can choose between these:\n"+
"		Type misc:\n"+
"		Type amulet:\n"+
"          Type ring:\n"+
"		Type shield:\n"+
"		Type armor:\n"+
"		Type boots:\n"+
"All you have to do is this: type < armor type needed >\n");
}
init()
{
::init();
if(environment() == this_player()) add_action("do_set", "type");
}
do_set(str)
{
if(!str) return 0;
if(str == "misc" || "boots" || "amulet" || "armor" || "shield" || "ring")
{
set_type(str);
set_name(str);
set_short("Funky "+str);
write("Ok. Done.\n");
return 1;
}
}
