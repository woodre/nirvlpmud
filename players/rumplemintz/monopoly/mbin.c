/* mbin.c
 * all the monopoly commands are in here in the form m_<command>(args)
 * You can add/change commands and update this file
 */
#include "path.h"

ping() { return this_object(); }  /* ping me..  to get object if not loaded */

/* these are the bin functions for the monopoly object - they start with m_ */

m_help(arg) {
  "/players/rumplemintz/monopoly/docs.c"->_help(arg);
  return 1;
}

m_show(arg) {
  if(arg=="rules") return m_rules();
  else FAIL("Usage:  show rules\n");
}
m_rules() {
  "/players/rumplemintz/monopoly/docs.c"->rules();
  return 1;
}

m_mwho(arg) {
  int i;
  string name;
  object *a;

  if(!arg || sscanf(arg,"%s",name)!=1)
    if(TPMOBJ) name=TPMOBJ->query_gamename();
    else return !notify_fail("Usage: mwho <gamename>\n");

  write(" Player            Cash     Square              Turn\n");
  write("----------------- -------- ------------------- ------\n");
  a=MAIN->query_players(name);
  for(i=0;i<sizeof(a);i++)
      write(PAD(a[i]->query_cname(),18)+PAD(MS+a[i]->query_cash(),9)
           +PAD(capitalize(extract(a[i]->query_square(),strlen(PATH)+2)),20)
           +a[i]->query_turn()+"\n");
  return 1;
}

list(a,b) {
  int i;
  string sfile,gname;
  object o;

  gname=TPMOBJ->query_gamename();
  write("Square                     Name              Owner        Houses\n");
  write("-------------------------- ----------------- ------------ ------\n");
  for(i=a;i<b;i++) {
    sfile=MAIN->square_file(i);
    write("  "+PAD(sfile->short(),27)+PAD(extract(sfile,strlen(PATH)+2),18));
    if(o=MAIN->query_owner(sfile,gname)) {
      write(PAD(o->query_cname(),14));
      if(o->query_house(i)>=MONOPOLY) write(o->query_house(i));
    }
    write("\n");
  }
  return 1;
}

m_list(what) {
  int i;

  if(!what || what!="properties") WRITE("Usage: list properties\n");
  write("Monopoly squares:\n");
  list(0,SQSZ/2);
  write(" -- Hit return to continue --\n");
  input_to("list_more");
  return 1;
}

list_more(str) { return list(SQSZ/2+1,SQSZ); }

m_mshout(what) {
  if(!what) WRITE("mshout what?\n");
  SHOUT(NAME+" mshouts: "+what+"\n");
  write("You mshout: "+what+"\n");
  return 1;
}

