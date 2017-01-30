/*
 * clone this, and move it to player before calling more(file)
 * each cloned object will more only one file. It destructs itself
 * when quitting out of the more.
 *
 * it allows a player to open multiple more objects and switch
 * between them. 
 */


#include "/include/mudlib.h"

#define MAX_BYTE_READ  8192       /* read file in 8KB blocks */
#define THIS_WIZARD         this_player()->query_security_level()
#define PASTE          "/open/paste/"+(string)this_player()->query_name(1)

#ifdef MSDOS
#define BOLD           "@#"
#define OFF            "#@"
#else
#define BOLD           "[1m"
#define OFF            "[0m"
#endif

static string more_filename;  /* file currently mored */
static string old_search;     /* last search string, so "/" only works */
static int total_lines;       /* total lines of file (Is this needed?) */
static int current_line;      /* line to cat(file) */
static status more_prompt_off;

/* search & replace */

string replace_file;
string replace;
string search;
int    last_byte;
int num_replaced;
int num_occured;

/* link list */

static object prev_more;      /* double linked more objects */
static object next_more;      /* when we in another more */

static int current_number;    /* current active more object */
static int total_links;       /* total more objects */
static int link_number;       /* link number */

static int MORE_BLOCK;

/**************************************************************************/
/* fn prototypes */

status more(string str);
void more_file();
void more_prompt();
static void answer_prompt(string str);
static void search_string(string str);
static void save_mored_file_with_overwrite(string str);
static void save_mored_file(string str);
static void dump_mored_file(string str);
static void copy_file(string in, string out, status overwrite);
void set_prev_more(object arg);
void set_next_more(object arg);
object get_top_more();
object get_bottom_more();
object get_more_ob(int i);
varargs void change_more(int i, status new);
void current_more(int i, int j);
void max_more(int j);
void add_more(object arg);
static void quit();
void Quit();
void list_files();
void show_file();
void replace_file(string str);
void replace_search(string str);
void replace_prompt();
void answer_replace_prompt(string ans);
void replace(status all);

/**************************************************************************/
/* object id */

status id(string str) { return str == "more"; }

status drop() {
  quit();
  return 1;
}


status illegal_filename(string file) {
  string *illegal, tmp1, tmp2;
  int i;

  if(!file || file == "") {
    file = "/"+file_name(environment(this_player()))+".c";
  }    
  illegal = ({ " ", "~", "!", "@", "#", "$", "%", "^", "&", "*",
               "(", ")", "=", "+", "<", ">", ":", ";", "\"", "'",
               "?", ",", "{", "}", "[", "]", "|", "\\", });

  for(i = 0; i < sizeof(illegal); i++) {
    if(sscanf(file,"%s"+illegal[i]+"%s", tmp1, tmp2)) {
      write("Illegal character '"+ illegal[i] +"' in filename.\n");
      return 1;
    }
  }
  return 0;
}

/****************************************************************************
/* start more here */

status more(string str) { 
  int f_size, byte_size, current_byte;
  int i;
  string txt, file;
  int lines_in_last_block;
  object ob;

  if(more_filename || environment() != this_player()) {
    quit();
    return 1;
  }
  if(!str) { 
    str = "/"+file_name(environment(this_player()))+".c";
  }

/* has wizard|player got read access */

  if(!(file = (string)this_player()->valid_read(str))) {
    write("Invalid access: "+str+"\n");
    quit();
    return 1;
  }

  file = "/" + file;

/* does file exist */

  if(illegal_filename(file)) {
    quit();
    return 1;
  }

  if((f_size = file_size(file)) < 0) { 
    write("Non-existing file: "+ file +"\n"); 
    quit();
    return 1; 
  } 

  if(!f_size) { 
    write("Empty file: "+ file +"\n"); 
    quit();
    return 1; 
  }

/* reset global variables */

  more_filename = file;
  current_line = 1;
  total_lines = 0;
  old_search = "";

/* find the files total line length */

  while(current_byte < f_size) {
    if(current_byte + MAX_BYTE_READ >= f_size) {
      byte_size = f_size - current_byte;
    }
    else {
      byte_size = MAX_BYTE_READ;
    }
    txt = read_bytes(file, current_byte, byte_size);         
    if(txt) {
#ifdef OLD_EXPLODE
      lines_in_last_block = sizeof(explode(txt + "\n","\n")) - 1;
#else
      lines_in_last_block = sizeof(explode(txt,"\n")) - 1;
#endif /* OLD_EXPLODE */
      total_lines += lines_in_last_block;
    }
    current_byte += byte_size;
  }
  MORE_BLOCK = 20;
  ob = present("more 2", this_player());
  if(!ob || ob == this_object()) ob = present("more",this_player());
  ob->add_more(this_object());
  return 1;
}


