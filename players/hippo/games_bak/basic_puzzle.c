#define SCORES "players/hippo/puzzles"
#include "/players/hippo/games/puzzle.c"
#include "/players/hippo/rvd.h"
string allscores,weekscores,ANTWOORD,value;
int this_week,guesses,correct;

id(str) {return str=="puzzle";}
get() {return 1;}
drop(str) {return 0;}
short() {return("This weeks puzzle");}
long()
{ write("Here is this weeks puzzle:\n\n");
  description();
  write("\nFor more information about this every-week quest stuff\n"+
        "just type 'puzzles'.\n");
  return 1;
}
reset()
{ restore_object(SCORES);
  if(this_week==0) this_week=1;
  if(correct==0) correct=1;
  if(guesses==0) guesses=1;
  if(value==0) value=1;
  return 1;
}
save()
{ save_object(SCORES);
  restore_object(SCORES);
  return 1;
}

init()
{ add_action("show_scores","puzzlescores");
  add_action("answer","answer");
  add_action("puzzles","puzzles");
  add_action("puzzles_2","puzzles_2");
  add_action("new_week","newweek");
  add_action("add","add");
  add_action("destroy","destroy");
}

answer(arg)
{ string name,rest;
  int antw,nr_last_puzzle,score,weeknr,tmp,your_score,done,your_guess;
  restore_object(SCORES);
  if(ANTWOORD=="mail")
  { write("You should mail your answer to Hippo or Francesco. It is not\n"+
    "possible to answer this week's question in another way.\n");
    say(CTP+" tried to answer this week's question, but failed.\n");
    return 1;
  }
  guesses++;
  done=0;score=0;weeknr=0;your_guess=0;
  rest=allscores;
  allscores="";
  while(rest!=0 && rest!="")
  { tmp=sscanf(rest,"%s %d %d %d\n%s",name,score,weeknr,your_guess,rest);
    if (tmp!=4 && tmp!=5)
    { write("Hmm... Can't search for names the list?? -> Mail Hippo!!\n");
      return 0;
    }
    if(CTP==name)
    { if(weeknr==-this_week)
      { write("Hey!! You already gave me the right answer of this week's question!\n"+
        "I won't give you more points this week. You'll have to wait for the\n"+
        "next week's puzzle to show how smart you are!\n");
        say(CTP+" tried to answer the same puzzle once again! Of course, he didn't\n"+
        "gain points. "+CTP+" must be a bit crazy to solve the same problem\n"+
        "twice...\n");
      }
      else
      { if(your_guess==3)
        { write("Hey, man!!! You already did three guesses this week. I can't\n"+
          "allow you to do more guesses, I'm sorry. Besides: I think three\n"+
          "guesses is enough, if you still didn't know the right answer you\n"+
          "probably won't know it the fourth time either.\n");
          say(CTP+" tried to answer this question for the fourth time! He must\n"+
          "be quite stupid if he didn't answer right within three attempts!\n");
          return 1;
        }
        else
        { if(arg==ANTWOORD)
          { write("* * * Yes, that is correct! * * *\n"+
            "'You'll gain points by the end of the week, I'm not sure how much yet.\n"+
            "Hopefully you solve next weeks puzzle, too!', you hear a voicying.\n");
            say(CTP+" just solved this weeks puzzle!\n");
            weeknr=-this_week;
            correct++;
          }
          else
          { write("Nope, that's the wrong answer. You could guess again, or think\n"+
            "about it more carefully before you give another answer.\n");
            say(CTP+" gave a wrong answer for this weeks puzzle.\n");
          }
          your_guess++;
        }
      }
      done=1;
    }
    allscores=allscores+name+" "+score+" "+weeknr+" "+your_guess+"\n";
  }
  if(done==0)
  { if(arg==ANTWOORD)
    { write("* * * Yes, that is correct! * * *\nYou receive 10 points.\n"+
      "'Hopefully you solve next weeks puzzle, too!', you hear a voice saying.\n");
      say(CTP+" just solved this weeks puzzle!\n");
      weeknr=-this_week;
      correct++;
    }
    else
    { write("Nope, that's the wrong answer. You could guess again, or think\n"+
      "about it more carefully before you give another answer.\n");
      say(CTP+" gave a wrong answer for this week's puzzle.\n");
      weeknr=0;
    }
    allscores=allscores+CTP+" "+0+" "+weeknr+" 1\n";
  }
  save();
  return 1;
}

