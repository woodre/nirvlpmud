#define WIZARD "usr/creators/"

/*
#define OLD_EXPLODE
*/

#define PASSWORD_CHECK 3
#define SEC1 10
#define SEC2 20
#define SEC3 30
#define SEC4 40
#define SEC5 50
#define SEC6 60
#define SEC7 70
#define SEC8 80
#define SEC9 90

string name;
int level;
int security_level;          /* access privileges */
string password;             /* crypted password  */

/* logon stuff */

static int password_check;   /* Gives you 3 tries if you forget your password */
static object other_copy;    /* other me when logging in */

static string current_path;

static string *list;
static string new_text;
static int line;
static string error_msg;

void logon3();
status secure(int arg);
void print_files(string arg);
void print_verbose(string arg);


/***************************************************************************/
/* Normal commands - for players and wizards alike */

void add_standard_commands() {
  add_action("quit",           "quit"     );
  add_action("wiz",            "wiz"      );
  add_action("inventory",      "i"        );
  add_action("look",           "l"        );
  add_action("tell",           "tell"     );
  add_action("cat_file",       "cat"      );
  add_action("tail_file",      "tail"     );
  add_action("show_log",       "log"      );
  add_action("show_main_log",  "main"     );
  add_action("show_debug_log", "debug"    );
  add_action("edit",           "ed"       );
  add_action("dir",            "ls"       );
  add_action("clone",          "clone"    );
  add_action("load",           "load"     );
  add_action("update",         "update"   );
  add_action("dest_ob",        "dest"     );
  add_action("local_commands", "localcmd" );
  add_action("cd",             "cd"       );
  add_action("pwd",            "pwd"      );
}

void set_error_msg(string err) { error_msg = err; }


/***************************************************************************/
/* make_path - for players */

string make_path(string file) {
  string tmp1, tmp2;
  string *path_split;
  int i, len;

  if (!current_path) current_path = "players/" + name;
  if (!file || file == "") return "/" + current_path;
  if (file[0] == '~') {
    len = strlen(file);
    if (len == 1)
      return "/players/" + name;
    else if (len > 3) {
      if (file[1] == ' ' && file[2] == '/')
        file = "players/" + name + "/" + extract(file, 3);
      else if (file[1] == ' ')
        file = "players/" + name + "/" + extract(file, 2);
      else if (file[1] == '/') {
        file = "/players/" + extract(file, 2);
      }
      else {
        file = "/players/" + extract(file, 1);
      }
    }
  }
  if (file[0] != '/') {
    if (current_path == "") {
      file = "/" + file;
    }
    else {
      file = "/" + current_path + "/" + file;
    }
  }
  if (!sscanf(file, "%s..%s", tmp1, tmp2)) return file;

#ifdef OLD_EXPLODE
  path_split = explode(file + "/", "/");
#else
  path_split = explode(file, "/");
#endif
  while ((i = member_array("..", path_split)) != -1) {
    path_split = path_split[0..i-2] +
                 path_split[i+1..sizeof(path_split)-1];
  }
  if (sizeof(path_split)) {
    return "/" + implode(path_split, "/");
  }
  return "/";
}


/***************************************************************************/
/* move_player */

varargs void move_player(string dir_dest, mixed optional_dest_ob) {
  int i;
  string dir;
  mixed dest;
  object *inv, ob;

  if (!optional_dest_ob) {
    if (!sscanf(dir_dest, "%s#%s", dir, dest)) {
      write("Move to bad dir/dest\n");
      return;
    }
  }
  else {
    dir = dir_dest;
    dest = optional_dest_ob;
  }
  if (environment())
    tell_room(environment(), capitalize(name) + " leaves.\n");
  move_object(this_object(), dest);
  if (environment())
    tell_room(environment(), capitalize(name) + " arrives.\n");
  ob = environment();
  ob->long(1);
  inv = all_inventory(ob);
  for (i = 0; i < sizeof(inv); i++) {
    if (inv[i] == this_object()) continue;
    write(((inv[i]->short(1)) ? (string)inv[i]->short(1) : file_name(inv[i]))
          + "\n");
  }
}

