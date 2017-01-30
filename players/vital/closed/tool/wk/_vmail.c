#include <ansi.h>

#define MLOGDIR "/players/vital/closed/temp/"

string messages, *heh, name;
int s;

status 
main(string str)
{
    int i;
    string mail;

    if(!str) 
    {
      notify_fail("Syntax: 'vmail <who>'\n");
      return 0; 
    }

    name = str;

    /* init the values */
    heh = ({ });
    s = 0;
    messages = "";
  
    if(!name)
    {
      notify_fail("Syntax: 'vmail <who>'\n");
      return 0;
    }
    if(!restore_object("post_dir/" + name))
    {
      notify_fail("No messages in " + capitalize(str) + 
      "'s mailbox.\n");
      return 0;
    }
    s = sizeof(heh = explode(messages, "\n**\n"));

    write("Number of messages: " + (s/2) + "\n");
    write("Newest message: ");
    if(mail = heh[s-1])
    {
      string dt;

       if(!sscanf(mail, "%sDate: %s\n", dt, dt))
      {
        write("Load error.\n");
        return 1;
      }
      else write(dt + "\n");
    }

    write("\
Please input a value.  'all' will dump all messages to your\n\
screen.  'cap' will capture all messages to a file.\n\
If you input a number, it will print that mail.\n\
Type anything else to quit this screen.\n" + BOLD + "->>" + NORM);
    input_to("inputVal");
    return 1;
}

status
inputVal(string arg)
{
    int c, i;

    if(c = atoi(arg))
    {
      if(c > (s / 2) || c <= 0)
      {
        write("That number isn't valid.\n");
        return 1;
      }
      else
      {
        string a, b, bleh;
        int ref_flag;


        write(BOLD + "\t\tMail " + c + "...\n" + NORM);
        write(heh[(c * 2) - 2]);
        bleh = heh[(c * 2) - 1];
        if(sscanf(bleh,   "%sSubj: %s\n%s", a, b, c) < 3)
        {
          if(sscanf(bleh, "%sRe:   %s\n%s", a, b, c) < 3)
          {
            write("Compile error.\n");
            return 1;
           }
          else ref_flag = 1;
        }
       else ref_flag = 2;
        write(a + "\n" + ((ref_flag == 1) ? "Re: " : "Subj:   ") +  b + "\n" + c + "\n");
        write(BOLD + "\t\tMail complete.\n" + NORM);
        return 1;
      }
    }
    else if(arg == "all")
    {

      for(i = 0; i < s; i ++)
        write(heh[i] + "\n");

     write(BOLD + "\nDump complete.\n" + NORM);
     return 1;
    }
    else if(arg == "cap")
    {

      rm(MLOGDIR + name + "_mail.log");
      for(i = 0; i < s; i ++)
        write_file(MLOGDIR + name + "_mail.log", heh[i] + "\n");
      write(BOLD + "Cap complete.\n");
      return 1;
    }
    else
    {
      write("Invalid option.\nCanceling procedure.\n");
      return 1;
    }

    return 0;
}

get_help()
{
  string help;
  help = "Syntax: vmail <player>";
  return help;
}
