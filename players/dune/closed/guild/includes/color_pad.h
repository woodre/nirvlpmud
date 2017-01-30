#include "../DEFS.h"

#define BLANKS "                                                                        "


string color_pad(string str, int len)
{
  int i,l;
  int flag;
  int ansi_length;  /* Length of current ansi code */
  int curr_length;  /* Length without ansi codes   */
  int total_length; /* Total length of the string so it doesn't cut off any codes */
  for (i=0,l=strlen(str); i < l && (total_length - ansi_length) < len; i++)
  {
    if(str[i..i] == ESC) flag = 1;
    if(flag) {
      ansi_length++;
      curr_length++;
      if(str[i..i] == "m") {
        flag = 0;
        total_length+=curr_length;
        curr_length=0;
      }
    }
    else
      total_length++;
  }
  str+=BLANKS;
  if(total_length - ansi_length < len)
    total_length += len - (total_length - ansi_length); /* Blah! */
  return str[0..total_length];
}


string color_help()
{
  return "$H$      "+BOLD+"bold"+OFF+"\n"+
         "$K$      "+BLACK+"black"+OFF+" (black)\n"+
         "$R$      "+RED+"red"+OFF+"\n"+
         "$G$      "+GREEN+"green"+OFF+"\n"+
         "$Y$      "+YELLOW+"yellow"+OFF+"\n"+
         "$B$      "+BLUE+"blue"+OFF+"\n"+
         "$M$      "+MAGENTA+"magenta"+OFF+"\n"+
         "$C$      "+CYAN+"cyan"+OFF+"\n"+
         "$W$      "+WHITE+"white"+OFF+" (white)\n"+
         "$-$      (color back to normal)\n"+
         "$HK$     "+BOLD+BLACK+"bold black"+OFF+"\n"+
         "$HR$     "+BOLD+RED+"bold red"+OFF+"\n"+
         "$HG$     "+BOLD+GREEN+"bold green"+OFF+"\n"+
         "$HY$     "+BOLD+YELLOW+"bold yellow"+OFF+"\n"+
         "$HB$     "+BOLD+BLUE+"bold blue"+OFF+"\n"+
         "$HM$     "+BOLD+MAGENTA+"bold magenta"+OFF+"\n"+
         "$HC$     "+BOLD+CYAN+"bold cyan"+OFF+"\n"+
         "$HW$     "+BOLD+WHITE+"bold white"+OFF+"\n";
}