varargs string query_name(status arg) {
  return (arg) ? lower_case(name) : capitalize(name);
}


/***************************************************************************/
/*  wiz */

static status wiz(string str) {
  object *ob;
  int i;

  ob = filter_array(users(), "filter_wizards", this_object());
  for (i = 0; i < sizeof(ob); i++) {
    ob[i]->shout_tell("[" + query_name() + ": " + ((str) ? str : "mumbles.") +
                      "]\n");
  }
  return 1;
}


/***************************************************************************/
/* id */

status id(string str) { return str == name; }

/***************************************************************************/
/* short */

string short() { return capitalize(name) + " in Debug"; }

void long() {
  write(short() + "\n");
}

/***************************************************************************/

string query_real_name() { return query_name(1); }


/***************************************************************************/
/* valid_write is called by edit(), write_file(), write_bytes() */

string valid_write(string str) {
  str = make_path(str);
/*
  if (str == "/obj/debug.c") return 0;
*/
  if (sscanf(str, "/usr/%s", str)) return 0; /* can't edit player files */
  if (sscanf(str, "/%s", str)) return str;   /* CAN edit everything else */
  return 0;
}

/***************************************************************************/
/* valid_read is called by file_size(), read_file(), read_bytes(), cat(),
 *                         tail()
 */

string valid_read(string str) {
  return valid_write(str);
}


/***************************************************************************/
/* look */

status look(string str, status extra) {
  object ob;
  status wiz;

  wiz = secure(SEC5);
  if (!str) {
    ob = environment();
  }
  else {
    sscanf(str, "at %s", str);
    sscanf(str, "in %s", str);
    if (environment()->look_at(str)) return 1;
    str = lower_case(str);
    if (!(ob = present(str, this_player()))) {
      if (!(ob = present(str, environment()))) {
        write("There is no " + str + " here.\n");
        return 1;
      }
    }
  }
  if (extra)
    ob->extra_long(wiz);
  else
    ob->long(wiz);
  if (!living(ob)) {
    int wt;

    wt = (int)ob->query_weight();
    if (wt >= 5)
      write("It looks very heavy.\n");
    else if (wt >= 3)
      write("It looks heavy.\n");
  }
  if (!ob->can_put_and_get(str)) return 1;
  ob->write_inventory(wiz);
  return 1;
}


/***************************************************************************/
/* who */

static status filter_users(object ob) {
  int sec, lvl;

  if (!environment(ob)) return 0;
  sec = (int)ob->query_security_level();
  lvl = (int)ob->query_level();
  if (sec) {
    if ((ob->query_invis() && sec <= security_level) || !ob->query_invis()) {
      return 1;
    }
  }
  else {
    if ((ob->query_invis() && (lvl <= level || security_level)) ||
        !ob->query_invis()) {
      return 1;
    }
  }
}

static status by_sec_level(object a, object b) {
  if ((int)a->query_security_level() == (int)b->query_security_level() &&
      (int)a->query_level() < (int)b->query_level())
    return 1;
  return ((int)a->query_security_level() < (int)b->query_security_level()) ?
                                                                         1 :
                                                                         0 ;
}

static status filter_wizards(object ob) {
  return (ob->query_security_level()) ? 1 : 0;
}

