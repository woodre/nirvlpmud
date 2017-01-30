#include "../def.h"

inherit "/players/illarion/room";

status drapes_closed;
int candles_lit;

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Western Tower");
  set_long("\
The cathedral's western tower is a cozy, well-appointed room.  The arched windows have thick, \
perfectly clear windows, hung with blue drapes, matching the thick round rug on the floor. \
There is a small but well-stocked mini-bar in the northwest corner, and several comfortable \
chairs placed strategically around the windows.  In the center of the room is a table, covered \
in candles.\
");

  set_light(1);

  add_item("windows","They're very nice.  If you want to enjoy the view, try the other tower.");
  add_item("drapes","Rich blue velvet.  They are currently $&show_drape_state$&");
  add_item("rug","Soft and rich, and shot through with silver highlights.");
  add_item("mini-bar","It's amazingly well-stocked.  Whatever drink you think of, the ingredients seem to appear as soon as you turn your head.  You could make yourself a drink.");
  add_item("chairs","Large, overstuffed chairs, bordering on loveseats: they're too large for one person, but likely to be somwhat cozy for two.");
  add_item("table","Barely visible under all the candles.");
  add_item("candles","An amazing variety of shapes, colors, and scents.  $&candle_string$&");

  add_exit("down",ROOM+"nave_aisle_west");
  
  set_etime_const(600);
  set_etime_rand(120);
    
}

void init() {
  ::init();
  add_action("cmd_open","open");
  add_action("cmd_close","close");
  add_action("cmd_light","light");
  add_action("cmd_blow","blow");
  add_action("cmd_make","make");
}

string show_drape_state() {
  return drapes_closed==0?"open.  You could close them.":"closed.  You could open them.";
}

string candle_string() {
  switch(candles_lit) {
    case 0: return "None of the candles are lit.  You could light one.";
    case 1: return "A single candle is lit.  You could light another, or blow out the candle";
    case 2..9: return "There are "+candles_lit+" candles lit.  You could light another, or try to blow them out.";
    case 33: return "Every single candle appears to be lit.  You could blow some of them out.";
    default: return "Many of the candles have been lit.  You could light another, or try to blow them out.";
  }
}

status cmd_make(string str) {
  string article;
  object drink;
  if(!str) {
    notify_fail("What kind of drink do you want to make?\n");
    return 0;
  }
  if((int)this_player()->query_money() < 10) {
    write("You need 10 coins to make a drink.\n");
    return 1;
  }
  if(member_array(str[0..0],({"a","e","i","o","u"})) != -1)
    article = "an";
  else
    article = "a";
  write("You make "+article+" "+str+".\n");
  say(this_player()->query_name()+" makes "+article+" "+str+".\n");
  drink=clone_object("obj/drink");
  this_player()->add_money(-10);
  drink->set_value(str+"#"+capitalize(article)+" "+str+"#You drink the drink#0#0#1");
  transfer(drink,this_player());
  return 1;
}

status cmd_light(string str) {
  if(str != "candle") {
    notify_fail("Light what?\n");
    return 0;
  }
  if(candles_lit >= 33) {
    write("You can't find an unlit candle to light.\n");
    return 1;
  }
  if(candles_lit==0) add_room_emote("A candle flame flickers.\n");
  candles_lit++;
  write("You light one of the candles.\n");
  say(this_player()->query_name()+" lights a candle.\n");
  return 1;
}

status cmd_blow(string str) {
  int blown_out;
  string blown_out_str;
  if(str != "out candle" && str !="out candles") {
    notify_fail("Blow out what?\n");
    return 0;
  }
  if(candles_lit <= 0) {
    write("None of the candles are lit.\n");
    return 1;
  }
  blown_out=random(4)+random(3)+random(2);
  if(blown_out > candles_lit) 
    blown_out=candles_lit;
  if(blown_out==0) {
    write("You fail to blow out any candles.\n");
    say(this_player()->query_name()+" tries to blow out a candle, but fails.\n");
  } else if(blown_out==1) {
    write("You blow out a single candle.\n");
    say(this_player()->query_name()+" blows out a single candle.\n");
  } else if(blown_out==2) {
    write("You blow out two candles.\n");
    say(this_player()->query_name()+" blows out two candles.\n");
  } else {
    write("You blow out several candles.\n");
    say(this_player()->query_name()+" blows out several candles.\n");
  }
  candles_lit -= blown_out;
  if(candles_lit <=0) {
    candles_lit=0;
    tell_room(this_object(),"All of the candles have been blown out.\n");
    remove_room_emote("A candle flame flickers.\n");
  }
  return 1;
}

status cmd_open(string str) {
  if(str != "drapes") {
    notify_fail("Open what?\n");
    return 0;
  }
  if(drapes_closed == 0) {
    write("They are already open.\n");
    return 1;
  }
  drapes_closed=0;
  write("You open the drapes.\n");
  say(this_player()->query_name()+" opens the drapes.\n");
  set_light(1);
  return 1;
}

status cmd_close(string str) {
  if(str != "drapes") {
    notify_fail("Close what?\n");
    return 0;
  }
  if(drapes_closed == 1) {
    write("They are already closed.\n");
    return 1;
  }
  drapes_closed=1;
  write("You close the drapes.\n");
  say(this_player()->query_name()+" closes the drapes.\n");
  set_light(-1);
  return 1;
}