new_scores()
{ string rest,name,new_name,str;
  int new_score,tmp,score,week_score,weeknr,gain,done,your_guess;
  gain=guesses/correct*value;
  write("All solvers gain "+gain+" points.\n");
  rest=allscores;
  allscores="";
  while(rest!=0 && rest!="")
  { tmp=sscanf(rest,"%s %d %d %d\n%s",name,score,weeknr,your_guess,rest);
    if (tmp!=4 && tmp!=5)
    { write("Hmm... I can't update the highscore list!!??.\n");
      return 0;
    }
    if(weeknr==-this_week)
    { weeknr=this_week;
      new_score=score+gain;
      new_name=name;
      rest=allscores+rest;
      allscores="";
      done=0;
      while(rest!=0 && rest!="")
  { tmp=sscanf(rest,"%s %d %d %d\n%s",name,score,weeknr,your_guess,rest);
    if(tmp!=4 && tmp!=5)
   { write("Damn.. I can't update the highscore list!!?\n");
          return 0;
        }
        if(new_score<score)
        { allscores=allscores+new_name+" "+new_score+" "+this_week+" 0\n";
          done=1;
        }
        allscores=allscores+name+" "+score+" "+weeknr+" 0\n";
      }
      if(done==0) { allscores=allscores+new_name+" "+new_score+" "+this_week+" 0\n";}
      rest=allscores;
      allscores="";
    }
    else { allscores=allscores+name+" "+score+" "+weeknr+" 0\n";}
  }
  return 1;
}

new_week(arg)
{ int ttmp,tmpvalue;
  restore_object(SCORES);
  if(CTP=="Hippo"||CTP=="Francesco")
  { if(!arg) {write("Syntax: 'newweek <value>|<answer>|[<new weeknr>|]'.\n"); return 1;}
    ttmp=sscanf(arg,"%d|%s|%d|",tmpvalue,ANTWOORD,this_week);
    if(ttmp!=2 && ttmp!=3)
    {write("Syntax: 'newweek <value>|<answer>|[<new weeknr>|]'.\n"); return 1;}
    new_scores();
    if(ttmp==2) this_week++;
    guesses=1;
    correct=1;
    value=tmpvalue;
    write("The week of puzzle "+this_week+" started, value "+value+".\n"+
    "The new answer is: "+ANTWOORD+".\n");
    save();
    return 1;
  }
  else { return 0;}
}

show_scores()
{ string name,rest;
  int high_score,week_score,i,j,tmp,your_guess;
  restore_object(SCORES);
  i=0;j=0;
  rest=allscores;
  write("Scores in week "+this_week+".\n"+
  "Your score of this week will be added at the end of the week. The amount\n"+
  "depends on the difficulty of the current puzzle.\n"+
  "For now, this score will be "+guesses/correct*value+".\n\n"+
  "* * NAME * score(week) * * NAME * score(week) * * NAME * score(week) * *\n");
  while(rest!=0 && rest!="")
  { tmp=sscanf(rest,"%s %d %d %d\n%s",name,high_score,week_score,your_guess,rest);
    if (tmp!=4 && tmp!=5)
    { write("Damn, the list is corrupted (Show-part). ==> mail Hippo!\n");
      return 1;
    }
    name=extract(capitalize(name+"          "),0,10);
    j++;i++;
    if(j==3) { j=0; write(i+") "+name+" "+high_score+"("+week_score+")\n"); }
    else { write(i+") "+name+" "+high_score+"("+week_score+") \t"); }
    if(i==250)
    { write("Too much scores. Mail Hippo\n");
      return 1;
    }
  }
  write("\n");
  return 1;
}

