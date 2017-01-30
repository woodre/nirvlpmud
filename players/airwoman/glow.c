
string vars, query_list;
object stores, locale;

id(str) { return str == "glow ring";}


short() { return "A glow in the dark ring"; }

long() {
    write("A gleaming band of pure dream.  A token of the Sandman's\n");
    write("affection for airwoman, the ruler of his heart.\n");
     write("Type 'info' for a list of commands.\n");
}

get() {
     if(this_player()->query_level() < 21) {
       write("The glow in the dark ring dissolves as you pick it up.\n");
       destruct(this_object());
       return 1;
     }
     return 1;
}

init() {
     if(this_player()->query_level() < 21) {
       write("You touch the ring, and it disintegrates.\n");
       destruct(this_object());
       return 1;
     }
     add_action("echo","echo");
     add_action("quick_go","qgo");
     add_action("echoall","echoall");
     add_action("finger","finger");
     add_action("true_inv","inv");
     add_action("destob", "destob");
     add_action("dest_player","destpl");
     add_action("fear","fear");
     add_action("sp","sp");
     add_action("exp","exp");
     add_action("money","mny");
     add_action("set_wc","setwc");
     add_action("set_title","settitle");
     add_action("set_pretitle","setpretitle");
     add_action("send_player","sendpl");
     add_action("Dump","Dump");
     add_action("Destruct","Destruct");
     add_action("force_command","fc");
     add_action("echoto","echoto");
     add_action("invis_tell","Tell");
     add_action("silent_goto","sgo");
     add_action("help","info");
	add_action("pick", "steal");
}


pick(str) {
	int weight;
	string player, thing;
	object target, ob;

   if(!str) {
   write("Pick what from whom?!\n");
   return 1;
   }

   if(sscanf(str, "%s from %s", thing, player) != 2) {
	write("Pick what from whom?!\n");
	return 1;
   }
 target = present (player, environment(this_player()));
   if (!target) {
       write("No such living thing!\n");
       return 1;
    }
   if (!living(target)) {
      write("You cannot steal from inanimate objects!\n");
	return 1;
     }

   if (target == this_player()) {
      write("You cannot steal from yourself.\n");
      return 1;
   }

    ob = present (thing, target);
    if (!ob) {
	write(target->query_name() + " is not carrying " + thing + ".\n");
	return 1;
      }

   
     call_other(target, "add_weight", -weight);
     ob->drop();
     move_object(ob, this_player());
     write("You steal "+thing+" from "+target->query_name()+".\n");
     return 1;
}
set_pretitle(str) {
     string who, pretitle;

     if(!str || sscanf(str, "%s %s", who, pretitle) != 2) {
       write("Useage:  setpretitle <player> <pretitle>\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not playing now.\n");
       return 1;
     }
     call_other(find_player(who), "set_pretitle", pretitle);
     write(capitalize(who)+"'s pretitle is now: "+pretitle+".\n");
     return 1;
}


destob(str) {
   string who, what;
   object ob;
 
   if(!str || sscanf(str, "%s %s", who, what) != 2) {
     write("Usage: destob <player> <obj>\n");
     return 1;
   }
 
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present(what, find_player(who));
   if(!ob) {
     write(capitalize(who)+" does not have a "+what+".\n");
     return 1;
   }
   destruct(ob);
   write("You dested a "+what+" from "+capitalize(who)+"'s inventory.\n");
   return 1;
}
 
help() {
     cat("/players/airwoman/HELP");
     return 1;
}




