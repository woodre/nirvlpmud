/*
 * Muditor
 * A fullscreen editor in LPC to be used in the mud
 * You need to use a frontend which is capable of character based telnet
 * connections to use this. The unix-program 'telnet' does this.
 */

#include <kernel.h>
#include <ctype.h>
#include <closures.h>
#include <kernel.h>
#include <is_wizard.h>
#include <prop/item.h>

#include <cntl_sequences.h>

inherit "complex/item";
inherit "basic/path";
inherit "basic/autoload";
inherit "basic/tools/output";
inherit ACCESS;

#define JUMP_X 8
#define JUMP_Y 4

private string file;
private string *lines;
private int row,column,max_row,max_column,scroll_row,scroll_column;
private int virtual_column;
private status changed,readonly,unreadable;

void create() {
  set_privilege(1);
  output::create();
  item::create();
}

void configure() {
  item::configure();
  set_id(({ "muditor","editor","edit","tool" }));
  set_short("a muditor");
  set_long("This is a muditor, a fullscreen editor for the mud. To use it"
           " one has to use a frontend which is capable of character based"
           " telnet connections.\n"
           "Usage: mudit [<file>]\n");
  set_property(P_NOT_DROPPABLE);
}

void init() {
  add_action("mudit","mudit");
}

void exit_editor() {
  write(CS_GOTO(999,1) CS_WRAP_ON"\n");
}

static void get_coords(string input,closure callback,string sequence) {
  mixed h;
  int row,column;
  sequence += input;
  if (sscanf(sequence,"\e[%d;%dR%s",row,column,h)==3 && h=="")
    funcall(callback,row,column);
  else if (strlen(sequence) > 9) {
    exit_editor();
    raise_error("Client didn't report cursor position\n");
  }
  else
    input_to("get_coords",3,callback,sequence);
}

void receive_screen_size(int r,int c,closure callback) {
  max_row = r;
  max_column = c;
  funcall(callback);
}

