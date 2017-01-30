/*
 * Robe of Sorcery V1.6
 */

/*
 * TODO:
 * - make Deepwatch working again
 * - make Review working
 * - make the robe using P_DISPLAY_WIDTH
 * - make a WORKFILE for each user, not a unique workfile
 * - improve 'Update' when an error occurs (e.g. moving items back)
 * - improve parsing of target objects
 * - improve T [I don't want to be inside monster's blueprints again]
 * - What shall happen with 'Changed'?
 * - Dump-command for dumping output into a file
 * - Tail should accept a 'lines' argument
 * - not yet new formatted: Changed
 */

#pragma strong_types

#include <kernel.h>
#include <wizlevels.h>
#include <lpctypes.h>
#include <functionlist.h>
#include <prop/player.h>
#include <is_wizard.h>
#include <libs.h>
#include <server.h>
#include <etc.h>
#include <inherit_list.h>

inherit ACCESS;
inherit "basic/quote";
inherit "basic/create";

#define SHELL

#define LOOKUP_BLOCK_SIZE 2000
#define VOID            "room/void"
#define SYSLOGDIR       "/syslog/"
#define LOGFILE         "/syslog/NEWLIB"
#define INCLUDEDIR      "/sys/"
#define PROBE           "obj/tools/toolbox/probe"
#define WORKFILE        "/global/work/workfile.c"
#define PROGRAM_NAME(x) "/"+load_name(x)+".c"
#define SHORT(ob)       ob->short()
#define PAGE(x)         {this_player()->view_text(x);this_player()->start_view();}

#ifndef NATIVE
#define MOVE(x,y)       move_object(x,y)
#define DESTRUCT(ob)    destruct(ob)
#else
#define MOVE(x,y)       x->move(y)
#define DESTRUCT(ob)    ob->remove()
#endif

#define L               lower_case
#define C               capitalize
#define OUT(x)          efun::write(x+"\n")
#define NOTIFY(x)       return OUT(x)
#define NOTIFY1(x)      return OUT(x),1
#define FAIL(x)         return notify_fail(x+"\n"),0
#define FOREACH(x,y)    for(y=0;y<sizeof(x);y++)
#define MEMBER(x,y)     (member(x,y)>=0)
#define DA(x)           dump_argument(x,-1)
#define BREAK           raise_error("Breakpoint!\n")

#define T_START_ARRAY   "({"
#define T_END_ARRAY     "})"
#define T_START_MAPPING "(["
#define T_END_MAPPING   "])"
#define T_START_SUBCALL "("
#define T_END_SUBCALL   ")"
#define T_START_INDEX   "["
#define T_END_INDEX     "]"
#define T_EFUN          "efun::"

#define E_STRING        "Runaway string!"
#define E_PARENTHESIS(x) "Unexpected end of the command line! "+x+"!"
#define E_ARGUMENT      "Illegal argument!"
#define E_UP_OPERATOR   "There is no marked object for the 'up' operator!"
#define E_NO_CLOSURE(x) "Can't translate this closure ("+x+")!"
#define E_NO_INDEX      "Too many indices!"
#define E_INDEX(x,y)    "Can't index "+DA(x)+" with ["+DA(y)+"]!"
#define E_ROBE_INDEX(x) "Illegal Robe-index ("+x+")!"
#define E_MULTIARG(x)   "Illegal multi-argument ("+x+")!"
#define E_RA_MULTIARG   "Runaway multi-argument!"
#define E_MAP_RUNAWAY   "Runaway mapping!"
#define E_MAP_VALUES(x) "Runaway value to key ("+DA(x)+")!"
#define E_MAP_TOOMANY   "Incompatible number of values in the mapping!"

#define O_VERBOSE       1
#define O_BRIEF         2
#define O_HEADLINE      4
#define O_GUESS         8

#define SUPPRESS       ((flags & (O_VERBOSE|O_BRIEF)) == 0)
#define HYBRID         ((flags & (O_VERBOSE|O_BRIEF)) == 3)
#define VERBOSE         (flags & O_VERBOSE)
#define BRIEF           (flags & O_BRIEF)
#define HEADLINE        (flags & O_HEADLINE)
#define GUESS           (flags & O_GUESS)

#define H_BANNER        1
#define H_CENTER        2
#define HLINE(x)        write(headline(x,0));
#define CENTER(x)       write(headline(x,H_CENTER));
#define BANNER(x)       write(headline(x,H_CENTER|H_BANNER));

static  string    cmd_line;
static  string    log;
static  int       lc;
static  mixed    *cmd_list;
static  int      *tc;
static  mapping  *cmd_args;
static  mixed    *argv;
        mapping   macros;
static  int       mappingmode;
static  object   *indexlist;
static  object    marked_slot;
        mixed     result_slot;
static  int       flags;
        string   *dir_array;
        string   *preloads;
        status    use_message_macros;
static  string   *command_array;
static  mapping   watches;
static  mapping   shadows;
        string   *expect_list;
        mapping   slot;
        int       lightlevel;
static  object    mtarget;
        int       tracelevel;
static  mixed     tprefix;
        string    lang;
static  mixed    *info_array;
static  mixed    *help_array;
        int       pager;
        int       editor;
        int       prediction;
static  string    lookoutput;
static  mapping   loadsyms;
static  mapping   loadincs;
static  mapping   robe_symbols;
static  mapping   inverted_symbols;
static  string   *files;

/*-----------------------------------------------------------------------*/

static nomask mixed   parse (string item);
static        string  next_token (int backskip);
static        string *add_command_line (string str, mapping keys);
static        mixed   call_function (mixed *args);
static        int     remove_watches (mixed arg, int quiet);
static        void    remove_shadow (mixed arg, int quiet);

/*-----------------------------------------------------------------------*/

static int check_safety() {
  return check_privilege(get_privilege(this_object()));
}

void notify_destruct() {
  int i;
  mixed *arr;

  arr = m_indices(shadows || ([ ]));
  FOREACH (arr,i)
    remove_shadow(arr[i],1);
  arr = m_indices(watches);
  FOREACH (arr,i)
    remove_watches(arr[i],1);
}

void notify_login(string name) {
  if (MEMBER(expect_list,find_player(name)->query_real_name()))
    tell_object(environment(this_object()),
        "ROBE: "+C(name)+" entered the game!\n");
}

static int player_exists(string str) {
  return "etc/fingerd"->load_player(str);
}

static string player_savefile(string str) {
  string out;

  out = "/save/players/"+str[0..0]+"/"+str+".o";
  if (file_size(out) > 0)
    return out;
  return 0;
}

static int wizard_check(object ob) {
  return query_once_interactive(ob) &&
         (is_wizard(ob, IW_APPRENTICE) || ob->query_property(P_TESTPLAYER));
}
  
static int teleport_player(object where) {
  this_player()->move_living("X", object_name(where));
  return 1;
}

static void execute_shell(string com, string str) {
  "bin/shell"->find_instance(this_player())->shell(str, com);
}

static int write_check(string file) {
  return MASTER->valid_write(file);
}

static string expand_filename(string str) {
  return MASTER->normalize_path(str, this_player());
}

static private int operate_file(closure what, mixed args) {
  return unguarded(1, what, args);
}

static string safe_read_file(string filename) {
  int length, count;
  string out;

  length = file_size(filename);
  if (length < 1)
    return 0;

  out = "";
  count = 0;
  while (length - count > 40000) {
    out += read_bytes(filename, count, 40000);
    count += 40000;
  }
  out += read_bytes(filename, count, length-count);
  return out;
}
  
/*-----------------------------------------------------------------------*/

static void reset_marker() {
  tc = ({ });
  cmd_args = ({ });
  cmd_list = ({ });
}

static void error(string str) {
  reset_marker();
  raise_error("Parse error: "+str+"\n");
}

static string dump_argument(mixed arg, int indent) {
  int i,j,tab;
  string out;
  mixed *values,*keys,tmp;

  if (prediction) {
    if (!arg)
      return "0";
    if (arg == 1)
      return "1";
    if (member(inverted_symbols, arg))
      return inverted_symbols[arg];
    if (use_message_macros &&
        intp(arg)          &&
        (tmp = LIB_MESSAGE->int2token(to_int(arg))))
      return tmp;
  }

  switch (typeof(arg)) {

  case T_STRING :
    if (indent == -1)
      return "\""+quote_string(arg)+"\"";
    return "\""+unquote_string(arg)+"\"";

  case T_OBJECT :
    return "<"+object_name(arg)+">";

  case T_NUMBER :
  case T_FLOAT  :
    return to_string(arg);

  case T_CLOSURE:
    return sprintf("%O",arg);

  case T_SYMBOL :
    out = "";
    for (i=get_type_info(arg)[1] ; i>0 ; i--)
      out += "'";
    return out+unquote_string(to_string(arg));

  case T_QUOTED_ARRAY:
    out = "";
    for (i=get_type_info(arg)[1] ; i>0 ; i--)
      out += "'";
    return out+dump_argument(to_array(arg),-1);

  case T_POINTER:
    if (indent>=0) {
      if (!sizeof(arg))
        return "({ })";
      if (sizeof(arg)==1)
        return "({ "+dump_argument(arg[0],indent) +" })";
      if (!indent)
        out = "*ARRAY*    (" + sizeof(arg) + " entries)\n({\n";
      else
        out = "({\n";
      FOREACH(arg,i)
        out += sprintf("%"+(indent+3)+"s%s,\n", " ", dump_argument(arg[i],
                       indent+3));
        out += sprintf("%"+indent+"s})", " ");
        return out;
      }
      out = "({";
      FOREACH(arg,i)
        out += dump_argument(arg[i],-1)+",";
      if (sizeof(arg)>0)
        out = out[0..strlen(out)-2];
        out += "})";
      return out;

  case T_MAPPING:
    if (indent>=0) {
      keys = m_indices(arg);
      FOREACH (keys,i) {
        tmp = explode(dump_argument(keys[i],0), "\n");
        j = indent + 4 + strlen(tmp[<1]);
        if (j>tab)
          tab = j;
      }

      if (!indent)
        out = "*MAPPING*    ("+sizeof(keys) +" keys)\n([\n";
      else
        out = "([\n";

      FOREACH (keys,i) {
        values = ({ });
        j = 0;
        while (j<widthof(arg))
          values += ({arg[keys[i],j++]});
        if (!sizeof(values)) {
          tmp = dump_argument(keys[i],-1);
          out += sprintf("%"+(tab-strlen(tmp)) +"s%s;\n"," ",tmp);
        } else {
          tmp = dump_argument(keys[i],-1) + " : ";
          out += sprintf("%"+(tab-strlen(tmp)) +"s%s;\n"," ",
                 tmp + dump_argument(values[0],tab));
        }
        for (j=1 ; j<sizeof(values) ; j++)
          out += sprintf("%"+tab+"s%s;\n"," ",
        dump_argument(values[j],tab));
      }
      out += sprintf("%"+indent+"s])"," ");
      return out;
    } else {
      keys = m_indices(arg);
      out = "([";
      FOREACH (keys,i) {
        values = ({ });
        j = 0;
        while (j<widthof(arg))
          values += ({arg[keys[i],j++]});
        if (!sizeof(values))
          out += " "+dump_argument(keys[i],-1);
        else {
          out += " "+dump_argument(keys[i],-1)+":";
          for (j=0 ; j<sizeof(values) ; j++)
            out += dump_argument(values[j],-1)+";";
          out = out[0..<2];
        }
      }
      out += " ])";
    }
    return out;

#if defined(USE_STRUCTS) || defined(__LPC_STRUCTS__)
  case T_STRUCT:   // TODO: new type in ldmud-3.3
    return "FIXME: structs are not supported, yet.";
#endif

  case T_INVALID:
    return "<0>";

  case T_LVALUE:
    return "<lvalue>";
  }
  NO_WARN_MISSING_RETURN;
}

static string dump_tree(mixed arg, string ins, int dump) {
  string out;
  mixed tmp;
  int i;

  if (!ins)
    ins = "";
  out = ins+"+---";

  switch (typeof(arg)) {
  case T_STRING:
    if (dump)
      return out + "\""+quote_string(arg)+"\"";
    return out + arg;

  case T_OBJECT:
    if (dump && indexlist &&
        (i=member(indexlist, arg)) != -1)
      return out+"<"+object_name(arg)+"> (#"+(i+1)+")";
    return out + "<"+object_name(arg)+">";

  case T_NUMBER:
  case T_FLOAT:
    return out + to_string(arg);

  case T_CLOSURE:
    return out + sprintf("%O",arg);

  case T_SYMBOL:
    for (i=get_type_info(arg)[1] ; i>0 ; i--)
      out += "'";
    return out + unquote_string(to_string(arg));

  case T_QUOTED_ARRAY:
    for (i=get_type_info(arg)[1] ; i>0 ; i--)
      out += "'";
    return out + dump_tree(to_array(arg), ins, dump);

  case T_POINTER:
    ins += "|   ";
    out += "+---+\n" + ins;
    FOREACH (arg, i)
      out += dump_tree(arg[i],ins,dump)+"\n";
    out += ins[0..<4];
    return out;

  case T_MAPPING:
    out += "(Mappings are not supported, yet.)\n";
    return out;

#if defined(USE_STRUCTS) || defined(__LPC_STRUCTS__)
  case T_STRUCT:   // TODO: new type in ldmud-3.3
    out += "(Structs are not supported, yet.)\n";
    return out;
#endif

  case T_INVALID:
    out += "(invalid type)\n";
    return out;

  case T_LVALUE:
    out += "(lvalue type)\n";
    return out;
  }
  NO_WARN_MISSING_RETURN;
}  

static string get_file(mixed arg) {
  int i;
  string tmp;

  if (!arg)
    return 0;

  switch (typeof(arg)) {

  case T_OBJECT:
    return PROGRAM_NAME(arg);

  case T_FLOAT:
  case T_NUMBER:
    arg = to_string(arg);

  case T_STRING:
    tmp = expand_filename(arg);
    if (tmp) {
      if (file_size(tmp)>0)
        return tmp;
      if (file_size(tmp+".c")>0)
        return tmp+".c";
    }
    FOREACH(dir_array,i) {
      if (file_size(dir_array[i]+"/"+arg)>0)
        return dir_array[i]+"/"+arg;
      if (file_size(dir_array[i]+"/"+arg+".c")>0)
        return dir_array[i]+"/"+arg+".c";
    }
  default:
    return 0;
  }
  return 0;
}

static int match_arguments(string str, mixed *args) {
  string item;
  mixed out,*arg,tmp;
  int i,j;

  if (!str)
    return 0;

  reset_marker();
  arg = allocate(sizeof(args));
  FOREACH (arg, i)
    arg[i] = ({ });
  i = 0;
  add_command_line(str,([]));

  while (item = next_token(0)) {
    out = parse (item);
    FOREACH (args,j) {
      if (!args[j])
        continue;
      if (!arg[j])  // arg[j] = 0: the last argument match failed
        continue;
      if (sizeof(args[j]) <= i) {
        arg[j] = 0;
        continue;
      }
      switch (args[j][i]) {
      case "string":
        if (out && stringp(out))
          arg[j] += ({ out });
        else
          arg[j] += ({ item });
        break;

      case "command":
        if (out && stringp(out) && (out[<1] == '!'))
          arg[j] += ({ out[0..<2] });
        else
          arg[j] = 0;
        break;

      case "stringlist":
        tmp = ({ });
        do {
          if (out && stringp(out))
            tmp += ({ out });
          else {
            arg[j] = 0;
            break;
          }
        } while ((item = next_token(0)) && (out = parse(item)));
        if (arg[j])
          arg[j] += ({ tmp });
        break;

      case "object":
        if (out && objectp(out))
          arg[j] += ({ out });
        else
          arg[j] = 0;
        break;

      case "integer":
        if (intp(out))
          arg[j] += ({ out });
        else
          arg[j] = 0;
        break;

      case "filename":
        if (tmp = get_file(out))
          arg[j] += ({ tmp });
        else
          arg[j] = 0;
        break;

      case "playerfile":
        if (!check_privilege(1))
          break;
        if (out && objectp(out) && query_once_interactive(out)) {
          if (tmp = player_savefile(out->query_real_name()))
            arg[j] += ({ tmp });
          else
            arg[j] = 0;
          break;
        }
        if (out && stringp(out)) {
          if (tmp = player_savefile(out))
            arg[j] += ({ tmp });
          else
            arg[j] = 0;
        }
        break;

      case "playername":
        if (out && objectp(out) && query_once_interactive(out)) {
          arg[j] += ({ out->query_real_name() });
          break;
        }
        if (out && stringp(out) && player_exists(L(out)))
          arg[j] += ({ L(out) });
        else
          arg[j] = 0;
        break;

      case "directory":
        if (out && objectp(out)) {
          tmp = PROGRAM_NAME(out);
          tmp = expand_filename (tmp);
          tmp = explode(tmp,"/")[0..<2];
          tmp = implode(tmp,"/");
          arg[j] += ({ tmp });
          break;
        }
        if (out && stringp(out)) {
          tmp = expand_filename(out);
          if (file_size(tmp) == -2)
            arg[j] += ({ tmp });
          break;
        }
        if (intp(out) && (out>0) && (out <= sizeof(dir_array)))
          arg[j] += ({dir_array[out-1]});
        else
          arg[j] = 0;
        break;

      default:
        if (out == args[j][i])
          arg[j] += ({ out });
        else
          arg[j] = 0;
        break;
      }
    }
    i++;
  }
  FOREACH (arg,i)
    if (arg[i] && (sizeof(arg[i]) == sizeof (args[i]))) {
      argv = arg[i];
      return i+1;
    }
  return -1;
}

