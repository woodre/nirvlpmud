#include "/players/hippo/rvd.h"
#define SCORES "players/hippo/scores51"

string pl,card,name_score,playing;
int dontleave,nrofpl,score,turn;
int coughts;

id(str) { return str=="51" || str=="table"; }
short() { return "Table to play 51"; }
get()   { return 0; }
drop()  { return 0; }

long()
{ int i;
  write("With this deck of cards you can play a game of '51' with\n"+
        "other players by typing 'start name1 name2 name3'. The\n"+
        "maximum number of players is 4, including yourself.\n"+
        "For more information and rules, type 'rules 51'.\n"+
        "Type 'help' if you think there is a bug, and you don't.\n"+
        "know how to handle. Try this before you call Hippo.\n");
  if(playing=="yes")
  { write("You notice that "+pl[0]);
    for(i=1;i<nrofpl-1;i++) write(", "+pl[i]);
    write(" and "+pl[nrofpl-1]+" are playing a game now.\n");
  }
  else
  { write("The table is empty... You can play if you want.\n"); }
  return 1;
}

reset()
{ int i;
  restore_object(SCORES);
  pl=allocate(8);
  for(i=0;i<nrofpl;i++) pl[i]=0;
  card=allocate(40);
coughts=allocate(nrofpl);
  return 1;
}

init()
{ add_action("rules","rules");
  add_action("start","51");
  add_action("show","show");
  add_action("put","put");
  add_action("scores","scores");
  add_action("leave","leave");
  add_action("help","help");
  add_action("peek","peek");
}
peek(name)
{ int i,j,k,l,chance,next,tmp,intpoints;
  string cardnum,cardcol;
  if(playing!="yes")
  { write("What exactly were you planning to do? I mean: nobody is playing 51!\n");
    return 1;
  }
  if(!name)
  { write("Whose cards do you want to peek?\n");
    return 1;
  }
  for(i=0;i<nrofpl;i++)
  { if(CTP==pl[i])
    { if(coughts[i]>2)
      { write("You have already been cought three times, and don't take the risk\n"+
              "of being cought another time. That would embarrass you too much.\n");
        say("You saw "+CTP+" moving his head another time, trying too peek again.\n"+
            "But then he reminded the other three times he was cought and decided\n"+
            "to wait at least for this game.\n");
        return 1;
      }
    }
  }
  for(j=0;j<nrofpl;j++)
  { if(CTP==pl[j])
    { for(i=0;i<nrofpl;i++)
      { if(capitalize(name)==pl[i])
        { write("You try to peek "+capitalize(name)+"'s cards......\n"+
                "\tYou have to move your head a little......\n"+
                "\t\tYou try to act quite normally......\n"+
                "\t\t\t(Should they notice????)\n");
          chance=random(5+2*coughts[j]);
          if(chance<3)
          { write("Yeah... you succeed, nobody saw you cheating!\n");
            write(capitalize(name)+"'s cards:\n");
            k=0;
            for(l=1;l<6;l++)
            { next="done";
              while(next=="done")
              { if(i+nrofpl*k>39)
                { write("That's all.\n");
                  return 1;
                }
                next=card[i+nrofpl*k];
                k=k+1;
              }
              tmp=sscanf(next,"%s-%s",cardcol,cardnum);
              if(cardnum=="A") cardnum="Ace"; if(cardnum=="J") cardnum="Jack";
              if(cardnum=="Q") cardnum="Queen"; if(cardnum=="K") cardnum="King";
              if(cardcol=="S") cardcol="spades"; if(cardcol=="D") cardcol="diamonds";
              if(cardcol=="H") cardcol="hearts"; if(cardcol=="K") cardcol="clubs";
              write("\t"+l+": "+cardnum+" of "+cardcol+"\n");
            }
          }
          else
          { write("Oeps... they cought ya. That wasn't a smart move, bud!\n"+
                  "Someone kicks you under the table, and your cheeks are burning\n"+
                  "as you notice that the other players saw YOUR cards!\n");
            say(CTP+" tried to peek the cards of "+name+", but when he\n"+
                "moved his head a little you saw "+CTP+"'s cards!\n"+
                "You kick him, and you tell the others that "+CTP+" has:\n");
            coughts[j]++;
            k=0;
            for(l=1;l<6;l++)
            { next="done";
              while(next=="done")
              { if(j+nrofpl*k>39)
                { say("That's all.\n");
                  return 1;
                }
                next=card[j+nrofpl*k];
                k=k+1;
              }
          tmp=sscanf(next,"%s-%s",cardcol,cardnum);
              if(cardnum=="A") cardnum="Ace"; if(cardnum=="J") cardnum="Jack";
              if(cardnum=="Q") cardnum="Queen"; if(cardnum=="K") cardnum="King";
              if(cardcol=="S") cardcol="spades"; if(cardcol=="D") cardcol="diamonds";
              if(cardcol=="H") cardcol="hearts"; if(cardcol=="K") cardcol="clubs";
              say("\t"+l+": "+cardnum+" of "+cardcol+"\n");
            }
          }
          return 1;
        }
      }
      write("Hmm.. maybe it's better to pick a player's cards to snoop.\n");
      return 1;
    }
  }
  write(capitalize(name)+" holds his cards close to his chest, you can't see them.\n");
  say(CTP+" tried to look at your cards, but you hold your cards close to\n"+
      "your chest. He can't see them.\n");
  return 1;
}

