#include "/players/wocket/closed/ansi.h"

string oldpretitle;
string oldtitle;

object tagger;
id(str){ return str == "tagobject" || str == "mark" || str == "tag";}

drop(){ quit(); return 1;}

short(){
    return HIG+"\t*- A tag mark -*"+NORM;
}
long(){
  write(HIG+"How to play:\n"+
"\ntag <player>                  to continue the game\n"+
"drop tag                        to end the game\n"+
"\nTis a simple game of tag.\n"+NORM);
}
init(){
  this_player()->chan_msg(HIG+"\t*- "+this_player()->query_name()+" is now IT -*\n"+NORM,"junk");
  new_title();
  add_action("tag","tag");
}

quit(){
restore_title();
this_player()->chan_msg(HIG+"\t*- The game has ended -*\n"+NORM,"junk");
restore_title();
destruct(this_object());
return 0;
}

tag(str){
if(!str){
  notify_fail(HIG+"Who would you like to tag?\n"+NORM);
  return 0;
}
if(!find_player(str)){
  notify_fail(HIG+"That player does not exist.\n"+NORM);
  return 0;
}
if(environment(find_player(str)) != environment(this_player())){
  notify_fail(HIG+"That person is not here.\n"+NORM);
  return 0;
}
if(find_player(str)->query_invis() > 20){
  notify_fail(HIG+"That person is not here.\n"+NORM);
  return 0;
}
if(!find_player(str)->query_interactive()){
  notify_fail(HIG+"The person must be active.\n"+OFF);
  return 0;
}
if(find_player(str) == tagger){
  notify_fail(HIG+"NO TAGBACKS :)\n"+NORM);
  return 0;
}
write(HIG+"You tag "+capitalize(str)+".\n"+NORM);
say(HIG+this_player()->query_name()+" tags "+capitalize(str)+".\n"+NORM,find_player(str));
tell_object(find_player(str),HIG+this_player()->query_name()+" tags you.\nYOU'RE IT!!\n"+NORM);
restore_title();
tagger = this_player();
move_object(this_object(),find_player(str));
return 1;
}

new_title(){
if(!this_player()->query_pretitle()){
oldpretitle = "|";
}
else
oldpretitle = this_player()->query_pretitle();
oldtitle = this_player()->query_title();
this_player()->set_pretitle(HIG+"");
this_player()->set_title(HIG+"is IT"+NORM);
return 1;
}

restore_title(){
this_player()->set_pretitle(oldpretitle);
this_player()->set_title(oldtitle);
return 1;
}

get() { return 1; }
