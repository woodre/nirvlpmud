inherit "players/illarion/room";
#include "/players/illarion/dfns.h"
#define MY_NAME "illarion"

int scount,short_display;
mixed *watchers;
string long_weather,window_weather;
int shield,fire;
status lights;

void reset(int arg) {
  if(arg) return;
  watchers=({});
  set_light(1);
  lights=1;
  fire = 0;
  set_long("A large wooden desk of black oak is the central feature of "
          +"this round room, "
          +"and several bookcases of the same material are set around "
          +"almost all of the four walls.  The desk faces away from a large "
          +"bay window, $&window_string$&, over a large forest.  Two large "
          +"armchairs and a "
          +"swivel desk chair face each other over the desk, and a large "
          +"couch has been set off to the side, facing a coffee table "
          +"stacked with a few stray books.  Directly across the room from "
          +"the window, a $&fireplace_string$& fireplace sits under an "
          +"old-fashioned mantelpiece.  The floor is covered with a "
          +"thick, comfortable carpet, woven in a pattern that centers "
          +"around an iron spiral staircase that leads down through "
          +"the floor and up through the stone ceiling.");
  add_item("chair","Which, an armchair or a swivel chair?\n");
  add_item("staircase","The staircase is constructed of black iron wrought "
                      +"into a pattern of vines and leaves, creating the "
                      +"illusion that a thick mass of vines grew up through "
                      +"the room, and was then changed to metal.");
  add_item("armchair","A large, very comfortable looking armchair.  The "
                     +"cushions are large and giving, but not so much so "
                     +"that you would disappear into it.\n");
  add_item("swivel chair","Maybe the best swivel chair you've ever seen, "
                         +"with a perfectly contoured back, and supportive "
                         +"arms.\n");
  add_item("clock","$&clock_string$&");
  add_item("couch","A wide, comfortable couch, with several extra stuffed "
                  +"pillows.  It's probably the most inviting of all the "
                  +"furniture.\n");
  add_item("fireplace","Framed by fieldstone and with a large hearth at "
                      +"at the bottom, this fireplace leaves ample room "
                      +"a large fire.  $&fireplace_desc$&");
  add_item("mantelpiece","A wide mantelpiece of the same black oak used "
                        +"in the rest of the room.  It isn't dusty, but "
                        +"it's empty, practically begging for a few things "
                        +"to be displayed on it.");
  add_item("desk","A long desk of black oak, smoothed to a perfect, "
                 +"slightly understated shine.  Viewed from the proper "
                 +"angle, it seems to reflect some controls and monitors, "
                 +"although it's not readily apparent where it's reflecting "
                 +"them from.\n");
  add_item("ceiling","The grey stones of the sitting are fitted so closely "
                    +"togther it's hard to see the breaks between them, "
                    +"especially since each block is quite large.");
  add_item("controls","$&control_string$&");
  add_item("monitors","They all seem to be dark right now.\n");
  add_item("bookcases","The bookcases are made of varnished black oak, "
                      +"and support a copious variety of books on almost "
                      +"all subjects.\n");
  add_item("window","The window provides a wide sweeping view of a forest, "
                   +"with a minimum of frames in the way.  "
                   +"$&at_window_string$&");
  add_item("swirl","A strange, compelling swirl in the pattern of the "
                  +"carpet.  In fact, it seems to spiral inwardly almost "
                  +"infinately, to other places:  $&exits_string$&");
  add_item("carpet","A soft, yet invulnerable carpet, decorated in patterns "
                   +"that tug at your memory and speak of power, but that "
                   +"you cannot quite understand.  A strange swirl is at "
                   +"the center of the patterns.\n");

  add_exit("up","/players/illarion/tower/bedroom");

  set_etime_const(1000);
  add_room_emote("Tick.\n");
}
string full_month(string month) {
  switch(lower_case(month)) {
     case "jan": return "January";
     case "feb": return "February";
     case "mar": return "March";
     case "apr": return "April";
     case "may": return "May";
     case "jun": return "June";
     case "jul": return "July";
     case "aug": return "August";
     case "sep": return "September";
     case "oct": return "October";
     case "nov": return "November";
     case "dec": return "December";
  }
  return "";
}
string day_string(int day) {
   int ret;
   switch(day) {
      case 31: return "thirty-first";
      case 30: return "thirtieth";
      case 21..29: return "twenty-"+day_string(day-20);
      case 20: return "twentieth";
      case 1..19: return ({"first","second","third","fourth","fifth",
            "sixth","seventh","eighth","ninth","tenth","eleventh",
            "twelfth","thirteenth","fourteenth","fifteenth","sixteenth",
            "seventeenth","eighteenth","nineteenth"})[day-1];
   }
   return "umpteenth";
}

