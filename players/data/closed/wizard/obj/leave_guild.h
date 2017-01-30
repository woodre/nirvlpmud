leave_it(){
 if(USER->query_level() > 19){
  tell_object(USER, "Dest this object, you're a wiz.\n");
  return 1;
  }             
tell_object(USER,
"You decide to quit your job and lose some experience.\n");
write_file("/players/maledicta/closed/w/logs/LEAVE", ctime(time())+
           "   "+HIR+USER->query_real_name()+NORM+" [L "+
           USER->query_level()+"+"+USER->query_extra_level()+"] \n"+NORM);
rm("/players/maledicta/closed/w/member/"+USER->query_real_name()+".o");
if(USER->query_attrib("str") > 30){ USER->set_attrib("str", 30); }
if(USER->query_attrib("ste") > 30){ USER->set_attrib("ste", 30); }
if(USER->query_attrib("sta") > 30){ USER->set_attrib("sta", 30); }

   USER->death();
   USER->set_guild_name(0);
   USER->add_guild_exp(-USER->query_guild_exp());   /*  Added 7/11/03.....Fred  */
   USER->save_me();
   USER->reset();
   destruct(this_object());
   return 1;       
   }
