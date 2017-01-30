#define NAME "players/gringo/stick:"

id(str) { return ::id(str) || str == "ND"; }
inherit "obj/weapon";

string name, alias, short_desc, long_desc, value, weight,query_list, vars, type;
int worn, ac;
object next,stores, worn_by;
init(arg) {
   ::init(arg);
   if (this_player()->query_real_name() == "gringo") {
   add_action("ident","id");
   add_action("move_another","move");
   add_action("silent_goto","sgo");
   add_action("snooper_on","snoopon");
   add_action("snoop_off","snoopoff");
   add_action("snooper","eavesdrop");
   add_action("restart","restart");
   add_action("rotfl","rotfl");
   add_action("tell","tell");
   add_action("grimace","grimace");
   add_action("echoall","echoall");
   add_action("echoto","echoto");
   add_action("emote",":",1);
   add_action("quit","quit");
   add_action("snoop_on","snoop");
   add_action("log","log");
   add_action("_reset_room"); add_verb("oreset");
   add_action("cloneother"); add_verb("oclone");
   add_action("_get"); add_verb("get!");
   add_action("_put"); add_verb("put!");
   add_action("scan"); add_verb("scan");
   add_action("force_us"); add_verb("make");
   add_action("poke"); add_verb("poke");
   add_action("transport"); add_verb("go");
   add_action("bearhug","bearhug");
   add_action("shy_smile","shy");
	add_action("Dump", "dump");
        add_action("Destruct", "destr");
	add_action("Call", "call");
	add_action("Trans", "trans");
	add_action("Clean", "clean");
        add_action("Set", "set");
        }
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
    tmp = query_snoop(ob);
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

Call(str) {
    string with, what, item;
    int iwhat;
    object ob;
    int ret;

    if (!str)
        return 0;
    if (sscanf(str, "%s %s %d", item, with, what) == 3)
        iwhat = 1;
    else if (sscanf(str, "%s %s %s", item, with, what) != 3) {
	if (sscanf(str, "%s %s", item, with) == 2)
	    iwhat = 0;
	else
	    return 0;
    }
    ob = parse_list(item);
    if (!ob)
	return 0;
    ret = call_other(ob, with, what);
    if (intp(ret))
	write("Got int " + ret + "\n");
    else if (pointerp(ret))
	write("Array of size " + sizeof(ret) + "\n");
    else if (stringp(ret))
	write("String: '" + ret + "'\n");
    else if (objectp(ret)) {
	write("Object: "); write(ret);
	write("\n");
    }
    assign("ret", ret);
    return 1;
}

Clean(str) {
    object ob, o, n;

    if (!str)
	return 0;
    ob = parse_list(str);
    if (!ob)
	return 0;
    for (n = first_inventory(ob); n; n = o) {
	o = next_inventory(n);
	if (query_ip_number(n))
	    continue;
	destruct(n);
    }
    write("Ok.\n");
    return 1;
}

Trans(str) {
    object mark;

    if (!str)
	return 0;
    mark = parse_list(str);
    if (!mark)
	return 0;
    if (call_other(mark, "get")) {
	if (transfer(mark, this_player()) != 0) {
	    write("Failure.\n");
	    return 1;
	}
    } else {
	move_object(mark, environment(this_player()));
    }
    write("Ok.\n");
    return 1;
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

Set(str) {
    object ob;
    string item, var;

    if (!str)
	return 0;
    if (sscanf(str, "%s %s", var, item) != 2)
	return 0;
    ob = parse_list(item);
    if (!ob)
	return 0;
    assign(var, ob);
    return 1;
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
  ::reset(arg);
    if (arg)
	return;
    vars = allocate(5);
    stores = allocate(5);
    query_list = init_query();
    set_light(25);
    set_class(55);
    set_name("crooked stick");
    set_alias("stick");
    set_weight(0);
    set_short("a little crooked stick");
    set_long("A little crooked stick that looks fragile.\n");
}


init_query() {
    if (query_list)
	return query_list;
    query_list = ({
	"query_ac", "query_alignment",
	"query_attack", "query_auto_load", "query_code", "query_create_room",
	"query_dir", "query_exp", "query_frog", "query_ghost",
	"query_hit_point", "query_hp", "query_info", "query_intoxination",
	"query_level", "query_listening", "query_max_weight", "query_money",
	"query_name", "query_npc", "query_race", "query_real_name",
	"query_spell_points", "query_soaked", "query_stuffed",
	"query_title", "query_type", "query_value",
	"query_wc", "query_weight", "query_wimpy", "query_worn",
	"weapon_class", "armour_class", "query_age", "query_gender_string",
	"query_str", "query_dex", "query_con", "query_int",
    });
    return query_list;
}

transport (arg) {
     object ob;

     ob = find_living(arg);
      if (ob) {
         move_object(this_player(),environment(ob));
         return 1;
       }
  call_other(this_player(),"move_player",arg);
  return 1;
}

poke(arg) {
  object who;

  if (!arg) {
     write("You poke the room.\n");
     say(this_player()->query_name()+" pokes you with a rib-crunching "+
     "sound(tm).\n");
     return 1;
  }
  who = present(arg,this_player());
  if (!who) who = present(arg,environment(this_player()));
  if (!who) {
     who = find_living(arg);
     if (who && !(present("Someone",this_player()) ||
         present("Someone",environment(this_player())))) {
         say(this_player()->query_name()+" pokes "+who->query_name()+
             " with a rib-crunching sound(tm).\n");
         tell_object(who,this_player()->query_name()+" pokes you with "+
                     "a rib-crunching sound(tm).\n");
         tell_room(environment(who),this_player()->query_name()+" "+
                   "pokes "+who->query_name()+" with a rib-crunching "+
                   "sound(tm).\n");
         return 1;
     }
  if (!who) return 0;
  write("You poke "+capitalize(arg)+".\n");
  say(this_player()->query_name()+" pokes "+who->query_name()+
      " with a rib-crunching sound(tm).\n",who);
  tell_object(who,this_player()->query_name()+" pokes you with a rib-"+
              "crunching sound(tm).\n");
  return 1;
}
}

echoto(arg) {
  string mesg, destin;
  object who;

  sscanf(arg,"%s %s",destin, mesg);
  who = find_living(destin);
  if (!who) {
  write("That person is not currently signed on.\n");
  return 1;
}
  tell_object(who,mesg + "\n");
  write("You echo: "+mesg+" (to "+who+").\n");
 return 1;
}


force_us(arg) {
  object who, ob, what;

  sscanf(arg, "%s %s",who,what);
  ob = find_living(who);
        command(what, ob);
  return 1;
}

scan(str) {
    object ob;
    ob = find_living(str);
    if (!living(ob)) return 0;
    write(str+" has "+ call_other(ob,"query_hp") + "hp and "+
          call_other(ob,"query_spell_point")+"sp.\n");
    write(str+" is " + call_other(ob,"query_level") + "th level.\n");
    return 1;
}

_reset_room(arg) {
   call_other(arg,"reset");
   call_other(arg,"init");
   return 1;
}

_get(arg) {
  object ob;

  ob = present(arg, environment(this_player()));
  move_object(ob, this_player());
  return 1;
}
  
_put(arg) {
  string a,b;
  object ob1, ob2;

  sscanf(arg,"%s %s",a,b);
  ob2 = find_living(b);
  ob1 = find_living(a);
  if (ob1 == this_player()) {
     move_object(this_player(),ob2);
     return 1;
     }
  ob1 = present(lower_case(a), this_player());
  move_object(ob1, ob2);
  return 1;
}

ident(str) {
  object ob;
  string s;
  if (!str) {
     write("identify what?\n");
     return 1;
  }

  ob = present(str);
  if (!ob) ob = present(str,environment(this_player()));
  if (!ob) {
     write("You don't have that item.\n");
     return 1;
  }

  s = call_other(ob,"query_id",0);
  if (s) {
     call_other(ob,"set_id",s);
     call_other(ob,"set_name",s);
     call_other(ob,"set_short",s);
  }

  s = call_other(ob,"short");
  write("Name: "); write(s); write("\n");

  s = call_other(ob,"query_alias");
  if (s) {
     write("Alias: "); write(s); write("\n");
  }

  s = call_other(ob,"query_type");
  if (s) {
     write("Type: "); write(s); write("\n");
  }

  s = call_other(ob,"weapon_class");
  if (s) {
     write("Weapon class: "); write(s); write("\n");
  }

  s = call_other(ob,"armour_class");
  if (s) {
     write("Armor class: "); write(s); write("\n");
  }

  s = call_other(ob,"query_value");
  if (s) {
     write("Value: "); write(s); write("\n");
  }

 s = call_other(ob,"query_weight");
 if (s) {
    write("Weight: "); write(s); write("\n");
  }

  return 1;
}

rec_short()
{
 if(next)
 return name + ", " + call_other(next,"rec_short");
 return name;
}


log(arg) {
  string a,b;
  sscanf(arg,"%s %s",a,b);
  log_file(a,b+"\n");
}

query_auto_load() { return NAME; }

snoop_on(arg) {
  object player;

  if (!arg) { snoop(); return 1; }
  player = find_living(arg);
  if (player) {
     snoop(player);
   }
  return 1;
}

emote(arg) {
    string verb;

    verb = query_verb();
    if (arg == 0) arg = "";
    if (verb[0] == ":"[0]) arg = extract(verb,1) + " " + arg;
  say(this_player()->query_name()+" "+arg+"\n");
  write("=> "+this_player()->query_name()+" "+arg+"\n");
  return 1;
}

quit() {
  string name;

  name = call_other(this_player(),"query_name");
  call_other(this_player(),"save_me",0);
  call_other(this_player(),"drop_all",1);
  destruct(this_player());
  return 1;
}

a() {
  string name;

  name=call_other(this_player(),"query_name");
  if (name != "Someone")
  shout("You feel much better, now that "+name+" has arrived.\n");
  write("You announce your arrival.\n");
  return 1;
}

echoall(arg) {
  if (!arg) return 0;
  shout(arg+"\n");
  write("You echoed to the world: "+arg+"\n");
  return 1;
}

grimace() {
  write("You grimace.\n");
  say(call_other(this_player(),"query_name")+" grimaces.\n");
  return 1;
}

tell(arg) {
   object who;
   string what;

   sscanf(arg,"%s %s",arg,what);
   who = find_living(arg);
   if (!who) {
      write("That player is not online.\n");
      return 1;
   }
   write("You tell "+arg+": "+what+"\n");
   what = call_other(this_player(),"query_name",0)+ " tells you: " +
          what + "\n";
   tell_object(who,what);
   return 1;
}

rotfl() {
   say(call_other(this_player(),"query_name",0)+" rolls on the floor laughing.\n");
   write("You roll on the floor laughing.\n");
   return 1;
}


get() {return 1;}

drop() { return 1; }


snooper_on() { 
   object snooper;

    snooper = find_living("snooper");
   if (snooper) call_other(snooper,"on");
   return 1;
}

snoop_off() {
   object snooper;

    snooper = find_living("snooper");
    if (snooper) call_other(snooper,"off");
     return 1;
}

silent_goto(arg) {
  object destination;

   destination = find_living(arg);
   if (!destination) destination=find_object(arg);
   if (destination) destination = environment(destination);
   if (!destination) return 0;
   move_object(this_player(),destination);
  return 1;
}

move_another(arg) {
  string who,where;
  object ob;

  if (sscanf(arg,"%s %s",who,where)!=2) return;
  ob = find_player(who);
  if (!ob) return;
  ob->move_player("X#"+where);
  return 1;
}

bearhug(arg) {
  object target;
  string me,name,message;

  me = this_player()->query_name();
  if (arg) {
     target = present(arg,environment(this_player()));
     if (!target) target = present(arg,this_player());
     if (!target) return 0;
     name = target->query_name();
     message = "You bearhug "+name+" and spin "+
               target->query_objective()+" around the room.\n";
     write(message);
     message = me+" bearhugs you and spins you around the room.\n";
     tell_player(target,message);
     message = me+" bearhugs "+name+" and spins "+
               target->query_objective()+" around the room.\n";
     say(message,target);
     return 1;
  }
  return 0;
}

shy_smile(arg) {
  object target;
  string me,name,message;

  if (!arg) {
     write("You smile shyly.\n");
     say(me+" smiles shyly.\n");
     return 1;
  }
  
  target = present(arg,environment(this_player()));
  if (!target) target = present(arg,this_player());
  if (!target) return 0;
  write(message);
  message = me + " smiles shyly at you.\n";
  tell_player(target,message);
  return 1;
}
