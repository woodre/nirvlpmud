#include "/players/forbin/ansi.h"
#include "/players/forbin/closed/wiztool/define.h"
#define FILENAME "log"
#define BULLETCHAR "-"

static string flag, temp, setwhat, str, str1, str2;
static string where, what, one, two;
string FileName, BulletChar;
static object target;

void show_help() {
  write("\n");
  write("ForbinHack(c) 2004 - Note Maker Ver 1.0\n");
  write("Use to make a variety of handy notes and documents.\n");
  write("Correct Syntax: fn [-option] [text]\n");
  write("File name will default to 'General' unless set.\n");
  write("The following options are available:\n");
  write("  help or ?  Help File.  You're looking at it.\n");
  write("  set        Use to set the filename and the bullet character.\n");
  write("  r          Line return.\n");
  write("  t          Make [text] a title. (all caps & bold white)\n");
  write("  h          Make [text] a heading. (colored in bold white brackets)\n");  
  write("  here       Uses filename of current location to make a heading.\n"); 
  write("  p          Uses filename of (p)resent arg.\n");
  write("  rm         Remove the current document, erasing it.\n");
  write("\n");
}

int unsave() {
  int a;
  a = restore_object("players/forbin/closed/wiztool/mnsave");
  return a;
}

status main(string arg) {
  flag = temp = setwhat = str = str1 = str2 = where = one = two = 0;
  unsave();
  if(!FileName) FileName = FILENAME;
  if(!BulletChar) BulletChar = BULLETCHAR;
  if(!arg) {
    write("Correct Syntax: fn [-option] [text].\n"+
          "Use 'fh -?' for more info.\n");
    return 1;
  }
  if(sscanf(arg, "-%s %s", flag, temp) || sscanf(arg, "-%s", flag)) {
    if(!temp)
      str = "";
    else
      str = temp; 
  }
  else {
    str1 = "  "+WTC+BulletChar+NORM+" "+arg; 
    str2 = "  "+BulletChar+" "+arg;      
  }
  if(flag) {
    flag = lower_case(flag);    
    switch(flag) {
      case "help" : 
      case "?" :    
        show_help(); 
        return 1;
      case "set" : 
        if(sscanf(str, "%s %s", setwhat, temp) == 2) {       
          if(setwhat != "filename" && setwhat != "bullet")
            return (notify_fail("Correct syntax:  'fn -set filename/bullet [filename/character]'.\n"), 1);
          if(setwhat == "filename") {
            FileName = temp;
            write("Filename set to:  "+FileName+".\n"); 
            save_object("players/forbin/closed/wiztool/ftsave");          
            return 1;
          }
          if(setwhat == "bullet") {
            BulletChar = temp; 
            write("Bullet character set to:  "+BulletChar+".\n"); 
            save_object("players/forbin/closed/wiztool/ftsave");         
            return 1;
          }
        }    
        else if(sscanf(str, "%s", setwhat) == 1) { 
          if(setwhat == "filename") { 
            write("Current filename set to:  "+FileName+".\n");
            write("Use 'fn -set filename [filename]' to set filename.\n");
            return 1;
          }
          else if(setwhat == "bullet") {
            write("Current bullet character set to:  "+BulletChar+".\n");
            write("Use 'fn -set bullet [character]' to set bullet character.\n");            
            return 1;
          }
          else {
            write("Correct syntax:  'fn -set filename/bullet [filename/character]'.\n");
            return 1;
          }
        }
        else {
          write("Correct syntax:  'fn -set filename/bullet [filename/character]'.\n");
          return 1;
        }
      case "here" :   
        where = file_name(environment(this_player()));
        if(sscanf(where, "%s#%s", one, two) == 2) where = one;
        str1 = HIW+"[ "+WTC+where+".c"+HIW+" ]"+NORM; 
        str2 = "[ "+where+".c ]";
        break;
      case "p" :
        if(str == "") {
          write("You must provide a target object.\n");
          return 1;
        }
        if(present(str, environment(this_player())))
          target = present(str, environment(this_player()));
        else if(present(str, this_player()))
          target = present(str, this_player());
        else {
          write("There is no "+str+" present.\n");
          return 1;  
        }
        what = file_name(target);
        if(sscanf(what, "%s#%s", one, two) == 2) what = one;
        str1 = HIW+"[ "+WTC+what+".c"+HIW+" ]"+NORM; 
        str2 = "[ "+what+".c ]";
        break;
      case "t": 
        str1 = HIW+upper_case(str)+NORM; 
        str2 = upper_case(str);
        break;
      case "r": 
        str1 = ""; 
        str2 = "";
        break;      
      case "h":
        str1 = HIW+"[ "+WTC+str+HIW+" ]"+NORM; 
        str2 = "[ "+str+" ]";
        break;
      case "rm" :
        rm("/players/forbin/closed/"+FileName);
        rm("/players/forbin/closed/"+FileName+".nc");
        write(FileName+" & "+FileName+".nc removed.\n");
        return 1;
    }
  }
  write_file("/players/forbin/mages/"+FileName, str1+"\n");
  write_file("/players/forbin/mages/"+FileName+".nc", str2+"\n"); 
  save_object("players/forbin/closed/wiztool/mnsave");    
  write("["+FileName+"] Note made.\n");
  return 1;  
}
