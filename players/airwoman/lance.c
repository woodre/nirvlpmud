inherit"obj/weapon";
int dmg, gmuff;
 
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dragon lance");
set_alias("lance");
set_short("The ULTIMATE DRAGON lance");
set_long("A weapon and guild thingy \n");
set_value(1000);
set_weight(0);
set_class(8);
set_hit_func(this_object());
}
get() { return 1;}

drop() { return 1;}
weapon_hit(attacker) {  
if (attacker->query_name()=="dragon"){
say(attacker->query_name()+" has been crushed by"+this_player()->query_name()+"\n");
dmg = attacker->query_hp();
dmg=(dmg*9)/10;
attacker->hit_player(-dmg);
return 1;}
}
 
init(){
	add_action("muff", "muff");
	add_action("wtf", "wtf");
        ::init();
}
muff(str) {
	if(!str) {
	write("Must type muff on or off\n");
	return 1;
	}

	if (str == "on" || str == "ON") {
	gmuff = 1;
	write("Muffs are ON\n");
	return 1;
	}

	if (str == "off" || str == "OFF") {
	gmuff = 0;
	write("Muffs are OFF\n");
	return 1;
	}
}

wtf(str){
        object ob,thing;
	int i;
	if (!str) {
	write("WTF WHAT?\n");
	return 1;
	}
	ob = users();
	for (i = 0; i < sizeof(ob); i++) {
	thing = present("dragon lance", ob[i]);
	if (thing) 
	
	{
	write("FTS\n");
	if (thing->query_gmuff())
	if (gmuff)
                tell_object(ob[i], this_player()->query_name()+": "+str+"\n");
	}
	}
 return 1;
}