static string get_token() {
  int cmd_length, pos, sflag;

  if (!cmd_line)
    return 0;
  cmd_length = strlen(cmd_line);
  while (cmd_length > ++lc)
    if (cmd_line[lc] != ' ')
      break;
  if (cmd_length <= lc)
    return 0;

  pos = lc;
  while (cmd_length > lc)
    switch (cmd_line[lc]) {
    case '\"':
      if (cmd_line[lc-1] != '\\')
        sflag = (!sflag);
      lc++;
      break;

    case '(':
      if (sflag) {
        lc++;
        break;
      }
      if (lc != pos)
        return cmd_line[pos..--lc];
      if (cmd_line[++lc] == '{')
        return T_START_ARRAY;
      if (cmd_line[lc] == '[')
        return T_START_MAPPING;
      lc--;
      return T_START_SUBCALL;

    case '\'':
      if (sflag || cmd_line[lc-1] == '#') {
        lc++;
        break;
      }
      if (pos == lc)
        return cmd_line[lc..lc];
      return cmd_line[pos..--lc];

    case ':':
    case ';':
    case '[':
      if (sflag) {
        lc++;
        break;
      }
      if (pos != lc) {
        if (cmd_line[lc] != ':')
          return cmd_line[pos..--lc];
        // extra handling for efun::
        if ((cmd_line[lc-4..lc+1] == T_EFUN) ||
            (cmd_line[lc-5..lc  ] == T_EFUN)) {
          lc++;
          break;
        }
        return cmd_line[pos..--lc];
      }
      return cmd_line[lc..lc];

    case ']':
      if (sflag) {
        lc++;
        break;
      }
      if (cmd_line[lc+1] == ')') {
        if (pos != lc)
          return cmd_line[pos..--lc];
        lc++;
        return T_END_MAPPING;
      }
      if (pos == lc)
        return T_END_INDEX;
      return cmd_line[pos..--lc];
      break;
      
    case ')':
      if (sflag) {
        lc++;
        break;
      }
      if (cmd_line[lc-1] == '}') {
        if (pos == lc-1)
          return T_END_ARRAY;
        else {
          lc -= 2;
          return cmd_line[pos..lc];
        }
      }
      if (pos == lc)
        return T_END_SUBCALL;
      lc--;
      return cmd_line[pos..lc];

    case ',' :
    case ' ' :
    case '\t':
      if (sflag) {
        lc++;
        break;
      }
      if (pos != lc)
        return cmd_line[pos..lc-1];
      return get_token();

    default:
      lc++;
      break;
    }
  if (sflag)
    error(E_STRING);
  return 0;
}

static mixed *add_command_line(string cmd, mapping keys) {
  string token;

  cmd_line = make_shared_string(" " + cmd + " ");
  lc = 0;
  tc = ({ 0 }) + tc;
  cmd_list = ({({ })}) + cmd_list;
  cmd_args = ({ keys }) + cmd_args;
  while (token = get_token())
    cmd_list[0] += ({token});
  return cmd_list;
}

static string next_token(int backskip) {
  if (!sizeof(tc))
    return 0;

  if (backskip) {
    if (tc[0] > 0)
      tc[0]--;
  } else
    tc[0]++;

  if (sizeof(cmd_list[0]) >= tc[0])
    return cmd_list[0][tc[0]-1];

  tc = tc[1..];
  cmd_list = cmd_list[1..];
  cmd_args = cmd_args[1..];
  return next_token(backskip);
}

static mixed look_ahead(mixed term) {
  string item;
  object lastmarked, *oldlist;
  mixed out;
  int i, j;

  switch ((item = next_token(0))) {

  case T_START_INDEX:
    if (!(item = next_token(0)))
      error(E_PARENTHESIS("(Runaway index)"));
    if (strstr(item,"..",0) < 0)
      out = parse(item);
    else
      out = item;
    if (next_token(0) != T_END_INDEX)
      error(E_NO_INDEX);
    if (!term ||
        (!pointerp(term) && !mappingp(term) && !stringp(term)))
      error (E_INDEX(term, out));
    if (mappingp(term)) {
      term = term[out];
      return look_ahead(term);
    }
    if (intp(out) && out >= 0) {
      if (stringp(term) && strlen(term) > out) {
        term = term[out];
        return look_ahead(term);
      }
      if (pointerp(term) && sizeof(term) > out) {
        term = term[out];
        return look_ahead(term);
      }
      error(E_INDEX(term, out));
    }
    if (!stringp(out))
      error(E_INDEX(term, out));

    if (sscanf(out,"%d..%d",i,j) == 2) {
      term = term[i..j];
      return look_ahead(term);
    }
    if (sscanf(out,"%d..<%d",i,j) == 2) {
      term = term[i..<j];
      return look_ahead(term);
    }
    if (sscanf(out,"..<%d",i) == 1) {
      term = term[0..<i];
      return look_ahead(term);
    }
    if (sscanf(out,"<%d",i) == 1) {
      term = term[<i];
      return look_ahead(term);
    }
    if (strstr(out,"..") >= 0 && sscanf(out,"%d..",i) == 1) {
      term = term[i..];
      return look_ahead(term);
    }
    if (strstr(out,"..") >= 0 && sscanf(out,"..%d",i) == 1) {
      term = term[0..i];
      return look_ahead(term);
    }
    error(E_INDEX(term, out));
    break;

  case ":":
    if (mappingmode) {
      next_token(1);
      return term;
    }
    if (!(term && objectp(term)))
      error(E_MULTIARG(term));
    item = next_token(0);
    if (!item)
      error(E_RA_MULTIARG);
    lastmarked  = marked_slot;
    oldlist     = indexlist;
    marked_slot = term;
    indexlist   = all_inventory(term);
    out = parse(item);
    marked_slot = lastmarked;
    indexlist = oldlist;
    if (!objectp(out))
      error (E_MULTIARG(item));
    return look_ahead(out);

  default:
    next_token(1);
    return term;
  }
  return 0;
}

static nomask mapping parse_mapping() {
  string item;
  mixed key,*vals;
  mapping out;
  int i;

  out = ([ ]);
  while ((item = next_token(0))) {
    if (item == T_END_MAPPING)
      return out;
    key = parse(item);
    vals = ({ });
    if (next_token(0) == ":") {
      while ((item = next_token(0))) {
        if (!(item && item != T_END_MAPPING))
          error (E_MAP_VALUES(key));
        vals += ({ parse(item) });
        if (next_token(0) != ";") {
          next_token(1);
          break;
        }
      }
    } else
      next_token(1);

    if (!sizeof(m_indices(out)))
      out = m_allocate(1, sizeof(vals));
    if (!sizeof(vals))
      out += ([ key ]);
    else {
      if (sizeof(vals) > get_type_info(out)[1])
        error(E_MAP_TOOMANY);
      FOREACH(vals,i)
        out[key,i] = vals[i];
    }
  }
  error(E_MAP_RUNAWAY);
  NO_WARN_MISSING_RETURN;
}

static nomask mixed parse(string term) {
  string item, *tmp;
  object lastmarked, *lastlist;
  mixed out, old, *args;
  mapping keys;
  int i, j, count;

  if (!term)
    item = next_token(0);
  else
    item = term;
  if (!item)
    error(E_PARENTHESIS(""));

  if (item == "@" && member(cmd_args[0], item)) {
    add_command_line(cmd_args[0][item], cmd_args[0]);
    return parse(0);
  }

  if (member(cmd_args[0], item))
    return look_ahead(cmd_args[0][item]);

  if (macros && member(macros, item)) {
    args = ({ });
    keys = ([ ]);
    tmp = macros[item,0];
    if (tmp && pointerp(tmp))
      FOREACH(tmp,i) {
        if (tmp[i]=="@") {
          while ((out = parse(0)) != T_END_SUBCALL && out != T_END_ARRAY)
            args += ({ out });
          next_token(1);
        } else {
          if (sizeof(args) > 0) {
            keys[tmp[i]] = args[<1];
            args = args[0..<2];
          } else
            keys[tmp[i]] = parse(0);
        }
      }
    if (sizeof(args) > 0) {
      out = " ";
      FOREACH (args, i) {
        keys["@"+i] = args[i];
        out += "@"+i+" ";
      }
      keys["@"] = out;
    }
    add_command_line(macros[item,1], keys);
    return parse(0);
  }

  // the next construct adds the item to the cmd_list, the real value is
  // given back at the end of this function.
  if (member(robe_symbols, item)) {
    out = dump_argument(robe_symbols[item], -1)[2..<3]; // "({P_FOREST})"[2..<3]
    add_command_line(out, ([ ]));
    item = next_token(0);
  } else {
    int me_token;
    if (use_message_macros &&
        (me_token = LIB_MESSAGE->token2int(item))) {
      out = dump_argument(({ me_token }), -1)[2..<3];
      add_command_line(out, ([ ]));
      item = next_token(0);
    }
  }
  switch (item) {
  case T_END_ARRAY:
  case T_END_MAPPING:
  case T_END_SUBCALL:
  case T_END_INDEX:
    return item;
  case T_START_SUBCALL:
    lastmarked = marked_slot;
    old = result_slot;
    out = ({ });
    count = 0;
    while (item = next_token(0)) {
      if (item == T_END_SUBCALL)
        break;
      if ((++count == 2) && out[0] && objectp(out[0])) {
        out += ({ item });
        continue;
      }
      out += ({ parse(item) });
    }
    if (lastmarked) {
      marked_slot = lastmarked;
      result_slot = old;
    }
    result_slot = call_function(out);
    return look_ahead(result_slot);

  case T_START_ARRAY:
    out = ({ 0 });
    while ((item = next_token(0))) {
      if (item == T_END_ARRAY)
        return look_ahead(out[1..]);
      out += ({ parse(item) });
    }
    error(E_PARENTHESIS("(Runaway array)"));
    break;

  case T_START_MAPPING:
    mappingmode++;
    out = look_ahead(parse_mapping());
    mappingmode--;
    return out;

  case "'":
    return look_ahead(quote(parse(0)));

  case "me":
    return look_ahead(this_player());

  case "here":
    return look_ahead(environment(this_player()));

  case "up":
    if (marked_slot)
      return look_ahead(environment(marked_slot));
    else
      error(E_UP_OPERATOR);
    break;

  case "$":
    return result_slot;

  case "$*":
    return marked_slot;

  case "0":
    return 0;
  }

  if (strlen(item) > 1)
    switch (item[0]) {
    case '$':
      if (member (slot, item))
        return look_ahead(slot[item]);
      break;
    case '#':
      if (item[1] == '\'' && strlen(item) > 2) {
        catch(out = symbol_function(item[2..]));
        if (out)
          return look_ahead(out);
        else
          error(E_NO_CLOSURE(item));
      }
      out = to_int(item[1..]);
      if (!(out && out <= sizeof(indexlist)))
        error (E_ROBE_INDEX(item));
      return look_ahead(indexlist[out-1]);
    case '\"':
      return look_ahead(unquote_string(item[1..<2]));
    case '<':
      if (item[<1] == '>')
        return look_ahead(find_object(item[1..<2]));
      break;
  }

  if (strstr(item, ".") < 0) {
    out = to_int(item);
    if (out)
      return look_ahead(out);
  } else {
    out = to_float(item);
    if (out != to_float("0"))
      return look_ahead(out);
  }

  if (out = symbol_function(item))
    return out;

  if (marked_slot && objectp(marked_slot))
    out = present(item, marked_slot);
  if (!out)
    out = present(item, this_player());
  if (!out)
    out = present(item, environment(this_player()));
  if (!out)
    out = find_player(item);
  if (!out)
    out = find_living(item);
  if (!out)
    out = find_object(item);
  if (!out) {
    old = get_file(item);
    if (old && (old[<2..] == ".c"))
      out = load_object(old);
  }
  if (out)
    return look_ahead(out);

  if (member(robe_symbols, item)) {
    out = robe_symbols[item][0];
    return out;
  } else {
    if (use_message_macros &&
        (out = LIB_MESSAGE->token2int(item))) {
      return out;
    }
  }
  return look_ahead(unquote_string(item));
}

static mixed translate(string term) {
  if (!(term && stringp(term)))
    return term;
  reset_marker();
  add_command_line("({"+term+"})", ([ ]));
  NOTIFY1("-> "+dump_argument(parse(0), 0));
}

void collect_watch_results(mixed *arr) {
  string out;
  mixed *tmp;
  int i;

  if (!(arr[0] && objectp(arr[0]) && PROGRAM_NAME(arr[0]) != WORKFILE))
    return;
  if (HEADLINE)
    out = "-----------------------------------------------------------------------------\n";
  else
    out = "";
  out += "ROBE: "+dump_argument(arr[0],0)+"->"+arr[1]+"(";
  if (sizeof(arr) > 4) {
    tmp = arr[4..];
    FOREACH (tmp,i) {
      out += dump_argument(tmp[i],-1);
      if (i < (sizeof(tmp)-1))
        out += ",";
    }
  }
  out += ") ==> ";
  if (!arr[3])
    out += dump_argument(arr[2],-1);
  else
    out += "*ERROR*\n("+arr[3][1..<2]+")";
  if (HEADLINE)
    out += "\n------------------------------------------------------------------------------\n";
  tell_object(environment(this_object()), out+"\n");
}

/*--------------------------------------------------------------------------*/

string blanks(int i) { return "                                                                                  "[0..i-1]; }
string stars (int i) { return "**********************************************************************************"[0..i-1]; }
string dashes(int i) { return "----------------------------------------------------------------------------------"[0..i-1]; }

static string headline(string str, int mode) {
  string out,fill,line;
  int tab,linelen;

  if (!str)
    return 0;

  if (mode & H_BANNER) {
    line = "*****  "+str+"  *****";
    fill = "*";
  } else {
    line = str;
    fill = "-";
  }
  linelen = strlen(line);
  if (linelen > 79)
    linelen = 79;

  if (mode & H_CENTER)
    tab = (80-linelen) / 2;
  else
    tab = 0;

  out = blanks(tab)+line+"\n";
  
  if (mode & H_BANNER)
    out = blanks(tab)+stars(linelen)+"\n" +
          out +
          blanks(tab)+stars(linelen)+"\n";
  else
    out += blanks(tab)+dashes(linelen)+"\n";
  return out;
}

static mixed *make_unique_array(mixed *arr) {
  int i;
  mixed *out;

  out = ({ });
  FOREACH (arr, i)
    if (member(out, arr[i]) < 0)
      out += ({ arr[i] });
  return out;
}

static mixed *insert_item(mixed item, mixed *arr, int pos) {
  int size;

  if (!pos)
    return ({ item }) + arr;
  if (pos == sizeof(arr))
    return arr + ({ item });
  return arr[0..pos-1] + ({ item }) + arr[pos..];
}

static string dump_object(object ob) {
  string out;

  if (!ob)
    return "NULL POINTER";
  out = SHORT(ob);
  if (!out || out == "")
    out = "INVISIBLE OBJECT";
  return out + " <" + object_name(ob) + ">";
}

/*--------------------------------------------------------------------------*/

static mixed *get_actions(object ob, string mask, object target) {
  object tmp;
  mixed *ar, *out;
  int i;

  ar = query_actions(ob, 27);
  if (!sizeof(ar)) {
    MOVE(PROBE,ob);
    ar = query_actions (PROBE,27);
    if ((tmp = find_object(PROBE)))
      DESTRUCT(tmp);
  }
  if (!sizeof(ar))
    return 0;

  for (i=0 ; i<sizeof(ar)-3 ; i+=4) {
    if (target && ar[i+2] != target)
      continue;
    if (ar[i+1]) {
      if (mask && strstr(mask,ar[i]) != 0)
        continue;
    } else
      if (mask && ar[i] != mask)
        continue;
    return ({ ar[i], ar[i+2], ar[i+3] });
  }
  return 0;
}

static int Actions(string str) {
  object ob, target;
  mixed mask, *ar, *co, entry;
  string *keys;
  int i,j;

  switch (match_arguments(str,
                          ({({ "object" }),
                            ({ "object", "object" }),
                            ({ "object", "command" }),
                            ({ "object", "string"}),
                          }))) {
  case 1:
    HLINE("All actions of "+dump_argument(argv[0],0));
    break;
  case 2:
    HLINE("All actions of "+dump_argument(argv[0],0) +
          "defined by "+dump_argument(argv[1],0));
    target = argv[1];
    break;
  case 3:
  case 4:
    HLINE("The execution chain of command \"" + argv[1] +
          "\" in object "+dump_argument(argv[0],0));
    mask = argv[1];
    break;
  default:
    FAIL("Usage: Actions <object> <command>");
  }

  ar = query_actions(argv[0], 27);
  if (!sizeof(ar)) {
    MOVE (PROBE,argv[0]);
    ar = query_actions(PROBE, 27);
    if ((ob = find_object(PROBE)))
      DESTRUCT (ob);
  }
  co = argv[0]->query_daemons();
  if (co && pointerp(co) && pointerp(co[0]) && sizeof(ar)) {
    co = co[0];
    FOREACH (co,i) {
      if (!(ob = find_object(co[i])))
        ob = load_object(load_name(co[i]));
      if ((entry = ob->get_commands()) && mappingp(entry)) {
        keys = m_indices(entry);
        FOREACH (keys,j)
          ar += ({ keys[j], 0, ob, entry[keys[j]] });
      }
    }
  }
  if (!sizeof(ar))
    NOTIFY1(dump_argument(argv[0],0) +
           " doesn't seem to define any actions!");

  log = "";
  for (i=0 ; i<sizeof(ar)-3 ; i+=4) {
    if (target && ar[i+2] != target)
      continue;
    if (ar[i+1]) {
      if (mask && strstr(mask,ar[i]) != 0)
        continue;
    } else
      if (mask && ar[i] != mask)
        continue;
    log += sprintf("%-25s%s->%s()\n", dump_argument(ar[i],0),
                   dump_argument(ar[i+2],0), ar[i+3]);
  }
  PAGE(log);
  return 1;
}

