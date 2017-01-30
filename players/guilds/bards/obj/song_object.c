#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"
#define SONG_DIR "/players/guilds/bards/songs/"
inherit "obj/clean";

object player;
string *lines;
string song;
int pause_time;
int pause_place;

id(str) { return str == "bard_song_object"; }

drop() { return 1; }

init() {
  add_action("cmd_stop","stop");
  add_action("cmd_continue","continue");
}

good_bye() {
  if(player) {
    tell_object(player,"You stop singing.\n");
    if(environment(player))
      tell_room(environment(player),NAME(player)+" stops singing.\n",({player}));
  }
  remove_call_out("do_song");
  destruct(this_object());
}

cmd_stop(str) {
  if(str!="singing")
    return 0;
  good_bye();
  return 1;
}

cmd_continue(str) {
  if(str!="singing")
    return 0;
  if(!pause_time)
    return 0;
  if(time() < pause_time)
    FAIL("Wait a little longer.  Timing is everything.\n");
  pause_time=0;
  call_out("do_song",0,pause_place+1);
  pause_place=0;
  return 1;
}

start_singing(what) {
  string temp_song;
  if(!environment())
    return;
  player=environment();
  song=what;
  temp_song = read_file(SONG_DIR+what+".song");
  lines = explode(temp_song,"\n");
  call_out("do_song",0,0);
}

pause_singing(place) {
  if(!player)
    return good_bye();
  tell_object(player,"You come to the end of a verse.\n"+
                     "You can \"continue singing\" in a few seconds.\n");
  pause_time=time()+5;
  pause_place=place;
}

do_song(index) {
  string line,temp;
  if(song=="heynonny" && index==22) {
    object jon;
    jon=present("johnathin",environment(player));
    if(jon) jon->finish_heynonny(player);
  }
  if(!player || !environment(player) || index >= sizeof(lines))
    return good_bye();
  if(lines[index] == "")
    return pause_singing(index);
  line=lines[index];
  if( index == 0 && sscanf(line,"<title>%s",temp) ) {
    tell_object(player,ansi_format(
                HIM+"You clear your throat, and announce, \""
               +NORM+"This is "+temp+HIM+"\""+NORM));
    tell_room(environment(player),ansi_format(
              HIM+NAME(player) + " clears " + POSS(player) 
              + " throat, and announces, \""+NORM
              +"This is "+temp+HIM+"\""+NORM),
             ({player}));
  } else {
    line=HIM+"\""+NORM+line+HIM+"\""+NORM;
    tell_object(player,
                ansi_format(HIM+"You sing, "+line,75));
    tell_room(environment(player),
              ansi_format(HIM+NAME(player)+ " sings, "+line,75),
              ({player}));
  }
  call_out("do_song",2,index+1);
}
