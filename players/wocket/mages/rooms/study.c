#include "../defs.h"
#define PATH ROOMDIR
inherit ROOM;

string owner;
string *a_pages;
id(str){ return owner+"magestudy"; }

set_owner(str){
  owner = str;
  if(!restore_object("players/wocket/mages/members/"+owner+"study"))
      save_object("players/wocket/mages/members/"+owner+"study");
}

short(){
 if(owner) return MAG+capitalize(owner)+"'s Private Study"+NORM;
           return short_desc;
}

reset(arg){
  if(arg) return;
  short_desc = MAG+"A Mage's Study"+NORM;
  long_desc = "   "+
     "Soft candle light flickers shadows throughout the room.  The walls\n"+
     "are lined with bookshelves.  A small writting desk sits in the far corner\n"+
     "The incence burns as flower scented smoke entangles its way up to the\n"+
     "ceiling.  This is your study of which you 'store' and 'retrieve' your most\n"+
     "precious spells.  A 'list' of your archives is posted above the desk.\n";
  set_light(1);
  items = ({
    "candles","Many of the white wax candles have melted down to near nothingness",
    "walls","Bookshelves line every wall",
    "bookshelves","They are made of a dark oak and hold many ancient books",
    "desk","A small writting desk made of a dark oak.  Papers and an ink well fill\nits counter",
    "smoke","It entwines against itself as it floats to ceiling",
    "ceiling","A wood panneled ceiling only adding to the feeling of comfort",
  });
  listens = ({
    "You hear soft chanting from down the hallway",
  });
  smells = ({
    "default","You smell dust and age",
  });
  dest_dir = ({
    PATH+"hallway.c","out"
  });
  a_pages = ({}); 
}

init(){
  ::init();
  add_action("store","store");
  add_action("retrieve","retrieve");
  add_action("list_pages","list_pages");
  add_action("list_pages","list");
  this_player()->set_fight_area();
}

retrieve(str){
  string found;
  int i;
  if(!str){
    notify_fail("What would you like to retrieve?\n");
    return 0;
  }
  i = 0;
  while(!found && i < sizeof(a_pages)){
    if(a_pages[i] == str) found = str;
    i++;
  }
  if(found){
    remove_page(str);
    move_object(clone_object(SPELLDIR+found+".c"),this_player());
    write("You retrive your "+str+" spell from your files.\n");
    return 1;
  }
  notify_fail("You may only retrieve spells that are in your files.\n");
  return 0;
}
 
store(str){
  object page;
  if(!str){
    notify_fail("What would you like to store?\n");
    return 0;
  }
  page = present(str,this_player());
  if(page && page->query_w_spell()){
    write("You store your "+str+" spell away in your files.\n");
    destruct(page);
    add_page(str);
    return 1;
  }
  notify_fail("You may only store magic spells that you have.\n");
  return 0;
}

list_pages(){
  int i,a;
  write("Your files contain the following spells:\n");
  for(i=0,a=sizeof(a_pages);i<a;i++){
    write("\tA "+a_pages[i]+" spell\n");
  }
  return 1;
}

add_page(str){
  a_pages += ({ str });
  save_object("players/wocket/mages/members/"+owner+"study");
}

remove_page(str){
  int i;
  int a;
  string *pagestemp;
  for(i=0,a=sizeof(a_pages);i<a;i++){
    if(a_pages[i] != str){
      if(!pagestemp)
        pagestemp = ({ a_pages[i] });
      else
        pagestemp += ({ a_pages[i] });
    }
  }
  if(!pagestemp) a_pages = ({});
  else a_pages = pagestemp;
  save_object("players/wocket/mages/members/"+owner+"study");
}