/*--------------------------------------------------------------------------*/

static int Add(string str) {
  string *arr,lpath;
  int pos;

  switch (match_arguments(str, ({({ "directory" }),
                                 ({ "directory", "integer"}),
                               }))) {
  case  1: pos = sizeof(dir_array);
           break;
  case  2: pos = argv[1]-1;
           if (pos < 0 || pos > sizeof(dir_array))
             NOTIFY1("Illegal path entrynumber!");
           break;
  default: FAIL("Usage: Add <directory> <entrynumber>");
           break;
  }
  dir_array = insert_item(argv[0], dir_array,pos);
  NOTIFY1("Directory "+argv[0]+" inserted at position "+(pos+1)+".");
}

/*-------------------------------------------------------------------------*/

static nomask int Call(string str) {
  flags |= O_VERBOSE|O_HEADLINE;
  reset_marker();
  log = "";
  add_command_line("("+str+")",([]));
  result_slot = parse(0);
  if (this_player())   // Call me quit *sigh*
    PAGE(log);
  return 1;
}

#ifndef NIRVLIB
static
#endif
nomask int Call2(string str) {
  if (!check_safety())
    return 0;
  flags = 0;
  reset_marker();
  if (!str)
    add_command_line(query_verb(), ([ ]));
  else
    add_command_line(query_verb()+" "+str, ([ ]));
  result_slot = parse(0);
  PAGE("==> "+DA(result_slot));
  return 1;
}

#ifndef NIRVLIB
static
#endif
nomask int Call3(string str) {
  mixed out;

  if (!check_safety())
    return 0;

  flags = 0;
  reset_marker();
  if (!str)
    add_command_line("("+query_verb()+")", ([ ]));
  else
    add_command_line("("+query_verb()+" "+str[0..<2]+"})", ([ ]));
  out = parse(0);
  if (out && pointerp (out) && (sizeof(out) == 1))
    PAGE("==> "+DA(out[0]))
  else
    PAGE("==> "+DA(out));
  return 1;
}

