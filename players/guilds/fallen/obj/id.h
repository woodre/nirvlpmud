/*  thanks for the 'format' Snow -- armor / wep restricting id */
/* 03/24/06 Earwax: added id of "GI" */

id(string str){
    if(previous_object()){
       if(!test_eq(previous_object()))
	{
	    return str == "guild_object" || str == "circle_object" ||
	    str == "no_spell" ||
      str == "pro_object" || str == "notweapon" || str == "notarmor" ||
        str == "GI"
	    || str == "guild_monitor"; 
	}
    }
    return str == "guild_object" || str == "circle_object" ||
    str == "no_spell" ||
    str == "GI" ||
    str == "pro_object" || str == "guild_monitor" || str == "no_mini"; 
}

extra_look(){
    if(environment()->is_player()) 
    {
	if(environment() == this_player())
	    return "You are one with the shadows";
	else
	    return environment()->QN+" is one with the shadows";
    }
}

test_eq(ob){
    string armor, weight;
    if(!USER) return;
    if(!ob) return 1;
    if(USER->query_level() > 21) return 1;
    weight = ob->query_weight();
    armor = (string)ob->query_type();
    if(ob->weapon_class()){
	if(duration || !weave || ob->query_info() != "csw") return 0;
	else return 1;
    }
    if(armor == "armor" && weight > 2) return 0;
    else if(armor == "gloves") return 0;
    else return 1;
}

/* Added by Feldegast 11-2-00 */

mini_dest(str) {
    if(this_player())
	write("Your guild forbids you from being a member of a miniguild.\n"+
	  "You leave the "+str+"s.\n");
}
