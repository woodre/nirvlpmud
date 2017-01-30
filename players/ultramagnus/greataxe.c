inherit "obj/weapon.c";

reset(arg){
object axe;
set_name("The Avenger of the Ring");
     set_alias("axe");
     set_short("The Avenger of the Ring");
     set_long("A beautifully carved, bejeweled shaft with a very large, sharp head\n");
     set_class(20);
     set_weight(4);
     set_value(10000);
     set_hit_func(this_object());

}
weapon_hit(attacker)
{
int n;
n=random(10);
if (n>7){
	write("The Avenger slashes through everything, slicing it's victim to                                                                              little pieces!!!!!");
return n-3;
}
return 0;
}
