/*
 * This is a mudlib file. Copy it to /obj/simul_efun.c, or
 * wherever the get_simul_efun() in master.c says.
 * The functions defined in this file should only be replacements of efuns
 * no longer supported. Don't use these functions any longer, use the
 * replacement instead.
 */

 
inherit "/obj/simul_efun/resolv_path";
inherit "/obj/simul_efun/check_file";
inherit "/obj/simul_efun/exclude_array";
inherit "/obj/simul_efun/emit_channel";

/*
  simul_efun.c
*/
#define MAX_LOG_SIZE 50000
#define COMPAT_FLAG

#include "/sys/wizlist.h"
#if 0
#include "/secure/std.h"
#endif

#pragma strong_types
#pragma save_types
#ifdef COMPAT_FLAG
#define MASTER "obj/master"
#else
#define MASTER "secure/master"
#endif

int file_time(string path)
{
    mixed *v;

    set_this_object(previous_object());
    if (sizeof(v=get_dir(path,4))) return v[0];
}

string create_wizard(string owner, string domain)
{
    mixed result;

    set_this_object(previous_object());
    result =
      (mixed)MASTER->master_create_wizard(owner, domain, previous_object());
    if (stringp(result)) return result;
    return 0;
}

void log_file(string file,string str)
{
    string file_name;
    int *st;

    file_name = "/log/" + file;
#ifdef COMPAT_FLAG
    if (sizeof(regexp(({file}), "/")) || file[0] == '.' || strlen(file) > 30 )
    {
        write("Illegal file name to log_file("+file+")\n");
        return;
    }
#endif
    if ( sizeof(st = get_dir(file_name,2) ) && st[0] > MAX_LOG_SIZE) {
	catch(rename(file_name, file_name + ".old")); /* No panic if failure */
    }
    set_this_object(previous_object());
    write_file(file_name, str);
}

void localcmd() {
    string *verbs;
    int i,j;

    verbs = query_actions(this_player());
    for (i=0, j = sizeof(verbs); --j >= 0; i++) {
	write(verbs[i]+" ");
    }
    write("\n");
}

mixed *unique_array(mixed *arr,string func,mixed skipnum) {
    mixed *al, last;
    int i, j, k, *ordinals;

    if (sizeof(arr) < 32) return efun::unique_array(arr, func, skipnum);
    for (ordinals = allocate(i = sizeof(arr)); i--; )
	ordinals[i] = i;
    al = order_alist(map_objects(arr, func), ordinals, (ordinals=0,arr));
    arr = al[2];
    ordinals = al[1];
    al = al[0];
    if (k = i = sizeof(al)) {
	for (last = al[j = --i]; i--; ) {
	    if (al[i] != last) {
		if (last != skipnum) {
		    arr[--k] = arr[i+1..j];
		    ordinals[k] = ordinals[j];
		}
		last = al[j = i];
	    }
	}
	if (last != skipnum) {
	    arr[--k] = arr[0..j];
	    ordinals[k] = ordinals[j];
	}
    }
    return order_alist(ordinals[k..], arr[k..])[1];
}

#ifdef COMPAT_FLAG
mixed snoop(mixed snoopee) {
    int result;

    if (snoopee && query_snoop(snoopee)) {
        write("Busy.\n");
        return 0;
    }
    result = snoopee ? efun::snoop(this_player(), snoopee)
                     : efun::snoop(this_player());
    switch (result) {
	case -1:
	    write("Busy.\n");
	case  0:
	    write("Failed.\n");
	case  1:
	    write("Ok.\n");
    }
    if (result > 0) return snoopee;
}
#endif

string version() {
    return __VERSION__;
}

#ifndef NO_MAPPINGS
mapping m_delete(mapping m, mixed key) {
    return efun::m_delete(copy_mapping(m), key);
}
#endif

