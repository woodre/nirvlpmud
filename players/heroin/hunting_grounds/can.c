inherit "obj/weapon";
int i;
reset (arg) {
:: reset (arg);
if(!arg){
set_name("Bean can");
set_alias ("can");
set_short ("a ordinary can for kickin' around");
set_long ("This is a pork-n-beans can . It is empty.\n Kids play games with cans like these. However I bet if you were in a pinch\n you could use it for a weapon\n");
set_class (15);
set_weight (5);
set_value (600);
}
set_hit_func (this_object());
}
weapon_hit (attacker) {
i = random (20);
if (i>5) {
say (this_player() -> query_name ()+" 's can bounces off you nogin'\n");
write ("You wish you'ld gotten a chance to finish your beans \n before this thing interrupted you\n");
return 1;
}
return 0;
}


