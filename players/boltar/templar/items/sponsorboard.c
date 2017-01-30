#include "/players/jaraxle/ansi.h"
#define CAP 20
string who,by;
int ii,spcnt,done,date;
string sp1,sp2,sp3,vt1,vt2,vt3;

short() { return GRN+"Sponsorship board"+NORM; }

reset() {
  if(!done) {
    who=allocate(CAP);
    by=allocate(CAP);
    date=allocate(CAP);
    spcnt=allocate(CAP);
    sp1=allocate(CAP);
    sp2=allocate(CAP);
    sp3=allocate(CAP);
    vt1=allocate(CAP);
    vt2=allocate(CAP);
    vt3=allocate(CAP);
    done = 8;
    restore_object("players/boltar/templar/items/sponsorboard");
  }
}

add_pros(str) {
int i;
  if(!str) return 0;
  if(!find_player(str)) {
    write("No such person is playing now.\n");
    return 1;
  }
  if(!present("KnightTemplar", this_player())) {
    write("You are not a knight!\n");
    return 1;
  }
  if(find_player(str)->query_guild_name() == "Knights Templar") {
    write("That person is already a Knight!\n");
    return 1;
  }
  while(i < CAP) {
    if(!who[i]) {
      ii = i;
      i = CAP + 10;
    }
    i += 1;
  }
  i = 0;
  while(i < CAP) {
    if(who[i]==str) {
      write("That person is already on the board.\n");
      return 1;
    }
    i+=1;
  }
  who[ii]=str;
  by[ii]=this_player()->query_real_name();
  date[ii]=time();
  write_file("/players/boltar/templar/log/SPONONE",
  this_player()->query_real_name()+" put "+str+" on the board.\n");
  write("Prospect added to board.\n");
  save_object("players/boltar/templar/items/sponsorboard");
  return 1;
}
add_count(str) {
int i;
  while(i < CAP) {
    if(who[i]==str) {
      spcnt[i]+=1;
      i = CAP + 10;
    }
    i += 1;
  }
  save_object("players/boltar/templar/items/sponsorboard");
  return 1;
}
remove_entryman(str) {
int i,idnum;
  while(i < CAP) {
    if(who[i]==str) {
      idnum = i;
      i = CAP + 10;
    }
    i += 1;
  }
  if(by[idnum] != this_player()->query_real_name())
  if(this_player()->query_guild_rank() < 9 || !present("KnightTemplar", this_player())) {
    write("You do not have high enough rank in the knights.\n");
    return 1;
  }
  who[idnum]=0;
  spcnt[idnum]=0;
  save_object("players/boltar/templar/items/sponsorboard");
  return 1;
}

totals(i){
int tot;
tot = 0;
if(sp1[i]) tot += 1;
if(sp2[i]) tot += 1;
if(sp3[i]) tot += 1;
return tot;
}


long() {
int i;
  write("Please add prospective members to this board.\n\n");
  write("Usage:   "+GRN+"add "+NORM+"<"+GRN+"name"+NORM+">       Add prospective member\n");
  write("         "+GRN+"remove "+NORM+"<"+GRN+"name"+NORM+">    Remove entry\n");
  write("         "+GRN+"sponsor "+NORM+"<"+GRN+"name"+NORM+">   Sponsor entry \n");
  write("         "+GRN+"veto "+NORM+"<"+GRN+"name"+NORM+">      Veto entry\n");
  write("  \n");
  write("You must be guild rank 6+ to sponsor a prospective member.\n"+
    "  \n");
  write("Date:\t\t\t   Sponsors:\tName:     Added by:\n"+
    "  \n");
  while(i < CAP) {
    if(who[i])
    write(ctime(date[i])+"\t"+totals(i)+"\t"+who[i]+"     "+by[i]+"\n");
    i += 1;
  }
  return 1;
}
query_date(str) {
int i;
  while(i < CAP) {
    if(who[i]==str) {
      return date[i];
      i = CAP + 10;
    }
    i+=1;
  }
  return 0;
}

id(str) {
  return str == "board" || str == "sponsorboard";
}
init() {
  add_action("add_pros","add");
  add_action("remove_entryman","remove");
  add_action("sponsor","sponsor");
  add_action("veto","veto");
}

