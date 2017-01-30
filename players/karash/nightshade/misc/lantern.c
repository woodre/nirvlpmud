inherit "obj/treasure";
int is_light;
reset(arg) {
if (arg) return;
set_short("Lantern");
set_long
("A nice looking lantern. Should provide a lot of light.\n");
set_weight(1);
set_alias("lantern");
set_value(100);
is_light=0;
}
init()
{
::init();
add_action("do_light", "light");
}
do_light(str)
{
if(!str) return;
if(str == "lantern")
{
  if(is_light) { write("It is already lit!\n"); return 1; }
set_light(1);
write("You light the lantern. It is forever lit.\n");
is_light=1;
return 1;
}
write("Light what?\n");
return 1;
}
