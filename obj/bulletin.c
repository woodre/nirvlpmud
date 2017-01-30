/* Bulletin Board 2 */

/*
 * This board gives the player greater control over notices. It uses
 * /obj/editor (a string editor), and /obj/pager (a 'more' for strings).
 * These are also used by the mailer
 */

#if 0 /* until include_dirs are resetup */
#include <mudlib.h>
#else
#include "/include/mudlib.h"
#endif
inherit BASE;

#include <ansi.h>

#define NAME    (string)this_player()->query_name()
#define REAL    (string)this_player()->query_name(1)
#define HEADER  0
#define AUTHOR  1
#define MESSAGE 2
#define TIME    ctime(time())[4..15]
#define PASTE   "/" + PASTE_DIR + "/" + REAL

/* bulletins */

mixed *bulletins;  /* ({ ({ header, author, message, }), }) */
static string save_file;

/* new notice */

static object new_author;
static string new_header;
static int edit_old;

void reset(status arg) {
  if (arg) return;

  set_name("bulletin board");
  set_alt_name("board");
  set_extra_long("There is a bulletin board here.\n");
  bulletins = ({});
}

void long(status wiz) {
  int i;

  if (query_long()) :: long(wiz);
  write("You can set up new notes with the command 'note headline'.\n");
  write("Read a note with 'read num', and remove an old note(s) with\n");
  write("'remove num{,num2}'.  You can clip a note to your clipboard with\n"+
        "'clip num'.  You can edit one of your old notes with\n"+
        "'edit num'.\n");
  if (!sizeof(bulletins)) {
    write("It is Empty.\n");
  }
  else if (sizeof(bulletins) == 1) {
    write("The Bulletin Board contains 1 note:\n\n");
  }
  else {
    write("The Bulletin Board contains " + sizeof(bulletins) + " notes:\n\n");
  }
  say(NAME + " studies the bulletin board.\n");
  for (i = 0; i < sizeof(bulletins); i++) {
    write((i+1) + ".\t" + bulletins[i][HEADER] + "\n");
  }
}

void set_save_file(string file) {
  save_file = file;
  if (save_file) restore_object(save_file);
}

status get() {
  write("It is secured to the ground.\n");
  return 0;
}

void init() {
  if (!bulletins) bulletins = ({});
  add_action("new", "note");
  add_action("read", "read");
  add_action("remove", "remove");
  add_action("bo", "bo");
  add_action("read", "clip");
  add_action("edit", "edit");
}

status bo() {
  long(0);
  return 1;
}



/****************************************************************************/

void add_message(string arg) { /* quit and save from editor */
  if (new_author != this_player()) return;
  if (edit_old) { /* was editing old notice */
    bulletins = bulletins[0..(edit_old-2)]
              + bulletins[edit_old..(sizeof(bulletins)-1)];
    edit_old = 0;
  }
  bulletins += ({
                 ({
                   new_header,
                         REAL,
                          arg,
                 })
               });
  if (save_file) save_object(save_file);
  new_author = 0;
  new_header = 0;
}

void editor_quit(string arg) { /* quit, no save from editor */
  edit_old = 0;
  new_author = 0;
  new_header = 0;
}


/****************************************************************************
 * edit old notice
 */

status edit(string str) {
  int i;
  string rest;

  if (!str || !(sscanf(str, "%d", i) || sscanf(str, "note %d", i))) return 0;
  if (i < 1 || i > sizeof(bulletins)) {
    write("Not that number of messages.\n");
    return 1;
  }
  i -= 1;
  if (!this_player()->id(bulletins[i][AUTHOR])) {
    write("Sorry, you can only edit your own notice.\n");
    return 1;
  }
  if (new_author && environment(new_author) == environment()) {
    write((string)new_author->query_name() + " is busy writing.\n");
    return 1;
  }
  sscanf(bulletins[i][HEADER],"%s("+capitalize(REAL)+", %s",new_header,rest);
  new_header += "(" + capitalize(REAL) + ", " + TIME + ")";
  new_author = this_player();
  edit_old = i + 1;
  clone_object(EDITOR)->edit("add_message", bulletins[i][MESSAGE], 1);
  return 1;
}


/****************************************************************************
 * add new notice
 */

status new(string hd) {
  if (!hd) {
    notify_fail("You must give a title.\n");
    return 0;
  }
  if (new_author && environment(new_author) == environment()) {
    write((string)new_author->query_name() + " is busy writing.\n");
    return 1;
  }
  if (sizeof(bulletins) == 30) {
    write("Yo have to remove an old message first.\n");
    return 1;
  }
  if (strlen(hd) > 50) {
    write("Too long header to fit the paper.\n");
    return 1;
  }
  hd = (string)this_player()->filter_ansi(hd); /* all headers filtered */
  new_author = this_player();
  new_header = hd + "(" + capitalize(REAL) + ", " + TIME + ")";
  clone_object(EDITOR)->edit("add_message", 0, 1);
  return 1;
}


/****************************************************************************
 * read notice
 */

status read(string str) {
  int i, k;
  object pager_ob;

  if (!str || (sscanf(str, "%d", i) && sscanf(str, "note %d", i))) {
    if (query_verb() == "clip")
      notify_fail("Usage: clip <note number>\n");
    return 0;
  }
  if (i < 1 || i > sizeof(bulletins)) {
    write("Not that number of messages.\n");
    return 1;
  }
  i -= 1;
  say(NAME + " reads a not titled '" + bulletins[i][HEADER] + "'.\n");
  if (query_verb() == "clip") {
    str = bulletins[i][MESSAGE];
  }
  else if (this_player()->ansi_on()) {
    str = bulletins[i][MESSAGE] + OFF;
  }
  else {
    str = (string)this_player()->filter_ansi(bulletins[i][MESSAGE]);
  }
  if (query_verb() == "clip") {
    rm(PASTE);
    write("The note titled '" + bulletins[i][HEADER] +
          "' has been copied to your Clipboard.\n");
    write_file(PASTE, str);
  }
  else {
    write("The note is titled '" + bulletins[i][HEADER] + "':\n\n");
#ifdef PAGER
    pager_ob = clone_object(PAGER);
    move_object(pager_ob, this_player());
    pager_ob->page(str);
#else
    write(str);
#endif
  }
  return 1;
}


/****************************************************************************
 * remove notice
 */

status remove(string str) {
  int i, j, k;

  if (!str || !(sscanf(str, "%d,%d", i, j) || sscanf(str, "note %d", i) ||
      sscanf(str, "%d", i))) {
    notify_fail("remove <number>\nremove <number1,number2>\n");
    return 0;
  }
  if (i < 1 || i > sizeof(bulletins)) {
    notify_fail("Not that number of messages.\n");
    return 0;
  }
  if (j < i) j = i;
  if (j > sizeof(bulletins)) j = sizeof(bulletins);
  for (i -= 1, j -= 1; j >= i; j--) {
    if (!(this_player()->id(bulletins[j][AUTHOR]) ||
          this_player()->query_security_level())) {
      write("Sorry, you will have to ask a creator to remove the message " +
            (j+1) + "for you.\n");
      continue;
    }
    say(NAME + " removed a not titled '" + bulletins[j][HEADER] + "'.\n");
    write("You remove the note " + bulletins[j][HEADER] + "...\n");
    bulletins = bulletins[0..j-1] + bulletins[j+1..sizeof(bulletins)-1];
  }
  if (save_file) save_object(save_file);
  return 1;
}

