status lastinv;
object lastob;
status lockon;

/*
query_auto_load () {
    return "players/catwoman/closed/glove:";
}
  no autoloading wiztools per boltar - Mythos <6-8-97>

*/
show (ob) {
    if (!ob) return;
    write (file_name(ob) + ": " + ob->short() + "\n");
}

find_item (str) {
    status path;
    int c;
    if (c = present(str,this_player())) return c;
    if (environment(this_player()) &&
        (c = present(str,environment(this_player())))) return c;
    path = explode (str,":");
    path[0] = find_at(path[0],environment(this_player()));
    for (c=1;c < sizeof(path); c++)
        path[c] = find_at(path[c],path[c-1]);
    return path[c-1];
}

find_at (str,where) {
    status arg;
    if (str[0]=='#') {
        if (objectp(where))
            where = inventorya(where);
        if (!pointerp(where)) return;
        sscanf(str,"#%d",arg);
        if (arg>0 && arg <= sizeof(where)) return where[arg-1];
    }
    if (str[0]=='!') {
        if (str[1]=='!') return lastob;
        else return find_at("#"+extract(str,1),lastinv);
    }
    if (str[0]=='/'){
        str = extract(str,1);
        if (arg = find_object(str)) return arg;
        write ("Loading: /"+str+"\n");
        str->foo();
        return find_object(str);
    }
    if (str=="env" && objectp(where)) return environment(where);
    if (str=="users") return users();
    if (objectp(where) && (arg = present(str,where))) return arg;
    if (arg = find_player(str)) return arg;
    if (arg = find_living(str)) return arg;
}

last_inv () {
    int i;
    write ("Environment: "); show(lastob);
    if (!lastinv) return 1;
    for (i=0;i<sizeof(lastinv);i++)
        if (lastinv[i]) {
            write (i+1); show(lastinv[i]);
        }
    return 1;
}

init () {
if (this_player()->query_level() < 50) return;
    add_action("whom","whom");
    add_action("move","transfer");
    add_action("move","move_object");
    add_action ("move","move");
    add_action("rcommand","command");
    add_action("do_call","call_other");
    add_action("do_call","call");
    add_action("last_inv","lastinv");
    add_action("items","items");
    add_action("nuke","nuke");
    add_action("acquire","acquire");
    add_action("goin","goin");
    add_action("drop_object","drop!");
    add_action("xclone","xclone");
}
drop_object(str) {
if(!str)  {write("Drop what?\n"); return 1; }
if(!present(str,this_player())) {
	write("You don't have it.\n"); return 1;}
	write("You dropped "+str+".\n");
	move_object(present(str,this_player()),environment(this_player()));
return 1; }
whom (str)
{
    status whoz;
    int min_level;
    int i;
    string foo;
    if (str) sscanf(str,"%d",min_level);
    whoz = users();
     for (i=0;i<sizeof(whoz);i++) {
        if (!whoz[i] || whoz[i]->query_level() < min_level) continue;
        foo = whoz[i]->query_real_name();
        if (strlen(foo)<8) foo = foo + "\t";
        foo = (i+1) + "\t" + foo + "\t";
        foo = foo + whoz[i]->query_level();
        if (environment(whoz[i]))
                foo = foo + "\t"+file_name(environment(whoz[i]));
        write (foo + "\n");
    }
    write ("\n");
    return 1;
}

move (str) {
    object ob,targ;
    sscanf(str,"%s %s",ob,targ);
    ob = find_item(ob);
    targ = find_item(targ);
    if (!ob) {
        write ("No such object.\n");
        return 1;
    }
    if (!str) {
        write ("Nowhere to move object to.\n");
        return 1;
    }
    if (transfer(ob,targ) && this_verb()!="transfer")
        move_object(ob,targ);
    return 1;
}

rcommand (str) {
    string targ, cmd;
    sscanf(str,"%s %s",targ,cmd);
    targ = find_item(targ);
    if (targ) command(cmd,targ);
    else write ("No target.\n");
    return 1;
}

do_call (str)
{
    object target;
    string function;
    status arguments;
    int i;
    status result;
    if (sscanf(str,"%s %s %s",target,function,arguments)!=3)
        sscanf(str,"%s %s",target,function);
    target = find_item(target);
    if (!target) {
        write ("No target.\n");
        return 1;
    }
    if (!arguments) {
        write (call_other(target,function));
        write ("\n");
        return 1;
    }
    arguments = explode(arguments,";");
    for (i=0;i<sizeof(arguments);i++) arguments[i]=get_arg(arguments[i]);
    if (sizeof(arguments)==1)
        result = call_other(target,function,arguments[0]);
    else if (sizeof(arguments)==2)
        result = call_other(target,function,arguments[0],arguments[1]);
    else if (sizeof(arguments)==3)
        result = call_other(target,function,arguments[0],arguments[1],
                arguments[2]);
    else if (sizeof(arguments)==4)
        result = call_other(target,function,arguments[0],arguments[1],
                arguments[2],arguments[3]);
    else if (sizeof(arguments)>4)
        result = call_other(target,function,arguments[0],arguments[1],
                arguments[2],arguments[3],arguments[4]);
    write (result);
    write ("\n");
    return 1;
}

get_arg (str) {
    int i;
    if (sscanf(str,"%d",i)) return i;
    if (str[0]=='@') return find_item(extract(str,1));
    if (str[0]=='"') return extract(str,1);
    return str;
}

items (str) {
    object where;
    if (!str) where = environment(this_player());
    else where = find_item(str);
    if (!where) {
        write ("No target.\n");
        return 1;
    }
    lastob = where;
    lastinv = inventorya(lastob);
    return last_inv();
}

nuke (str) {
    object targ;
    targ = find_item(str);
    if (!targ) {
        write ("No target.\n");
        return 1;
    }
    call_out("nukeit",1,targ);
    write ("Nuke: "); show(targ);
    destruct(targ);
    return 1;
}

nukeit (ob) {
    if (!ob) return;
    tell_object(environment(),"Garbage collection\n");
    destruct(ob);
}

acquire (str) {
    str = find_item(str);
    if (!str) {
        write ("acquire what?\n");
        return 1;
    }
    if (transfer(str,this_player())) move_object(str,this_player());
    return 1;
}

goin (str) {
    str = find_item(str);
    if (!str) {
        write ("No target.\n");
        return 1;
    }
    str = file_name(str);
    this_player()->move_player("X#"+str);
    return 1;
}

xclone (str) {
    object ob;
    ob = clone_object(str);
    if (ob) lastob = ob;
    if (ob->get()) move_object(ob,this_player());
    else move_object(ob,environment(this_player()));
    return 1;
}

short () {
   if (this_player() != environment()) tell_object(environment(),
        "scanned by "+this_player()->query_real_name() + "\n");
    return "black silk gloves(worn)";
}

id (str) {
     return str == "gloves" || str == "ND";
}

get () {
    if (this_player()->query_level() > 20) return 1;
}

drop () { return get(); }