void more_file() {
  if(current_number != link_number) {
    change_more(current_number);
    return;
  }
  if(current_line < 1) current_line = 1; 
  if(!cat(more_filename,current_line, MORE_BLOCK)) {
    write("                    -=- EOF -=-\n");
    quit();
    return;
  }
  more_prompt();
  return;
}


/* make the more prompt */

void more_prompt() {
  int percent, f_size;
  string str;

  if(current_number != link_number) {
    change_more(current_number);
    return;
  }
  if(!more_filename) {
    quit();
    return;
  }
  if(current_line + MORE_BLOCK > total_lines) {
    percent = 100;
  }
  else {
    percent = ((current_line + MORE_BLOCK)*100)/total_lines;
  }
  f_size = file_size(more_filename);
  
  if(THIS_WIZARD) {
    str = "More("+ link_number +"/"+ total_links +"): "+
           more_filename+" ("+f_size+" bytes), ";
  }
  else {
    str = "More("+ link_number +"/"+ total_links +"): ";
  }
  if(strlen(str) > 45) str += "\n      ";
  if(!more_prompt_off)
    write("\n"+ str+percent+"% [<cr>,u,b,f,-/+,/,q,!,?] ");
  input_to("answer_prompt");
  return;
}


static void answer_prompt(string str) {
  int i;
  string tmp;

  if(!str || str == "" || str[0] == 'n') {
    current_line += MORE_BLOCK;
  }
  else if(sscanf(str, "-%d", i)) { 
    current_line -= i; 
  } 
  else if(str[0] == '-') {
    current_line -= 1;
  }
  else if(sscanf(str, "+%d", i)) { 
    current_line += i; 
  } 
  else if(str[0] == '+') {
    current_line += 1;
  }
  else if(sscanf(str, "%d", i)) { 
    current_line = i; 
  } 
  else if(str[0] == 'u' || str[0] == 'p') {
    current_line -= MORE_BLOCK; 
  }
  else if(str[0] == 'f') {
    current_line += 5;
  }
  else if(str[0] == 'b') {
    current_line -= 5;
  }
  else if(sscanf(str,"/%s",tmp)) {
    search_string(tmp);
    return;
  }
  else if(str[0] == '/') {
    search_string("");
    return;
  }
  else if(str[0] == 'h' || str[0] == '?') {

write("      -=[ More Help ]=-\n\n");
write(" Command         Notes\n");
write("   u,p      One page up.\n"); 
write(" <cr>,n     One page down.\n"); 
write("   b,f      Up/Down 5 lines.\n");
write("    #       Goto line #.\n"); 
write("  +/-#      Jump # lines up/down.\n");
write("    !       !external command.\n");
if(THIS_WIZARD) {
  write("   s,S      Save "+more_filename+", S is with overwrite.\n");
  write("    d       Dump page to file, if exists, appends to file.\n");
  write("    r       Search & Replace in new file.\n");
  write("    >file   Open another 'mored' file.\n");
  write("   o        Toggle prompt line off|on, useful for screen captures.\n");
}
write("    >#      Change to more number #.\n");
write("    l       Number of lines in file.\n");
write(" q,x,Q,X    quit more; Quit all mored files.\n");
write("  /str      Search for string \"str\"\n");
write("    c       clip page to clipboard\n");
write("    m#      Screen Mode, # lines (Default: 20 lines)\n");
write("  other     Rewrite page.\n");

    more_prompt();
    return; 
  }    
  else if(str[0] == 'q' || str[0] == 'x') {
    quit();
    return; /* quit more */
  }
  else if(str[0] == 'l') {
    int l;

    l = current_line + MORE_BLOCK;
    l = (l > total_lines) ? total_lines : l;
    write("Line: ("+current_line+"-"+l+")/"+total_lines+"\n");
    more_prompt();
    return;
  } 
  else if(str[0] == 'o') {
    more_prompt_off = !more_prompt_off;
    write("Prompt line "+((more_prompt_off) ? "Off.\n" : "On.\n"));
    more_prompt();
    return;
  }
  else if(str[0] == '!') {
    command(extract(str,1), this_player());
    more_prompt();
    return;
  }
  else if(str[0] == 'm') {
    sscanf(str,"m%d",i);
    if(i < 1 || i > 45) i = 20;
    write("Screen Mode set to "+i+" lines.\n");
    MORE_BLOCK = i;
    more_prompt();
    return;
  }
  else if(sscanf(str,">%d",i)) {
    if(i > 0 && i <= total_links) {
       current_number = i;
    }
    else {
      write("More number "+i+" is not open.\n");
      more_prompt();
      return;
    }
  }
  else if(str[0] == 'Q' || str[0] == 'X') {
    get_bottom_more()->Quit();
    return;
  }
  else if(str[0] == 'c') {
    dump_mored_file(PASTE);
    return;
  }
  else if(THIS_WIZARD) {
    if(str[0] == 'r') {
      write("Enter Filename to write Replacement file.\n"+
            "(Default Dir: /"+(string)this_player()->query_path()+"): ");
      input_to("replace_file");
      return;
    }
    if(str[0] == 's') {
      write("Enter Save Filename (Default Dir: /"+
            (string)this_player()->query_path()+"): ");
      input_to("save_mored_file");
      return;
    }
    else if(str[0] == 'S') {
       write("Enter Save Filename (Default Dir: /"+
             (string)this_player()->query_path()+"): ");
       input_to("save_mored_file_with_overwrite");
       return;
    }
    else if(str[0] == 'd') {
      write("Enter Dump Filename (Default Dir: /"+
            (string)this_player()->query_path()+"): ");
      input_to("dump_mored_file");
      return;
    }
    else if(str[0] == '>') {
      object ob;
      if(str == ">") {
        list_files();
        more_prompt();
        return;
      }
      else {
        sscanf(file_name(this_object()),"%s#%d", tmp, i);
        ob = clone_object(tmp); /* generic self clone */
        move_object(ob, environment());
        ob->more(extract(str,1));
        if(!ob) more_prompt(); /* new more object may destruct itself */
        return;
      }
    }
  }

  /* else rewrite page */

  more_file();
  return;
} 


