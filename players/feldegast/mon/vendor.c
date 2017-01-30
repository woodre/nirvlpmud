#include "/players/feldegast/log/logs.h"
#include "/players/feldegast/defines.h"
#include "defs.h"

#define NUM_ITEMS 11


int *inventory;
int *values;

reset(arg) {
  int i;
  int maxmin;
  if(arg) {
    for(i=0; i < NUM_ITEMS; i++)
    {
      inventory[i]+=({
                      10,10,10,
                      10+random(10),10+random(10),10+random(10),
                      5,
                      10,10,
                      3,
                      6
                    })[i];
      if(inventory[i] > 50) inventory[i]=50;
    }
    tell_room(environment(this_object()),"A deliveryman arrives with new goods for the market.\n");
    return;
  }
  inventory=({
    35,35,35,
    50,50,50,
    30,30,30,
    5,15
  });
  values=({
    1400,1400,1400,
    2400,1950,2400,
    1800,
    1800,1800,
    10000,
    2250,
  });      
}

init() {
  add_action("menu","ask");
  add_action("menu","list");
  add_action("buy","buy");
  if(this_player()->query_level() > 29)
    add_action("refill","refill");
}

id(str) {
  return str=="vendor";
}

short() {
  return "A food vendor";
}

long() {
  write("A short merchant with a wooden cart full of healing items.\n"+
        "You can 'ask' him for a list of what he has.\n"
  );
}

menu() {
  write("The vendor says:  I sell the following:\n\n"+
        "\t    Item                      Quantity        Price\n"+
        "\t-------------------------------------------------------\n"+
        "\t 1. Blackberry juice          "+pad(inventory[0],16)+values[0]+
        "\n\t 2. Biscuits                  "+pad(inventory[1],16)+values[1]+
        "\n\t 3. Southern Comfort          "+pad(inventory[2],16)+values[2]+
        "\n\t 4. White Zinfandel           "+pad(inventory[3],16)+values[3]+
        "\n\t 5. Pecan pie                 "+pad(inventory[4],16)+values[4]+
        "\n\t 6. Nectar                    "+pad(inventory[5],16)+values[5]+
        "\n\t 7. Fermented berries         "+pad(inventory[6],16)+values[6]+
        "\n\t 8. Vita potion               "+pad(inventory[7],16)+values[7]+
        "\n\t 9. Majin potion              "+pad(inventory[8],16)+values[8]+
        "\n\t10. Potion of [fullheal]ing   "+pad(inventory[9],16)+values[9]+
        "\n\t11. Spiced Rum                "+pad(inventory[10],16)+values[10]+
        "\n\nYou may 'buy <str>' or 'buy # of <str>'.\n"
  );
  return 1;
}

buy(str) {
  object ob;
  string kind;
  int quantity; 
  int i;

  string file;
  int weight;
  int tcost;
  int temp;
  int index;

  if (!str) {
    write("The vendor asks: What do you want to buy?\n");
    return 1;
  }
  if(sscanf(str,"%d of %s",quantity,kind)!=2) {
    quantity=1;
    kind=str;
  }


#ifdef MARKETLOG
  write_file(MARKETLOG,
  ctime(time())+" "+pad(capitalize(TP->query_real_name()),20)+quantity+"   "+kind+"\n");
#endif

  for(i=0; i < quantity; i++) {
    switch(kind) {
      case "juice": case "jug":case "1":
        weight=2;
        file="/players/feldegast/heals/juice";
        index=0;
        break;
      case "biscuit": case "biscuits": case "tin": case "2":
        weight=2;
        file="/players/feldegast/heals/biscuits";
        index=1;
        break;
      case "comfort": case "southern comfort": case "soco": case "3":
        weight=2;
        file="/players/feldegast/heals/soco";
        index=2;
        break;
      case "heal": case "fullheal": case "10":
        weight=1;
        file="/players/feldegast/heals/fullheal";
        index=9;
        break;    
      case "zinfandel": case "white zinfandel": case "wine": case "4":
        weight=1;
        file="/players/feldegast/heals/zinfandel";
        index=3;
        break;
      case "pie": case "pecan pie": case "5":
        weight=1;
        file="/players/feldegast/heals/pecan_pie";
        index=4;
        break;
      case "nectar": case "6":
        weight=1;
        file="/players/feldegast/heals/nectar";
        index=5;
        break;
      case "berries": case "7":
        weight=1;
        file="/players/feldegast/heals/berries";
        index=6;
        break;
      case "vita": case "8":
        weight=1;
        file="/players/feldegast/heals/vita";
        index=7;
        break;
      case "majin": case "9":
        weight=1;
        file="/players/feldegast/heals/majin";
        index=8;
        break;
      case "rum": case "11":
        weight=1;
        file="/players/feldegast/heals/rum";
        index=10;
        break;
        default: write("Vendor says: Pardon sir, I do not sell that.\n");
                 return 1;
    }

    /* Do I have enough money? */
    if(TP->query_money() < values[index]) {
      write("You don't have enough money for that!\n");
      temp=i; i=quantity; quantity=temp;
    }

    /* Is that item in stock? */ 
    else if(inventory[index] <= 0) {
      write("Vendor says: I apologize sir, but we're out of that item.  Is there\n"+
            "             something else you'd like?\n");
      temp=i; i=quantity; quantity=temp;
    }

    /* Can I carry this */
    else if(!TP->add_weight(weight)) {
      write("You can't carry that!\n");
      temp=i; i=quantity; quantity=temp;
    }

    /* Sold! */
    else {
      TP->add_money(-values[index]);
      tcost+=values[index];
      inventory[index]--;
      ob=clone_object(file);
      move_object(ob,this_player());
    }
  }
  write("You buy "+quantity+" of "+kind+" for "+tcost+" coins.\n");
  say(TPN+" buys something from the vendor.\n");
  save_object("players/feldegast/mon/vendor");
  return 1;
}

int refill(string str)
{
  reset(1);
  return 1;
}

