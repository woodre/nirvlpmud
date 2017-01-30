/****************************************************************************/
/* Party Object, Made by Murky 9/6-1991.  Version 1.0                       */
/*                                                                          */
/* You are free to copy this object, but you will need to change your       */
/* local living.c in hit_player().  Add this before add_exp() is called:    */
/*     if(attacker_ob) {                                                    */
/*         object party;                                                    */
/*         party=present("party object",attacker_ob);                       */
/*         if(party) party->share_exp(experience/35);                       */
/*         else attacker_ob->add_exp(experience/35);                        */
/*     }                                                                    */
/* You might also want to change the function short() in player.c to this:  */
/*   short() {                                                              */
/*     object ob;                                                           */
/*     (* Here comes tests of is_invis/ghost/frog *)                        */
/*     ob=present("party object",this_object());                            */
/*     if(ob) return cap_name+" "+title+" ("+al_title+")"+ob->extra_short();*/
/*     return cap_name+" "+title+" ("+al_title+")";                         */
/*   }                                                                      */
/*                                                                          */
/* Send bugreports to frankj@ifi.uio.no or to murky on VikingMUD.           */
/****************************************************************************/

/* Max members in a party.  Game might be slow if this is set high */
#define MAX_MEMBERS 6

/* Logfile.  Define it to '0' if you don't want logging. */
#if 1 /* Logging this for now - Rumplemintz */
#define LOGFILE "PARTY_EXP"
#else
#define LOGFILE 0
#endif

/* If this object isn't the leader object, it cointains the leader object: */
static object leader_ob;

/* owner_ob is usually the environment of this object */
static object owner_ob;

/* members is an array of all members */
static object members;

/* leader is 1 if this is the leader object, otherwise 0 */
static int leader;

/* nrofmembers returns the number of members (not including the leader) */
static int nrofmembers;

/* membernr contains the member-number (the place in the array members[]) */
static int member_nr;

/* follow is an array of flags.  if follow[1]==1, member #1 will follow */
static int follow;

/* toggle is used in the function do_copy to avoid endless recursion */
static int toggle;

/* tot_exp and tot_share are logs of experience given to the party */
static int tot_exp, tot_share;

/* An array of which shares the different members have: */
static int contract;

/* The sum of shares in contract: */
static int contract_sum;

/* party_name contains the party name selected */
static string party_name;

/* What to clone to get another party object: */
static string filepath;

id(str) { return str=="party"||str=="party object"||str=="object"; }

get() {
  if(this_player()&&this_player()->query_npc()) return 0; /*I don't like Harry*/
  if(query_verb()=="get"||query_verb()=="take") {
    if(present("party object",this_player())) {
      write("But you already have a party object!\n");
      return 0;
    }
    write("You should now set a party name with \"party name <str>\".\n");
    /* Create another party-object where the first was found: */
    move_object(clone_object(filepath), environment(this_object()));
  }
  return 1;
}

drop() {
  if(query_verb()=="sell") return 1;
  if(query_verb()=="drop") {
    write("Type 'party leave' to leave the party.\n");
    return 1;
  }
  if(leader) do_disband();
  else leader_ob->do_cutout(member_nr);
  write("The party object selfdestructs as it hits the ground.\n");
  destruct(this_object());
  return 1;
}

reset(arg) {
  int i;
  if(arg) return;
  nrofmembers=0; leader_ob=0; owner_ob=0; leader=1; member_nr=0; toggle=0;
  tot_exp=0; tot_share=0; party_name=""; contract_sum=0;
  members=allocate(MAX_MEMBERS+1);
  follow=allocate(MAX_MEMBERS+1);
  contract=allocate(MAX_MEMBERS+1);
  for(i=1;i<=MAX_MEMBERS;i++) { members[i]=0; follow[i]=0; contract[i]=0; }
  sscanf(object_name(this_object()),"%s#%d",filepath,i);
}

short() {
  if(leader) return "A party object (leader)";
  return "A party object ("+leadername()+":"+member_nr+")";
}

