#include "/players/hippo/rvd.h"
#define SCORES "players/hippo/sc_oware"
int hole,sc_pl,to_play,stake,full,payment,maxbet;
string pl,playing,dontleave,name_score,name,messages;

id(str) { return str=="oware"; }
get()
{ if (playing=="yes")
  { write("You can't take it while playing!\n");
    say(CTP+" tried to take the board, but failed.\n");
    return 0;}
  write("You collected the stones and took the board.\n");
  return 1;
}
drop()
  { write("Type 'Oware <name> <stake>' to play a game.\n");
    return 0;}
short() {return("The Oware Game");}
long() {write("This is the Oware game. Oware is a typical African game,\n"+
  "although it is played all over the world with sometimes\n"+
  "different rules. The rules of this game are quite easy,\n"+
  "though. I suppose it's the best to read them before you\n"+
  "start to play.\n"+
  "Notice that money is involved, except when wizards play,\n"+
  "and that the scores will always be registered in a list.\n\n"+
  "------------------------------------------------------------\n"+
  " * Possible commands *\n"+
  " ---------------------\n"+
  " owarerules 1/2/3        : examine the rules of this game\n"+
  " oware <player> <amount> : start a game against <player> for\n"+
  "                           <amount> of coins\n"+
  " unaccepted              : don't accept a requested game\n"+
  " move <holenumber>       : replace stones from a hole\n"+
  " disp                    : display the board\n"+
  " scores                  : look at the highscorelist\n"+
  " fix oware               : (try to) fix a corrupted game\n"+
  " fix                     : help on the 'fix oware' command\n"+
  "------------------------------------------------------------\n");
  if(CTP=="Hippo") write("You can also do 'extra', Hippo.\n");
  return 1;
}

extra()
{   if(CTP=="Hippo")
    {   write("Possible commands:\n"+
        "   extra                        -> this message\n"+
        "   add <score> <name>           -> add a player and a score\n"+
        "   remove <num>                 -> remove that score number\n"+
        "   destroy scores               -> destroy the entire scorelist\n");
        return 1;}
    else
    { write("Hey.. that's only a command for Hippo!!\n");
      say(CTP+" tried to get information which is only for Hippo.\n");
      return 1;}
}

reset()
{ pl=allocate(2);
  sc_pl=allocate(2);
  hole = allocate(13);
  restore_object(SCORES);
  return 1;
}

init() {
  add_action("display","disp");
  add_action("scores","scores");
  add_action("start","oware");
  add_action("play","move");
  add_action("rules","owarerules");
  add_action("extra","extra");
  add_action("fix","fix");
  add_action("unaccepted","unaccepted");
  add_action("remove","remove");
  add_action("destroy","destroy");
  add_action("add","add");
}