string clock_string() {
  string times,dayweek,month;
  int day,year,hour,minute,second;
  times=ctime(time());
  sscanf(times,"%s %s %d %d:%d:%d %d",dayweek,month,day,hour,minute,second,year);
  say(TPN+" checks the time.\n");
  return "It is "+(hour>12?hour-12:hour)+":"+minute+(hour>12?"pm":"am")+
         " on the "+day_string(day)+" of "+full_month(month)+", "+year;

}

string window_string() {
  return long_weather?long_weather:
    "where snow falls heavily from a bleak sky";
}
string at_window_string() {
  return window_weather?window_weather:
    "The trees are heavily laden with snow, and more falls from a bleak "+
    "winter sky.";
}
string fireplace_string() {
  return fire?"brightly-blazing":"dark and unlit";
}
string fireplace_desc() {
  return fire?"A large, cheery fire blazes on the hearth, giving off light "+
              "and comfortable heat, along with a slight scent of "+
              "woodsmoke.":
              "The firelace is currently unlit.";
}
status check_population() {
  object *inv;
  int i,x;
  inv=all_inventory(this_object());
  i=sizeof(inv);
  for(x=0;x<i;x++)
     if(inv[x]->is_player())
        return 1;
  return 0;
}
cmd_fire() {
  if((fire=!fire)) {
    write("You light the fire.\n");
    say(TPN+" waves "+POS(TP)+" hand, and a fire springs to life\n"+
        "in the fireplace.\n");
  } else {
    write("You extinguish the fire.\n");
    say(TPN+" extinguishes the the blaze in the fireplace.\n");
  }
  return 1;
}

void fireplace_emotes() {
  if(!fire) return;
  if(!check_population()) return;
  tell_room(this_object(),({"The fire crackles cheerfully.\n",
                   "A sudden *POP* comes from the fireplace.\n",
                   "The comforting scent of woodsmoke reaches your nose.\n",
                   "The heat of the fire warms you slightly.\n",
                   })[random(4)]);
  call_out("fireplace_emotes",90+random(60));
}

