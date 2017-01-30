/* Daemon for calls and objects from Bin dir
 * Rumplemintz - 1/7/2007
 */

#define WHITESPACES ({' ','\t','\n'})
#define THIS this_object()
private object *destruct_list = ({});
private object *program_list = ({});
private string wiz_name;
string vars, query_list;
object stores;


init_query(){
  if(query_list) return query_list;
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

rdump(str){
    int tmp, i;
    object ob;
    string flag, path;

    notify_fail("Usage: Dump [<item> [list]]\n");

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

static find_item (prev, str)
{
    object ob;
    string tmp;

    if (str == "here")
	return environment(this_player());
    if (str == "me")
	return this_player();
    if (str == "^")
	return environment(prev);
    if (sscanf(str, "@%s", tmp) == 1)
	return find_living(tmp);
    if (sscanf(str, "*%s", tmp) == 1)
	return find_player(tmp);
    if (str[0] == '/' || str[0] == '~' || str[0] == '.')
	return load_object (this_player () -> valid_read (str));
    if (sscanf(str, "$%d", tmp) == 1) {
	object u;
	u = users();
	write("size: " + sizeof(u) + "\n");
	if (tmp >= sizeof(u) || tmp < 0)
	    return 0;
	return u[tmp];
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

parse_list (str)
{
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

assign (var, val)
{
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

static disp (ob) {
    write(file_name(ob) + "\n");
}

private
varargs strstr2 (str, pat, off)
{
    int p;

    p = strstr (str, pat, off);
    return p == -1 ? -0x80000000 : p;
}

skip_comment (str, pos) {
    return pos + strstr (str,"*/",pos) + 1;
}

skip_string (str, pos)
{
    int lpos;

    while (1)
    {
	lpos = pos;
	if ((pos = strstr (str, "\"", lpos)) == -1)
	{
	    return strlen (str);
	}
	pos = lpos + pos;
	if (str[pos-1] != '\\')
	{
	    return pos;
	}
	pos++;
    }
}

/*
    start and end can be passed
    as call-by-reference parameter (&par)
    and will contain the position of the
    first `(' (after the initial start)
    and the matching `)'
*/
scan_argument (str, start, end)
{
    int pse, pos, pop, pcl, pst, pco, brackets;

    pos = start;
    while (1)
    {
	pop = strstr2 (str, "(", pos);
	pcl = strstr2 (str, ")", pos);
	pst = strstr2 (str, "\"", pos);
	pco = strstr2 (str, "/*", pos);
	pse = strstr2 (str, ";", pos);
	pos++;

	if (pse < pcl && pse < pop && pse < pst && pse < pco)
	    break;
	if (pco < pcl && pco < pop && pco < pst)
	{
	    pos = skip_comment (str, pco + pos);
	}
	else if (pst < pcl && pst < pop)
	    pos = skip_string (str, pst + pos) + 1;
	else if (pop < pcl)
	{
	    pos += pop;
	    brackets++;
	}
	else
	{
	    pos += pcl;
	    brackets--;
	}
	if (brackets == 0)
	{
	    start += strstr (str,"(",start);
	    end = pos - 1;
	    return str[start..end];
	}
    }
    return -1;
}

string
trim_string (string str)
{
    int pos, pos2;

    pos2 = strlen (str) - 1;

    while (pos < pos2 && member (WHITESPACES, str[pos]) >= 0)
	pos++;

    while (pos2 >= 0 && member (WHITESPACES, str[pos2]) >= 0)
	pos2--;

    return str[pos..pos2];
}

string
tab_string (string str, int len)
{
    int t, l;

    l = len - strlen(str);
    if (l <= 0)
	return str;
    for (t=0; t<=l/8; t++)
	str += "\t";
    return str;
}