leave()
{ int i;
  if(playing=="yes")
  { for(i=0;i<nrofpl;i++)
    if(CTP==pl[i])
    { if(dontleave==1)
      { write("You are playing 51!! You can't just go then, leaving the \n"+
              "other players here! First finish the game. Then you are \n"+
              "allowed to leave.\n"+
              "If you didn't wanna play this game, you should have left \n"+
              "before you dropped your first card.\n");
        say(CTP+" tried to leave the building.. while playing 51 !!!\n"+
           "Fortunately, Hippo forced him to stay and finish the game first.\n");
        return 1;
      }
      else
      {
        write("Aha... you didn't wanna play fiftyone with them? It's ok with me...\n");
        say(CTP+" doesn't wanna play, I guess. He left the room before he\n"+
           "dropped his first card. You can start again without him, or\n"+
           "wait for another chance to beat him.\n");
        playing=0;
      }
    }
  }
  say(CTP+" leaves this room silently.\n");
  write("You leave the room silently.\n");
  call_other(this_player(),"move_player","leave#players/hippo/rooms/nose");
  return 1;
}

rules(str)
{ if(!str || str!="51")
  { write("What rules do you wanna read? (syntax: 'rules 51'.\n"); }
  else
  { write("\n=============================================================\n"+
          "|         *                                       *         |\n"+
          "|         **     *  *  ****  *     *     ***     **         |\n"+
          "|    ********    *  *  *     *     *     * *    ********    |\n"+
          "|     ********   ****  ***   *     *     * *   ********     |\n"+
          "|    ********    *  *  *     *     *     * *    ********    |\n"+
          "|         **     *  *  ****  ****  ****  ***     **         |\n"+
          "|         *                                       *         |\n"+
          "|                                                           |\n"+
          "|  FIFTY-ONE RULES   51-RULES   FIFTY-ONE RULES   51-RULES  |\n"+
          "|                                                           |\n"+
          "|   You get five cards. One at a time, the players drop a   |\n"+
          "|  card from their hand, and receive another one from the   |\n"+
          "| deck. The total value of the cards which has been thrown  |\n"+
          "|  on the table will be counted. The one who throws a card  |\n"+
          "| which makes the total value more than 51 lost. The amount |\n"+
          "|   of points above 51 will be added to the scores of the   |\n"+
          "|   other players, while the score of this player will be   |\n"+
          "|  decreased with the total number of points which has been |\n"+
          "|             added. All scores will be stored.             |\n"+
          "|...........................................................|\n"+
          "| The values of the cards are as follows:                   |\n"+
          "|   9 :  0          |    J : 1         |   6 : 6            |\n"+
          "|   5 :  5 or  -5   |    Q : 2         |   7 : 7            |\n"+
          "|  10 : 10 or -10   |    K : 3         |   8 : 8            |\n"+
          "|                   |    A : 1 or 11   |                    |\n"+
          "|...........................................................|\n"+
          "| Available commands:                                       |\n"+
          "|      51 <names>        --> start game                     |\n"+
          "|      show              --> show cards                     |\n"+
          "|      put card <number> --> drop a card                    |\n"+
"|      peek <name>      --> peek someone's cards          |\n"+
          "|      scores            --> see all scores                 |\n"+
          "==================================================Hippo======\n");
  }
  return 1;
}

