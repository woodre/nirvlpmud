int len;

init() {
    if (call_other(this_player(),"query_real_name",) != "gareth")
        destruct(this_object());
    add_action("stone","stone");
    add_action("set","set");
    add_action("set");add_verb("set");
}

short() {
    return "dust";
}

long() {
    write("Just dust, nothing important.\n");
}

id(str) {
    return str == "dust";
}

get(str) {
    if (call_other(this_player(),"query_real_name") != "gareth") {
        write ("It slips through your fingers.\n");
        return 0;
        }
    return 1;
}

stone(str) {
    object statue;
    object person;
    object location;
    
    if (!str)
        return 1;
	
    person = find_living(str);
    if (!person) {
        write(str + " is not playing now.\n");
	return 1;
    }
    statue = clone_object("players/vayde/statue");
    if (len)
        call_other(statue,"set_len",len);
      else
        call_other(statue,"set_len",10);
    call_other(statue,"set_desc", str);
    location = environment(person);
    tell_object(person,"You are turned to stone.\n");
    move_object(person, statue);
    move_object(statue, location);
    tell_room(location,str + " is turned to stone.\n");
    return 1;
}

set(str) {
    string what;
    
    sscanf(str,"%s %d",what,len);
    if (!id(what))
        return 0;
    return 1;
}
