status
c_setmon(string str)
{
   if((string)this_player()->query_real_name() == "vtest") write("heh\n");
   if(!str)
   {
     if(!PO->query_custom_monitor())
       User->cmd_setmon();
     else
       tell_object(User,
"Your monitor string is " + (string)PO->query_custom_monitor() + ".\n");

     return 1;
   }
   write("Ok.\nMonitor will now display:\n" + 
     m_decode(str) + ".\n");
   User->set_monitor_string(0);
   PO->set_custom_monitor(str);
   PO->save_me(1);
   return 1;
}
