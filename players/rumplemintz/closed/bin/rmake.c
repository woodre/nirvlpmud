private object *destruct_list = ({});
private object *program_list = ({});
private string wiz_name;

rebuild_inherit_list(inh, flag)
{
    int t, il_change, change;
    object ob;

    for (t = 1; t < sizeof(inh); t++) {
	if (ob = find_object(inh[t])) {
	    if (!flag && explode(inh[t],"/")[1] != wiz_name)
		continue;

	    il_change = rebuild_inherit_list(inherit_list(ob), flag);

	    if (file_time("/"+inh[t]) > program_time(ob)) {
		if (member_array(ob, program_list) == -1) {
		    write("Destructing: "+inh[t]+" (object changed).\n");
		    destruct_list += ({ ob });
		}
		change = 1;
	    }
	    else if (il_change) {
		if (member_array(ob, program_list) == -1) {
		    write("Destructing: "+inh[t]+" (inherited object changed).\n");
		    destruct_list += ({ ob });
		}
		change = 1;
	    }
	    else
	    if (member_array(ob, program_list) == -1)
		write(inh[t] + " is up to date.\n");
	}
	else
	if (file_size("/"+inh[t]) < 0)
	    if (member_array(ob, program_list) == -1)
		write(inh[t] + " has been deleted.\n");
	    else {
		if (member_array(ob, program_list) == -1)
		    write(inh[t] + " is not loaded.\n");
		change = 1;
	    }
	program_list += ({ ob });
    }
    return change;
}

make(ob, flag)
{
    string file;
    int t;

    if (this_player())
	wiz_name = this_player()->query_real_name();

    file = explode((objectp(ob) ? file_name(ob) : ob),"#")[0];
    ob = find_object(file);
    if (ob)
	if (rebuild_inherit_list(inherit_list(ob),flag)
	  || file_time("/"+file+".c") > program_time(ob)) {

	    write("Rebuilding \""+file+".\"\n");
	    for (t=0; t<sizeof(destruct_list); t++)
		if (destruct_list[t])
		    destruct(destruct_list[t]);
	    destruct(ob);
	    call_other(file,"???");
	}
	else
	    write("Target is up to date.\n");
    else
	write("No such object");

    destruct_list = ({});
    program_list = ({});

    return 1;
}
