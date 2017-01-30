#include <ansi.h>
#define codeword "\"verbal_kint\""

#define t this_player()
#define dir "/bin/soul/_"


string emote_name, *afar, *targ, *ntarg, code_text;
int    editMode;

reset(x) { if(!x) { editMode = 0; afar = allocate(2);  ntarg = allocate(2);  targ = allocate(3);  } }

main()
{
  mainmenu();
  reset(0);
  input_to("mainchoice");
  return 1;
}

string
replace_read(string arg, object target)
{
    switch(arg)
    {
      case "MN":  /* my name */
        return (string)t->query_name();
      case "MP":  /* my possessive */
        return possessive(t);
      case "MS":  /* my subjective */
        return subjective(t);
      case "MO":  /* my objective */
        return objective(t);
      case "TN":  /* target name */
        return "Bob";
      case "TP":  /* target possessive */
        return "his";
      case "TS":  /* target subjective */
        return "he";
      case "TO":  /* target objective */
        return "him";
      case "RET": /* carriage return */
        return "\n";
      case "CMN": return capitalize((string)t->query_name());
      case "CTN": return "Bob";
      case "CMP": return capitalize(possessive(t));
      case "CMS": return capitalize(subjective(t));
      case "CMO": return capitalize(objective(t));
      case "CTO": return "Him";
      case "CTS": return "He";
      case "CTP": return "His";
    }
    return arg;
}

d(arg)
{
    int s;
    string *words, rr;

   if(!arg) return 0;
   words = explode(arg, "#");
   s = sizeof(words);

   while(s--)
     if(rr=replace_read(words[s], 0))
       words[s] = rr;

   arg = (implode(words, ""));

   words = explode(arg, "$");
   s = sizeof(words);

   while(s--)
   {
     if(rr=(string)t->replace_ansi(words[s], 0))
       words[s] = rr;
    if(rr=replace_read(words[s], 0))
      words[s] = rr;
   }

   arg = (implode(words, "")) + esc + "[0m";
   return arg;
}

mainmenu()
{
  write("\n\t\tEmote Creator/Editor (c) Vertebraker 2001\n\n\t\
[1] Create a new emote\n\t\
[2] Remove an emote\n\t\
[3] Edit an emote\n\t\
[x] Exit\n\n\t\
[1,2,3,4,x] ");
}

create()
{
  write("What would you like the emote to be called? ");
}

removeemote()
{
  write("Type the name of the emote you would like to remove: ");
}

editemote()
{
  write("Type the name of the emote you would like to edit: ");
}

mainchoice(arg)
{
  editMode = 0;
  if(arg != "1" && arg != "2" && arg != "3" && arg != "x")
 {
    mainmenu();
    reset(0);
    input_to("mainchoice");
    return 1;
  }
  if(arg == "1")
  {
    create();
    input_to("createchoice");
    return 1;
  }
  if(arg == "2")
  {
    removeemote();
    input_to("removechoice");
    return 1;
  }
  if(arg == "3")
  {
    editemote();
    input_to("editchoice");
   return 1;
  }
  if(arg == "x")
    return (destruct(this_object()), 1);
}

