/*
    basic/pack.c - A pack of livings, all with the same living_name.
    Jan 1992 by marion@cs.tu-berlin.de
*/

private string pack_name;

int filter_pack (mixed arg);

void
set_pack_name (string str)
{
    set_living_name (pack_name = str);
}

varargs object *
query_all_pack (mixed arg)
{
    object *all;
    object next;

    set_living_name ("");
    if (filter_pack (arg)) {
	all = ({this_object()});
	if (next = find_living (pack_name)) {
	    all += (object *)next->query_all_pack(arg);
	}
    } else {
	if (next = find_living (pack_name)) {
	    all = (object *)next->query_all_pack(arg);
	} else {
	    all = allocate (0);
	}
    }
    set_living_name (pack_name);
    return all;
}

object
query_pack_individual (string fun, mixed arg)
{
    object next;

    if (call_other (this_object(),fun,arg)) return this_object();
    set_living_name ("");
    if (next = find_living (pack_name)) {
	next = (object)next->query_pack_individual (fun, arg);
    }
    set_living_name (pack_name);
    return next;
}

int
filter_pack (mixed arg)
{
    return 1; /* default */
}
