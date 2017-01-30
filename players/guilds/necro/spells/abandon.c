#include "../DEFS"

#define GRAVESITE present("gsite_ob", environment(this_player())) || environment(this_player())->gravesite()
#define BLOODMOON present("bloodmoon", environment(this_player()))
int heal;

cmd(str) {
    int dam,time,cost;
    string caster_msg,room_msg,target_msg;
    object ob, att;

    ob = present(GUILD_ID, this_player());
    if(!ob->checklev(8,15)) return 1;
    if(!str) {
	if(this_player()->query_attack()){
	    att = this_player()->query_attack();
	}
	else{ 
	    notify_fail("Who would you like to abandon all hope?\n"); 
	    return 0; 
	}
    }
    else{
	att = present(str, environment(this_player()));
    }
    if(!att){
	notify_fail("There is no "+str+" here to curse.\n"); 
	return 0;
    }
    if(!att->is_npc()){
	notify_fail("That is not something you can curse.\n");
	return 0;
    }
    if(att->query_prevent_shadow() || att->query_limited_shadow()){
	notify_fail("This monster either has to strong a will or is to stupid to abandon hope.\n");
	return 0;
    }
    cost = att->query_wc()*3; /* 3/4 wc * 4 per round */
    if(this_player()->query_sp() < cost) {
	notify_fail("You do not have the spell points available for this spell.\n");
	return 0; 
    }
    if(ob->query_eye() < 1){
	notify_fail("You do not have the spell components available for the spell.\n");
	return 0;
    }
    caster_msg = "You pull out an eye from your pouch.  As you squeeze it "+att->query_name()+" falls\n"+
    "to the ground in pain.\n";
    room_msg = this_player()->query_name()+" squeezes an eye from "+this_player()->query_possessive()+" pouch.\n"+att->query_name()+" buckles over in pain.\n";
    target_msg = "As "+this_player()->query_name()+" squeezes an eye from "+this_player()->query_possessive()+" pouch your stomach squeezes and you\nfeel the life drain out of you.\n";

    time = random(2)+3;
    if(BLOODMOON){
	time += 1;
	caster_msg+=ROD+"Your spell grows stronger by the presence of the BloodMoon\n";
    }
    if(GRAVESITE) {
	caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
	time += 1;
    }
    write(caster_msg);
    ob->add_val(1);
    ob->add_eye(-1);
    this_player()->add_spell_point(-cost);
    call_out("get_life",1,({this_player(), att, time }));
    return 1;
}


get_life(arg){
    object spell;
    tell_room(environment(arg[1]),BOLD+BLK+"A dark cloud falls over "+OFF+arg[1]->query_name()+OFF+BOLD+BLK+" as they give up all hope.\n"+OFF);
    spell = clone_object(SPELLS+"/abandon_shad.c");
    spell->set_monster(arg[1],arg[2]);  
    arg[1]->stop_fight();
    arg[1]->stop_fight();
}