status who() {
  object *who;
  int i, num_wiz;
  string str;

  who = filter_array(users(), "filter_users", this_object());
  who = sort_array(who, "by_sec_level", this_object());

  /* Top line */

  str = "---- Welcome " + query_name() + " to ";
  str += "Nirvana -------------------------------------------------";
  str = extract(str, 0, 75);
  write(str + "\n");

  /* who list */

  for (i = 0; i < sizeof(who); i++) {
    if (!who[i]->query_security_level())
      str = "[ " + (string)who[i]->query_level() + " ]";
    else if ((int)who[i]->query_security_level() >= SEC9)
      str = "[ADMIN]";
    else if ((int)who[i]->query_security_level() >= SEC8)
      str = "[ARCH]";
    else if ((int)who[i]->query_security_level() >= SEC7)
      str = "[ELDER]";
    else if ((int)who[i]->query_security_level() >= SEC6)
      str = "[SENIOR]";
    else if ((int)who[i]->query_security_level() >= SEC5)
      str = "[LORD]";
    else if ((int)who[i]->query_security_level() >= SEC4)
      str = "[SAGE]";
    else if ((int)who[i]->query_security_level() >= SEC3)
      str = "[CREATOR]";
    else if ((int)who[i]->query_security_level() >= SEC2)
      str = "[APPREN]";
    else
      str = "[ASPIR]";
    str += ".................";
    str = extract(str, 0, 11);
    if (who[i]->query_invis()) {
      str = "#" + str;
    }
    str += (who[i]->short())
        ? (string)who[i]->short()
        : (string)who[i]->query_name() + " " +
          (string)who[i]->query_title() + " " +
          (string)who[i]->query_al_title();
    str = extract(str, 0, 75);
    write(str + "\n");
  }

  /* Bottom line */

  who = filter_array(who, "filter_wizards", this_object());
  num_wiz = sizeof(who);
  if (i == 1) {
    str = "---- You are all alone ";
  }
  else {
    if (num_wiz - i == 1) {
      str = "---- There is 1 player ";
    }
    else {
      str = "---- There are " + (num_wiz-i) + " players ";
    }
    if (num_wiz == 1)
      str += "and 1 creator ";
    else
      str += "and " + num_wiz + " creators ";
  }
  str += "-------------------------------------------------------------";
  str = extract(str, 0, 75);
  write(str + "\n");
  return 1;
}


/***************************************************************************/
/* local cmds */

static status local_commands() {
  localcmd();
  return 1;
}

/***************************************************************************/
/* tell */

static status tell(string str) {
  object ob;
  string who, msg;

  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Usage: tell <who> <msg>\n");
    return 1;
  }
  ob = find_living(lower_case(who));
  if (!ob ||
      (ob->query_invis() && security_level < (int)ob->query_security_level())) {
    write("No player with that name.\n");
    return 1;
  }
  if (security_level < (int)ob->query_security_level() && ob->query_edit()) {
    write("Sorry, that person is editing.  Please use mail if important.\n");
    return 1;
  }
  tell_object(ob, query_name() + " tells you: " + msg + "[0m\n");
  write("You tell " + capitalize(who) + ": " + msg + "\n");
  return 1;
}


/***************************************************************************/
/* Mud logon - calls logon() first */

static void time_out() {
  write("Time out\n");
  destruct(this_object());
}

static status logon() {
  write("Nirvana...\n");
  write("Please enter your name.......> ");
  input_to("logon2");
  call_out("time_out", 120);
  return 1;
}

static void logon2(string str) {
  int i, length;

  if (!str || str == "") {
    remove_call_out("time_out");
    destruct(this_object());
    return;
  }
  str = lower_case(str);
  name = str;
  restore_object(WIZARD + name);
  if (!secure(SEC5)) {
    write("\n\nSorry. 'Nirvana' has had a break down!!\n");
    remove_call_out("time_out");
    destruct(this_object());
    return;
  }
  write("Please enter unique password > ");
  input_to("check_password", 1);
  return;
}

static void check_password(string p) {
  write("\n");
  if (++password_check > PASSWORD_CHECK) {
    write("\nThat was your last try!\n");
    remove_call_out("time_out");
    destruct(this_object());
    return;
  }
  if (!p || p == "") {
    write("Please enter your unique password > ");
    input_to("check_password", 1);
    return;
  }
  if (!password) {
    remove_call_out("time_out");
    destruct(this_object());
    return;
  }
  if (crypt(p, password) != password) {
    write("\nWrong password!" +
          " (You have " + (PASSWORD_CHECK - password_check) +
          " attempts left) > ");
    input_to("check_password", 1);
    return;
  }
  remove_call_out("time_out");
  logon3();
}