void add_worth(int value, object ob) {
    mixed old;
#ifdef COMPAT_FLAG
    switch (explode(file_name(previous_object()), "/")[0]) {
#else
    switch (explode(file_name(previous_object()), "/")[1]) {
#endif
      default:
	raise_error("Illegal call of add_worth.\n");
      case "obj":
      case "std":
      case "room":
    }
    if (!ob) {
	if ( !(ob = previous_object(1)) )
	    return;
    }
    if (intp(old = get_extra_wizinfo(ob)))
        set_extra_wizinfo(ob, old + value);
}

void wizlist(string name) {
    int i, pos, total_cmd;
    int *cmds;
    mixed *a;
    mixed *b;

    if (!name) {
        name = this_player()->query_real_name();
        if (!name)
            return;
    }
    a = transpose_array(wizlist_info());
    cmds = a[WL_COMMANDS];
    a[WL_COMMANDS] = a[0];
    a[0] = cmds;
    a = order_alist(a);
    cmds = a[0];
    a[0] = a[WL_COMMANDS];
    a[WL_COMMANDS] = cmds;
    if ((pos = member(a[WL_NAME], name)) < 0 && name != "ALL")
        return;
    b = allocate(sizeof(cmds));
    for (i = sizeof(cmds); i;) {
        b[<i] = i;
        total_cmd += cmds[--i];
    }
    a = transpose_array(a + ({b}) );
    if (name != "ALL") {
        if (pos + 18 < sizeof(cmds)) {
            a = a[pos-2..pos+2]+a[<15..];
        } else if (pos < sizeof(cmds) - 13) {
            a = a[pos-2..];
        } else {
            a = a[<15..];
        }
    }
    write("\nWizard top score list\n\n");
    if (total_cmd == 0)
        total_cmd = 1;
    for (i = sizeof(a); i; ) {
        b = a[<i--];
        printf("%-15s %5d %2d%% (%d)\t[%4dk,%5d] %6d %d\n",
          b[WL_NAME], b[WL_COMMANDS], b[WL_COMMANDS] * 100 / total_cmd, b[<1],
          b[WL_EVAL_COST] / 1000,
          b[WL_HEART_BEATS], b[WL_EXTRA], b[WL_ARRAY_TOTAL]
        );
    }
    printf("\nTotal         %7d     (%d)\n\n", total_cmd, sizeof(cmds));
}

/*
 * Function name: exclude_array
 * Description:   Deletes a section of an array
 * Arguments:     arr: The array
 *		  from: Index from which to delete elements
 *		  to: Last index to be deleted.
 * Returns:       
 */
public mixed *
exclude_array(mixed *arr, int from, int to)
{
    return arr[0..from-1] + arr[to+1..sizeof(arr)];
}

/*
 * Function name: exclude_element
 * Description:   deletes an element from an array
 * Arguments:     arr: the array
 *                from: index of the element to remove from the array
 * Returns:       first element of the array, or -1 if failed.
 * Warning:       elements in the array will have been reshuffled somewhat.
 */
public mixed * exclude_element (mixed *arr, int index) {
        arr[index] = arr[0];
        return slice_array (arr, 1, sizeof (arr));
}


/*************************************************************************/

/* Efun: all_environment() */

/*
 * Function name: all_environment
 * Description:   Gives an array of all containers which an object is in, i.e.
 *		  match in matchbox in bigbox in chest in room, would for the
 *		  match give: matchbox, bigbox, chest, room 
 * Arguments:     ob: The object
 * Returns:       The array of containers.
 */
public object *
all_environment(object ob)
{
  object *r;
  
  if (!ob || !environment(ob)) return 0;
  if (!environment(environment(ob)))
      return ({ environment(ob) });
  r = ({ ob = environment(ob) });
  while (environment(ob))
      r = r + ({ ob = environment(ob) });
  return r;
}

/*************************************************************************/

/* Efuns: break_string() and update_actions()
*/

static int gCol;

/*
 * Function name: break_string
 * Description:   Breaks a continous string without newlines into a string
 *		  with newlines inserted at regular intervalls replacing spaces
 *		  Each newline separeted string can be indented with a given
 *		  number of spaces.
 * Arguments:     str: Original message
 *		  width: The total maximum width of each line.
 *		  indent: (optional) How many spaces to indent with.
 * Returns:       A string with newline separated strings
 */
public varargs string
break_string(string str, int width, int indent)
{
    mixed *brkarg;
    string indstr;

    if (indent)
	indstr = extract("                                                                                ", 0, indent-1);
    else
	indstr = "";
    gCol = indent;
    brkarg = ({ width, indstr });
  
    return indstr + 
	implode(map_array(explode(str+" "," "),"brk",this_object(),brkarg)," ");
}

static string brk(string word, mixed *width_indstr)
{
    int width;
    string indstr;

    width = width_indstr[0];
    indstr = width_indstr[1];
    if ((strlen(word)+gCol) > width) {
	gCol = strlen(indstr) + strlen(word) + 1;
	return "\n" + indstr + word;
    }
    else {
	gCol += strlen(word) + 1;
	return word;
    }
}    

/*
 * Function name:   update_actions
 * Description:     Updates this_objects actions in all living objects
 */
public void
update_actions()
{
  int objs;

  if (environment(previous_object()))
    previous_object()->move(environment(previous_object()),1);
  filter_array(all_inventory(previous_object()),"move_inv",previous_object());
}

static void move_inv(object ob) { if (living(ob)) ob->move(previous_object(),1); }

/*************************************************************************/


/* Functions below are useful but should probably not be made into efuns
*/

#if 0
string creator(object ob) { return (string)SECURITY->creator_object(ob); }
#endif
#if 0
string domain(object ob) { return (string)SECURITY->domain_object(ob); }
#endif


static void dump_elem(mixed sak, string tab);

/*
 * Function name: dump_array
 * Description:   Dumps a variable with write() for debugging purposes.
 * Arguments:     a: Anything including an array
 */
public varargs void 
dump_array(mixed *a, string tab)
{
  int n,m;

  if (!tab) tab = "";
  if (!pointerp(a)) {
    write(a); return;
  }
  else write("\n");
  m=sizeof(a);
  n=0;
  while (n<m) {
    write(tab+"["+n+"] = "); dump_elem(a[n],tab); n+=1;
  }
}

status is_clone(mixed ob) {
    return objectp(ob) && member(file_name(ob), '#') >= 0;
}

static void dump_elem(mixed sak, string tab)
{
  if (pointerp(sak)) {
    write("Array: \n"); dump_array(sak,tab+"   ");
  }
  else write(sak);
  write("\n");
}

#if 0
/*
 * The old 'slice_array' is no longer needed. Use range argument inside
 * a pair of brackets instead.
 */
mixed *slice_array(mixed *arr, int from, int to) {
    return arr[from..to];
}

/*
 * filter_objects() has been renamed to filter_array().
 */
mixed *filter_objects(mixed *list, string str, object ob, mixed extra) {
    return filter_array(list, str, ob, extra);
}

#endif
/* This is an addition to the simul_efun file for a fast migration from
 * the -DR parser. Only the ls() function of the original simul_efun need to
 * be commented out
 */
#include "/sys/lpctypes.h"
#define BACKBONE_WIZINFO_SIZE 3
#define ATTRIBUTE_INDEX 2
#define TEXT_WIDTH 70

/*
 * check_ref() is only a fake function.
 * missing: query_arg/this_arg(), remove_action()
 *
 * The following defines might be appropriate when you need to stay with
 * old code and want speed. Put them in an appropriate header file or in
 * the auto_include string.
 *
 * #define caller() previous_object()
 * if using OLD_PREVIOUS_OBJECT_BEHAVIOUR :
 * #define caller() previous_object(0) // always works, but slower
 *
 * #define contents(ob) all_inventory((ob))
 * #define deletem(m, d) efun::m_delete((m), (d))
 * #define this_verb() query_verb()
 * #define atoi(str) to_int(str)
 * #define keys(m) m_indices(m)
 * #define mapp(m) mappingp(m)
 *
 * The following defines have a problem: a parameter is used twice.
 * #define deletea(a, start, end) ((a)[0..(start)-1] + (a)[(end)+1..])
 * #define index(a, d, start)   member((start) ? (a)[(start)..] : (a) , (d))
 * #define searcha(a, d, start) member((start) ? (a)[(start)..] : (a) , (d))
 */

#ifdef COMPAT_FLAG
void reset(int arg) {
    /* wait till we are a simul_efun, and the master is a master... */
    if (!arg) call_out("start_simul_efun", 1);
}
#else
void create() {
    call_out("start_simul_efun", 1);
}
#endif

static void start_simul_efun() {
    mixed *info;

    if ( !(info = get_extra_wizinfo(0)) )
	set_extra_wizinfo(0, info = allocate(BACKBONE_WIZINFO_SIZE));
    if (!info[ATTRIBUTE_INDEX])
	info[ATTRIBUTE_INDEX] = allocate_mapping(0, 1);
    call_out("clean_simul_efun", 900);
}

static void clean_simul_efun() {
    /* There might be destructed objects as keys. */
    m_indices(get_extra_wizinfo(0)[ATTRIBUTE_INDEX]);
    remove_call_out("clean_simul_efun");
    call_out("clean_simul_efun", 3600);
}

varargs void add_attribute(string name, mixed value, object ob) {
    mapping attributes;

    if (!ob) {
	if (objectp(value)) {
	    ob = value;
	    value = 1;
	} else {
	    ob = previous_object();
	}
    }
    attributes =
      (attributes = get_extra_wizinfo(0)[ATTRIBUTE_INDEX])[ob] ||
      (attributes[ob] = allocate_mapping(1, 1));
    if (member(attributes, quote(name))) {
	attributes[quote(name)] = value;
	return;
    }
    attributes[name] = value;
}

varargs void add_prot_attribute(string name, mixed value, object ob) {
    mapping attributes;

    if (!ob) {
	if (objectp(value)) {
	    ob = value;
	    value = 1;
	} else {
	    ob = previous_object();
	}
    }
    efun::m_delete(
      ( (attributes = get_extra_wizinfo(0)[ATTRIBUTE_INDEX])[ob] ||
        (attributes[ob] = allocate_mapping(1, 1)) )
      , name)[quote(name)] = value;
}

#ifndef caller
object caller() {
    return previous_object(1);
}
#endif /* caller */

/* int */ mixed check_ref() {
    /* There are other ways to debug ref counts. Although a simul_efun is
     * possible, I doubt that it would be worth the trouble
     */
    return 42.42;
}

object *contents(object ob) {
    return all_inventory(ob);
}

varargs void delete_attribute(string name, object ob) {
    mapping attributes;

    if (attributes =
	  get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()])
    {
	if (member(attributes, quote(name)))
	    raise_error(
	      sprintf("Error, cannot delete protected attribute %s.\n", name));
	if ( !sizeof(efun::m_delete(attributes, name)) )
	    efun::m_delete(
	      get_extra_wizinfo(0)[ATTRIBUTE_INDEX],
	      ob || previous_object()
	    );
    }
}