/* remove this next line if you don't want 'give' to work (only mgive) */
m_give(str) { return m_mgive(str); } 
m_mgive(str) {
  string what,name,plus;
  int cash,i,j,tmp,mort;
  object a,who;

  cash=0;  what=0;  name=0;  who=0;
  if(!str || (sscanf(str,MS+"%d to %s",cash,name)!=2
     && sscanf(str,"%s to %s",what,name)!=2))
    FAIL("Usage:  mgive <what> to <who>\n"
        +"what can be:  $<cash>, <property>, card\n");

  name=capitalize(name);
  if(!(a=MAIN->query_players(TPMOBJ->query_gamename()))) return 1;
  for(i=0;i<sizeof(a);i++)
    if(a[i]->query_cname()==name || a[i]->query_cname()==name+" (jail)") {
      who=a[i];
      break;
    }
  if(!who) FAIL(name+" is not playing this game.  Type 'mwho'\n");
  if(who==TPMOBJ) FAIL("That would be kind of silly, yes?\n");

  if(cash) {
    if(cash<0) WRITE("You can't do that!\n");
    if(cash>TPMOBJ->query_cash()) WRITE("You don't have that much.\n");
    who->add_cash(cash);
    TPMOBJ->add_cash(-cash);
    SHOUT(NAME+" gives "+MS+cash+" to "+name+"\n");
    write("You give "+MS+cash+" to "+name+"\n");
    return 1;
  }
  if((i=MAIN->num_square(what))!=-1) {
    what=MAIN->square_file(i)->short();
    if((j=TPMOBJ->query_house(i))==UNOWNED)
      WRITE("You don't own that property.\n");
    if(j>0)
      WRITE("You must sell the houses on that property first.\n");
    mort=(j==MORTGAGED);
    a=MAIN->monopoly(i);
    if(j==0) {
      for(j=0;j<sizeof(a);j++)
        if(TPMOBJ->query_house(a[j])>MONOPOLY)
          WRITE("You still have houses on "
                       +MAIN->square_file(a[j])->short()+"\n");
      for(j=0;j<sizeof(a);j++)
        TPMOBJ->set_house(a[j],OWNED); /*clear monopoly-we are giving one away*/
    }
    TPMOBJ->set_house(i,UNOWNED);
    tmp=1;
    if(mort) {
      who->set_house(i,MORTGAGED);
      plus="  (mortgaged).\n";
    } else {
      for(j=0;j<sizeof(a);j++)
        if(who->query_house(a[j])!=OWNED) tmp=0; /*if tmp then monopoly*/
      if(tmp) {
        who->set_house(i,MONOPOLY);
        for(j=0;j<sizeof(a);j++)
          who->set_house(a[j],MONOPOLY);
        plus=", giving "
            +({"it","him","her"})[who->query_player()->query_gender()]
            +" a monopoly!\n";
      } else {
        who->set_house(i,OWNED);
        plus="\n";
      }
    }
    write("You give "+what+" to "+name+plus);
    SHOUT(NAME+" gives "+what+" to "+name+plus);
    return 1;
  }
  if(what=="card") {
    if(!TPMOBJ->query_out_of_jail()) WRITE("You don't have any.\n");
    TPMOBJ->add_out_of_jail(-1);
    who->add_out_of_jail(1);
    write("You give a Get Out of Jail Free card to "+name+"\n");
    SHOUT(NAME+" gives a Get Out of Jail Free card to "+name+"\n");
    return 1;
  }
  FAIL("Usage:  mgive <what> to <who>\n"
      +"what can be:  $<cash>, <property>, card\n");
}

m_return() {
  string str;
  if(check_square(1)) WRITE("You are already there.\n");
  if(sscanf(file_name(environment(TP)),PATH+"/%s",str)!=1)
    WRITE("You need to be on the monopoly board first.\n");
  write("You bounce back to your square.\n");
  say(TP->query_name()+" returns to the right square.\n");
  move_object(TP,TPMOBJ->query_square());
  say(TP->query_name()+" shows back up.\n");
  return 1;
}

inventory(ob) {
  int i,j,m,h;

  write("  Inv of: "+ob->query_cname()+"\n");
  write("Cash:\n  "+MS+ob->query_cash()+"\n\n");
  write("Properties:                   Houses:   Monopoly:     ID:\n");
  for(i=0;i<SQSZ;i++)
    if(ob->query_house(i)>UNOWNED) {
      write("  "+PAD(MAIN->square_file(i)->short(),30));
      m=MAIN->num_monopoly(i);
      if((h=ob->query_house(i))==MORTGAGED) write("M          "+m);
      else if(m>0 && m<100)
        if((h=ob->query_house(i))==5) write("H          "+m);
        else if(h==OWNED) write("           "+m);
        else write(h+"          "+m);
      else write("-           ");
      write("          "+extract(MAIN->square_file(i),strlen(PATH)+2)+"\n");
      j++;
    }
  if(j==0) write("  None.\n");
  write("\nCards:\n");
  if(i=ob->query_out_of_jail())
    if(i==1) write("  Get Out Of Jail Free card\n");
    else write("  "+i+" Get Out Of Jail Free cards\n");
  else write("  None.\n");
  write("\nTotal worth:  "+MS+ob->query_worth()+"\n");
  return 1;
}

m_mi(who) { return m_inventory(who); }
m_i(who) { return m_inventory(who); }
m_inventory(who) {
  object ob;

  if(!who && TPMOBJ) return inventory(TPMOBJ);
  if((ob=find_living(who)) &&
     (ob=(present("__mobj",ob))))
    return inventory(ob);
  return 0;
}

/* maybe just see if they are in the monopoly board? */
check_square(quiet) {
  if(file_name(environment(TP))!=TPMOBJ->query_square())
    if(quiet) return 0;
    else return !write("You need to be on your square first: "
          +TPMOBJ->query_square()->short()+".\n");
  return 1;
}

