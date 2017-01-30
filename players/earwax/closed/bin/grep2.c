#include "../defs.h"

int main(string arg) {
  string pattern, filename, filetext;
  int i, siz;
  string *lines, *matches;

  if (!arg || sscanf(arg, "%s %s", pattern, filename) != 2)
  {
    notify_fail("See 'wizhelp grep' for help on using grep.\nSyntax: grep <pattern> <filename>\n");
    return 0;
  }

  if (sscanf(filename, "/%s", filename) == 1)
    filename = resolv_path("/"+filename);
  else
    filename = resolv_path((string)this_player()->query_pwd() + filename);

  filetext = read_file(filename, 1, 5000);

  if (!filetext)
  {
    write("File did not read: "+filename+"\n");
    siz = file_size(filename);

    if (siz < 1)
    {
      write("File does not exist, or is unreadable.\n");
      return 1;
    }

    write("Size of file probably too large: "+siz+"\n");
    return 1;
  }

  lines = explode(filetext, "\n");

  if (!sizeof(lines))
  {
    write("Could not explode file: "+filename+"\n");
    return 1;
  }

  matches = regexp(lines, pattern);
  siz = sizeof(matches);
  write(HIY+"Searching "+filename+" for \""+pattern+"\" returned "+siz+" matches.\n"+NORM+NORM);

  for (i = 0; i < siz; i++)
    write(matches[i]+"\n");

  write("Filesize: "+file_size(filename)+"\n");
  return 1;
}
