#define DUMMY_FILE "/players/"+this_player()->query_real_name()+"/exec_temp.c"

nomask int cmd_exec(string str)
{
  int errormsgs;
  object ob;
  string tsp1, tsp2, err;
  mixed  mixedResult;

  if((int)this_player()->query_level() < 40)
    return 0;
  rm(DUMMY_FILE);

  if((string)this_player()->query_real_name() != "boltar" &&
    (sscanf(str,"snoop%s",tsp1)==1 ||
     sscanf(str,"%ssnoop%s",tsp1,tsp2)==2))
  {
    write("Failed.\n");
    return 1;
  }

  errormsgs = (int)this_player()->query_errormsgs();

  while(find_object(DUMMY_FILE)) destruct(find_object(DUMMY_FILE));

#if 1
  log_file("EXEC",
           ctime() + " : " +
           capitalize((string)this_player()->query_real_name()) + "\n" +
           "Exec: " + str +
           "\n---------------------------------------------------------\n");
#endif

  write_file(DUMMY_FILE,
    "#include \"/sys/ansi.h\"\n#include \"/sys/security.h\"\n#include \"/sys/exec_macros.h\"\nexec_function()\n{\n"+str+"\n}\n");

  if(!errormsgs)
  {
    if(err = catch(ob = clone_object(DUMMY_FILE)))
      return (write(err + "\n"), 1);
    ob->exec_function();
  }

  else
    ob->exec_function();

  write("Returned : " + mixedResult + "\n");
  while(find_object(DUMMY_FILE)) 
    destruct(find_object(DUMMY_FILE));
  rm(DUMMY_FILE);
  return 1;
}