m_buy(arg) {
  string square,str;
  int price,i,*mon,m,tmp;
  object obj;

  if(arg) return m_build(arg);
  if(!check_square()) return 1;
  square=TPMOBJ->query_square();
  if(!(price=square->query_price()))
    WRITE("You can't buy "+square->short()+".\n");
  if(obj=MAIN->query_owner(square,TPMOBJ->query_gamename()))
    if(obj==TPMOBJ) WRITE("You already own "+square->short()+".\n");
    else WRITE(obj->query_cname()+" owns "+square->short()+".\n");
  if((i=MAIN->num_square(square))==-1)
    WRITE("Error:  Cannot find this square!\n");
  if(TPMOBJ->query_cash()<price)
    WRITE("You don't have enough ("+price+").\n");
  TPMOBJ->add_cash(-price);
  mon=MAIN->monopoly(i);
  m=1;
  for(tmp=0;tmp<sizeof(mon);tmp++)
    if(TPMOBJ->query_house(mon[tmp])!=OWNED) m=0;
  if((tmp=MAIN->num_monopoly(i))==0 || tmp==100 || tmp==200) m=0;
  if(m) {
    TPMOBJ->set_house(i,MONOPOLY);
    for(tmp=0;tmp<sizeof(mon);tmp++) TPMOBJ->set_house(mon[tmp],MONOPOLY);
    str=" acquiring a monopoly!\n";
  } else {
    TPMOBJ->set_house(i,OWNED);
    str=".\n";
  }
  write("You buy "+square->short()+str);
  say(NAME+" buys this square"+str);
  SHOUT(NAME+" buys "+square->short()+str);
  return 1;
}

m_build(arg) {
  string square,name,str;
  int m,j,*arr,cost;

  if(!arg || (!sscanf(arg,"house on %s",square) 
           && !sscanf(arg,"house at %s",square)
           && !sscanf(arg,"houses on %d",m)
           && !sscanf(arg,"houses at %d",m))) {
    if(query_verb()=="buy") write("Usage:  buy   (for this square)\n");
    WRITE("Usage:  "+query_verb()+" house [at|on] <square>\n"
                +"        "+query_verb()+" houses [at|on] <monopoly number>\n");
  }
  if(square) return house(square);

  arr=({});
  for(j=0;j<SQSZ;j++)
    if(MAIN->num_monopoly(j)==m) arr+=({j});
  if(!sizeof(arr) ||m==100||m==200) WRITE("That is not a monopoly!\n");
  if(TPMOBJ->query_house(arr[0])<MONOPOLY)
    WRITE("You don't own that monopoly.\n");
  cost=0;
  for(j=0;j<sizeof(arr);j++)
    cost+=MAIN->square_file(arr[j])->query_housecost();
  if(cost>TPMOBJ->query_cash())
    WRITE("You don't have enough money ("+MS+cost+")\n");
  TPMOBJ->add_cash(-cost);
  for(j=0;j<sizeof(arr);j++) {
    name=MAIN->square_file(arr[j])->short();
    if(TPMOBJ->query_house(arr[j])==5) {
      write("You have a hotel on "+name+"\n");
      continue;
    }
    if(TPMOBJ->query_house(arr[j])==4) str="hotel"; else str="house";
    write("You build a "+str+" on "+name+"\n");
    SHOUT(NAME+" builds a "+str+" on "+name+"\n");
    TPMOBJ->set_house(arr[j],TPMOBJ->query_house(arr[j])+1);
  }
  return 1;
}

house(square) {
  int i,c,m,*mon,tmp1,tmp2,tmp3;
  string name,str;

  if((i=MAIN->num_square(square))==-1)
    WRITE("That square doesn't exist.\n");
  name=MAIN->square_file(i)->short();
  if((m=MAIN->num_monopoly(i))==0 || m==100 || m==200)
    WRITE("You can't build a house on "+name+"!\n");
  if((tmp1=TPMOBJ->query_house(i))==UNOWNED)
    WRITE("You don't own "+name+".\n");
  if(tmp1==MORTGAGED) WRITE("That property is mortgaged.\n");
  if(tmp1==OWNED) WRITE("You don't have the monopoly for "+name+".\n");
  if(tmp1==5) WRITE("You already have hotels.\n");
  mon=MAIN->monopoly(i);
  for(tmp2=0;tmp2<sizeof(mon);tmp2++)
    if((tmp3=TPMOBJ->query_house(mon[tmp2]))!=tmp1 && tmp3!=tmp1+1)
      WRITE("You don't have enough houses on your other"
                  +" properties in that monopoly.\n");
  if((tmp1=MAIN->square_file(i)->query_housecost())>TPMOBJ->query_cash())
    WRITE("You don't have enough money.\n");
  TPMOBJ->add_cash(-tmp1);
  if(TPMOBJ->query_house(i)==4) str="hotel"; else str="house";
  write("You build a "+str+" on "+name+"\n");
  SHOUT(NAME+" builds a "+str+" on "+name+"\n");
  TPMOBJ->set_house(i,TPMOBJ->query_house(i)+1);
  return 1;
}