static void search_string(string str) { 
  int i;
  int lines_in_block;       /* number of lines in a file block */
  int lines_before;         /* number of lines before a file block */
  int lines;                /* number of lines searched in a block */
  int abort;                /* number of blocks read, if > 40 abort */
  string txt;               /* text of a block */
  string *txt_list;         /* list separating search string */
  int current_byte;         /* file handle */
  int max_byte;             /* max bytes read from file */ 
  int f_size;               /* file size */


  /* is this a repeat of an old search? */

  if(!str || str == "") { 
    if(old_search == "") {
      more_prompt();
      return; 
    }
    str = old_search;
  }
  else {
    old_search = str;
  }


  /* read through file */

  f_size = file_size(more_filename);
  while(current_byte < f_size) {
    if(abort++ > 30) break;  /* aborts if file > 240 kB! tested to 140kB */ 
    if(current_byte + MAX_BYTE_READ > f_size)
      max_byte = f_size - current_byte;
    else
      max_byte = MAX_BYTE_READ;
    txt = read_bytes(more_filename, current_byte, max_byte);         
#ifdef OLD_EXPLODE
    lines_in_block = sizeof(explode(txt + "\n","\n")) - 1;
#else
    lines_in_block = sizeof(explode(txt, "\n")) - 1;
#endif

    if(lines_in_block + lines_before < current_line) {
      lines_before += lines_in_block;   
      current_byte += max_byte;

      continue;
    }

#ifdef OLD_EXPLODE
    txt_list = explode(txt + str, str);
#else
    txt_list = explode(txt, str);
#endif /* OLD_EXPLODE */

    for(i = 0; i < sizeof(txt_list); i++) {
      if(i) {
        string tmp;
        tmp = implode(txt_list[0..i], str);

#ifdef OLD_EXPLODE
        lines = sizeof(explode(tmp + "\n", "\n"));
#else
        lines = sizeof(explode(tmp, "\n"));
#endif /* OLD_EXPLODE */

      }
      else {

#ifdef OLD_EXPLODE
        lines = sizeof(explode(txt_list[0] + "\n", "\n"));
#else
        lines = sizeof(explode(txt_list[0], "\n"));
#endif /* OLD_EXPLODE */

      }
      if(lines_before + lines > current_line && i < sizeof(txt_list) - 1) {
        current_line = lines_before + lines;
        more_file();
        return;
      }
    }
    lines_before += lines_in_block;
    current_byte += max_byte;

  }


  /* can't find string or search aborted */

  if(abort > 30) {
    write("Evaluation too long, aborting search.\n");
  }
  else {
    write("Cannot match "+str+" after line "+current_line+".\n"); 
  }
  more_prompt(); 
  return;
} 


