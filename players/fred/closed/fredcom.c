#include <ansi.h>
#define TPRN this_player()->query_real_name()
#define TP this_player()
#define ENN environment()->query_name()
#define nytewhisp find_player("nytewhisp")
#define fred find_player("fred")

id(str) { return str == "pimp_com" || str == "pink" || str == "pink ring"; }

init()
{
    if(TP->query_level() > 19 && TPRN != "fred")
      destruct(this_object());
    add_action("preach_on","ho");
    add_action("snort","press_1");
    add_action("cough","press_2");
    add_action("leave_em","i-aint-freds-ho");
}

int drop() { return 1; }
int get() { return 1; }

com_all();

preach_on(string str)
{
 string name;
 if(!str){ write("ho <msg>\n"); return 1; }
  name = (string)TPRN;
 if(str[0] == ':') com_all(BOLD+HIY+"(HO)"+NORM+" "+capitalize(name)+" "+NORM+str[1..(strlen(str) - 1)] + NORM + "\n");
  else com_all(BOLD+HIY+"(HO)"+NORM+" "+capitalize(name)+" bitches: " + NORM + str + NORM +"\n");
  return 1;
}

snort(){
  write("Your options as a Ho are obviously few but do include:\n\n"+
BOLD+GRN+"        Ho chatter...                 ho\n"+                                  
         "        Ho emotes...                  ho :\n"+
         "        Ho leave...                   i-aint-freds-ho\n"+NORM+"\n");
  return 1; 
} 

com_all(string str)
{
   if(nytewhisp) tell_object(nytewhisp,str);
   if(fred) tell_object(fred,str);
   return 1;
}
long()
{
   write("With this small but expensive pink ring you have become\n"+
         "one of Fred's Ho's. To check out your duties as a new Ho\n"+
         "you can "+BOLD+HIY+"press_1"+NORM+". To see if Fred is on at the moment "+BOLD+HIY+"press_2"+NORM+".\n");
}

/*query_auto_load() { return "/players/fred/closed/fredcom.c:"; }*/

extra_look() { return ""+ENN+" sports a stylish '"+RED+"I'm Fred's Ho"+NORM+"' tattoo"; }

leave_em(){
  write("\nYou toss the pink ring into the trash to find a new pimp.\n");       
  destruct(this_object());
  return 1; }

cough(){
  object who;
  who = find_player("fred");
  if(!who){ write("Fred is not on at the moment, I'm sorry.\n"); return 1; }	
  if(who){
    write("\n        Fred is currently online. Responses may be delayed\n"+
          "                 because well Fred is kinda lazy.\n");          
    return 1; }
  }
    
short(){
  return "A small pink ring "+BOLD+YEL+"("+NORM+"worn"+BOLD+YEL+")"+NORM+""; }


                
