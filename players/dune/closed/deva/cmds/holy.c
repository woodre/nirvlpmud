/*
 * HOLY command for Ascension
 * help file command
 */
#include "../def.h"


string shorted_file(string str) {
  string files;
  files = str + "short";
  if(file_size(files) >= 0) str = files;
  return str;
}

int find_menu(string str) {
  string menustr;
  if(sscanf(str, "%smenu", menustr) == 1) return 1;
  if(sscanf(str, "%sshort", menustr) == 1) return 1;
  return 0;
}

status main(string str) {
/* takes str and refers to files in docs directory */
  string file, topic, all;
  if(!str) {
    cat(HELPDIR+"main_menu");
    return 1; }
  if(sscanf(str, "%s %s", topic, all)) {
    file = HELPDIR +""+ topic;
    file = shorted_file(file);
    if(all == "all") {
      if (file_size(file) >= 0) {
        cat(file);
        return 1; }
      else {
        write("There is no holy scripture on that topic.\n");
        return 1; }
      }
    if(all != "all") {
      write("Read a scripture page by page: holy [topic]\n"+
            "Read a scripture all at once : holy [topic] all.\n");
      return 1; }
    }
  if(sscanf(str, "%s", topic)) {
      file = HELPDIR +""+ topic;
      file = shorted_file(file);
      if (file_size(file) >= 0) {
         if(find_menu(file)) {
           cat(file);
           return 1; }
         call_other(MORED, "more_file", file);
         return 1; }
      write("There is no holy scripture on that topic.\n");
      return 1; }

  write("Read a scripture page by page: holy [topic]\n"+
        "Read a scripture all at once : holy [topic] all.\n");
}
