c_monitor(string arg){

  if((string)this_player()->query_real_name() == "vtest") write("ok!\n");
  if(arg)
  {
  if(arg == "default" || arg == "default ansi" || arg == "ansi")
  {
      PO->set_custom_monitor(0);
      PO->save_me(1);
   }
    User->cmd_monitor(arg);
    return 1;
  }

  if(User->query_monitor_string())
  {
    User->print_monitor();         /* then print it :) */
    return 1;
  }

  GOB->print_monitor();
    
  return 1;
}
