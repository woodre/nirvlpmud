inherit "obj/armor";
int x;
reset(arg) 
{
   ::reset(arg);
if (arg) return;
   set_name("amulet");
set_short("Amulet of Health");
set_long("This is an amulet that is made by the local town cleric. He\n"+
"sells them for a small price so as to be able to keep his church in\n"+
"good shape. To activate its powers just type 'tonic'.\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(1000);
   set_alias("amulet");
}
init()
{
::init();
add_action("do_tonic", "tonic");
}
do_tonic()
{
x=this_player()->query_sp();
if(x >= 50)

{
write("You activate the talismans powers and feel your health increas but sense that your magical powers have decreased.\n");
this_player()->add_hit_point(25);
this_player()->add_spell_point(-50);
return 1;
}
write("Your magical aura is not strong enough.\n");
return 1;
}