varargs mixed
deletea(mixed a, int start, int end) {
    if (!end)           // this isn't really exact
        end = start;    // it should only be done if end is not given
 
    if (end == sizeof(a) - 1)   // avoid "out of bounds"
        return a[0..start - 1];
 
    return a[0..start-1] + a[end+1..];
}

mapping deletem(mapping m, mixed d) {
    return efun::m_delete(m, d);
}

void dumpobjs(int start, int end) {
    object ob;

    rm("/OBJDUMP");
    if (end <= 0) {
	printf("Dumping all objects starting with %d.\n", start);
	end = 0x7fffffff;
    } else {
	printf("Dumping objects %d through %d.\n", start, end);
    }
    write_file("/OBJDUMP",
	sprintf("Object                                  Location\n"));
    for (ob = debug_info(start); ob && start <= end;
					ob = debug_info(2, ob), start++)
       write_file("/OBJDUMP", sprintf("%-40s %s\n", file_name(ob),
               (environment(ob)?file_name(environment(ob)):"None")));
    write("Done.\n");
}

int exists(string file) {
    return file_size(file) != -1;
}

string *files(string path) {
    mixed *a;
    string *b;
    int i, j;

    set_this_object(previous_object());
    a = get_dir(path, 3);
    /* Don't call this locally, unless you add code to set this_object() back */
    b = allocate(j = (i = sizeof(a)) >> 1);
    while (i)
	b[--j] = a[--i] < 0 ? a[--i] + "/" : a[--i];
    return b;
}

