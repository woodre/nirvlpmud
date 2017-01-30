#pragma strict_types
#pragma save_types
#pragma combine_strings

/*
 *  Base Object for all objects
 *
 */

#include "/include/mudlib.h"
#include "/include/fn_specs/base_obj.spc"
#include "/include/fn/process.h"        /* process_msg() fn */

#define BLIND  present("Blindness", this_player())
#define DEAF   present("Deafness", this_player())

static string create_room;    /* filename of room this object was created */

string name;           /* name */
string alias_name;     /* alias name */
string alt_name;       /* == invis_name */

static string short_desc;          /* short via brief mode, or inventory */
static string by_living_env_short; /* short seen by living environment */
static string living_env_short;    /* short seen in a living environment */

string long_desc;               /* long seen in room, or via 'look at' */
static string living_env_long;  /* long seen by living environment */

static string extra_long;       /* extra long- between long & inventory */
static string alt_extra_long;   /* extra_long seen by environment of this */

static string info;           /* more info -> via 'identify' spell, oracles */

string extra_info;            /* called by 'examine' */
static string read_msg;       /* msg for 'read' cmd */
static string listen_msg;     /* msg for 'listen' cmd */
string smell_msg;             /* msg for 'smell' cmd */

static int weight;            /* weight of object */
static int value;             /* value of object */
static int light_value;       /* light value of object */

static status enchanted;      /* 1 == is it a magical item */
static status domain_safe;    /* don't destruct on domain move */
static status modified;       /* 1 == has it been modified since cloned */
static status quest_item;     /* 1 == is this a special quest item */

static status sell_destruct;  /* 1 == destruct when selling */


/**************************************************************/
/*  general queries */

string query_create_room()   { return create_room; }

varargs string query_name(status arg) { return name; }
string query_id()            { return name;     }
string query_alias_name()    { return alias_name;  }
string query_alias()         { return alias_name;  }
string query_alt_name()      { return alt_name;    }

string query_short()         { return short_desc;  }
string query_alt_short()     { return living_env_short; }
string query_inv_short()     { return by_living_env_short; }

string query_long()          { return long_desc;   }
string query_alt_long()      { return living_env_long;  }

string query_extra_long()    { return extra_long;  }
string query_alt_extra_long(){ return alt_extra_long; }

string query_info()          { return info;        }

string query_extra_info()    { return extra_info;  }
string query_examine()       { return extra_info;  }

string query_read()          { return read_msg;    }
string query_listen()        { return listen_msg;  }
string query_smell()         { return smell_msg;   }

int query_weight()           { return weight;      }
int query_value()            { return value;       }
int query_real_light()       { return set_light(0); }  /* light available */
int query_light_value()      { return light_value; }   /* light by this */

status query_enchanted()     { return enchanted;   }
status query_modified()      { return modified;    }
status query_quest_item()    { return quest_item;  }
status query_domain_safe()   { return domain_safe; }

status query_sell_destruct() { return sell_destruct; }

varargs mixed query(string fun, mixed arg1, mixed arg2) {
  return (mixed)call_other(this_object(),"query_"+fun, arg1, arg2);
}


/**************************************************************/
/*  general sets */

string set_name(string s)          { return name = s;      }
string set_id(string s)            { return name = s;      }
string set_alias_name(string s)    { return alias_name = s;  }
string set_alias(string s)         { return alias_name = s;  }
string set_alt_name(string s)      { return alt_name = s;  }

string set_short(string s)         { return short_desc = s;  }
string set_alt_short(string s)     { return living_env_short = s; }
string set_inv_short(string s)     { return by_living_env_short = s; }

string set_long(string s)          { return long_desc = s;   }
string set_alt_long(string s)      { return living_env_long = s; }

string set_extra_long(string s)    { return extra_long = s;  }
string set_alt_extra_long(string s){ return alt_extra_long = s; }

