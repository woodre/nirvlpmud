#include "../defs.h"
#define MAX_NOTES 25
string subject, new_mess, *messages;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("clan_board_obj");
   set_long("There is no clan_board_obj here.\n");
}

int restore_me()
{
   if(!TP || !CNAME) return 0;
   return restore_object(SAVE_DIR + CNAME + "/board");
}

void save_me()
{
   if(file_size(TOP_DIR + CNAME) != -2) return;
   save_object(SAVE_DIR + CNAME + "/board");
}

void update_others()
{
   int x;
   object *us;
   
   us = users();
   for(x = 0; x < sizeof(us); x++)
   {
      if(us[x]->query_clan_name() == CNAME && present("clan_board_obj",us[x]) && us[x] != TP)
         {
         tell_object(us[x],"A note has been removed or added.\nRefreshing object and returning to main menu.\n");
         destruct(present("clan_board_obj",us[x]));
         move_object(clone_object(TOP_DIR + "obj/clan_board_obj"),us[x]);
       }
   }
   return;
}

void pause_me(string str)
{
   this_object()->main_menu();
   return;
}

void halt()
{
   write("Press ENTER to continue.\n");
   input_to("pause_me");
   return;
}

void help_menu()
{
   write("At the main menu, the following commands are available:\n"+
      "  #               Type the number of a note to read that note.\n"+
      "  note [subject]  Write a note with subject 'subject'.\n"+
      "  remove [#]      Remove note. Clan leaders may remove any note.\n"+
      "                  Everyone else can only remove their own notes.\n"+
      "  q               Quit clan boards.\n"+
      "  help            This message.\n\n");
   halt();
   return;
}

void read_message(int message)
{
   string *this_message;
   int my_time;
   if(message < 1 || message > sizeof(messages))
      {
      write("Invalid message number.\n\n");
      halt();
      return;
   }
   
   message -= 1;
   this_message = explode(messages[message],"%DATA_BREAK%");
   if(sscanf(this_message[1],"%d",my_time) == 1);
   write("==================================\n"+
      "Author    " + capitalize(this_message[0]) + "\n" +
      "Subject   " + this_message[2] + "\n" +
      "Date      " + ctime(my_time) + "\n\n" +
      "==================================\n\n"+
      this_message[3] + "\n\n" +
      "==================================\n");
   halt();
   return;
}

void delete_note(int message)
{
   string *this_message;
   
   if(message < 1 || message > sizeof(messages))
      {
      write("Invalid message number.\n\n");
      halt();
      return;
   }
   
   message -= 1;
   this_message = explode(messages[message],"%DATA_BREAK%");
   if(!C_OBJ->query_leader(TP->query_real_name()) && this_message[0] != (string)TP->query_real_name())
      {
      write("Only leaders may remove the notes of other members.\n\n");
      halt();
      return;
   }
   
   write("Removing note " + (message + 1) + ".\n\n");
   messages -= ({ messages[message] });
   save_me();
   update_others();
   call_other(TOP_DIR + "cmds/_c_chat","main",":has removed a note from the clan board.");
   halt();
   return;
}

void make_note(string str)
{
   if(str == "~q")
      {
      write("Aborting.\n\n");
      halt();
      return;
   }
   
   if(str == "**")
      {
      if(new_mess == "")
         {
         write("Note blank. Aborting.\n\n");
         halt();
         return;
      }
      
      messages += ({ TP->query_real_name() + "%DATA_BREAK%" + time() + "%DATA_BREAK%" + subject + "%DATA_BREAK%" + new_mess });
      save_me();
      update_others();
      call_other(TOP_DIR + "cmds/_c_chat","main",":has written a note to the clan board.");
      halt();
      return;
   }
   
   if(str) new_mess += str;
   new_mess += "\n";
   write("] ");
   input_to("make_note");
   return;
}

void main_choice(string str)
{
   string arg;
   int mess_num;
   if(!str)
      {
      write("] ");
      input_to("main_choice");
      return;
   }
   
   if(sscanf(str,"%d",mess_num) == 1)
      {
      read_message(mess_num);
      return;
   }
   
   if(str == "q")
      {
      write("Exiting boards.\n");
      destruct(this_object());
      return;
   }
   
   if(str == "help")
      {
      help_menu();
      return;
   }
   
   if(sscanf(str,"%s %s",str,arg) == 2);
   
   if(str == "note")
      {
      
      if(sizeof(messages) >= MAX_NOTES)
         {
         write("Maximum note limit reached.\nYou must remove a note before writing a new one.\n] ");
         input_to("main_choice");
         return;
      }
      
      if(!arg)
         {
         write("You must supply the subject as an argument.\n] ");
         input_to("main_choice");
         return;
      }
      subject = arg;
      new_mess = "";
      write("Begin writing the note.\nType '**' on a blank line to finish, and ~q to abort.\n] ");
      input_to("make_note");
      return;
   }
   
   if(str == "remove")
      {
      if(!arg || sscanf(arg,"%d",mess_num) != 1)
         {
         write("Invalid note number to remove.\n] ");
         input_to("main_choice");
         return;
      }
      delete_note(mess_num);
      return;
   }
   
   write("Invalid argument. Type 'help' for help.\n] ");
   input_to("main_choice");
   return;
}

void main_menu()
{
   int x, my_time;
   string *these_messages;
   write("Messages:\n");
   if(!sizeof(messages))
      {
      write("None.\n");
   }
   else
      {
      for(x = 0; x < sizeof(messages); x++)
      {
         these_messages = explode(messages[x],"%DATA_BREAK%");
         if(sscanf(these_messages[1],"%d",my_time) == 1);
         write(pad((x+1) + ".",4) + " " + these_messages[2] + " [" + capitalize(these_messages[0]) + ", " + ctime(my_time) + "]\n");
      }
   }
   write("\nType 'help' for help.\n] ");
   input_to("main_choice");
   return;
}

init()
{
   ::init();
   
   if(TP && !CNAME)
      {
      destruct(this_object());
      return 1;
   }
   
   restore_me();
   if(!messages) messages = ({ });
   main_menu();
}

drop() { main_choice("q"); }