m_remove(arg) { return m_sell(arg); }
m_sell(arg) {
  int i,c,m,*mon,tmp1,tmp2,tmp3;
  string square,name,str;

  if(!arg || (!sscanf(arg,"house on %s",square)
           && !sscanf(arg,"house at %s",square)
           && !sscanf(arg,"house %s",square)))
    WRITE("Usage: "+query_verb()+" house [at|on] <square>\n");

  if((i=MAIN->num_square(square))==-1)
    WRITE("That square doesn't exist.\n");
  name=MAIN->square_file(i)->short();
  if((tmp1=TPMOBJ->query_house(i))==UNOWNED)
    WRITE("You don't own "+name+".\n");
  if(tmp1==OWNED) WRITE("You don't have the monopoly for "+name+".\n");
  if(tmp1==0) WRITE("You don't have any houses on "+name+".\n");
  mon=MAIN->monopoly(i);
  for(tmp2=0;tmp2<sizeof(mon);tmp2++)
    if((tmp3=TPMOBJ->query_house(mon[tmp2]))>tmp1)
      WRITE("You have to sell a house at "
                   +MAIN->square_file(mon[tmp2])->short()+"\n");
  tmp1=MAIN->square_file(i)->query_housecost()/2;
  TPMOBJ->add_cash(tmp1);
  if(TPMOBJ->query_house(i)==5) str="hotel"; else str="house";
  write("You sell a "+str+" on "+name+" for "+MS+tmp1+"\n");
  SHOUT(NAME+" sells a "+str+" on "+name+"\n");
  TPMOBJ->set_house(i,TPMOBJ->query_house(i)-1);
  return 1;
}

m_mortgage(arg) {
  string square,name,str;
  int price,i,h,*mon,m,tmp;
  object obj;

  if(!arg || sscanf(arg,"%s",square)!=1)
    FAIL("Usage: "+query_verb()+" <property name>\n");

  if((i=MAIN->num(square))==-1)
    WRITE("That square doesn't exist.\n");
  name=MAIN->square_file(i)->short();
  price=MAIN->square_file(i)->query_price()/2;
  str=" for "+MS+price;

  if((h=TPMOBJ->query_house(i))==UNOWNED)
    WRITE("You don't own "+name+"\n");
  if(h==MORTGAGED) WRITE(name+" is already mortgaged.\n");
  if(h>MONOPOLY) WRITE(name+" has houses on it.\n");

  if(h==MONOPOLY) {
    mon=MAIN->monopoly(i);
    for(h=0;h<sizeof(mon);h++)
      if(TPMOBJ->query_house(mon[h])>MONOPOLY)
        WRITE("You still have houses on "
                     +MAIN->square_file(mon[h])->short()+"\n");
    for(h=0;h<sizeof(mon);h++)
      TPMOBJ->set_house(mon[h],OWNED);  /* clear monopoly */
    str+=" losing a monopoly!";
  }
  write("You mortgage "+name+str+"\n");
  SHOUT("++"+NAME+" mortgages "+name+str+"\n");

  TPMOBJ->set_house(i,MORTGAGED);
  TPMOBJ->add_cash(price);

  return 1;
}

