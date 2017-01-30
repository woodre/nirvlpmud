int n,stock,hand,score,myscore,joho;
string shaked;
#define TP capitalize(call_other(this_player(),"query_name"))

reset()
{  shake();
   return;
}
id(str) { return str=="cards"; }
long()
{  write("These are cards to play twenty-one.\n"+
         "To see your cards, type 'show'.\n"+
         "Type 'rules 21' if you don't know how to play.\n");
}
short() { return "A hand of Twenty-one playing cards"; }
get() { return 1; }
drop() { return 0; }
value() { return 0; }

init()
{  add_action("rules","rules");
   add_action("show","show");
   add_action("card","card");
   add_action("stay","stay");
}

rules(str)
{ if(str!="21"&&str!="Twenty-one"&&str!="twenty-one"&&str!="twentyone")
   {  write("What rules you wanna see? --> Twenty-one?\n");
      return 1;
  }
   write("\t...............................................\n"+
         "\t..................Twenty One...................\n"+
         "\t...............................................\n"+
         "This is quite an easy game. It's quite the same as Blackjack, the\n"+
         "main difference is the value of the cards. I'll explain the basic rules\n"+
         "in a nutshell.\n"+
         "You play against me, there are no other players involved. Cardvalues are\n"+
         "Jack: 1, Queen: 2, King: 3, Ace: 1 or 11, the other cards show their\n"+
         "own values. I give you two cards in advance. You can ask for another \n"+
         "card by typing 'card', or you can just 'stay'. In that case it's my\n"+
         "turn to draw some cards. I stay if I have more than 17 points, else \n"+
         "I draw another card. Suppose one has exactly 21, than he gets a 750\n"+
         "coins bonus from the other player. The looser always pays 200 times\n"+
         "the difference in score to the winner of the game. Finally, when your\n"+
         "points exceed 21, you will loose 750 coins.\n\n"+
         "Easy, huh? Ok, let's play the game then.\n"+
         "If you wanna see what cards you have, type 'show'.\n");
   return 1;
}

stay()
{  int i,tmp,next,cardsc,coins,ace,mon;
   string cardcol,cardnum;
   if(call_other(this_player(),"query_money",0) < 2500)
   {  write("Hmm.. you don't have enough money to gamble. First make sure\n"+
            "that you have at least 2500 coins. Than come back to this place.\n");
     say("You laugh... "+TP+" has too little money to play Twenty-one!\n");
      return 1;
   }
   write("Hmm.. you don't want a card anymore, and you don't have 21 points\n"+
         "yet, right? I'll see what cards i'm gonna draw from the deck. You\n"+
         "can watch my cards now... \n");
myscore=0;
ace=0;
next=hand;
   while(myscore<17)
   {  next=next+1;
      tmp=sscanf(shaked[next],"%s-%s",cardcol,cardnum);
      if(cardnum=="A"||cardnum=="J"||cardnum=="Q"||cardnum=="K")
         tmp=sscanf(shaked[next],"%s-%d",cardcol,cardnum);
      if(cardnum=="A")
      {  cardnum="Ace";
         ace=ace+1;
         myscore=myscore+11;
         if(myscore>21) { myscore=myscore-10; ace=ace-1; }
      }
      else { if(cardnum=="J") { cardnum="Jack"; myscore=myscore+1; }
         else { if(cardnum=="Q") { cardnum="Queen"; myscore=myscore+2; }
             else { if(cardnum=="K") { cardnum="King"; myscore=myscore+3; }
               else { tmp=sscanf(shaked[next],"%s-%d",cardcol,cardsc);
                      myscore=myscore+cardsc;
           }  }  }  }
      if(myscore>21 && ace>0) { myscore=myscore-10; ace=ace-1; }
   }
   for(i=hand+1;i<next+1;i++)
   {  tmp=sscanf(shaked[i],"%s-%s",cardcol,cardnum);
      if(cardnum=="A") cardnum="Ace"; if(cardnum=="J") cardnum="Jack";
      if(cardnum=="Q") cardnum="Queen"; if(cardnum=="K") cardnum="King";
      if(cardcol=="S") cardcol="spades"; if(cardcol=="D") cardcol="diamonds";
      if(cardcol=="H") cardcol="hearts"; if(cardcol=="K") cardcol="clubs";
      write("\t"+cardnum+" of "+cardcol+"\n");
   }
   write("\n");
   if(myscore>21)
   {  coins=750;
      write("Shit. I have more than 21 points...\n"+
            "That means you won, I'll give you 750 coins for this game.\n"+
            "I'll shake the cards again. You can play (show) or just walk away\n"+
            "and play another time.\n\n");
           say(TP+" won his Twenty-one game.\n");
   }
   else
   {  write("I have "+myscore+" points, you have "+score+" points. \n");
      if (score>myscore)
      {  coins=(score-myscore)*200;
         if(score==21)
         {  coins=coins+750;
            write("WOW!!?! 21 Points?? How did you do that?\n"+
              "Anyway, here you are: 750 gold coins plus the difference,\n"+
              "which makes "+coins+" coins.\n");
           say(TP+" has 21 points with Twenty-one!\n");
         }
         else
         { write("That means you won this time, I'll give you "+coins+" coins.\n"+
               "I'll shake the cards again. You can look at your cards again\n"+
               "or just walk away and play another time.\n\n");
           say(TP+" won his Twenty-one game.\n");
      }  }
      else
      {  if(score==myscore)
         {  coins=0;
            write("A draw. I'll shake the cards again. You can have a look at them\n"+
                  "or continue your own life and play another time.\n\n");
         }
         else
         {  if(score<myscore)
            {  coins=(score-myscore)*200;
               if(myscore==21)
               {  coins=coins-750;
                  write("YEAH! I have 21 points!!!\n"+
                        "That's gonna cost you 750 coins extra, man!\n");
               }
              write("I won this time. You owe me "+-coins+" coins."+
                    " I'll shake the cards\n"+
                     "again. Look at them or play another time.\n\n");
              say(TP+" lost his Twenty-one game.\n");
   }  }  }  }
  coins = 0;
   call_other(this_player(),"add_money",coins);
   shake();
   return 1;
}

