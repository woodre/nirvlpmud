#include <ansi.h>

#define MAX_LEN 70
#define DOCS "/players/sparrow/closed/guild/docs/"

void print_all()
{
  int s;
  int x;
  string *fs;
  string line;

  fs=get_dir(DOCS);
  s = sizeof(fs);

  line="\t";
  for(x=0;x<s;x++)
  {
    if(strlen(line + fs[x] + "\t") > MAX_LEN)
    {
      write(line + "\n");
      line = "\t" + fs[x] + "\t";
    }
    else
    {
      line += (fs[x] + "\t");
    }
  }
  write(line+"\n");
}

int cmd_bwo(string str)
{
  if(!str) str="main";

  write("\n");

  write("\t\t\t"+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIK+" -="+NORM+"The Order"+HIK+"=- "+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+".\n"+NORM);
  write("\n");

  if(str=="all")
    print_all();
  else if(file_size(DOCS+str)==-1)
    write(" There is no such help file.\n");
  else cat(DOCS+str);

  write("\n");

  write("\t\t\t"+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+
HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+".");
  write(HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+
HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+"."+HIC+"."+NORM+CYN+".");
  write(HIC+"."+NORM+CYN+"."+NORM+"\n");
  write("\n");

  return 1;
}
