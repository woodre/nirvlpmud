/*
 * wizard.c - player object for wizards
 *
 */

inherit "obj/player";

#include "/include/fn_specs/wizard.spc"
#include "/include/cfg/levels.h"

static string current_path;            /* Current directory */

void reset(status arg) {
  ::reset(arg);
  if (arg) return;
  if (this_object() != this_player()) return;
  if (!current_path) current_path = "players/" + query_name(1);

  if (!security_level) return;
  add_action("renew",                       "new"     );
  add_action("renew",                       "refresh" );

  if (security_level > SEC1) {
    add_action("Cat_file",            "Cat"    );
    add_action("Put",                 "Put"    );
    add_action("promote",             "promote");

    if (security_level > SEC7) {
      add_action("demote",            "demote" );
    }
  }
}


/***************************************************************************/
/* new */

static status renew(string who) {
  object ob;

  if (!who) ob = this_object();
  else      ob = find_player(who);

  if (!ob) {
    write(capitalize(who) + " is not here.\n");
    return 1;
  }
  ob->get_new_player_object();
  return 1;
}


/***************************************************************************/
/*     Wizard Actions                                                      */
/***************************************************************************/


/***************************************************************************/
/* promote */

status promote(string str) {
  object ob;
  int new_level;
  string level_name;

  if (!str ||
      (sscanf(str, "%s %d", str, new_level) != 2 &&
       sscanf(str, "%s %s", str, level_name) != 2)) {
    write("Usage: promote <who> <level|level name>\n");
    write("Notes: promotes a player to security level, <level> or " +
          "<level name>\n" +
          "       Level names: asp, app, creator, sage, lord, sen, elder, " +
          "arch, or admin.\n" +
          "       See also 'domain' command.\n");
    return 1;
  }
  if (!(ob = present(str, environment()))) {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  if (level_name) {
    switch(level_name) {
      case "admin": case "administration": new_level = SEC9; break;
      case "arch":                         new_level = SEC8; break;
      case "elder":                        new_level = SEC7; break;
      case "sen": case "senior":           new_level = SEC6; break;
      case "lord":                         new_level = SEC5; break;
      case "sage":                         new_level = SEC4; break;
      case "creator":                      new_level = SEC3; break;
      case "app": case "apprentice":       new_level = SEC2; break;
      case "asp": case "aspirant":         new_level = SEC1; break;
      default:
        promote(0);
        return 1;
        break;
    }
  }
  ob->set_security_level(new_level);
  return 1;
}

/***************************************************************************/
/* demote */

static status demote(string str) {
  object ob;

  if (!str) {
    write("Usage: demote <who>\n");
  }
  if (!(ob = present(str, environment()))) {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  ob->reduce_security_level(0);
  return 1;
}

/***************************************************************************/
/* put: move objects about */

static status Put(string str) {
  int i;
  object *ob1, *ob2;
  string what, who, short_desc;

  if (!str) {
    write("Usage: put <object> in <where> (may cause ambiguities)\n" +
          "       put <object::where>\n\n" +
          "Notes: Reposition objects. The first variation is for the sake\n" +
          "       of compatibility with the original 'put', but it can be\n" +
          "       ambiguous. The second format eliminates that.\n");
    return 1;
  }
  if (!sscanf(str, "%s::%s", what, who)) {
    if (!sscanf(str, "%s in %s", what, who)) {
      Put(0);
      return 1;
    }
  }
  if (!sizeof((ob1 = PROCESS_ARG(what)))) return 1;
  if (!sizeof((ob2 = PROCESS_ARG(who)))) return 1;
  if (sizeof(ob2) > 1) {
    write("You cannot put into an object list, using first element.\n");
  }
  for (i = 0; i < sizeof(ob1); i++) {
    if (environment(ob2[0]) == ob1[i]) {
      if (environment(ob1[i])) {
        move_object(ob2[0], environment(ob1[1]));
      }
      else {
        write("You cannot move an object into itself!\n");
        return 1;
      }
    }
    if (ob1[i] != ob2[0]) {
      move_object(ob1[i], ob2[0]);
      if (!ob1[i]) { /* This has happened, how unusual */
        write("Object has destructed itself, on moving.\n");
        continue;
      }
      short_desc = (ob1[i]->short()) ? (string)ob1[i]->short()
                                     : file_name(ob1[i]);
      write(capitalize(short_desc) + " has been moved into " +
            ob2[0]->short() + ".\n");
    }
  }
  return 1;
}

/***************************************************************************/
/* cat whole file */

#define CAT_LENGTH 45

static status Cat_file(string str) {
  int line;

  if (!str) {
    write("Usage: Cat <file>\n\n" +
      "Notes: Useful for copying a file to disk via screen capture.\n" +
      "       This will probably crash on files with more than 2000 lines.\n" +
      "       For those muds that don't allow ftp downloading ;)\n");
    return 1;
  }
  str = make_path(str);
  for (line = 1; cat(str, line, CAT_LENGTH); line += CAT_LENGTH);
  return 1;
}


/***************************************************************************/
/*     Wizard Tools - functions used by various actions                    */
/***************************************************************************/

/***************************************************************************/
/* make_path */

string make_path(string file) {
  string *path_split, tmp;
  string tmp1, tmp2;
  int i, len;

  if (!file || file == "") return "/" + current_path;
  if (file == "~") return "/players/" + name;
  if (sscanf(file, "~/%s", file)) {
    file = "/players/" + file;
  }
  if (sscanf(file, "~%s", file)) {
    file = "/players/" + name + "/" + file;
  }
  if (sscanf(file, "%s#%s", tmp1, tmp2)) {
    file = "/d/" + tmp1 + "/w/" + name + "/" + tmp2;
  }
  if (sscanf(file, "%s,%s", tmp1, tmp2)) {
    file = "/d/" + tmp1 + "/w/" + tmp2;    /* experimental */
  }
  if (file[0] != '/') {
    if (current_path == "") {
      file = "/" + file;
    }
    else {
      file = "/" + current_path + "/" + file;
    }
  }
  while (sscanf(file, "%s//%s", tmp1, tmp2)) file = tmp1 + "/" + tmp2;
  return ::make_path(file);
}


/***************************************************************************/
/* convert a plural string to a singular */

string plural_to_single(string plural) {
  string word, end;
  int len;

  if (!plural) return "";
  len = strlen(plural);

  /* sscanf() sucks...it wouldn't work *sob*
   * it has problems with things like "%ss"
   */
  if (len > 3) {
    end = extract(plural, (len - 3), (len - 1));
    word = extract(plural, 0, (len - 4));
    if (end == "ies") return word + "y";  /* babies -> baby */
    if (end == "ses") {
      if (word[strlen(word)-1] == 's')
        return word + "s";                /* glasses -> glass */
      else
        return word + "se";               /* fuses -> fuse */
    }
  }
  if (len > 2) {
    end = extract(plural, (len - 2), (len - 1));
    word = extract(plural, 0, (len - 1));
    if (end == "ii") return word + "us";
    if (plural[len-1] == 's')
      return extract(plural, 0, (len - 2));
  }
  return plural;
}


/***************************************************************************/
/* find_object() - uses various object finding efuns */

static varargs object *FIND_OBJECT(string str, object who) {
  string tmp1, tmp2;
  int i, j;
  object *ob;
  string current_path;

  if (!str) {
    write("No Argument to FIND_OBJECT!\n");
    return ({});
  }
  ob = ({});
  if (str == "who" || str == "users") {
    ob = allocate(sizeof(users()));
    ob = users();
    if (who) {     /* eg. users in room */
      ob = filter_array(ob, "present_filter", this_object(), who);
    }
  }
  if (!sizeof(ob)) ob = allocate(1);
  if (!who) who = this_player();

  if (str == "me") ob[0] = this_player();
  else if (str == "env") ob[0] = environment(who);
  else if (str == "room") ob[0] = environment(who);
  else if (str == "all") {
    ob = allocate(sizeof(all_inventory(who)));
    ob = all_inventory(who);
    if (!sizeof(ob)) ob = allocate(1);
  }
  else if (sscanf(str, "all %s", tmp1)) {      /* eg. all swords */
    ob = filter_array(all_inventory(who), "plural_filter", this_object(), tmp1);
    if (!sizeof(ob)) ob = allocate(1);
  }
  else if (sscanf(str, "%d %s", j, tmp1)) {    /* eg. 3 sword */
    ob = filter_array(all_inventory(who), "plural_filter", this_object(), tmp1);
    if (j <= sizeof(ob)) {
      ob = ob[0..(j-1)];
    }
    if (!sizeof(ob)) ob = allocate(1);
  }
  else if (sscanf(str, "who%d", i) == 1) {
    if (i < 1 || i > sizeof(users()) - 2) {
      write("Who " + i + " is out of who number bounds.\n");
      return ({});
    }
    ob[0] = users()[i-1];
  }
  if (!ob[0]) ob[0] = present(str, who);
  if (!ob[0] && environment(who)) ob[0] = present(str, environment(who));
  if (!ob[0]) ob[0] = find_object(str);
  if (!ob[0]) ob[0] = find_living(str);
  if (!ob[0]) {
    ob = find_all_living(plural_to_single(str));
    if (!sizeof(ob)) ob = allocate(1);
  }
  if (!ob[0]) ob[0] = find_living("ghost of " + str);
  if (!ob[0]) {
    if (!sscanf(str, "%s %s", tmp1, tmp2)) {
      str = make_path(str);
      sscanf(str, "/%s", str);
      sscanf(str, "%s.c", str);
      if (FILE_SIZE("/" + str + ".c") > 0) {
        if (catch(call_other(str, "???"))) {
          write("Error in loading: " + str + "\n");
          return ({});
        }
        ob[0] = find_object(str);
      }
    }
  }
  if(!ob[0]) return ({});
  return ob;
}


/***************************************************************************/
/* processes an action string to find an object list */

static object *PROCESS_ARG(string arg) {
  string tmp1, tmp2;
  mixed *ob_list;
  string *contents, list, content_list;
  mixed *ob;
  int i;

  if (!arg) return ({});
#ifdef OLD_EXPLODE
  ob_list = explode(arg + " in ", " in ");
  list = implode(ob_list, " of ") + " of ";
#else
  ob_list = explode(arg, " in ");
  list = implode(ob_list, " of ");
#endif
  ob_list = explode(list, " of ");
  if (!ob_list) ob_list = ({ arg, });
  for (i = 0; i < sizeof(ob_list); i++) {
    content_list = ob_list[i];
    while(sscanf(content_list, "%s, %s", tmp1, tmp2)) {
      content_list = tmp1 + "," + tmp2;
    }
    if (content_list[strlen(content_list) - 1] != ',') content_list += ",";
    contents = explode(content_list, ",");
    ob_list[i] = contents;
  }
  ob = PROCESS_ARG_OB(ob_list, ({ 0, }));
  if (!sizeof(ob)) {
    write("Error: Cannot find '" + arg + "'\n");
  }
  return ob;
}

object *PROCESS_ARG_OB(mixed *ob_list, object *ob) {
  int i, size, j;
  object *new_ob, *obj;
  string *list;

  new_ob = ({});
  list = ob_list[sizeof(ob_list)-1];
  for (i = (size = sizeof(ob)) - 1; i >= 0; i--) {
    for (j = 0; j < sizeof(list); j++) {
      obj = FIND_OBJECT(list[j], ob[i]);
      if (sizeof(obj)) {
        new_ob = new_ob + obj;
      }
    }
  }
  if (!sizeof(new_ob)) return ({});
  if (sizeof(ob_list) > 2) {
    return PROCESS_ARG_OB(ob_list[0..(sizeof(ob_list)-2)], new_ob);
  }
  else if (sizeof(ob_list) == 2) {
    return PROCESS_ARG_OB(({ ob_list[0], }), new_ob);
  }
  return new_ob;
}

