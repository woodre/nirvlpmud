/*
 * A generic piece of armour
 * It handles multi-type and locker saving
 * Balowski@Nirvana
 */
#pragma strict_types
#include "/players/guilds/bards/bard_lib/lib.h"
#define ARMOR "obj/armor"
inherit ITEM;
mixed	Type;
int	Size, ac;
static object	WornBy, Next;
#define sizetostr(x)\
 ((x == 1) ? "XS" : (x == 2) ? "S" : (x == 3) ? "M" : (x == 4) ? "L" : "XL")
#define strtosize(x)\
 ((x == "XS") ? 1 : (x == "S") ? 2 : (x == "M") ? 3 : (x == "L") ? 4 : 5)


void	set_type(mixed t) { Type = t;}
void	set_size(mixed s) { Size = (intp(s) ? s : strtosize(s));}
void	set_ac(int c) { ac = c;}

status	query_worn() { return objectp(WornBy);}
object	query_worn_by() { return WornBy;}
string	query_type() { return pointerp(Type) ? Type[0] : Type;}
string *query_types() { return (stringp(Type) ? ({Type}) : Type);}
int	query_size() { return Size;}
int	armor_class() { return ac;}
string	query_type_string() {return pointerp(Type) ? implode(Type,"*") : Type;}

status is_type(string t) {
    if (pointerp(Type)) {
	return (member_array(t, Type) >= 0);
    }
    else {
	return (t == Type);
    }
}

static status type_match(object ob) {
    string *ts;
    if (ts = (string *)ob->query_types()) {
	/* this is a bit crap.. but for compatability */
	int i;
	i = sizeof(ts);
	while (i--) {
	    if (is_type(ts[i])) return 1;
	}
    }
    else {
	string t;
	t = (string)ob->query_type();
	return (is_type(t));
    }
}

void create()
{
    ::create();
    Type = "armor";
}

void init()
{
    add_action("cmd_wear", "wear");
}

void ev_wear(object who)
{
    /*who->wear(this_object()); wouldn't work*/
    WornBy = who;
}

void ev_remove()
{
    WornBy->stop_wearing(query_name());/* should it be here? */
    WornBy = 0;
}

status prevent_remove(int silently)
{
}

status prevent_wear(object who)
{
    object ob;

    if (present("notarmor", who)) {
        tell_object(who, "For some reason you are unable to wear armor.\n");
        return 1;
    }
    if (Size) {
        int tmp; /* the player's body size */

        tmp = (int) ARMOR->find_size(who);
        if (tmp > Size) {
            tell_object(who, "You find that it is too small for you.\n");
            return 1;
        }
        if (tmp < Size - 1) {
            tell_object(who, "It is far too big for you, it simply falls off.\n");
            return 1;
        }
        if (tmp < Size)
	  tell_object(who, "It's a little big, but you can wear it.\n");
    }

    ob = first_inventory(who);
    while (ob) {
	/* cannot wear in layers */
	if (ob->query_worn()) {
	    if (type_match(ob)) {
		tell_object(who, "You cannot wear it over your " +
			    ob->query_name() + ".\n");
		return 1;
	    }
	}
	/* shields cannot be worn with an off-wielded weapon */
	if (ob->query_offwielded() && is_type("shield")) {
	    tell_object(who, "You have an offwielded weapon!\n");
	    return 1;
	}
	ob = next_inventory(ob);
    }
}

status cmd_wear(string str)
{
    if (id(str))
        notify_fail("You are unable to wear it.\n");
}

int drop(int silently)
{
    if (::drop(silently)) return 1;
    if (objectp(WornBy)) {
        /* if it's a player and he is alive, see if he can remove */
        if (WornBy->is_player() && !WornBy->query_ghost()
        &&  prevent_remove(silently))
            return 1;

        /* actually, there is a problem here with unique names/ids */
        /*worn_by->stop_wearing(name); see ev_remove()*/
        ev_remove();
    }
}

/*
 * This function is called by the ready command
 * It's kinda bad to duplicate parts of my wear command..
 */
void wear(string arg)
{
    if (WornBy != this_player() && !prevent_wear(this_player()))
        if (this_player()->wear(this_object()))
            write("You are already wearing a similar piece of armour.\n");
        else
            ev_wear(this_player());
}

#if 1
string short()
{
    string tmp;

    if (!(tmp = ::short())) return 0;
    if (Size) tmp += " [" + sizetostr(Size) + "]";
    if (query_worn()) tmp += " (worn)";
    if (this_player() && (int) this_player()->query_level() > 30) {
	tmp += "  < ac " + ac + ", " + query_type_string() + " >";
    }
    return tmp;
}

void long(string str)
{
    ::long(str);
    /* I am not so happy about this, what if: "look at engravings" */
    /* well well.. long sucks anyway */
    if (Size) write("Size: [" + sizetostr(Size) + "]\n");
}

#else
/*
 * Having short() return 0 doesn't work so well with the main lib
 */
string short()
{
    if (!WornBy)
        return (string) ::short();
}

string extra_look()
{
    if (WornBy) {
        if (WornBy == this_player())
            return "You are wearing " + query_short();
        else
            return WornBy->query_name() + " is wearing " + query_short();
    }
}
#endif

/*
 * the old chained list implementation of armours
 */
object remove_link(string str)
{
    /* would've been more appropiate to use type, but for old times sake */
    if (str == query_name()) {
	object ob;
	ob = Next;
	Next = 0;
	return ob;
    }
    if (Next)
	Next = (object) Next->remove_link(str);
    return this_object();
}

void link(object ob) {
    Next = ob;
}

string rec_short() {
    return (query_name() + (Next ? ", " + (string)Next->rec_short() : ""));
}

int tot_ac() {
    return ac + (Next && (int) Next->tot_ac());
}

object test_type(string t) {
    return (is_type(t)) ? this_object()
      			: (Next && (object) Next->test_type(t));
}

/*
 * For saving stuff
 * It's a bit too complicated to be easy to add more vars
 * mostly because of the thief locker compat stuff
 */
varargs mixed locker_arg(int mix)
{
    if (mix) {
	mixed *al;
	al = insert_alist("Type", Type, ::locker_arg(mix));
	al = insert_alist("Size", Size, al);
	al = insert_alist("ac", ac, al);
	return al;
    }
    return Type +" "+ Size +" "+ ac +" "+ ::locker_arg(mix);
}

void locker_init(mixed arg)
{
    if (pointerp(arg)) {
	Type = assoc("Type", arg);
	Size = assoc("Size", arg);
	ac = assoc("ac", arg);
	::locker_init(arg);
    }
    else if (stringp(arg)) {
	string a0, s; int a1, a2;
	if (sscanf(arg, "%s %d %d %s", a0, a1, a2, s) >= 4) {
	    Type = a0; Size = a1; ac = a2;
	    ::locker_init(s);
	}
    }
}

#if 0
/* consider this: (makes it necessary to do to_alist, tho) */
mixed locker_arg()
{
    mapping m;
    m = ::locker_arg();
    m["Type"] = Type; m["Size"] = Size; m["ac"] = ac;
    return m;
}

void locker_init(mapping m)
{
    ::locker_init(m);
    Type = arg["Type"]; Size = arg["Size"]; ac = arg["ac"];
}
#endif
