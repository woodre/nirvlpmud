#pragma strong_types

#include <kernel.h>
#include <grammar.h>
#include <lpctypes.h>
#include <ctype.h>
#include <libs.h>

inherit ACCESS;
inherit "basic/daemon";
inherit "basic/create";
inherit "basic/path";
inherit "basic/parser";
inherit "basic/tools/output";
inherit "basic/list";
inherit "basic/stack";
static functions inherit "basic/property";

private mapping programs, save_programs;
private static string owner;
private static mixed last_result;

#define ARRAY #'({

#define THREAD_SERVER "/bin/sub/thread"
#define PUSH_CALL(x,y) THREAD_SERVER->push_call(x,y)

#define QUEUE_RESULT 0
#define QUEUE_QUOTES 1
#define QUEUE_PARANTHESES 2
#define QUEUE_OPEN_PARANTHESES 3
#define QUEUE_ESCAPED 4
#define QUEUE_QUOTED 5
#define QUEUE_IN_STRING 6
#define QUEUE_POSITION 7
#define QUEUE_SCOPE 8

#define PARSE_FAMILY "queue_parse_family"
#define DEFAULT_SAVE_FILE "/players/ugh/.queuerc"

#define AFTER_PARSE_QUEUE 1
#define AFTER_ARRAY 2
#define AFTER_CALL 3
#define AFTER_CALL2 4
#define AFTER_RESULT 5
#define AFTER_EVAL 6

// added static in next 5 lines, Coogan, 11-Oct-01
static varargs mixed *scan(string input,mixed *queue);
static varargs void evaluate(mixed *queue);
static varargs void parse_queue(mixed *queue,status quote_symbols,int label);
static varargs void build_array(mixed *queue,int to,status quote_symbols,
                                int label);
static varargs void build_mapping(mixed *queue,int to,int label);

static void error(string str) { 
  raise_error(str);
}

