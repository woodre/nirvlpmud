/*  do not clone, grazi */

#include <ansi.h>


#define REP "/players/forbin/closed/neo/obj/reporter"

string type;
string *fs;
mixed  *reps, *dates, *names, *data;

status id(string str) {
  return (str=="report_tool");
}

int dsp_menu()
{
  int x, y;
  y = sizeof(fs);
  if(!y) {
    write("There are no "+type+"s.");
    this_object()->quit();
    return 1;
  }
  write("\n");
  
  for(x = 0; x < y; x ++) {
    write(x+1);
    write(": ");
    write(fs[x]);
    write("\n"); 
  }
  
  write("\n");
  write(HIR+"*"+NORM+" indicates a file with multiple reports.\n");
  write("['1'-'"+y+"'], ['d'elete], ['q'uit]: ");
  input_to("choose_report");
  return 1;
}

int start_report(string t)
{
  int    x, y;
  
  type = t;
  
  data = (mixed *)call_other(REP,"query_"+type);
  fs = data[0];
  names = data[1];
  reps = data[2];
  dates = data[3];
  
  return dsp_menu();
}

int good_number(string str) {
  int c;
  if(!sscanf(str,"%d",c) || c < 1 || c > sizeof(fs)) {
    write("Invalid choice.\n");
    return 0;
  }
  return c;
}

int quit() {
  write("\n");
  move_object(this_object(), "/room/void");
  return 1;
}

int delete() {
  write("# to delete? ['1'-'"+sizeof(fs)+"'], ['m'enu], ['q'uit]: ");
  input_to("delete_num");
  return 1;
}

int to_delete;

int delete_num(string d)
{
  int c;
  to_delete = 0;
  if(d == "q") {
    return quit();
  }
  if(d == "m") {
    return dsp_menu();
  }
  if(!(c = good_number(d))) {
    write("Try again.\n");
    write("# to delete? ['1'-'"+sizeof(fs)+"'], ['q'uit]: ");
    input_to("delete_num");
    return 1;
  }
  c--;
  to_delete = c;
  write("You are deleting report #"+(c+1)+".\n");
  write("This is in reference to: "+HIW+reps[c][c]+NORM+".\n");
  write("Are you sure? <y/n> ");
  input_to("confirm_delete");
  return 1;
}

int confirm_delete(string yn)
{
  if(yn != "y") {
    write("Canceled delete.\n");
  }
  else {
    write("Ok. Deleting #"+(to_delete+1)+".\n");
    call_other(REP, "delete_"+type, to_delete);
    write("Done.\n");
  }
  return start_report(type);
}   

int choose_report(string str) {
  int c, s, x;
  
  if(str == "q") {
    return quit();
  }
  
  if(str == "d") {
    return delete();
  } 
  
  if(!(c=good_number(str)))
  {
    write("Invalid choice.\n");
    write("['1'-'"+sizeof(fs)+"'], ['d'elete], ['q'uit]: ");
    input_to("choose_report");
    return 1;
  }
  
  c--;
  
  write("\nReports for: "+fs[c]+"\n\n");
  s = sizeof(names[c]);
  for(x = 0; x < s; x ++) {
    write(dates[c][x]+" :: "+pad(names[c][x],13)+"\n");
    print(reps[c][x], 69);
  }
  return start_report(type);
}
   