/* save Mored file */

static void save_mored_file_with_overwrite(string str) {
  if(!illegal_filename(str)) {
    copy_file(more_filename, str, 1);
  }
  more_prompt();
}


static void save_mored_file(string str) {
  if(!illegal_filename(str)) {
    copy_file(more_filename, str, 0);
  }
  more_prompt();
}


/* dump page to file */

static void dump_mored_file(string str) {
  string txt;

  if(illegal_filename(str)) {
    more_prompt();
    return;
  }
  if(!(str = (string)this_player()->valid_write(str))) {
    write("Invalid File Access.\n");
    more_prompt();
    return;
  }
  str = "/" + str;
  if(file_size(str) >= 0) {
    if(str == PASTE)
      rm(PASTE);
    else
      write("Appending to File: "+str+"\n");
  }
  write("Dumping screen to "+ ((str == PASTE) ? "clipboard." : str) +"\n");
  txt = read_file(more_filename, current_line, MORE_BLOCK);
  write_file(str, txt);
  more_prompt();
}


/************************************************************************/
/* copy a file from in to out */

static void copy_file(string in, string out, status overwrite) {
  int f_size, current_byte;
  int max_byte;
  string txt;

  if(!(in || out) || in == "" || out == "") return;

  if(!(in = (string)this_player()->valid_read(in))) {
    write("Invalid Read Access.\n");
    return;
  }
  in = "/"+in;

  if(!(out = (string)this_player()->valid_write(out))) {
    write("Invalid Write Access.\n");
    return;
  }
  out = "/"+out;

  if(file_size(in) < 0) {
    write("File: "+in+" does not exist.\n");
    return;
  }

  if(file_size(out) >= 0) {
    if(!overwrite) {
      write("File Already Exists: "+out+"\n");
      return;
    }
    if(out == in) {
      write("Cannot copy file onto itself.\n");
      return;
    }
    write("Removing old file....\n");
    rm(out);
  }
  write("Copying "+in+" to "+out+"\n");
  f_size = file_size(in);
  while(current_byte < f_size) {
    if(current_byte + MAX_BYTE_READ > f_size)
      max_byte = f_size - current_byte;
    else
      max_byte = MAX_BYTE_READ;
    txt = read_bytes(in, current_byte, max_byte);
    write_file(out, txt);
    current_byte += max_byte;
  
  }
}

/************************************************************************/
/* list of mored files */

void list_files() {
  object head;

  write("File(s): \n");
  head = get_bottom_more();
  head->show_file();
}

void show_file() {
  write(link_number+". "+more_filename+"\n");
  if(next_more) next_more->show_file();
}

/************************************************************************/
/* set links */

void set_prev_more(object arg) { prev_more = arg; }
void set_next_more(object arg) { next_more = arg; }


/************************************************************************/
/* find link limits */

object get_top_more() { /* get link head */ 
  if(next_more) return (object)next_more->get_top_more();
  return this_object();
}

object get_bottom_more() { /* get link base */
  if(prev_more) return (object)prev_more->get_bottom_more();
  return this_object();
}

object get_more_ob(int i) {
  if(i == link_number) return this_object();
  if(i > link_number && next_more) return (object)next_more->get_more_ob(i);
  if(i < link_number && prev_more) return (object)prev_more->get_more_ob(i);
  return 0; /* this should not happen */
}

/**********************************************************************/
/* number links */


varargs void change_more(int i, status new) {
  object head;

  head = get_bottom_more();
  head->current_more(i,0);
  if(i > total_links)  {
    return (void)head->change_more(total_links, new); /* Error */
  }
  head = (object)head->get_more_ob(i);
  if(head) {
    if(new)
      head->more_file();
    else
      head->more_prompt();
  }
}  

void current_more(int i, int j) {
  current_number = i;
  j += 1;
  link_number = j;
  if(next_more)
    next_more->current_more(i,j);
  else
    max_more(j);
}

