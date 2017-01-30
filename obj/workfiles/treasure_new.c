/*
 * base obj
 * for all Nirvana objs
 * Coded by Vertebraker@Nirvana 2002
 */

string name_of_weapon;  /* Used only for weapons */
string name;            /* Used for all other objs, query_name() */
int    broke;           /* Is item broken? */
int    misses,hits;     /* Hits, Misses.. used primarily for Weps ..
                           these vals have use since they are the only real
                           built-in variables that save for Lockers */
string alt_name;        /* Alternate name */
string alias_name;      /* Alias name */
string alias;           /* See above, a concession */
string *aliases;        /* Array to handle infinite alias adding */
string short_desc;      /* Short description of the item */
string long_desc;       /* Long description */
string read_msg;        /* Msg seen when 'read' */
int    save_flag;       /* Save flag .. 1 for nonsave, 0 for okay */
int    value;           /* Value of obj, in coins */
int    local_weight;    /* Weight of obj */
int    weight;          /* See above, concession time */
string info;            /* Special info about an obj */
string type;            /* Type of item.. used primarily for wep & armor */
static status is_loaded; /* is obj loaded? if not, reset some vals ..
                            needed instead of reset() code to keep
                            things okay */
status dest_flag;       /* Destruct flag for shops */

/* ----- id querying ----- */

status id(string str) {
  if(!aliases) aliases=({});
  return (str==name_of_weapon||
          str==name||
          str==alt_name||
          str==alias_name||
          str==alias||
          str==type||
          member_array(str, aliases)> -1);
}

/* ----- Initialization code ----- */

void init() {
  if(!is_loaded)
  {
    weight=0;
    local_weight=0;
    value=0;
    is_loaded=1;
  }
  add_action("read", "read");
}

/* ----- Id props ----- */

void set_name(string x) {
  name_of_weapon=x;
  name=x;
}

string query_name()
{
  if(name)
    return name;
  else
    return name_of_weapon;
}

void set_id(string x) {
  set_name(x);
}

void set_alias(string x) {
  alias=x;
  alias_name=x;
}

/* ----- New Aliasing ----- */

status add_alias(string x) {
  if(!aliases) aliases=({});
  if(member_array(x,aliases)>-1)
    return 0;
  else
  {
    aliases+=({x});
    return 1;
  }
}

status delete_alias(string x) {
  if(!aliases)
  {
    aliases=({});
    return 0;
  }
  else
  {
    int y;
    if((y=member_array(x,aliases))==-1)
      return 0;
    else
    {
      aliases-=({aliases[y]});
      return 1;
    }
  }
}   

/* ----- Descriptions ----- */

void set_short(string x) {
  short_desc=x;
  if(!long_desc)  /* Added this .. so
                     set_short() can be called again */
    long_desc=(x+".\n");
}

string short() {
  string tmp_short;
  object x;
  tmp_short=short_desc;
  if(broke)
    tmp_short += "[BROKEN]";
/* some day note this level in 'help wiz_levels' ..
   and use <security.h>
*/
  if(info && (x=this_player()) && ((int)x->query_level()>30))
    tmp_short += "{i:"+info+"}";

  return tmp_short;
}

string query_short() {
  return short_desc;
}

void set_long(string x) {
  long_desc=x;
}

void long(string str) {
  write(long_desc);
}

string query_long(string x) {
  return long_desc;
}

/* ----- ints: value, weight, etc. ----- */

void set_value(int x) {
  value=x;
}

int query_value() {
  if(broke) return 0;
  return value;
}

void set_weight(int x) {
  weight=x;
  local_weight=x;
}

int query_weight() {
  if(weight)
    return weight;
  else
    return local_weight;
}

void set_save_flag(int x) {
  save_flag=1;
  if(x > 0)
    save_flag=x;
}

int query_save_flag() {
  if(broke)
    return 1;
  return save_flag;
}

void set_hits(int x) {
  hits=x;
}

void set_misses(int x) {
  misses=x;
}

int query_hits() {
  return hits;
}

int query_misses() {
  return misses;
}

/* ----- special properties ----- */

int get() { return 1; }

void set_read(string x) {
  read_msg=x;
}

string query_read() { 
  return read_msg;
}

void set_info(string x) {
  info=x;
}

string query_info() {
  return info;
}

void set_type(string x) {
  type=x;
}

string query_type() {
  return type;
}

void set_broke(int x) {
  broke=x;
}

int query_broke() {
  return broke;
}

/* ----- new light code ----- */

mixed set_light(int x) {
  if(x)
  {
    int light_val;
    if((light_val=(efun::set_light(0))) > x)
      efun::set_light(light_val-x);
    else
      efun::set_light(light_val-x);
    return;
  }
  else
    return efun::set_light(0);
}

int query_light() {
  return set_light(0);
} 

/* ----- hotel save properties ----- */

status save_thing(string str) {
  save_object(str);
  return 1;
}

status restore_thing(string str) {
  return restore_object(str);
}

/* ----- shop funs ----- */
status query_dest_flag() { return dest_flag; }
void set_dest_flag(int x) { dest_flag=x; }

/* ----- reading ---- */

int read(string str) {
  if(!read_msg) return 0;
  if(!str)
    return (notify_fail("Read what?\n"), 0);
  if(!id(str))
    return (notify_fail("You may only read "+short()+".\n"),0);
  write(read_msg);
  return 1;
}