count()
{  int cardsc,tmp,coins;
   string dump,pic;
   score=0;
   for(n=0;n<hand;n++)
   {  tmp=sscanf(shaked[n],"%s-%s",dump,pic);
      if (pic=="J") { score=score+1; }
      else { if (pic=="Q") { score=score+2; }
           else { if (pic=="K") { score=score+3; }
                else { if (pic=="A")
                       {  score=score+11;
                           joho=joho+1;
                          if(score>21) { score=score-10; joho=joho-1; }
                       }
                     else { tmp=sscanf(shaked[n],"%s-%d",dump,cardsc);
                            score=score+cardsc;
   }       }    }    }    }
   if (joho>0 && score>21) score=score-10;
   if(score>21)
   {  write("You have more than 21 points. You LOST!!\n"+
            "This costs you 750 coins.. *grin*\n\n"+
           "I'll shake the cards again."+
           " You could go away and take the cards with\n"+
            "you or type 'show' and play now.\n");
      say(TP+" throws his cards away as he has more than 21 points again.\n");
      coins=-750;
   coins = 0;
      call_other(this_player(),"add_money",coins);
      shake();
      return 1;
   }
   else { write("\tTotal score is: "+score+"\n"); }
}

card()
{  int mon;
   if(call_other(this_player(),"query_money",0) < 2500)
   {  write("Hmm.. you don't have enough money to gamble. First make sure\n"+
            "that you have at least 2500 coins. Than come back to this place.\n");
     say("You laugh... "+TP+" has too little money to play Twenty-one!\n");
      return 1;
   }
   write("Ok, I gave you a card.\n");
   hand=hand+1;
   stock=stock-1;
   show();
   write("You want another 'card', or you 'stay'?\n");
   return 1;
}

show()
{  int tmp;
   string cardcol, cardnum;
   write("Your cards are:\n");
   for(n=0;n<hand;n++)
   {  tmp=sscanf(shaked[n],"%s-%s",cardcol,cardnum);
      if(tmp!=2) write("Something is wrong.\nPlease, mail Hippo!!\n");
      if(cardnum=="A") cardnum="Ace"; if(cardnum=="J") cardnum="Jack";
      if(cardnum=="Q") cardnum="Queen"; if(cardnum=="K") cardnum="King";
      if(cardcol=="S") cardcol="spades"; if(cardcol=="D") cardcol="diamonds";
      if(cardcol=="H") cardcol="hearts"; if(cardcol=="K") cardcol="clubs";
      write("\t"+cardnum+" of "+cardcol+"\n");
   }
   count();
   return 1;
}

shake()
{  int whatcard, oldarray, newarray;
   int k,l,m,o;
   string card;
   card = allocate (32);
   card = ({"S-7","S-8","S-9","S-10","S-J","S-Q","S-K","S-A",
            "H-7","H-8","H-9","H-10","H-J","H-Q","H-K","H-A",
            "D-7","D-8","D-9","D-10","D-J","D-Q","D-K","D-A",
            "K-7","K-8","K-9","K-10","K-J","K-Q","K-K","K-A"});
   oldarray = allocate (sizeof(card)+1);
   newarray = allocate (sizeof(card));
   shaked = allocate (sizeof(card));
   stock=30; hand=2; joho=0;
   for(n=0;n<sizeof(card);n++) oldarray[n]=n;
   for(n=0;n<sizeof(card);n++)
   {  k=0;
      whatcard=oldarray[random(sizeof(card)-n)];
      for(m=0;m<sizeof(card);m++)
      {  if(oldarray[m]==whatcard) {m=m+1; }
         newarray[k]=oldarray[m];
          k=k+1;
      }
      shaked[n]=card[whatcard];
      for(l=0;l<sizeof(card);l++) oldarray[l] = newarray[l];
   }
   show();
   return 1;
}
