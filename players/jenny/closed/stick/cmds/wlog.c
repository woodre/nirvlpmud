#include "/players/jenny/define.h"
main(str) {
string reason, action;

if(!str) {
                command("tail /log/WR"+this_player()->query_real_name()+"_workreport",this_player());

        return 1;
}
if(sscanf(str,"%s#%s",action,reason) != 2) {
        write("Usage: wlog action#reason\ni.e. wlog heal me#I was hurt.\n");
        return 1;
}
else {
write_file("/log/WR/"+TPRN+"_workreport",ctime()+RED+" ========|> "+NORM+action+YEL+" Reason: "+NORM+reason+"\n");
write("Wrote: Action: "+action+" Reason: "+reason+", to /log/WR/"+this_player()->query_real_name()+"_workreport.\n");
return 1;
}
}