string set_info(string s)          { return info = s;        }
string set_read(string s)          { return read_msg = s;    }
string set_listen(string s)        { return listen_msg = s;  }
string set_smell(string s)         { return smell_msg = s;   }
string set_extra_info(string s)    { return extra_info = s;  }
string set_examine(string s)       { return extra_info = s;  }

int set_weight(int i)              { return weight = i;      }
int set_value(int i)               { return value = i;       }

status set_enchanted(status s)     { return enchanted = s;   }
status set_modified(status s)      { return modified = s;    }
status set_quest_item(status s)    { return quest_item = s;  }

status set_sell_destruct(status s) { return sell_destruct = s; }
status set_domain_safe(status s)   { return domain_safe = (s) ? 1 : 0; }

varargs mixed set(string fun, mixed arg1, mixed arg2) {
  return (mixed)call_other(this_object(),"set_"+fun, arg1, arg2);
}

/**************************************************************/
/* if this is used light you can keep an eye on light sources */

int adj_light(int i) {
  set_light(i);
  return light_value = light_value + i;
}


/*************************************************************/
/*  general fn for all object */


/* called by present() efun */

status id(string str) {
  return ((name       && str == lower_case(name)) ||
          (name       && str == name) ||
          (alias_name && str == alias_name) ||
          (alt_name   && str == alt_name));
}



/* called by the inventory of a 'look at' command, or brief mode */

string short(status wiz) {
  object env;

  if (wiz && !short_desc) {
    if (name) {
      return "Invis. Object-> " + name + "-> " + file_name(this_object());
    }
    else {
      return "Invis. Object-> " + file_name(this_object());
    }
  }
  else {
    env = environment();
    if (env && (living_env_short || by_living_env_short) && living(env)) {
      if (by_living_env_short && this_player() == env)
        return process_msg(by_living_env_short);
      else if (living_env_short)
        return process_msg(living_env_short);
      else if (short_desc)
        return process_msg(short_desc);
    }
    else {
      return process_msg(short_desc);
    }
  }
}



/* called by 'look at', or 'look' in room */

void long(status wiz) {
  object env;

  if (!long_desc) {
    if (!short_desc) {
      if (wiz) write("No Description: " + file_name(this_object()) + "\n");
    }
    else {
      write((string)this_object()->short(wiz) + "\n");
    }
  }
  else {
    env = environment();
    if (env && living_env_long && living(env))
      write(process_msg(living_env_long));
    else
      write(process_msg(long_desc));
  }
}



/* added to long of container|room */

void extra_long(status wiz) {
  if (alt_extra_long && environment(this_object()) == this_player()) {
    write(process_msg(alt_extra_long));
  }
  else if (extra_long) {
    write(process_msg(extra_long));
  }
}



/* called by 'identify', 'divination' spells, or oracles */

void info() {
  if (!info) {
    write("You find nothing special.\n");
  }
  else {
    write(process_msg(info));
  }
}



/* used by 'examine' command */

void extra_info(status wiz) {
  if (extra_info) {
    write(process_msg(extra_info));
  }
  else {
    this_object()->long(wiz);
  }
}


/* from 'read' cmd */

status read(string str) {
  if (BLIND) {
    write("You cannot read when you are blind!\n");
    return 1;
  }
  if (set_light(0) < 1) {
    write("It is too dark.\n");
  }
  else {
    if (str && !id(str)) return 0;
    if (!str && query_object_type() != "Room") return 0;
    write(process_msg(read_msg));
  }
  return 1;
}

/* from 'listen' cmd */

status listen(string str) {
  if (DEAF) {
    write("You cannot hear when you are deaf!\n");
    return 1;
  } 
  if (str && !id(str)) return 0;
  if (!str && query_object_type() != "Room") return 0;
  write(process_msg(listen_msg));
  return 1;
}


/* from 'smell' cmd */

status smell(string str) {
  if (str && !id(str)) return 0;
  if (!str && query_object_type() != "Room") return 0;
  write(process_msg(smell_msg));
  return 1;
}


/* init is called this is 1st moved, or something is moved into this */