static varargs mixed * scan(string input,mixed *queue) {
  mixed h;
  int length, spaces, *bracket_begins, quoted;
  status escaped, in_string;
  string *result;
  mapping quotations, brackets;
  if (!queue)
    queue = allocate(9);
  result = queue[QUEUE_RESULT] || ({""});
  quotations = queue[QUEUE_QUOTES] || ([]);
  brackets = queue[QUEUE_PARANTHESES] || ([]);
  bracket_begins = queue[QUEUE_OPEN_PARANTHESES] || ({-1});
  quoted = queue[QUEUE_QUOTED];
  escaped = queue[QUEUE_ESCAPED];
  in_string = queue[QUEUE_IN_STRING];
  length = strlen(input);
  while (length--) {
    if (quoted && input[<length+1] != '\'') {
      quotations += ([sizeof(result)-1 : quoted]);
      quoted = 0;
      if (input[<length+1] == ' ')
	result += ({""});
    }
    if (escaped) {
      switch (input[<length+1]) {
      case 'n':
	result[<1] += "\n"; break;
      case 'a':
	result[<1] += "\a"; break;
      case 'b': 
	result[<1] += "\b"; break;
      case 't':
	result[<1] += "\t"; break;
      case '\\':
	result[<1] += "\\"; break;
      case '\r':
	result[<1] += "\r"; break;
      case '\f':
	result[<1] += "\f"; break;
      default:
	result[<1] += "\\"+input[<length+1..<length+1];
      }
      escaped = 0;
      continue;
    }
    if (input[<length+1] == '\\') {
      escaped = 1;
      continue;
    }
    if (in_string) {
      result[<1] += input[<length+1..<length+1];
      if (input[<length+1] == '\"') {
	in_string = 0;
	result += ({""});
      }
      continue;
    }
    if (input[<length+1] == ' ') {
      if (strlen(result[<1])) {
	result += ({""});
	spaces = 1;
      }
      spaces++;
      continue;
    }
    if (result[<1] == "#'") {
      result[<1] += input[<length+1..<length+1];
      continue;
    }
    switch (input[<length+1]) {
    case '\,':
      if (strlen(result[<1]))
	result += ({""});
      break;
    case '\'':
      if (strlen(result[<1]) && result[<1][<1] == '#') {
	if (strlen(result[<1]) > 1) {
	  result += ({"#"});
	  result[<2][<1..] = "";
	}
	result[<1] += "\'";
	break;
      }
      else
        if (strlen(result[<1]) && !quoted)
          result += ({""});
      quoted++;
      break;
    case '\"':
      if (strlen(result[<1]))
	result += ({""});
      in_string = 1;
      result[<1] += "\"";
      break;
    case '\`':
      if (strlen(result[<1]))
	result += ({""});
      result[<1] += "`";
      if (bracket_begins[<1] >= 0 && result[bracket_begins[<1]] == "`") {
	brackets += ([ bracket_begins[<1] : sizeof(result)-1 ]);
	bracket_begins[<1..] = ({});
      }
      else
	bracket_begins += ({sizeof(result)-1});
      result += ({""});
      break;
    case '(':
      if (strlen(result[<1]))
	result += ({"("});
      else
	result[<1] += "(";
      bracket_begins += ({sizeof(result)-1});
      result += ({""});
      break;
    case ')':
      if (sizeof(bracket_begins) < 2)
	return error("Parse error: No matching parantheses.\n"), 0;
      if (result[<1][<1..<1] == "]") {  // closing mapping
	if (result[bracket_begins[<1]] != "([")
	  return error("Parse error: No matching parantheses.\n"), 0;
	if (strlen(result[<1]) > 1) {
	  result[<1][<1..<1] = "";
	  result += ({"]"});
	}
      }
      else if (result[<1][<1..<1] == "}") {
	if (result[bracket_begins[<1]] != "({")
	  return error("Parse error: No matching parantheses.\n"), 0;
	if (strlen(result[<1]) > 1) {
	  result[<1][<1..<1] = "";
	  result += ({"}"});
	}
      }
      else {
	if (result[bracket_begins[<1]] != "(")
	  return error("Parse error: No matching parantheses.\n"), 0;
	if (strlen(result[<1]))
	  result += ({""});
      }
      result[<1] += ")";
      brackets += ([bracket_begins[<1] : sizeof(result)-1]);
      bracket_begins[<1..<1] = ({});
      result += ({""});
      break;
    case '[':
      if (!strlen(result[<1]) && sizeof(result) > 1 && result[<2] == "(" &&
	  !spaces)
	result[<2] += "[";
      else
	result[<1] += "[";
      break;
    case '{':
      if (!strlen(result[<1]) && sizeof(result) > 1 && result[<2] == "(" &&
	  !spaces)
	result[<2] += "{";
      else
	result[<1] += "{";
      break;
    case ':':
      if (strlen(result[<1]))
	result += ({""});
      result[<1] += input[<length+1..<length+1];
      result += ({""});
      break;
    default:
      result[<1] += input[<length+1..<length+1];
      break;
    }
    spaces = 0;
  }
  if (!escaped) {
    if (sizeof(bracket_begins) > 1)
      return error("Parse_error: Not all parantheses closed.\n"), 0;
    if (in_string)
      return error("Parse error: Newline in string.\n"), 0;
    if (!strlen(result[<1]))
      result[<1..<1] = ({});
  }
  queue[QUEUE_RESULT] = result;
  queue[QUEUE_QUOTES] = quotations;
  queue[QUEUE_PARANTHESES] = brackets;
  queue[QUEUE_OPEN_PARANTHESES] = bracket_begins;
  queue[QUEUE_QUOTED] = quoted;
  queue[QUEUE_ESCAPED] = escaped;
  queue[QUEUE_IN_STRING] = in_string;
  return queue;
}

static string query_program(string name) {
  return save_programs[name];
}

static string * query_private_functions() {
  return 
    m_indices(mkmapping(m_indices(programs)+m_indices(save_programs)));
}

static mixed * private_function(string name) {
  if (!member(programs,name) && member(save_programs,name))
    programs[name] = save_programs[name];
  return programs[name];
}

