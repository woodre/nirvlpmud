inherit "obj/monster";
object ob;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("elrond");
set_short("Elrond, King of the Elves");

set_long("Elrond has been the king of the Elves for a long time. He is not about to give it up without a good fight.\n");
set_level(20);
set_hp(500);
set_wc(30);
set_ac(17);
}
