#define save_me() save_talk()
#define TP this_player()
#define user this_player()
#define RN user->query_real_name()
#define LV user->query_level()
#define TE tell_object

inherit "obj/clean";

string pres, posts;

object P (object ob) {
   object returned_ob;
   returned_ob = present("talker", ob);
   return returned_ob;
}

versions() {
   object talkor;
   object * list;
   int i;
   list=users();
   for(i=0; i < sizeof(list); i++) {
      talkor = P(list[i]);
      if(talkor) {
        write(list[i]->query_real_name()+"'s talker is version: "+
          talkor->query_version()+", ");
        if(talkor->query_version() != "400x")
          write("it needs updating.\n");
        else write("it is like new.\n");
         }
    }
    return 1;
}

uselist() {
write("_______________Version 400x________________\n"+
      "Simply customize your says with\n"+
      "  presay <whatever>      pretell <whatever>\n"+
      "  postsay <whatever>     posttell <whatever>\n"+
      "\n"+
      "And start talkin' with:\n"+
      "  sy <what>              for fancy says\n"+
      "\n"+
      "*Fancy says are free, they don't cost any sp!\n"+
      ":O  For talker commands, type 'talkmagic'\n\n");
return 1;
}

talkmagic() {
   write(
"~~~~~~~~~~~~~~~~~~~~~ Talk Magic! ~~~~~~~~~~~~~~~~~~~~~\n"+
"sy <message>              fancy say\n"+
"presay <script>           set your preceeding scripts\n"+
"postsay <script>          set your postceeding scripts\n"+
"viewtalk                  view all talker settings\n"+
"savetalk                  save all talker settings\n"+
"loadtalk                  loads all talker settings\n"+
"totaltalk <on/off>        makes you fancy talk all the time\n"+
"newtalk                   makes your talker up to date\n"+
"whotalk                   shows who has a talker, etc.\n"+
"givetalk <towho>          share your talker\n"+
"notalk                    trash your talker\n");

   if( (TP->query_real_name() == "dune") ||
       (P(TP)->query_talkmaster()) ||
       (LV >= 20) ) {
         write(
"versions                  shows the version of talkers\n"+
"talkup <who>              updates an inividual's talker\n"+
"talkrm <who>              removes a person's talker\n"+
"talkupall                 updates everyone's talker\n");
         }
   if (RN == "dune") {
         write(
"master <who> <yes/no>     makes/unmakes talkmasters\n");
         }
write(
"talknote <message>        any bugs, comments, questions?\n");
write(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

totaltalk(string str) {
  int old;
  if(!str) {
    write("Usage: totaltalk <on/off>\n");
    return;}
  if((str == "off") || (str == "on")) {
    old = P(TP)->query_totaltalk();
    if(str == "off") {
      if(!old) {
        write("Your talking was already limited to 'sy'\n");
        return;}
      else {
        write("Your talking is now limited to 'sy' commands\n");
        P(TP)->change_totaltalk(0);
        P(TP)->save_me();
        P(TP)->newtalk();
        return;}
      }
    if(str == "on") {
      if(old) {
        write("Your 'say' command was already overwritten.\n");
        return;}
      else {
        write("You can now just type 'say' to fancy talk.\n");
        P(TP)->change_totaltalk(1);
        P(TP)->save_me();
        P(TP)->init();
        return;}
      }
    }
  write("Usage: totaltalk <on/off>\n");
}



sy(str) {
   string name, Name;
   pres = P(TP)->query_presay();
   posts = P(TP)->query_postsay();
   name = this_player()->query_real_name();
   if (!str) {
      write("Usage: sy [message].\n");
      return 1;}
   Name = capitalize(name);
   str = format(str, 60);
   if ((pres == 0) && (posts != 0)) {
     say(Name+" "+posts+": "+str+"\n");
     write("You fancy say: "+str+"\n");
     return 1;}
   if ((posts == 0) && (pres != 0)) {
     say(pres+" "+Name+" says: "+str+"\n");
     write("You fancy say: "+str+"\n");
     return 1;}
   if ((posts == 0) && (pres == 0)) {
     say(Name+" says: "+str+"\n");
     write("You fancy say: "+str+"\n");
     return 1;}
   say(pres+" "+Name+" "+posts+": "+str+"\n");
   write("You fancy say: "+str+"\n");
   return 1;
}

viewtalk() {
   int qmast;
   pres = P(TP)->query_presay();
   posts = P(TP)->query_postsay();
   qmast = P(TP)->query_talkmaster();

   write("Fancy Talker Settings:\n");
   if(qmast) {
      write(
         "You are Talkmaster!\n"); }
   write("______________________\n");
   write("Pre-say   --- "+pres+"\n");
   write("Post-say  --- "+posts+"\n");
   write("______________________\n");
   return 1;
}

int check1(string str) {
   if (strlen(str) > 20) {
      write("Script length limited to 20 characters long.\n");
      return 0;}
   return 1;
}

int check2(string str) {
   if (strlen(str) > 15) {
      write("Script length limited to 15 characters long.\n");
      return 0;}
   return 1;
}


notalk() {
   object tempno;
   write("You utterly trash your talker  :( \n");
   tempno = P(TP);
   destruct(tempno);
   return 1;}



presay(string str) {
   string pres;
   pres = P(TP)->query_presay();
   if(!str) {
      write("Pre-say script cleared.\n");
      pres = str;
      P(TP)->change_presay(pres);
      P(TP)->save_me();
      return 1; }
   if(check2(str)) {
      pres = str;
      if(str) write("Pre-say script changed to '"+pres+"'.\n");
      P(TP)->change_presay(pres);
      P(TP)->save_me();
      return 1;}
   return 1;
}

postsay(string str) {
   string posts;
   posts = P(TP)->query_postsay();
   if(!str) {
      write("Post-say script cleared.\n");
      posts = str;
      P(TP)->change_postsay(posts);
      P(TP)->save_me();
      return 1; }
   if(check1(str)) {
      posts = str;
      if(str) write("Post-say script changed to '"+posts+"'.\n");
      P(TP)->change_postsay(posts);
      P(TP)->save_me();
      return 1;}
   return 1;
}


givetalk(string str) {
   object ob;
   if(!str) {
      write("Give a talker to who?\n");
      return 1;}
   if(!find_player(str)) {
      write("Hmm, "+capitalize(str)+" doesn't seem to be on at the time.\n");
      return 1;}
   ob = find_player(str);
   if(P(ob)) {
      write(capitalize(str)+ ", the wise, already has a talker.\n");
      return 1;}
   move_object(clone_object("/players/dune/objects/talkobj.c"),ob);
   tell_object(ob, "A funny little talker device falls into your hands!\n");
   write(capitalize(str)+" now has a talker!\n");
   write_file("/players/dune/log/TALKGV", this_player()->
      query_real_name()+" gave "+ ob->
       query_real_name()+" a talker on "+ctime()+".\n");
   return 1;
}

int talkup(string str) {
if (!str) {
   write("Usage: talkup <who>.\n");
   return 1;}
if (find_player(str)) {
   if(P(find_player(str))) {
      command("newtalk",find_player(str));
      write(capitalize(str)+" has a brand new talker!\n");
      return 1;
      }
   write("That person don't have a talker.\n");
   return 1;}
write("No "+str+" here.\n");
return 1;
}

int talkupall () {
   object talkor;
   object * list;
   int i;
   list=users();
   for(i=0; i < sizeof(list); i++) {
      talkor = P(list[i]);
      if(talkor) {
         command("savetalk",list[i]);
         command("newtalk",list[i]);
         write(list[i]->query_real_name()+" HAS UPDATED TALKER.\n");
         }
      else
         write(list[i]->query_real_name()+" does not have a talker.\n");
    }
    return 1;
}

int talkrm(string str) {
object play, talkob;
if (!str) {
   write("Usage: talkrm <who>.\n");
   return 1;}
if (find_player(str)) {
   play = find_player(str);
   if(!P(play)) {
      write("That person does not have a talker in the first place.\n");
      return 1;}
   talkob = P(play);
   destruct(talkob);
   write("You destroy "+capitalize(str)+"'s talker.\n");
   write_file("/players/dune/log/TALKRM", this_player()->
      query_real_name()+" removed "+ play->
       query_real_name()+"'s talker.\n");
   return 1;
   }
write("No "+str+" found.\n");
return 1;
}


whotalk() {
   object list, guild;
   int i;
   list = users();
   write("\n");
write("          :[  :)  :O  :|  :(  :>  :<  :@  :P  :D  :{\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");
write("Name\t\tLevel\tPk\tWhereabouts\n");
write("-----------------------------------------------------------\n");
   for(i=0; i < sizeof(list); i++) {
      guild = P(list[i]);
      if(guild) {
         write(capitalize(list[i]->query_real_name()));
         if(strlen(list[i]->query_real_name())>7) write("\t");
         else write("\t\t");
         write(list[i]->query_level()+"\t");
         if(list[i]->query_pl_k()) write("Pk");
         else write("Non-pk");
         write("\t");
         if(!environment(list[i])) write("Logging in");
         else write(environment(list[i])->short());
         write("\n");
       }
   }
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");
write("          :I  :-)  :'U  :*O  >:]  <:o  |)  >B={}\n");
   return 1;
}


master(string str) {
 string who, yesno;
 object target, ob;
 int current;
 if(!str) {
    write("Usage: master <who> <yes/no>\n");
    return; }
 if(!sscanf(str, "%s %s", who, yesno)) {
    write("Usage: master <who> <yes/no>\n");
    return; }
 if(!find_player(who)) {
    write("User "+capitalize(who)+" not found.\n");
    return;}
 if((yesno == "yes") || (yesno == "no")) {
    target = find_player(who);
    ob = P(target);
    current = ob->query_talkmaster();
    if(yesno == "yes") {
      if(current) {
        write(capitalize(who)+
          " is already a Talkmaster.\n");
        return;}
      else {
        ob->change_master(1);
        ob->save_me();
TE(target, "Suddenly, your talker glows bright red.\n"+
"You have been promoted to Talkmaster!  :D \n");
        return;}
      }
    if(yesno == "no") {
      if(!current) {
        write(capitalize(who)+
          " is not a Talkmaster in the first place.\n");
        return;}
      else {
        ob->change_master(0);
        ob->save_me();
TE(target, "Unexpectedly, your talker loses its nice red glow.\n"+
"You are no longer Talkmaster  :( \n");
        return;}
        }
 }
 write("Usage: master <who> <yes/no>\n");
 return;
}

bug_report(string str) {
   if(!str) {
      write("Usage: talknote <message>\n");
      return; }
   write_file("/players/dune/log/TALKNOTE", "-->"+
      RN+": "+str+"\n");
   write("Your message is recorded, thank you :)\n");
   return;
}