m_unmortgage(arg) {
  string square,name,str;
  int price,i,h,*mon,m,tmp;
  object obj;

  if(!arg || sscanf(arg,"%s",square)!=1)
    FAIL("Usage: "+query_verb()+" <property name>\n");

  if((i=MAIN->num_square(square))==-1)
    WRITE("That square doesn't exist.\n");
  name=MAIN->square_file(i)->short();
  price=MAIN->square_file(i)->query_price()/2*(100+MORTGAGE_PERCENT)/100;
  str=" for "+MS+price;

  if((h=TPMOBJ->query_house(i))==UNOWNED)
    WRITE("You don't own "+name+"\n");
  if(h!=MORTGAGED) WRITE(name+" isn't mortgaged.\n");
  if(TPMOBJ->query_cash()<price)
    WRITE("You don't have enough.  ("+MS+price+")\n");

  TPMOBJ->add_cash(-price);

  mon=MAIN->monopoly(i);
  m=1;
  for(tmp=0;tmp<sizeof(mon);tmp++)
    if(TPMOBJ->query_house(mon[tmp])!=OWNED) m=0;
  if((tmp=MAIN->num_monopoly(i))==0 || tmp==100 || tmp==200) m=0;
  if(m) {
    TPMOBJ->set_house(i,MONOPOLY);
    for(tmp=0;tmp<sizeof(mon);tmp++) TPMOBJ->set_house(mon[tmp],MONOPOLY);
    str+=" acquiring a monopoly!";
  } else 
    TPMOBJ->set_house(i,OWNED);

  write("You unmortgage "+name+str+"\n");
  SHOUT("--"+NAME+" unmortgages "+name+str+"\n");
  return 1;
}




show_dice(i,j) {
  if(TP->query_brief()) WRITE("You roll: "+i+", "+j+"\n");
  write("You roll:    -----      -----\n");
  write("             |");
  if(i==2 || i==4 || i==5 || i==6) write("o "); else write("  ");
  if(i==3 || i==4 || i==5 || i==6) write("o"); else write(" ");
  write("|      |");
  if(j==2 || j==4 || j==5 || j==6) write("o "); else write("  ");
  if(j==3 || j==4 || j==5 || j==6) write("o"); else write(" ");
  write("|\n             |");
  if(i==1 || i==3 || i==5) write(" o ");
  else if(i==2 || i==4) write("   "); else write("o o");
  write("|      |");
  if(j==1 || j==3 || j==5) write(" o ");
  else if(j==2 || j==4) write("   "); else write("o o");
  write("|\n             |");
  if(i==3 || i==4 || i==5 || i==6) write("o "); else write("  ");
  if(i==2 || i==4 || i==5 || i==6) write("o"); else write(" ");
  write("|      |");
  if(j==3 || j==4 || j==5 || j==6) write("o "); else write("  ");
  if(j==2 || j==4 || j==5 || j==6) write("o"); else write(" ");
  write("|\n             -----      -----\n");
  write("\n");
}

turn_okay() {
  object a;
  int i,t,tt,mego,theygo;

  mego=1;    /* if this isn't cleared, then everyone else is waiting at the */
  theygo=1;  /* next turn and we should inform them that we are rolling */
  t=TPMOBJ->query_turn();
  if(!t) write("Please wait for all players to join before taking"
                     +" your next turn.\n");
  a=MAIN->query_players(TPMOBJ->query_gamename());
  if(sizeof(a)==1) return 1;

  for(i=0;i<sizeof(a);i++) {
    tt=a[i]->query_turn();
    if(tt<t) return 0;
    if(tt==t && a[i]!=TPMOBJ) mego=0;
    if(tt!=t+1 && a[i]!=TPMOBJ) theygo=0;
  }
/*   put this in incturn in mobj.c
  if(theygo) 
    MAIN->gameshout("Everyone has rolled turn "+t
                 +", you can take your next turn.\n",TPMOBJ->query_gamename());
  if(mego) write("You can take your next turn immediately.\n");
*/
  return 1;
}

m_mroll(arg) { return m_roll(arg); }
m_roll(arg) {
  int i,j,num;

  if(!turn_okay())
   WRITE("You have to wait for the other players to catch up.\n");
  if(!check_square()) return 1;
  i=random(6)+1;   j=random(6)+1;
  if(arg && NAME=="Jubal" && sscanf(arg,"%d %d",i,j)==2);
  show_dice(i,j);
  if(i==j) {
    write("                 DOUBLES!\n\n");
    if(TPMOBJ->query_in_jail()) {
      write("You get out of jail.\n");
      SHOUT(NAME+" gets out of jail by rolling doubles.\n");
      TPMOBJ->set_in_jail(0);
    }
    if(TPMOBJ->incdoubles()==3) {
      write("You have rolled doubles three times.\n");
      SHOUT(NAME+" rolls doubles three times.\n");
      TPMOBJ->clear_doubles();
      (PATH+"/_goto")->land();
      return 1;
    }
    write("You get to go again.\n");
    SHOUT(NAME+" rolls doubles and gets to go again.\n");
  } else {  /* not doubles */
    TPMOBJ->incturn();
    if(TPMOBJ->query_in_jail()) {
      if(TPMOBJ->query_in_jail()==3) {
        write("You have been in jail for 3 turns, you must pay to get out.\n");
        return m_pay(1);
      }
      TPMOBJ->set_in_jail(TPMOBJ->query_in_jail()+1);
      write("You are still in jail."
           +"  You can 'pay' to leave ("+MS+"50).\n");
      return 1;
    }
    TPMOBJ->clear_doubles();
  }

  num=MAIN->num_square(TPMOBJ->query_square());
  if(num==-1)
    WRITE("Error in looking your square up! (shouldn't happen)\n");
  say(NAME+" rolls the dice and moves forward.\n");
  MAIN->square_file(num+1)->bounce(i+j);
  return 1;
}