void max_more(int j) {
  total_links = j;
  if(prev_more) prev_more->max_more(j);
}


/**********************************************************************/
/* add link */


void add_more(object new) {
  object head;

  head = get_top_more(); 
  if(head != new) { /* for more(1): head == new == this_object() */
    head->set_next_more(new);
    new->set_prev_more(head);
  }
  head = (object)new->get_bottom_more();
  head->change_more(total_links+1,1);
}


/*************************************************************************/
/* quit */

static void quit() {
  object ob;

  if(next_more) {
    next_more->set_prev_more(prev_more);
    ob = (object)next_more->get_top_more();
  }
  if(prev_more) {
    prev_more->set_next_more(next_more);
    ob = (object)prev_more->get_top_more();
  }
  if(ob && ob != this_object()) {
    ob->change_more(1); /* 1 must exist */
  }
  destruct(this_object());
}


/************************************************************************/
/* Quit */

void Quit() { /* destruct all list - call from bottom of list */
  if(next_more) next_more->Quit();
  destruct(this_object());
}


/*************************************************************************/
/* search & replace */


void replace_file(string str) {
  replace_file = (string)this_player()->valid_write(str);
  if(!illegal_filename(str)) {
    replace_file = "/" + replace_file;
    if(file_size(replace_file) > 0) {
      write("Cannot overwrite an existing file.\n");
      more_prompt();
      return;
    }
    write(" Search Pattern: ");
    input_to("replace_search");
    return;
  }
  more_prompt();
}

void replace_search(string str) {
  if(!str || strlen(str) < 2) {
    write("Invalid search string.\n");
    more_prompt();
    return;
  }
  search = str;
  write("Replace Pattern: ");
  input_to("replace_pattern");
}

void replace_pattern(string str) {
  if(!str) str = "";
  replace = str;
  last_byte = 0;
  replace(0);
}

void replace_prompt() {
 write("Replace \""+ BOLD + search + OFF +"\" with \""+
       replace+"\" (y/n/r/q) [n]: ");
 input_to("answer_replace_prompt");
}


static void answer_replace_prompt(string ans) {
  if(ans == "q") {
    write("Quitting: File "+replace_file+" not complete.\n");
    more_prompt();
    return;
  }
  if(ans == "r") {
    write("Replacing all occurrances...\n");
    write_file(replace_file, replace);
    replace(1);
    return;
  }
  if(ans == "y") {
    write("Replacing...\n");
    write_file(replace_file, replace);
    ++num_replaced;
  }
  else {
    write("Skipping...\n");
    write_file(replace_file, search);
  }
  replace(0);
}


static void replace(status all) {
  int max_byte;             /* max bytes read from file */ 
  int f_size;               /* file size */
  string txt1, txt2, tmp;
  int abort;

  f_size = file_size(more_filename);
  while(last_byte < f_size) {
    txt2 = 0;
    if(last_byte + MAX_BYTE_READ > f_size)
      max_byte = f_size - last_byte;
    else
      max_byte = MAX_BYTE_READ;
    txt1 = read_bytes(more_filename, last_byte, max_byte);
    if(txt1) {
      sscanf(txt1,"%s"+ search +"%s", txt1, txt2);         
      write_file(replace_file, txt1);
      last_byte += strlen(txt1);
      if(txt2) last_byte += strlen(search);
      
      if(txt2) {
        ++num_occured;
        if(all && ++abort <= 30) {
          write_file(replace_file, replace);
          ++num_replaced;
          continue;
        }   
        if(strlen(txt1) > 300) {
          txt1 = extract(txt1, strlen(txt1)-300);
        }
        sscanf(txt1,"%s\n%s", tmp, txt1);
        write(txt1);
        write(BOLD+search+OFF);
        if(strlen(txt2) > 200) {
          txt2 = extract(txt2, 0, 200) + "\n";
        }
        write(txt2 +"\n");
        if(abort > 30) {
          write("Replaced "+num_replaced+" occurrances. Continue?\n");
        }
        replace_prompt();
        return;
      }
    }
  }
  write("Found "+ num_occured +" occurances of \""+ BOLD + search + OFF +
        "\" in "+more_filename+"\n"+
        "Replaced "+ num_replaced +" of them with \""+ replace +
        "\" in "+replace_file+"\n");
  more_prompt();
}

