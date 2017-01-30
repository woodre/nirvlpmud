/*
 * sarlf - Search and Replace Logged Functions
 *
 * This object will automatically replace strings in a file logged into
 * /log/SARLF
 *
 * It is configured to replace outdated fn in inherited files with
 * the more current versions
 */

#include "/include/mudlib.h"

#define MAX_BYTE_READ 8192          /* read file in 8KB blocks */
#define DELIMITER ":"
#define FILE    sarco_list[indice][0]
#define SEARCH  sarco_list[indice][1]
#define REPLACE sarco_list[indice][2]

mixed *sarco_list;
int indice;
string file;

void sarlf(string arg);
void load_file();

void reset(status arg) {
  if (arg) return;
  sarco_list = ({});
}

status id(string str) { return str == "sarlf"; }

status get() { return 1; }

void init() {
  add_action("start", "sarlf");
}

status start() {
  indice = 0;
  file = "/log/SARLF";
  load_file();
  if (!sizeof(sarco_list)) {
    write("No Logged Function Replacements.\n");
    return 1;
  }
  write("Next File: " + FILE + ", Replace: " + SEARCH + " with " + REPLACE +
        "\n" + "Continue (y/q/s) [y]: ");
  input_to("sarlf");
  return 1;
}

void load_file() {
  string txt, *lines, *fsr, *chk;
  int i, size_chk;

  txt = read_file(file);
  if (!txt) return;
  lines = explode(txt, "\n");
  for (i = sizeof(lines); i--;) {
    if (lines[i] == "" || lines[i][0] != '/') continue;

#ifdef OLD_EXPLODE
    fsr = explode(lines[i] + DELIMITER, DELIMITER);
#else
    fsr = explode(lines[i], DELIMITER);
#endif

    if (sizeof(fsr) != 3) continue;

#ifdef OLD_EXPLODE
    chk = explode(txt + lines[i], lines[i]);
    size_chk = sizeof(explode(chk[0] + "\n", "\n"));
#else
    chk = explode(txt, lines[i]);
    size_chk = sizeof(explode(chk[0], "\n"));
#endif

    if (!i || size_chk-1 == i) {
      sarco_list += ({ fsr, });
    }
  }
}

void quit() {
  int i;
  string txt;

  rm(file);
  for (i = indice; i < sizeof(sarco_list); i++) {
    txt = sarco_list[i][0] + DELIMITER +
          sarco_list[i][1] + DELIMITER +
          sarco_list[i][2] + DELIMITER +
          "\n";
    write_file(file, txt);
  }
}

static void sarlf(string prompt) {
  int last_byte;
  int max_byte;            /* max bytes read from file */
  int f_size;              /* file size */
  string txt1, txt2, tmp;
  int i;
  string replace_file;
  string name;
  object ob;

  if (prompt == "n" || prompt == "q") {
    quit();
    return;
  }
  if (prompt == "s") {
    if (++indice < sizeof(sarco_list)) {
      write("Next File: " + FILE + ", Replace: " + SEARCH + " with " +
            REPLACE + "\n" + "Continue (y/n/s) [y]: ");
      input_to("sarlf");
    }
    else {
      quit();
    }
  }

  f_size = file_size(FILE);
  name = (string)this_player()->query_name(1);

  while (file_size("/plyaers/" + name + "/sarco" + i + ".c") > 0) i++;
  replace_file = "/players/" + name + "/sarco" + i + ".c";

  txt1 = "\/* sarlf replaced " + SEARCH + " with " + REPLACE + " *\/\n";
  write_file(replace_file, txt1);

  /* do search and replace */

  while (last_byte < f_size) {
    txt2 = 0;
    if (last_byte + MAX_BYTE_READ > f_size)
      max_byte = f_size - last_byte;
    else
      max_byte = MAX_BYTE_READ;
    txt1 = read_bytes(FILE, last_byte, max_byte);
    if (txt1) {
      sscanf(txt1, "%s" + SEARCH + "%s", txt1, txt2);
      write_file(replace_file, txt1);
      last_byte += strlen(txt1);
      if (txt2) last_byte += strlen(SEARCH);
      if (txt2) {
        write_file(replace_file, REPLACE);
      }
    }
  }

  /* if replacement file loads, replace FILE */

  if (!catch(call_other(replace_file, "??"))) { /* it loads */
    rm(FILE);
    last_byte = 0;
    f_size = file_size(replace_file);
    while (last_byte < f_size) {
      if (last_byte + MAX_BYTE_READ > f_size)
        max_byte = f_size - last_byte;
      else
        max_byte = MAX_BYTE_READ;
      txt1 = read_bytes(replace_file, last_byte, max_byte);
      write_file(FILE, txt1);
      last_byte += max_byte;
    }
    log_file("DONE_SAR", REPLACE + " replaced " + SEARCH + " in " + FILE +
             "\n");
    rm(replace_file);
    sscanf(replace_file, "/%s.c", replace_file);
    if ((ob = find_object(replace_file))) destruct(ob);
    sscanf(FILE, "/%s.c", replace_file);
    if ((ob = find_object(replace_file))) destruct(ob);
  }
  else {
    log_file("log", "Sarlf Error: cannot load " + replace_file +
                    " to replace " + FILE + "\n");
  }
  if (++indice < sizeof(sarco_list)) {
    write("Next File: " + FILE + ", Replace: " + SEARCH + " with " + REPLACE +
          "\n" + "Continue (y/n) [y]: ");
    input_to("sarlf");
  }
  else {
    quit();
    write("Ok.\n");
  }
}