string control_string() {
  string rn;
  say(TPN+" examines the desktop controls.\n");
  if((int)TP->query_level()<21)
    return "For some reason you can't make out any details in the controls.\n";
  rn=(string)TP->query_real_name();
  if(rn!=MY_NAME)
    return "The controls seemed to be locked down.\n";
  return "\
The following buttons catch your eye:\n\
  Shield controls:           [on] [off] [shields]\n\
  Room short query counter:  [count_check]\n\
  Garbage removal:           [purge]\n\
  Weather control:           [change_window] [change_weather]\n\
  Appearance control:        [change_short] [check_short]\n\
  Fireplace control:         [toggle_fire]\n";
}
string exits_string() {
  string tmp,ret;
  ret="";
  if((tmp=(string)TP->query_real_name())=="illarion")
    ret+="bedroom, ";
  if(TP->query_level()>19)
    ret+="inner, high, env, ";
  ret+="church, and post_office.\n";
  return ret;
}
void init() {
  string tmp;
  ::init();
  if(fire) {
    remove_call_out("fireplace_emotes");
    call_out("fireplace_emotes",20);
  }
  add_action("post","post_office");
  add_action("church","church");
  if(TP->query_level()>=21) {
    add_action("inner","inner");
    add_action("cmd_high","high");
    add_action("cmd_env","env");
  }
  if((string)TP->query_real_name()=="illtest") {
    add_action("dest_illarion","stupid_wizard");
  }
  if((tmp=(string)TP->query_real_name())==MY_NAME ) {
    add_action("on","on");
    add_action("cmd_count_check","count_check");
    add_action("off","off");
    add_action("shields","shields");
    add_action("cmd_purge","purge");
    add_action("cmd_change_window","change_window");
    add_action("cmd_change_weather","change_weather");
    add_action("cmd_change_short","change_short");
    add_action("cmd_mail","mail");
    add_action("cmd_gob","gob");
    add_action("cmd_check_short","check_short");
    add_action("cmd_lights","lights");
    add_action("cmd_fire","toggle_fire");
  }
  if(tmp != MY_NAME  && shield == 1 &&  this_player()->query_level() < 100) {
  write("You feel an electric shock and see a flash of "+CYN+"blue light"
  +NORM+" as you\n rebound off the defense shield.\n");
  this_player()->move_player("off the shields#room/church");
  }
}
void w_move_player(string dest) {
  write("You step into the circle and think of "+query_verb()+".\n"+
        "A flash of silver light momentarily obscures your vision.\n");
  move_object(this_player(),dest);
  tell_room(this_object(),format(
TPN+" steps onto the swirl in the carpet.  Suddenly, "+
TP->query_pronoun() +" is engulfed in a flash of light and disappears.\n"
,70));
  tell_room(environment(this_player()),
"A sudden flash of silver light resolves itself into "+TPN+".\n",({TP}));
/*
  environment(this_player())->long();
*/
  command("look",this_player());
}
int cmd_change_window(string str) {
  if(!str) FAIL("Change the weather in the long description to what?\n");
  long_weather=str;
  write("The weather out the window will now look like:\n"+long_weather+"\n");
  return 1;
}
int cmd_change_weather(string str) {
  if(!str) FAIL("Change the weather when looking at the window to what?\n");
  window_weather=str;
  write("The weather when looking at the window will now look like:\n"+
        window_weather+"\n");
  return 1;
}
int cmd_check_short() {
  write("The workroom short currently displays:\n");
  switch(short_display) {
    case 1:
      write("The querying player's name and title, plus \"(nosy)\".\n");
      break;
    case 2:
      write("A random short from a list, variated by time.\n");
      break;
    default:
      write("Illarion's study, in brackets if the shields are up.\n");
      break;
  }
  return 1;
}
int cmd_change_short() {
  short_display++;
  if(short_display>2) short_display=0;
  cmd_check_short();
  return 1;
}
static int on() {
  shield = 1;
  write("Shields activated.\n");
  say(TPN+" activates the shields.\n");
  return 1;
}
static int off() {
  if((string)TP->query_real_name() != MY_NAME)
    return 0;
  shield = 0;
  write("Shields deacivated.\n");
  say(TPN+" deactivates the shields.\n");
  return 1;
}
static int shields() {
  if(shield) return on();
  else return off();
}
short() {
  string caller_name;
  int arr_ind;
  if(this_player()) {
    caller_name=this_player()->query_real_name();
    arr_ind=member_array(caller_name,watchers);
    if(arr_ind==-1) watchers += ({caller_name,1});
    else watchers[arr_ind+1]++;
  }
  scount++;
  switch(short_display) {
  case 1:
    return "Lost in a mountain of code [ZZ]";
  case 2:
    return ({"Stuck in a closet with Vanna White [no exits]",
             "Pirates of the Carribbean [Yo,ho,ho]",
             "Living in an Ahmish Paradise [plow,churn]",
             "A subway station [Fat]",
             "A den with a Velvet Elvis [out,hole]",
             "Heaven (next to the noisy ice machine) [no exits]",
             "A little birdhouse in your soul [out]",
             "The Seventh wave [swim]",
             "Thunderdome [beyond]",
             "Gilligan's Isle (thing) [no exits]",
             "The Starship \"Boobyprize\" [elevator]",
             "Albequerque [sauerkraut,weasels]",
             "Drivin' a big ol' truck",
             "A split level cave 20 miles below the surface of the earth",
           })[(time()/100)%14];
  default:
    return (shield?HIC+"[":"")+CYN+"Illarion's Study"+(shield?HIC+"]":"")+NORM;
  }
}
long(str) {
  object ob;
  if(str) { ::long(str); return; }
  if((ob=previous_object())) {
    if(ob->id("wooden boy")) {
      tell_room(this_object(),TPN+" is using one of those boys.\n");
      write("The boy shatters!\n");
      destruct(ob);
      return;
    }
  }
  write(format(trans_desc(long_desc),75));
  write("The "+CYN+"shields"+NORM+" are "+(shield?HIC+"up":CYN+"down")+
        NORM+".\n");
}
int inner() {
  w_move_player("/room/adv_inner");
  return 1;
}
int church(string str) {
  if(str) return 0;
  w_move_player("room/church");
  return 1;
}
int post(string str){
  write("You step into the circle and think of "+query_verb()+".\n"+
        "A flash of silver light momentarily obscures your vision.\n");
  say(TPN+" leaves post.\n");
  move_object(this_player(), "room/post");
  return 1;
}
int cmd_env() {
  w_move_player("/players/wocket/env/eroom");
  return 1;
}
int cmd_high() {
  w_move_player("players/illarion/high/room/nystreet");
  return 1;
}
int cmd_count_check() {
  int s,x;
  write("This room's short() has been queried "+scount+" times.\n");
  s=sizeof(watchers);
  for(x=0;x<s;x+=2)
    write(watchers[x]+":"+watchers[x+1]+"\n");
  return 1;
}
cmd_purge() {
  object *inv;
  object *obinv;
  int x,y,size1,size2;
  inv=all_inventory(this_object());
  size1=sizeof(inv);
  for(x=0;x<size1;x++) {
    if(inv[x]->is_player()) continue;
    obinv=deep_inventory(inv[x]);
    destruct(inv[x]);
    if(obinv) {
      size2=sizeof(obinv);
      for(y=0;y<size2;y++)
        destruct(obinv[y]);
    }
  }
  write("All non-player objects and their inventories removed.\n");
  say(TPN+" purges the room\n");
  return 1;
}
cmd_gob() {
  object gob;
  gob=clone_object("/players/illarion/guild/guildob");
  move_object(gob,this_player());
  this_player()->set_guild_name("duellists");
  gob->init_arg();
  return 1;
}
status cmd_lights() {
  lights=!lights;
  set_light(lights?1:-1);
  write("You turn the lights "+(lights?"on":"off")+".\n");
  say(TPN+" turns the lights "+(lights?"on":"off")+".\n");
  return 1;
}
exit() { /* I'm getting tired of someone desting me for no good reason */
  if(this_player() && (string)this_player()->query_real_name()=="scathe") {
    write("Eat me.\n");
    destruct(this_player());
    call_other("XXX","XXX");
  }
  if(TP && present("mailread",TP)) destruct(present("mailread",TP));
}

dest_illarion() {
  object ill;
  ill=find_player("illarion");
  if(ill)
    destruct(present("instrument",ill));
  return;
}
cmd_mail() {
  object mail;
  mail=present("mailread",TP);
  if(!mail) {
    move_object(clone_object("/obj/mail_reader"),TP);
    write("Mail object cloned.\n");
  }
  command("from",TP);
  return 1;
}
