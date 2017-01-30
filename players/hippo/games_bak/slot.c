#define TP capitalize(call_other(this_player(),"query_name"))
int coins,time,res;
string fig,turn,s;

id(str) { return str="bandit"; }
short() { return ("A one-armed bandit");
}
long()
{  write ("This is a slot machine. You can pull the arm for any\n"+          "amount of coins in between 100 and 1000. The machine\n"+          "returns you money when you get the following sequences:\n\n"+
          " picture  | three | first two | other pair\n"+
          "===========================================\n"+
          "  bar     |  15   |    10     |     4\n"+
          "  seven   |  10   |     7     |     3\n"+
          "  bottle  |   8   |     5     |     2\n"+
          "  disk    |   8   |     4     |     2\n"+
          "  star    |   6   |     3     |     2\n"+
          "  moon    |   5   |     3     |     1\n"+
          "  spade   |   4   |     2     |     1\n"+
          "  heart   |   4   |     2     |     -\n"+
          "  club    |   3   |     1     |     1\n"+
          "  diamond |   3   |     1     |     -\n\n"+
          "Besides you get your amount of coins for each bar or seven\n"+
          "and twice that money for a combination of three different\n"+
          "card-colors or in case you get a star and a moon together.\n");
   return 1;}
get()
{  write("Don't be silly, it's a very heavy one-armed bandit!!\n");   return 0; }
drop() { return 1; }
init() {add_action ("pull","pull");
        return 1;}
reset()
{  fig=allocate(10);
   turn=allocate(3);
   res=allocate(10);
   fig=({"bar","seven","bottle","disk","moon",
         "star","spade","heart","club","diamond"});
   return 1;
}

result()
{  int mag,i,why;
   if(res[4]>0 && res[5]>0)
   {  write("You get twice your "+coins+" coins, because you got a\n"+
      "star and a moon.\n");
      call_other(this_player(),"add_money",2*coins);
   }
   if(res[9]+res[8]+res[7]==3 &&
      turn[0]!=turn[1] && turn[1]!=turn[2] && turn[0]!=turn[2])
   {  write("You get twice your "+coins+" coins, because you got a\n"+
      turn[0]+", a "+turn[1]+" and a "+turn[2]+".\n");
      call_other(this_player(),"add_money",2*coins);
   }
   for (i=0;i<10;i++)
   {if (res[i]>2)
    {why=3;
     if(i<1) { mag=15;
               write ("WOW!!! Congrats, that was a lucky shot, man!\n");
             }
     else { if(i<2) { mag=10; }
      else { if(i<4) { mag=8; }
       else { if(i<5) { mag=6; }
        else { if(i<6) { mag=5; }
         else { if(i<8) { mag=4; }
          else { mag=3; }
          }}}}}
               write ("Well.. that is nice, isn't it?\n");
               say (TP+" had THREE "+fig[i]+"s at the bandit!\n");
    }
    else
    {if (res[i]>1)
     {if(turn[0]==turn[1])
      {why=2;
       if(i<1) { mag=10; }
       else { if(i<2) { mag=7; }
        else { if(i<3) { mag=5; }
         else { if(i<4) { mag=4; }
          else { if(i<6) { mag=3; }
           else { if(i<8) { mag=2; }
            else { mag=1; }
      }     }}}}}
      else
      {why=1;
       if(i<1) { mag=4; }
       else { if(i<2) { mag=3; }
        else { if(i<5) { mag=2; }
         else { if(i<6 || i==7) { mag=1; }
          else { mag=0; }
     }}     }}}
     else { why=0; mag=0; }
    }
    if(mag>0)
    {write("That's better. You won "+mag*coins+" coins this time, because\n");
     if(why==3) {write("of your three "+fig[i]+"s.\n");}
     else { if(why==2) {write("the first two figures are "+fig[i]+"s.\n");}
      else { if(why==1) {write("you got two "+fig[i]+"s.\n");}
       else { write("This should not be possible. Call Hippo.\n");}          }}
   }       }}
   call_other(this_player(),"add_money",mag*coins);
   time=0;
   return 1;
}
 
