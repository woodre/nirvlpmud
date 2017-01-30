#include "/players/wocket/closed/ansi.h"
inherit "obj/armor.c";
int shhcheck;
int rank,guildstat;

reset(arg){
    set_id("ifonlybardscouldntmakeobjects");
    set_alias("halo");
    set_short(HIY+"A halo"+NORM);
    set_long("blah.\n");
    set_ac(1);
    set_type("misc");
    set_weight(0);
    shhcheck = 0;
    rank = 1;
    guildstat = 1;
}

drop(){ return 1; }
get(){ return 0; }

query_rank(){ return rank; }
query_gstat(){ return guildstat; }
query_silence(){ return shhcheck; }

set_rank(newrank){ rank = newrank; }
set_gstat(newgstat){ guildstat = newgstat;}

init(){
::init();
restoreme();
    add_action("asay","say");
#ifndef __LDMUD__
  add_action("asay"); add_xverb("'");
#else
  add_action("asay", "'", 3);
#endif
    add_action("asay","'");
    add_action("angel","angel");
    add_action("angel","agl");
    add_action("angelemote","age");
    add_action("newhalo","mend");
    add_action("angels","angels");
    add_action("silence","silence");
    add_action("saveme","saveme");
    add_action("restoreme","restoreme");
    add_action("angelscore","sc");
    add_action("no_do","pretitle");
if(rank > 1){
    add_action("hymn","hymn");
    add_action("polish","polish");
    add_action("tarnish","tarnish");
    add_action("goodness","goodness");
}
if(rank > 2){
}
if(rank > 3){
this_player()->set_pretitle("|");
this_player()->set_title("the Angel");
    add_action("immitate","immitate");
    add_action("inflame","inflame");
}
if(rank > 4){
}
if(rank > 5){
}
if(rank > 6){
}
if(rank > 7){
this_player()->set_pretitle(HIC+"The Archangel");
this_player()->set_title(NORM);
    add_action("sponsor","newangel");
}
if(rank > 8){
}
if(this_player()->query_real_name() == "wocket" || rank > 9){
    add_action("setrank","setrank");
    add_action("setgstat","setgstat");
}
}

no_do(){
  write("You many not do that.\n");
  return 1;
}
int newhalo(string str){
if(str != "halo"){notify_fail("What would you like to mend?\n");
return 0;
}
move_object(clone_object("/players/wocket/angels/halo.c"),this_player());
write("Your halo glows brightly as it has been restored.\n");
destruct(this_object());
return 1;
}

int angel(string str){
"/players/wocket/angels/cmds/channel.c"->channelsay(str);
return 1;
}

int angelemote(string str){
"/players/wocket/angels/cmds/channel.c"->channelemote(str);
return 1;
}

int silence(){
if(shhcheck == 1){
  write("You begin to listen to the angels chatter.\n");
  shhcheck = 0;
  return 1;
}
if(shhcheck != 1){
  write("You silence the angels chatter.\n");
  shhcheck = 1;
  return 1;
}
}

int angels(){
"/players/wocket/angels/cmds/guildwho.c"->guildwho();
return 1;
}


int polish(){
write("You begin to polish you halo and it shines like the sun.\n");
say(this_player()->query_name()+" begins to polish there halo making it shine like the sun.\n");
set_light(2);
this_player()->add_spell_point(-10);
call_out("polishstop",1000+random(50));
return 1;
}

polishstop(){
write("You halo begins to tarnish.\n");
say(this_players()->query_name()+"'s halo begins to tarnish.\n");
set_light(-2);
}

int tarnish(){
write("You tarnish your halo.\n");
say(this_player()->query_name()+" tarnishes their halo.\n");
set_light(-2);
return 1;
}

int asay(string str){
"/players/wocket/angels/cmds/communicate.c"->asay(str);
return 1;
}

int immitate(string str){
"/players/wocket/angels/cmds/communicate.c"->immitate(str);
return 1;
}

int hymn(string str){
"/players/wocket/angels/cmds/communicate.c"->hymn(str);
return 1;
}

goodness(){
"/players/wocket/angels/cmds/goodness.c"->goodness();
return 1;
}
sponsor(string str){
"/players/wocket/angels/cmds/sponsor.c"->sponsor(str);
return 1;
}
int inflame(string str){
"/players/wocket/angels/cmds/inflame.c"->inflame(str);
return 1;
}

int saveme(){
save_object("players/wocket/angels/members/"+this_player()->query_real_name());
write("Saving Guild Info...\n");
return 1;
}

int restoreme(){
if(!restore_object("players/wocket/angels/members/"+this_player()->query_real_name())){
write("You have no guild info to restore...\n");
saveme();
return 1;
}
restore_object("players/wocket/angels/members/"+this_player()->query_real_name());
write("Restoring Guild Info...\n");
return 1;
}

int angelscore(){
"/players/wocket/angels/cmds/angelscore.c"->angelscore();
return 1;
}
int setrank(string str){
"/players/wocket/angels/cmds/setrank.c"->setrank(str);
return 1;
}

int setgstat(string str){
"/players/wocket/angels/cmds/setgstat.c"->setgstat(str);
return 1;
}