static nomask mixed call_lfun(mixed *arr) {
  mixed result;
  string out,error;
  int i;

  if (HEADLINE)
    log += "----------------------------------------------------------------------------\n";
  if (sizeof(arr) == 1) {
    if (VERBOSE)
      log += dump_argument(arr[0],1)+"\n";
    return arr[0];
  }

  if (VERBOSE) {
    out = dump_argument(arr[0],0)+"->"+arr[1]+"(";
    for (i=2; i<sizeof(arr); i++)
      out += " "+dump_argument(arr[i],-1) + ",";
    if (sizeof(arr) > 2)
      out = out[0..<2]+" ";
    log += out+")";
  }

  if (function_exists(arr[1],arr[0])) {
    if (VERBOSE)
      log += "\n";
    result = apply(#'call_other,arr);
    if (!SUPPRESS)
      log += "==> "+dump_argument(result,0)+"\n";
    return result;
  }
  if (VERBOSE)
    log += " does not exist!";
  return 0;
}

static mixed call_efun(mixed *arr) {
  mixed result;
  string out,error;
  int i;

  if (HEADLINE)
    log += "----------------------------------------------------------------------------\n";
  if (VERBOSE) {
    out = dump_argument(arr[0],0)[2..]+"(";
    for (i=1; i<sizeof(arr); i++)
      out += " "+dump_argument(arr[i],-1) + ",";
    if (sizeof(arr)>1)
      out = out[0..<2]+" ";
    log += out + ")\n";
  }

  result = apply(arr[0],arr[1..<1]);

  if (!SUPPRESS)
    log += "==> "+dump_argument(result,0)+"\n";

  return result;
}

static mixed call_function(mixed *args) {
  mixed result;

  if (!(pointerp(args) && (sizeof(args)>0)))
    error ("Need an object or efun to call!");

  if (closurep(args[0]))
    return call_efun (args);

  if (!objectp(args[0]) && marked_slot)
    args = ({ marked_slot }) + args;

  if (objectp(args[0]))
    return call_lfun (args);
  else {
    result = symbol_function(args[0]);
    if (result) {
      args[0] = result;
      return call_efun(args);
    }
    error("Need an object!");
  }
  return 0;
}

/*-------------------------------------------------------------------------*/

#ifdef SHELL
static int Robe_shell(string com, string str) {
  switch (match_arguments(str, ({({ "playerfile" }),
                                 ({ "filename" }),
                               }))) {
  case  1:
  case  2: execute_shell(com, argv[0]);
           return 1;
  }
  // default
  FAIL("Usage: "+C(com)+" <file>");
}

static int Cat(string str) {
  return Robe_shell("cat", str);
}
#endif

/*-------------------------------------------------------------------------*/

static int Cd(string str) {
  if (!str)
    str = "~";
  switch (match_arguments(str, ({({ "directory" }),
                                 ({ "integer" }),
                                }))) {
  case  1: execute_shell("cd", argv[0]);
           return 1;
  case  2: if (argv[0] > 0 && argv[0] <= sizeof(dir_array)) {
             execute_shell("cd", dir_array[argv[0]-1]);
             return 1;
           }
           FAIL("Illegal path entrynumber!");
  }
  // default:
  FAIL("Usage: Cd <directory>");
}

/*-------------------------------------------------------------------------*/

#ifdef NIRVLIB

static int accept_changes (string str, string text) {
  if (str && ((str=="n") || (str=="N")))
    NOTIFY1("Aborted.");

  log_file (LOGFILE, text);
  NOTIFY1("Logfile entry added.");
}

static void changed_done(string name, string str) {
  string out, tmp;
  int i;

  if (!str) {
    OUT("Aborted.");
    return;
  }
  if ((!files) || (!sizeof(files)))
    return /* 1 */;  /* should not happen */

  out = "-----------------------------------------------------------------------------\n";
  out += ">> "+ctime()+" by "+this_player()->query_vis_name();
  if (sizeof(files) > 1)
    out += " ("+sizeof(files)+" files)";
  else
    out += " (1 file)";

  tmp = files[0];
  for (i=1; i<sizeof (files); i++)
    tmp += "   "+files[i];

  out += "\n\n"+break_string(tmp, 76)+"\n\n";
  out += break_string(str, 76);
  OUT (out+"-----------------------------------------------------------------------------");
  write("Commit changes? Type 'n' to abort: ");
  input_to("accept_changes",0,out);
}

static void changed_loop(string str, string text) {
  if (!str) {
    text += "\n";
    write ("] ");
    return input_to("changed_loop",0,text), 0;
  }

  if ((str==".") || (str=="**"))
    return changed_done(0,text);
  if (str=="~q") {
    OUT("Aborted.");
    return;
  }

  text += str+"\n";
  write ("] ");
  return input_to("changed_loop",0,text), 0;
}
    
static int Changed(string str) {
  mixed *out;
  int i;

  if (!str)
    FAIL ("Usage: Changed <file1> <file2> ...");

  flags = 0;
  reset_marker();
  add_command_line ("({"+str+"})",([]));
  out = parse(0);
  files = allocate(sizeof(out));

  FOREACH (out, i) {
    files[i] = get_file(out[i]);
    if (!files[i])
      NOTIFY1 ("No such file: "+DA(out[i]));
  }

  /* Plausibilitaetscheck */
  FOREACH (files, i)
    if ((time() - file_time(files[i])) > 86400)
      OUT ("Warning: "+files[i]+" last changed on "
           +ctime(file_time(files[i]))[4..9]+", "
           +ctime(file_time(files[i]))[<4..]);

  if (editor)
    "/etc/editor"->edit_temp(({}),#'changed_done);
  else {
    write ("] ");
    input_to("changed_loop", 0, "");
  }
  return 1;
}

#endif

/*-------------------------------------------------------------------------*/

static int Check(string str) {
  switch (match_arguments(str, ({({ "object" })}))) {
  case  1: debug_info(1, argv[0]);
           return 1;
  }
  // default:
  FAIL("Usage: Check <object>");
}

/*-------------------------------------------------------------------------*/

static varargs void execute_clean(object ob, status clean_all) {
  object *list;
  int i;

  list = all_inventory(ob);
  for (i = sizeof(list); i-->0; ) {
    if (!query_once_interactive(list[i])) {
      execute_clean(list[i]); 
      OUT(dump_argument(list[i],0)+" destructed.");
      DESTRUCT(list[i]);
    }
  }
}

static int Clean(string str) {
  mixed arr;
  object ob;
  int i;

  if (!str)
    str = "here";
  switch (match_arguments(str, ({({ "object" }),
                                 ({ "directory", "confirmed" }),
                               }))) {
  case 0: argv = ({ environment(this_player()) });
  case 1: execute_clean (argv[0]);
          NOTIFY1(dump_argument(argv[0],0)+" is cleaned up.");
  case 2: if (!write_check(argv[0]))
            NOTIFY1("You aren't allowed to clean "+argv[0]);
          arr = get_dir(argv[0]+"/*.c",1);
          FOREACH (arr,i)
            if (ob = find_object(argv[0]+"/"+arr[i])) {
              OUT(DA(ob)+" destructed.");
              DESTRUCT (ob);
            }
          NOTIFY1("Directory "+argv[0]+" is cleaned up.");
  }
  // default: 
  FAIL("Usage: Clean <object>\n       Clean <directory> confirmed");
}

/*-------------------------------------------------------------------------*/

#ifdef SHELL
static int Clone(string str) {
  return Robe_shell("clone", str);
}
#endif

/*-------------------------------------------------------------------------*/

static int list_watches(object *ob) {
  mixed *arr;
  int i,j;

  if (!ob) {
    ob = m_indices(watches);
    if (sizeof(ob))
      HLINE("You are deep-watching the following calls:")
    else
      NOTIFY1("You aren't deep-watching any calls right now.");
  }
  FOREACH(ob,i) {
    arr = watches[ob[i]];
    FOREACH(arr,j)
      OUT(dump_argument(ob[i],0)+"->"+arr[j]+"()");
  }
  return 1;
}

static int remove_watches (object ob, int quiet) {
  object sh,tmp;
  string *func,bpname;

  if (!(ob && objectp(ob)))
    return 0;
  if (member(watches,ob)) {
    if (!quiet)
      OUT("You don't deepwatch "+dump_argument(ob,-1)+" anymore.");

    watches = m_delete(watches, ob);
    bpname = PROGRAM_NAME(ob);
    sh = find_object(bpname);
    if (sh)
      DESTRUCT(sh);

    if (clonep(ob))
      sh = clone_object(bpname);
    else
      sh = load_object(bpname);
    if (ob) {
      tmp = environment(ob);
      if (tmp)
        MOVE(sh, tmp);
      DESTRUCT(ob);
    }
  }
  else if (!quiet)
    OUT("You didn't deepwatch "+dump_argument(ob,-1)+" yet.");
  return 1;
}

static int parameter_number(object ob, string func) {
  mixed *fl;
  int i;

  fl = functionlist(ob, 9);
  i = member_array(func,fl);
  return fl[i+1];
}

static string add_varlist(int num) {
  int i;
  string t2;

  t2 = "";
  for (i=1 ; i<=num ; i++) {
    t2 += "v"+i;
    if (i<num)
      t2 += ",";
  }
  return t2;
}

static int Deepwatch(string str) {
  string bpname;
  object bp;
  mixed tmp;
  int i, parcount;

  if (!str)
    return list_watches(0);
  switch (match_arguments(str, ({({ "object" }),
                                 ({ "object", "stringlist" }),
                               }))) {
  case  1: return remove_watches (argv[0],0);
  case  2: break;
  default: FAIL("Usage: Deepwatch <object> <func1> <func2> ...");
  }

  if (!write_check(PROGRAM_NAME(argv[0])))
    NOTIFY1("Sorry, but you aren't allowed to use Deepwatch on " +
           DA(argv[0]));
  
  if (query_once_interactive(argv[0]) || argv[0] == this_object())
    NOTIFY1("You can't do this. Use 'Watch' instead.");

  tmp = watches[argv[0]];
  FOREACH(argv[1],i) {
    if (tmp && member(tmp, argv[1][i]) >= 0) {
      OUT("You already deepwatch "+argv[1][i]+"().");
      argv[1][i] = 0;
      continue;
    }
    if (!function_exists(argv[1][i],argv[0])) {
      OUT ("No function "+unquote_string(argv[1][i])
        +"() in "+dump_argument(argv[0],0));
      argv[1][i] = 0;
    }
  }
  if (!sizeof(argv[1] -= ({ 0 })))
    return 1;
  if (tmp = watches[argv[0]])
    argv[1] = make_unique_array(argv[1]+tmp);

  bpname = PROGRAM_NAME(argv[0]);
  bp = load_object(bpname);
  if (!bp)
    NOTIFY1("Error: Couldn't load the blueprint of "+dump_argument(argv[0],-1));

  tmp = find_object(WORKFILE+"_tmp");
  if (tmp)
    DESTRUCT(tmp);

  rename_object(bp, WORKFILE+"_tmp");

  tmp = "inherit \""+WORKFILE+"_tmp\";\n\n"
      + "mixed r_cat,r_res;\nobject r_robe;\n";
  FOREACH (argv[1],i) {
    parcount = parameter_number (argv[0],argv[1][i]);
    tmp += "\n"+argv[1][i]+"("+add_varlist(parcount)+")\n{\n\t"
         + "r_cat = catch (r_res = ::"+argv[1][i]+"("
         + add_varlist(parcount)+"));\n\t"
         + "r_robe = find_object (\""
         + object_name(this_object())+"\");\n\t"
         + "if (r_robe)\n\t\tr_robe->collect_watch_results (\n\t\t\t"
         + "({this_object(),\""+argv[1][i]+"\",r_res,r_cat,"
         + add_varlist(parcount)+"}) );\n\t"
         + "return r_res;\n}\n";
  }

  operate_file(#'rm, WORKFILE);
  if (!operate_file(#'write_file, ({ WORKFILE, tmp })))
    NOTIFY1("Couldn't write the deepwatch-object file!");

  if (tmp = find_object(WORKFILE))
    DESTRUCT(tmp);
  tmp = load_object(WORKFILE);
  if (!tmp)
    NOTIFY1("Couldn't load the deepwatch-object file!");
  rename_object(tmp,bpname);
  
  if (clonep(argv[0])) {
    bp = clone_object(bpname);
    DESTRUCT(tmp);
  }
  else
    bp = load_object(bpname);

  if (environment(argv[0]))
    MOVE(bp, environment(argv[0]));
  DESTRUCT(argv[0]);

  watches[bp] = argv[1];
  list_watches(({ bp }));
  return 1;
}

/*-------------------------------------------------------------------------*/

#ifdef SHELL
static int Ed(string str) {
  return Robe_shell("ed", str);
}
#endif

/*-------------------------------------------------------------------------*/

static int Error(string str) {
  string dest;

  switch (match_arguments(str, ({({ "playername" })}))) {
  case  0: dest = "/log/"+this_player()->query_real_name();
           break;
  case  1: dest = "/log/"+L(argv[0]);
           break;
  default: FAIL ("Usage: Error <player>");
  }
  execute_shell("tail", dest);
  if (!str)
    log_file(dest,"--------- Last Errorcheck\n");
  return 1;
}

/*-------------------------------------------------------------------------*/

#ifdef NIRVLIB
static int Expect(string str) {
  int i;

  switch (match_arguments(str, ({({ "playername" })}))) {
  case  0: if (sizeof(expect_list)) {
             write ("Expected players:");
             FOREACH (expect_list,i)
               write(" "+C(expect_list[i]));
             NOTIFY1(".");
           }
           NOTIFY1("You don't expect special players.");
  case  1: if (!MEMBER(expect_list, argv[0])) {
             expect_list += ({ argv[0] });
             NOTIFY1("You expect "+C(argv[0])+".");
           } else {
             expect_list -= ({ argv[0] });
             NOTIFY1("You don't expect "+C(str)+" anymore.");
           }
           break;
  }
  // default: 
  FAIL("Usage: Expect <player>");
}
#endif

/*-------------------------------------------------------------------------*/

static int Flush(string str) {
  string *arr,item;
  int i;

  if (!str) {
    marked_slot = 0;
    result_slot = 0;
    slot = ([ ]);
    reset_marker();
    NOTIFY1("All slots flushed.");
  }
  arr = explode(str," ") - ({ "" });
  FOREACH (arr,i)
    switch (arr[i]) {
    case "$":
      result_slot = 0;
      OUT("Result slot flushed.");
      break;
    case "$*":
      marked_slot = 0;
      OUT("Marked object flushed.");
      break;
    default:
      if (arr[i][0] != '$')
        NOTIFY1("Usage: Flush <slot1> <slot2> ...");
      item = arr[i][1..];
      if (!member(slot, item)) {
        OUT("Skipping $"+item+" (no such slot)");
        break;
      }
      m_delete(slot, item);
      OUT("Slot $"+item+" flushed.");
    }
  return 1;
}

/*-------------------------------------------------------------------------*/

static string find_function(string name, object ob) {
  string where,*arr;
  mixed *list;
  int i, pos;

  if (where = function_exists(name,ob))
    return where;

  arr = inherit_list(ob);
  FOREACH (arr,i) {
    list = functionlist(arr[i],3);
    pos = member(list,name) + 1;
    if (pos && !(list[pos] & NAME_INHERITED))
      return arr[i][0..<3];
  }
  return 0;
}

static int Functions(string str) {
  string *names, *list, where, target;
  mixed *arr, *arr2, *out;
  int i, pos, mask, max, max2;

  switch (match_arguments(str, ({({ "object" }),
                                 ({ "-deep", "object" }),
                                 ({ "object", "string" }),
                               }))) {
  case  1: HLINE("Functionlist of "+DA(argv[0]));
           target = PROGRAM_NAME(argv[0]);
           target = target[1..<3];
           argv += ({ "" });
           break;
  case  2: argv[0] = argv[1];
           argv[1] = "";
           HLINE("Full functionlist of " + DA(argv[0]));
           break;
  case  3: HLINE("Full functionlist of " + DA(argv[0]) +
                 " with pattern "+DA(argv[1]));
           break;
  default: FAIL("Usage: Functions <object> [pattern]");
  }

  names = ({ 0 }) + sort_array(functionlist(argv[0], 1), #'>);
  arr = functionlist(argv[0],
                     RETURN_FUNCTION_NAME  |
                     RETURN_FUNCTION_FLAGS |
                     RETURN_FUNCTION_TYPE  |
                     RETURN_FUNCTION_NUMARG);
  out = allocate(sizeof(names));

  for (i=1; i<sizeof(names); i++) {
    if (strstr(names[i], argv[1]) == -1 || names[i-1] == names[i])
      continue;
    where = find_function(names[i], argv[0]);
    if (!target || where == target) {
      pos = member(arr,names[i]);
      out[i] = ({ where }) + arr[pos..(pos+3)];
    }
  }
  if (!sizeof(out -= ({ 0 })))
    NOTIFY1("No matching functions.");

  max  = 0;
  max2 = 0;
  arr  = allocate(sizeof(out));
  arr2 = allocate(sizeof(out));
  FOREACH (out,i) {
    arr[i] = "";
    mask = out[i][2];
    if (mask & TYPE_MOD_PRIVATE)
      arr[i] += "private ";
    if (mask & TYPE_MOD_STATIC)
      arr[i] += "static ";
    if (mask & TYPE_MOD_NO_MASK)
      arr[i] += "nomask ";
    if (mask & TYPE_MOD_VARARGS)
      arr[i] += "varargs ";
    if ((mask = strlen(arr[i])) > max)
      max = mask;
    arr2[i] = "";
    switch (out[i][3]) {
    case TYPE_NUMBER : arr2[i] = "int";
          break;
    case TYPE_STRING : arr2[i] = "string";
          break;
    case TYPE_OBJECT : arr2[i] = "object";
          break;
    case TYPE_MAPPING: arr2[i] = "mapping";
          break;
    case TYPE_FLOAT  : arr2[i] = "float";
          break;
    case TYPE_VOID   : arr2[i] = "void";
          break;
    case TYPE_CLOSURE: arr2[i] = "closure";
          break;
    case TYPE_SYMBOL : arr2[i] = "symbol";
          break;
    case 65          : arr2[i] = "int*";
          break;
    case 66          : arr2[i] = "string*";
          break;
    case 68          : arr2[i] = "object*";
          break;
    case 69          : arr2[i] = "mapping*";
          break;
    case 70          : arr2[i] = "float*";
          break;
    case 71          : arr2[i] = "mixed*";
          break;
    case 73          : arr2[i] = "closure*";
          break;
    case 74          : arr2[i] = "symbol*";
          break;
    default          : arr2[i] = "mixed";
          break;
    }
    if ((mask = strlen(arr2[i])) > max2)
      max2 = mask;
  }
  log = "";
  if (max > 15)
    max = 15;
  FOREACH (out,i)
    log +=sprintf("%-"+max+"s%-"+max2+"s %-26s <%s>\n",arr[i],
          arr2[i], out[i][1]+"("+add_varlist(out[i][4])+")",out[i][0]);
  PAGE(log);
  return 1;
}

/*-------------------------------------------------------------------------*/

static void help_out(string mess, string str) {
  string *out;
  int i;

  out = explode(str,"\n");
  printf ("\n%-14s%s\n", mess, out[0]);
  for (i=1; i<sizeof(out); i++)
    OUT("              "+out[i]);
}

static int Help(string str) {
  int i,j,max;
  string out,*full;

  if (!str) {
    if (lang == "deutsch")
      BANNER("Es gibt Helpfiles fuer folgende Befehle:")
    else
      BANNER("There are helpfiles for these commands:");
    write("\n");
    i = 0;
    max = sizeof(command_array);
    while (i<max) {
      out = "";
      for(j=i; j<i+7; j++)
        if (j<max)
          out += sprintf("%-11s",command_array[j]);
      OUT(out);
      i += 7;
    }
    write("\n");
    if (lang == "deutsch")
      BANNER("Weitere Helpfiles gibt es fuer die Topics:")
    else
      BANNER("There are additional helpfiles for these topics:");
    NOTIFY1("\n"+implode(help_array,", ")+".");
  }

  full = command_array + help_array;
  i = member_array(C(str), full);
  if (i >= 0) {
    if (sizeof(info_array[i]) > 2) {
      BANNER (full[i]);
      help_out("SYNTAX:", info_array[i][0]);
      if (lang == "deutsch")
        help_out("DESCRIPTION:", info_array[i][1]);
      else
        help_out("DESCRIPTION:", info_array[i][2]);
      help_out("EXAMPLES:", info_array[i][3]);
      if (info_array[i][4])
        help_out("SEE ALSO:", info_array[i][4]);
    } else
      if (lang == "deutsch")
        OUT("\n"+info_array[i][0]);
      else
        OUT("\n"+info_array[i][1]);
    return 1;
  }

  str = L(str);
  if (str == "english") {
    lang = "english";
    NOTIFY1("Help will be printed in English.");
  }
  if (str == "german") {
    lang = "deutsch";
    NOTIFY1("Hilfetexte werden auf Deutsch ausgegeben.");
  }
  FAIL("No help available for the subject "+C(str)+"!");
}

/*-------------------------------------------------------------------------*/

static int Last(string str) {
  object ob;

  switch (match_arguments(str, ({({ "playername" })}))) {
  case  0: tail ("/syslog/ENTER");
           return 1;
  case  1: if ((ob = find_player(argv[0])) && interactive(ob))
             NOTIFY1(C(argv[0]) + " is still online!");
           NOTIFY1("The last login of "+C(argv[0])+" was at " +
                  ctime(ETC_FINGERD->query_last_login(argv[0])) + ".");
  default: FAIL("Usage: Last <player>");
  }
  NO_WARN_MISSING_RETURN;
}

/*-------------------------------------------------------------------------*/

static int Light(string str) {
  switch (match_arguments(str, ({({ "integer" })}))) {
#ifdef NIRVLIB
  case  0: OUT("The light level of this room is " +
               (all_environment(this_object())[<1])->query_light()+".");
           OUT("The light level sum of all lights in this room is " +
               query_light(all_environment(this_object())[<1])+".");
           break;
#else
  case  0: OUT("The light level of this room is " + set_light(0) + ".");
           break;
#endif
  case  1: set_light(argv[0]-lightlevel);
           lightlevel = argv[0];
           break;
  default: FAIL("Usage: Light <lightlevel>\n");
  }
  if (!lightlevel)
    NOTIFY1("The Robe doesn't radiate any light.");
  else
    NOTIFY1("The Robe radiates light of level "+lightlevel+".");
}

int query_light() {
  return lightlevel;
}

/*-------------------------------------------------------------------------*/

static int List(string str) {
  int i, ns;
  object ob;

  switch (match_arguments(str, ({({ "-noshort", "object" }),
                                 ({ "object" }),
                               }))) {
  case  1: ns = 1;
           argv[0] = argv[1];
  case  2: indexlist = all_inventory(argv[0]);
           break;
  default: FAIL("List the inventory of which object?");
  }

  log = "";
  HLINE("Inventory of "+dump_object(argv[0]));
  FOREACH(indexlist,i) {
    if (ns)
      log += sprintf("#%2d : ", i+1) + DA(indexlist[i]) + "\n";
    else
      log += sprintf("#%2d : ", i+1) + dump_object(indexlist[i]) + "\n";
  }
  if (!sizeof(indexlist))
    OUT("No inventory!");
  PAGE(log);
  return 1;
}

/*-------------------------------------------------------------------------*/

static string clean_string(string str) {
  int i, pos;

  for (i=0; i<strlen(str); i++)
    if (str[i]=='\t')
      str[i] = ' ';
  return str;
}

static mapping extract_symbols(string file) {
  mixed tmp;
  string *lines, includefile, s1, s2;
  int i, pos;

  if (!(tmp = safe_read_file(file)))
    return ([ ]);
  make_shared_string(tmp);
  if (catch(lines = explode(tmp, "\n"))) {
    OUT("Sorry, but this file is too large to be loaded.");
    return ([ ]);
  }

  FOREACH(lines, i) {
    if (lines[i][0] != '#')
      continue;

    if (sscanf(lines[i], "#include%s<%s>", s1, s2) == 2) {
      loadincs += ([ s2 ]);
      if (!(includefile = get_file(INCLUDEDIR+s2)))
        continue;
      loadsyms += extract_symbols(includefile);
      continue;
    }

    if (strstr(lines[i], "#define") == 0) {
      tmp = clean_string(lines[i][7..]);
      // TODO: better regexplode with whitestrings
      tmp = explode(tmp, " ") - ({""});
      if (sizeof(tmp)) {
        if (pos = strstr(tmp[0], "(")<0)  // no macro
          loadsyms += ([ tmp[0] ]);
      }
    }
  }
  return loadsyms;
}

static string build_workfile(string file) {
  string *syms, *incs, *workfile, out;
  int i, l;

  loadincs = ([ ]);
  loadsyms = ([ ]);
  workfile = allocate(900);
  syms = m_indices(extract_symbols(file));
  if (!sizeof(syms))
    return 0;
  incs = m_indices(loadincs);
  workfile[l++] = "#include \""+file+"\"";
  FOREACH(incs,i)
    workfile[l++] = "#include <"+incs[i]+">";
  workfile[l++] = "mixed r_e,r_r;";
  workfile[l++] = "mixed r_e(varargs args) {return args;}";
  workfile[l++] = "mixed r_g (string sym) {";
  FOREACH (syms, i)
    workfile[l++] = "if(sym==\""+syms[i]+"\"){if(catch(r_r=r_e("+syms[i]+")))return 0;return r_r;}";
  workfile[l] = "}";
  out = implode(workfile[0..l], "\n");
  return out;
}

static int incorporate_symbols(mixed *arguments) {
  mapping syms;
  string filetext, filename, *symbols;
  int quiet;
  object bp;
  mixed *tmp;
  int i;

  syms     = arguments[0];
  filetext = arguments[1];
  filename = arguments[2];
  quiet    = arguments[3];

  operate_file(#'rm, WORKFILE);
  if (!operate_file(#'write_file, ({ WORKFILE, filetext })))
    NOTIFY1("Robe error: Couldn't write the temporary workfile!");
  if (bp = find_object(WORKFILE))
    DESTRUCT(bp);
  if (catch(bp = load_object(WORKFILE)))
    NOTIFY1("Robe Error: Couldn't decipher the symbols of file " +
           filename + ", sorry.");

  symbols = m_indices(syms);
  FOREACH(symbols, i) {
    tmp = bp->r_g(symbols[i]);
    if (tmp && sizeof(tmp)) {
      robe_symbols[symbols[i]] = tmp;
      inverted_symbols[tmp[0]] = symbols[i];
    }
  }
  NOTIFY1 ("Symbols of file "+filename+" loaded.");
}

static int load_file(string file, int quiet) {
  string out;

  if (file_size(file) < 0)
    NOTIFY1("Warning: File "+file+" does not exist!");
  loadsyms = ([ ]);

  if (file == "/sys/message.h") {
    use_message_macros = 1;
    if (!quiet) {
      OUT("Evaluation of message macros is switched on.");
    }
  }

  out = build_workfile(file);
  if (!out)
    return 1;
  if (!quiet)
    OUT ("Loading symbols of "+file+" ...");
  call_out(#'incorporate_symbols, 1, ({ loadsyms, out, file, quiet }));
  return 1;
}

static int Loaddef(string str) {
  string file, out;

  switch (match_arguments(str, ({({ "object" }),
                                 ({ "filename" }),
                               }))) {
  case  1: file = PROGRAM_NAME (argv[0]);
           break;
  case  2: file = argv[0];
           break;
  default: FAIL("Usage: Loaddef <object>\n"
                "       Loaddef <file>");
  }
  return load_file(file, 0);
}

static void do_load_object(string fn) {
  if (fn[<2..<1] == ".c")
    fn = fn[0..<3];
  if (find_object(fn))
    OUT(fn + " is already loaded.");
  else {
    OUT("Loading " + fn);
    load_object(fn);
  }
}

static int Load(string str) {
  string file, out, *files;

  switch (match_arguments(str, ({({ "object" }),
                                 ({ "filename" }),
                                 ({ "directory" }),
                                 ({ "directory", "string" }),
                               }))) {
  case  1: file = PROGRAM_NAME(argv[0]);
           break;
  case  2: file = argv[0];
           break;
  case  3:
  case  4: file = argv[0];
           if (file[<1] != '/')
             file += "/";
           if (sizeof(argv) > 1) {
             if (argv[1] == "-r" || argv[1] == "-R")
               OUT("The recursive option is not supported yet.");
           }
           files = (get_dir(file+"*") || ({ })) - ({ ".", ".." });
           files = filter(files, (: if ($1[<2..<1] == ".c") return $1; :));
           map(files, (: call_out(#'do_load_object, 2, $2 + $1) :), file);
           OUT("Ok.");
           return 1;
  default: FAIL("Usage: Load <object>\n"
                "       Load <file>\n"
                "       Load <directory> [-r]");
  }
  do_load_object(file);
  return 1;
}

/*-------------------------------------------------------------------------*/

static int Log(string str) {
  int lines;
  string file;
  lines = 0;
  file  = 0;
  switch (match_arguments(str, ({({ "integer" }),
                                 ({ "string" }),
                                 ({ "string", "integer" }),
                               }))) {
  case  0: lines = 15;
  case  1: if (!lines)
             lines = argv[0];
           file = "/"+query_host_name()+".debug.log";
  case  2: if (!file) {
             file = argv[0];
             lines = 15;
           }
  case  3: if (!file)
             file = argv[0];
           if (!lines)
             lines = argv[1];
           if (file_size(file) > 0) {
             tail(file, lines);
             return 1;
           }
           if (file_size(SYSLOGDIR + file) > 0) {
             tail(SYSLOGDIR + file, lines);
             return 1;
           }
           if (file_size("/log/" + file) > 0) {
             tail("/log/" + file, lines);
             return 1;
           }
  default: FAIL("Usage: Log [logfile] [#lines]");
  }
  NO_WARN_MISSING_RETURN;
}

/*-------------------------------------------------------------------------*/

static string strip_regexp(string s, string re) {
  string *a;
  int i;

  a = regexplode(s, re);
  return a[0] + " " + implode(a[2..],"");
}

static string strip_raw_text(string s) {
  int begin, end, temp;
  int i;
  string *select;
  string which;

  select = ({ "\"", "'", "/*", "//" });
  for (;;) {
    which = "";
    begin = strlen(s);
    for (i=0; i<sizeof(select); i++) {
      temp = strstr(s, select[i]);
      if (temp >= 0 && temp < begin) {
        begin = temp;
        which = select[i];
      }
    }
    switch (which) {
    case "":
      return s;
    case "\"":
      s = strip_regexp(s, "\"([^\"]|\\\")*\"");
      break;
    case "'":
      s = strip_regexp(s, "'([^']|\\')*'");
      break;
    case "//":
      return s[0..begin-1];
    case "/*":
      end = strstr(s, "*/", begin+2);
      if (end < 0)
        return s[0..begin-1];
      s[begin..end+1] = " ";
      break;
    }
  }
  return 0;
}

static int one_line_function(string s) {
  int i;
  int *c;
  mapping count;

  count = ([ ]);
  c = to_array(strip_raw_text(s));
  for (i=0; i<sizeof(c); i++)
    count[c[i]]++;
  return count['{'] && count['{'] == count['}'];
}

static int find_lfun_pos(string *range, string lfun) {
  string *match;

  match = regexp(range,lfun);
  match = regexp(match,
                 "^([a-zA-Z_][a-zA-Z0-9_* \t]*\\<|)" + lfun +
                 "\\>[ \t]*\\([ \ta-zA-Z_0-9*,]*(\\)[ \t]*|)($|//|/\\*|{)");
  if (!sizeof(match))
    return -1;
  return member_array(match[0], range);
}

mixed lookup(string filename, string lfun) {
  int current, length, newlines, t, begin, end, line;
  string *block;
  mapping mfilter;
  string s, head;

  mfilter = ([ '\n' : 1 ]);
  s = make_shared_string(safe_read_file(filename));
  length = strlen(s);
  newlines = 0;
  head  = "";
  begin = 0;
  line  = 1;
  for (current=0; current<length; current+= LOOKUP_BLOCK_SIZE) {
    t = sizeof(filter(to_array(s[current..current+LOOKUP_BLOCK_SIZE-1]),
                      mfilter));
    newlines += t;
    if (newlines >= LOOKUP_BLOCK_SIZE) {
      newlines = t;
      block = explode(s[begin..current-1], "\n");
      block[0] = head + block[0];
      t = find_lfun_pos(block[0..<2], lfun);
      if (t >= 0)
        break;
      head = block[<1];
      line += sizeof(block);
      begin = current;
    }
    t = -1;
  }
  if (t < 0) {
    block = explode(s[begin..],"\n");
    block[0] = head + block[0];
    t = find_lfun_pos(block, lfun);
  }
  if (t>=0) {
    line += t;
    if (t)
      begin = begin+strlen(implode(block[0..t-1],"\n"))+1-strlen(head);
    end = strstr(s, "\n", begin);
    if (end >= 0 && one_line_function(lookoutput = s[begin..end]))
      return line;
    end = strstr(s, "\n}", begin);
    if (end >= 0)
      end = strstr(s, "\n", end+2);
    if (end >= 0)
      lookoutput = s[begin..end];
    else
      lookoutput = s[begin..];
    return line;
  }
  return 0;
}

static int Lookup(string str) {
  mixed *tmp;
  string lfun, file;
  object target;
  int line;

  switch (match_arguments(str, ({({ "object",  "command" }),
                                 ({ "command", "object"  }),
                                 ({ "object",  "string"  }),
                                 ({ "string",  "object"  }),
                               }))) {
    case  1: tmp = get_actions (argv[0], argv[1], 0);
             target = tmp[1];
             lfun = tmp[2];
             break;
    case  2: tmp = get_actions (argv[1], argv[0], 0);
             target = tmp[1];
             lfun = tmp[2];
             break;
    case  3: target = argv[0];
             lfun = argv[1];
             break;
    case  4: target = argv[1];
             lfun = argv[0];
             break;
    default: FAIL("Usage: Lookup <object> <lfun>\n"
                  "       Lookup <object> <command>");
  }

  if (!(file = find_function(lfun, target)))
    FAIL("There is no lfun "+lfun+"() within object "+DA(target)+"!");
  else
    file = "/"+file+".c";

  if (!(line = lookup(file, lfun))) {
    log_file("Robe.rep", "Lfun "+lfun+"() not found in file "+file+"\n");
    FAIL("Weird. I cannot find the lfun "+lfun+"() within file "+file);
  }
  OUT("Lfun "+lfun+"() in file "+file+" (line "+line+"):");

  if (!pager) {
    OUT ("-----------------------------------------------------------------------------");
    PAGE(lookoutput);
  } else
   return Robe_shell("ed", file);
  return 1;
}

/*-------------------------------------------------------------------------*/

static int list_macros() {
  mixed tmp;
  string *keys,*args;
  int max, len, i;

  keys = m_indices (macros);
  if (!sizeof(keys))
    NOTIFY1("No macros defined.");
  HLINE("Defined macros:");
  keys = sort_array(keys,#'>);
  tmp  = allocate(sizeof(keys));
  FOREACH (keys,i) {
    if (args = macros[keys[i],0])
      tmp[i] = keys[i]+" "+implode(args," ");
    else
      tmp[i] = keys[i];
    if ((len = strlen(tmp[i])) > max)
      max = len;
  }
  FOREACH (keys,i)
    printf("%-"+max+"s :%s\n", tmp[i], macros[keys[i],1]);
  return 1;
}

static int Macro(string str) {
  mixed tmp;
  string substitute;
  int i;

  if (!str)
    return list_macros();

  tmp = explode(str,":") - ({""});
  switch (sizeof(tmp)) {
    case  1: if (!member(macros, str))
               FAIL("No such macro defined.");
             m_delete(macros, str);
             NOTIFY1("Macro '"+str+"' deleted.");
    case  2: break;
    default: tmp[1] = implode(tmp[1..],":");
  }

  substitute = tmp[1];
  tmp = explode(tmp[0]," ") - ({ "" });
  macros[tmp[0],1] = substitute;
  if (sizeof(tmp) > 1)
    macros[tmp[0],0] = tmp[1..];
  NOTIFY1("Macro '"+tmp[0]+"' defined.");
}

/*-------------------------------------------------------------------------*/

static int list_slots() {
  string *keys;
  int max, len, i;

  HLINE("Defined slots:");
  keys = sort_array (m_indices(slot), #'>);
  max  = 6;
  FOREACH(keys,i)
    if ((len = strlen(keys[i])) > max)
      max = len;
  FOREACH(keys,i)
    printf("%-"+max+"s : %s\n", keys[i], DA(slot[keys[i]]));
  printf("Marked : %s\n", DA(marked_slot));
  printf("Result : %s\n", DA(result_slot));
  return 1;
}

static int Mark(string str) {
  string item;
  mixed value;
  int i;

  if (!str)
    return list_slots();

  add_command_line(str,([]));
  while (item = next_token(0)) {
    if (item != "$" && item[0] == '$') {
      value = parse(0);
      slot[item] = value;
      OUT("Slot "+item+" : "+DA(value));
      continue;
    }
    while (member(slot, "$"+(++i)) && slot["$"+i])
      ;
    value = parse(item);
    slot["$"+i] = value;
    OUT("Slot $" + i + " : " + DA(value));
  }
  return 1;
}

/*-------------------------------------------------------------------------*/

#ifdef SHELL
static int More(string str) {
  return Robe_shell("more", str);
}
#endif

/*-------------------------------------------------------------------------*/

#ifndef NIRVLIB
static
#endif
int New() {
  object ob;

  if (!check_safety())
    return 0;
  ob = find_object(PROGRAM_NAME(this_object()));
  if (ob)
    DESTRUCT(ob);
  ob = clone_object(PROGRAM_NAME(this_object()));
  MOVE(ob, this_player());
  DESTRUCT(this_object());
  NOTIFY1("You now wear the newest Robe of Sorcery!");
}

/*-------------------------------------------------------------------------*/

static int Path() {
  int i;

  CENTER("Current Path");
  FOREACH(dir_array, i)
    printf("%2d: %s\n", i+1, dir_array[i]);
  NOTIFY1("");
}

/*-------------------------------------------------------------------------*/

static int list_preloads() {
  int i;
  mixed *out;

  if (!sizeof(preloads))
    OUT("No preloaded files.");
  BANNER("These files will automatically be preloaded:");
  out = sort_array (preloads, #'>);
  FOREACH(out,i)
    OUT(out[i]);
  if (use_message_macros)
    if (sizeof(preloads))
      OUT("Additionally, the macros of <message.h> are evaluated.");
    else
      OUT("Only the macros of <message.h> are evaluated.");
  return 1;
}

static int Preload(string str) {
  string entry;

  switch (match_arguments(str, ({({ "filename" })}))) {
    case 0:  return list_preloads();
    case 1:  entry = argv[0];
             break;
    default: FAIL("Usage: Preload [file]");
  }

  if (entry == "/sys/message.h") {
    use_message_macros = !use_message_macros;
    if (use_message_macros) {
      NOTIFY1("Evaluation of message macros is switched on.");
    } else {
      NOTIFY1("Evaluation of message macros is switched off.");
    }
  }

  if (member(preloads, entry) == -1) {
    preloads += ({ entry });
    NOTIFY1(entry+" added to the preload-list.");
  } else {
    preloads -= ({ entry });
    NOTIFY1(entry+" removed from the preload-list.");
  }
}

/*-------------------------------------------------------------------------*/

static int Remove(string str) {
  int pos;

  switch (match_arguments(str, ({({ "integer" }),
                                 ({ "directory" }),
                               }))) {
  case  0: FAIL("Remove which directory from the path?");
  case  1: pos = argv[0]-1;
           if (pos < 0 || pos >= sizeof(dir_array))
             FAIL("Illegal path entrynumber!");
           argv[0] = dir_array[pos];
           break;
  case  2: pos = member(dir_array, argv[0]);
           if (pos >= 0)
             break;
  default: FAIL("Usage: Remove <directory>\n"
                "       Remove <entrynumber>");
  }
  dir_array = dir_array - ({ argv[0] });
  NOTIFY1("Directory "+argv[0]+" removed.");
}

/*--------------------------------------------------------------------------*/

static int Restore(string str) {
  string file;

  switch (match_arguments(str, ({({ "playername" })}))) {
    case  0: file = expand_filename("~/.robe.o");
             break;
    case  1: file = expand_filename("~"+argv[0]+"/.robe.o");
             break;
    default: FAIL("Usage: Restore [player]");
  }
  if (file_size(file) > 0)
    operate_file(#'restore_object, file[0..<3]);
  set_light(lightlevel);
  if (query_verb() == "Restore")
    OUT("Robe setup loaded.");
  return 1;
}

/*--------------------------------------------------------------------------*/

#ifdef NIRVLIB

static int Review(string str) {
  int i, number;
  string pattern, out, logfile, tmp_log;
  mixed *tmp;

  switch (match_arguments(str, ({({ "string" }),                      // l
                                 ({ "string", "integer" }),           // l e
                                 ({ "string", "integer", "string" }), // l e p
                                 ({ "string", "string" }),            // l p
                                 ({ "string", "string", "integer" }), // l p e
                               }))) {
    case  1: number = 20;
             break;
    case  2: number = argv[1];
             break;
    case  3: number = argv[1];
             pattern = L(argv[2]);
             break;
    case  4: number = 20;
             pattern = L(argv[1]);
             break;
    case  5: number = argv[2];
             pattern = L(argv[1]);
             break;
    default: FAIL("Usage: Review logfile [#entries] [pattern]\n"
                  "       Review logfile [pattern] [#entries]");
  }

  logfile = argv[0];

  tmp_log = expand_filename(logfile);
  out = safe_read_file(tmp_log);

  if (!out &&                        // try /changelog/
      strstr(logfile, "/") == -1) {
    tmp_log = expand_filename("/changelog/"+upper_case(logfile));
    out = safe_read_file(tmp_log);
  }

  if (!out &&                        // try /syslog/
      strstr(logfile, "/") == -1) {
    tmp_log = expand_filename(SYSLOGDIR + upper_case(logfile));
    out = safe_read_file(tmp_log);
  }

  if (!out)
    FAIL("Error: Cannot find that logfile: " + logfile);

FAIL("Review is not fully implemented yet!");

  tmp = explode (out,"-----------------------------------------------------------------------------");
  if ((!tmp) || (!sizeof(tmp)))
    FAIL ("Error: Cannot read "+LOGFILE);
  out = "";

  for (i=sizeof(tmp)-1 ; i>=0 ; i--) {
    if ((pattern) && (strstr(L(tmp[i]),pattern) == -1))
      continue;
    out += "-----------------------------------------------------------------------------"
           +tmp[i];
    if (!--number)
      break;
  }

  if (out == "")
    NOTIFY1 ("No appropriate changelog entries found.");
  PAGE(out);
  return 1;
}

#endif

/*--------------------------------------------------------------------------*/

static int Runtime(string str) {
  mixed result,r1,r2;
  int st,ut;

  if (!str)
    NOTIFY1("What command do you want to time-check?");

  r1 = rusage();
  result = command(str, this_player());
  r2 = rusage();
  ut = r2[0] - r1[0];
  st = r2[1] - r1[1];
  OUT("The call required "+result+" time units.");
  NOTIFY1("Execution time was "+(st+ut)+" milliseconds (" + st +
         " system/"+ut+" user)");
}

/*--------------------------------------------------------------------------*/

static int Save() {
  operate_file(#'save_object, expand_filename("~/.robe"));
  NOTIFY1("Robe setup saved.");
}

/*--------------------------------------------------------------------------*/

static int Send(string str) {
  switch (match_arguments(str, ({({ "object" })}))) {
    case   1: mtarget = argv[0];
              break;
    default : FAIL ("Usage: Send <player>");
  }
  if (interactive(mtarget)) {
    OUT("Sending the following message to " +
        C(mtarget->query_real_name())+":");
    tell_object(mtarget, "Incoming message from " +
                C(this_player()->query_real_name())+":\n");
  } else {
    OUT("Sending the following message to " + dump_object (mtarget));
    tell_room(mtarget, "Incoming message from " +
                       C(this_player()->query_real_name())+":\n");
  }
  write("]");
  input_to("send_interactive");
  return 1;
}

static void send_interactive(string str) {
  if (!mtarget) {
    NOTIFY("Message finished.");
  }

  if (str == "**" ||  str == "." || str == "~q") {
    if (interactive(mtarget))
      tell_object(mtarget, "End of message.\n");
    else
      tell_room(mtarget, "End of message.\n");
    NOTIFY("Message finished.");
  }

  if (interactive(mtarget))
    tell_object(mtarget, "'"+str+"\n");
  else
    tell_room(mtarget, "'"+str+"\n", ({ this_player() }));

  write("]");
  input_to("send_interactive");
}

/*-------------------------------------------------------------------------*/

static int T(string str) {
  switch (match_arguments(str, ({({ "object" })}))) {
  case  0: if (marked_slot)
           argv = ({ marked_slot });
  case  1: if (living(argv[0]) && environment(argv[0]))
             return teleport_player(environment(argv[0]));
           else
            return teleport_player(argv[0]);
  default: FAIL("Usage: T <destination>");
  }
  NO_WARN_MISSING_RETURN;
}

/*-------------------------------------------------------------------------*/

#ifdef SHELL
static int Tail(string str) {
  return Robe_shell("tail", str);
}
#endif
  
/*-------------------------------------------------------------------------*/

static int Toggle(string str) {
  switch (match_arguments(str, ({({ "Pager" }),
                                 ({ "pager" }),
                                 ({ "Editor" }),
                                 ({ "editor" }),
                                 ({ "Prediction" }),
                                 ({ "prediction" }),
                               }))) {
  case 1:
  case 2:
    if (pager) {
      OUT("Output will be paged with 'more'.");
      pager = 0;
    } else {
      OUT("Output will be paged with 'ed'.");
      pager = 1;
    }
    return 1;
  case 3:
  case 4:
    if (editor) {
      OUT("Input will be processed directly.");
      editor = 0;
    } else {
      OUT("Input will be processed with 'ed'.");
      editor = 1;
    }
    return 1;
  case 5:
  case 6:
    if (prediction) {
      OUT("Symbol prediction deactivated.");
      prediction = 0;
    } else {
      OUT("Symbol prediction activated.");
      prediction = 1;
    }
    return 1;
  default:
    FAIL("Usage:  Toggle Pager\n"
         "        Toggle Editor\n"
         "        Toggle Prediction");
  }
  NO_WARN_MISSING_RETURN;
}

/*-------------------------------------------------------------------------*/

static int Trace(string str) {
  switch (match_arguments(str, ({({ "-level", "integer", "string" }),
                                 ({ "-prefix", "object", "string" }),
                                 ({ "integer" }),
                                 ({ "none" }),
                                 ({ "object" }),
                               }))) {
  case 1: tracelevel = argv[1];
          str = argv[2];
          break;
  case 2: tprefix = object_name(argv[1]);
          str = argv[2];
          break;
  case 3: tracelevel = argv[0];
  case 0: trace(0);
          if (tprefix)
            OUT("Traceprefix is "+DA(tprefix));
          NOTIFY1("Tracelevel is set to "+ tracelevel + ".");
  case 4: tprefix = 0;
          NOTIFY1("Traceprefix deleted.");
  case 5: tprefix = object_name(argv[0]);
          NOTIFY1("Traceprefix is set to "+DA(tprefix));
  }
  traceprefix(tprefix);
  trace(tracelevel);
  command(str, this_player());
  trace(0);
  traceprefix(0);
  return 1;
}

/*-------------------------------------------------------------------------*/

private int test_for_include_update(object o) {
  mixed *list;
  int i, t;
  list = include_list(o);
  t = program_time(o);
  for (i = 7; i < sizeof(list); i = i+3) {  // ignore first 2 entries (autoinc)
    if (file_time("/"+list[i]) > t)
      return 1;
  }
  return 0;
}

private mixed* get_deep_update_list(mixed parent, mixed *list, int u) {
  int i, mu, pu;  // pu: parent needs update; mu: first entry needs update
  object ob, p;

  for (i = sizeof(list); i-->0; ) {
    if (pointerp(list[i])) {
      list[i..i] = ({ get_deep_update_list(list[0], list[i], &u), u });
    }
    else {
      if (!(ob = find_object(list[i])))
        catch((ob = load_object(list[i])); nolog);
      if (stringp(parent))
        p = find_object(parent);
      if (p && (program_time(p) <= program_time(ob)))
        pu = 1;
      list[i..i] = ({ list[i],
                      !ob ||
                      file_time("/"+list[i]) >= program_time(ob) ||
                      test_for_include_update(ob),
                   });
    }
  }
  mu = 0;
  for (i = sizeof(list); i > 0; i = i-2) {
    if (list[i-1]) {
      list[1] = 1;  // mu-field of first entry
      mu = 1;
      break;
    }
  }
  u = mu || pu;
  return list;
}

static object* deep_update(object arg) {
  mixed *list_tree, *list_flat, tmp, *inh_list;
  int i, node_moved;

  inh_list = inherit_list(arg, INHLIST_TREE);

  if (sizeof(inh_list) && inh_list[0] != (load_name(arg) + ".c")) // because of
    inh_list = ({ load_name(arg) + ".c", inh_list });      // replace_program()

  list_tree = get_deep_update_list(arg, inh_list, &i);
  // now bring the update-list tree structure in the order of inherit_list()
  // output, and already filtering of the need-to-updated files
  list_flat = ({ });
  do {
    for (i = 0; i < sizeof(list_tree); i = i+2) {
      if (pointerp(list_tree[i])) {
        if (list_tree[i+1] == 0 ||      // nothing to update or
            list_tree[i][1] == 0) {     // first entry not needed to update
          list_tree[i..i+1] = ({ });    // cut the whole tree-part
          i = i-2;
          continue;
        }
        list_tree[i..i-1] = list_tree[i][0..1]; // otherwise: move the first
        list_tree[i+2][0..1] = ({ });   // entry to the parent list where it
        node_moved = 1;                 // belongs as it's inheritted by the
      }                                 // first object of the parent list
      if (stringp(list_tree[i])) {
        if (list_tree[i+1] == 1)                // filter particular items
          list_flat = ({ list_tree[i] }) + list_flat;   // if update needed
        list_tree[i..i+1] = ({ });              // otherwise: cut them
        if (!node_moved)
          i = i-2;
        node_moved = 0;
      }
    }
    if (sizeof(list_tree)) {            // in list_tree only arrays are left,
      tmp = list_tree[0];               // concatenate them
      for (i = 2; i < sizeof(list_tree); i = i+2)
        tmp += list_tree[i];
      list_tree = tmp;
    }
  } while (sizeof(list_tree));          // continue until list_tree is empty
  list_flat = map(list_flat, #'find_object) - ({ 0 });
  return list_flat;
}

static int Update(string str) {
  object *arr,ob,env, *inv;
  string name, error, fn, on;
  int i;

  // TODO: filename, directory
  switch (match_arguments(str, ({({ "object" })}))) {
  case 0:
    argv = ({ environment(this_player()) });
  case 1:
    if (object_name(argv[0]) == VOID)
      NOTIFY1("It's unwise to update the void!");
    if (query_once_interactive(argv[0]))
      NOTIFY1("Don't update players!");
    if (argv[0] == this_object())
      return New();
    if (member(inherit_list(argv[0]), "basic/populate.c") > -1)
      argv[0]->destruct_population();
    inv  = all_inventory(argv[0]);
    env  = environment(argv[0]);
    name = load_name(argv[0]);
    error = 0;
    FOREACH(inv, i)
      MOVE(inv[i], VOID);
    arr = deep_update(argv[0]);
    FOREACH(arr,i)
      if (arr[i] && !error) {
        fn = load_name(arr[i]);
        on = DA(arr[i]);
        DESTRUCT(arr[i]);
        error = catch(load_object(fn); nolog);
        if (error) {
          OUT(on + " destructed.");
          OUT("Reloading of " + fn + " failed.");
          OUT("Update stopped.");
          OUT("Reason: " + error);
        } else {
          OUT(on + " updated.");
        }
      }
    if (clonep(argv[0])) {
      DESTRUCT(argv[0]);
      ob = clone_object(name);
    } else {
      DESTRUCT(argv[0]);
      ob = load_object(name);
    }
    if (env)
      MOVE(ob, env);
    inv -= ({ 0 });
    FOREACH(inv, i)
      MOVE(inv[i],ob);
    NOTIFY1(DA(ob)+" has been remade.");
    break;
  }
  // default:
  FAIL("Usage: Update <object>");
}

/*-------------------------------------------------------------------------*/

static void list_shadows(object *ob) {
  mixed *arr;
  int i,j;

  if (!ob) {
    ob = m_indices(shadows);
    if (sizeof(ob))
      HLINE("You are watching the following calls:")
    else
      NOTIFY("You aren't watching any calls right now.");
  }
  FOREACH(ob,i) {
    arr = shadows[ob[i],1];
    FOREACH(arr,j)
      OUT(dump_argument(ob[i],0)+"->"+arr[j]+"()");
  }
  return;
}

static void remove_shadow(object ob, int quiet) {
  object sh;

  sh = shadows[ob,0];
  m_delete(shadows,ob);
  if (sh && objectp(sh))
    DESTRUCT(sh);
  else if (!quiet)
    NOTIFY("You didn't watch "+DA(ob)+" yet.");
  if (!quiet)
    OUT("You don't watch "+DA(ob)+" anymore.");
  return;
}

static int Watch(string str) {
  mixed tmp;
  int i,parcount;

  switch (match_arguments(str, ({({ "object" }),
                                 ({ "object", "stringlist" }),
                               }))) {
  case  0: list_shadows(0);
           return 1;
  case  1: remove_shadow(argv[0],0);
           return 1;
  case  2: break;
  default: FAIL ("Usage: Watch <object> <lfun1> <lfun2> ...");
  }

  FOREACH(argv[1],i) {
  if (!function_exists(argv[1][i], argv[0])) {
    OUT("No function "+argv[1][i]+"() in "+DA(argv[0]));
    argv[1][i] = 0;
  }
  if (argv[1][i] == "reset")
    NOTIFY1("Sorry, but due to technical reasons this is"+
           " impossible.\nPlease use Deepwatch instead.");
  }
  argv[1] -= ({ 0 });
  if (!sizeof(argv[1]))
    return 1;

  if (tmp = shadows[argv[0],1])
    argv[1] = make_unique_array(argv[1]+tmp);

  remove_shadow(argv[0],1);

  tmp = "mixed r_w_r,r_w_c;\nobject r_w_t,r_w_n;\n"
        "activate_robe_watch(ob)\n{\n\tr_w_t = ob;\n\t"
        "r_w_n = previous_object();\n\t"
        "return shadow (ob,1);\n}\n";
  FOREACH (argv[1],i) {
    parcount = parameter_number(argv[0],argv[1][i]);
    tmp += argv[1][i]+"(" + add_varlist (parcount)
         + ")\n{\n\tr_w_c = catch(r_w_r = r_w_t->"
         + argv[1][i]+"(" + add_varlist (parcount)
         + "));\n\tif (r_w_n)\n\t\tr_w_n->"
         + "collect_watch_results(({ r_w_t,\""
         + argv[1][i]+"\","+"r_w_r,r_w_c,"+add_varlist(parcount)
         + "}) );\n\telse\n\t\tdestruct(this_object());\n\t"
         + "return r_w_r;\n}\n";
  }

  operate_file(#'rm, WORKFILE);
  if (!operate_file(#'write_file, ({ WORKFILE, tmp })))
    NOTIFY1("Couldn't write the shadow file!");
  if (tmp = find_object(WORKFILE))
    DESTRUCT(tmp);
  tmp = clone_object(WORKFILE);
  if (!tmp->activate_robe_watch(argv[0])) {
    remove_shadow(argv[0],1);
    NOTIFY1("Sorry, but you don't have the permissions to watch "+DA(argv[0]));
  }
  shadows[argv[0],0] = tmp;
  shadows[argv[0],1] = argv[1];
  list_shadows(({ argv[0] }));
  return 1;
}

/*-------------------------------------------------------------------------*/

string short() {
  return "Robe of sorcery";
}

string long(string str) {
  return 
    "A simple grey robe.\n" + 
    (this_player() == environment(this_object()) ? 
     "You feel that the robe's magic can 'Help' you a lot.\n" : "");
}

int id(string str) {
  return L(str) == "robe";
}

int get() {
  if (!wizard_check(this_player())) {
    OUT("When you reach out for the robe, it dissolves.");
    DESTRUCT(this_object());
    return 0;
  }
  return 1;
}

int drop(int silently) {
  if (!silently) {
    if (query_verb()=="drop")
      NOTIFY1("You cannot drop the Robe of Sorcery!");
    if (query_verb()=="give")
      NOTIFY1("You cannot give away the Robe of Sorcery!");
  }
  return 1;
}

string query_auto_load() {
  return PROGRAM_NAME(this_object())[0..<3] + ":";
}

/*-------------------------------------------------------------------------*/

void create() {
  mixed priv;
  if (this_player() && interactive(this_player()))
    priv = get_privilege(this_player());
  else
    priv = get_privilege(previous_object());
  if (check_previous_privilege(priv))
    set_privilege(priv);

  command_array = ({
    "Actions",
    "Add",
    "Call",
#ifdef SHELL
    "Cat",
    "Cd",
#endif
#if 0
    "Changed",
#endif
    "Check",
    "Clean",
#ifdef SHELL
    "Clone",
#endif
    "Deepwatch",
#ifdef SHELL
    "Ed",
#endif
#ifdef NIRVLIB
    "Error",
    "Expect",
#endif
    "Flush",
    "Functions",
    "Help",
    "Last",
    "Light",
    "List",
    "Load",
    "Loaddef",
    "Log",
    "Lookup",
    "Macro",
    "Mark",
#ifdef SHELL
    "More",
#endif
    "Path",
    "Preload",
    "Remove",
    "Restore",
#ifdef NIRVLIB
    "Review",
#endif
    "Runtime",
    "Save",
    "Send",
    "T",
#ifdef SHELL
    "Tail",
#endif
    "Toggle",
    "Trace",
    "Update",
    "Watch",
  });

  help_array = ({
    "Arguments",
    "Arrays",
    "Mappings",
    "Slots",
    "Userpath",
  });

  info_array = ({
({
"Actions <object> [command]\nActions <object> [object]",
"Gibt die Befehle aus, die derzeit fuer das gegebene\n\
<object> definiert sind. Zu den Befehlen werden die mittels\n\
add_action() definierten Objekte und Funktionen ausgegeben.\n\n\
Wurde zusaetzlich noch ein <command> angegeben, werden\n\
die beteiligten Objekte/Funktionen in der korrekten Auswer-\n\
tungsreihenfolge ausgegeben. Wird stattdessen ein weiteres\n\
[object] angegeben, wird nur ausgegeben, welche Befehle von\n\
ihm definiert werden.",
"Prints those commands which have been defined for the given\n\
Object. Along with it the objects and functions defined by\n\
add_action() are printed.\n\n\
If a [command] is specified, the corresponding command handlers\n\
are printed in the correct order of execution. If a second\n\
[object] is given as an argument, only the handlers defined by\n\
it are listed.",
"Actions /room/adv_guild\n\
Actions #3 get\n\
Actions rumplemintz robe",
"Arguments, Arrays, Functions, Lookup.\n",
}),
({
"Add [directory] <no>",
"Addiert das angegebene [directory] zum Userpath.\n\
Es wird an der Position <no> eingefuegt. Wenn keine\n\
Position <no> spezifiziert wird, wird das Directory\n\
an das Ende des Userpaths gesetzt.",
"Adds the given [directory] to the userpath. By\n\
default it is added as the last entry, if you specify\n\
a <no>, the [directory] will be added at this position.",
"Add /basic 2\n\
Add ~/monsters",
"Path, Remove, Userpath."
}),
({
"Call <object> [lfun] <arg1> <arg2> ...\nCall [efun] <arg1> <arg2> ...",
"Im ersten Fall wird die gewaehlte [lfun] mit den\n\
angegebenen <args> aufgerufen. Wird auf die Angabe\n\
des <object> verzichtet, wird das zuletzt markierte\n\
Objekt als default gewaehlt. Im zweiten Fall wird\n\
die [efun] natuerlich ohne <object> aufgerufen.\n\
Um Versehen vorzubeugen, druckt die Robe bei jedem\n\
Aufruf zur Kontrolle noch einmal aus, welchen Aufruf\n\
genau sie denn gerade ausgewertet hat. Es ist sehr zu\n\
empfehlen, immer einen kurzen Kontrollblick zu machen.",
"In the former case the chosen [lfun] will be called\n\
with the specified <args>. If <object> is omitted, the\n\
most recently marked object will be chosen as default.\n\
In the latter case the [efun] will be called with the\n\
given <args>. Of course no <object> would make sense here.\n\
To avoid misunderstandings, the Robe prints out exactly\n\
what it has been evaluating. It is highly advisable to\n\
_always_ check if something has been misinterpreted.",
"Help Examples\n\
Call robe dump_argument ({ ([key:value]) *me ({ #3 }) })\n\
Call set_title \"the \\\"lazy\\\" mage\"\n\
Call transfer *demos /room/prison",
"Arguments, Arrays, Efuns, Interactive, Mappings, Slots, Mark."
}),
#ifdef SHELL
({
"Cat <argument>",
"Gibt die ersten Zeilen der angegebenen Datei aus.\n\
Genaueres ueber die zulaessigen Argumente findet\n\
man unter \"Arguments\" und \"Userpath\".",
"Prints the first lines of the given file.\n\
You can find additional informations about valid\n\
<argument>s in \"Arguments\",\"Slots\" and \"Userpath\".",
"Cat bag\n\
Cat here\n\
Cat #4",
"Arguments, More, Slots, Tail, Userpath.\n"
}),
({
"Cd [argument]",
"Ist [argument] ein Pfad, wechselt die Robe auf das\n\
angegebene Directory. Ist [argument] ein Objekt, so\n\
wird in das Directory gewechselt, in dem dessen Code\n\
steht. Wird als [argument] eine Zahl angegeben, wechselt\n\
die Robe in das Directory der entsprechenden Stelle im\n\
Userpath.",
"If [argument] is a path, the Robe changes to the\n\
specified directory. If [argument] is an object, the\n\
directory containing the object's code will be used.\n\
If [argument] is an integer, the given entry in the\n\
Userpath will be taken.",
"Cd ~/directory\n\
Cd here\n\
Cd $3\n\
Cd 2",
"Add, Arguments, Path, Remove, Slots, Userpath.\n"
}),
#endif
#if 0
({
"Changed [file1 file2 ...]",
"Mit dieser Funktion wird fuer die angegebenen\n\
Dateien ein Logfile-Eintrag erstellt. Mittels ed\n\
kann der Wizard die durchgefuehrten Aenderungen\n\
beschreiben.",
"With this command the given files are stored\n\
in a logfile. Using ed, the wizard can describe\n\
all changes made.",
"Changed /kernel/master.c\n\
Changed here /obj/torch #1",
"Arguments, Ed.\n",
}),
#endif
({
"Check [argument]",
"Liefert einige nuetzliche Informationen ueber das\n\
gegebene [argument].",
"Prints some useful informations about the specified\n\
[argument].",
"Check me\n\
Check /room/adv_guild\n\
Check $1",
"Arguments.\n",
}),
({
"Clean [argument]",
"Destructed alle Objekte im angegebenen [argument],\n\
solange es keine Spieler sind. Der Befehl rekursiert\n\
ueber die Inventories der destructeten Objekte. Wird\n\
kein [argument] angegeben, wird das Environment des\n\
Spielers geraeumt.\n\n\
Freundliche Warnung: Andere Spieler, Wizards und\n\
insbesondere Archwizards koennen ziemlich humorlos\n\
werden, wenn mit diesem Befehl unvorsichtig umgegangen\n\
wird. Ein froehliches \"Clean rumplemintz\" z.B. ist genauso\n\
witzig wie ein probates Mittel, um sich auesserst\n\
unangenehme Gespraeche einzuhandeln.",
"Destructs all objects inside of [argument] as long\n\
as they aren't players. It also destructs the inventories\n\
of the objects recursively. If no [argument] is specified,\n\
the environment of the wizard is cleaned up.\n\n\
Friendly advice: Other players, wizards and especially\n\
archwizards tend to become very unpleasant if this\n\
command is abused. A good-natured \"Clean rumplemintz\" is\n\
just as cool and entertaining as it is a foolproof\n\
method to have a nasty talk with him.",
"Clean\n\
Clean #3",
"Arguments, List, Update.\n"
}),
#ifdef SHELL
({
"Clone [argument]",
"Cloned das mit [argument] bezeichnete Objekt.\n\
Genaueres ueber die zulaessigen Argumente findet\n\
man unter \"Arguments\".",
"Clones the specified [argument]. Additional\n\
informations about valid [argument]s can be found\n\
in \"Arguments\", \"Slots\" and \"Userpath\".",
"Clone torch\n\
Clone rumplemintz:#2\n\
Clone $3",
"Arguments, Clean, Update.\n"
}),
#endif
({
"Deepwatch [object] <lfun1> <lfun2> ...",
"Arbeitet wie 'Watch' (siehe dort), bis auf folgende\n\
Unterschiede:\n\n\
o Deepwatch faengt ALLE Aufrufe der <lfuns> ab, auch lokale.\n\
o Deepwatch ist destruktiv. Bei der Benutzung wird das [object]\n\
  destructed und in einer debug-version neu geladen. Dabei\n\
  verliert das Objekt seine Variableninhalte.\n\
o Bei der Benutzung geht das blueprint des [object] verloren.\n\n\
WARNUNG: Deepwatch darf nur dann auf im Spiel befindliche Objekte\n\
         angewendet werden, wenn Du _GENAU_ weisst, was Du tust!",
"Works like 'Watch' (see there) except for the following points:\n\n\
o Deepwatch catches _all_ <lfun>-calls, including local ones.\n\
o Deepwatch is destructive. When used, the [object] will be\n\
  destructed and reloaded in a debug-version. Therefore it\n\
  loses all contents of variables.\n\
o The blueprint of the given [object] gets lost.\n\n\
CAUTION: Deepwatch may only be used on game-objects, if you\n\
         know _EXACTLY_ what you are doing!",
"Deepwatch here short query_exit\n\
Deepwatch $3\n\
Deepwatch",
"Arguments, Watch.\n"
}),
#ifdef SHELL
({
"Ed <argument>",
"Ruft \"ed\" auf das File des angegebenen\n\
<argument> auf. Wird auf die Angabe von \n\
<argument> verzichtet, wird das File des\n\
zuletzt markierten Objektes editiert.",
"Invokes \"ed\" on the file of the given\n\
<argument>. If <argument> is omitted, the\n\
file of the most recently marked object will\n\
be edited.",
"Ed here\n\
Ed $4\n\
Ed amulet\n\
Ed",
"Arguments, Cat, More, Tail, Userpath.\n"
}),
#endif
#ifdef NIRVLIB
({
"Error <wizard>",
"Listet das Error-Logfile des bezeichneten <wizard>\n\
auf. Wird auf die Angabe von <wizard> verzichtet,\n\
wird das eigene Logfile ausgegeben und zusaetzlich\n\
eine Leerzeile an diese Datei angehaengt. Dadurch\n\
soll klar ersichtlich gemacht werden, welche Fehler\n\
seit dem letzten Aufruf von \"Error\" dazugekommen sind.\n\n\
Hinweis: In diesem Logfile finden sich nur Fehler, die\n\
unmittelbar beim Laden oder Clonen eines Objektes\n\
aufgetreten sind. (also KEINE Laufzeitfehler !)",
"Lists the error-logfile of the given <wizard>.\n\
If <wizard> is omitted, the wizard's own logfile\n\
will be printed and a marker line will be appended.\n\
This way you can keep track of those errors, which\n\
occur between two consecutive calls.\n\n\
(Keep in mind that the logfile only contains errors\n\
which occur during compile time (NO run time errors).",
"Error\n\
Error rumplemintz",
"Log.\n"
}),
#endif
#if 0
({
"Eval <expression>",
"Weil mich eine Vielzahl von Leuten mit enormer Ausdauer\n\
belagert haben, doch endlich eine Eval-Funktion einzubauen,\n\
hab ich mich zaehneknirschend dazu durchgerungen. Mir\n\
persoenlich missfaellt das ganze Konzept, da mir keine\n\
saubere Definition fuer Eval eingefallen ist. Es wird nur\n\
so von Bugs wimmeln, aber ihr wolltet es ja so ... (rumplemintz)\n\n\
Eval versucht, eine angegebene LPC-<expression> moeglichst\n\
praezise zu evaluieren. Wird auf <expression> verzichtet,\n\
wird ein Modus wie bei Board-Notes gestartet. Will man\n\
Robe-Argumente wie Slots ($) und Indizes (#) verwenden,\n\
MUSS man sie beidseitig mit Spaces abtrennen (s.u.)",
"Since alot of wizards have pestered me with unbelievable\n\
tenacity, I finally gave in and added this Eval-command\n\
against better judgement. I thoroughly dislike the concept\n\
since no straightforward definition for Eval came to my\n\
mind. It will be full of bugs, but it wasn't MY idea. Heed\n\
my advice use Call instead whenever possible. (rumplemintz)\n\n\
Eval tries to compute the given LPC-<expression> correctly.\n\
If <expression> is omitted, you can write multiline commands\n\
just the way you write mails. You can use slots ($) and\n\
indices (#) as usual, but you MUST seperate them with Spaces\n\
from the rest of the code (see below).",
"Eval \"/lib/language\"->plural_word(\"foot\")\n\
Eval *me ->normalize_path( $path )\n\
Eval",
"Arguments, Call, List, Mark, Slots."
}),
#endif
#ifdef NIRVLIB
({
"Expect <player>",
"Expect ist ein kleiner Notifier, mit dem man auf\n\
bestimmte Spieler warten kann. Wenn der besagte <player>\n\
ins Mud kommt, gibt die Robe eine Meldung aus.\n\
Wurde <player> bei der Eingabe des Befehls erwartet,\n\
wird er/sie aus der Liste der erwarteten Spieler geloescht.\n\
Wird auf die Angabe von <player> verzichtet, wird\n\
die Liste aller derzeit erwarteten Spieler gezeigt.\n\n\
Die Liste der erwarteten Spieler kann auch gespeichert\n\
werden. Siehe unter \"Save\".",
"Expect is a small notifier, which waits for special\n\
players to log in. Whenever the given <player> enters\n\
the mud, the Robe will notify you. If the <player> has\n\
already been expected, he will be deleted from the list\n\
of expected players. If <player> is omitted, the actual\n\
list will be printed. Note also that you can \"Save\" the\n\
settings.", 
"Expect rumplemintz\n\
Expect",
"Last, Restore, Save.\n"
}),
#endif
({
"Flush [slot]",
"Loescht den angegebenen Slot aus dem Speicher.\n\
Wird auf die Angabe von [slot] verzichtet, wird\n\
kategorisch der GESAMTE Slot-Speicher geloescht.",
"Flushes the given [slot]. If [slot] is omitted,\n\
the WHOLE slot memory will be erased. Caution!",
"Flush",
"Slots.\n"
}),
({
"Functions <argument> [pattern]",
"Ist sehr nuetzlich, wenn man nach Funktionen eines Objektes\n\
sucht, die einen bestimmten Begriff (wie z.B. \"title\")\n\
betreffen. Genauso einfach lassen sich alle set_ und\n\
query_funktionen und aehnliche Konsorten herausfinden.\n\
Wird ein [pattern] angegeben, werden nur die Funktionen\n\
gelistet, die [pattern] beinhalten, andernfalls werden alle\n\
Funktionen ausgegeben. Zusaetzlich zu den Funktionen selbst\n\
wird ausgedruckt, in welchem File sie definiert sind (nuetzlich\n\
fuer multiple inheritance).\n\n\
Hinweis: Als \"private\" deklarierte Funktionen kann die\n\
Robe aus technischen Gruenden nicht immer exakt aufloesen.\n\
Daher listet sie alle in Betracht kommenden Files auf.",
"Very useful whenever you happen to look for an object's\n\
functions which relate to a special topic (like e.g. \"title\").\n\
Likewise you can extract all set_ and query_functions etc.\n\
If a [pattern] is specified, only the functionnames containing\n\
this pattern will be selected and printed, all functions will\n\
be listed otherwise. Additionally the Robe will compute, in\n\
which files the functions are defined (very useful whenever\n\
multiple inheritance is used).\n\n\
Note: If functions are declared \"private\", the Robe cannot\n\
resolve them exactly due to technical reasons. In this case\n\
the Robe lists all files in question.", 
"Functions me add_\n\
Functions -deep #7",
"Actions, Lookup."
}),
({
"Help <topic>\nHelp English\n\Help Deutsch",
"Help English/Deutsch schaltet die Sprache der\n\
Hilfstexte um. Der Rest ist selbsterklaerend.",
"Help English/Deutsch toggles the language\n\
od the helpfiles. The rest is selfexplanatory.",
"Help Introduction\n\
Help",
0
}),
({
"Last <player>",
"Gibt aus, wann <player> zum letzten Mal im Mud\n\
Gewesen ist. Wenn kein <player> angegeben wurde,\n\
wird angezeigt, welche Spieler zuletzt ins Mud\n\
gekommen sind.",
"Prints the last login-date of the given <player>.\n\
If <player> is omitted, the last lines of /log/ENTER\n\
are listed.",
"Last rumplemintz\n\
Last",
0
}),
({
"Light <level>",
"Setzt die Robe auf Lightlevel <level>. Damit kann\n\
sie Licht ausstrahlen (wie eine Fackel), aber auch\n\
absorbieren (wenn level negativ ist). Wird kein\n\
<level> angegeben, gibt die Robe Informationen ueber\n\
den Lightlevel des Raumes und der Robe aus.\n\n\
Der Lightlevel der Robe kann gespeichert werden.\n\
Siehe dazu \"Save\".",
"Illuminates the Robe with light level <level>. This\n\
way she can resemble a light source (like a torch), but\n\
it can absorb light aswell (if <level> is negative).\n\
If <level> is omitted, the Robe prints informations\n\
about its and the current room's light level. Note that\n\
the light level can be \"Save\"d.",
"Light 1000\n\
Light",
0
}),
({
"List [argument]",
"Listet das Inventory des [argument] auf. Alle Objekte\n\
werden mit Indizes (#) versehen und abgespeichert.\n\
Bis zum naechsten Aufruf von \"List\" bleiben alle\n\
Eintraege erhalten. Wird kein [argument] angegeben,\n\
wird das zuletzt markierte Objekt gelistet.\n\n\
Hinweis: Die Mehrfachschritt-Syntax comm1:comm2:comm3\n\
zerstoert die Indexliste und belegt die Indizes neu.\n\
Vorsicht ist daher geboten.",
"Lists up the inventory of [argument]. All objects\n\
are given indices (#) and saved. The indices remain\n\
fixed till the next call of \"List\". If [argument] is\n\
omitted, the inventory of the most recently marked\n\
object is used.\n\n\
Note: The multicall-syntax comm1:comm2 destroys and\n\
renumbers the indices prematurely. Caution.",
"List me\n\
List -noshort here\n\
List #1",
"Arguments, Arrays, Flush, Mark, Slots."
}),
({
"Load <object/file/directory> [-r]",
"Laden eines files (*.c) bzw. aller Files eines Verzeichnisses.\n\
Die rekursive Option (-r) wird derzeit noch nicht unterstuetzt.",
"Loading of a file (*.c) or of all files of a directory.\n\
The recursive loading (option -r) is not supported yet.",
"Load \"/room/church\"\n\
Load /players/examples/obj",
""
}),
({
"Loaddef <object/file>",
"Die Robe versucht, per #define deklarierte Symbole eines\n\
Objekts oder Files einzulesen und fuer die Nutzung innerhalb\n\
der Robe verfuegbar zu machen. Leider kann ein fehlerfreies\n\
Verhalten nicht garantiert werden, und Macros und besonders\n\
komplexe Konstrukte koennen aufgrund der Praefixnotation der\n\
Robe leider gar nicht unterstuetzt werden.",
"The Robe tries to read all symbols #defined within the given\n\
object or file, and to provide them for further use. Unfortu-\n\
nately, a flawless execution cannot be guaranteed due to tech-\n\
nical reasons, and macros cannot be supported at all due to\n\
their prefix notation.",
"Loaddef here\n\
Loaddef /sys/lpctypes.h\n\
Loaddef $3",
"Preload"
}),
({
"Log [file] [#lines]",
"Ohne Angabe von <file> werden die letzten Zeilen des\n\
Error-Logfile des Muds ausgegeben. Hier finden sich\n\
(im Gegensatz zu \"Error\") auch Laufzeitfehler, allerdings\n\
auch die Fehler anderer Wizards. Es ist eine gute Idee, nach\n\
dem Auftreten von Laufzeitfehlern erst mal dort nach\n\
Informationen zu forschen.\n\n\
Wird ein <file> angegeben, wird zuerst nach syslog/<file>, dann \n\
nach log/<file> gesucht (case sensitiv!), und die letzten Zeilen\n\
des zuerst gefundenen Files ausgedruckt.",
"If <file> is omitted, the last lines of the mud's general\n\
error-logfile are listed. Contrary to \"Error\", this logfile\n\
also contains runtime errors. On the other hand, all errors\n\
are listed here, including those of other wizards. Nevertheless\n\
it's quite a good idea to have a look at it whenever a runtime\n\
error occurs. You will find valuable informations there.\n\n\
If a <file> is specified, it is looked for in syslog/<file> \n\
resp. log/<file> (case sensitive!), and the last lines are \n\
printed.",
"Log\n\
Log QUESTS\n\
Log room.rep",
"Error, Review.\n"
}),
({
"Lookup <object> <lfun/command>",
"Lookup versucht, den Code einer gesuchten Funktion oder\n\
eines gesuchten Kommandos ausfindig zu machen und aufzulisten.\n\
Kommandos werden mit einem nachgestellten \"!\" gekennzeichnet.\n\n\
WARNUNG: Obwohl Lookup relativ zuverlaessig arbeitet, kann es\n\
dennoch zu Misserfolgen kommen. Weiterhin sollte dieser\n\
Befehl NICHT UNNOETIG verwendet werden, weil er ziemlich viel\n\
Rechenzeit kostet und Lags verursachen kann!",
"Lookup tries to extract and list up the code of a given function\n\
or command. Commands are being distinguished by a trailing \"!\".\n\n\
WARNING: Though Lookup is more or less reliable, it can fail\n\
under special circumstances. Furthermore this command shouldn't be used\n\
without reason, since it requires alot of cpu time and can cause\n\
considerable lags.",
"Lookup here reset\n\
Lookup me wimpy!\n\
Lookup $4 short",
"Arguments, Arrays, Slots, More."
}),
({
"Macro <name> [arg1] [arg2] ... : <substitute>",
"Dieser Befehl fungiert als Praeprozessor fuer die Robe. Man\n\
kann einem Makro <name> eine beliebige Anzahl von Argumenten\n\
mitgeben. Diese werden dann korrekt ins <substitute>-pattern\n\
expandiert. Man kann mittels \"@\" auch eine variable Anzahl\n\
von Argumenten beschreiben. In diesem Fall liest die Robe alle\n\
Argumente bis zum Ende des Calls oder Subcalls und expandiert\n\
sie en bloc. Die Robe kann eine beliebige Anzahl von Makros\n\
verwalten. Makros sind mittels \"Save\" speicherbar.",
"This command emulates a preprocessor for the Robe. You can\n\
define a macro <name> with a unlimited number of arguments. They\n\
will be expanded into the <substitute> body correctly. With \"@\"\n\
you can denominate a block of arguments of unknown length. In this\n\
case the Robe reads all arguments up to the end of the Call or\n\
subcall and expands them in one piece. The Robe can administer an\n\
unlimited number of macros. They can be stored with \"Save\".",
"Macro cwd : (/kernel/master normalize_path \".\" me)\n\
{ cwd }\n\
Macro !f_event x : ([\"target\":x \"location\":(environment x)])\n\
{ !f_event me }\n\
Macro swap x @ y : y @ x\n\
{ ({swap 1 2 3 4 5}) }\n\
Macro collect @  : /players/rumplemintz/server collect_args ({@})",
0
}),
({
"Mark <slot> [argument1] [argument2] ...",
"Uebersetzt die angegebenen [arguments] und speichert sie\n\
in den mit <slot> spezifizierten Slot. Wird <slot>\n\
nicht angegeben, wird beim ersten freien Slot begonnen.\n\
Wird \"Mark\" voellig ohne Argumente aufgerufen, gibt die\n\
Robe aus, welche Werte in welchen Slots markiert sind.\n\
Wenn man die Uebersetzung verzoegern will, kann man die\n\
Argumente mit ! beginnen lassen. Sie werden erst dann\n\
ausgewertet, wenn der Slot referenziert wird. Dies kann\n\
sogar rekursiv geschehen, aber Vorsicht (Endlosschleifen)",
"Translates the given [arguments] and stores them in the\n\
specified <slot>. If <slot> is omitted, the smallest unused\n\
numerical slot will be used. If \"Mark\" is called without\n\
arguments at all, the Robe prints a list with all slots and\n\
their contents/definitions. If you want to delay the translation\n\
of the slots, prepend a ! to the argument. They will be evaluated\n\
whenever the slot is referenced. Recursive definitions are\n\
supported, but you should avoid inifinite loops.",
"Mark *here /room/church me #2\n\
Mark $s \"this is a nice abbreviation for a long long string\"\n\
Mark $target !(me attacked_by)\n\
Mark $fightevent !([ ?:attack agent:*me target:$target ])\n\
Mark",
"Arguments, Arrays, Call, Flush, List, Slots.\n"
}),
#ifdef SHELL
({
"More [argument]",
"Gibt die angegebene Datei per \"more\" aus.\n\
Genaueres ueber die zulaessigen Argumente findet\n\
man unter \"Arguments\" und \"Userpath\".",
"Prints the specified file via \"more\". You can\n\
find more informations about valid [argument]s\n\
in \"Arguments\", \"Slots\" and \"Userpath\".",
"More bag\n\
More here\n\
More #4",
"Arguments, Arrays, Cat, Tail, Userpath."
}),
#endif
({
"Path",
"Gibt den aktuellen Userpath aus. Keine Argumente.",
"Prints the actual userpath. No arguments.",
"Path",
"Add, Remove, Userpath."
}),
({
"Preload [file]",
"Mittels Preload kann spezifiziert werden, welche\n\
[files] von der Robe beim Einloggen automatisch\n\
mittels \"Loaddef\" geladen werden. Preload ohne\n\
Argument liefert die aktuelle Preload-Liste, und\n\
die erneute Eingabe eines Files loescht den\n\
entsprechenden Eintrag wieder.",
"With Preload you can specify which [files] the\n\
robe will \"Loaddef\" initially. Preload without\n\
argument prints the list of given files, and\n\
if the [file] is already part of the list, it\n\
will be removed from it again.",
"Preload /sys/event.h\n\
Preload here\n\
Preload",
"Add, Loaddef, Remove, Userpath"
}),
({
"Remove [entry]",
"Loescht einen [entry] aus dem Userpath. Das Argument\n\
[entry] kann entweder die Nummer des zu loeschenden\n\
Directories im Userpath oder das Directory selbst sein.",
"Removes the specified [entry] from the userpath. The\n\
argument [entry] can be the corresponding number in the\n\
userpath or the directory itself.",
"Remove 2\n\
Remove /obj",
"Add, Path, Userpath."
}),
({
"Restore",
"Laedt die vorher mit \"Save\" abgespeicherten\n\
Einstellungen der Robe wieder ein. Wenn eine Robe\n\
gecloned wird, passiert das automatisch. Folgende\n\
Einstellungen sind speicher/ladbar:\n\n\
Der Lightlevel      (Light)\n\
Der Tracelevel      (Trace)\n\
Der Userpath        (Add, Path, Remove)\n\
Die Expect-Liste    (Expect)\n\
Die Sprache         (Help)",
"Restores the setup which has been \"Save\"d\n\
before. Whenever the Robe is cloned, this happens\n\
automatically. These values can be saved:\n\n\
The light level     (Light)\n\
The tracelevel      (Trace)\n\
The userpath        (Add, Path, Remove)\n\
The expect list     (Expect)\n\
The language        (Help)",
"Restore",
"Add, Expect, Light, Path, Remove, Userpath."
}),

#ifdef NIRVLIB
({
"Review [pattern] [#entries]",
"Mittels Review kann man die letzten Eintraege des\n\
Changelogs untersuchen. Wenn ein [pattern] angegeben\n\
wird, werden nur diejenigen Eintraege gelistet, die\n\
diesen Begriff erwaehnen. Mittels [#entries] wird\n\
spezifiziert, wie viele der letzten Eintraege\n\
angezeigt werden.",
"Review can be used to scan the latest changelog\n\
entries for a given [pattern]. The [#entries]\n\
arguments determines how many entries will actually\n\
be listed.",
"Review\n\
Review /kernel/master\n\
Review \"Mar 29\"\n\
Review rumplemintz\n\
Review here 3",
"Changed"
}),
#endif

({
"Runtime [command]",
"Mit diesem Befehl kann man sich anzeigen lassen, wieviel\n\
units ein Kommando zur Ausfuehrung braucht. Die units sind\n\
nur ein recht grobes Mass fuer den Zeitverbrauch, aber\n\
insgesamt dennoch nuetzlich, insbesondere wenn man versucht,\n\
wichtige Funktionen durch geschicktere Programmierung zu\n\
beschleunigen. So kann man mehrere Implementationen leicht\n\
vergleichen.",
"With this command you can evaluate how many time units the\n\
execution of a given [command] takes. The units are only\n\
a very rough estimate. Rusage is quite useful if you try to\n\
speed up applications, since you can easily compare their\n\
cpu consumption.",
"Runtime people\n\
Runtime Lookup reset me\n\
Runtime Call me query_title",
0
}),
({
"Save",
"Speichert die Einstellungen der Robe ab. Folgende\n\
Einstellungen werden abgespeichert:\n\n\
Der Lightlevel      (Light)\n\
Der Tracelevel      (Trace)\n\
Der Userpath        (Add, Path, Remove)\n\
Die Expect-Liste    (Expect)\n\
Die Macros          (Macro)\n\
Die Toggle-Liste    (Toggle)\n\
Die Preload-Liste   (Preload)",
"Saves the Robe's setup. The following\n\
values are stored:\n\n\
The light level     (Light)\n\
The tracelevel      (Trace)\n\
The userpath        (Add, Path, Remove)\n\
The expect list     (Expect)\n\
The language        (Help)\n\
The macro set       (Macro)\n\
The toggle list     (Toggle)\n\
The preload list    (Preload)",
"Save",
"Add, Expect, Light, Path, Remove, Userpath, Preload, Toggle."
}),
({
"Send [argument]",
"Schickt alle Eingaben ungefiltert zum angegebenen\n\
[argument]. Die Nachricht wird mit ** oder . beendet.",
"Sends the following input directly to the specified\n\
[argument]. The message can be terminated via '**' or '.'.",
"Send rumplemintz\n\
Send here\n\
Send $2",
0
}),
({
"T [argument]",
"Ein \"goto\" fuer Tippfaule. Im Gegensatz zu seinem\n\
Pendant verdaut \"T\" nicht nur Filenamen, sondern\n\
eine Vielzahl von Argumenten (siehe dort).",
"Another \"goto\" for lazy typists. \"T\" allows to\n\
use the regular Robe [argument]s, too.",
"T adv_guild\n\
T harry\n\
T $1",
"Arguments."
}),
#ifdef SHELL
({
"Tail [argument]",
"Gibt die letzten Zeilen der angegebenen Datei aus.\n\
Genaueres ueber die zulaessigen Argumente findet\n\
man unter \"Arguments\" und \"Userpath\".",
"Lists the last lines of the given [argument]'s\n\
file. You can get additional informations about\n\
them in \"Arguments\", \"Slots\" and \"Userpath\".",
"Tail bag\n\
Tail here\n\
Tail #4",
"Arguments, Arrays, Cat, More, Userpath."
}),
#endif
({
"Toggle",
"Erlaubt es, Einstellungen der Robe nach seinem Belieben\n\
anzupassen. Bisher wird unterstuetzt:\n\n\
Toggle Pager\n\
Toggle Editor\n\
Toggle Prediction",
"Allows the user to customize the behaviour of the Robe\n\
accordingly. Up to now these toggles are supported:\n\n\
Toggle Pager\n\
Toggle Editor\n\
Toggle Prediction",
"*ahemm*",
"Actions, Call, Functions, Lookup."
}),
({
"Trace [tracelevel] <command>\nTrace [object]",
"Mittels Trace kann man Informationen ueber den Ablauf\n\
von Funktionsaufrufen, die auf einen bestimmten <command>\n\
folgen. Wird kein <command> angegeben, wird der gegebene\n\
[tracelevel] gespeichert. Der gespeicherte [tracelevel]\n\
wird benutzt, wenn er nicht beim Aufruf angegeben wird.\n\
Wird [objekt] angegeben, wird der traceprefix darauf gesetzt.\n\
Der [tracelevel] ist die Summe folgender traceflags:\n\n\
1 : alle lfun-Aufrufe       16 : alle Stackmachinebefehle\n\
2 : alle call_other()       32 : alle heart_beat()s\n\
4 : alle Rueckgabewerte     64 : alle apply()s (Vorsicht!)\n\
8 : alle Aufrufparameter   128 : alle Objekte ausgeben",
"With Trace you can get additional informations about\n\
the execution chain of a given <command>. If <command>\n\
is omitted, the specified [tracelevel] will be stored.\n\
If [tracelevel] is omitted, the stored one will be used.\n\
If [object] is specified, it will become the traceprefix.\n\
The [tracelevel] is the sum of those traceflags:\n\n\
1 : all lfun calls           16 : all stackmachine instructions\n\
2 : all call_other() calls   32 : all heart_beat()s\n\
4 : all return values        64 : all apply()s (caution!)\n\
8 : all function parameters 128 : print object names",
"Trace grin\n\
Trace -level 15 grin\n\
Trace -prefix here grin     (traceprefix)\n\
Trace 15",
0
}),
({
"Update [argument]",
"Dieser Befehl destructed das [argument], updated es und\n\
laedt (bei Raeumen) oder cloned (bei Objekten) es neu.\n\
Danach wird das Inventory des destructeten [arguments] in\n\
das neue Objekt gemoved, das neue Objekt \"ersetzt\" das\n\
alte sozusagen. Wird kein [argument] angegeben, wird das\n\
Environment des Robe-Traegers bearbeitet. Update erkennt\n\
auch selbstaendig, wann Unterklassen neu geladen werden\n\
muessen und entspricht in dieser Hinsicht einem 'make'.\n\n\
Mit Hilfe dieses Befehls kann man z.B. problemlos Raeume\n\
updaten, ohne dass Spieler sie verlassen muessen. Will man\n\
doppelte Objekte vermeiden, muss vorher gegebenenfalls noch\n\
ein \"Clean\" abgesetzt werden.",
"This command destructs the [argument], updates its blueprint\n\
and reloads (rooms) or clones (objects) it. Afterwards the\n\
inventory of the destructed [argument] will be moved into\n\
the new one, the new object effectively replaces the old one.\n\
If [argument] is omitted, the environment of the wizard will\n\
be used. Update also takes care that subclasses are remade\n\
when necessary (multiple inheritance), in this respect it\n\
resembles a 'make'.\n\n\
With \"Update\" you can easily update rooms without having\n\
to leave them first. To avoid doubling the interior, you\n\
may have to \"Clean\" the room first.",
"Update\n\
Update bag",
"Arguments, Clean, List."
}),
({
"Watch [object] <lfun1> <lfun2> <lfun3> ...",
"Dieser Befehl ist vor allem beim Debuggen sehr nuetzlich. Nach\n\
Watch mit [object] und einer oder mehrerer <lfuns> wird der\n\
Wizard jedesmal informiert, wenn die spezifizierte Funktion\n\
im gewaehlten Objekt call_other()d wird. Darueberhinaus gibt die\n\
Robe aus, mit welchen Argumenten die Funktion aufgerufen wurde\n\
und welches Ergebnis zurueckgegeben wurde.\n\n\
Wird auf die Angabe von <lfuns> verzichtet, werden alle\n\
vorherigen Watch-Befehle fuer das betreffende [object] geloescht.\n\
Wird Watch ganz ohne Argumente aufgerufen, werden alle aktiven\n\
Watch-Auftraege angezeigt.",
"This command is especially useful for debugging purposes. After\n\
Watch with [object] and one or more <lfuns> the wizard gets\n\
notified whenever the specified function in the given command\n\
is called via call_other(). Furthermore the robe prints the\n\
arguments and the results of the call.\n\n\
If the <lfuns> are omitted, all previous Watch-jobs for the\n\
specified [object] are cancelled. If Watch is called without\n\
any argument, all active Watch-jobs are listed.",
"Watch here long short query_exit\n\
Watch $slot buggy_function\n\
Watch me\n\
Watch",
"Arguments, Deepwatch.",
}),
({
"Wenn in den Beschreibungen der Befehle in der Syntax [argument] auftaucht,\n\
versucht die Robe, das [argument] folgendermassen aufzuloesen:\n\n\
[argument] == $key  -> der in Slot key gespeicherte Wert\n\
[argument] == #nr  -> das nr-te Objekt der letzten Indexliste\n\
[argument] == \"string\"  -> der angegebene String\n\
[argument] == @         -> das Ergebnis des letzten Call/Eval-Aufrufs\n\
[argument] == me        -> das Objekt des aufrufenden Spielers\n\
[argument] == here   -> das Environment des aufrufenden Spielers\n\
[argument] == up  -> das Environment des zuletzt markierten Objekts\n\
[argument] == (subcall) -> das Ergebnis des angegebenen Subcalls\n\
[argument] == c1:c2:... -> das Ergebnis der aufeinanderfolgenden Auswertungen\n\
                           von c1, c2 ...\n\
[argument] == /file  -> das File mit der Bezeichnung file. Es wird\n\
         zunaechst das aktuelle Verzeichnus und danach\n\
         der komplette Userpath abgesucht.\n\n\
Dazu koennen die Spieler analog zu LPC auch Arrays, Mappings, Floats,\n\
Symbols und Closures erzeugen. Naeheres dazu in den jeweiligen\n\
Helpfiles.\n",
"When the descriptions of the commands refer to [argument], the Robe tries\n\
to resolve it following these rules:\n\n\
[argument] == $key  -> the contents of slot $key\n\
[argument] == #no  -> the (no). element of the indexlist\n\
[argument] == \"string\"  -> the given string\n\
[argument] == @         -> the result of the last Call/Eval-command\n\
[argument] == me        -> the object of the calling wizard\n\
[argument] == here   -> the environment of the calling wizard\n\
[argument] == up  -> the environment of the most recently marked object\n\
[argument] == (subcall) -> the result of the given subcall.\n\
[argument] == c1:c2:... -> the result of consecutive evaluations\n\
                           of c1, c2 ...\n\n\
Additionally the wizard can create arrays, mappings, floats, symbols\n\
and closures. Read the corresponding helpfiles for further informations.\n",
}),

({
"Die Robe kann auch Arrays als Aufrufparameter von efuns oder lfuns verdauen.\n\
Arrays als Parameter lassen sich einfach generieren: Sie werden einfach wie\n\
in LPC mit ({ ... }) erzeugt. Die einzelnen Elemente des Arrays werden aber\n\
mit Leerzeichen getrennt, NICHT mit Kommata. Arrays koennen beliebig\n\
verschachtelt werden. Innerhalb der Arrays verhaelt sich die Robe genau\n\
wie im Standardmodus, man kann weiterhin mit $, # und * auf markierte und\n\
gesuchte Objekte zugreifen, subcalls sind ebenfalls erlaubt. Auch der String-\n\
Konstruktor \"String mit vielen Spaces\" arbeitet innerhalb von Arrays.\n\
Beispiel:\n\n\
Call robe dump_argument ({ ({ *me }) \"das ist ein String\" 3 })\n\
==> *ARRAY*    (4 entries)\n\
({\n\
    ({\n\
        <obj/player#134>,\n\
    }),\n\
    \"das ist ein String\",\n\
    3,\n\
})",
"The Robe supports arrays as parameters for efuns or lfuns. You can easily\n\
generate them following these conventions: Like LPC, arrays are encapsulated\n\
in ({ ... }). Unlike LPC, the elements are separated by spaces, not colons.\n\
Arrays may be defined recursively. Array elements are regular [arguments],\n\
you can use slots, indices, subcalls and all the like. Example:\n\n\
Call robe dump_argument ({ ({ *me }) \"das ist ein String\" 3 })\n\
==> *ARRAY*    (4 entries)\n\
({\n\
    ({\n\
        <obj/player#134>,\n\
    }),\n\
    \"das ist ein String\",\n\
    3,\n\
})\n",
}),

({
"Die Robe kann auch Mappings als Funktionsparameter uebergeben, neuerdings\n\
auch valueless mappings (Mappings, die nur aus Keys bestehen, aber keine\n\
Values haben) und multidimensional mappings (Mappings mit mehreren Values\n\
zu einem Key). Die Syntax sieht so aus (gefolgt von einem Beispiel):\n\n\
normale mappings:           ([ <key1>:<value1> <key2>:<value2> ... ])\n\
                            ([ \"wizard\":me 1234:$4 ])\n\n\
multidimensional mappings:  ([ <key1>:<val1>;<val2>;... <key2>:<val3>;... ])\n\
                            ([ \"key\":1;2;3 $slot:here;me;(here short) ])\n\n\
valueless mappings:         ([ <key1> <key2> <key3> ... ])\n\
                            ([ \"key 1\" $7 church ])\n\n\
Hinweis: Zwischen Keys und Values duerfen _keine_ Spaces stehen!!\n",
"The Robe supports all kind of mappings as function parameters. Syntax:\n\n\
standard mappings:          ([ <key1>:<value1> <key2>:<value2> ... ])\n\
                            ([ \"wizard\":me 1234:$4 ])\n\n\
multidimensional mappings:  ([ <key1>:<val1>;<val2>;... <key2>:<val3>;... ])\n\
                            ([ \"key\":1;2;3 $slot:here;me;(here short) ])\n\n\
valueless mappings:         ([ <key1> <key2> <key3> ... ])\n\
                            ([ \"key 1\" $7 church ])\n\n\
Please note that between key and values _must not_ be any spaces!!\n"
}),
({
"Slots sind Zwischenspeicher, in denen man Daten oder Aufrufe speichern\n\
kann. Aehnlich wie Mappings bestehen sie aus einem Slot-Key und einem\n\
Value. Wird ein Slot mittels $key referenziert, wird der Value an der\n\
entsprechenden Auswertungsstelle eingesetzt. Values koennen jegliche\n\
Art von [arguments] sein.\n\n\
Darueberhinaus ist es moeglich, die Auswertung der Slots zu verzoegern.\n\
Falls der Value mit \"!\" beginnt, wird der Slot erst dann ausgewertet,\n\
wenn er referenziert wird. Beispiel:\n\n\
  Mark $cwd !(me query_path)\n\n\
Wenn zukuenftig $cwd verwendet wird, wird an der entsprechenden Stelle\n\
jedesmal das aktuelle Directory errechnet und eingefuegt.\n",
"Slots represent temporal memory units in which you can store data or\n\
Robe calls. Like mappings they consist of a slot-key and a value. If\n\
a slot is referenced via $key, the corresponding value gets inserted\n\
and evaluated. Values may be any kind of [arguments].\n\n\
Forthermore it is possible to delay the evaluation of a slot. If the\n\
value starts with a \"!\", the slot will only be evaluated when referenced,\n\
but not at definition time. Example:\n\n\
  Mark $cwd !(me query_path)\n\n\
Whenever $cwd will be used, the current working directory will be\n\
evaluated with the query_path subcall and returned.\n"
}),
({
"Die Robe verwaltet einen eigenen internen Userpath. Wenn die Robe\n\
nach einem File sucht, geht sie zuerst das aktuelle Directory und danach\n\
den Userpath Schritt fuer Schritt durch. Wird die Robe fuendig, bricht\n\
sie den Suchvorgang sofort ab. Dadurch kann es schon mal passieren, dass\n\
die Robe bei der Suche nach \"monster\" das File obj/monster.c anstelle\n\
des eigentlich anvisierten players/rumplemintz/sub/monster.c findet, weil\n\
/obj im Userpath \"weiter vorn\" steht. Ein kurzer Kontrollblick auf\n\
den gefundenen Filenamen ist immer eine gute Idee.\n\n\
Der Path kann insbesondere dann sehr nuetzlich sein, wenn man z.B. viele\n\
Raeume in verschiedenen Unterdirectories hat. Wenn man alle Directories\n\
in den Path eintraegt, kann man mit dem \"T\"-Befehl (Teleport) sehr\n\
bequem durch die Gegend springen, ohne sich darum kuemmern zu muessen,\n\
in welchem Directory man sich denn nun gerade befindet.\n\n\
Genauere Beschreibungen ueber die Benutzung des Userpaths findet man\n\
bei den Befehlen Path, Add und Remove.\n",
"The Robe has got its own internal Userpath. Whenever the Robe is looking\n\
for a special file, the current directory is scanned. On failure the\n\
Userpath will be searched step by step. On the first match the search\n\
ends instantly. Therefore it might happen that a search for \"monster\"\n\
will find obj/monster.c instead of the intended players/wizard/monster.c\n\
So it's quite a good idea to check the found filename everytime.\n",
})
  });
  macros  = m_allocate(0,2);
  shadows = m_allocate(0,2);
  watches = ([ ]);
  slot    = ([ ]);
  expect_list = ({ });
  dir_array   = ({ });
  if (!robe_symbols)
    robe_symbols = ([ ]);
  if (!inverted_symbols)
    inverted_symbols = ([ ]);
  call_out("install_me", 2);
  reset_marker();
}

static void install_me() {
  object env;
  int i;

#ifdef NIRVLIB
  if (environment(this_object()))
    SE_USERS->add_notify();
#endif
  if (!(env = environment(this_object())))
    return;

  MOVE(this_object(), environment());
  Restore(0);
  if (!sizeof(m_indices(macros)))
    macros = m_allocate(0,2);
  if (!preloads)
    preloads = ({ });
  else
    FOREACH(preloads,i)
      load_file(preloads[i],1);
  if (lang)
    return;
  if (interactive(env) &&
      member(({ ".de", ".at" }), query_ip_name(env)[<3..]) >= 0)
    lang = "deutsch";
  else
    lang = "english";
}

#ifndef NIRVLIB
static
#endif
int call_command(string arg) {
  if (!check_safety())
    return 0;
  return funcall(symbol_function(query_verb(), this_object()), arg);
}

void init() {
  int i;

  if (!wizard_check(this_player()))
    return;

  FOREACH(command_array,i)
    add_action("call_command",command_array[i]);

  add_action("New", "New");
  add_action("Call2","(",1);
  add_action("Call3","{",1);
}