rules(str)
{ if(str=="1")
  { write("\nConstruction of the Oware game:\n"+
    "The board contains 12 holes. Each hole contains some marbles (four when\n"+
    "you start), which can be replaced by typing 'move <holenum>'. One of \n"+
    "those marbles will be put in the next hole, the second one in the hole\n"+
    "next to that one, etc. When the last replaced marble makes a total of\n"+
    "2 or 3 in a hole at the opposite site, you win those marbles. If the\n"+
    "previous hole also contains 2 or 3 stones you get those too, etc.\n"+
    "Winner is the one who gained 25 or more marbles (more than 50%). Besides\n"+
    "you win five times the stake in case there are no marbles left at your\n"+
    "opponents side.\n"+
    "\nPayment:\n"+
    "The looser pays an amount of money to the winner, which is calculated as\n"+
    "follows: --> (24 - number of gained stones by the looser) X stake.\n"+
   "\n   ** Continue reading in 'owarerules 2' **\n");
  return 1;
  }
  if(str=="2")
  { write("\nNotice that:\n"+
    "1. You can only replace stones from your own site, and you can only win\n"+
    "   marbles from the opposite site.\n"+
    "2. You can neither win more money than your opponent owns, nor loose more\n"+
    "   than you own yourself! You get a message when your opponent has less\n"+
    "   than five times the amount of the stake. In that case the stake is\n"+
    "   automaticaly set to onefifth of his amount of money.\n"+
    "3. Maximum stake is 1000, minimum=0 (why should you bet less?).\n"+
    "4. You can neither win nor loose money while playing with a wizard. Just\n"+
    "   play for points on the highscore list in that case.\n"+
    "\nThat's it.\n"+
    "I hope you like this game, as well as you ppl seem to like the cardgames\n"+
    "51, 21 and blackjack (anyone tried to solve my brain-quest yet?? *grin*).\n"+
    "If you have more ideas for new games, just mail me.\n      GOOD LUCK!!\n"+
  "\t\trvd_hippo.\n\nPS: A last note is in 'owarerules 3'!\n");
  return 1;
  }
  if(str=="3")
  { write("\nOne last thing:\n"+
    "I am aware of the fact that you can just run away while playing this game.\n"+
    "This has been introduced for the sake of your own freedom. Else you would be\n"+
    "stuck in the same place in case of for instance linkdeath of the other player.\n"+
    "I suppose loosing players will NOT run from the board so they won't have to\n"+
    "pay money, for four reasons:\n"+
    "1. You are considered to be FAIR! If you are afraid to loose money, don't play.\n"+
    "2. You can WIN money, playing oware. This implicits two things. You have to\n"+
    "   find someone you can defeat and you have to practise a lot to do so. You\n"+
    "   need the practising stage (where you probably loose some money) to earn a\n"+
    "   lot more!! See every coin you loose as an investment for wealth later.\n"+
    "3. Running away might result in a lot of player-killing, which is not the main\n"+
    "   purpose of this game. Besides, you will never be trusted anymore.\n"+
    "4. I LOVE critical comments concerning my coding, as much as I HATE complaints\n"+
    "   about ppl who (try to) cheat. If I receive such complaints, I have to change\n"+
    "   this game in a way that it is not portable anymore. I tried to make oware\n"+
    "   easy to handle, and wanna keep it like that. Don't spoil your own chances!\n");
    return 1;
  }
  write("What rules? 'owarerules 1', 'owarerules 2' or 'owarerules 3'?\n");
  return 1;
}

start(str)
{ int i;
  object ob;
  if (environment()==this_player())
  { write("You must drop the Oware game first !\n");
    return 1; }
  if(sscanf(str,"%s %d",name,stake)!=2)
  { notify_fail("Use the following syntax: 'oware <player> <amount>'.\n");
    return 0; }
  pl[0] = CTP;
  pl[1] = capitalize(name);
  ob = present(name,environment(this_object()));
  if(!ob)
  { notify_fail(pl[1]+" is not present here.\n"); return 0; }
  if(!living(ob))
  { notify_fail(pl[1]+" is not a living person.\n"); return 0; }
  if(call_other(this_player(),"query_level",0)>=20 ||
     call_other(find_living(lower_case(pl[1])),"query_level",0)>=20)
  { write("You will not play for money, because one of the players is a wizard.\n"+
    "Only points on the highscore list are interesting, the game itself\n"+
    "excluded.\n");
    maxbet=0; }
  else { coins(); }
  to_play = random(2);
  for (i=1;i<13;i++) hole[i]=4;
  for (i=0;i<2;i++) sc_pl[i]=0;
  write(pl[to_play]+" has to do the first move.\n");
  playing="yes";
  return 1;
}

coins()
{ int i;
  maxbet=1000;
  for(i=0;i<2;i++)
  { if(call_other(find_living(lower_case(pl[i])),"query_money")<5*maxbet)
    { maxbet=call_other(find_living(lower_case(pl[i])),"query_money")/5;}
  }
  if(stake>maxbet)
  { write("I'll make that "+maxbet+", the maximum bet, because one of you\n"+
          "only has "+5*maxbet+" coins.\n");
    say(CTP+" challenges "+pl[1]+" for a game of Oware, with stake "+maxbet+",\n"+
        "the maximum stake one of the players can affort.\n");
    stake=maxbet;
  }
  else
  { write("You start oware with "+pl[1]+".\n");
    say(CTP+" started a game of oware with "+pl[1]+", with stake "+stake+".\n");
  }
  say("If you don't wanna play for some reason, just type 'unaccepted'.\n");
  return 1;
}