static void logon3() {
  string tmp_name;

  tmp_name = name;
  name = 0;
  other_copy = find_player(tmp_name);
  name = tmp_name;
  if (other_copy) {
    write("Your character seems to already be in the game!\n");
    write("Throw that copy out, and log back in? (y/n) > ");
    input_to("logon9_throw_out_other_copy");
    return;
  }
  write("         !! PLAYER OBJECTS ARE CORRUPTED !!\n\n");
  write("You are using the default debug object, and have been given access\n" +
        "to fix the problem.  The Admin are putting trust in your hands. If\n" +
        "you don't feel confident that you can fix the proglem, then leave\n" +
        "it until an Admin Creator arrives.\n\n" +
        "The Basic setup is that obj/wizard inherits obj/player which\n" +
        "inherits inherit/base/living which inherits inherit/base/base_obj\n" +
        "The corruption will be in one of those objects.\n\n" +
        "You are currently using obj/debug.  This only allows 'Lords' or\n" +
        "greater to login.  Debug only has a limited number of commands,\n" +
        "use 'localcmd' to get a list.\n\n" +
        "Player Object Error: " + error_msg + "\n");
  enable_commands();
  set_living_name(lower_case(name));
  add_standard_commands();
  current_path = "players/" + name;
  if (catch(move_player("X#room/church"))) move_player("X#room/void");
}

static void logon9_throw_out_other_copy(string str) {
  if (str == "" || (str[0] != 'y' && str[0] != 'Y')) {
    write("Welcome another time then!!\n");
    destruct(this_object());
    return;
  }
  logon3();
}


/***************************************************************************/
/* The reverse of logging on */

status quit() {
  destruct(this_object());
  return 1;
}


/***************************************************************************/
/* A NO valid_read() restricted file_size */

static int FILE_SIZE(string file) {
  return (int)"obj/master"->master_file_size(file);
}


/***************************************************************************/
/* shout_tell - called from check_shout() */

varargs void shout_tell(string str, string lang) {
  tell_object(this_object(), str);
}


/***************************************************************************/
/* cat */

status cat_file(string path) {
  if (!path) return 0;
  path = make_path(path);
  if (!cat(path)) return 0;
  return 1;
}



/***************************************************************************/
/* security level routines */

status security(int sec_level) {
  if (!query_ip_number(this_player())) return 0;
  return ((int)this_player()->query_security() >= sec_level ||
          this_player() == this_object()) ? 1 : 0;
}

status secure(int sec_level) {
  if (!query_ip_number(this_player())) return 0;
  return ((int)this_player()->query_security() >= sec_level) ? 1 : 0;
}

int query_security() {
  return security_level;
}

int query_security_level() {
  return security_level;
}


/***************************************************************************/
/* ls */

static status dir(string str) {
  int i, start;
  status verbose;
  string tmp1, tmp2;
  string path, file;

  if (!str) str = "";

  /* scan for help */

  if (sscanf(str, "%s-h%s", tmp1, tmp2)) {
    write("Usage: dir { options: <path><-#><-v><-h> }\n\n" +
          "Notes: writes out list of files.\n" +
          "       <path> directory path, or wildcard filename\n" +
          "       <-#>   start file list after file number#\n" +
          "       <-v>   list files in verbose mode\n" +
          "       <-h>   this help file\n");
    write("       Example: dir / -3-v\n");
    return 1;
  }

  /* scan for verbose */

  if (sscanf(str, "%s-v%s", tmp1, tmp2)) {
    str = tmp1;
    if (str != "") {
      while(str[strlen(str)-1] == ' ') {
        str = extract(str, 0, strlen(str)-2);
      }
    }
    str += tmp2;
    verbose = 1;
  }

  /* scan for start number */

  line = 0;
  if (sscanf(str, "%s-d%d", tmp1, line)) {
    if (tmp1 != "") {
      while(tmp1[strlen(tmp1)-1] == ' ') {
        tmp1 = extract(tmp1,0,strlen(tmp1)-2);
      }
    }
    str = tmp1;
  }

  /* has wizard|player got read access */

  if (!(str = valid_read(str))) {
    write("No directory access\n");
    return 1;
  }
  str = "/" + str;

  /* extract path and filename */

  for (i = strlen(str) - 1; (str[i] != '/' && i >= 0); i--);
  new_text = extract(str, 0, i);
  file = extract(str, i+1, strlen(str));

  if (!file || file == ".") file = "";
  if (file_size(new_text + file) == -2) {
    new_text += file;
    if (new_text[strlen(new_text)-1] != '/') new_text += "/";
    if (!valid_read(new_text)) {
      write("No directory access: " + new_text + "\n");
      return 1;
    }
    list = get_dir(new_text + ".");
  }
  else {
    list = get_dir(new_text + file);
  }
  line = 0;

  if (!(list || sizeof(list))) {
    write("No match for " + str + ".\n");
    return 1;
  }
  if (verbose)
    print_verbose("");
  else
    print_files("");
  return 1;
}