string format(string text, int width) {
    if (width < 0)
	raise_error("Bad width given to format(); must be >= 0.\n");
    return sprintf("%*-=s", width || TEXT_WIDTH, text);
}

varargs mixed get_attribute(mixed m, object ob) {
    mapping attributes;

    if (!stringp(m))
	return
	  transpose_array( ({
	    m_indices(
	      attributes =
		get_extra_wizinfo(0)
		  [ATTRIBUTE_INDEX][m || previous_object()] ||
		allocate_mapping(0,1)),
	    m_values(attributes)
	  }) ) ;
    if ( ( attributes =
	     get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()]
	 ) && (mapping_contains(attributes, m , &m) ||
	       mapping_contains(attributes, quote(m), &m))
    )
	return m;
    return -1;
}

varargs string *grab_file(string path, int start, int len) {
    set_this_object(previous_object());
    return explode(read_file(path, start, len), "\n");
    /* Don't call this locally, unless you add code to set this_object() back */
}

int index(mixed a, mixed d, int start) {
    return member(start ? a[start..] : a , d);
}

string pad(mixed str, int len, int padchar) {
    string sp_format;

    str = to_string(str);
    if (len < 0) {
	if (padchar) {
	    sp_format = "%' '*.*s";
	    sp_format[2] = padchar;
	    return sprintf(sp_format, -len, -len, str);
	}
	return sprintf("%*.*s", -len, -len, str);
    }
    if (padchar) {
	sp_format = "%' '-*.*s%s";
	sp_format[2] = padchar;
	return sprintf(sp_format, len, len, str, "");
    }
    return sprintf("%-*.*s%s", len, len, str, "");
}

