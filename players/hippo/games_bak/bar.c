#include "/players/hippo/rvd.h"
int total,i;
string beers,nrofbeers;

id(str) { return str == "bar"; }
short() { return "A bar"; }
long()
{ write("This is a bar, where you can order beer, chips or popcorn.\n"+
        "The barkeeper says: \n"+
        "\t'I'll bring you popcorn and chips on the table where\n"+
        "\tyou play 51, the beer must remain on the bar'.\n");
  if(nrofbeers>0)
  { write("You see "+nrofbeers+" beers on the bar, which belong to\n");
    for(i=0;i<nrofbeers;i++)
    { write(beers[i]+" ");
      if(total[i]==0) write("(empty)");
    }
    write("\n");
  }
}

query_value() { return 0; }
get() { return 0; }
drop() { return 1; }
query_weight() { return 1; }

init()
{ add_action("drink","drink");
  add_action("order","order");
}

reset()
{ beers=allocate(22);
  total=allocate(22);
  for(i=0;i<22;i++)
  { total[i]=0;
    beers[i]="noone";
  }
  nrofbeers=0;
}

drink(str)
{ if(str=="beer")
  { for(i=0;i<20;i++)
    { if(beers[i]==TP)
      { if(total[i]==0)
        { write("The glass is empty. If you want another beer, ask the barkeeper.\n");
          say(CTP+" stares at his empty glass.\n");
          return 1;
        }
        write("Hmmm... you like that taste!\n"+
              "You put ");
        if(total[i]==1) write("an empty glass"); else write("the beer");
        write(" back on the bar.\n");
        say(CTP+" drinks some beer. You get thursty yourself, too...\n");
        total[i]=total[i]-1;
        return 1;
      }
    }
    write("You didn't order a beer, yet.\n");
    return 1;
  }
  write("Sorry?\n");
  return 1;
}

order(str)
{ int j;
  if(str=="beer")
  { if(nrofbeers>20)
    { write("I don't have more glasses! First finish some beers, please.\n");
      return 1;
    }
    for(i=0;i<nrofbeers+1;i++)
    { if(beers[i]==TP && total[i]!=0)
      { write("  'Finish your other glass first', the barkeeper says.\n");
        return 1;
      }
      { if (beers[i]==TP)
        { write("The barkeeper quickly arrives and takes the empty glasses away.\n");
          say(CTP+" ordered a new beer. The barkeeper changes the empty glass for a full one.\n");
          total[i]=4;
          return 1;
        }
        else
        { if (total[i]==0)
          { if(beers[i]=="noone") nrofbeers++;
            beers[i]=TP;
            total[i]=4;
            write("Ok, you ordered a beer,\n");
            say(CTP+" orders a beer.\n");
            return 1;
          }
        }
      }
    }
    return 1;
  }
  if(str=="popcorn")
  {move_object(clone_object("players/hippo/games/popcorn"),environment(this_player()));
    write("Ok.\n");
    say(CTP+" ordered some extra popcorn.\n");
    return 1;
  }
  if(str=="chips")
  {move_object(clone_object("players/hippo/games/chips"),environment(this_player()));
    write("Ok.\n");
    say(CTP+" ordered some extra chips.\n");
    return 1;
  }
  write("Sorry?\n");
  return 1;
}