void init() {
  object ob;

  if (!create_room) {
    while (1) {
      if (ob) {
        if (environment(ob)) {
          ob = environment(ob);
        }
        else {
          create_room = file_name(ob);
          break;
        }
      }
      else {
        if (environment(this_object())) {
          ob = environment(this_object());
        }
        else {
          create_room = file_name(this_object());
          break;
        }
      }
    }
  }
  if (read_msg) add_action("read", "read");
  if (listen_msg) add_action("listen", "listen");
  if (smell_msg) add_action("smell", "smell");
}



/*************************************************************/
/*  show inventory */

varargs status show_inventory(object ob) {
  string pad, list, *e_ob, *sh, sht;
  object *inv;
  int size, i, len, mon;
  status wiz;

  /* list of contents */

  if (!ob) ob = this_object();
  wiz = (this_player()->query_security_level()) ? 1 : 0;
  pad = "                                               ";
  list = ((string)ob->query_object_type() == "Room")
       ? "You find here: "
       : (!ob->query_name())
       ? "Inventory: "
       : (!living(ob))
       ? "The " + (string)ob->query_name() + " contains: "
       : (ob == this_player())
       ? "You are carrying: "
       : capitalize((string)ob->query_name()) + " is carrying: ";

  len = strlen(list);
  pad = extract(pad, 0, len-1);
  inv = all_inventory(ob);
  size = sizeof(inv);

  if (size > 20) size = 20;
  for (i = 0; i < size; i++) {
    if (inv[i] == this_player()) continue;
    inv[i]->extra_long();      /* between long and inventory */
    if ((sht = (string)inv[i]->short(wiz))) {
    /* this gives a reliable|nice inventory string */
#ifdef OLD_EXPLODE
      sh = explode(sht + " ", " ");
#else
      sh = explode(sht, " ");
#endif /* OLD_EXPLODE */
#ifndef __LDMUD__
      sh = filter_array(sh,
#else
      sh = filter(sh,
#endif
                            "filter_nul_str", this_object());
      if (sizeof(sh)) {
        sht = implode(sh, " ");
        list += (strlen(list) == len)
             ? sht + "\n"
             : pad + sht + "\n";
      }
      else if (wiz) {
        list += (strlen(list) == len)
             ? "Nul Short->" + file_name(inv[i]) + "\n"
             : pad + "Nul Short->" + file_name(inv[i]) + "\n";
      }
    }
    else if (wiz) {
      list += (strlen(list) == len)
           ? "Invisible-> " + file_name(inv[i]) + "\n"
           : pad + "Invisible-> " + file_name(inv[i]) + "\n";
    }
  }

  /* a rooms 'extra_objects' */
  /* A players should look in the description to find out what he can get
     or can't get out of it

  if ((e_ob = (string *)ob->query_extra_objects())) {
    for (i = 0; i < sizeof(e_ob); i += 2) {
      list += ((size) ? pad : "") + capitalize(e_ob[i]);
    }
  }
  ****/

  ob->exits(); /* between extra-long and inventory */
#ifdef MONEY
  if (this_player() == ob) {
    mon = (int)ob->query_money();
    write(((!mon)
           ? "Your money pouch is empty...\n"
           : "You have " +
             ((MONEY->convert(mon)) ? (string)MONEY->convert(mon) : (mon +"")) +
             " coins in your pouch\n"));
  }
#endif /* MONEY */
  write(((strlen(list) != len) ? list : ""));
  if (size != sizeof(inv)) write(pad + "*** Truncated ***\n");
  return 1;
}

status filter_nul_str(string str) { return (str != "") ? 1 : 0; }


/*************************************************************/
/*  test_dark */

status test_dark() {
  if (set_light(0) < 1) {
    write("It is dark.\n");
    return 1;
  }
  return 0;
}


#ifdef 312MASTER

/* used by find_all_living simul-efun when using 3.1.2 */

void set_living(string str) {
  if (file_name(previous_object()) == SIMUL_EFUN ||
      file_name(previous_object()) == SPARE_SIMUL_EFUN_FILE) {
    set_living_name(str);
  }
}

#endif

       
