/*
 *  rehash manual pages for the tome of magic
 *  Jan-20-1993, foslay
 */

#include <prop/item.h> // Chameloid, 07-Jul-1996
#include <wizlevels.h>
#include <kernel.h>
#include <message.h>

inherit "/complex/item";
inherit ACCESS;

#define WHATIS  "/doc/whatis"
#define WHEREIS "/doc/whereis"
#define LIBCHANGELOG "/changelog/LIBCHANGE"

void create() {
  if (clonep()) {
    write("This tool cannot be cloned (to avoid inconsistencies).\n");
    destruct(this_object());
    return;
  }
  set_privilege(1);
  set_property(P_NOT_DROPPABLE,
               ({ ({ M_WRITE,M_ME_THE," sticks to your fingers." }) }));
  set_short("a rehash command");
  set_long("A tool to check the directories in /doc/whereis for files "
           "missing in /doc/whatis.\n");
  set_id(({ "tool","rehash","command" }));
  move_object(this_object(),this_player());
}

void init() {
  if (this_player() == environment() && query_is_wizard(this_player()) &&
      this_player()->query_level() >= WL_ELDER)
    add_action("rehash_man_pages","rehash");   
}

static string *manpages_of(string str) {
  mixed *dir;
  int t, count;
  dir = get_dir(str+"/", 3);
  for (t=0; t<sizeof(dir); t+=2) {
    if (dir[t+1] != -2 &&
        !member(([ "README","whatis","whereis","whatis.bak" ]),dir[t]))
      dir[count++] = dir[t];
  }
  return dir[0..count-1];
}

mixed *whereis;
mixed *whatis;
mixed *whatis_new;
mixed *whatis_new_desc;
int count, all_flag;
    
// removed static so it can be called from /bin/admin, Chameloid, 07-Jun-1996
status rehash_man_pages() {
  string s1,s2,s3;
  mixed *chapters;
  int chapter_count;
  string *chapter_names;
  string *chapter_dirs;
  int whatis_count;
  string *whatis_names;
  string *whatis_descs;
  int t, k, i;
  mixed h;

  all_flag = 0;
  chapters = ({});
  chapter_names = ({});
  chapter_dirs = ({});
  whatis_names = ({});
  whatis_descs = ({});
  whatis_new = ({});
  whatis_new_desc = ({});

  count = 0;
  whereis = regexp(explode(read_file(WHEREIS),"\n"),
                   "^[^ \t][^ \t]*\t[^ \t][^ \t]*$");  // Alfe 96-Nov-12;
  whatis = explode(read_file(WHATIS), "\n");

  for (t=0; t<sizeof(whereis)-1; t++) {
    if (sscanf(whereis[t], "%s\t%s", s1, s3) != 2) {
      write("Bad \"whereis\" entry: \"" + whereis[t] + "\" at line "+(t+1)+
            ".\n");
      continue;
    }
    chapter_names += ({ s1 });
    chapter_dirs += ({ s3 });
    chapters += ({ manpages_of("/" + s3 + "/.") });
    write("Chapter \"" + s1 + "\" (" + s3 +  ") has " +
          describe("entry",0,0,sizeof(chapters[chapter_count])) + ".\n");
    chapter_count++;
  }
  for (t=0; t<chapter_count; t++)
    for (k=0; k<sizeof(chapters[t]); k++)
      whatis_new += ({ chapters[t][k] + " (" + chapter_names[t] + ")" });
#if 0  // the last line in WHATIS is not a new line. Alfe 97-May-29
  for (t=0; t<sizeof(whatis)-1; t++)
#else
  for (t=0; t<sizeof(whatis); t++)
#endif
  {
    if (sscanf(whatis[t], "%s)%s-%s", s1, s2, s3) < 2) {
      write("Bad \"whatis\" entry: \"" + whatis[t] + "\".\n");
      continue;
    }
    whatis_count++;
    whatis_names += ({ s1 + ")" });
    whatis_descs += ({ s3 });
  }
  whatis_new -= whatis_names;
  if (sizeof(whatis_new)) {
    write("Missing man pages:\n");
    h = whatis_new[0..];
    for (i=sizeof(h); i--; )
      h[i] = "["+i+"] "+h[i];
    printf("%#-79s\n",implode(h,"\n"));
    write("\nAdd man pages? (y/n/a) ");
    whatis_new_desc = allocate(sizeof(whatis_new));
    input_to("add_man_pages");
  }
  else
    write("No missing man pages.\n");

  return 1;
}

private string trim_string(string s,int n) {
  int t, l;

  l = n - strlen(s);
  if (l <= 0)
    return s;
  for (t=0; t<=l/8; t++)
    s += "\t";
  return s;
}

static void write_whatis() {
  string s;
  int t;

  for (t = 0; t < sizeof(whatis_new); t++)
    if (stringp(whatis_new_desc[t]) || all_flag) {
      /*
       * I changed 24 to 16 and added a \t in the string to make sure that
       * there always is at least one tab before the - because the tome
       * searches for "\t-".   Alfe 95-Aug-15
       */
      s = (trim_string(whatis_new[t], 16) + "\t- " +
           (whatis_new_desc[t] ? whatis_new_desc[t] : ""));
      whatis += ({ s });
      write(s); write("\n");
    }
  write("Save changes? (y/n) ");
  input_to("ask_save");
}

static void add_man_pages(string str) {
  if (str == "y") {
    write("Index? (return to exit) ");
    input_to("ask_number");
  }
  else if (str == "n")
    return;
  else if (str == "a") {
    all_flag = 1;
    write_whatis();
    return;
  }
  else {
    write("Add man pages? (y/n/a) ");
    input_to("add_man_pages");
  }
}

int index;

static void ask_number(string str) {
  if (!str || str == "") {
    write_whatis();
    return;
  }
  index = to_int(str);
  if (index < 0 || index >= sizeof(whatis_new)) {
    write("Bad index!\n");
    write("Index? (return to exit) ");
    input_to("ask_number");
  }
  else {
    write("Keywords? ");
    input_to("ask_desc");
  }
}

static void ask_desc(string str) {
  whatis_new_desc[index] = str ? str : "";
  write("Index? (return to exit) ");
  input_to("ask_number");    
}

static void write_whatis2() {
  string tmp;

  tmp = implode(sort_array(whatis, "_alpha_sort", this_object()), "\n");
  rm(WHATIS);
  write_file(WHATIS, tmp);
  write("Done.\n");
  tmp = ctime();     // tmp added by Carador, Jul-1996
  write_file(LIBCHANGELOG,
             break_string(tmp[8..9] + "-" + tmp[4..6] + "-" + tmp[22..23] +
                          " " + tmp[11..15] + ", " +
                          this_player()->query_vis_name() + " (" +
                          this_player()->query_level() +
                          "): "WHATIS", AUTOMATIC ENTRY (generated by"
                          " etc/rehash)\n", 78,2,-1));
}

static void ask_save(string str) {
  if (str == "y") {
    write_whatis2();
    return;
  }
  else if (str == "n")
    return;

  write("Save changes? (y/n) ");
  input_to("ask_save");  
}

private status _alpha_sort(string s1, string s2) { return s1 > s2; }