display()
{ int i;
  if (playing == "no")
  { write("You have to start the game with an opponent first.\n");
    return 1;}
  write(pl[to_play]+" to play.\n\n");
  write("\t\t"+pl[0]+" (score: "+sc_pl[0]+")\n\t (6) (5) (4) (3) (2) (1)\n\t");
  for(i=6;i>0;i=i-1) {write("  "+hole[i]);if (hole[i]<10) write(" ");}
  write("\n\t ------------------------ \n\t");
  for(i=7;i<13;i++) {write("  "+hole[i]);if (hole[i]<10) write(" ");}
  write("\n\t (7) (8) (9)(10)(11)(12)\n\t\t"+pl[1]+" (score: "+sc_pl[1]+")\n");
  return 1;
}

play(str)
{ int i,num,number,gain,nroffours,excontents,done,exnum;
  if(!str||sscanf(str,"%d",num)!=1)
  { write("Syntax: move <number>.\n");
    return 1;}
  if(playing=="no")
  { write("You have to start the game with an opponent first.\n");
    return 1;}
  if(CTP!=pl[to_play])
  { if(CTP!=pl[0]&&CTP!=pl[1])
    { write(pl[0]+" and "+pl[1]+" are playing. Not you!\n");
      say(CTP+" tried to move stones while he ain't playing!\n");}
    else
    { write("It is not your turn now.\n");
      say(CTP+" tried (illegaly) to play.\n");}
    return 1;}
  if(CTP==pl[0] && num>6 || CTP==pl[1] && num<7)
  { write("These are not your stones, man!\n");
    say(CTP+" tried to move YOUR stones!\n");
    return 1;}
  if(hole[num]==0)
  { write("You can't move stones from an empty hole, bud.\n");
    say(CTP+" tried to move stones from empty hole "+num+"!\n");
    return 1;}
  excontents=hole[num];
  exnum=num;
  hole[num]=0;
  for(i=1;i<excontents+1;i++)
  { if(num+i>12) num=num-12;
    number=num+i;
    hole[number]++;}
  done=0;
  while ((hole[number]==2 || hole[number]==3) && done!=1)
  { if (CTP==pl[0] && number>6 || CTP==pl[1] && number<7)
    { gain=gain+hole[number]; hole[number]=0;
      number=number-1; } else { done=1; } }
  if(gain==0)
  { write("You didn't gain stones with that move.\n");
    say(CTP+" moved stones from hole "+exnum+".\n"); }
  else
  { write("You gain "+gain+" stones with that move.\n");
    say(CTP+" moved stones from hole "+exnum+" and gained "+gain+" stones.\n");}
  check_all_empty();
  if(full==0) return 1;
  sc_pl[to_play]=sc_pl[to_play]+gain;
  if(sc_pl[to_play]>24)
  { write("You got more than 24 stones... you WON!!\n");
    say(pl[to_play]+" won, which automatically means you LOST!!\n");
    playing="no"; dontleave=0;
    pay();
    return 1;}
  if (to_play==1) to_play=0; else to_play=1;
  if(dontleave!=1)
  { nroffours=0;
    for(i=1;i<13;i++) if(hole[i]==4) nroffours++;
    if (nroffours<7) dontleave=1;}
  write("Ok.\n");
  return 1;
}

check_all_empty()
{ int j;
  full=0;
  if(to_play==1)
  { for(j=1;j<7;j++) { if(hole[j]!=0) { full=1; return 1; } } }
  else { for(j=7;j<13;j++) { if(hole[j]!=0) { full=1; return 1; } } }
  write("That move took your opponent's last marbles!! You won five times\n"+
        "your stake by that move..\n");
  say("You have no marbles left. That means you have to pay five times the\n"+
      "stake..\n");
  pay();
  return 1;
}