createchoice(arg)
{
  if(!arg)
  {
    create();
    input_to("createchoice");
    return 1;
  }
  if(file_size(dir + arg + ".c") > 0)
  {
    write("That emote already exists.\n");
    mainmenu();
    reset(0);
    input_to("mainchoice");
    return 1;
  }
  emote_name = arg;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

loadEmote(bog)
{
  mixed *heh;
  heh = (mixed*)bog->query_junk();
/*
  heh[0] = implode(explode(heh[0],"$N$"),"$N$");
  heh[1] = implode(explode(heh[1],"$N$"),"$N$");
  heh[2] = implode(explode(heh[2],"$N$"),"$N$");
  heh[3] = implode(explode(heh[3],"$N$"),"$N$");
  heh[4] = implode(explode(heh[4],"$N$"),"$N$");
  heh[5] = implode(explode(heh[5],"$N$"),"$N$");
  heh[6] = implode(explode(heh[6],"$N$"),"$N$");
*/
  heh[0] = heh[0][0..strlen(heh[0])-2];
  heh[1] = heh[1][0..strlen(heh[1])-2];
  heh[2] = heh[2][0..strlen(heh[2])-2];
  heh[3] = heh[3][0..strlen(heh[3])-2];
  heh[4] = heh[4][0..strlen(heh[4])-2];
  heh[5] = heh[5][0..strlen(heh[5])-2];
  heh[6] = heh[6][0..strlen(heh[6])-2];

  ntarg = ({heh[0],heh[1]});
  targ = ({heh[2],heh[3],heh[4]});
  afar = ({heh[5],heh[6]});
}

editchoice(arg)
{
  string myFile;
  editMode = 1;
  if(!arg)
  {
    editemote();
    input_to("editchoice");
    return 1;
  }
  if(file_size(myFile=(dir+arg+".c")) < 0)
  {
    write("That emote doesn't exist.\n");
    mainmenu();
    reset(0);
    input_to("mainchoice");
    return 1;
   }
  if(catch(myFile->load_me()))
  {
    write("Uhhh..  that file seems screwy.\nSomeone should remove that one.\n");
    mainmenu(); reset(0); input_to("mainchoice");
    return 1;
  }
  else if(myFile->query_code_word() != "verbal_kint")
  {
    write("Nope. That one still needs to be converted to the new format.\n");
    mainmenu(); reset(0); input_to("mainchoice");
    return 1;
  }
  else if(myFile->query_creator() != this_player()->query_real_name() &&
     (this_player()->query_real_name() != "stardream") &&
     (this_player()->query_real_name() != "mishtar") &&
      (this_player()->query_level() < 100))
  {
    write("No. You didn't make that one.\n");
    mainmenu(); reset(0); input_to("mainchoice");
    return 1;
  }

  emote_name = arg;
  loadEmote(myFile);
  msgmenu();
  input_to("crmsgchoice");
}

msgmenu()
{
  write("\n\tMessages Editor - " + emote_name + ".\n\n\
NON-TARGETED ROOM MESSAGES\n\t\
[1] USER:   - " + (d(ntarg[0]) ? d(ntarg[0]) : "Empty") + "\n\t\
[2] ROOM:   - " + (d(ntarg[1]) ? d(ntarg[1]) : "Empty") + "\n\n");
write("\
TARGETED ROOM MESSAGES\n\t\
[3] USER:   - " + (d(targ[0]) ?  d(targ[0]) : "Empty") + "\n\t\
[4] ROOM:   - " + (d(targ[1]) ?  d(targ[1]) : "Empty") + "\n\t\
[5] TARGET: - " + (d(targ[2]) ?  d(targ[2]) : "Empty") + "\n\n");
write("\
AFAR MESSAGES:\n\t\
[6] USER:   - " + (d(afar[0]) ?  d(afar[0]) : "Empty") + "\n\t\
[7] TARGET: - " + (d(afar[1]) ?  d(afar[1]) : "Empty") + "\n\n\t\
[c] Save and create the emote\n\t\
[x] Exit to Main Menu\n\
\t[1,2,3,4,5,6,7,c,x] ");
}

crmsgchoice(str)
{
  if(str == "1")
  {
    write("Input new user message, 'h' for details.\n> ");
    input_to("nt_usr");
    return 1;
  }
  if(str == "2")
  {
    write("Input new room message, 'h' for details.\n> ");
    input_to("nt_rm");
    return 1;
  }
  if(str == "3")
  {
    write("Input new user message, 'h' for details.\n> ");
    input_to("t_usr");
    return 1;
  }
  if(str == "4")
  {
    write("Input new room message, 'h' for details.\n> ");
    input_to("t_rm");
    return 1;
  }
  if(str == "5")
  {
    write("Input new target message, 'h' for details.\n> ");
    input_to("t_t");
    return 1;
  }
  if(str == "6")
  {
    write("Input new user message, 'h' for details.\n> ");
    input_to("a_usr");
    return 1;
  }
  if(str == "7")
  {
    write("Input new target message, 'h' for details.\n> ");
    input_to("a_t");
    return 1;
  }
  if(str == "x")
  {
    mainmenu();
    reset(0);
    input_to("mainchoice");
    return 1;
  }
  if(str == "c")
  {
    rm(dir+emote_name+".c");
    if(find_object(dir+emote_name))
      destruct(find_object(dir+emote_name));
    write_file(dir + emote_name + ".c", "\
inherit \"/bin/std\";\n\n\
void\nreset(int x)\n{\n    if(!x) {\n      ::reset();\n");
  if(!editMode) {
    ntarg[0]+= "$N$";
    ntarg[1]+= "$N$";
    targ[0] += "$N$"; targ[1] += "$N$"; targ[2] += "$N$";
    afar[0] += "$N$"; afar[1] += "$N$";
 }
    ntarg[0]=implode(explode(ntarg[0],"\""),"\\\"")+((ntarg[0][strlen(ntarg[0])-1] == '\"') ? "\\\"" : "");
    ntarg[1]=implode(explode(ntarg[1],"\""),"\\\"")+((ntarg[1][strlen(ntarg[1])-1] == '\"') ? "\\\"" : "");
    targ[1]=implode(explode(targ[1],"\""),"\\\"")+((targ[1][strlen(targ[1])-1] == '\"') ? "\\\"" : "");
    targ[0]=implode(explode(targ[0],"\""),"\\\"")+((targ[0][strlen(targ[0])-1] == '\"') ? "\\\"" : "");
    targ[2]=implode(explode(targ[2],"\""),"\\\"")+((targ[2][strlen(targ[2])-1] == '\"') ? "\\\"" : "");
    afar[0]=implode(explode(afar[0],"\""),"\\\"")+((afar[0][strlen(afar[0])-1] == '\"') ? "\\\"" : "");
    afar[1]=implode(explode(afar[1],"\""),"\\\"")+((afar[1][strlen(afar[1])-1] == '\"') ? "\\\"" : "");
    write_file(dir + emote_name + ".c", "\
       nontarget(\"" + ntarg[0] + "\\n\", \"" + ntarg[1] + "\\n\");\n\
       target(\"" + targ[0] + "\\n\", \"" + targ[1] + "\\n\", \"" + targ[2] + "\\n\");\n");
    write_file(dir + emote_name + ".c", "\
       afar(\"" + afar[0] + "\\n\", \"" + afar[1] + "\\n\");\n\
    }\n}\n\nint\ncmd_" + emote_name + "(string arg)\n\{\n    return do_cmd(arg);\n}\n");

    write_file(dir + emote_name + ".c", "\nquery_code_word() { return " + codeword + "; }\n");
    write_file(dir + emote_name + ".c", "\nquery_creator() { return \""+(string)this_player()->query_real_name()+"\"; }\n");
    write("Ok, emote created.\n");
    write("Spawning new help file...\n");
    command("genemotes", this_player());
    write("Done.\n");
    editMode=0;
    return 1;
  }
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

helpmenu()
{
  tell_object(this_player(),"\n\
   #MN#: My name           #MP#: My possessive    #MS#: My subjective\n\
   #MO#: My objective      #TN#: Target Name      #TP#: Target possessive\n\
   #TS#: Target subjective #TO#: Target Objective #RET#: Carriage return [\\n]\n\n\
 You may capitalize any of these modifiers with a C in front,\n\
  e.g. #CMP# for capitalized my possess., i.e. \"His\" instead of \"his\"\n\
[Note: a carriage return is already appended automatically-\n\
        you do not NEED to add one.]\n\
 Adding ANSI is the same syntax [$] as \"help moncolor\"\n\n");
}

nt_usr(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }
  ntarg[0]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

nt_rm(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }
  ntarg[1]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

t_usr(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }
  targ[0]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

t_rm(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }
  targ[1]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

t_t(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }

  targ[2]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

a_usr(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }
  afar[0]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

a_t(str)
{
  if(str == "h")
  {
    helpmenu();
    msgmenu();
    input_to("crmsgchoice");
    return 1;
  }
  afar[1]=str;
  msgmenu();
  input_to("crmsgchoice");
  return 1;
}

status drop() { return 1; }

void init()
{
  if((int)this_player()->query_level() < 50 &&
     (string)this_player()->query_real_name() != "mizan" &&
     (string)this_player()->query_real_name() != "x" &&
     (string)this_player()->query_real_name() != "stardream" &&
     (string)this_player()->query_real_name() != "sparkle" &&
     (string)this_player()->query_real_name() != "desiree" &&
     (string)this_player()->query_real_name() != "quicksilver")
      return destruct(this_object());
}

query_prevent_shadow() { return 1; }

removechoice(arg)
{
  string tha_file;
  if(!arg)
  {
    create();
    input_to("removechoice");
    return 1;
  }
  if(file_size(tha_file=(dir + arg + ".c")) <= 0)
  {
    write("That emote doesn't exist.\n");
    mainmenu();
    reset(0);
    input_to("mainchoice");
    return 1;
  }
  if((catch(tha_file->heh()) || (string)tha_file->query_creator() !=
     (string)this_player()->query_real_name()) &&
    (string)this_player()->query_real_name() != "stardream" &&
    (string)this_player()->query_real_name() != "mishtar" &&
     (int)this_player()->query_level() < 1000)
  {
    write("You didn't create that emote.\n");
    return 1;
  }
  rm(tha_file);
  if(find_object(tha_file)) destruct(find_object(tha_file));
  write("Emote removed.\n");
  mainmenu();
  reset(0);
  input_to("mainchoice");
  return 1;
}

id(str) { return (str=="e-create"||str=="e-creator"); }