long() {
  write("Commands:\n");
  write("party status              -Lists members and other info.\n");
  write("party leave               -To leave the party.  If the leader\n");
  write("                           leaves the party, it is disbanded.\n");
  write("party follow              -Toggles following the party leader.\n");
  write("party say message         -Sends a message to all members.\n");
  write("party name party_name     -Sets a party name (displayed in who).\n");
  write("\nIf you're the party leader, you can also do the following:\n");
  write("party add member          -Adds a member to your party.\n");
  write("party share member nr     -Sets nr. of shares to that member.\n");
  write("party remove member       -Removes a member from your party.\n");
  write("party leader member       -Changes the leader of the party.\n");
  write("party reset               -Resets you as owner, do after disconnect.\n");
  write("\nThe experience is divided at once.  'party status' keeps a log.\n");
}

init() {
  if(this_player()==environment()) {
    owner_ob=this_player();
    add_action("do_party","party");
    if(leader) {
      if(!contract_sum) {
        contract_sum=min_share(owner_ob->query_level());
        contract[0]=contract_sum;
        members[0]=this_object();
        set_nr(0);
      }
      add_action("do_copy","enter");
      add_action("do_copy","exit");
      add_action("do_copy","north");
      add_action("do_copy","south");
      add_action("do_copy","east");
      add_action("do_copy","west");
      add_action("do_copy","southwest");
      add_action("do_copy","southeast");
      add_action("do_copy","northwest");
      add_action("do_copy","northeast");
      add_action("do_copy","up");
      add_action("do_copy","down");
      add_action("do_copy","out");
      add_action("do_copy","in");
      add_action("do_copy","crawl");
      add_action("do_copy","jump");
      add_action("do_copy","swim");
      add_action("do_copy","dive");
      add_action("do_copy","board");
      add_action("do_copy","climb");
    }
  }
}

query_party_name() {
  if(!leader) return leader_ob->query_party_name();
  return party_name;
}

extra_short() {
  string pname;
  pname=query_party_name();
  if(pname=="") return "";
  if(leader) return " (leader of "+pname+")";
  return " (member of "+pname+")";
}

set_leader(ob) { leader=0; leader_ob=ob; }

query_leader() { return leader_ob; }

query_nr() { return member_nr; }

set_nr(i) { member_nr=i; }

leadername() {
  if(leader) return name();
  return leader_ob->name();
}

tell_leader(str) {
  if(leader) tell_object(owner(),str);
  else tell_object(leader_ob->owner(),str);
}

name() { return capitalize(owner_ob->query_real_name()); }

owner() { return owner_ob; }

max_share(lvl) {
  return lvl;
}

min_share(lvl) {
  return lvl/5+1;
}

share_exp(exp) {
  int share,i;
  if(!leader) return leader_ob->share_exp(exp);
  tot_exp+=exp;
  if(!nrofmembers) return owner_ob->add_exp(exp);
  share=exp/contract_sum+1;
/*
 share+=share*nrofmembers/10;* 10% bonus for each member */
  tot_share+=share;
  owner_ob->add_exp(share*contract[0]);
#ifdef LOGFILE
  log_file(LOGFILE,name()+"(leader of "+party_name+"): "+
           share*contract[0]+"\n");
#endif
  for(i=1;i<=nrofmembers;i++) {
    if(environment(members[i]->owner()) == environment(owner_ob)){
    call_other(members[i]->owner(),"add_exp",share*contract[i]);
    } else
          tell_object(members[i]->owner(), "You must be with the leader to gain experience.\n");
#ifdef LOGFILE
    log_file(LOGFILE,members[i]->name()+"("+i+" of "+party_name+"): "+
             share*contract[i]+"\n");
#endif
  }
}

do_party(arg) {
  string who;
  int i;
  if(arg=="status") return do_status();
  if(arg=="leave") return do_leave();
  if(arg=="follow") return do_follow();
  if(arg=="reset") {
       owner_ob=this_player();
     return 1;
   }
  notify_fail("Look at your party object to find out usage.\n");
  if(!arg) return;
  if(sscanf(arg,"say %s",who)) return do_say(member_nr,who);
  if(sscanf(arg,"name %s",who)) return do_set_name(who);
  if(!leader) return 0;
  if(sscanf(arg,"add %s",who)) return do_add(who);
  if(sscanf(arg,"remove %s",who)) return do_remove(who);
  if(sscanf(arg,"leader %s",who)) return do_leader(who);
  if(sscanf(arg,"share %s %d",who,i)==2) return do_share(who,i);
  return 0;
}