pay()
{ int sc,high_score,new_score,ok,i,tmp,nr,gain;
  if(full==0) {gain=5;}
  else {if(CTP==pl[0]) {gain=24-sc_pl[1];} else {gain=24-sc_pl[0];}}
  nr=0;
  payment=gain*stake;
   payment = 0;
  if(maxbet!=0)
  { if(CTP==pl[0])
    { if(call_other(find_living(lower_case(pl[1])),"query_money")<payment)
        { payment=call_other(find_living(lower_case(pl[1])),"query_money");}}
    else
    { if(call_other(find_living(lower_case(pl[0])),"query_money")<payment)
        { payment=call_other(find_living(lower_case(pl[0])),"query_money");}}
    if(CTP==pl[0])
    { write("You won "+payment+" coins from "+pl[1]+".\n");
      say(pl[1]+" pays "+payment+" coins to "+CTP+"!!\n");
      call_other(this_player(),"add_money",payment);
      call_other(find_living(lower_case(pl[1])),"add_money",-payment);}
    else
    { write("You won "+payment+" coins from "+pl[0]+".\n");
      say(pl[0]+" pays "+payment+" coins to "+CTP+"!!\n");
      call_other(this_player(),"add_money",payment);
      call_other(find_living(lower_case(pl[0])),"add_money",-payment);}}
  write("Updating the scores.....\n");
  say("Updating the scores.....\n");
  newsc(gain);
  return 1;
}

newsc(gain)
{ string rest;
  int score,new_score,i,done,tmp;
  done=allocate(2);
  new_score=allocate(2);
  for(i=0;i<2;i++) done[i]=0;
  rest=messages;
  messages="";
  while(rest!="" && rest!=0)
  { tmp=sscanf(rest,"%s %d\n%s",name,score,rest);
    if(tmp!=2 && tmp!=3)
    { write("Hmm... I can't update the highscore list!!?? ==> Mail Hippo.\n");
      return 0; }
    if(capitalize(name)!=pl[0] && capitalize(name)!=pl[1])
    { messages=messages+name+" "+score+"\n"; }
    else
    { for(i=0;i<2;i++)
      { if(capitalize(name)==pl[i])
        { if(pl[i]==CTP) {new_score[i]=score+gain;}
          else {new_score[i]=score-gain;}
          done[i]=1;}}}}
  for(i=0;i<2;i++)
  { if(done[i]!=1)
    { if(pl[i]==CTP) {new_score[i]=gain;} else {new_score[i]=-gain;}}}
  for(i=0;i<2;i++)
  { rest=messages; messages="";
    while(rest!="" && rest!=0)
    { tmp=sscanf(rest,"%s %d\n%s",name,score,rest);
      if (tmp != 2 && tmp != 3)
      { write("Hmm... I can't read the highscore list!!?? ==> mail Hippo.\n");
        return 0; }
      if(new_score[i]>score)
      { messages=messages+pl[i]+" "+new_score[i]+"\n"+
        name+" "+score+"\n"+rest;
        rest=""; }
      else
      { messages=messages+name+" "+score+"\n"; }}
    if(new_score[i]<score || messages=="")
      messages=messages+pl[i]+" "+new_score[i]+"\n";}
  save_object(SCORES);
  return 1;
}

scores()
{ write("Hippo's Oware Highscore List.\n");
  if (messages == "" || messages == 0)
  { write("There are no scores yet.\n");
    return 1; }
  write("   name          score     name          score"+
        "     name          score\n");
  headers();
  return 1;
}

headers() {
    string name,rest;
    int high_score,i,j,tmp;
    i=0;j=0;
    rest=messages;
    while(rest!=0 && rest!="" && rest!="\n") {
        tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
        if (tmp != 2 && tmp != 3) {
            write("Shit, the list is corrupted (Headers-part).\n");
            return; }
        name=extract(capitalize(name+"             "),0,12);
        j++; i++;
        if (j==3) { j=0; write(i+") "+name+" "+high_score+"\n"); }
        else { write(i+") "+name+" "+high_score+" \t"); }}
    write("\n");
    return 1;
}

remove(arg)
{   string name,rest;
    int high_score,i,j,tmp;
    if(CTP=="Hippo")
    {   rest=messages;
        messages="";
        if(sscanf(arg,"%d",j)!=1)
        {   write("Argument should be the score number to remove.\n");
            return 1; }
        for(i=0;i<j-1;i++)
        {   tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
            if (tmp != 2 && tmp != 3) {
                write("Shit, the list is corrupted (remove-part).\n");
                return;}
            messages=messages+name+" "+high_score+"\n";}
        tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
        messages=messages+rest;
        save();
        write("Score "+j+") "+name+" "+high_score+" removed.\n");
        return 1;}
    else
    {   write("Hey.. only Hippo is allowed to remove scores!!\n");
        say(capitalize(this_player()->query_real_name())+
            " tried to remove scores!! (But didn't succeed).\n");
        return 1;}
}