pull(arg)
{  int i,cost;
   if (!arg) {coins=100;}
   else
   {if(sscanf(arg,"%d",cost)==1)
    {if (cost<100) {coins=100;}
     else {if (cost>1000) {coins=1000;}
      else {coins=cost;}
    }     }
    else
    {write("I don't understand that. Try 'pull <amount>'\n");
     return 1;
   }}
   if(call_other(this_player(),"query_money")-coins<0)
   {  write("You don't have enough money to play this game.\n"+
            "You start to blush, while other people laugh.\n");
      say("You laugh as you notice that "+TP+" has not enough money\n"+
          "to pull the arm of the bandit.\n");
      return 1;
   }
   call_other(this_player(),"add_money",-coins);
   say(TP+" tries his luck at the slot machine.\n");
   for(i=0;i<10;i++) res[i]=0;
   for(i=0;i<3;i++) rnd();
   result();
   return 1;
}
 
rnd()
{  int n;
   if(time==1) { s="                  ";}
   else { if(time==2) {s="                                    ";}
   else {s="";}}
   n=random(32);
   if (n<4) {diamond();}
   else { if (n<8) {club();}
    else { if (n<12) {heart();}
     else { if (n<16) {spade();}
      else { if (n<19) {star();}
       else { if (n<22) {moon();}
        else { if (n<25) {bottle();}
         else { if (n<28) {disk();}
          else { if (n<30) {seven();}
           else { if (n<32) {bar();}
            else { write("Should not happen. Call Hippo.\n");
   }}}}}}}}}}
   write("\n");
   time=time+1;
   return 1;
}
 
bar() { write ( s+" ___    __   ___  \n"+
                s+" |  |  |  |  |  | \n"+
                s+" |==   |==|  |==  \n"+
                s+" |  |  |  |  |  | \n"+
                s+" ~~~   ~  ~  ~  ~ ");
   turn[time]="bar";
   res[0]=res[0]+1;
   write("\n        You get "+coins+" for each of these automatically.\n");
   call_other(this_player(),"add_money",coins);
   return 1; }
seven() { write ( s+"      //////      \n"+
                  s+"         //       \n"+
                  s+"        //        \n"+
                  s+"       //         \n"+
                  s+"      //          ");
   turn[time]="seven";
   res[1]=res[1]+1;
   write("\n        You get "+coins+" for each of these automatically.\n");
   call_other(this_player(),"add_money",coins);
   return 1; }
bottle() { write (  s+"        ..        \n"+
                    s+"        ||        \n"+
                    s+"       i__i       \n"+
                    s+"       I--I       \n"+
                    s+"       I__I       ");
   turn[time]="bottle";
   res[2]=res[2]+1;
   return 1; }
disk() { write (  s+"     ________     \n"+
                  s+"     I #### I     \n"+
                  s+"     I ____ I     \n"+
                  s+"     I ll l I     \n"+
                  s+"     ~~````~~     ");
   turn[time]="disk";
   res[3]=res[3]+1;
   return 1; }
moon() { write (  s+"       ;,         \n"+
                  s+"        ll,       \n"+
                  s+"        :Il       \n"+
                  s+"        ll'       \n"+
                  s+"       ;'         ");
   turn[time]="moon";
   res[4]=res[4]+1;
   return 1; }
star() { write (  s+"        i         \n"+
                  s+"    ...iOi...     \n"+
                  s+"     `OOOOO'      \n"+
                  s+"     iO' `Oi      \n"+
                  s+"     '     `      ");
   turn[time]="star";
   res[5]=res[5]+1;
   return 1; }
spade() { write (   s+"        o         \n"+
                    s+"       o o        \n"+
                    s+"     o'   `o      \n"+
                    s+"     `o'T`o'      \n"+
                    s+"        I         ");
   turn[time]="spade";
   res[6]=res[6]+1;
   return 1; }
heart() { write (   s+"    oOo   oOo     \n"+
                    s+"    OOOOoOOOO     \n"+
                    s+"     OOOOOOO      \n"+
                    s+"       OOO        \n"+
                    s+"        O         ");
   turn[time]="heart";
   res[7]=res[7]+1;
   return 1; }
club() { write (  s+"       .o.        \n"+
                  s+"      ~OOO~       \n"+
                  s+"    oOOoOoOOo     \n"+
                  s+"    `OI'T`IO'     \n"+
                  s+"        I         ");
   turn[time]="club";
   res[8]=res[8]+1;
   return 1; }
diamond(){ write( s+"        I         \n"+
                  s+"      .iIi.       \n"+
                  s+"     <lIIIl>      \n"+
                  s+"      `III'       \n"+
                  s+"        I         ");
   turn[time]="diamond";
   res[9]=res[9]+1;
   return 1; }