help(arg)
{ object ob;
  int i;
  if(!arg)
  { say(CTP+" asks for help on 51.\n");
    write("If, for some reason, this game seems to be corrupted, for instance\n"+
          "when you can't start a new game, while noone is playing, you can\n"+
          "try to reset the game.\n"+
          "most cases this will be sufficient. If not, you'd better call\n"+
          "Hippo, and tell him exactly what was wrong. Be as specific as\n"+
          "possible about what has happened or what you have been doing.\n"+
          "\nTo reset the game, type: -->  help reset 51  <--\n");
          return 1;
  }
  if(arg=="reset 51")
  { if(playing=="yes")
    { for(i=0;i<nrofpl;i++)
      { ob=present(lower_case(pl[i]),environment(this_player()));
        if(!ob || !living(ob))
        { write("Ok, I'll reset the game now. I found something\n"+
                "which might be corrupted in this game. You should\n"+
                "try to start again, and see if this worked out. If\n"+
                "not, call Hippo.\n");
          say(CTP+" resetted the 51 game.\n");
          playing="no";
          score=0;
          dontleave=0;
          turn=0;
          return 1;
        }
      }
      write("Hmm.. I can't find any mistake. If this game doesn't work\n"+
            "properly, mail Hippo. Else you are trying to cheat in here.\n"+
            "I hope for you it's the first option....\n"+
            "PS: It might be that you can't play, because others are \n"+
            "    currently playing. Look at the table to verify.\n");
      say(CTP+" tried to reset 51, which didn't work out. If nothing is\n"+
          "wrong with this game, this means he tried to cheat!\n");
      return 1;
    }
    write("Nothing seems to be wrong. Just type 51 <name(s)>. If this\n"+
          "game doesn't work properly, mail Hippo. Else you are trying \n"+
          "to cheat in here!!\n");
    say(CTP+" tried to reset 51, but nothing seems to be wrong. If I'm\n"+
        "right about that, this means he tried to cheat!\n");
    return 1;
  }
  write("What help do you want? (Just type 'help' for more).\n");
  return 1;
}

