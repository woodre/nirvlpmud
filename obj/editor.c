/* Player Editor Version 1 */

/* 
This is a simple editor for making strings. DO CLONE this object,

Example in invoking editor:

status describe() {
  clone_object("obj/editor")->edit("set_description", description);
}                                   ^^^ fn name ^^^   ^^^ init string

when the editor does a quit and save it calls set_description()

void set_description(string arg) { 
  description = arg;
}

when the editor does a quit and No save it calls editor_quit(),

void editor_quit(string arg) {
  switch(arg) {
    case "set_description":
      write("Description has not been changed.\n");
    break;
  }
}

 */


#include "/include/mudlib.h"

#define PASTE  "/"+ PASTE_DIR +"/"+ (string)this_player()->query_name(1)


/* editor caller */

static object caller;            /* object that called editor */
static string caller_fn;         /* fn name to call in editor caller when
                                    finished. Called with editor string as
                                    argument. */

/* editor set-up */

static status mark_paste;        /* flag on, mark pastes with ">" */


/* new message */

static string *new_message;      /* array of strings */
static int current_line;         /* current editor line */

static mixed *extra_args;

/* fn prototypes */

void reset(status arg);
status drop();
void quit();
void prompt();
status command_parser(string str);
varargs void edit(string return_fn, string init_message);
void get_body(string str);


/**************************************************************************/

void reset(status arg) {
  if(arg) return;
  new_message = ({});
  current_line = 1;
}


status id(string str) { return str == "editor"; }


string query_name()   { return "editor"; }


status drop() {
  destruct(this_object());
  return 1;
}


/********************************************************************/
/* quit */

static void quit() {
  string message;

  message = implode(new_message,"\n") +"\n";
  if(caller) {
    call_other(caller, caller_fn, message, extra_args);
  }
  else {
    write("Error: Object that invoked editor has destructed itself.\n");
  }
  destruct(this_object());
  return;
}


/*********************************************************************/
/* line prompt */

static void prompt() {
  input_to("get_body");
  write(((current_line < 10) ? " " : "")+ current_line +"] ");
}


/********************************************************************/
/* interpret cmds */

static status command_parser(string str) {
  int to, from;
  int i;
  string *lines;


  /* help */

  if(str == "~h") {
    write("               -=[ Commands ]=-\n\n"+
          "           '~h'       this help\n"+
          "           '**'       terminate and save\n"+
          "           '~q'       quit, do not save\n"+
          "           '~c#1,#2'  copy line(s) #1 {to #2 }, to clipboard\n"+
          "           '~p'       paste from clipboard\n"+
          "           '~s'       show clipboard\n"+
          "           '~w'       reprint message so far\n"+
          "           '~i#1'     insert above line #1\n"+
          "           '~d#1,#2'  delete line(s) #1 {to #2 }\n"+
          "           '!cmd'     do action 'cmd'\n\n"+
          "           Note: '#1' means <start line number>\n"+
          "                 '#2' means <end line number>\n");
    prompt();
    return 1;
  }

  /* quit without save */

  if(!sizeof(new_message) && str == "**") str = "~q";
  if(str == "~q") {
    write("You quit...\n");
    if(caller) call_other(caller,"editor_quit",caller_fn);
    destruct(this_object());
    return 1;
  }

  /* quit and save */

  if(str == "**") {
    write("You finish writing...\n");
    quit();
    return 1; 
  }

  /* delete */

  if(sscanf(str,"~d%d,%d",from, to) || sscanf(str,"~d%d",from)) {
    if(!to) to = from;
    if(from < 1 || from > sizeof(new_message)+1 || to < from 
    || to > sizeof(new_message)+1) {
      write("Lines out of range.\n");
      prompt();
      return 1;
    }
    write("You delete "+((to == from) 
        ? "line "+ to +"\n" 
        : "from line "+ from +" to line "+ to +"\n"));
      
    new_message = new_message[0..from-2]
                + new_message[to..sizeof(new_message)-1];
    if(current_line > sizeof(new_message)+1) {
      current_line = sizeof(new_message)+1;
    }
    prompt();
    return 1;
  }

  /* print out message so far */

  if(str == "~w") {
    if(sizeof(new_message) < 50) {
      for(i = 0; i < sizeof(new_message); i++) {
        if(i < 9) write(" ");
        write((i+1) +"] "+ new_message[i] +"\n");
      }
    }
    else if(sizeof(new_message)) {
      write(implode(new_message,"\n") +"\n");
      write("There are "+ sizeof(new_message) +" lines.\n");
    }
    else {
      write("Empty.\n");
    }
    prompt();
    return 1;
  }

  /* insert */

  if(sscanf(str,"~i%d",from)) {
    if(from < 1) from = 1;
    if(from > sizeof(new_message)+1) from = sizeof(new_message)+1;
    current_line = from;
    prompt();
    return 1;
  }

  /* copy to clipboard */

  if(sscanf(str,"~c%d,%d",from, to) || sscanf(str,"~c%d",from)) {
    if(!to) to = from;
    if(from < 1 || from > sizeof(new_message) || to < from 
    || to > sizeof(new_message)) {
      write("Lines out of range.\n");
      prompt();
      return 1;
    }
    write("You copy "+((to == from) 
        ? "line "+ to +" to clipboard.\n" 
        : "from line "+ from +" to line "+ to +" to clipboard.\n"));
    
    if(from == to)
      str = new_message[from-1] +"\n";
    else
      str = implode(new_message[(from-1)..(to-1)],"\n") +"\n";
    rm(PASTE);
    write_file(PASTE,str);
    prompt();
    return 1;
  }

  /* show clipboard */

  if(str == "~s") {
    str = read_file(PASTE);
    write(((str) ? "Clipboard:\n"+ str +"\t\t\t-=-\n" : "Clipboard Empty.\n"));
    prompt();
    return 1;
  }
  return 0;
}