do_set_name(str) {
  if(!str) {
    notify_fail("Next argument would have been the party name.\n");
    return 0;
  }
  if(strlen(str)>16) {
    write("Too long party name.  Max 16 characters.\n");
    return 1;
  }
  party_name=str;
  do_say(member_nr,"New party name is "+str+".");
  return 1;
}

do_status() {
  int i;
  if(!leader) return leader_ob->do_status();
  if(party_name=="") write("No party name yet (use \"party name <str>\")\n");
  else write("Partyname: "+party_name+"\n");
  write("Total experience given:      "+tot_exp+"\n");
  write("Experience shared (1 share): "+tot_share+"\n");
  write("Number of shares:            "+contract_sum+"\n");
  write("Party leader: "+leadername()+" ["+contract[0]+"]\n");
  if(!nrofmembers) {
    write("There are no members.\n");
    return 1;
  }
  write("Members:\n");
  for(i=1;i<=nrofmembers;i++) {
    write(i+": "+members[i]->name()+" ["+contract[i]+"]");
    if(follow[i]) write(" (following)\n");
    else write("\n");
  }
  return 1;
}

do_follow() {
  if(leader) {
    notify_fail("You can't follow yourself!\n");
    return 0;
  }
  return leader_ob->toggle_follow(member_nr);
}

toggle_follow(nr) {
  if(follow[nr]) {
    follow[nr]=0;
    write("You no longer follow "+leadername()+".\n");
    tell_leader(capitalize(this_player()->query_real_name())+
                " no longer follow you.\n");
    return 1;
  }
  if(!present(owner(),environment(this_player()))) {
    notify_fail("But "+leadername()+" isn't present!\n");
    return 0;
  }
  follow[nr]=1;
  write("You now follow "+leadername()+".\n");
  tell_leader(capitalize(this_player()->query_real_name())+
              " starts following you.\n");
  return 1;
}

do_copy(arg) {
  string vb;
  object room;
  int i;
  if(!toggle) call_out("fix_init",0);
  if(toggle||!nrofmembers) return 0;
  room=environment(owner_ob);
  vb=query_verb();
  if(arg) vb=vb+" "+arg;
  toggle=1;
  command(vb,owner_ob);
  if(room!=environment(owner_ob)) {
    fix_init();
    for(i=1;i<=nrofmembers;i++)
      if(follow[i]) {
        if(environment(members[i]->owner())!=room) {
          write("You have lost "+members[i]->name()+".\n");
          follow[i]=0;
/*
       command(members[i], "party follow");
       tell_object(members[i], "You have lost track of "+leadername()+".\n");
*/
        }
        else {
          tell_object(members[i]->owner(),"You follow "+name()+".\n");
          command(vb,members[i]->owner());
        }
      }
  }
  toggle=0;
  return 1;
}

fix_init() {
  move_object(this_object(),owner_ob);
}

do_say(nr,msg) {
  int i;
  if(!msg) return 0;
  if(!leader) return leader_ob->do_say(nr,msg);
  for(i=0;i<=nrofmembers;i++) {
    tell_object(members[i]->owner(),
                members[nr]->name()+" [Party:"+nr+"]: "+msg+"\n");
  }
  return 1;
}