void set_screen_size(closure callback) {
#define NO_POS_QUERY
#ifdef NO_POS_QUERY
  max_row = 24;
  max_column = 80;
  funcall(callback);
#else
  write(CS_GOTO(999,999) CS_GET_COORDS);
  input_to("get_coords",3,lambda(({ 'r,'c }),
                                 ({ (#'receive_screen_size),'r,'c,callback })),
           "");
#endif
}

void init_editor(closure callback) {
  write(CS_WRAP_OFF);
  set_screen_size(callback);
}

void remove_message() {
  write(CS_SAVE_CURSOR CS_GOTO(max_row,1) CS_CLEAR_RIGHT CS_RESTORE_CURSOR);
}

void display_message(string msg) {
  printf(CS_SAVE_CURSOR CS_GOTO(max_row,1)"%:-*s"CS_RESTORE_CURSOR,
         max_column-1,msg);
  remove_call_out("remove_message");
  call_out("remove_message",10);
}

void display_status() {
  printf(CS_SAVE_CURSOR CS_GOTO(max_row-1,1) CS_INVERSE"%:'-'-*s"
         CS_NORMAL_MODE CS_RESTORE_CURSOR,max_column,
         sprintf("--%s-Muditor: %s    L%d--C%d--%s",
                 (unreadable? "??" : readonly? "%%" : changed? "**" : "--"),
                 (file? mixed2string(file)[1..<2] : "(no name)"),row+1,column,
                 (scroll_row? scroll_row*100/sizeof(lines)+"%" : "Top")));
}

private status special_char(int char) {
  if (char < ' ')
    return char + 64;
  if (char == 127)
    return '?';
}

string prepare_line(string line,status current_line) {
  int i,my_scroll_column;
  status long_line;
  my_scroll_column = current_line? scroll_column : 0;
  if (my_scroll_column)
    line = line[my_scroll_column+1..];
  if (strlen(line) >= max_column) {  // line too long for screen?
    long_line = 1;  // we cannot append the marker yet!
    line[max_column-1..] = "";
  }
  while ((i=find_element(line,#'special_char,i)) >= 0) {
    line[i+1..i] = CS_NORMAL_MODE;
    line[i] = special_char(line[i]);
    line[i..i-1] = CS_INVERSE;
    i += strlen(CS_NORMAL_MODE) + strlen(CS_INVERSE) + 1;
  }
  if (my_scroll_column)
    line = CS_INVERSE"<"CS_NORMAL_MODE + line;
  if (long_line)
    return line + CS_INVERSE">"CS_NORMAL_MODE;
  return line + CS_CLEAR_RIGHT /* CS_INVERSE_MODE"*"CS_NORMAL_MODE */;
}

void shift_line() {
  if (scroll_column > 0 &&
      column-scroll_column < max_column-JUMP_X)  // far from end of screen?
    while (scroll_column > 0 &&
           column-scroll_column < max_column-JUMP_X)
      scroll_column -= JUMP_X;
  else if (column-scroll_column + 1 >= max_column)  // reached end of screen?
    while (column-scroll_column + 1 >= max_column)
      scroll_column += JUMP_X;
}

void shift_screen() {
  shift_line();
  if (row < scroll_row)  // at top of screen?
    while (row < scroll_row)
      scroll_row -= JUMP_Y;
  else if (row-scroll_row > max_row-JUMP_Y+1)  // at bottom of screen?
    while (row-scroll_row > max_row-JUMP_Y+1)
      scroll_row += JUMP_Y;
}

void refresh_line() {
  shift_line();
  write(CS_GOTO(row-scroll_row + 1,1) + prepare_line(lines[row],1) +
        CS_GOTO(row-scroll_row + 1,column-scroll_column + 1));
  display_status();
}

void refresh_screen() {
  int file_row,screen_row;
  write(CS_CLEAR_SCREEN);
  shift_screen();
  for (file_row=scroll_row, screen_row=0;
       screen_row<max_row-1 && file_row<sizeof(lines);
       file_row++, screen_row++)
    write(CS_GOTO(screen_row+1,1) +
          prepare_line(lines[file_row],file_row==row));
  if (screen_row < max_row-1)  // file end visible?
    printf(CS_INVERSE CS_GOTO(screen_row+1,1)"%:'~'|*s"CS_NORMAL_MODE,
           max_column," end of file ");
  display_status();
  write(CS_GOTO(row-scroll_row + 1,column-scroll_column + 1));
}

void update_line() {
  if (column-scroll_column+1 >= max_column ||
      (scroll_column && column-scroll_column+1 < max_column-JUMP_X))
    refresh_line();
  else
    write(CS_GOTO(row-scroll_row + 1,column-scroll_column + 1));
  display_status();
}

void update_screen() {
  if (row-scroll_row+2 >= max_row || row < scroll_row)
    refresh_screen();
  else
    write(CS_GOTO(row-scroll_row + 1,column-scroll_column + 1));
  display_status();
}

void display_file() {
  scroll_row = scroll_column = row = column = 0;
  refresh_screen();
  input_to("receive_char",3);
}

void load_file() {
  changed = readonly = unreadable = 0;
  if (!file) {  // no file given?
    lines = ({ "" });
    return display_file();
  }
  else if (file_size(file) == -2) {  // directory?
    file = 0;
    display_message("Cannot edit directory");
    lines = ({ "" });
    display_file();
    return;
  }
  else if (!check_privilege(SECURITY->query_protection(file,0))) { // readable?
    display_message("File unreadable");
    unreadable = 1;
    lines = ({ "" });
    display_file();
    return;
  }
  else if (!check_privilege(SECURITY->query_protection(file,1))) { // writable?
    display_message("File is readonly");
    readonly = 1;
  }
  lines = explode(read_file(file) || "","\n");
  display_file();
}

status mudit(string s) {
  if (!is_wizard(this_player(),IW_TOOLUSER))
    return notify_fail("Sorry, you are not allowed to use this wizard"
                       " tool.\n"), 0;
  if (!check_previous_privilege(get_privilege(this_player())))
    raise_error("Illegal force to mudit\n");
  file = s && normalize_path(s,this_player());
  init_editor(#'load_file);
  return 1;
}

status check_readonly() {
  if (readonly)
    display_message("\aFile is readonly!");
  return readonly;
}

void cursor_left() {
  virtual_column = 0;
  if (!column && !row)
    write("\a");
  else {
    if (column) {
      column--;
      update_line();
    }
    else {
      row--;
      update_screen();
      column = strlen(lines[row]);
      update_line();
    }
  }
}

void cursor_right() {
  virtual_column = 0;
  if (column == strlen(lines[row]) && row+1 == sizeof(lines))
    write("\a");
  else {
    if (column < strlen(lines[row])) {
      column++;
      update_line();
    }
    else {
      column = 0;
      update_line();
      row++;
      update_screen();
    }
  }
}

void cursor_up() {
  int column_mem;
  if (!row)
    write("\a");
  else {
    if (!virtual_column)
      virtual_column = column;
    else
      column = virtual_column;
    column_mem = column;
    column = 0;
    update_line();
    row--;
    column = column_mem;
    if (column > strlen(lines[row]))
      column = strlen(lines[row]);
    update_screen();
    update_line();
  }
}

void cursor_down() {
  int column_mem;
  if (row+1 == sizeof(lines))
    write("\a");
  else {
    if (!virtual_column)
      virtual_column = column;
    else
      column = virtual_column;
    column_mem = column;
    column = 0;
    update_line();
    row++;
    column = column_mem;
    if (column > strlen(lines[row]))
      column = strlen(lines[row]);
    update_screen();
    update_line();
  }
}

void cursor_end() {
  column = strlen(lines[row]);
  update_line();
}

void cursor_home() {
  column = 0;
  update_line();
}

void del_char() {
  if (check_readonly())
    return;
  if (row+1 == sizeof(lines) && column == strlen(lines[row]))
    write("\a");
  else {
    changed = 1;
    virtual_column = 0;
    if (column < strlen(lines[row])) {
      lines[row][column..column] = "";
      refresh_line();
    }
    else {
      lines[row] += lines[row+1];
      lines[row+1..row+1] = ({});
      refresh_screen();
    }
  }
}

void backspace() {
  if (check_readonly())
    return;
  if (!column && !row)
    write("\a");
  else {
    changed = 1;
    virtual_column = 0;
    if (column) {
      column--;
      lines[row][column..column] = "";
      refresh_line();
    }
    else {
      row--;
      column = strlen(lines[row]);
      lines[row] += lines[row+1];
      lines[row+1..row+1] = ({});
      refresh_screen();
    }
  }
}

void insert_char(string char) {
  if (check_readonly())
    return;
  virtual_column = 0;
  changed = 1;
  lines[row][column..column-1] = char;
  column++;
  refresh_line();
}

void insert_return() {
  if (check_readonly())
    return;
  virtual_column = 0;
  changed = 1;
  lines[row+1..row] = ({ lines[row][column..] });
  lines[row][column..] = "";
  row++;
  column = 0;
  refresh_screen();
}

closure input_receiver;
string search_string;

closure search_input_receiver(string char) {
  if (char != "x") {
    search_string += char;
    display_message("Searching for " + search_string);
    return #'search_input_receiver;
  }
}

void start_search() {
  input_receiver = #'search_input_receiver;
  display_message("Search started: ");
  search_string = "";
}

static void receive_char(string char) {
  status written;
  if (input_receiver)
    input_receiver = funcall(input_receiver,char);
  else switch (char[0]) {
  case '\e':
    input_to("receive_sequence",3,char);
    call_out("display_pending_sequence",1,char);
    return;
  case 2:  // C-b
    cursor_left(); break;
  case 6:  // C-f
    cursor_right(); break;
  case 16:  // C-p
    cursor_up(); break;
  case 14:  // C-n
    cursor_down(); break;
  case 1:  // C-a
    cursor_home(); break;
  case 5:  // C-e
    cursor_end(); break;
  case 4:  // C-d
    del_char(); break;
  case 23:  // C-w
    start_search(); break;
  case '\b':  // C-h, backspace
  case 127:  // backspace
    backspace(); break;
  case '\n':  // C-j
  case '\r':  // C-m, return, enter
    insert_return(); break;
  case ' '..'~':  // printable chars
  case 161..255:  // special printable chars
    insert_char(char); break;
  case '\f':  // C-l, form feed
    set_screen_size(lambda(0,({ (#',),
                                ({ (#'refresh_screen) }),
                                ({ (#'input_to),"receive_char",3 }) })));
    return;
  case 15:  // C-o
    if (readonly)
      display_message("\aCannot write, file is readonly");
    else if (!changed)
      display_message("(No changes need to be saved)");
    else if (file_size(file) == -2)
      display_message("\a?! A directory with that name exists");
    else if (file_size(file) != -1)  // file exists?
      if (rename(file,file + "~"))  // rename resulted in error?
        display_message("\aCouldn't rename original file to backup");
      else if (!write_file(file,implode(lines,"\n")))  // write ==> error?
        display_message("\aCouldn't write file, backup is at " + file + "~");
      else
        written = 1;
    else if (!write_file(file,implode(lines,"\n")))  // write ==> error?
      display_message("\aCouldn't write new file");
    else
      written = 1;
    if (written) {
      display_message("Wrote " + file);
      changed = 0;
      display_status();
    }
    break;
  case 17:  // C-q
  case 3:  // C-c
  case 24:  // C-x
    if (changed) {
      display_message("\aFile has changed! Quit really?");
      input_to("quit_really",3);
    }
    else
      exit_editor();
    return;
  }
  input_to("receive_char",3);
}

static void display_pending_sequence(string sequence) {
  display_message(": " + mixed2string(sequence)[1..<2]);
}

static void receive_sequence(string char,string sequence) {
  remove_call_out("display_pending_sequence");
  sequence += char;
  switch (sequence) {
  default:
    if (strlen(sequence) < 3) {
      input_to("receive_sequence",3,sequence);
      call_out("display_pending_sequence",1,sequence);
      return;
    }
    write("\a");
    display_message("Unknown sequence: " + mixed2string(sequence));
    break;
  case CS_KEY_UP:
    cursor_up();
    break;
  case CS_KEY_DOWN:
    cursor_down();
    break;
  case CS_KEY_LEFT:
    cursor_left();
    break;
  case CS_KEY_RIGHT:
    cursor_right();
    break;
  }
  input_to("receive_char",3);
}

static void quit_really(string char) {
  if (toupper(char[0]) == 'Y')
    exit_editor();
  else {
    remove_message();
    input_to("receive_char",3);
  }
}
