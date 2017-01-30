/* 08/17/06 Earwax: Coded this to display callouts */
/* 12/12/2013 - Rumplemintz: Coded to work on LP mud - moved Wax's to LD only
                             for now, until I can test it there.
 */

#include <ansi.h>

#ifdef __LDMUD__
status cmd_callouts(string arg)
{
  int i, siz;
int j, k;
  mixed *info;

  i = siz = sizeof(info = call_out_info());
  if (!i)
  {
    write("No callout information to display.\n");
    return 1;
  }

  while(i--)
  {
/*
for (j = 0, k = sizeof(info[i]); j < k; j++)
write(typeof(info[i][j])+"\n");
*/
    printf("%3d ", i);
    printf("%4d ", (intp(info[i][2]) ? info[i][2] : 0));
    printf("%-50s ", (info[i][0] && objectp(info[i][0]) ? object_name(info[i][0]) : "UNKNOWN"));
    printf("%-30s", (info[i][1]) && stringp(info[i][1]) ? info[i][1] : "UNKNOWN");
    write((string)info[i][0]->short());
    write("\n");
  }
  /* NOTE:  I may need to add error checks or show an additional
   * line of info for the arguments passed, we'll see. 
   */

  printf("%d callouts displayed.\n", siz);
  return 1;
}
#else

int cmd_callouts() {
  mixed callouts;
  int i;
  string output;

  callouts = call_out_info();

  write( HIR + "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% CALL OUTS " +
               "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" + NORM + "\n");

  for (i=0; i<sizeof(callouts); i++) {
    output += i + ". ";
    if (sizeof(callouts[i]) > 0)
      output += object_name(callouts[i][0]);
    if (sizeof(callouts[i]) > 1)
      output += "\t" + callouts[i][1];
    output += "\n";
    write( output );
    output = "";
  }
  output += HIR + "----------------------------------------"+
                  "----------------------------------------"+ NORM +"\n";
  output += HIR + sizeof(callouts) + " callouts found currently.\n";
  output += "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" +
            "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" + NORM + "\n";
  write(output + "\n");
  return 1;
}
#endif