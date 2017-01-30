inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_ac(1);
set_type("armor");
set_weight(1);
set_name("whatever you want");
set_value(300);
set_short("Whatever you want armor");
set_long(
"This armor is magical.  It can be shaped into any form you choose.\n"+
"You have the following choices to select from, as your heart desires:\n"+
"               Type misc:\n"+
"               Type amulet:\n"+
"               Type ring:\n"+
"               Type shield:\n"+
"               Type armor:\n"+
"               Type boots:\n"+
"Just enter the magic word: shapearmor < armor type needed >\n");
}
init()
{
::init();
if(environment() == this_player()) add_action("do_set", "shapearmor");
}
do_set(str)
{
if(!str) return 0;
if(str == "misc" || "boots" || "amulet" || "armor" || "shield" || "ring")
{
set_type(str);
set_name(str);
set_short("Magical shaped "+str);
write("You have created the desired armor.\n");
return 1;
}
}
