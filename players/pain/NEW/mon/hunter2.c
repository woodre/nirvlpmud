object blade,chainmail;
object ring,helm;
object shield;
make_stuff(who) {
     chainmail = clone_object("obj/armor");
        call_other(chainmail, "set_ac",12);
        call_other(chainmail, "set_alias","armor");
        call_other(chainmail, "set_type","armor");
        call_other(chainmail, "set_alias","mail");
        call_other(chainmail, "set_name", "chainmail");
        call_other(chainmail, "set_value", 800);
        call_other(chainmail, "set_short", "A death black chainmail");
        call_other(chainmail, "set_weight",4);
        move_object(chainmail, who);
        helm=clone_object("obj/armor");
        helm->set_ac(2);
        helm->set_name("helmet");
        helm->set_type("helmet");
        helm->set_value(300);
        helm->set_weight(2);
        helm->set_short("A horned steel helmet");
        move_object(helm,who);
        ring=clone_object("obj/armor");
        ring->set_ac(1);
        ring->set_name("ring");
        ring->set_type("ring");
        ring->set_value(900);
        ring->set_weight(1);
        ring->set_long("A plain, black metal ring, it feels a bit warm.\n");
        ring->set_short("A magical ring");
        move_object(ring,who);
        shield=clone_object("obj/armor");
        shield->set_ac(2);
        shield->set_name("shield");
        shield->set_type("shield");
        shield->set_value(800);
        shield->set_weight(3);
        shield->set_long("A large 2'x2' Black metal shield\n");
        shield->set_short("A Black shield");
        move_object(shield,who);
        blade = clone_object("obj/weapon");
    call_other(blade, "set_name", "A black demon blade");
    call_other(blade, "set_short", "A black demon blade");
    call_other(blade, "set_hit_func", this_object());
    call_other(blade, "set_alt_name", "blade");
    call_other(blade, "set_value",5000);
    call_other(blade, "set_class", 18);
    call_other(blade, "set_wield_func", this_object());
    call_other(blade,"set_alias","sword");
     blade->set_save_flag(1);
    move_object(blade, who);
 }

wield(weap) {
    int alig,evil;
    alig = call_other(this_player(),"query_alignment");
    if(alig > 0) {
        write("The blade gives you an electric jolt.\n");
        write("The blade don't like you, you're too stinking good.\n");
        call_other(this_player(),"hit_player",20);
        return 0;
        } else {
        if (evil ==0) {
            evil =1;
            call_other(this_player(),"add_alignment",-10);
            write("You feel more evil.\n");
            }
        return 1;
        }
}

weapon_hit(attacker) {
    int alig,dam;
    alig = call_other(attacker,"query_alignment");
    if(alig > 0){
	dam = random(25);
	if(dam < 10)
	    return 0;
	if(dam < 15)
	    write("The blade flashes.\n");
	else if(dam < 20)
	    write("The blade flashes happily.\n");
	else if(dam < 24)
	    write("The blade flashes happily, and gives out a happy cry.\n");
	else if(dam == 24) {
	    write("The blade flashes happily, and you can feel its evil might.\n");
	    tell_room(this_object(),
		      "The black demon blade flashes !\n");
	    call_other(this_player(),"heal_self",random(10));
	    write("You feel stronger.\n");
	    dam = dam + random(20);
	    if (dam == 43) {
		write("And the blade flashes.\n");
		call_other(this_player(),"heal_self",random(10));
		write("You feel stronger.\n");
		tell_room(this_object(),
			  "The black demon blade flashes, and gives out a happy cry.\n");
	    }
	}
	return dam;
    }
    dam = random(15);
    return dam;
}
query_blade() { return blade; }
query_chain() { return chainmail; }