/*********************************************************************/
/* body of txt writing */
 
void get_body(string str) { 
  string *line;

  if(command_parser(str)) return;
  if(!str) str = "";
  line = ({ str, });
  if(str == "~p") {
    str = read_file(PASTE);
    if(!str) {
      write("Nothing in Clipboard.\n");
      prompt();
      return;
    }
#ifdef OLD_EXPLODE
/*
    if(str[strlen(str)-1] != '\n') str += "\n";
*/
#else
    if(str[strlen(str)-1] == '\n') str = extract(str,0,strlen(str)-2);
#endif
    line = explode(str,"\n");

    if(mark_paste && !this_player()->query_security_level()) {
      str = ">"+ implode(line,"\n>");
#ifdef OLD_EXPLODE
      str += "\n";  
#endif
      line = explode(str,"\n");
    }
  }
  if(current_line-1 > sizeof(new_message)) {
    current_line = sizeof(new_message)+1;
  }
  if(current_line-1 != sizeof(new_message)) {
    new_message = new_message[0..(current_line-2)]+ line +
                  new_message[current_line-1..sizeof(new_message)-1];
  }
  else {
    new_message += line; 
  }
  current_line += sizeof(line);
  prompt();
} 


/***********************************************************************/
/* start editor */

varargs void edit(string return_fn, string init_message, status mark, mixed *args) {
  extra_args = args;
  caller = previous_object(); 
  if(!return_fn || !function_exists(return_fn, caller)) {
    write("Error: No return Function for editor to call.\n");
    return;
  }
  caller_fn = return_fn;
  current_line = 1;
  mark_paste = mark;
  if(init_message && init_message != "") {
#ifdef OLD_EXPLODE
    if(init_message[strlen(init_message)-1] != '\n') init_message += "\n";
#else
    if(init_message[strlen(init_message)-1] == '\n') 
      init_message = extract(init_message,0,strlen(init_message)-2);
#endif
    new_message = explode(init_message,"\n");
    current_line += sizeof(new_message);
  }
  write("'~h' for help. '**' to quit and save. '~q' to quit.\n"+
        "Write message,\n");
  command_parser("~w");
}