varargs void print(string text, int width) {
    if (width > TEXT_WIDTH)
	raise_error("Invalid size for argument 2 to print()\n");
    if (width < 0)
	raise_error("Bad width given to print(); must be >= 0.\n");
    write(sprintf("%*-=", width || TEXT_WIDTH, text));
}

varargs mixed query_attribute(string m, object ob) {
    mapping attributes;

    return
      ( attributes =
	    get_extra_wizinfo(0)[ATTRIBUTE_INDEX][ob || previous_object()]
      ) && (member(attributes, m) || member(attributes, quote(m)));
}

static int remote_command_flag;
int command(string str, object ob) {
    /* Don't call this locally, unless you add code to set this_object() back */
    int result;
    object me;
    
    if (!ob) {
	set_this_object(previous_object());
	return efun::command(str);
    }
    if (ob == previous_object()) {
	set_this_object(previous_object());
	return efun::command(str);
    }
    remote_command_flag++;
    me = this_object();
    set_this_object(previous_object());
    result = efun::command(str, ob);
    set_this_object(me);
    remote_command_flag = 0; /* global variable... */
    return result;
}
int remote_command() { return remote_command_flag; }

int root(object ob) {
    return member(file_name(ob || previous_object()), '#') == -1;
}

int searcha(mixed a, mixed d, int start) {
    return member(start ? a[start..] : a , d);
}

