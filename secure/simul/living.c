
#define BACKBONE_WIZINFO_SIZE 5
#define LIVING_NAME 3
#define NAME_LIVING 4


private mapping living_name_m;
private mapping name_living_m;


void start_simul_efun() {
    mixed *info;

    if ( !(info = get_extra_wizinfo(0)) )
	set_extra_wizinfo(0, info = allocate(BACKBONE_WIZINFO_SIZE));
    if (!(living_name_m = info[LIVING_NAME]))
	living_name_m = info[LIVING_NAME] = m_allocate(0, 1);
    if (!(name_living_m = info[NAME_LIVING]))
	name_living_m = info[NAME_LIVING] = m_allocate(0, 1);
    if (find_call_out("clean_simul_efun") < 0) {
        efun::call_out("clean_simul_efun", 1800);
    }
}

//---------------------------------------------------------------------------
static void clean_simul_efun()
{
    /* There might be destructed objects as keys. */
    m_indices(living_name_m);
    remove_call_out("clean_simul_efun");
    if (find_call_out("clean_name_living_m") < 0)
    {
	call_out(
	  "clean_name_living_m",
	  1,
	  m_indices(name_living_m),
	  sizeof(name_living_m)
	);
    }
    call_out("clean_simul_efun", 3600);
}

//---------------------------------------------------------------------------
static void clean_name_living_m(string *keys, int left)
{
    int i, j;
    mixed a;

    if (left) {
	if (pointerp(a = name_living_m[keys[--left]]) && member(a, 0)>= 0) {
	    i = sizeof(a);
	    do {
		if (a[--i])
		    a[<++j] = a[i];
	    } while (i);
	    name_living_m[keys[left]] = a = j > 1 ? a[<j..] : a[<1];
	}
	if (!a)
	    efun::m_delete(name_living_m, keys[left]);
	call_out("clean_name_living_m", 1, keys, left);
    }
}

//---------------------------------------------------------------------------
protected void set_living_name(string name)
{
    string old;
    mixed a;
    int i;

    if (old = living_name_m[previous_object()]) {
	if (pointerp(a = name_living_m[old])) {
	    a[member(a, previous_object())] = 0;
	} else {
	    efun::m_delete(name_living_m, old);
	}
    }
    living_name_m[previous_object()] = name;
    if (a = name_living_m[name]) {
	if (!pointerp(a)) {
	    name_living_m[name] = ({a, previous_object()});
	    return;
	}
	/* Try to reallocate entry from destructed object */
	if ((i = member(a, 0)) >= 0) {
	    a[i] = previous_object();
	    return;
	}
	name_living_m[name] = a + ({previous_object()});
	return;
    }
    name_living_m[name] = previous_object();
}

//---------------------------------------------------------------------------
object find_living(string name)
{
    mixed *a, r;
    int i;
    
    if (pointerp(r = name_living_m[name])) {
	if ( !living(r = (a = r)[0])) {
	    for (i = sizeof(a); --i;) {
		if (living(a[<i])) {
		    r = a[<i];
		    a[<i] = a[0];
		    return a[0] = r;
		}
	    }
	}
	return r;
    }
    return living(r) && r;
}

//---------------------------------------------------------------------------
/* returns an list of objects that can be found by find_living()
   Basically giving the contents of the living 'name' hash table.
   Used in wizard.c in 'FIND_OBJECT'  

  limitations:  evaluation limits to less then 30

*/

object *find_all_living(string name) {
  object ob, *all;
  closure live;
  int i;

  live = unbound_lambda(({'live_name}),({#'set_living_name,'live_name}));
  for(all = ({}),i = 0; (ob = find_living(name)) && i < 45; i++) {
    if(member(all, ob) != -1) break;
    all += ({ ob, });
    funcall(bind_lambda(live,ob),"DUMMY");
  }
  for(i = sizeof(all); i--; ) {
    funcall(bind_lambda(live,all[i]),name);
  }
  return all;
}

//---------------------------------------------------------------------------
object find_player(string name)
{
    mixed *a, r;
    int i;

    if (pointerp(r=name_living_m[name])) {
	if ( !(r=(a=r)[0]) || !query_once_interactive(r)) {
	    for (i=sizeof(a); --i;) {
		if (a[<i] && query_once_interactive(a[<i])) {
		    r=a[<i];
		    a[<i]=a[0];
		    return a[0]=r;
		}
	    }
	    return 0;
	}
	return r;
    }
    return r && query_once_interactive(r) && r;
}