start(str)
{ string toomany,more;
  object ob;
  int i,j;
  if(playing=="yes")
  { write("Look at the table and you'll notice that the table is occupied.\n"+
          "You have to wait until they are finished\n");
    return 1;
  }
  if(!str) { write("Try: 51 <name> <name> <name>\n"); return 1; }
  str=str+" ";
  nrofpl=sscanf(str,"%s %s %s %s %s %s %s %s %s",pl[1],pl[2],pl[3],+
  pl[4],pl[5],pl[6],pl[7],more,toomany);
  nrofpl=nrofpl+1;
  if(nrofpl>8)
  { write("You can only play this game with maximum of eight players,\n"+
  { write("You can only play this game with two, three or four players,\n"+            "including yourself. You must type start name1 name2 name3,\n"+
          "including yourself. The game did not start, try agian.\n");
    return 1;
  }
  pl[0]=TP;
  for(i=0;i<nrofpl;i++) pl[i]=capitalize(pl[i]);
  for(i=0;i<nrofpl-1;i++)
  { for(j=i+1;j<nrofpl;j++)
    { if(pl[i]==pl[j])
      { write("All players should be different!\n");
        return 1;
  } } }
  for(i=1;i<nrofpl;i++)
  { ob=present(lower_case(pl[i]),environment(this_player()));
    if(!ob || !living(ob))
    { write("Hmm... I don't see "+pl[i]+" here, try again.\n");
      say(pl[0]+" tried to start a game of fiftyone with \n");
      for(j=1;j<nrofpl-1;j++) say(pl[j]+", ");
      say(pl[nrofpl-1]+", but since "+pl[i]+" is not present,\n"+
          "this game will not start\n");
      return 1;
  } }
  score=0;
  dontleave=0;
  turn=0;
  write("Ok, you sit down at the table and start a game of 51 with them.\n"+
        "I'll give you five cards now.\n");
  say(CTP+" started a game of 51 with:\n");
  for(i=0;i<nrofpl;i++) say("\t"+capitalize(pl[i])); say(".\n");
  say("They all take a seat around the table and take their five cards.\n");
  shake();
  playing="yes";
  return 1;
}

shake()
{  int whatcard, oldarray, newarray, cardsize;
   int k,m,n;
   string cardarray;
   cardarray=({"S-5","S-6","S-7","S-8","S-9","S-10","S-J","S-Q","S-K","S-A",
            "H-5","H-6","H-7","H-8","H-9","H-10","H-J","H-Q","H-K","H-A",
            "D-5","D-6","D-7","D-8","D-9","D-10","D-J","D-Q","D-K","D-A",
          "K-6","K-7","K-8","K-9","K-10","K-J","K-Q","K-K","K-A"});
   cardsize=sizeof(cardarray);
   oldarray = allocate (cardsize+1);
   newarray = allocate (cardsize);
   card = allocate (cardsize);
   for(n=0;n<cardsize;n++) oldarray[n]=n;
   for(n=0;n<cardsize;n++)
   {  k=0;
      whatcard=oldarray[random(cardsize-n)];
      for(m=0;m<cardsize-n;m++)
      {  if(oldarray[m]==whatcard) m=m+1;
         newarray[k]=oldarray[m];
         k=k+1;
      }
      card[n]=cardarray[whatcard];
      for(m=0;m<cardsize;m++) oldarray[m] = newarray[m];
   }
   write("Type 'show' to see them.\n");
   say("If you are one of the players, type 'show' to see them.\n");
   return 1;
}

show()
{ int i,k,l,tmp;
  string next,cardcol,cardnum;
  if(playing=="yes")
  { for(i=0;i<nrofpl;i++)
    { if(CTP==pl[i])
      { write("Your cards:\n");
        k=0;
        for(l=1;l<6;l++)
        { next="done";
          while(next=="done")
          { if(i+nrofpl*k>39)
            { write("There are no more cards at the deck.\n");
              return 1;
            }
            next=card[i+nrofpl*k];
            k=k+1;
          }
          tmp=sscanf(next,"%s-%s",cardcol,cardnum);
          if(cardnum=="A") cardnum="Ace"; if(cardnum=="J") cardnum="Jack";
          if(cardnum=="Q") cardnum="Queen"; if(cardnum=="K") cardnum="King";
          if(cardcol=="S") cardcol="spades"; if(cardcol=="D") cardcol="diamonds";
          if(cardcol=="H") cardcol="hearts"; if(cardcol=="K") cardcol="clubs";
          write("\t"+l+": "+cardnum+" of "+cardcol+"\n");
        }
        return 1;
    } }
    write("Hmm.. you don't play this game now. Look around and you'll\n"+
          "find out that "); for(i=0;i<nrofpl;i++) write(pl[i]+", ");
    write("are playing 51.\n");
    say(CTP+" tried to intervene, the bastard!\n",this_player());
  }
  else { write("Hmm.. if you were playing 51, I could show you your cards.\n"); }
  return 1;
}

put(str)
{ int tmp,num,i,k,who,cardsc,gain,x,z,nrcard,l;
  string word,next,cardnum,cardcol,dummy;
  if(playing=="yes")
  { for(who=0;who<nrofpl;who++)
    { if(CTP==pl[who])
      { if(!str || sscanf(str,"%s %d",word,num)!=2 || word!="card")
        { show();
          write("What card do you wanna put? (syntax: put card <number>)\n");
          return 1;
        }
        if(num>5 || num<1)
        { write("Hmm.. You don't have that many cards, man!\n");
          return 1;
        }
        if(CTP!=pl[turn])
        { write("Hey man, it's "+pl[turn]+"'s turn to put a card, not yours!\n");
          say("WATCH OUT! "+CTP+" wanted to cheat.\n");
          say("He tried to put a card on the table, while it's not hurn!\n");
          return 1;
        }
        k=0;
        for(l=0;l<num;l++)
        { next="done";
          while(next=="done")
          { if(who+nrofpl*k>39)
            { write("You don't have that many cards, there are no more at the deck!\n");              return 1;
            }
            next=card[who+nrofpl*k];
            nrcard=who+nrofpl*k;
            k=k+1;
        } }
        tmp=sscanf(next,"%s-%s",cardcol,cardnum);
        if(cardnum=="A") cardnum="Ace";    if(cardnum=="J") cardnum="Jack";
        if(cardnum=="Q") cardnum="Queen";  if(cardnum=="K") cardnum="King";
        if(cardcol=="S") cardcol="spades"; if(cardcol=="D") cardcol="diamonds";
        if(cardcol=="H") cardcol="hearts"; if(cardcol=="K") cardcol="clubs";
        write("You drop the "+cardnum+" of "+cardcol+".\n");
        say(pl[turn]+" drops the "+cardnum+" of "+cardcol+".\n");
        if(cardnum=="Ace")
        {  score=score+11;
           if(score>51) score=score-10;
        }
        else { if(cardnum=="Jack") { score=score+1; }
          else { if(cardnum=="Queen") { score=score+2; }
            else { if(cardnum=="King") { score=score+3; }
              else { tmp=sscanf(next,"%s-%d",dummy,cardsc);
                     if(cardsc==9) {score=score; }
                     else { if(cardsc==5)
                            { score=score+5;
                              if(score>51) score=score-10;
                            }
                       else { if(cardsc==10)
                              { score=score+10;
                                if(score>51) score=score-20;
                              }
                         else { score=score+cardsc; }
             } } } }      } }
        if(score>51)
        { z=score-51;
          write("\nThat "+cardnum+" makes "+score+"!!! \n"+
                "It'll cost you "+z+" points each player...\n");
           say("\n"+CTP+" made the score "+score+" by dropping the "+cardnum+" of "+cardcol+".\n"+
            "This means the other players WON "+z+" points this game!\n\n");
          pay();
          return 1;
        }
        card[nrcard]="done";
        turn++;
        if(turn>nrofpl-1) { dontleave=1; turn=0; }
        say("Total: "+score+", "+pl[turn]+" has to put next card.\n");
        write("Total: "+score+", "+pl[turn]+" has to put next card.\n");
        return 1;
      }
    }
    write("Hmm.. you don't play this game now. Look around and you'll\n"+
          "find out that "+pl[0]);
    for(i=1;i<nrofpl-1;i++) write(", "+pl[i]);
    write(" and "+pl[nrofpl-1]+" are playing 51.\n");
    say(CTP+" tried to intervene, the bastard!\n");
  }
  else
  { write("Maybe it's better to start a game before you drop a card!\n"); }
  return 1;
}

pay()
{ string addpl,list,name,new_name;
  int sc,gain,high_score,new_score,ok,nr,i,tmp;
  write("UPDATING HIGHSCORE-LIST...\n");
  say("UPDATING HIGHSCORE-LIST...\n");
  addpl=allocate(4);
  for(i=0;i<4;i++) addpl[i]=0;
  gain=score-51; nr=0;
  list=name_score; name_score="";
  while(list!="\n" && list!= "" && list!=0)
  { tmp=sscanf(list,"%s %d\n%s",name,sc,list);
    for(i=0;i<nrofpl;i++)
    { if(name==pl[i])
      { if(name==CTP) { sc=sc+((1-nrofpl)*gain); }
        else { sc=sc+gain; }
        addpl[nr]=name+" "+sc+"\n";
        pl[i]="done"; ok=1; nr++;
    } }
    if(ok==0) name_score=name_score+name+" "+sc+"\n";
    ok=0;
  }
  for(i=0;i<nrofpl;i++)
  { if(pl[i]!="done")
    { if(pl[i]==CTP) { sc=(1-nrofpl)*gain; }
      else { sc=gain; }
      addpl[nr]=pl[i]+" "+sc+"\n";
      nr++;
  } }
  list=name_score; name_score="";
  while(list!="\n" && list!="" && list!=0)
  { tmp=sscanf(list,"%s %d\n%s",name,high_score,list);
    if(tmp!=2 && tmp!=3) { write("Error 6. Call Hippo..\n"); return 1; }
    { for(i=0;i<nrofpl;i++)
      { if(addpl[i]!="\n" && addpl[i]!="" && addpl[i]!=0 && addpl[i]!="done")
        { if(sscanf(addpl[i],"%s %d\n",new_name,new_score)!=2)
          { write(addpl[i]+"Error 7. Call Hippo..\n"); return 1; }
          if(new_score>high_score)
          { name_score=name_score+addpl[i];
            addpl[i]="done";
    } } } }
    name_score=name_score+name+" "+high_score+"\n";
  }
  for(i=0;i<nrofpl;i++) { if(addpl[i]!="done") name_score=name_score+addpl[i]; }
  playing="no";
  save_object(SCORES);
  write("\n\t\tGame over...\nStart a new game by typing '51 <names>'.\n");
  for(i=0;i<nrofpl;i++)
  { pl[i]=0;
    coughts[i]=0;
  }
  nrofpl=0; new_name=0; new_score=0;
  return 1;
}

scores(str)
{ string name,rest;
  int high_score,i,tmp;
  if (name_score==0 || name_score=="\n" || name_score=="")
  { write("The high score list is empty.\n");
    return 1;
  }
  write("\tRank Player\tScore\n");
  i=1; rest=name_score;
  while(rest!=0 && rest!="" && rest!="\n")
  { tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
    if (tmp!=2 && tmp!=3)
    { write("Error 8. Call Hippo..\n");
      return 1;
    }
    write("\t  "+i+". "+name+"\t "+high_score+"\n"); i++;
  }
  return 1;
}