sponsor(str){
int i;
if(this_player()->query_guild_rank() < 6 ||
   !present("KnightTemplar", this_player())) return 0;
if(!str){ write("Sponsor whom?\n"); return 1; }
if(!query_entry(str)){ write("That person is not on the board yet.\n"); return 1; }
if(check_sp(this_player()->query_real_name(), str)){ write("You have already sponsored this person.\n"); return 1; }
i = 0;
while(i < CAP){
  if(who[i] == str){
     if(sp1[i] && sp2[i] && sp3[i]){
        write("That prospective member already has 3 sponsors.\n");
        return 1;
        }
     if(!sp1[i]) sp1[i] = this_player()->query_real_name();
     else if(!sp2[i] && sp1[i]) sp2[i] = this_player()->query_real_name();
     else if(!sp3[i] && sp1[i] && sp2[i]){ sp3[i] = this_player()->query_real_name();
      write_file("/players/boltar/templar/SPONSOR",
      "Sponsor: "+str+": "+sp1[i]+", "+sp2[i]+", "+sp3[i]+"\n");
      }
     }
i += 1;
}
write("You sponsor "+str+" as a member of the Knights Templar.\n");
save_object("players/boltar/templar/items/sponsorboard");
return 1;
}

veto(str){
int i;
if(this_player()->query_guild_rank() < 6 ||
   !present("KnightTemplar", this_player())) return 0;
if(!str){ write("Veto whom?\n"); return 1; }
if(!query_entry(str)){ write("That person is not on the board yet.\n"); return 1; }
if(check_vt(this_player()->query_real_name(), str)){ write("You have already vetoed that person.\n"); return 1; }
while(i < CAP){
  if(who[i] == str){
     if(vt1[i] && vt2[i]){
        write("You are the final veto for this prospect.\n"+
              "Removing them from the board...\n");
      write_file("/players/boltar/templar/VETO",
        "FINAL: "+str+": "+vt1[i]+","+vt2[i]+","+this_player()->query_real_name()+"\n");
      who[i]=0;
      spcnt[i]=0;
      sp1[i]=0;
      sp2[i]=0;
      sp3[i]=0;
      vt1[i]=0;
      vt2[i]=0;
      vt3[i]=0;
        write("Done.\n"+
              "Please notify Maledicta or Fakir of this occurence.\n");        
       write("You veto "+str+" as a member of the Knights Templar.\n");
       save_object("players/boltar/templar/items/sponsorboard");
       return 1;

        }
     if(!vt1[i]) vt1[i] = this_player()->query_real_name();
     else if(!vt2[i] && vt1[i]) vt2[i] = this_player()->query_real_name();
     }
i += 1;
}
write("You veto "+str+" as a member of the Knights Templar.\n");
save_object("players/boltar/templar/items/sponsorboard");
return 1;
}


check_vt(str, str2){
int i;
while(i < CAP){
  if(who[i] == str2){
     if(vt1[i] == str || vt2[i] == str || vt3[i] == str) return 1;
  }
i += 1;
}
return 0;
}

check_sp(str, str2){
int i;
while(i < CAP){
  if(who[i] == str2){
     if(sp1[i] == str || sp2[i] == str || sp3[i] == str) return 1;
  }
i += 1;
}
return 0;
}


remove_entry(str) {
int i;  while(i < CAP) {
    if(who[i]==str) {
      who[i]=0;
      by[i]=0;
      date[i]=0;
      spcnt[i]=0;
      sp1[i]=0;
      sp2[i]=0;
      sp3[i]=0;
      vt1[i]=0;
      vt2[i]=0;
      vt3[i]=0;
      i = CAP + 10;
    }
    i += 1;
  }
  save_object("players/boltar/templar/items/sponsorboard");
  return 1;
}

query_sponsored(str){
int i;
if(!query_entry(str)) return 0;
while(i < CAP){
  if(who[i] == str){
     if(sp1[i] && sp2[i] && sp3[i]) return 1;
  }
i += 1;
}
return 0;
}

query_entry(str){
int i;
while(i < CAP){
  if(who[i] == str) return 1;
 i += 1;
 }
return 0;
}