do_add(who) {
  object ob;
  if(!who) return 0;
  who=lower_case(who);
  ob=find_player(who);
  if(!ob) return 0;
  if(!present(ob,environment(this_player()))) {
    notify_fail("But that player isn't present!\n");
    return 0;
  }
  if(present("party object",ob)) {
    notify_fail("But that player is already member of a party!\n");
    return 0;
  }
  if(nrofmembers==MAX_MEMBERS) {
    notify_fail("There can only be "+MAX_MEMBERS+" members in a party.\n");
    return 0;
  }
  do_say(0,capitalize(ob->query_real_name())+
         " is now a member of the party.");
  nrofmembers++;
  members[nrofmembers]=clone_object(filepath);
  members[nrofmembers]->set_leader(this_object());
  members[nrofmembers]->set_nr(nrofmembers);
  move_object(members[nrofmembers],ob);
  contract[nrofmembers]=min_share(ob->query_level());
  contract_sum+=contract[nrofmembers];
  tell_object(ob,"You're now a member of "+leadername()+"'s party");
  if(party_name!="")
    tell_object(ob," called "+party_name+".\n");
  else
    tell_object(ob,".\n");
  do_say(0,ob->query_name()+" will now receive "+contract[nrofmembers]+"/"
          +contract_sum+" of the party's experience.");
  tell_object(ob,"Type 'look at party' and 'party status' to receive "+
              "further help.\n");
  return 1;
}

get_party_ob(who) {
  object party_ob, ob;
  if(!who)
    return notify_fail("One more parameter expected.\n");
  who=lower_case(who);
  ob=find_player(who);
  if(!ob)
    return notify_fail("No such player logged on now.\n");
  party_ob=present("party object",ob);
  if(!party_ob)
    return notify_fail("But that player isn't a member of any party!\n");
  if(party_ob->query_leader()!=this_object())
    return notify_fail("But that player isn't a member of your party!\n");
  return party_ob;
}

do_remove(who) {
  object party_ob,ob;
  party_ob=get_party_ob(who);
  if(!party_ob) return 0;
  ob=environment(party_ob);
  do_cutout(party_ob->query_nr());
  destruct(party_ob);
  tell_object(ob,"You are removed from the party.\n");
  do_say(0,capitalize(ob->query_real_name())+" is removed from the party.");
  return 1;
}

do_leader(who) {
  object party_ob,ob;
  int i;
  party_ob=get_party_ob(who);
  if(!party_ob) return 0;
  if(!present(party_ob->owner(),environment(this_player()))) {
    notify_fail("The new leader must be present.\n");
    return 0;
  }
  follow[party_ob->query_nr()]=0;
  i=contract[0];
  contract[0]=contract[party_ob->query_nr()];
  contract[party_ob->query_nr()]=i;
  ob=environment(party_ob);
  do_say(0,party_ob->name()+" is the new leader of the party.");
  move_object(party_ob,environment());
  move_object(this_object(),ob);
  return 1;
}

do_share(who,i) {
  object party_ob;
  int lvl;
  if(who&&lower_case(who)==this_player()->query_real_name())
    party_ob=this_object();
  else {
    party_ob=get_party_ob(who);
    if(!party_ob) {
      notify_fail("Change which share?  There is no such member.\n");
      return 0;
    }
  }
  lvl=call_other(party_ob->owner(),"query_level");
  if(i<min_share(lvl)||i>max_share(lvl)) {
    write("Share out of range.  Choose a number between "+
          min_share(lvl)+" and "+max_share(lvl)+".\n");
    return 1;
  }
  contract_sum-=contract[party_ob->query_nr()];
  contract[party_ob->query_nr()]=i;
  contract_sum+=i;
  do_say(0,party_ob->name()+" will now receive "+i+" share(s).");
  return 1;
}

do_leave() {
  if(leader) {
    write("OK, the party is disbanded.\n");
    do_disband();
    destruct(this_object());
    return 1;
  }
  do_say(member_nr,name()+" left the party.");
  leader_ob->do_cutout(query_nr());
  destruct(this_object());
  return 1;
}

do_disband() {
  int i;
  if(!nrofmembers) return;
  for(i=1;i<=nrofmembers;i++) {
    if(members[i]->owner()) {
    tell_object(members[i]->owner(),"The party is disbanded.\n");
    destruct(members[i]);
    }
  }
  nrofmembers=0;
}

do_cutout(nr) {
  int i;
  contract_sum-=contract[nr];
  if(nr==nrofmembers)
    return nrofmembers--;
  for(i=nr;i<nrofmembers;i++) {
    members[i]=members[i+1];
    follow[i]=follow[i+1];
    contract[i]=contract[i+1];
    members[i]->set_nr(i);
  }
  nrofmembers--;
}