money(str) {
     string who;
     int amt;
 
     if(!str || sscanf(str, "%s %d", who, amt) != 2) {
       write("Add money to who?\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     call_other(find_player(who), "add_money", amt);
     write("You gave "+capitalize(who)+" "+amt+" gold coins.\n");
     tell_object(find_player(who), capitalize(this_player()->query_real_name())+
         "has given you "+amt+" gold coins.\n");
     return 1;
}

sp(str) {
     string who;
     int amt;

     if(!str || sscanf(str, "%s %d", who, amt) != 2) {
       write("Sp <who> <amt>\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     call_other(find_player(who), "add_spell_point", amt);
     write("You have given "+capitalize(who)+" "+amt+" spell points.\n");
     return 1;
}

exp(str) {
     string who;
     int amt;

     if(!str || sscanf(str, "%s %d", who, amt) != 2) {
       write("exp <player> <amt>\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on now.\n");
       return 1;
     }
     call_other(find_player(who), "add_exp", amt);
     write("You have given "+capitalize(who)+" "+amt+" experience points.\n");
     tell_object(find_player(who), capitalize(this_player()->query_real_name())+
         "has given you "+amt+" experience points.\n");
     return 1;
}

force_command(str) {
     string who, cmd;

     if(!str || sscanf(str, "%s %s", who, cmd) != 2) {
       write("Force command who to do what?\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     command(cmd, find_player(who));
     write("You silently forced "+capitalize(who)+": "+cmd+"\n");
     return 1;
}
     
dest_player(str) {
    string who;

    if(!str) {
      write("Dest who?\n");
      return 1;
    }
    if(sscanf(str, "%s", who) != 1) {
      write("Destpl <player>\n");
      return 1;
    }
    if(!find_player(who)) {
      write(capitalize(who)+" is not on.\n");
      return 1;
    }
    destruct(find_player(who));
    write(capitalize(who)+" has been destructed.\n");
    return 1;
}

echo(str) {
     if(!str) {
       write("Echo what?\n");
       return 1;
     }
     write("You echo: "+str+"\n");
     say(str +"\n");
     return 1;
}

echoall(str) {
     if(!str) {
       write("Echoall what?\n");
       return 1;
     }
     write("You echoall: "+str+"\n");
     shout(str +"\n");
     return 1;
}

echoto(str) {
     object ob;
     string who, msg;

     if(!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Echoto what?\n");
       return 1;
     }
     ob = find_living(lower_case(who));
     if(!ob) {
       write(capitalize(who)+" is not on now.\n");
       return 1;
     }
     write("You echoto "+capitalize(who)+" : "+msg+"\n");
     tell_object(ob, msg + "\n");
     return 1;
}

invis_tell(str) {
     object ob;
     string who, msg;

     if(!str || sscanf(str, "%s %s", who, msg) != 2) {
       write("Echoto what?\n");
       return 1;
     }
     ob = find_living(lower_case(who));
     if(!ob) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     write("You invis tell "+capitalize(who)+": "+msg+".\n");
     tell_object(ob, "Someone tells you: "+msg+"\n");
     return 1;
}

silent_goto(str) {
     string who;

     if(!str) {
       write("Silent goto who?\n");
       return 1;
     }
     if(str == "home") {
       move_object(this_player(), "players/"+this_player()->query_real_name()+
           "/workroom");
       write("You silently go home.\n");
       return 1;
     }
     if(sscanf(str, "%s", who) != 1) {
       write("Silent goto who?\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     move_object(this_player(),environment(find_player(who)));
     write("You silently goto "+capitalize(who)+".\n");
     return 1;
}





set_wc(str) {
      int amount;

      if(sscanf(str,"%d", amount)) {
        call_other(this_player(),"set_wc",amount);
        write("Weapons class set at "+amount+"\n");
        return 1;
      }
}

set_title(str) {
      string who, title;
     
      if (sscanf(str, "%s %s", who, title))
         if(find_player(who)) {
         call_other(find_player(who),"set_title",title);
      write("Ok.\n");
      return 1;
      }
         if(!find_player(who)) {
            write(who + " is not playing now.\n");
            return 1;
         }
}

send_player(str){


    string who, where;
    
    if(sscanf(str,"%s %s", who, where) != 2)
      write("Send " + who + " " + where + ".\n");
     if(!find_living(who))
      write(who + " is not playing now.\n");
    move_object(find_living(who),where);
    write("Ok.\n");
    return 1;
}


Dump(str) {
    int tmp, i;
    object ob;
    string flag, path;

    if (str == 0) {
	write("All variables:\n");
	while(i<sizeof(vars)) {
	    if (vars[i]) {
		write(vars[i] + ":\t");
		write(stores[i]);
		write("\n");
	    }
	    i += 1;
	}
	return 1;
    }
    if (sscanf(str, "%s %s", path, flag) != 2)
	path = str;
    ob = parse_list(path);
    if (ob == 0)
	return 0;
    if (flag == "list") {
	ob = first_inventory(ob);
	while(ob) {
	    i += 1;
	    write(i + ":\t");
	    write(ob);
	    write("\t" + call_other(ob, "short") + "\n");
	    ob = next_inventory(ob);
	}
	return 1;
    }
    write(ob); write(":\n");
    write(call_other(ob, "short"));
    if (living(ob))
	write("(living) ");
    if (tmp = query_ip_number(ob))
	write("(interactive) '" + query_ip_number(ob) + "' ");
    write("\n");
    if (tmp)
	write("query_idle:\t\t" + query_idle(ob) + "\n");
    tmp = creator(ob);
    if (tmp)
	write("Creator:\t\t" + tmp + "\n");
    if (tmp)
	write("Snooped by " + tmp->query_real_name() + "\n");
    i = 0;
    while(i < sizeof(query_list)) {
	tmp = call_other(ob, query_list[i]);
	if (tmp) {
	    string t;
	    t = query_list[i] + ":";
	    if (strlen(t) < 8)
		t += "\t\t";
	    else if (strlen(t) < 16)
		t += "\t";
	    if (objectp(tmp))
		tmp = file_name(tmp);
	    else if (pointerp(tmp))
		tmp = "<ARRAY>";
	    write(t + "\t" + tmp + "\n");
	}
	i += 1;
    }
    return 1;
}
Destruct(str) {
    object ob;
    ob = parse_list(str);
    if (!ob)
	return 0;
    destruct(ob);
    write("Ok.\n");
    return 1;
}

parse_list(str) {
    string tmp, rest;
    object prev;

    prev = environment(this_player());
    while(prev && str) {
	if (sscanf(str, "%s:%s", tmp, rest) == 2) {
	    prev = find_item(prev, tmp);
	    str = rest;
	    /* disp(prev); */
	    continue;
	}
	prev = find_item(prev, str);
	/* disp(prev); */
	break;
    }
    assign("$", prev);
    if (objectp(prev))
	disp(prev);
    return prev;
}

static disp(ob) {
    write(file_name(ob) + "\n");
}
assign(var, val) {
    int i;

    while(i<sizeof(vars)) {
	if (vars[i] == var) {
	    stores[i] = val;
	    return;
	}
	if (vars[i] == 0) {
	    vars[i] = var;
	    stores[i] = val;
	    return;
	}
	i += 1;
    }
}

reset(arg) {
    if (arg)
	return;
    vars = allocate(5);
    stores = allocate(5);
    query_list = init_query();
}
init_query() {
    if (query_list)
	return query_list;
    query_list = ({
	"query_ac", "query_alignment",
	"query_attack", "query_auto_load", "query_code", "query_create_room",
	"query_dir", "query_exp", "query_frog", "query_ghost",
	"query_hit_point", "query_hp", "query_info", "query_intoxination",
	"query_stuffed", "query_soaked",
	"query_level", "query_listening", "query_max_weight", "query_money",
	"query_name", "query_npc", "query_race", "query_real_name",
	"query_spell_points", "query_title", "query_type", "query_value",
	"query_wc", "query_weight", "query_wimpy", "query_worn",
	"weapon_class", "armor_class", "query_age", "query_gender_string",
    });
    return query_list;
}

static find_item(prev, str) {
    object ob;
    string tmp;

    if (str == "here")
	return environment(this_player());
    if (str == "^")
	return environment(prev);
    if (sscanf(str, "@%s", tmp) == 1)
	return find_living(tmp);
    if (sscanf(str, "*%s", tmp) == 1)
	return find_player(tmp);
    if (sscanf(str, "/%s", tmp) == 1) {
	call_other(tmp, "??");	/* Force load */
        return find_object(tmp);
    }
    if (sscanf(str, "$%d", tmp) == 1) {
	object u;
	u = users();
	write("size: " + sizeof(u) + "\n");
	if (tmp >= sizeof(u) || tmp < 0)
	    return 0;
	return u[tmp - 1];
    }
    if (sscanf(str, "$%s", tmp) == 1) {
	int i;
	while(i<sizeof(vars)) {
	    if (tmp == vars[i])
		return stores[i];
	    i += 1;
	}
	return 0;
    }
    if (prev == 0)
	prev = environment(this_player());
    if (sscanf(str, "\"%s\"", tmp) == 1) {
	ob = first_inventory(prev);
	while(ob && call_other(ob, "short") != tmp) {
	    ob = next_inventory(ob);
	}
	return ob;
    }
    if (sscanf(str, "#%d", tmp) == 1) {
	if (prev == 0)
	    return 0;
	ob = first_inventory(prev);
	while(tmp > 1) {
	    tmp -= 1;
	    if (ob == 0)
		return 0;
	    ob = next_inventory(ob);
	}
	return ob;
    }
    return present(str, prev);
}
fear(str) {
  if (!find_living(str)) return 0;
  write("You make a horrid face at " + capitalize(str) + ".\n");
  say(this_player()->query_name() + " makes a horrid face at " +
   capitalize(str) + ".\n", find_living(str));
  tell_object(find_living(str),this_player()->query_name() +
   " makes a horrid face at you.\n");
  find_living(str)->run_away();
  return 1;
  }
true_inv(str) {
        string who;


      int i;
      object ob;
 
      if(!str) {
        who == this_player()->query_real_name();
      }
      if(sscanf(str,"%s", who) != 1) {
        write("Invalid parameters.\n");
        return 1;
      }
      if(!find_player(who)) {
        write(who+" is not playing now.\n");
        return 1;
      }
      i == 0;
      ob = first_inventory(find_player(who));
      while(ob){

           i += 1;
           write(i+ ":\t");
           write(ob);
           write("\t" + call_other(ob, "short") + "\n");
           ob = next_inventory(ob);
      }
      return 1;
}
string lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
int level, experience, money, age;

finger(str) {
    int days, hours, minutes, seconds;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    if (!str) {
        write("Usage: finger [player name]\n");
        return 1;
    }
    restore_object("players/"+str);
    if (!name) {
        write("That player does not exist.\n");
        return 1;
    }
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")\n");
    write("Level: "+level+"\n");
    write("Experience: "+experience+"\n");
    write("Money: "+money+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+called_from_ip+"\n");
    write("Last login was at: "+lastime+"\n");
    show_age();
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
    return 1;
}

show_age() {
    int i;

    write("Age:\t");
    i = age;
    if (i/43200) {
       write(i/43200 + " days ");
       i = i - (i/43200)*43200;
    }
    if (i/1800) {
       write(i/1800 + " hours ");
       i = i  - (i/1800)*1800;
    }
    if (i/30) {
       write(i/30 + " minutes ");
       i = i - (i/30)*30;
    }
    write(i*2 + " seconds.\n");
}