destroy(arg)
{   if (arg=="scores")
    {   if(CTP=="Hippo")
        {   messages = "";
            save_object(SCORES);
            write("done.\n");
            return 1;}
        else
        {   write("Hey.. only Hippo is allowed to destroy scores!!\n");
            say(capitalize(this_player()->query_real_name())+
                " tried to destroy the scores!! (But didn't succeed).\n");
            return 1;}}
    return 0;
}

add(arg)
{   int s;
    string n;
    if (sscanf(arg,"%d %s",n,s)==2)
    {   if(CTP=="Hippo")
        {   newsc(arg);
            write("done\n");
            return 1; }
        else
        {   write("Hey.. only Hippo is allowed to add scores!!\n");
            say(capitalize(this_player()->query_real_name())+
                " tried to add scores!! (But didn't succeed).\n");
            return 1; }}
    write("Syntax: add <score> <player name>.\n");
    return 1;
}

unaccepted()
{ int i;
  if(playing=="yes")
  { for(i=0;i<2;i++)
    if(CTP==pl[i])
    { if(dontleave==1)
      { write("What?? Are you loosing or what? You are already playing Oware!!\n"+
              "You have to finish the game you started. If you didn't wanna play\n"+
              "this game, you should have typed that before you made your first \n"+
              "move.\n");
        say(CTP+" tried to quit the game. Fortunately, Hippo forced him to finish\n"+
                "the game.\n");}
      else
      { write("Aha.. you didn't wanna play Oware? It's ok with me..\n");
        say(CTP+" didn't accept the request to play Oware. The game didn't start.\n");
        playing="no";dontleave=0;}
      return 1;}
    else
    { write("Hmm.. "+pl[0]+" asked "+pl[1]+" to play oware. Not you. Sorry\n"+
            "about that. If you want a board yourself, you can get one for\n"+
            "free from Hippo's game machine (s,8e,shake hand,nose from church)\n");
      return 1;}}
  write("Huh?? Nobody asks you to play oware.. \n");
  return 1;
}

fix(arg)
{ object ob;
  int i;
  if(!arg)
  { say(CTP+" asks for help on Oware.\n");
    write("If, for some reason, this game seems to be corrupted, for instance\n"+
          "when you can't start a new game, while noone is playing, you can\n"+
          "try to reset it.\n"+
          "In most cases this will be sufficient. If not, you'd better call\n"+
          "Hippo, and tell him exactly what was wrong. Be as specific as\n"+
          "possible about what has happened or what you have been doing.\n"+
          "\nTo reset the game, type: -->  fix oware  <--\n");
          return 1;}
  if(arg=="oware")
  { if(playing=="yes")
    { for(i=0;i<2;i++)
      { ob=present(lower_case(pl[i]),environment(this_player()));
        if(!ob || !living(ob))
        { write("Ok, I'll reset the game now. I found something\n"+
                "which might be corrupted in this game. You should\n"+
                "try to start again, and see if this worked out. If\n"+
                "not, call Hippo.\n");
          say(CTP+" resetted the Oware game.\n");
           playing="no"; dontleave=0;
           save_object(SCORES);
           return 1; } }
      write("Hmm.. I can't find any mistake. If this game doesn't work\n"+
            "properly, mail Hippo. Else you are trying to cheat in here.\n"+
            "I hope for you it's the first option....\n"+
            "PS: It might be that you can't play, because others are \n"+
            "    currently playing. Look at the game to verify.\n");
      say(CTP+" tried to reset Oware, which didn't work out. If nothing is\n"+
          "wrong with this game, this means he tried to cheat!\n");
      return 1;}
    write("Nothing seems to be wrong. Just type Oware <player> <stake>. If\n"+
          "this game doesn't work properly, mail Hippo. Else you are trying \n"+
          "to cheat in here!!\n");
    say(CTP+" tried to fix Oware, but nothing seems to be wrong.\n"+
        "Maybe "+CTP+" tried to type 'Hippo created this wonderfull\n"+
        "game' in stead of 'fix oware'??\n");
    return 1;}
  write("What do you wanna fix? (Just type 'fix' for more information).\n");
  return 1;
}
