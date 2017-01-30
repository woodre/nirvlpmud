/***************************************************************************
  board.c -- a board to read and write notes on, improved version of former
             /std/new_board.c, written by Ugh for Tubmud (1995)
***************************************************************************/
#include <grammar.h>
#include <wizlevels.h>
#include <describe.h>
#include <prop/item.h>
#include <prop/player.h>
#include <server.h>
#include <message.h>
#include <describe.h>
#include <kernel.h>
#include <event.h>  // Coogan, 30-Mar-2002

inherit "basic/database";
static variables inherit "basic/parser";
static variables inherit "complex/item";

#define BOARD "<board>"
#define BOARD_NOTE "obj/board_note"// moved from std to obj, Coogan, 28-May-1998
#define BOARD_COUNTER_FLAG 17
#define MAX_TITLE_LENGTH 45 

#define NOTE_TITLE "title"
#define NOTE_AUTHOR "author"
#define NOTE_LAST_CHANGE "last_change"
#define NOTE_MOVED "moved"
#define NOTE_FOLLOWUP_TO "followup_to"
#define NOTE_DATE "date"
#define NOTE_STICKY "sticky"
#define NOTE_READ "read"
#define NOTE_TITLE_CHANGED_BY "title_changed_by"
#define NOTE_CHANGED_BY "changed_by"

#define DAY 86400
#define WEEK 604800

int *note_keys = ({}), next_key = 1, last_write; 
static int admin_level = WL_ELDER;
static string topic = "nothing special", *administrators;
static int max_notes = 60, write_level, read_level;
static status verbose;
static object creator_object;
static mixed gnome, clean; // reset and clean-up messages

void set_verbose(status v);
void set_max_notes(int n);
void set_admins(string *admin);
void set_admin_level(int l);
void set_write_level(int l);
void set_read_level(int l);
void set_topic(string t);
void set_gnome(mixed g);
void set_clean(mixed c);

int query_admin_level();
int query_write_level();
int query_read_level();
int query_max_notes();

string query_topic();

static void   read_note(int note);  // status->void, Coogan, 12-Sep-2000
static void   read_note_and_followups(int note);
static status store_note(int note, string file);
static status move_note(int note, object board);
static varargs status remove_note(int note, status force);
static void mark_sticky(int note, status sticky);

static void edit(string text, closure callback);

public varargs status add_note(string text, mixed info, status force);

status author_of(int note, object who);
status is_admin(object who);
status write_permission(object who);
status read_permission(object who);

static status return_from_write_note(string text, string name, mixed info);
static void   return_from_edit_note(int key, string text, string name,
                                    mixed info);

private string full_board_long();
private string board_long();
private string board_short();
private string inscription_long();