m_pay(force) {
  if(!force || force!=1) /* we werent called from roll..  so check_turn */
    if(!turn_okay())
      WRITE("You have to wait for the other players to catch up.\n");

  if(!TPMOBJ->query_in_jail()) WRITE("You are not in Jail.\n");
  if((!force || force!=1) && TPMOBJ->query_cash()<50)
    WRITE("You don't have enough money ("+MS+"50).\n");
  write("You pay to get out of Jail.\n");
  TPMOBJ->set_in_jail(0);
  TPMOBJ->add_cash(-50);
  return m_roll();
}

m_use(arg) {
  if(!arg || arg!="card")
    WRITE("Usage: use card  (Get Out Of Jail Free cards)\n");
  if(!turn_okay())
    WRITE("You have to wait for the other players to catch up.\n");

  if(!TPMOBJ->query_out_of_jail())
    WRITE("You don't have any Get Out Of Jail Free cards.\n");
  if(!TPMOBJ->query_in_jail()) WRITE("You are not in Jail.\n");
  write("You use your Get Out Of Jail Free card to get out of Jail.\n");
  SHOUT(NAME+" uses a Get Out Of Jail Free card.\n");
  TPMOBJ->add_out_of_jail(-1);
  TPMOBJ->set_in_jail(0);
  return m_roll();
}


show_railroad(i) {
  string pfile;
  object tmp;

  pfile=MAIN->square_file(i);

  write("------------------------------------\n"
       +"|                                  |\n"
       +"|                                  |\n"
       +"|             ^   ___              |\n"
       +"|             V__(  /              |\n"
       +"|            (  ___ \\              |\n"
       +"|            /|O   O               |\n"
       +"|                                  |\n"
       +"|  ------------------------------  |\n"
       +"|"+PAD(pfile->short(),-17-strlen(pfile->short())/2)
           +PAD("",17-strlen(pfile->short())/2)+"|\n");
  write("|  ------------------------------  |\n"
       +"|                                  |\n"
       +"|  Rent                      "+MS+"25.  |\n"
       +"|  If 2 R.R.'s are owned      50.  |\n"
       +"|  If 3  \"      \"   \"        100.  |\n"
       +"|  If 4  \"      \"   \"        200.  |\n"
       +"|                                  |\n"
       +"|  Mortgage Value           "+MS+"100.  |\n");
  if(tmp=MAIN->query_owner(pfile,TPMOBJ->query_gamename()))
  write("|  Owner: " +PAD(tmp->query_cname(),25)+"|\n");
  write("|                                  |\n"
       +"------------------------------------\n");

  return 1;
}

show_utility(i) {
  string pfile;
  object tmp;

  pfile=MAIN->square_file(i);
  write("------------------------------------\n"
       +"|                                  |\n");

  if(pfile==PATH+"/_water")
    write("|               .                  |\n"
         +"|              -+-                 |\n"
         +"|          /\\___m__                |\n"
         +"|         (((___._ \\               |\n"
         +"|          \\/     \\_|              |\n");
  else if(pfile==PATH+"/_electric")
    write("|              _-_                 |\n"
         +"|             /   \\                |\n"
         +"|             | V |                |\n"
         +"|              \\|/                 |\n"
         +"|               =                  |\n");
  else write("|  Unknown utility!!               |\n");
  write("|                                  |\n"
       +"|  ------------------------------  |\n"
       +"|"+PAD(pfile->short(),-17-strlen(pfile->short())/2)
           +PAD("",17-strlen(pfile->short())/2)+"|\n");
  write("|  ------------------------------  |\n"
       +"|                                  |\n"
       +"|    If one \"Utility\" is owned     |\n"
       +"|  rent is 4 times amount shown    |\n"
       +"|  on dice.                        |\n"
       +"|    If both \"Utilities\" are       |\n"
       +"|  owned rent is 10 times          |\n"
       +"|  amount shown on dice.           |\n"
       +"|                                  |\n"
       +"|  Mortgage Value            "+MS+"75.  |\n");
  if(tmp=MAIN->query_owner(pfile,TPMOBJ->query_gamename()))
  write("|  Owner: " +PAD(tmp->query_cname(),25)+"|\n");
  write("|                                  |\n"
       +"------------------------------------\n");

  return 1;
}

