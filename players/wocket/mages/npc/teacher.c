#include "/players/wocket/closed/ansi.h"
#include "../def.h"

inherit "/obj/monster.c";
string *spell_name;
string *spell_path;
int *spell_xp;
int *spell_difficulty;

reset(arg){
  ::reset(arg);
  if(arg) return;
  spell_name=({ });
  spell_path=({ });
  spell_xp=({ });
  spell_difficulty=({ });
  set_name("MageTeacher");
}

void init(){
  if(BOOK){
    add_action("ask_mage","ask");
    add_action("study_spell","study");
  }
}

add_spell(string sname,string path,int xp,int diff) {
  spell_name+=({ sname });
  spell_path+=({ path });
  spell_xp+=({ xp });
  spell_difficulty+=({ diff });
}

int ask_mage(string str){
  write(query_name()+" says, \"I can help you '"+BOLD+"study"+NORM+"' the art of sorcery.\n"+
        "             What would you like help with?\"\n\n");
  write("\tSpells:\n");
  this_object()->list_spells();
  say(query_name()+" speaks privately with "+(string)this_player()->query_name()+".\n");
  return 1;
}

list_spells(){
  int i,a;
  int xexp;
  string color;
  int level;
  int elevel;

  level=(int) this_player()->query_level();
  if(level > 19) level=19;

  elevel=(int) this_player()->query_extra_level();
  if(elevel > 21) elevel=21;

   for(i=0,a=sizeof(spell_name);i<a;i++){
/*
    if(BOOK->query_practicepoints() < spell_pp[i])
      color=HIR;
    else
      color=HIG;
*/
    if(elevel < 1)
      xexp =(int) this_player()->query_exp() - (int)"room/adv_guild"->get_next_exp(level-1);
    else
      xexp =(int) this_player()->query_exp() - (int)"room/exlv_guild"->get_next_exp(elevel-1);

    if(xexp < spell_xp[i])
      color=HIR;
    else
      color=HIG;

    write("\t\t"+color+capitalize(spell_name[i])+NORM+"\n");
  }
}

study_spell(str){
  int index;
  int xexp;

  if(!str){
    notify_fail(query_name()+" says, \"What would you like help studing?\"\n");
    return 0;
  }
  index = member_array(str,spell_name);
  if(index == -1) {
    notify_fail(query_name()+" says, \"I'm sorry, but I can not help you with that.\"\n");
    return 0;
  }
/*
  if(BOOK->query_practicepoints() < spell_pp[index]){
    write(query_name()+" says, \"You don't have enough knowledge.  To train you would be \n"+
          "a waste of my time.\"\n");
    return 1;
  }
*/
  if(this_player()->query_level() < 21) { /* This is so it doesn't break on wizzes. */
    if(this_player()->query_extra_level() < 1)
      xexp = this_player()->query_exp() - "room/adv_guild"->get_next_exp(this_player()->query_level()-1);
    else
      xexp = this_player()->query_exp() - "room/exlv_guild"->get_next_exp(this_player()->query_extra_level()-1);
  }
  else
    xexp=spell_xp[index];

  if(xexp < spell_xp[index]){
    write(query_name()+" says, \"You don't have enough knowledge.  To train you would be \n"+
          "a waste of my time.\"\n");
    return 1;
  }

  write(query_name()+" shows and explain the spell to you then leaves you to study\n"+
        "in peace.  You begin to concentrate, seeping your knowledge into\n"+
        "the pen you scribe with.  ");
  say(this_player()->query_name()+" studies quietly.\n");
/*
  BOOK->add_practicepoints(-spell_pp[index]);
*/

  this_player()->add_exp(-spell_xp[index]);

  if(random(100) < spell_difficulty[index] ) {
    this_player()->add_guild_exp(spell_xp[index]);
    write(HIR+"The ink glows red as the spell takes form.\n"+NORM);
    move_object(clone_object(SPELLDIR+spell_path[index]+".c"),this_player());
    return 1;
  }
  else 
   get_fail();
  return 1;
}

get_fail(){
  string msg;
  switch(random(7)){
    case 0:  msg = "The page ignites, destroying all of your work.\n"; break;
    case 1:  msg = "Your page tears, letting the magic seep out.\n"; break;
    case 2:  msg = "You faint, destroying your concentration.\n"; break;
    case 3:  msg = "You sneeze, destroying your concentration.\n"; break;
    case 4:  msg = "The ink fades leaving your page blank.\n"; break;
    case 5:  msg = "Jibberish fills your minDA LAsL iDL Tles.\n"; break;
    case 6:  msg = query_name()+" tears up your paper and shakes his head at you.\n";  break;
    case 7:  msg = "The page fades from this reality leaving you\nbewildered.\n"; break;
  }
  write(msg);
}
