#include "/players/hippo/rvd.h"                                                `
#define SCORES "players/hippo/games/puzzle_room/p_score"

string allscores,allpuzzles,playing_now,descr;
int nrofpuzzles;

/* allpuzzles= "<puzzlename>**<answer>**<description>**\n" */
/* allscores= "<playername>**<nrofsolved>**<puzzlename>$<puzzlename>$<..>$**\n" */
/* playing_now= "<CTP>**<puzzlename>**\n" */

id(str) {return str=="machine" || str=="puzzle machine";}
get() { write("It's far too heavy.\n"); return 0;}
drop(str) {return 1;}
short() {return("The puzzle machine");}
long()
{ write("\n"+
  "              .---------------------.\n"+
  "             -|  F R A N C I P P O  |-\n"+
  "             ||---------------------||\n"+
  "             ||   Puzzle  Machine   ||\n"+
  "             |-----------------------|\n"+
  "             |               -       |\n"+
  "             |      push     |       |\n"+
  "             |             |-O-|     |\n"+
  "             |     button    |       |\n"+
  "             |               -       |\n"+
  "             |                       |\n"+
  "             |  Hippo                |\n"+
  "             |  Francesco            |\n"+
  "             | _____________________ |\n"+
  "             ||                     ||\n");

  write("\nFor more information about this every-week quest stuff\n"+
        "just type 'puzzles'.\n");
  return 1;
}
reset()
{ restore_object(SCORES);
  if(allpuzzles==0)allpuzzles="";
  if(playing_now==0)playing_now="";
  if(allscores==0)allscores="";
  return 1;
}
save(){ save_object(SCORES); return 1;}
init()
{ add_action("show_scores","puzzlescores");
  add_action("answer","answer");
  add_action("puzzles","puzzles");
  add_action("puzzles_2","puzzles_2");
  add_action("push","push");
  add_action("description","show");
        /* next commands are only for Hippo or Francesco */
  add_action("add_puzzle","add_puzzle");
  add_action("remove_puzzle","remove_puzzle");
  add_action("show_puzzles","show_puzzles");
  add_action("all_scores","all_scores");
  add_action("who_plays","who_plays");
  add_action("remove_all_puzzles","remove_all_puzzles");
  add_action("remove_all_scores","remove_all_scores");
}
push(arg)
{ int tmp,tmp2,i,done,nr_to_do,amount,nrofsolved;
  string rest,rest2,this_puzzle,answer,str_to_do,puzzle_name,name,puzzles,p_name;
  if(CTP=="Francesco"){write("You cannot play, you know the answers!\n");return 1;}
  if(!arg&&arg!="button"){notify_fail("What do you wanna push?\n");return 1;}
  reset();
  if(QMON<500){write("You need 500 coins. Go and get them first!\n");return 1;}
  done=0;
  rest=playing_now; playing_now="";
  while(rest!="" && rest!=0)
  { tmp=sscanf(rest,"%s**%s**\n%s",name,puzzle_name,rest);
    if(tmp!=2 && tmp!=3){write("'Playing_now' bugged. Mail Hippo.\n");return 1;}
    if(name!=CTP) playing_now=playing_now+name+"**"+puzzle_name+"**\n";
  }
  name="";
  rest=allscores;
  while(name!=CTP && rest!="" && rest!=0)
  { tmp=sscanf(rest,"%s**%d**%s**\n%s",name,nrofsolved,puzzles,rest);
    if(tmp!=3 && tmp!=4){write("'Allscores' bugged. Mail Hippo.\n");return 1;}
  }
  rest2=allpuzzles;
  str_to_do=""; nr_to_do=nrofpuzzles;
  while(rest2!="" && rest2!=0)
  { tmp=sscanf(rest2,"%s**%s**%s**\n%s",puzzle_name,answer,this_puzzle,rest2);
    if(tmp!=3&&tmp!=4){write("'Allpuzzles'(1) bugged. Mail Hippo.\n");return 1;}
    if(CTP==name)
    { rest=puzzles;
      while(rest!="" && rest!=0)
      { tmp=sscanf(rest,"%s$%s",p_name,rest);
        if(tmp!=1&&tmp!=2){write("'Puzzles' bugged. Mail Hippo.\n");return 1;}
        if(p_name!=puzzle_name) { str_to_do=str_to_do+puzzle_name+"**"; }
        else { nr_to_do=nr_to_do-1; }
      }
    }
    else
    { str_to_do=str_to_do+puzzle_name+"**"; }
  }
  if(nr_to_do==0)
  { write("You already solved all puzzles!\n");
    say(CTP+" can't puzzle because he already solved all puzzles.\n");
    return 1;
  }
  for(i=1;i<random(nr_to_do)+2;i++)
  { tmp=sscanf(str_to_do,"%s**%s",p_name,str_to_do);
    if(tmp!=1&&tmp!=2){write("'Str_to_do' bugged. Mail Hippo.\n");return 1;}
  }
  rest=allpuzzles;
  while(rest!="" && rest!=0 && p_name!=puzzle_name)
  { tmp=sscanf(rest,"%s**%s**%s**\n%s",puzzle_name,answer,this_puzzle,rest);
    if(tmp!=3&&tmp!=4){write("'Allpuzzles'(2) bugged. Mail Hippo.\n");return 1;}
  }
  if(p_name!=puzzle_name){write("Couldn't determine puzzle. Mail Hippo.\n");
    write("p_name ="+p_name+"\npuzzle_name ="+puzzle_name+"\n");
    return 1;}
  write("Ok, your puzzle:\n\t*** "+puzzle_name+" ***\n"+this_puzzle+"\n");
  say(CTP+" receives a new puzzle.\n");
  playing_now=playing_now+CTP+"**"+puzzle_name+"**\n";
  amount=-500;AMON;
  save();
  return 1;
}
description(arg)
{ int tmp,tmp2,i;
  string name,puzzle_name,rest,answer,this_puzzle,pn;
  if(!arg||arg!="puzzle"){notify_fail("What do you wanna show?\n");return 1;}
  reset();
  rest=playing_now;
  while(name!=CTP && rest!="" && rest!=0)
  { tmp=sscanf(rest,"%s**%s**\n%s",name,puzzle_name,rest);
    if(tmp!=2 && tmp!=3){write("'Playing_now' bugged. Mail Hippo.\n");return 1;}
  }
  if(name!=CTP){write("Push the button to receive a puzzle.\n");return 1;}
  rest=allpuzzles;
  while(puzzle_name!=pn && rest!="" && rest!=0)
  { tmp=sscanf(rest,"%s**%s**%s**\n%s",pn,answer,this_puzzle,rest);
    if(tmp!=3 && tmp!=4){write("'Allpuzzles' bugged. Mn");return 1;}
  }
  if(pn!=puzzle_name)
  { write("Can't find your puzzle. It might have been removed lately.\n"+
    "I'm sorry about that, but you shouldn't wait too long before you answer.\n"+
    "Push the button for a new puzzle.\n");
    return 1;
  }
  write("Ok, here's your puzzle:\n\t*** "+pn+" ***\n"+this_puzzle+"\n");
  say(CTP+" looks at his puzzle.\n");
  return 1;
}
answer(arg)
{ string p_name,rest,answer,puzzle_name,name,this_puzzle,puzzles,tname;
  int tmp,amount,nrofsolved;
  if(!arg) { notify_fail("Missing answer.\n"); return 1; }
  reset();
  rest=playing_now;playing_now="";
  while(rest!="" && rest!=0 && name!=CTP)
  { tmp=sscanf(rest,"%s**%s**\n%s",name,p_name,rest);
    if(tmp!=2&&tmp!=3){write("'Playing_now' bugged. Mail Hippo.\n");return 1;}
    if(name!=CTP) playing_now=playing_now+name+"**"+p_name+"**\n";
  }
  playing_now=playing_now+rest;
  if(name!=CTP){write("Push the button to receive a puzzle.\n");return 1;}
  rest=allpuzzles;
  while(rest!="" && rest!=0 && p_name!=puzzle_name)
  { tmp=sscanf(rest,"%s**%s**%s**\n%s",puzzle_name,answer,this_puzzle,rest);
    if(tmp!=3 && tmp!=4){write("'Allpuzzles' bugged, mail Hippo.\n");return 1;}
  }
  if(p_name!=puzzle_name){write("Couldn't find your puzzle. Mail Hippo.\n");return 1;}
  if(arg!=answer)
  { write("That was the wrong answer. You have to push the button again\n"+
    "to receive a new puzzle.\n");
    say(CTP+" just gave a wrong answer on the "+puzzle_name+" puzzle.\n");
  }
  else
  { rest=allscores;allscores="";
    while(tname!=CTP && rest!="" && rest!=0)
    { tmp=sscanf(rest,"%s**%d**%s**\n%s",tname,nrofsolved,puzzles,rest);
      if(tmp!=3 && tmp!=4){write("'Allscores' bugged. Mail Hippo.\n");return 1;}
      if(tname!=CTP){allscores=allscores+tname+"**"+nrofsolved+"**"+puzzles+"**\n";}
    }
    if(tname==CTP)
    { nrofsolved++;
      allscores=allscores+tname+"**"+nrofsolved+"**"+puzzles+p_name+"$**\n"+rest;
    }
    else
    { nrofsolved=1;
      allscores=allscores+name+"**"+nrofsolved+"**"+p_name+"$**\n";
    }
    write("* * * Yes, that is correct! * * *\n"+
    "You gain 2000 coins. It was puzzlenumber "+nrofsolved+" you solved.\n"+
    "Push the button to receive another puzzle.\n");
    say(CTP+" just solved his "+nrofsolved+" puzzle and gained 2000 coins!\n");
    amount=2000;AMON;
  }
  save();
  return 1;
}
show_scores()
{ string name,rest,puzzles;
  int i,j,tmp,nrofsolved;
  restore_object(SCORES);
  i=0;j=0;
  rest=allscores;
  write("Right now, these are the persons who solved one or more puzzles:\n"+
  "* * NAME * * * * * * * NAME * * * * * * * NAME * * * * * * \n");
  rest=allscores;
  while(rest!="" && rest!=0)
  { tmp=sscanf(rest,"%s**%d**%s**\n%s",name,nrofsolved,puzzles,rest);
    if(tmp!=3 && tmp!=4){write("'Allscores' bugged. Mail Hippo.\n");return 1;}
    name=extract(capitalize(name+"          "),0,10);
    j++;i++;
    if(j==3){j=0;write(i+") "+name+" "+nrofsolved+"\n");}
    else { write(i+") "+name+" "+nrofsolved+" \t"); }
  }
  write("\n");
  rest=allscores;
  while(rest!="" && rest!=0 && name!=CTP)
  { tmp=sscanf(rest,"%s**%d**%s**\n%s",name,nrofsolved,puzzles,rest);
    if(tmp!=3 && tmp!=4){write("'Allscores' bugged. Mail Hippo.\n");return 1;}
  }
  if(name!=CTP){write("You didn't solve puzzles yourself yet.\n");}
  else{write("You solved the following puzzles yourself: \n"+puzzles+"\n");}
  return 1;
}
all_scores()
{ string name,rest,puzzles;
  int tmp,nrofsolved;
  if(CTP=="Hippo" || CTP=="Francesco")
  { restore_object(SCORES);
    write("Right now, these are the persons who solved one or more puzzles:\n"+
    "   * * Special Hippo/Francesco puzzlescore list * *\n");
    rest=allscores;
    while(rest!="" && rest!=0)
    { tmp=sscanf(rest,"%s**%d**%s**\n%s",name,nrofsolved,puzzles,rest);
      if(tmp!=3 && tmp!=4){write("'Allscores' bugged. Mail Hippo.\n");return 1;}
      write(name+" "+nrofsolved+"\n"+puzzles+"\n");
    }
    return 1;
  }
  return 0;
}
who_plays()
{ string name,rest,puzzle_name;
  int tmp;
  if(CTP=="Hippo" || CTP=="Francesco")
  { restore_object(SCORES);
    write("Right now, these are the persons with their puzzles to solve:\n"+
    "   * * Special Hippo/Francesco puzzlers list * *\n");
    rest=playing_now;
    while(rest!="" && rest!=0)
    { tmp=sscanf(rest,"%s**%s**\n%s",name,puzzle_name,rest);
      if(tmp!=2 && tmp!=3){write("'playing_now' bugged. Mail Hippo.\n");return 1;}
      write(name+" "+puzzle_name+"\n");
    }
    return 1;
  }
  return 0;
}
remove_all_puzzles()
{ if(CTP=="Hippo"||CTP=="Francesco")
  { allpuzzles="";
    playing_now="";
    nrofpuzzles=0;
    save();
    return 1;
  }
  return 0;
}
remove_all_scores(str)
{ if(CTP=="Hippo" || CTP=="Francesco")
  { if(str!="for sure"){write("Syntax: remove_all_scores for sure.\n");return 1;}
    allscores="";
    save();
    write("Ok, removed all scores (!).\n");
    return 1;
  }
  return 0;
}
show_puzzles(str)
{ string r,pn,a,tp;
  int t,i,j;
  if(CTP=="Hippo" || CTP=="Francesco")
  { r=allpuzzles;
    if(!str)
    { write("The current puzzles are:\n");
      while(r!="" && r!=0)
      { t=sscanf(r,"%s**%s**%s**\n%s",pn,a,tp,r);
        if(t!=3&&t!=4){write("'Allpuzzles' bugged. Mail Hippo.\n");return 1;}
        pn=extract(capitalize(pn+"                    "),0,20);
        j++;i++;if(j==2){j=0;write(pn+"\n");}else{write(pn+" \t");}
      }
      write("\n");
    }
    else
    { while(pn!=str && r!="" && r!=0)
      { t=sscanf(r,"%s**%s**%s**\n%s",pn,a,tp,r);
        if(t!=3&&t!=4){write("'Allpuzzles' bugged. Mail Hippo.\n");return 1;}
      }
      if(pn!=str){write("That puzzle does not (yet) exist.\n");}
      else{write("Here is puzzle "+pn+":\n"+tp+"\nThe answer is: "+a+".\n");}
    }
    return 1;
  } else { return 0; }
}
remove_puzzle(str)
{ string r,pn,a,tp;
  int done,t;
  done=0;
  if(CTP=="Hippo" || CTP=="Francesco")
  { if(!str){write("Syntax: remove_puzzle <puzzlename>\n");return 1;}
    r=allpuzzles;
    allpuzzles="";
    write("The current puzzles are:\n");
    while(r!="" && r!=0)
    { t=sscanf(r,"%s**%s**%s**\n%s",pn,a,tp,r);
      if(t!=3&&t!=4){write("'Allpuzzles' bugged. Mail Hippo.\n");return 1;}
      if(str!=pn){allpuzzles=allpuzzles+pn+"**"+a+"**"+tp+"**\n";}
      else{nrofpuzzles=nrofpuzzles-1;done=1;}
    }
    if(done==0)
    { write("Didn't find that puzzle.\n");
      show_puzzles();
    }
    else{save();}
    return 1;
  }
  else {return 0;}
}
add_puzzle(arg)
{ string name,answer;
  reset();
  if(CTP=="Hippo" || CTP=="Francesco")
  { if(sscanf(arg,"%s -> %s",name,answer)!=2)
    { write("Syntax: 'add <Puzzlename> -> <answer>'.\n"); return 1; }
    else
    { allpuzzles=allpuzzles+name+"**"+answer+"**";
      if(descr==0) descr="";
      input_to("get_descr");
      write("Give description, end with '**'.\n");
      write(":");
      return 1;
    }
  }
  else {return 0;}
}
get_descr(str)
{ if(str=="**")
  { allpuzzles=allpuzzles+descr+"**\n"; nrofpuzzles++; descr=""; save();
    write("Added puzzlenumber "+nrofpuzzles+".\n"); return;
  }
  descr=descr+str+"\n";
  write(":");
  input_to("get_descr");
}
puzzles()
{ write("\n\t* * * * * FRANCIPPO PUZZLES * * * * *\n\n"+
  "Set up:\n"+
  "This machine is the big puzzle machine. When you push the machine's button\n"+
  "you'll receive one of the puzzles that are available at the moment. The\n"+
  "puzzles are not always the same. Sometimes puzzles will be removed, and\n"+
  "puzzles will be added to the machine every now and then. Besides, you\n"+
  "will never get the same puzzle after you solved it. It'll cost ya 500\n"+
  "coins to get a puzzle, and you get 2000 coins if you solved it. You can\n"+
  "look at the puzzle as many times as you want, and answer whenever you want\n"+
  "-even after a reboot- when you are in this room. However, you get only one\n"+
  "opportunity to answer. If you didn't answer correctly you'll have to push\n"+
  "the button again for a new puzzle. Be carefull! Follow the syntax that\n"+
  "is told in the description. It checks for capitals, for example.\n"+
  "How to play?\n"+
  "It's quite easy to puzzle. Here are the commands:\n"+
  "  push button      | get a new puzzle from the machine\n"+
  "  show puzzle      | see the description of your puzzle\n"+
  "  answer <answer>  | give an answer, required syntax in puzzle description\n"+
  "  puzzlescores     | see scores and the puzzles you answered correctly\n"+
  "  puzzles          | this info\n"+
  "  puzzles_2        | more info\n");
  if(CTP=="Hippo" || CTP=="Francesco")
  { write("\n"+CTP+", you can also do:\n"+
    "add_puzzle <name> -> <answer>         remove_puzzle <name>\n"+
    "show_puzzles [optional: <name>]       all_scores\n"+
    "who_plays\n"+                               
    "remove_all_puzzles                    remove_all_scores for sure\n");
  }
  return 1;
}
puzzles_2()
{ write("The idea:\n"+
  "The Francippo puzzles started in an attempt to give life in Nirvana\n"+
  "an extra dimension. To give you the opportunity to do something\n"+
  "different than walking around, chatting, killing, chasing monsters,\n"+
  "doing a quest and sometimes playing a little game. Right now, a new\n"+
  "challenge has been created: Solving puzzles.\n\n"+
  "Why should you start thinking??\n"+
  "The purpose of these puzzles is to make your brains work a bit harder\n"+
  "than they are used to, and to create some kind of competition. Besides,\n"+
  "this is one of the rare ways to make more money out of your coins without\n"+
  "killing!\n"+
  "\n\t* * * * * Francesco * * * Hippo * * * * *\n\n");
  return 1;
}