static varargs void build_array(mixed *queue,int to,status quote_symbols,
                                int label) {
  switch (label) {
  case 0:
    if (queue[QUEUE_POSITION] <= to) {
      PUSH_CALL(#'build_array,
		({queue,to,quote_symbols,AFTER_PARSE_QUEUE})); 
      PUSH_CALL(#'parse_queue,({queue,quote_symbols}));
      break;
    }
    else
      queue[QUEUE_POSITION] = to;
    break;
  case AFTER_PARSE_QUEUE:
    queue[QUEUE_POSITION]++;
    if (sizeof(queue[QUEUE_SCOPE]) == 1)
      last_result = top(top(queue[QUEUE_SCOPE]));
    PUSH_CALL(#'build_array,({queue,to,quote_symbols}));
  }
}

static varargs void build_mapping(mixed *queue,int to,int label) {
  mixed h;
  switch (label) {
  case 0:
    if (queue[QUEUE_POSITION] <= to) {
      if (queue[QUEUE_RESULT][queue[QUEUE_POSITION]] == ":") {
	h = top(queue[QUEUE_SCOPE]);
	queue[QUEUE_SCOPE] = pop(queue[QUEUE_SCOPE]);
	queue[QUEUE_SCOPE] =
	  push(push(top(h),({})),
	       push(push(pop(h),top(queue[QUEUE_SCOPE])),
		    pop(queue[QUEUE_SCOPE])));
      }
      else {
	PUSH_CALL(#'build_mapping,
		  ({queue,to,AFTER_PARSE_QUEUE}));
	PUSH_CALL(#'parse_queue,({queue}));
	return;
      }
    }
  case AFTER_PARSE_QUEUE:
    queue[QUEUE_POSITION]++;
  }
  if (queue[QUEUE_POSITION] <= to) {
    PUSH_CALL(#'build_mapping,({queue,to}));
    return;
  }
  queue[QUEUE_POSITION] = to;
  h = top(queue[QUEUE_SCOPE]);
  queue[QUEUE_SCOPE] = pop(queue[QUEUE_SCOPE]);
  queue[QUEUE_SCOPE] = 
    push(push(h,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
  if (sizeof(h = top(queue[QUEUE_SCOPE])) == 1) {
    if (!sizeof(h[0])) // no entries at all
      queue[QUEUE_SCOPE] = push(([]),pop(queue[QUEUE_SCOPE]));
    else
      queue[QUEUE_SCOPE] = push(mkmapping(h[0]),pop(queue[QUEUE_SCOPE]));
  }
  else if (sizeof(h[0]))
    error("Parse error: Unknown format of mapping.\n");
  else
    queue[QUEUE_SCOPE] = 
      push(apply(#'mkmapping,transpose_array(h[1..])),pop(queue[QUEUE_SCOPE]));
}

static mixed * substitute_symbol(mixed code,mixed s,mixed with) {
  if (code == s)
    return with;
  if (pointerp(code))
    return map(code,#'substitute_symbol,s,with);
  else
    return code;
}

// func type from mixed to void, Coogan, 26-Mar-2011
static varargs void build_lambda(mixed *queue,mixed *args,mixed *code,
                                 int label) {
  mixed result, h;
  int last_open, argc, closing, i;
  switch (label) {
  case 0:
    last_open = top(queue[QUEUE_OPEN_PARANTHESES]);
    if (!args)
      args = ({});
    if (sizeof(args)) {
      queue[QUEUE_POSITION]++;
      if (last_open < 0
          ? queue[QUEUE_POSITION] >= sizeof(queue[QUEUE_RESULT])
          : (queue[QUEUE_POSITION] == queue[QUEUE_PARANTHESES][last_open] ||
	     (queue[QUEUE_RESULT][last_open] == "([" &&
	      queue[QUEUE_RESULT][queue[QUEUE_POSITION]] == ":"))) {
	queue[QUEUE_POSITION]--;
	break;
      }
      queue[QUEUE_SCOPE] = push(({args[0]}),queue[QUEUE_SCOPE]);
      PUSH_CALL(#'build_lambda,({queue,args[1..],code,AFTER_PARSE_QUEUE}));
      PUSH_CALL(#'parse_queue,({queue,1}));
      return;
    }
    break;
  case AFTER_PARSE_QUEUE:
    h = top(queue[QUEUE_SCOPE]);
    queue[QUEUE_SCOPE] = pop(queue[QUEUE_SCOPE]);
    code = substitute_symbol(code,top(pop(h)),top(h));
    if (sizeof(args)) {
      PUSH_CALL(#'build_lambda,({queue,args,code}));
      return;
    }
  }
  if (sizeof(args))
    queue[QUEUE_SCOPE] = 
      push(push(lambda(args,code),top(queue[QUEUE_SCOPE])),
	   pop(queue[QUEUE_SCOPE]));
  else
    queue[QUEUE_SCOPE] =
      push(push(funcall(lambda(0,code)),top(queue[QUEUE_SCOPE])),
	   pop(queue[QUEUE_SCOPE]));
}

static mixed parse_object(string ob) {
  mixed h;
  return 
    ((h = parse_sentence("object "+ob,PARSE_FAMILY)) && h[G_OBJECT]) || 
    find_living(ob) ||
    find_object(ob) ||
    ((h = normalize_path(ob,this_player())) && 
     (find_object(h) || (file_size(h+".c") >= 0 && h)));
}

static varargs void parse_queue(mixed *queue,status quote_symbols, int label) {
  int quoted, to, begin;
  mixed result, h;
  string word;
  word = queue[QUEUE_RESULT][queue[QUEUE_POSITION]];
  quoted = queue[QUEUE_QUOTES][queue[QUEUE_POSITION]];
  switch (label) {
  case 0:
    switch (word) {
    case "`":
      queue[QUEUE_OPEN_PARANTHESES] = 
	push(queue[QUEUE_POSITION],queue[QUEUE_OPEN_PARANTHESES]);
      queue[QUEUE_SCOPE] = push(({}),queue[QUEUE_SCOPE]);
      queue[QUEUE_POSITION]++;
      PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_EVAL}));
      PUSH_CALL(#'parse_queue,({queue,1}));
      return;
    case "(":
      queue[QUEUE_OPEN_PARANTHESES] = 
	push(queue[QUEUE_POSITION],queue[QUEUE_OPEN_PARANTHESES]);
      queue[QUEUE_SCOPE] = push(({}),queue[QUEUE_SCOPE]);
      queue[QUEUE_POSITION]++;
      if (quoted) {
	to = queue[QUEUE_PARANTHESES][queue[QUEUE_POSITION]-1];
	queue[QUEUE_QUOTES][queue[QUEUE_POSITION]-1]--;
	PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_ARRAY}));
	PUSH_CALL(#'build_array,({queue,to-1}));
      }
      else {  // this is a code-array it seems
	PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_CALL}));
	PUSH_CALL(#'parse_queue,({queue,1}));
      }
      return;
    case "({":
      queue[QUEUE_OPEN_PARANTHESES] = 
	push(queue[QUEUE_POSITION],queue[QUEUE_OPEN_PARANTHESES]);
      queue[QUEUE_SCOPE] = push(({}),queue[QUEUE_SCOPE]);
      if (quote_symbols)
	queue[QUEUE_QUOTES][queue[QUEUE_POSITION]]++;
      quoted = queue[QUEUE_QUOTES][queue[QUEUE_POSITION]];
      to = queue[QUEUE_PARANTHESES][queue[QUEUE_POSITION]];
      queue[QUEUE_POSITION]++;
      PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_ARRAY}));
      PUSH_CALL(#'build_array,({queue,to-1,(!quoted && quote_symbols)}));
      return;
    case "([":
      queue[QUEUE_OPEN_PARANTHESES] = 
	push(queue[QUEUE_POSITION],queue[QUEUE_OPEN_PARANTHESES]);
      queue[QUEUE_SCOPE] = push(({}),push(({}),queue[QUEUE_SCOPE]));
      to = queue[QUEUE_PARANTHESES][queue[QUEUE_POSITION]];
      queue[QUEUE_POSITION]++;
      PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_ARRAY}));
      PUSH_CALL(#'build_mapping,({queue,to-1}));
      return;
    default:
      result = word;
      if (strlen(result) > 1 && result[0] == '\"' && result[<1] == '\"')
	queue[QUEUE_SCOPE] =
	  push(push(unescape_string(result[1..<2]),top(queue[QUEUE_SCOPE])),
	       pop(queue[QUEUE_SCOPE]));
      else if (!quoted) {
	if (h = private_function(result)) {
	  PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_RESULT}));
	  PUSH_CALL(#'build_lambda,({queue,h[0],h[1]}));
	  return;
	}
	else if (sizeof(regexp(({result}),"^(-|)[0-9]*$")))
	  queue[QUEUE_SCOPE] =
	    push(push(to_int(result),top(queue[QUEUE_SCOPE])),
		 pop(queue[QUEUE_SCOPE]));
	else if (result[0..1] == "#'" && 
		 h = symbol_function(result[2..]))
	  queue[QUEUE_SCOPE] =
	    push(push(h,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
	else if (quote_symbols && h = symbol_function(result))
	  queue[QUEUE_SCOPE] =
	    push(push(h,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
	else if (sizeof(regexp(({result}),
			"^(-|)([0-9][0-9]*\\.[0-9]*|[0-9]*)"
			"(e([+]|-)[0-9][0-9]*|)$")))
	  queue[QUEUE_SCOPE] =
	    push(push(to_float(result),top(queue[QUEUE_SCOPE])),
		 pop(queue[QUEUE_SCOPE]));
	else if (strstr(result," ") < 0 && h = parse_object(result))
	  queue[QUEUE_SCOPE] =
	    push(push(h,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
	else
	  queue[QUEUE_SCOPE] =
	    push(push(result,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
      }
      else {
	if (quoted && quote_symbols)
	  quoted++;
	queue[QUEUE_SCOPE] =
	  push(push(result,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
      }
    }
    break;
  case AFTER_EVAL:
    queue[QUEUE_SCOPE] = 
      push(top(top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
    PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_ARRAY}));
    return;
  case AFTER_CALL:
    h = top(top(queue[QUEUE_SCOPE]));
    to = queue[QUEUE_PARANTHESES][top(queue[QUEUE_OPEN_PARANTHESES])];
    if (closurep(h)) {
      if (CLOSURE_IS_LAMBDA(get_type_info(h,1)))
	queue[QUEUE_SCOPE] = push(({#'funcall,h}),pop(queue[QUEUE_SCOPE]));
    }
    else if (objectp(h) || stringp(h))
      queue[QUEUE_SCOPE] = push(({#'call_other,h}),pop(queue[QUEUE_SCOPE]));
    else 
      return error("Function '"+
		   queue[QUEUE_RESULT][queue[QUEUE_OPEN_PARANTHESES][<1]+1]+
		   "' not found.\n"), 0;
    queue[QUEUE_POSITION]++;
    PUSH_CALL(#'parse_queue,({queue,quote_symbols,AFTER_CALL2}));
    PUSH_CALL(#'build_array,({queue,to-1,1}));
    return;
  case AFTER_CALL2:
    queue[QUEUE_SCOPE] =
      push(funcall(lambda(0,top(queue[QUEUE_SCOPE]))),
	   pop(queue[QUEUE_SCOPE]));
  case AFTER_ARRAY:
    begin = top(queue[QUEUE_OPEN_PARANTHESES]);
    queue[QUEUE_POSITION] = queue[QUEUE_PARANTHESES][begin];
    quoted = queue[QUEUE_QUOTES][begin];
    h = top(queue[QUEUE_SCOPE]);
    queue[QUEUE_SCOPE] = pop(queue[QUEUE_SCOPE]);
    queue[QUEUE_SCOPE] =
      push(push(h,top(queue[QUEUE_SCOPE])),pop(queue[QUEUE_SCOPE]));
    queue[QUEUE_POSITION] =
      queue[QUEUE_PARANTHESES][top(queue[QUEUE_OPEN_PARANTHESES])];
    queue[QUEUE_OPEN_PARANTHESES] = pop(queue[QUEUE_OPEN_PARANTHESES]);
    break;
  case AFTER_RESULT:
    break;
  }
  if (quote_symbols && pointerp(top(top(queue[QUEUE_SCOPE]))))
    quoted++;
  if (quoted) {
    h = top(top(queue[QUEUE_SCOPE]));
    while (quoted--)
      h = quote(h);
    queue[QUEUE_SCOPE] = 
      push(push(h,pop(top(queue[QUEUE_SCOPE]))),
	   pop(queue[QUEUE_SCOPE]));
  }
  if (query_property("trace_parse_queue"))
    write(mixed2string(top(top(queue[QUEUE_SCOPE])))+"\n");
}

static varargs void evaluate(mixed *queue) {
  queue[QUEUE_SCOPE] = ({({})});
  PUSH_CALL(#'build_array,({queue,sizeof(queue[QUEUE_RESULT])-1,0}));
}

static void after_parse_input(mixed result) {
  mixed h;
  result = top(result[QUEUE_SCOPE]);
  if (stringp(result[0]) && (h = symbol_function(result[0])))
    result = ({last_result = apply(h,result[1..])});
  else if (sizeof(result) > 1) {
    if (stringp(result[1]) && objectp(result[0]))
      result = ({last_result = apply(#'call_other,result)});
    else if (closurep(result[0]))
      result = ({last_result = apply(#'funcall,result)});
  }
  if (sizeof(result))
    write("--\n"+
	  break_string(implode(map(result,#'mixed2string),";\n"))+"\n");
}

static varargs status parse_input(string str,string verb,mixed *queue) {
  mixed result, *code;
  string error;
  if (!str)
    return 0;
  result = scan(str,queue);
  if (!result)
    return 0;
  if (result[QUEUE_ESCAPED]) {
    write("? ");
    result[QUEUE_ESCAPED] = 0; // we only escaped the line
    input_to("parse_input",0,verb,result);
    return 1;
  }
  THREAD_SERVER->thread(({
			  ({#'after_parse_input,({result})}),
			  ({#'evaluate,({result})})}));
  return 1;
}

static void assign_function(string name,mixed *args,mixed *code) {
  m_delete(programs,name);
  if (code)
    save_programs[name] = ({args,code});
  else
    m_delete(save_programs,name);
}

static mixed * query_code(string name,mixed arg) {
  if (pointerp(arg))
    arg = ({ARRAY}) + arg;
  return ({#'apply,
	   ({#'apply,
	     #'lambda,
	     ({#'call_other,
	       ({#'this_object}),
	       "private_function",
	       name
	     })
	   }),
	   arg
	 });
}

static void let_variable(string name,mixed arg) {
  programs[name] = ({0,({#'return, arg})});
}

void create() {
  output::create();
  if (!clonep()) {
    set_auto_clone();
    set_privilege(1);
  }
}

static void save_queue() {
  if (owner)
    LIB_SAVER->save(LIB_TYPES->mixed2save(save_programs),
                    "/players/"+owner+"/.queuerc");
}

static varargs mapping load_queue(string file) {
  if (!file)
    file = "/players/"+owner+"/.queuerc";
  return
    LIB_TYPES->save2mixed(LIB_SAVER->load(file));
}

object query_owner() {
  return find_object(owner) || find_player(owner);
}

public mixed query_result() {
  if (check_privilege(get_privilege(this_object())))
    return last_result;
}

static void initialize(string who) {
  programs = ([]);
  set_privilege(get_privilege(find_object(who) || find_player(who)));
  owner = who;
  add_rule("object <object>","return_args",0,PARSE_FAMILY);
  add_command("parse_input","?");
  save_programs = 
    load_queue() ||
    load_queue(DEFAULT_SAVE_FILE);
  if (!save_programs)
    save_programs = ([]);
}

void set_player(string who) {
  if (!clonep() || object_name(previous_object()) != load_name(this_object()))
    return;
  initialize(who);
}

static status is_privileged(object who,string func) {
  return check_privilege(get_privilege(this_object()));
}
