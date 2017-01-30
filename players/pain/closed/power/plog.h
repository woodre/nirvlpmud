
plog(str) {
if(!str) { command("tail /log/PAIN_WORKREPORT",this_player()); return 1; }
log_file("PAIN_WORKREPORT",ctime()+"->"+str+"\n");
write("It has been logged.\n");
return 1;
}
