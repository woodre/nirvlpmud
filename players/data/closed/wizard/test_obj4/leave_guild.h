leave_it(){
 if(USER->query_level() > 19){
  tell_object(USER, "Dest this object, you're a wiz.\n");
  return 1;
  }             
tell_object(USER,
"You decide to quit your job and lose some experience.\n");
write_file("/players/data/closed/wizard/logs/LEAVE", ctime(time())+
           "   "+HIR+USER->query_real_name()+NORM+" [L "+
           USER->query_level()+"+"+USER->query_extra_level()+"] \n"+NORM);
if(USER->query_attrib("str") > 20){ USER->set_attrib("str", 20); }
if(USER->query_attrib("ste") > 20){ USER->set_attrib("ste", 20); }
if(USER->query_attrib("sta") > 20){ USER->set_attrib("sta", 20); }

   USER->death();
   USER->set_guild_name(0);
   USER->save_me();
   USER->reset();
   rm("/players/data/closed/wizard/member/"+USER->query_real_name()+".o");
if(present("KnightTemplar", USER)){
   write("You also leave the Templars.\n");
    USER->add_guild_rank(-USER->query_guild_rank());
     USER->set_home("/room/church");
     destruct(present("KnightTemplar", USER));
      }
   destruct(this_object());
   return 1;       
   }