static void print_files(string answer) {
  string name;
  int i, finish, columns;

  if (answer == "n") {
    write("Ok.\n");
    return;
  }
  sscanf(answer, "%d", line);

  if (line >= sizeof(list)) line = sizeof(list) - 52;
  if (line < 0) line = 0;
  finish = line + 52;
  if (finish > sizeof(list)) finish = sizeof(list);

  write("Current Path: /" + ((current_path == "") ? "\n" : current_path +
        "/\n"));
  if (new_text != "/" + current_path + "/") {
    if (current_path != "" || (current_path == "" && new_text != "/")) {
      write("     ls Path: " + new_text + "\n");
    }
  }
  write("\n");
  for (i = line; i < finish; i++) {
    if (!valid_read(new_text + list[i])) {
      name = "?????                                            ";
    }
    else if (file_size(new_text + list[i]) == -2) {
      if (!valid_read(new_text + list[i] + "/"))
        name = "?????/                                              ";
      else
        name = list[i] + "/                                    ";
    }
    else {
      if (!find_object(new_text + list[i]))
        name = list[i] + "                                   ";
      else
        name = "*" + list[i] + "                                    ";
    }

    name = extract(name, 0, 16);
    if (++columns > 4) {
      columns = 1;
      write("\n");
    }
    write(name);
  }
  if (finish != sizeof(list)) {
    line = finish;
    write("\n(" + (line+1) + "-" + finish + ")/" + sizeof(list) + " Files\n");
    write("\nContinue (y/n/#num) [y]: ");
    input_to("print_files");
    return;
  }
  write("\nOk.\n");
}

static void print_verbose(string answer) {
  string name, date;
  int i, finish;
  int f_size;

  if (answer == "n") {
    write("Ok.\n");
    return;
  }
  sscanf(answer, "%d", line);

  if (line >= sizeof(list)) line = sizeof(list) - 16;
  if (line < 0) line = 0;
  finish = line + 16;
  if (finish > sizeof(list)) finish = sizeof(list);

  write("Current Path: /" + ((current_path == "") ? "\n" : current_path +
        "/\n"));
  if (new_text != "/" + current_path + "/") {
    if (current_path != "" || (current_path == "" && new_text != "/")) {
      write("     ls Path: " + new_text + "\n");
    }
  }
  write("\n");
  for (i = line; i < finish; i++) {
    if (!valid_read(new_text + list[i])) {
      name = "?????                                              ";
      name = extract(name, 0, 17) + " Size: Unknown                       ";
      name = extract(name, 0, 36) + " Access: None\n";
    }
    else if ((f_size = file_size(new_text + list[i])) == -2) {
      if (!valid_read(new_text = list[i] + "/")) {
        name = "?????/                                           ";
        name = extract(name, 0, 17) + " Size: Unknown                       ";
        name = extract(name, 0, 36) + " Access: None\n";
      }
      else {
        string *tmp_dir;

        name = list[i] + "/                                    ";
        name = extract(name, 0, 17) + " Size: ";
        tmp_dir = get_dir(new_text + list[i] + "/.");
        if (!tmp_dir) tmp_dir = ({});
        name += sizeof(tmp_dir) + " Files\n";
      }
    }
    else {
      if (!find_object(new_text + list[i]))
        name = list[i] + "                                   ";
      else
        name = "*" + list[i] + "                                    ";
      name = extract(name, 0, 17)+" Size: " +f_size+ " bytes                  ";
      if (valid_write(new_text + list[i]))
        name = extract(name, 0, 36) + " Access: Read/Write";
      else
        name = extract(name, 0, 36) + " Access: Read Only";
      name += "\n";
    }
    write(name);
  }
  if (finish != sizeof(list)) {
    line = finish;
    write("\n(" + (line+1) + "-" + finish + ")/" + sizeof(list) + " Files\n");
    write("Continue (y/n/#num) [y]: ");
    input_to("print_verbose");
    return;
  }
  write("Ok.\n");
}


