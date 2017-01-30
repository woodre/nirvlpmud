 /* ghelp.c
  * Lists and displays help for specific commands and for
  * other help files
  */

#include "/players/illarion/guild/def.h"

help() {
  return "Usage: ghelp [topic]\n"+
         "Cost:  none\n\n"+
         "When used without a topic, a list of possible topics\n"+
         "is displayed.  When used with a topic, information\n"+
         "about that topic is displayed.\n"+
         "Not all information is available here; some things\n"+
         "you must discover on your own.\n";
}

void display_nice_list(string *list,int col_size,int cols,string lead) {
  int x,s;
  s=sizeof(list);
  if(lead) write(lead);
  for(x=0;x<s;x++) {
    write(pad(list[x],col_size));
    if((x+1)%cols==0)
      write("\n"+(lead?lead:""));
  }
  if(x%cols!=0)
    write("\n");
}

string centerdash(string arg, int len) {
  int x,s,a;
  len-=strlen(arg);
  for(x=0;x<len;x++) {
    if(a) arg+="-";
    else arg="-"+arg;
    a=!a;
  }
  return arg;
}

main(string arg,object gob,object owner) {
  string *powers,*docs;
  int x;
  powers=DAEM->query_power_list();
  docs=DAEM->query_doc_list();
  if(!arg) {
    write(CYN+"---------------------[ Guild Commands ]---------------------\n\n"+NORM);
    display_nice_list(powers,14,4,"    ");
    write(CYN+"\n--------------------[ Other Information ]-------------------\n\n"+NORM);
    display_nice_list(docs,19,3,"    ");
    write(CYN+"\n-----------------------------[*]----------------------------\n"+NORM);
    return 1;
  }
  if(member_array(arg,powers)!= -1) {
    write(CYN+centerdash("[ Blademaster Lore: "+arg+" ]",60)+"\n"+NORM);
    write(call_other(POWER_DIR+arg,"help",gob));
    write(CYN+"-----------------------------[*]----------------------------\n"+NORM);
    return 1;
  }
  if(member_array(arg,docs)!= -1) {
    write(CYN+centerdash("[ Blademaster Lore: "+arg+" ]",60)+"\n"+NORM);
    cat(DOC+arg+".txt");
    write(CYN+"-----------------------------[*]----------------------------\n"+NORM);
    return 1;
  }
  FAIL("Topic not found.\n");

}