show_property(i) {
  string pfile,o;
  int tmp,j;

  pfile=MAIN->square_file(i);

  write("------------------------------------\n"
       +"|  ------------------------------  |\n"
       +"|  |         TITLE DEED         |  |\n"
       +"|  |"+PAD(pfile->short(),-15-strlen(pfile->short())/2)
       +PAD("",13-strlen(pfile->short())/2)+"|  |\n"
       +"|  ------------------------------  |\n"
       +"|                                  |\n");
  write("|            Rent "+MS+PAD(""+pfile->rent_for(OWNED)+".",16)+"|\n"
       +"|     With 1 House        ");
  if(strlen(""+pfile->rent_for(4))==4) write(MS+" ");
  else write(" "+MS);
  write(PAD(""+pfile->rent_for(1),-3)+".   |\n"
       +"|     With 2 Houses        "+PAD(""+pfile->rent_for(2),-4)+".   |\n"
       +"|     With 3 Houses        "+PAD(""+pfile->rent_for(3),-4)+".   |\n"
       +"|     With 4 Houses        "+PAD(""+pfile->rent_for(4),-4)+".   |\n"
       +"|         With HOTEL "+MS+PAD(""+pfile->rent_for(5),13)+"|\n"
       +"|                                  |\n");
  write("|       Price          "+MS+PAD(pfile->query_price()+".",11)+"|\n"
       +"|       Mortgage Value "+MS+PAD(pfile->query_price()/2+".",11)+"|\n"
       +"|       Houses cost "
                     +MS+PAD(pfile->query_housecost()+". each",14)+"|\n"
       +"|     Hotels, "+MS
            +PAD(pfile->query_housecost()+". plus 4 houses",20)+"|\n");
  write("|                                  |\n");
  if(o=MAIN->query_owner(pfile,TPMOBJ->query_gamename()))
  write("| Owner: " +PAD(o->query_cname(),10)+" Rent: "+MS
    +PAD(""+pfile->calc_rent(o),-4)+".   |\n");
  write("| For Monopoly:                    |\n");
  tmp=MAIN->monopoly(i);
  for(j=0;j<sizeof(tmp);j++) {
    write("|  "+PAD(MAIN->square_file(tmp[j])->short(),16));
    if(o=MAIN->query_owner(MAIN->square_file(tmp[j]),TPMOBJ->query_gamename()))
      write(PAD(o->query_cname(),-13)+"   |\n");
    else write("                |\n");
  }

  write("|                                  |\n"
       +"------------------------------------\n");

  return 1;
}

m_l(arg) { return m_look(arg); }
m_look(arg) {
  string what;
  object ob;
  int i,m;

  if(!arg || (!sscanf(arg,"at %s",what) && !sscanf(arg,"%s",what))) return 0;
  if((i=MAIN->num_square(PATH+"_"+what))!=-1)
    if((m=MAIN->num_monopoly(i))==100) return show_railroad(i);
    else if(m==200) return show_utility(i);
    else if(m==0) WRITE("That doesn't have a card.\n");
    else return show_property(i);
  if((ob=find_living(what)) &&
     (ob=(present("__mobj"+TPMOBJ->query_gamename(),ob))))
    return inventory(ob);
  return 0;
}

m_exit(arg) {
  string tmp;

  if(arg!="game") FAIL("Usage: exit game  (leaves game of monopoly)\n");
  destruct(TPMOBJ);  /* destructor() will call remove_player in MAIN */
  if(sscanf(file_name(environment(TP)),PATH+"/_%s",tmp)) {
    say(TP->query_name()+" jumps off the board and leaves the game.\n");
    move_object(TP,MAIN);
    say(TP->query_name()+" shows up from a game of monopoly.\n");
  }
  return 1;
}