static private string *strsub_formats = ({0, "\\<%s\\B","\\B%s\\>","\\<%s\\>"});
string strsub(string input,string *patterns, int mode) {
    int i;
    string format;

    if ( (i = sizeof(patterns)) & 1)
	raise_error("Odd length array given to strsub.\n");
    if (!mode) {
	while (i) {
	    input = implode(explode(input, patterns[<i--]), patterns[<i--]);
	}
	return input;
    }
    format = strsub_formats[mode];
    while (i) {
	input =
	  implode(
	    regexplode(input, sprintf(format, patterns[i--])),
	    patterns[i--]
	  );
    }
    return input;
}

string this_verb() { return query_verb(); }


int atoi(string str) { return to_int(str); }

int cp(string from, string to) {
    string str;

    set_this_object(previous_object());
    rm(to);
    str = read_file(from);
    return write_file(to, str);
    /* Don't call this locally, unless you add code to set this_object() back */
}

int in_editor(object ob) { return query_editing(ob) && 1; }

mixed *keys(mapping m) { return m_indices(m); }

int mapp(mixed m) { return mappingp(m); }

int memused() {
    return rusage()[2];
}

object remove_shadow(object ob) {
    if (!(ob))
	if ( !(ob = previous_object()) )
	    return 0;
    /* we are missing a test here to test for actual shadowing. */
    funcall(bind_lambda(#'unshadow, ob || previous_object()));
    return ob;
}

mixed *reallocate(mixed *a, int size) {
    if (size > sizeof(a))
	return a + allocate(size - sizeof(a));
    return a[0..size-1];
}

string typeof(mixed m) {
    switch(efun::typeof(m)) {
      case T_OBJECT:
	return "object";
      case T_NUMBER:
	return "int";
      case T_POINTER:
	return "vector";
      case T_STRING:
	return "string";
      case T_MAPPING:
	return "mapping";
      default:
	return "";
    }
}

static int last_destruct;
static private mapping destructing = ([]);
varargs void destruct(object ob, int flag) {
object caller;
    if (flag && !member(destructing, ob)) {
	if (last_destruct != time())
	    destructing = allocate_mapping(0,0);
	destructing += ([ob]);
	ob->destructor();
    }
/*
    if ( stringp(ob) ) ob = find_object(ob);
*/
    if ( (caller = previous_object()) == ob )
        efun::destruct(ob);
    catch(ob->remove_object(caller));
    if ( ob )
        efun::destruct(ob);
}

/*
 * The ls() function is no longer needed, as get_dir() can do the same
 * work.
 */
void ls(string path) {
    int max, i, len, tmp;
    status trunc_flag;
    mixed *dir;
    set_this_object(previous_object());
    if (!path)
	path = ".";
    dir = get_dir (path,3);
#if defined(COMPAT_FLAG) && 0
    if (path[0] == '/')
	path = extract(path, 1);
    if (path != "")
	path += "/";
#else
    if (path != "/")
	path += "/";
#endif
    if (!dir) {
	write("No such directory.\n");
	return;
    }
    if (sizeof(dir) > 999)
    {
	dir = dir[0..998];
	trunc_flag = 1;
    }
    for(i = sizeof(dir); i--; ) {
	if(dir[i--] == -2)
	    dir[i]+="/";
	len = strlen(dir[i]);
	if (len > max)
	    max = len;
    }
    ++max;
    if (max > 79)
	max = 79;
    for (i=0; i < sizeof(dir); i+=2) {
	string name;
	    name = dir[i];
	tmp = strlen(name);
	if (len + tmp > 79) {
	    len = 0;
	    write("\n");
	}
	write(name);
	if (len + max > 79) {
	    write("\n");
	    len = 0;
	} else {
	    write(extract(
"                                                                                ",
		80-max+tmp));
	    len += max;
	}
    }
    write("\n");
    if (trunc_flag) write("***TRUNCATED***\n");
}
/*
varargs object
this_player(int x)
{
    return x ? this_interactive() : efun::this_player();
}
*/
/*
 * This is a mudlib file. Copy it to /obj/simul_efun.c, or
 * wherever the get_simul_efun() in master.c says.
 * The functions defined in this file should only be replacements of efuns
 * no longer supported. Don't use these functions any longer, use the
 * replacement instead.
 */

/*
 * The old 'slice_array' is no longer needed. Use range argument inside
 * a pair of brackets instead.
 */
mixed *slice_array(mixed *arr, int from, int to) {
    return arr[from..to];
}

/*
 * filter_objects() has been renamed to filter_array().
 */
mixed *filter_objects(mixed *list, string str, object ob, mixed extra) {
    return filter_array(list, str, ob, extra);
}

/*
 * Define functions to return the proper third person pronoun based on
 * gender.
 */
string subjective(object ob) {
    int gender;
    if (!ob) 
    {
       ob = this_player();
       if (!ob) return "it";
    }
    gender = (int)ob->query_gender();
    if (gender == 1) return "he";
    else if (gender == 2) return "she";
    else return "it";
}

string objective(object ob) {
    int gender;
    if (!ob)
    {
       ob = this_player();
       if (!ob) return "it";
    }
    gender = (int)ob->query_gender();
    if (gender == 1) return "him";
    else if (gender == 2) return "her";
    else return "it";
}

string possessive(object ob) {
    int gender;
    if (!ob) 
    {
       ob = this_player();
       if (!ob) return "its";
    }
    gender = (int)ob->query_gender();
    if (gender == 1) return "his";
    else if (gender == 2) return "her";
    else return "its";
}

/*
// This function recursively replaces a key with a string.
// Variables:
// 		str		The text that needs formatting
//		match		The key that is getting replaced
//		replace		What to replace match with
// Returns:
//		The string we end up with.
*/

string substr(string str, string match, string replace) {
  string foo, fii;
  string reg;
/*
// Do some checking first.
*/
  if( !str || !match )
    return "";
  if( !stringp(str) || !stringp(match) || !stringp(replace) )
    return "";
  if( !replace ) 
    replace = "";
/*
// The loop to replace the text
*/
  reg = "";
  while( sscanf(str, "%s"+match+"%s", foo, fii) ) {
    if( !foo ) 
      foo = "";
    if( !fii )
      fii = "";
    reg += foo + replace;
    str = str[strlen(foo)+strlen(match)..strlen(str)];
  }
  reg += fii;
  return reg;
}

/*
string resolv_path(string p1, string p2) {
  string *comp1, *comp2, tmp1, tmp2;
  int i;
 
  if(!p2 || p2=="") 
    return p1;
  substr(p2, "/./", "/");
  if(p2[0] == '/') 
    return p2;
  if(p2[0] == '~') {
    tmp1 = "/players/" + (string)this_player()->query_real_name() + "/";
    if(p2 == "~")
      return tmp1;
    p2 = extract(p2, 1, strlen(p2));
    comp2 = explode(p2, "/");
    tmp2 = "/players/" + comp2[0];
    if(p2[0] == '/' || !tmp2)
      return resolv_path(tmp1, p2);
    return tmp2+"/"+implode(comp2[1..sizeof(comp2)], "/");
  }
  if(!p1 || p1 == "")
    return p2;
  if(!(comp1 = explode(p1,"/")))
    comp1 = ({});
  if(!(comp2 = explode(p2,"/")))
    comp2 = ({});
  for(i = 0; i < sizeof(comp2); ++i) {
    if(comp2[i] == "..") {
      comp1 = slice_array(comp1, 0, sizeof(comp1) - 2);
      if(comp1 == 0)
	comp1 = ({});
      continue;
    }
    comp1 = comp1 + ({comp2[i]});
  }
  return "/" + implode(comp1,"/");
}
*/

varargs int cat(string file, int first, int second) {
  if(first < 0)
    return tail(file);
  return efun::cat(file, first, second);
}
