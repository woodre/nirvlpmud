inherit "obj/weapon";
string rowner;

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_name("Lord's Frostreaver");
    set_alt_name("frostreaver");
    set_alias("axe");
    set_short("Dwarf Lord's Frostreaver");
    set_long("This is the mighty axe of the Lord Dwarven Lord.\n");
    set_class(18);
    set_hit_func(this_object());
    set_weight(3);
    set_value(1);
    set_save_flag(0);
    rowner=this_player()->query_real_name();
}
weapon_hit(attacker){
    if(random(30) > 20){
	write("The axe screams through the air.\n");
	say(capitalize(this_player()->query_name())+"'s axe screams through the air.\n",this_player());
	return(8);
    }
}
id(str) {return str == "dquestobj" || str == "axe" || str == "frostreaver";}
