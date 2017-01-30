#include "/players/hippo/rvd.h"

string pl,wind,card;
int playing,turn,to_play,nrofpl;
 
/* 
  pl[0..4]
  card[0..52]
  wind[pl][0..13]
*/

id(str) { return str=="bridge"; }
short() { return "Bridge table"; }
get()   { return 1; }
drop()  { return 0; }
long()
{ write("With this deck of cards you can play a game of 'bridge'.\n"+
  "Type bridge to start\n");
  return 1;
}
reset()
{ int i;
  pl=allocate(4);
  for(i=0;i<4;i++) pl[i]=0;
  card=allocate(52);
  wind=allocate(4);
  for(i=0;i<4;i++) wind[i]=allocate(13);
  return 1;
}
init()
{
  add_action("rules","rules");
  add_action("bridge","bridge");
  add_action("show","show");
  add_action("put","put");
  add_action("bid","bid");
  add_action("solution","solution");
}
rules(str)
{ if(!str || str!="51")
  { write("What rules do you wanna read? (syntax: 'rules 51'.\n"); }
  else
  { write("\n=============================================================\n"+
          "|        *                                         *        |\n"+
          "|        **     ***   ***   *  ***    **   ***    **        |\n"+
          "|   ********    *  *  *  *  *  *  *  *     *     ********   |\n"+
          "|    ********   ***   ***   *  *  *  * **  **   ********    |\n"+
          "|   ********    *  *  *  *  *  *  *  *  *  *     ********   |\n"+
          "|        **     ***   *  *  *  ***    **   ***    **        |\n"+
          "|        *                                         *        |\n"+
          "|                                                           |\n"+
          "|  BRIDGE BRIDGE BRIDGE BRIDGE BRIDGE BRIDGE BRIDGE BRIDGE  |\n"+
          "|                                                           |\n"+
          "|                                                           |\n"+
          "|                                                           |\n"+
          "|...........................................................|\n"+
          "| Available commands:                                       |\n"+
          "|      bridge <names>    --> start game                     |\n"+
          "|      show              --> show cards                     |\n"+
          "|      put card <number> --> drop a card                    |\n"+
          "==================================================Hippo======\n");
  }
  return 1;
}
bridge(str)
{ object ob;
  int i,j;
  str=str+" ";
  nrofpl=sscanf(str,"%s %s %s",pl[1],pl[2],pl[3]);
write("<"+pl[1]+"><"+pl[2]+"><"+pl[3]+">\n");
  nrofpl++;
  if(nrofpl!=4)
  { write("You can't play a complete game, right\n"+
    "now you just get cards to practice some bidding.\n");
    say(CTP+" gave some cards around to practice bridge bidding.\n");
    for(i=nrofpl;i<4;i++) pl[i]="Dummy";
  }
  pl[0]=CTP;
  for(i=1;i<nrofpl;i++) pl[i]=capitalize(pl[i]);
  for(i=1;i<nrofpl;i++)
  { ob=present(lower_case(pl[i]),environment(this_player()));
    if(!ob || !living(ob))
    { write("Hmm... I don't see "+pl[i]+" here, try again.\n");
      say(pl[0]+" tried to start a game of bridge with \n");
      for(j=1;j<nrofpl;j++) say(pl[j]+", ");
      say(pl[nrofpl-1]+", but since "+pl[i]+" is not present,\n"+
          "this game will not start\n");
      return 1;
    }
  }
  turn=0;
  write("Ok, you sit down at the table and start a game of bridge with them.\n"+
  "I'll deal the cards now.\n");
  say(CTP+" started a game of bridge with:\n");
  for(i=0;i<nrofpl;i++) say("\t"+capitalize(pl[i])); say(".\n");
  shake();
  return 1;
}
shake()
{ int whatcard,oldarray,newarray,cardsize,k,m,n;
  int i;
  string cardarray;
  cardarray=
  ({"S-2","S-3","S-4","S-5","S-6","S-7","S-8","S-9","S-10","S-J","S-Q","S-K","S-A",
    "H-2","H-3","H-4","H-5","H-6","H-7","H-8","H-9","H-10","H-J","H-Q","H-K","H-A",
    "D-2","D-3","D-4","D-5","D-6","D-7","D-8","D-9","D-10","D-J","D-Q","D-K","D-A",
    "K-2","K-3","K-4","K-5","K-6","K-7","K-8","K-9","K-10","K-J","K-Q","K-K","K-A"});
  cardsize=sizeof(cardarray);
  oldarray=allocate(cardsize+1);
  newarray=allocate(cardsize);
  card=allocate(cardsize);
  for(n=0;n<cardsize;n++)oldarray[n]=n;
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
  n=0;for(k=0;k<4;k++){for(m=0;m<13;m++){wind[k][m]=card[n];n++;}}
  for(i=0;i<nrofpl;i++)
  tell_object(find_living(lower_case(pl[i])),"'Show' to see cards.\n");
  playing=1;
  return 1;
}
solution()
{ int i,k,l,tmp,sp,he,di,cl;
  string next,cardcol,cardnum;
  if(playing)
  { say(CTP+" asked for the solution.\n");
    for(i=0;i<4;i++)
    { write(pl[i]+":\n");say(pl[i]+":\n");
      { write("Spades:   ");say("Spades:   ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="S")write(cardnum+" ");say(cardnum+" ");
        } write("\n");say("\n");
        write("Hearts:   ");say("Hearts:   ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="H")write(cardnum+" ");say(cardnum+" ");
        } write("\n");say("\n");
        write("Diamonds: ");say("Diamonds: ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="D")write(cardnum+" ");say(cardnum+" ");
        } write("\n");say("\n");
        write("Clubs:    ");say("Clubs:    ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="K")write(cardnum+" ");say(cardnum+" ");
        } write("\n");say("\n");
      }
    }
  }
  else{write("If you played bridge, that would be possible.\n");}
  return 1;
}
show()
{ int i,k,l,tmp,sp,he,di,cl;
  string next,cardcol,cardnum;
  if(playing)
  { for(i=0;i<nrofpl;i++)
    { if(CTP==pl[i])
      { write("Your cards:\n");
        write("Spades:   ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="S")write(cardnum+" ");
        } write("\n");
        write("Hearts:   ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="H")write(cardnum+" ");
        } write("\n");
        write("Diamonds: ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="D")write(cardnum+" ");
        } write("\n");
        write("Clubs:    ");
        for(k=0;k<13;k++)
        { tmp=sscanf(wind[i][k],"%s-%s",cardcol,cardnum);
          if(cardcol=="K")write(cardnum+" ");
        } write("\n");
        return 1;
      }
    }
    write("Hmm.. you don't play this game now. Look around and you'll\n"+
          "find out that "); for(i=0;i<nrofpl;i++) write(pl[i]+", ");
    write("are playing bridge.\n");
    say(CTP+" tried to intervene, the bastard!\n");
  }
  else{write("If you played bridge, I could show you your cards.\n");}
  return 1;
}