destroy(arg)
{ if(CTP=="Hippo")
  { if(arg=="all scores for sure")
    { allscores="";
      guesses=1;
      correct=1;
      weekscores=0;
      this_week=0;
      value=0;
      save();
      return 1;
    }
    write("Syntax: destroy all scores for sure.\n");
    return 1;
  }
  return 0;
}

add(arg)
{ string name,rest,plname;
  int antw,nr_last_puzzle,score,weeknr,tmp,your_score,done,your_guess;
  restore_object(SCORES);
  if(sscanf(arg,"%s %d",plname,antw)==2)
  { if(CTP=="Hippo" || CTP=="Francesco")
    { guesses++;correct++;
      done=0;score=0;weeknr=-this_week;
      rest=allscores;allscores="";
      while(rest!=0 && rest!="")
      { tmp=sscanf(rest,"%s %d %d %d\n%s",name,score,weeknr,your_guess,rest);
        if (tmp!=4 && tmp!=5)
        { write("Hmm... Can't search for names the list?? -> Mail Hippo!!\n");
          return 0;
        }
        if(plname==name) { done=1; score=score+antw; }
        allscores=allscores+name+" "+score+" "+weeknr+" 0\n";
      }
      if(done==0) allscores=allscores+plname+" "+antw+" "+weeknr+" 0\n";
      save();
      return 1;
    }
    else{return 0;}
  }
  if(CTP=="Hippo" || CTP=="Francesco")
  { write("Syntax: add <player_name> <score>\n");
    return 1;
  }
  else {return 0;}
}

puzzles()
{ write("\n\t* * * * * FRANCIPPO PUZZLES * * * * *\n\n"+
  "Set up:\n"+
  "Each week, starting today, a new puzzle will be available which\n"+
  "you can solve (or can't?). When you succeeded, you get 10 points\n"+
  "(sometimes less in case of an incomplete answer). You only get three\n"+
  "opportunities to give the right answer for a specific puzzle. If your\n"+
  "answer was not right, you won't get points for that weeks puzzle.\n"+
  "How to play?\n"+
  "Just look at this puzzle to see this weeks problem. You just have to\n"+
  "type 'answer', followed by the requested answer. How to write this\n"+
  "down will become clear from the description of the puzzle itself.\n\n"+
  "Only thing we have to do now, is to wish you very good luck and a lot\n"+
  "of fun with these puzzles!!\n"+
  "All possible commands:\n"+
  "\tanswer <answer>  | give an answer\n"+
  "\tpuzzlescores     | see the scores\n"+
  "\tpuzzles          | more about these puzzles\n"+
  "\tpuzzles_2        | even more info\n"+
  "Continue reading: type 'puzzles_2'.\n");
  if(CTP=="Hippo" || CTP=="Francesco")
  { write("\n"+CTP+", you can also do: 'newweek', if a new puzzle was added.\n");}
  return 1;
}

puzzles_2()
{ write("The idea:\n"+
  "The Francippo puzzles started in an attempt to give life in Nirvana\n"+
  "an extra dimension. To give you the opportunity to do something\n"+
  "different than walking around, chatting, killing, chasing monsters,\n"+
  "doing a quest and sometimes playing a little game. Right now, a new\n"+
  "challenge has been created: Solving puzzles.\n"+
  "\n"+
  "Why should you start thinking??\n"+
  "The purpose of these puzzles is to make your brains work a bit harder\n"+
  "than they are used to, and to create some kind of competition. Maybe\n"+
  "we can give away some prizes for the best puzzlers sometimes. This\n"+
  "will merely depend on your response.\n\n"+
  "You can get a puzzle from the game machine. It can be found at:\n"+
  "    s,8e from church, shake hand, nose.\n\n"+
  "\t* * * * * Francesco * * * Hippo * * * * *\n\n");
  return 1;
}
