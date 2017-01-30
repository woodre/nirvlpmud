inherit "obj/monster";

#define ME "rumplemintz"        /* thats me. */
#undef  HEART             /* have heartbeat (otherwise rest won't work) */
#define TOOLS ({/*"lfun","players/rumplemintz/closed/tools/lfun",*/ \
                "trace","players/rumplemintz/closed/tools/trace", \
                "stick","players/rumplemintz/closed/tools/stick", \
                /*"glasses","players/rumplemintz/closed/tools/glasses",*/ \
                /*"shadow","players/rumplemintz/closed/shad/shadower",*/ \
                })        /* tools to give me (undef for none) */
#undef TOOLS
#define WATCH_SNOOPS      /* inform me of snoops */
/*  not on VR :(
#define PROTECT ({"rumplemintz","rumpsen","rump","timmy","john" })
                          /* people to protect -- only if WATCH_SNOOPS */
#define TITLES ({"E. Harshaw loves Welch's Grape Soda (sparkling)", \
  "E. Harshaw is too sexy for this mud", \
  "E. Harshaw of the many titles", \
  "\b\b\b\b\b\bHave you sent a dollar to Rumplemintz today? ($$$)", \
  "\b\b\b\b\b\b              -- rump", \
  "\b\b\b\b\b\bthis_player()->query_real_name() { return \"rumplemintz\"; }", \
"\b\b\b\b\b\bYour sensitive mind notices a rumpleness in the fabric of space.", \
  "\b\b\b\b\b\b\b\b\b\b\b\b\b(Rumplemintz) ;)", \
  "says: Beep me if its not important!", \
  })
#define MYFILE "players/rumplemintz/closed/tools/valentine"

static me;
static snoops;

reset(arg) {
  if (arg) return;
  ::reset(arg);
  set_name("valentine");
  set_gender(1);
  set_short("Valentine Michael Smith (The Man From Mars)");
  set_long("This is Rumplemintz's friend,\n" +
           "The man from mars.\n");
  set_level(100000);
  set_hp(10000000);
  set_ac(10000);
  set_wc(10000);
  set_al(1000);
  me=0;  snoops=({});
  enable_commands();
#ifdef HEART  /* only start up if its a clone */
  start();
#endif /* HEART */
}

id(str) { return str=="mike" || str=="valentine" || str=="michael"; }
query_real_name(){ return "valentine"; }
query_name() { return "Valentine"; }

/* VR needs a space after the says:...   who knows..  :( */
catch_tell(str) {
/*
  if(me) tell_object(me,"home: "+str);
*/
  if(str=="Rumplemintz says: off \n") {
    say("Valentine says: Shutting down.\n");
    set_heart_beat(0);
  }
  if(str=="Rumplemintz says: on \n") {
    say("Valentine says: Booting up security systems\n");
    start();
  }
}

start() {
  string tmp;
  if(sscanf(file_name(this_object()),MYFILE+"#%s",tmp)==1)
    set_heart_beat(1);  
}

heart_beat() {
  object a,tmp;
  int i;

  a=users();

  tmp=find_player(ME);
  if(tmp && !me) {
    me=tmp;
    welcome_me();
  }
  me=tmp;

/* Ideally, at some point this could be written such that the loop
 * doesn't even run if !me and #ifndef PROTECT..  oh well..
 */
#ifdef WATCH_SNOOPS
  for(i=0;i<sizeof(a);i++)
    if(a[i] && (tmp=query_snoop(a[i]))) {
#ifdef PROTECT
      if(member_array(a[i]->query_real_name(),PROTECT)!=-1) desnoop(a[i]);
      else
#endif /* PROTECT */
      if(me) add_snoop(a[i],tmp);
    }

  i=0;
  while(i<sizeof(snoops)) {
    if(snoops[i][0] && ((tmp=query_snoop(snoops[i][0]))!=snoops[i][1]))
      if(tmp) change_snoop(i,tmp);
      else remove_snoop(i);
    else i++;
  }
#endif /* WATCH_SNOOPS */

#ifdef TITLES
  if(me) me->set_title(TITLES[random(sizeof(TITLES))]);
#endif /* TITLES */

   return 1;
}

welcome_me() {
  tell_object(me,"Valentine tells you: Hello Rumplemintz.\n");
#ifdef TOOLS
  load_tools(me);
#endif
}

add_snoop(who,by) {
  snoops+=({ who, by });
  tell_object(me,who->query_name()+" is being snooped by "
                 +by->query_name()+"\n");
}

remove_snoop(num) {
  if(snoops[num][1])
    tell_object(me,snoops[num][0]->query_name()+" no longer snooped by "
                   +snoops[num][1]->query_name()+"\n");
  else tell_object(me,snoops[num][0]->query_name()
                      +"'s snooper has left the game.\n");
  snoops-=({ snoops[num] });
}

/* not likely, but worth mentioning if it happens */
change_snoop(num,new) {
  object tmp;

  tmp=snoops[num][0];
  remove_snoop(num);
  add_snoop(tmp,new);
}

#ifdef TOOLS
load_tools(me) {
  int i;

  i=0;
  while(i<sizeof(TOOLS)) {
    if(!present(TOOLS[i],me)) {
      move_object(clone_object(TOOLS[i+1]),me);
      tell_object(me,"Valentine hands you a "+TOOLS[i]+".\n");
    }
    i+=2;
  }
}
#endif /* TOOLS */

#ifdef PROTECT   /* no need to load it unless protect is defined */
desnoop(who) {
  object snooper,soff;

  snooper=query_snoop(who);
  soff=clone_object("players/rumplemintz/closed/tools/snoopoff");
  move_object(soff,snooper);
  command("look", snooper);
  tell_object(who, "You were snooped by "+snooper->query_name()+"\n");
  if(me) tell_object(me,"Desnooped: "+snooper->query_name()+" (snooping: "
                     +who->query_name()+")\n");
}
#endif /* PROTECT */