/***************************************************************************/
/* edit */

static status edit(string file) {
  string tmp_file;

  if (!file) {
    ed();
    return 1;
  }
  if (!(file = valid_write(file))) {
    write("Sorry, Access denied.\n");
    return 1;
  }
  log_file("DEBUG", name + " edited " + file + " at " + ctime(time()) + "\n");
  ed(file);
  return 1;
}


/***************************************************************************/
/* update */

static status update(string str) {
  object ob;

  if (!str) {
    write("Usage: update <object>\n");
    return 1;
  }
  str = make_path(str);
  sscanf(str, "%s.c", str);
  if (!(ob = find_object(str))) {
    write("Error: No such object.\n");
    if (FILE_SIZE(str + ".c") < 0) {
      write("       File " + str + ".c does not exist.\n");
    }
    return 1;
  }
  tell_object(this_object(),
              file_name(ob) + " will be loaded at next reference.\n");
  destruct(ob); /* note that master.c takes care of player if room dested */
  return 1;
}


/***************************************************************************/
/* load */

static status load(string str) {
  if (!str) {
    tell_object(this_object(), "Usage: load <file>\n");
    return 1;
  }
  str = make_path(str);
  sscanf(str, "%s.c", str);
  sscanf(str, "/%s", str);
  if (FILE_SIZE("/" + str + ".c") < 0) {
    tell_object(this_object(), "Error: Could not find /" + str + ".c\n");
    return 1;
  }
  call_other(str, "????"); /* load (force) into memory */
  tell_object(this_object(), "Loaded: " + str + ".\n");
  return 1;
}


/***************************************************************************/
/* clone */

static status clone(string file) {
  object ob;

  if (!file) {
    write("Usage: clone <filename>\n");
    return 1;
  }
  file = make_path(file);
  sscanf(file, "%s.c", file);
  sscanf(file, "/%s", file);
  if (FILE_SIZE("/" + file + ".c") < 0) {
    tell_object(this_object(), "File: " + file + ".c does not exist.\n");
    return 1;
  }
  ob = clone_object(file);
  write("Cloning: " + file + "\n");
  if (ob->get()) {
    move_object(ob, this_object());
    write("Object moved to you.\n");
  }
  else {
    move_object(ob, environment());
    write("Object moved to Room.\n");
  }
  return 1;
}


/***************************************************************************/
/* log */

static status show_log() {
  tail("/log/" + query_name(1));
  return 1;
}

/***************************************************************************/
/* mainlog */

static status show_main_log() {
  tail("/log/log");
  return 1;
}

/***************************************************************************/
/* debug log */

static status show_debug_log() {
  tail("/debug.log");
  return 1;
}


/***************************************************************************/
/* change directory */

static status cd(string str) {
  if (!str) str = "~"; /* change to player dir */
  str = make_path(str);
  if (FILE_SIZE(str) != -2) {
    write("Error: Directory not found.\n");
  }
  else {
    sscanf(str, "/%s", current_path);
  }
  tell_object(this_object(), "Current Path: /" + current_path + "\n");
  return 1;
}


/***************************************************************************/
/* tail */

status tail_file(string path) {
  if (!path) return 0;
  path = make_path(path);
  if (!tail(path)) return 0;
  return 1;
}


/***************************************************************************/
/* print working directory */

status pwd() {
  tell_object(this_object(), "Current path: /" + current_path + "\n");
  return 1;
}

