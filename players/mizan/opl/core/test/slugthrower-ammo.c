
int rounds,value;

string ammo_alias;
string ammo_simple_name;
string ammo_name;
string ammo_type;
string ammo_single_short;
string ammo_plural_short;


string short_desc;
string long_desc;
int my_weight;
int my_power_index;

mixed id(string str)
{
    return str == ammo_simple_name ||
           str == ammo_name ||
           str == ammo_type ||
           str == ammo_alias;
}

void reset(int arg)
{
    if (arg) return;
    /* rounds = 35;
       value = rounds * 3; */
}

void set_short(string arg)
{
    short_desc = arg;
}

string short()
{
    return short_desc + " [" + rounds + "]";
}

void set_long(string arg)
{
    long_desc = arg;
}

void long()
{
    if (long_desc) write(long_desc);
    else write("You see nothing special.\n");

    if(rounds > 1) write("There are [" + rounds + "] rounds left.\n");
    else if(rounds == 1) write("There is [" + rounds + "] round left.\n");
}

int lose_ammo(int i)
{
    if (i) rounds = rounds - i;
    else rounds = rounds - 1;
    return rounds;
}

void set_ammo(int arg) { rounds = arg; }
void set_rounds(int arg) { rounds = arg; }
int query_ammo() { return rounds; }
int query_save_flag() { return 1; }
void set_value(int arg) { value = arg; }
int query_value() { return value; }

int get() { return 1; }

void set_weight(int arg) { my_weight = arg; }

int query_weight() { return my_weight; }

void set_alias(string arg) { ammo_alias = arg; }
void set_simple_name(string arg) { ammo_simple_name = arg; }
void set_name(string arg) { ammo_name = arg; }
void set_type(string arg) { ammo_type = arg; }
void set_single_short(string arg) { ammo_single_short = arg; }
void set_plural_short(string arg) { ammo_plural_short = arg; }
void set_power_index(int arg) { my_power_index = arg; }

/** AMMO SPECIFIC FUNCTIONS **/

/*
 * This describes the ammunition.
 *
 *
 */
string query_ammo_name() { return ammo_name; /* "generic 9.64mm rounds"; */ }

/*
 * this describes a single round of the ammunition
 *
 */
string query_ammo_single_short() { return ammo_single_short; /*"a 9.64mm round"; */ }

/*
 * this describes a plural quantity of this ammunition
 *
 */
string query_ammo_plural_short()
{
    return ammo_plural_short; /*"9.64mm rounds"; */
}

/*
 * a one-word or abbreviated description of what kind of ammo this is.
 *
 */
string query_ammo_type() { return ammo_type; /* "9.64_generic";*/ }

/*
 * The power index specifies in percentage the gain this ammo has over
 * the baseline generic ammo. That baseline is 0 percent gain.
 *
 */
int query_ammo_power_index() { return my_power_index; }