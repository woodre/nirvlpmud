inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("box");
  set_short("Voting Box");
  set_weight(100000000);
}

long() {
  write("This is Grimm's Voting Box.  You can cast a vote on who you would\n"+
        "like to see as the next Guild Commander by typing:\n"+
        "\"vote <name>\"\n"+
        "and you can see a tally of the top 10 people voted on by typing:\n"+
        "\"summary\"\n"+
        "\nNOTE:  You can only vote 1 time per election!\n");
  return 1;
}

init() {
  add_action("vote","vote");
  add_action("summary","summary");
}

scan(str) {
  int i,j;
  string ln,who,by;
  i=1;
  ln=read_file("/players/grimm/closed/obj/badge_stuff/vbox.talley",i);
  j=0;
  while(ln && !j) {
    sscanf(ln,"%s %s\n",who,by);
    if(by==str) j=1;
    i++;
    ln=read_file("/players/grimm/closed/obj/badge_stuff/vbox.talley",i);
  }
  return j;
}

vote(str) {
  string who,by;
  if(!str) {
    write("Who do you want to vote on?\n");
    return 1;
  }
  if(scan(this_player()->query_real_name())) {
    write("You've already voted!\n");
    return 1;
  }
  who=lower_case(str);
  if(!check(who)) {
    write(capitalize(who)+" is not yet on the guild's register.\n");
    return 1;
  }
  write_file("/players/grimm/closed/obj/badge_stuff/vbox.talley",
             who+" "+this_player()->query_real_name()+"\n");
  write("Your vote has been entered.\n");
  say(capitalize(this_player()->query_name())+" puts a vote in the voting box.\n");
  return 1;
}

summary() {
  int i,j,k,l,m,n;
  int done;
  string peepl;
  string ln;
  string nme,by;
  done=0;
  j=allocate(1000);
  peepl=allocate(1000);
  for(i=0;i<1000;i++) {
    j[i]=0;
    peepl[i]=" ";
  }
  i=1;
  ln=read_file("/players/grimm/closed/obj/badge_stuff/vbox.talley",i);
  while(ln) {
    sscanf(ln,"%s %s\n",nme,by);
    k=0;
    while(k<1000) {
      if(peepl[k]==nme) j[k]=j[k]+1;
      else
        if(peepl[k]==" " && j[k]==0) {
        peepl[k]=nme;
        j[k]++;
        k=10000;
      }
     k++;
    }
    i++;
    ln=read_file("/players/grimm/closed/obj/badge_stuff/vbox.talley",i);
  }
  write("Doppleganger Top Five Choices for Guild Commander:\n\n");
  for(i=0;i<5;i++) {
     l=0;
     m=0;
     if(!done) {
    for(k=0;k<900;k++) {
       if(!j[k]) j[k]=0;
      if(j[k]>l) {
        m=k;
        l=j[k];
      }
   }
    }
    if(l==0) done=1;
    else
    {
    write((i+1)+"\t"+capitalize(peepl[m]));
    if(strlen(peepl[m])>7) write("\t");
    else write("\t\t");
    write(j[m]+"\n");
    j[m]=0;
    nme=peepl[m];
    for(n=0;n<1000;n++) {
      if(peepl[n]==nme) {
        peepl[n]=" ";
        j[n]=0;
      }
    }
     }
  }
  return 1;
}

check(who) {
  string ln;
  int i,found;
  found=0;
  i=1;
  ln=read_file("/players/grimm/closed/obj/badge_stuff/register",i);
  while(ln && !found) {
    if(ln==who+"\n") {
      found=1;
    }
    i++;
    ln=read_file("/players/grimm/closed/obj/badge_stuff/register",i);
  }
  return found;
}
