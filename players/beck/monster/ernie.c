inherit "obj/monster";

reset(arg)
{
object gold, weapon;
  ::reset(arg);
  if(arg) return;
set_name("ernie");
set_alias("ernie");
set_short("Ernie");
set_long("Ernie runs the youth center.  He appears to be in his\n"+
"early thirties and is very large (wide).  He is the most cheerful\n"+
"guy you have ever met, and is always ready to assist you.\n");
set_level(8);
set_wc(12);
set_ac(7);
set_hp(135);
set_al(500);
set_aggressive(0);
}
