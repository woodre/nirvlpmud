/*
 * harvest
 * 11/30/2006 - Rumplemintz - strict_types conversion
 * 11/30/2006 - Rumplemintz - Removed include
 */
#define TYPES ({"sword","dagger","knife","axe","blade","katana","blades","sword"})

int cmd(string str){
    string name;
    object ob, wep;
    int c_level, glevel, i, failed;
    string msg, what, cwhat;
    string *types, *file, *bpartarray, *missingpart;
    int *bpartgain;
    bpartarray = ({"blood","skin","eye","eyes","heart","spine","soul"});
    bpartgain = ({1,4,10,15,15,20});
    types = TYPES;
    if(!present("necro_ob", this_player()))
	return 0;
    if(!str){
	notify_fail("What would you like to harvest?\n"); 
	return 0; 
    }
    if(sscanf(str,"%s from %s",what,cwhat) == 2){
	ob = present(cwhat,environment(this_player()));
	if(!ob){
	    notify_fail("There is no "+cwhat+" here.\n");
	    return 0;
	}
	file = explode(file_name(ob),"#");
	if(!ob->query_corpse_level() && file[0] == "obj/corpse"){ 
	    notify_fail("That corpse is worthless to you.\n");
	    return 0;
	}
	if(!ob->query_corpse_level()){
	    notify_fail("That is not something you can harvest.\n");
	    return 0;
	}
	if(member_array(what,bpartarray) == -1){
	    notify_fail("That is not something you can harvest from a corpse.\n");
	    return 0;
	}
	wep = (object)this_player()->query_weapon();
	if(!wep){
	    write("You must have a weapon wielded!\n");
	    return 1;
	}
	if(member_array(wep->query_type(),types) == -1){
	    write("That weapon is not sharp enough to harvest components.\n");
	    return 1;
	}
	if(!present("necro_ob", this_player())->query_harvest() && 
	  !wep->id("necro_tool")){
	    write("You must have your harvesting dagger wielded!\n");
	    return 1;
	}
	if(ob->query_info()){
	    missingpart = explode((string)ob->query_info(), "#");
	    if(member_array("n"+what,missingpart) != -1){
		write("The "+what+
		  " of the corpse has already been removed or damaged beyond use.\n");
		return 1;
	    }
	}
	glevel = (int)this_player()->query_guild_rank();
	if(glevel < 4)
	    glevel = 4;
	c_level = (int)ob->query_corpse_level();
	if(what == "eyes")
	    what = "eye";
	switch(what){
	case "soul":
	    if(c_level > 17 && glevel > random(9)){
		call_other(present("necro_ob", this_player()), "add_soul", 1);
		ob->set_corpse_level((int)ob->query_corpse_level() / 4);
	    } else {
		failed = 1;
		ob->set_corpse_level((int)ob->query_corpse_level() / 2);
	    }
	    ob->set_info(ob->query_info()+"#nsoul");
	    msg = "a soul";
	    break;
	case "heart":
	    if(c_level > 12 && glevel > random(9)){
		call_other(present("necro_ob", this_player()),"add_heart",1);
		ob->set_corpse_level((int)ob->query_corpse_level() / 2);
	    } else {
		failed = 1;
		ob->set_corpse_level(((int)ob->query_corpse_level()*3) / 4);
	    }
	    ob->set_info(ob->query_info()+"#nheart");
	    msg = "a heart";
	    break;
	case "spine":
	    if(c_level > 12 && glevel > random(9)){
		call_other(present("necro_ob", this_player()),"add_spine",1);
		ob->set_corpse_level((int)ob->query_corpse_level() / 2);
	    } else {
		failed = 1;
		ob->set_corpse_level(((int)ob->query_corpse_level()*3) / 4);
	    }
	    ob->set_info(ob->query_info()+"#nspine");
	    msg = "a spine";
	    break;
	case "eye":
	    if(c_level > 7 && glevel > random(7)){
		i = 1;
		if(!random(3))
		    i++;
		call_other(present("necro_ob", this_player()),"add_eye",i);
		ob->set_corpse_level((int)ob->query_corpse_level() / 2);
	    } else {
		failed = 1;
		ob->set_corpse_level(((int)ob->query_corpse_level()*3) / 4);
	    }
	    ob->set_info(ob->query_info()+"#neye");
	    if(i == 2)
		msg = "2 eyes";
	    else
		msg = "an eye";
	    break;
	case "skin":
	    if(c_level > 3 && glevel > random(4)){
		i = random(6)+1;
		call_other(present("necro_ob", this_player()),"add_skin",i);
		ob->set_corpse_level((int)ob->query_corpse_level() / 2);
	    } else {
		failed = 1;
		ob->set_corpse_level(((int)ob->query_corpse_level()*3) / 4);
	    }
	    ob->set_info(ob->query_info()+"#nskin");
	    if(i > 1)
		msg = i+" pieces of skin";
	    else 
		msg = "a piece of skin";
	    break;
	case "blood":
	    i = random(c_level)+1+random(5);
	    if(i > 20)
		i = random(8)+13;
	    call_other(present("necro_ob", this_player()),"add_blood",i);
	    ob->set_corpse_level(((int)ob->query_corpse_level()*3) / 4);
	    ob->set_info(ob->query_info()+"#nblood");
	    if(i == 1)
		msg = "a vial of blood";
	    else 
		msg = i+" vials of blood";
	    break;
	}
	if(failed){
	    write("You try to harvest "+msg+
	      " from the corpse but butcher the removal.\n");
	    say(this_player()->query_name()+
	      " tries to harvest "+msg+" but fails.\n");
	    return 1;
	}
	write("With great care, you harvest "+msg+" from the corpse.\n");
	say("With great care, "+this_player()->query_name()+
	  " harvests "+msg+" from the corpse.\n");
	return 1;
    }
    ob = present(str,environment(this_player()));
    if(!ob)
	ob = present(str,this_player());
    if(!ob){ 
	write("There is no corpse here.\n");
	return 1; 
    }  
    file = explode(file_name(ob),"#");
    if(!ob->query_corpse_level() && file[0] == "obj/corpse"){ 
	notify_fail("That corpse is worthless to you.\n");
	return 0;
    }
    if(!ob->query_corpse_level()){
	notify_fail("That is not something you can harvest.\n");
	return 0;
    }
    ob = present("corpse",environment(this_player()));
    if(!ob)
	ob = present("corpse",this_player());
    if(!ob){ 
	write("There is no corpse here.\n");
	return 1; 
    }  
    wep = (object)this_player()->query_weapon();
    if(!wep){
	write("You must have a weapon wielded!\n");
	return 1;
    }
    if(member_array(wep->query_type(),types) == -1){
	write("That weapon is not sharp enough to harvest components.\n");
	return 1;
    }
    if(!present("necro_ob", this_player())->query_harvest() &&
      !wep->id("necro_tool")){
	write("You must have your harvesting dagger wielded!\n");
	return 1;
    }
    if(sscanf(ob->short(),"corpse of %s",name)){
	c_level = (int)ob->query_corpse_level();
	if(c_level < 1){
	    write("That corpse is worthless to you.\n");
	    return 1;
	}
	if(ob->query_info())
	    missingpart = explode((string)ob->query_info(), "#");
	else
	    missingpart = ({ "", });
	if(c_level > 19 && !random(20) && member_array("nsoul",missingpart) == -1){
	    call_other(present("necro_ob", this_player()),"add_soul",1);
	    msg = "a soul";
	}
	if(c_level > 14 && !random(10) && member_array("nspine",missingpart) == -1){
	    call_other(present("necro_ob", this_player()),"add_spine",1);
	    if(!msg)
		msg = "a spine";
	    else
		msg += ", a spine";
	}
	if(c_level > 14 && !random(10) && member_array("nheart",missingpart) == -1){
	    call_other(present("necro_ob", this_player()),"add_heart",1);
	    if(!msg)
		msg = "a heart";
	    else
		msg += ", a heart";
	}
	i = random(3);
	if(c_level > 9 && i && member_array("neye",missingpart) == -1){
	    call_other(present("necro_ob", this_player()),"add_eye",i);
	    if(!msg){
		if(i == 2)
		    msg = "2 eyes";
		else
		    msg = "an eye";
	    } else {
		if(i == 2)
		    msg += ", 2 eyes";
		else
		    msg += ", an eye";
	    }
	} 
	if(c_level > 3 && !random(2) && member_array("nskin",missingpart) == -1){
	    i = random(6)+1;
	    call_other(present("necro_ob", this_player()),"add_skin",i);
	    if(!msg){
		if(i == 1)
		    msg = "a piece of skin";
		else 
		    msg = i+" pieces of skin";
	    } else {
		if(i == 1)
		    msg += ", a piece of skin";
		else
		    msg += ", "+i+" pieces of skin";
	    }
	}
	i = random(c_level)+1+random(3);
	if(i > 20)
	    i = random(8)+13;
	if(i && member_array("nblood",missingpart) == -1){  
	    call_other(present("necro_ob", this_player()),"add_blood",i);
	    if(!msg){
		if(i == 1)
		    msg = "a vial of blood";
		else 
		    msg = i+" vials of blood";
	    } else {
		if(i == 1)
		    msg += ", and a vial of blood";
		else
		    msg += ", and "+i+" vials of blood";
	    }
	}
	write("You bend over and harvest all you can from the corpse.\n");
	if(msg){
	    write("Quickly you slip "+msg+" into your pouch.\n");
	    say(this_player()->query_name()+
	      ", with great care, rips out "+msg+
	      " from a corpse.\n");
	    say("As blood flies everywhere the corpse is destroyed.\n");
	} else {
	    write("You can't manage to harvest anything from the corpse.\n");
	    say(this_player()->query_name()+" rips apart the corpse.\n");
	}
	present("necro_ob", this_player())->add_harvs(1);
	destruct(ob);
	return 1;
    }
    notify_fail("You don't find a useful corpse here.\n");
    return 0;
}