static string database_retrieve(mixed key) {
  return unguarded(query_read_privilege(),#'retrieve,key);
}

static mixed database_get_info(mixed key) {
  return unguarded(query_read_privilege(),#'get_info,key);
}

static void database_store(mixed key,string text,mixed info) {
  return unguarded(query_set_privilege(),#'store,({key,text,info}));
}

static void database_delete(mixed key) {
  return unguarded(query_set_privilege(),#'delete,key);
}

static status database_exists(mixed key) {
  return unguarded(query_read_privilege(),#'exists,key);
}

string query_database() {
  return query_database_file();
}

varargs string set_database(string file, mixed set_priv, mixed read_priv) {
  mixed creator_priv;
  if (extern_call()) {
    creator_priv = SECURITY->query_protection(creator_object,1);
    if (previous_object() == creator_object && 
        function_exists("board_room",creator_object) &&
        SECURITY->higher_privilege(creator_priv,
                                   SECURITY->query_protection(file,1)))
      unguarded(creator_priv,#'load_database,
                ({file,creator_priv,set_priv,read_priv}));
  }
  else {
    creator_priv =
      SECURITY->reduced_privilege(1,
                                  SECURITY->query_protection(this_object(),1));
    unguarded(creator_priv,#'load_database,
              ({file,creator_priv,set_priv,read_priv}));
  }
  return query_database();
}

void notify_move(object from, object to) {
  if (to && topic != "nothing special" && query_database()) 
    SE_BOARDS->notify_board();
}

status prevent_move(object from, mixed to) {  // mixed, Coogan, 29-Sep-2010
  // if once moved, don't move again
  return !!from;
}

void notify_change() {
  if (environment() && topic != "nothing special")
    SE_BOARDS->notify_change();
  last_write = time();
}

void configure() {
  item::configure();
  if (creator_object)
    return;
  creator_object = previous_object();
  set_id(({"board", "bulletin board"}));
  set_short(#'board_short);
  set_long(#'board_long);
  add_item("whole board", #'full_board_long);
  add_item(({"inscription", "tiny inscription","board inscription"}), 
              #'inscription_long);
  add_item("rim", "You can see a tiny inscription there.\n");
  set_gnome(({({"A small gnome appears and secures some notes on the "
                "board that were loose."}),
              ({"The gnome leaves again."})}));
  set_clean(({({ "A small gnome appears and takes ",
                 M_ARG, "removed_notes", " from the board." }),
              ({ "The gnome leaves again." })}));
  set_property(P_NOT_PORTABLE);
  add_class(BOARD, "parse_board");
  add_rule("list notes", "list_notes");
  add_rule("read note <number>", "read_notes");
  add_rule("read notes <numbers>", "read_notes");
  add_rule("read <numbers>", "read_notes");
  add_rule("read note <number> and followups", "read_notes_followups");
  add_rule("read notes <numbers> and followups", "read_notes_followups");
  add_rule("read <numbers> and followups", "read_notes_followups");
  add_rule("remove note <number>", "remove_notes");
  add_rule("remove notes <numbers>", "remove_notes");
  add_rule("remove <numbers>", "remove_notes");
  add_rule("reply to note <number>", "followup");
  add_rule("reply to <number>", "followup");
  add_rule("reply <number>", "followup");
  add_rule("followup note <number>", "followup");
  add_rule("followup <number>", "followup");
  add_rule("store note <number> in <text>", "store_notes");
  add_rule("store notes <numbers> in <text>", "store_notes");
  add_rule("store <numbers> in <text>", "store_notes");
  add_rule("move note <number> to <board>", "move_notes");
  add_rule("move notes <numbers> to <board>", "move_notes");
  add_rule("move <numbers> to <board>", "move_notes");
  add_rule("note <text>", "write_note");
  add_rule("write note <text>", "write_note");
  add_rule("change headline of note <number> to <text>", "edit_headline");
  add_rule("change headline of <number> to <text>", "edit_headline");
  add_rule("edit note <number>", "edit_note");
  add_rule("edit <number>", "edit_note");
  add_rule("change note <number>", "edit_note");
  add_rule("change <number>", "edit_note");
  add_rule("mark note <number> as sticky","mark_sticky");
  add_rule("mark note <number> as not sticky","mark_not_sticky");
  add_rule("mark notes <numbers> as sticky","mark_sticky");
  add_rule("mark notes <numbers> as not sticky","mark_not_sticky");
  add_rule("mark <numbers> as sticky","mark_sticky");
  add_rule("mark <numbers> as not sticky","mark_not_sticky");
}

void init() {
  add_actions();
}

status parse_board(mixed res, mixed aux, int f, int l, string *w, string *t) {
  res = find_object(implode(t[2*f+1..2*l+1], ""));
  return !!res;
}

private status check_note_number(int number) {
  return (number > 0 && number <= sizeof(note_keys));
}

private string get_title(int n) {
  return database_get_info(note_keys[n-1])[NOTE_TITLE];
}

private string show_time(int t) {
  string h;
  h = ctime(t);
  switch (time()/DAY - t/DAY) {
  case 0:                       // same day, display the time of the writing
    return h[11..15];
  case 1:                       // next day, display weekday and time
    return h[0..3]+h[11..15];
  case 2..6:                    // for the rest of the week, show the weekday
    return h[0..2];
  case 7..365:                  // for the rest of the year show month and day
    return h[4..9];
  default:                      // after one year, show month day and year
    return h[4..10]+h[20..23];  // fixed to 20..23, Coogan, 23-Mar-1999
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

private string inscription_long() {
  return 
    "The tiny, barely readable inscription reads: How to use this board?\n"
    "You may 'read <notes> [and followups]', 'write note <title>' or \n"
    "just 'note <headline>', 'reply to <note>' or 'followup <note>',\n"
    "'edit <notes>', 'change headline of <note> to <headline>' and\n"
    "'remove <notes>' will remove one of your own notes,\n" + 
    "'mark <notes> as [not] sticky' will prevent the notes from [not] \n" +
    "being removed (automatically or otherwise).\n" +
    (this_player()->query_level() >= WL_WIZARD ? 
    "You may also 'store <notes> in <file>' and \n"
    "'move <notes> to <other_board>.\n" : "");
}

mixed apply_action(string action,int level, mapping arg) {
  switch (action) {
  case "read":
    if (arg[E_TARGET] == this_object())
      write(long(arg[E_ID]));
    break;
  default:
    return 0;
  }
  return 1;
}

mixed do_action(string verb, mapping args) {
  int i, number, *numbers;
  mixed tmp, title;
  if (m_contains(&number, &tmp, args, G_NUMBER)) 
    args[G_NUMBERS] = ({number});
  numbers = args[G_NUMBERS];
  if (numbers)
  {
    tmp = numbers - filter(numbers, #'check_note_number);
    numbers -= tmp;
    if (sizeof(tmp))
      write("There is no note with the number "+
             make_list(map(tmp, #'to_string), 0, " or ")+
             " on this board.\n");
    if (!sizeof(numbers)) return 1;
  }
  switch (verb) {
  case "list_notes":
    if (!read_permission(this_player())) {
      write("Sorry, you cannot list the notes on this board.\n");
      return 1;
    }
    write(long());
    return 1;
  case "mark_sticky":
    if (!is_admin(this_player())) {
      write("You are not allowed to do that.\n");
      break;
    }
    map(numbers, #'mark_sticky, 1);
    if (verbose)
      send_message(({ M_PL_THE, M_PL_VERB, "mark",
                      " ", describe("note",ARTICLE_THE,0,sizeof(numbers)), " ",
#if 0  // Coogan, 13-Mar-2002
                      numbers,
#else
                      make_list(map(numbers, (: return "" + $1; :)), "and"),
#endif
                      " on ", M_OBJECT, M_ME_THE," as sticky." }));
    else
      write("Ok.\n");
    break;
  case "mark_not_sticky":
    if (!is_admin(this_player())) {
      write("You are not allowed to do that.\n");
      break;
    }
    map(numbers, #'mark_sticky, 0);
    if (verbose)
      send_message(({ M_PL_THE, M_PL_VERB, "mark",
                      " ",describe("note",ARTICLE_THE,0,sizeof(numbers))," ",
#if 0  // Coogan, 13-Mar-2002
                      numbers,
#else
                      make_list(map(numbers, (: return "" + $1; :)), "and"),
#endif
                      " on ", M_OBJECT, M_ME_THE," as not sticky." }));
    else
      write("Ok.\n");
    break;
  case "read_notes":
    if (!read_permission(this_player())) {
      write("Sorry, you cannot read any notes on this board.\n");
      return 1;
    }
    map(numbers, #'read_note);
    if (verbose)
      message(({ ({ M_SAY,M_PL,M_PL_VERB,"read"," ",  // Alfe 1996-Sep-29
                    describe("note", ARTICLE_A, 0, sizeof(numbers)),
                    (" on the bulletin board: '"+
                     make_list(map(numbers, #'get_title),0,"' and '",
                               "', '")),
                    "'." }) }));
    this_player()->start_view();
    break;
  case "read_notes_followups":
    if (!read_permission(this_player())) {
      write("Sorry, but you are not allowed to read notes on this board.\n");
      return 1;
    }
    map(numbers, #'read_note_and_followups);
    if (verbose)
      message(({ ({ M_SAY,M_PL,M_PL_VERB,"read"," ",  // Alfe 1996-Sep-29
                    describe("note", ARTICLE_A, 0, sizeof(numbers)),
                    (" on the bulletin board: '"+
                     make_list(map(numbers, #'get_title),0,"' and '",
                               "', '")),
                    "' and the followups." }) }));
    this_player()->start_view();
    break;
  case "remove_notes":
    // remove multiple occurences 
    numbers = m_indices(tmp = mkmapping(numbers)); 
    numbers = sort_array(numbers, #'>);
    tmp = mkmapping(numbers,numbers);
    for (i = sizeof(numbers); i; i--) {
      if (remove_note(tmp[numbers[<i]])) {
        m_delete(tmp,numbers[<i]);
        tmp = mkmapping(m_indices(tmp),map(m_values(tmp),#'-,1));
      }
    }
    tmp = filter(numbers,tmp);
    if (sizeof(tmp))
      write(break_string("Sorry, couldn't remove "+
             describe("note", ARTICLE_THE, 0, sizeof(tmp))+": "+
             make_list(map(tmp, #'to_string))+".\n", 78));
    numbers -= tmp;
    if (verbose && sizeof(numbers))
      message(({({M_PL,M_PL_VERB,"remove",
                  " "+describe("note",ARTICLE_NONE,0,sizeof(numbers)),
                  " from ",M_OBJECT,M_ME_THE,"."})}));
    if (sizeof(numbers))
      write("Ok.\n");
    unguarded(query_privilege(),#'save_database);
    break;
  case "store_notes":
    numbers = m_indices(mkmapping(numbers)); // remove multiple occurences 
    numbers = sort_array(numbers,#'>);
    tmp = numbers - filter(numbers, #'store_note, args[G_TEXT]);
    if (sizeof(tmp))
      write(break_string("Sorry, but I couldn't store "+
              describe("note", ARTICLE_THE, 0, sizeof(tmp))+" "+
              make_list(map(tmp, #'to_string))+".\n",78));
    if (sizeof(numbers - tmp))
      write("Ok.\n");
    break;
  case "move_notes":
    numbers = m_indices(mkmapping(numbers)); // remove multiple occurences 
    numbers = sort_array(numbers,#'>);
    tmp = mkmapping(numbers,numbers);
    for (i = sizeof(numbers); i; i--) {
      if (move_note(tmp[numbers[<i]],args[BOARD])) {
        m_delete(tmp,numbers[<i]);
        tmp = mkmapping(m_indices(tmp),map(m_values(tmp),#'-,1));
      }
    }
    tmp = filter(numbers,tmp);
    if (sizeof(tmp))
      write(break_string("Sorry, but I couldn't move "+
              describe("note", ARTICLE_THE, 0, sizeof(tmp))+" "+
              make_list(map(tmp, #'to_string))+" to the board "+
              object_name(args[BOARD])+".\n",78));
    unguarded(query_privilege(),#'save_database);
    if (sizeof(numbers - tmp))
      write("Ok.\n");
    break;
  case "followup":
    if (!write_permission(this_player())) {
      write("Sorry, but you are not allowed to write notes on this board.\n");
      return 1;
    }
    if (sizeof(note_keys) >= max_notes) {
      write("Sorry, but the board is full.\n");
      return 1;
    }
    title = database_get_info(note_keys[number-1]);
    if (title[NOTE_FOLLOWUP_TO] > 0) {
      if (sscanf(title[NOTE_TITLE], "Re: %s", title) == 1)
        title = "Re^2: "+title;
      else if (sscanf(title[NOTE_TITLE], "Re^%d: %s", i, title) == 2)
        title = "Re^"+(i+1)+": "+title;
      else title = "Re: "+title[NOTE_TITLE];
    }
    else title = "Re: "+title[NOTE_TITLE];
    edit("", lambda(({'name, 'text}), 
                      ({#'return_from_write_note, 
                        'text, 
                        'name,
                        ([NOTE_AUTHOR:
                            this_player()->query_real_name(),
                          NOTE_TITLE: title,
                          NOTE_FOLLOWUP_TO: note_keys[number-1]
                        ]),
                      })));
    if (verbose)
      say(break_string(capitalize(describe(this_player()))+
                         " starts writing a note.\n", 78), this_player());
    break;
  case "write_note":
    if (!write_permission(this_player())) {
      write("Sorry, but you are not allowed to write notes on this board.\n");
      return 1;
    }
    if (sizeof(note_keys) >= max_notes) {
      write("Sorry, but the board is full.\n");
      return 1;
    }
    if (strlen(args[G_TEXT]) > MAX_TITLE_LENGTH) {
      write("Please choose a shorter title!\n");
      return 1;
    }
    edit("", lambda(({'name, 'text}), 
                      ({#'return_from_write_note, 
                        'text, 
                        'name, 
                        ([NOTE_AUTHOR: 
                            this_player()->query_real_name(), 
                          NOTE_TITLE: args[G_TEXT], 
                        ]),
                      })));
    if (verbose)
      say(break_string(capitalize(describe(this_player()))+
                       " starts writing a note.\n", 78),this_player());
    break;
  case "edit_note":
    if (!write_permission(this_player())) {
      write("Sorry, but you are not allowed to write notes on this board.\n");
      return 1;
    }
    if (!(check_privilege(1) || author_of(number, this_player()))) {
      write("Sorry, but you can't change other peoples' notes.\n");
      return 1;
    }
    edit(database_retrieve(note_keys[number-1]), 
          lambda(({'name, 'text}), 
                 ({#'return_from_edit_note, 
                   note_keys[number-1],
                   'text, 
                   'name, 
                   (title = database_get_info(note_keys[number-1])), 
                 })));
    if (verbose)
      say(break_string(capitalize(describe(this_player()))+
                         " starts editing a note titled '"+
                         title[NOTE_TITLE]+"'.\n", 78), this_player());
    break;
  case "edit_headline":
    if (!author_of(number, this_player())) {
      write("Sorry, but you can't change the headline of other peoples' "
             "notes.\n");
      return 1;
    }
    if (strlen(args[G_TEXT]) > MAX_TITLE_LENGTH) {
      write("Please choose a shorter title!\n");
      return 1;
    }
    tmp = note_keys[number-1];
    title = database_get_info(tmp)[NOTE_TITLE];
    change_info(tmp,lambda(({'info}),
                           ({#'+=,
                               'info,
                               ([NOTE_TITLE: args[G_TEXT], 
                                 NOTE_LAST_CHANGE: time(),
                                 NOTE_TITLE_CHANGED_BY : 
                                   this_player()->query_real_name()])
                           })));
    if (verbose)
      say(break_string(capitalize(describe(this_player()))+ 
                        " changes the headline of the note titled '"+
                        title+"' to '"+args[G_TEXT]+
                        "'.\n", 78), this_player());
    write("Ok.\n");
    notify_change();
    break;
  default:
    return 0;
  }
  return 1;
}

static void edit(string text, closure callback) {
  if (this_player()->query_property(P_ED_USER)) {
    "etc/editor"->edit_temp(text, callback);
    write("type h for help, leave insert mode with '.', abort with 'q' "
            "or 'Q'\nand leave savingly with 'x'.\n");
  }
  else
    clone_object(BOARD_NOTE)->edit_note(text, callback);
}

private string header() {
  if (verbose)
    say(capitalize(describe(this_player()))+ " studies "+
         describe(this_object(), ARTICLE_THE)+".\n", this_player());
  return break_string(
          "This is a bulletin board where you may write notes concerning "+
          topic+". "+
         "There is a tiny inscription scribbled on the rim of the board, "
         "which might even be readable.\n" + 
         (this_player()->query_level() >= WL_APPRENTICE ? 
          "Removed notes are stored in "+query_database()+".b.\n" : ""), 78) +
          "\n";
}

string get_title_info(mapping info) {
  return 
    " (" + 
    capitalize(info[NOTE_AUTHOR]) + ", " +
    show_time(info[NOTE_LAST_CHANGE]||info[NOTE_DATE]) +
    ")";
}

string list_notes(int count) {
  status counter;
  int begin, i, l;
  mixed info;
  string n, result;
  if (count < sizeof(note_keys)) begin = sizeof(note_keys) - count;
  else begin = 0;
  if (!read_permission(this_player()))
    return "Strangely enough, you can see no notes.\n";
  result = "";
  counter = this_player()->test_flag(BOARD_COUNTER_FLAG);
  l = strlen(to_string(sizeof(note_keys)));
  for (i = begin; i < sizeof(note_keys); i++) {
    info = database_get_info(note_keys[i]);
    if (!mappingp(info))
      continue;
    n = to_string(i+1);
    n = "                      "[0..l-strlen(n)]+n;
    result += n + ": " + info[NOTE_TITLE]+ get_title_info(info) + 
              (counter && info[NOTE_READ] ? " ("+info[NOTE_READ]+")" : "") +
              "\n";
  }
  return result;
}

private string board_long() {
  return header() + list_notes(15);
}

private string board_short() {
  return "bulletin board on "+query_topic();
}

private string full_board_long() {
  return header() + list_notes(sizeof(note_keys));
}

static varargs void read_text(int key, int note) {
  string text;
  mixed info;
  text = database_retrieve(key);
  info = database_get_info(key);
  this_player()->view_text(info[NOTE_TITLE]+get_title_info(info)+
                             "\n\n"+text+
                             (note ? "[end of note "+note+"]\n" : "")+
                             (note == sizeof(note_keys) ? 
                              "[no more notes]\n" : ""), 
                             info[NOTE_TITLE]);
  info[NOTE_READ]++;
  change_info(key,lambda(({'info}),({#'=,'info,info})));
}

static void read_note(int note) {
  read_text(note_keys[note-1], note);
}

static void read_note_and_followups(int note) {
  mixed *keys, info;
  int i, j, following_up_to;
  for (i = 0, keys = ({note_keys[note-1]}); i < sizeof(keys); i++) {
    following_up_to = keys[i];
    for (j = following_up_to + 1; j < next_key; j++) {
      info = database_get_info(j);
      if (info && info[NOTE_FOLLOWUP_TO] == following_up_to)
        keys += ({j});
    }
  }
  map(keys, #'read_text);
}

static status store_note(int number, string file) {
  mixed key, info;
  if (sizeof(explode(file, " ")) > 1)
    return 0;
  key = note_keys[number-1];
  info = database_get_info(key);
  return unguarded(1, #'write_file, 
                    ({file, "\nAuthor: "+ info[NOTE_AUTHOR] +"\n" +
                            "Title: " + info[NOTE_TITLE] + "\n" +
                            "Written: "+
                              ctime(info[NOTE_LAST_CHANGE]||info[NOTE_DATE])+
                              "\n\n" +
                            database_retrieve(key)+"\n"}));
}

static void mark_sticky(int number,status u) {
  if (u)
    change_info(note_keys[number-1],
                lambda(({'info}),
                       ({#'+=,'info,([NOTE_STICKY : 1])})));
  else
    change_info(note_keys[number-1],
                lambda(({'info}),({#'m_delete,'info,NOTE_STICKY})));
}

static varargs status remove_note(int number, status force) {
  int i;
  mixed key, info;
  if (!force && 
      !(is_admin(this_player()) || 
        author_of(number, this_player()))) 
    return 0;
  key = note_keys[number-1];
  info = database_get_info(key);
  if (info[NOTE_STICKY])
    return 0;
  if (force || !author_of(number,this_player()) ||
      time() - (info[NOTE_LAST_CHANGE]||info[NOTE_DATE]) > 86400) 
      // more than one day old
    store_note(number,query_database_file()+".b");
  database_delete(key);
  note_keys = exclude_element(note_keys, number-1);
  return 1;
}

static status move_note(int number, object board) {
  if (!(is_admin(this_player()) ||
        author_of(number, this_player()))) 
    return 0;
  if (board->add_note(database_retrieve(note_keys[number-1]), 
                       database_get_info(note_keys[number-1]))) {
    database_delete(note_keys[number-1]);
    note_keys = exclude_element(note_keys, number-1);
    return 1;
  }
}

public varargs status add_note(string text, mixed info, status force) {
  if (!force && sizeof(note_keys) >= max_notes) 
    return 0;
  if (!(force || write_permission(this_player())))
    return 0;
  note_keys += ({next_key++});
  info[NOTE_MOVED] = time();
  database_store(next_key-1, text, info);
  notify_change();
  return 1;
}

static status return_from_write_note(string text, string name, mixed info) {
  if (text == "") {
    write("Aborted.\n");
    if (verbose)
      say(capitalize(describe(this_player()))+" aborted writing a note.\n", 
           this_player());
    return 0;
  }
  else {
    note_keys += ({next_key++});
    info[NOTE_DATE] = time();
    unguarded(query_set_privilege(), #'database_store, 
               ({next_key-1, text, info}));
    write("Ok.\n");
    if (verbose)
      say(break_string(capitalize(describe(this_player()))+
                         " finished writing a note titled '"+
                         info[NOTE_TITLE]+"'.\n", 78), this_player());
    notify_change();
    return 1;
  }
}

// status -> void, Coogan, 12-Sep-2000
static void return_from_edit_note(int key, string text, string name,
                                  mixed info) {
  info[NOTE_LAST_CHANGE] = time();
  if (name != info[NOTE_AUTHOR])
    info[NOTE_CHANGED_BY] = name;
  if (!database_exists(key))
    add_note(text,info,1);
  else
    unguarded(query_set_privilege(), #'database_store, 
               ({key, text, info}));
  write("Ok.\n");
  if (verbose)
    say(break_string(capitalize(describe(this_player()))+ 
                      " finished editing a note titled '"+
                      info[NOTE_TITLE]+"'.\n", 78), this_player());
  notify_change();
}

status author_of(int note, object player) {
  return player->query_real_name() == 
         database_get_info(note_keys[note-1])[NOTE_AUTHOR];
}

status is_admin(object player) {
  return interactive(player) && 
         (check_previous_privilege(1) || 
          query_admin_level() <= player->query_level() || 
          (administrators && 
           member(administrators, player->query_real_name()) > -1));
}

status write_permission(object player) {
  return
    check_previous_privilege(query_set_privilege()) &&
    query_write_level() <= player->query_level();
}

status read_permission(object player) {
  return 
    check_previous_privilege(query_read_privilege()) &&
    query_read_level() <= player->query_level();
}

void set_verbose(status v) {
  verbose = v;
}

void set_max_notes(int n) {
  if (previous_object() != creator_object && 
      !check_privilege(query_privilege()))
    return;
  max_notes = n;
}

int query_max_notes() {
  return max_notes;
}

void set_admins(string *admin) {
  if (previous_object() != creator_object)
    return;
  if (admin && !pointerp(admin))
    return;
  administrators = admin;
}

int query_admin_level() {
  return admin_level;
}

void set_admin_level(int l) {
  if (previous_object() != creator_object)
    return;
  admin_level = l;
}

string query_topic() {
  return topic;
}

void set_topic(string t) {
  if (previous_object() != creator_object)
    return;
  if (environment()) {
    if (topic != "nothing special")
      SE_BOARDS->remove_board(topic);
    SE_BOARDS->notify_board();
  }
  topic = t;
}

int query_messages() {
  return sizeof(note_keys);
}

string *query_titles() {
  int i;
  string *result;
  result = allocate(sizeof(note_keys));
  for (i = sizeof(note_keys); i; i--)
    result[i-1] = get_title(i);
  return result;
}

string *query_message_list() {
  return map(note_keys,#'database_retrieve);
}

int query_last_write() {
  return last_write;
}

void refresh() {
  int i, removed;
  mixed h;
  for (i = 0; 
       i < (h = query_messages()) && h > query_max_notes()-15; 
       i++) {
    h = database_get_info(note_keys[i]);
    if ((h = h[NOTE_LAST_CHANGE]||h[NOTE_DATE]) > WEEK) {
      if (remove_note(i+1,1)) {
        removed++;
        i--;
      }
    }
  }
  if (removed && clean)
    map(clean,#'send_message,
              // ARTICLE_NONE to _A, Coogan, 08-Sep-1998
              (["removed_notes":describe("note",ARTICLE_A,0,removed)]));
  else if (gnome && !random(5))
#if 0 // sunblood 28-jun-1999
    message(gnome);
#else
    if (stringp(gnome))
      tell_room(environment() || this_object(), break_string(gnome));
    else
      message(gnome);
#endif
        
}

void set_clean(mixed c) {
  if (previous_object() != creator_object)
    return;
  clean = c;
}

void set_gnome(mixed g) {
  if (previous_object() != creator_object)
    return;
  gnome = g;
}

void set_write_level(int l) {
  if (previous_object() != creator_object)
    return;
  if (l < 0)
    l = 0;
  write_level = l;
}

int query_write_level() {
  return write_level;
}

void set_read_level(int l) {
  if (previous_object() != creator_object)
    return;
  if (l < 0)
    l = 0;
  read_level = l;
}

int query_read_level() {
  return read_level;
}

object query_creator_object() {
  return creator_object;
}

string *query_boards() {
  return SE_BOARDS->query_boards();
}
