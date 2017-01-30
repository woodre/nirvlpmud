string cmd_to_do;

int execute_me()
{
   object obj;
   string executer,executer2;
   executer = "/players/" + this_player()->query_real_name() + "/exec_file.c";
   executer2 = "/players/" + this_player()->query_real_name() + "/players/" + this_player()->query_real_name() + "/exec_file.c";
   if(file_size(executer) > 1) rm(executer);
   obj = find_object(executer);
   if(obj) destruct(obj);
   write_file(executer,"execute()\n{\n" + cmd_to_do + "}\n");
   executer2->execute();
   write("Execution finished.\n");
   rm(executer);
   return 1;
}

int build_cmd(string str)
{
   if(!str)
      {
      write("] ");
      input_to("build_cmd");
      return 1;
   }

   if(str == "~q")
      {
      write("Aborting.\n");
      return 1;
   }

   if(str == "**")
      {
      execute_me();
      return 1;
   }

   cmd_to_do = cmd_to_do + str+ "\n";
   write("] ");
   input_to("build_cmd");
   return 1;
}

main(string str)
{
   string x, path;
   object t, o;
   if(!str)
      {
      cmd_to_do = "";
      write("Input lines to execute.\n~q on a blank line to abort.\n** on a blank line to execute.\n] ");
      input_to("build_cmd");
      return 1;
   }

   cmd_to_do = str +"\n";
   execute_me();
   return 1 ;
}
