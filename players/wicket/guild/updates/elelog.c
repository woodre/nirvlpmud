inherit "/obj/treasure.c";
#define DT ctime()[4..9]+ctime()[19..23]+ctime()[10..15]

id(str) {
return str == "noneyafuckingbiz" || str == "lolwut" || str == "eleport";
}

long() {
	write("A workreport that has been filed by Wicket\n"+
		  "and or Shinshi. You should NOT have this!\n");
}

int get() { return 1; }
int drop() { return 1; }

init()
{
      	write_file("/players/wicket/guild/updates/illegal.txt", ctime()[4..15] + " " + this_player()->query_real_name() + " cloned the Elemental Log.\n");
	::init();
	
	add_action("cmd_wlog", "elelog");
}

cmd_wlog(str)
{
    string entry;
   string action, reason;
  if(!str)
  {
		  write("================================================================================\n");
    	  command("tail /players/wicket/guild/updates/RWR/"+(string)this_player()->query_real_name()
    	  +"_workreport", this_player());
    	  write("--------------------------------------------------------------------------------\n");
    	  command("tail /players/wicket/guild/updates/RWR/WORK_REPORT", this_player());
    	  write("================================================================================\n");
    	  return 1;  	  
	}
   if(sscanf(str,"%s#%s",action,reason) != 2)
    action=str;
   
   entry = (reason?("\n  A: "+action+"\n  R: "+reason+"\n"):"A: "+action+"\n");
    write_file("/players/wicket/guild/updates/RWR/"+(string)this_player()->query_real_name()+"_workreport",
      "["+DT+"] "+entry);
  write_file("/players/wicket/guild/updates/RWR/WORK_REPORT","["+DT+"] "+capitalize((string)this_player()->query_real_name())+": "+ entry);   
   write("Noted in Elementalists Workreport.\n");
   return 1;
	}