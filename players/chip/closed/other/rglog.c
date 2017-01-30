inherit "/obj/treasure.c";
#define DT ctime()[4..9]+ctime()[19..23]+ctime()[10..15]

id(str) {
return str == "noneyafuckingbiz" || str == "lolwut" || str == "rogport";
}

short() { return "A large booty (unwashed)"; }

long() {
        write("A workreport that has been filed by Chip\n"+
                  "and or Shinshi. You should NOT have this!\n");
}

void init()
{
        ::init();
        
        add_action("cmd_wlog", "rglog");
}

int cmd_wlog(string str)
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