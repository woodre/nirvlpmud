/* changed random to 30% not 60%
- mythos <5-10-96> */

inherit "obj/weapon";
object ob;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("dagger");
set_alias("impslayer");
set_short("Impslayer");
set_long("The infamous dagger of defeating imps. Might be useful against them.\n");
set_weight(1);
set_class(15);
set_value(0);
set_hit_func(this_object());
}
weapon_hit(attacker)
{
ob=this_player()->query_attack();
if(ob->query_race() == "imp");
{
   if(random(100) < 30)
   {
return 5;
   }
}
}
