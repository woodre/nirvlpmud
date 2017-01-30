/* plum [stuff] - 50 hp/sp intox 12   2100  */

inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TQL (int)this_player()->query_level()
int bites;
string sht;

reset(arg) {
  if(arg) return;
  bites = 3;
}

id(str){ return str == "plum";  }

short(){ 
 if(!sht)
         if(bites == 3)
                 sht = MAG+"A whole plum"+NORM;
         if(bites == 2)
                 sht = MAG+"A partially eaten plum"+NORM;
         if(bites == 1)
                 sht = MAG+"A mostly eaten plum"+NORM;
 return sht;
}

long(){    
        write("This is a very juicy plum.  Its tender purple skin is perfectly\n"+
                "ready for you to bite into.  ");
        if(bites == 3)
        write("There are 3 bites left.\n");
    else if(bites == 2)
                write("There are 2 bites left.\n");
    else if(bites == 1)
                write("There is 1 bite left.\n");
        write("It looks ready to 'eat' and so very tasty.\n");
}

is_heal(){                      return "food";  }
query_potence(){        return 35;      }
query_save_flag(){      return 1;       }
query_value(){          return (bites * 333); }
get(){                          return 1;       }
query_weight(){         return 1;       }


void init(){
        ::init();
        add_action("bite_cmd", "eat");
}


status bite_cmd(string str){
        int NM, i,f,s,t;
        if(environment(TO) != TP) return 0;
        if(!str) return 0;
    if(str == "plum")
        {
    if(!call_other(this_player(),"eat_food", 10)) return 1;
 
    write("You take a big bite out of the plum.  ");
        if(bites == 3)
                write("There are two servings left.\n");
        if(bites == 2)
                write("There is one serving left.\n");
        if(bites == 1)
                write(BOLD+"You finish off the plum.\n"+NORM);
  say(TP->QN+" takes a bite of a plum.\n");
  bites -= 1;
  TP->heal_self(50);
  i = (int)TP->query_intoxination()*100 / (TQL+3);
  f = (int)TP->query_stuffed()*100 / (TQL*8);
  s = (int)TP->query_soaked()*100 / (TQL*8);
  t = (int)TP->query_infuse()*100 / ((TQL*9)/2);
  if(TP->checkNM())
          NM = 1;
  write(GRN+"\t HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
          write("SP [???/"+TP->query_msp()+"]  ");
  else
          write("SP ["+TP->query_spell_point()+"/"+TP->query_msp()+"]  ");
  write("I "+i+"%  ");
  write("F "+f+"%  ");
  write("S "+s+"%  ");
  write("T "+t+"%\n"+NORM);
  if(!bites) 
        destruct(TO);
  call_other(TP,"recalc_carry");
  return 1; }
}

