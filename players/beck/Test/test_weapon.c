inherit "/players/beck/updates/weapon.c";
int w;
reset(arg) {
::reset(arg);
        if(!arg) {
set_name("staff");
set_class(18);
set_value(6900);
set_weight(4);
set_alias("staff");
set_short("Lord Zed's Staff");
set_long("This wooden staff is rather plain except for the giant\n"+
"letter Z placed at the top.\n");
set_hit_func(this_object());
set_params("other|fire",0,"weapon_hit");
}
}
wield(arg) {
if(::wield(arg));
if(id(arg)) {
write("You feel a surge of...POWER!\n");
}
return 1;
}
weapon_hit(attacker)
{
w=random(20);
if (w>16) {
say("The giant Z on Lord Zed's Staff glows bright red.\n"+
"A giant fireball engulfs the ememies face and head.\n");
write("You launch a fireball right into the enemies face!\n");
return 15;
}
}
query_save_flag() { return 1; }
