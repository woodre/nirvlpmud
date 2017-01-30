inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pain killer");
set_alias("pain");
set_short("pain killer");
set_long("This weapon is stronger than Tylenol in fact it kills everything\n"+
	"including Michaelangelo.  But it doesn't kill AIDS.  AIDS \n"+
	"kills all.  No one is invincible \n");
set_value(1000);
set_weight(5);
set_class(18);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 20) {
write("n\n");
say(attacker->query_name()+" is slammed by "+this_player()->query_name()+"'s PAIN KILLER.\n");
return 10;
   }
return 0;
 }
