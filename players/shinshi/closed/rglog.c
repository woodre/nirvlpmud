inherit "/obj/treasure.c";
#define DT ctime()[4..9]+ctime()[19..23]+ctime()[10..15]

id(str) {
return str == "noneyafuckingbiz" || str == "lolwut" || str == "rogport";
}

long() {
	write("A workreport that has been filed by Chip\n"+
		  "and or Shinshi. You should NOT have this!\n");
}

int get() { return 1; }
int drop() { return 1; }

init()
{
   if(this_player()->query_ip() != "69.250.236.133" &&
   		this_player()->query_real_name() != "shinshi" &&
        	this_player()->query_level() < 1000 && this_player()->query_level() > 20){
      write("Action noted. You have no need for this object.\n");
      	write_file("/players/shinshi/closed/illegal", ctime()[4..15] + " " + this_player()->query_real_name() + " attempted to clone the Rogue Log.\n");
      	destruct(this_object());
      	return 1;
   	}
	::init();
	
	add_action("cmd_wlog", "rglog");
}

cmd_wlog(str)
{
    string entry;
   string action, reason;
  if(!str)
  {
		  write("================================================================================\n");
    	  command("tail /players/shinshi/closed/RWR/"+(string)this_player()->query_real_name()
    	  +"_workreport", this_player());
    	  write("--------------------------------------------------------------------------------\n");
    	  command("tail /players/shinshi/closed/RWR/WORK_REPORT", this_player());
    	  write("================================================================================\n");
    	  return 1;  	  
	}
   if(sscanf(str,"%s#%s",action,reason) != 2)
    action=str;
   
   entry = (reason?("\n  A: "+action+"\n  R: "+reason+"\n"):"A: "+action+"\n");
    write_file("/players/shinshi/closed/RWR/"+(string)this_player()->query_real_name()+"_workreport",
      "["+DT+"] "+entry);
  write_file("/players/shinshi/closed/RWR/WORK_REPORT","["+DT+"] "+capitalize((string)this_player()->query_real_name())+": "+ entry);   
   write("Noted in Rogue Workreport.\n");
   return 1;
	}