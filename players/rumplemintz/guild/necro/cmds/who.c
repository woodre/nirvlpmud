#include "../DEFS"

string cutstring(string str, int i){
    colour_pad(str, i);
    return str;
}

string get_spouse(object obj){
    if(present("wedding ring",obj))
	return cutstring((string)present("wedding ring", obj)->query_spouse(), 12);
    return "            ";
}
string get_oppt(object obj){
    if(obj->query_attack())
	return capitalize((string)obj->query_attack()->query_name());
    return "";
}

string get_race(object obj){
    return cutstring((string)obj->query_race(), 20);
}

string get_gender(object obj){
    return cutstring((string)obj->query_gender(), 6);
}

int cmd(string str){
    int i, a, count, cost, lvl, elvl;
    string msg, z, name;
    object *ppl, attk;
    if(str == "-old")
	return 0;
    count = 0;
    ppl = users();
    ppl = sort_array(ppl,"greater_fun",this_object());
    write("You ask the Realm of Death for knowledge which they gladly "+
      "give you for a price.\n\n");
    write("   <"+HIR+"Necromantic Mud Who"+OFF+">---------------------"+
      "---------------------------------->\n\n"+OFF);
    switch(str){
    case "-b":
	write(BOLD+BLK+pad("",          4)+
	  pad("Name",     13)+
	  pad("Level",    12)+
	  pad("Oppt",     15)+
	  pad("Location", 25)+"\n\n"+OFF);
	cost = 10;
	break;
    case "-s":
	write(BOLD+BLK+pad("",        4)+
	  pad("Name",   13)+
	  pad("Level",  12)+
	  pad("Guild",  18)+
	  pad("Gender", 10)+
	  pad("Spouse", 12)+
	  pad("Race",   15)+"\n\n"+OFF);
	cost = 10;
	break;
    case "-t":
	write(BOLD+BLK+pad("",           8)+
	  pad("Title",     90)+"\n"+OFF);
	cost = 1;
	break;
    default:
	cost = 5;
	write(BOLD+BLK+pad("",          4)+
	  pad("Name",     13)+
	  pad("Level",    12)+
	  pad("Guild",    18)+
	  pad("Location", 25)+"\n\n"+OFF);
	break;
    }
    for(i=0,a=sizeof(ppl); i<a ;i++){
	if(!ppl[i]->query_invis() ||
	  ppl[i]->query_level() < this_player()->query_level() ||
	  this_player()->query_level() > 21){
	    count++;
	    name = capitalize((string)ppl[i]->query_real_name());
	    lvl = (int)ppl[i]->query_level();
	    elvl = (int)ppl[i]->query_extra_level();
	    switch(str){
	    case "-b": 
		z =  pad("", 4);
		z += pad(name,               13);
		if(ppl[i]->query_level() > 99999)
		    z += pad(GRN+"God"+OFF, 21);
		else if(ppl[i]->query_level() > 9999)
		    z += pad(GRN+"Demi-God"+OFF, 21);
		else if(ppl[i]->query_level() > 99)
		    z += pad(GRN+"Admin"+OFF, 21);
		else if(ppl[i]->query_level() > 20)
		    z += pad(GRN+"Dev"+OFF, 21);
		else if(elvl > 0)
		    z += pad(lvl+"+"+elvl, 12);
		else
		    z += pad(lvl, 12);
		z += pad(get_oppt(ppl[i]),   15);
		z += environment(ppl[i])->short()+OFF+OFF;
		write(z);
		break;
	    case "-s":
		write(pad("",                             4)+
		  pad(name,                          13));
		if(ppl[i]->query_level() > 99999)
		    write(pad(GRN+"God"+OFF, 21));
		else if(ppl[i]->query_level() > 9999)
		    write(pad(GRN+"Demi-God"+OFF, 21));
		else if(ppl[i]->query_level() > 99)
		    write(pad(GRN+"Admin"+OFF, 21));
		else if(ppl[i]->query_level() > 20)
		    write(pad(GRN+"Dev"+OFF, 21));
		else if(elvl > 0)
		    write(pad(lvl+"+"+elvl, 12));
		else
		    write(pad(lvl, 12));
		write(pad((string)(ppl[i])->query_guild_name(), 18)+
		  pad(get_gender(ppl[i]),            10)+
		  pad(get_spouse(ppl[i]),            12)+
		  pad(get_race(ppl[i]),              15)); 
		break;
	    case "-t":
		if(ppl[i]->short()){
		    write(pad("",      8)+
		      pad((string)ppl[i]->short(), 90)+OFF);
		} else {
		    write(pad("",     8)+
		      pad((string)ppl[i]->query_name(), 90));
		}
		break;
	    default :
		write(pad("",                            4)+
		  pad(name,                         13));
		if(ppl[i]->query_level() > 99999)
		    write(pad(GRN+"God"+OFF, 21));
		else if(ppl[i]->query_level() > 9999)
		    write(pad(GRN+"Demi-God"+OFF, 21));
		else if(ppl[i]->query_level() > 99)
		    write(pad(GRN+"Admin"+OFF, 21));
		else if(ppl[i]->query_level() > 20)
		    write(pad(GRN+"Dev"+OFF, 21));
		else if(elvl > 0)
		    write(pad(lvl+"+"+elvl, 12));
		else
		    write(pad(lvl, 12));
		write(pad((string)(ppl[i])->query_guild_name(), 18));
		if (environment(ppl[i]))
		    write(pad((string)environment(ppl[i])->short(), 40)+OFF);
		else
		    write(pad("None", 40)+OFF);
		/* 03/31/06 Earwax: attempt at a bug fix 
			  pad(environment(ppl[i])->short(), 40)+OFF);
		*/
		break;
	    }
	    write("\n");
	}
    }
    write(BOLD+BLK+"\n   There are currently "+HIR+count+NORM+BOLD+BLK+
      " players online\n"+OFF);
    write("   <--------------------------------------------------------"+
      "-------------------->\n\n"+OFF);
    if(this_player()->query_sp() > cost)
	this_player()->add_spell_point(-cost);
    return 1;
}



string get_level(object obj){
    string str;
    if(obj->query_level() > 99999)
	str = BOLD+"God"+OFF;
    else if(obj->query_level() > 9999)
	str = BOLD+"Demi-God"+OFF;
    else if(obj->query_level() > 100)
	str = GRN+"Admin"+OFF;
    else if(obj->query_level() > 20)
	str = GRN+"Dev"+OFF;
    else {
	str = (string)obj->query_level();
	if(obj->query_extra_level())
	    str += "+"+obj->query_extra_level();
    }
    return str;
}

string get_enviro(object obj){
    if(environment(obj))
	return (string)environment(obj)->short();
    return "";
}

int greater_fun(object one, object two){
    if(!environment(one))
	return 1;
    if(!environment(two))
	return 0;
    if(one->query_level() == two->query_level())
	return one->query_extra_level() < two->query_extra_level();
    return one->query_level() < two->query_level();
}
