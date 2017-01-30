/* Newbie Wiz Workroom, created by Feldegast, modified <4/27/00> by Jara */

#include "/players/feldegast/closed/ansi.h"

#define OWNER "jara"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
    "  A small room, with wooden floors and stone walls. An oak desk stands\n"+
    "in one corner, a stained glass lamp dimly lighting the scrolls and\n"+
    "charts spread across the desktop. The west wall holds a fireplace, with\n"+ 
    "a fire burning within, and an alcove in the opposite wall opens up to a\n"+
    "window overlooking a lush, green valley. A door leads south, and a\n"+
    "softly humming portal stands opposite the desk. A strange mirror hangs\n"+ 
    "on the wall.\n";
  items=({
    "portal",
"A light blue portal, humming softly with energy. The currents seem to\n"+
"pulsate gently. Type 'tp' for help",
    "mirror",
"An oval mirror with an ornate oak frame. The glass is hazy and difficult\n"+
"to see a reflection",
    "lamp",
"The stained glass lamp has been delicately crafted of a fine, burgandy\n"+
"glass and a silver metal. A small chain hangs from the base of the bulb",
    "charts",
"Yellowed with age, the scrolls and charts appear brittle and delicate",
    "scrolls", 
"Yellowed with age, the scrolls and charts appear brittle and delicate",
  });
  dest_dir=({
  });
}

cmd_smell(str) {
  write("The scent of wood burning within the fireplace.\n");
  return 1;
}

cmd_listen(str) {
  write("The sounds of birds singing can be heard in the distance.\n");
  return 1;
}

init() {
  ::init();
  if(this_player()->query_real_name() != OWNER && shield == 1) {
    write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off of the shield.\n");
    this_player()->move_player("off the shields#players/feldegast/closed/tower/outside");
  }

  add_action("teleport","teleport");
  add_action("teleport","tp");
  
  if(this_player()->query_real_name()==OWNER) {
    add_action("shields","shields");
    add_action("cloak","cloak");
    add_action("locks","locks");
    add_action("scry","scry");
    add_action("gaze","gaze"); 
    add_action("escort","escort");
  }
}

short() {
  string str;
  if(cloak) {
    switch(random(4)) {
      case 0: str="Village church"; break;
      case 1: str="Village green [n,w,e]"; break;
      case 2: str="Village road [w,n,s,e]"; break;
      case 3: str="The adventurers guild"; break;
      case 4: str="Black Chamber []"; break;
      default: str="Village church";
    }
    return str;
  }
    else {
    switch(random(2)) {
    case 0: str=HIR; break;
    case 1: str=HIW; break;
    default: str=HIR; break;
  }
  return str+capitalize(OWNER)+"'s Workroom"+NORM;
  }
}

realm() {
  if(locked) return "NT";
}

shields() {
  if(this_player()->query_real_name()!=OWNER)
    return 0;
  if(shield) {
    write("You deactivate the shields.\n");
    shield=0;
    return 1;
  }
  else {
    write("You activate the shields.\n");
    shield=1;
    return 1;
  }
}

cloak() {
  if(this_player()->query_real_name()!=OWNER)
    return 0;
  if(cloak) {
    write("You deactivate the cloak.\n");
    cloak=0;
    return 1;
  }
  else {
    write("You activate the cloak.\n");
    cloak=1;
    return 1;
  }
}

locks() {
  if(this_player()->query_real_name()!=OWNER)
    return 0;
  if(locked) {
    write("You unlock the exits.\n");
    dest_dir=exits;
    locked=0;
    return 1;
  }
  else {
    write("You lock the exits.\n");
    exits=dest_dir;
    dest_dir=({ });
    locked=1;
    return 1;
  }
}

scry(string str) {
  object person,ob,special;
  if(!str) {
    write("Usage: scry <living>.\n");
    return 1;
  }
  person=find_player(str);
  if(!person)
    person=find_living(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  say(this_player()->query_name()+" gazes into the pool.\n");
  write("You gaze into the pool and see: \n");
  person->long();
  special=first_inventory(person);
  while(special) {
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str)
       write(extra_str+".\n");
    special=next_inventory(special);
  }
  write(capitalize(person->query_pronoun())+" is carrying: \n");
  ob = first_inventory(person);
  while (ob) {
    string sh;
    sh = call_other(ob, "short");

    if (sh)
    write(sh + ".\n");
    ob = next_inventory(ob);
  }
  return 1;
}

gaze(string str) {
  object person;
  object ob;
  if(!str) {
    write("Usage: gaze <living>\n");
    return 1;
  }
  person=find_player(str);
  if(!person)
    person=find_living(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  say(this_player()->query_name()+" gazes into the pool.\n");
  write("You gaze into the pool and see: \n");
  environment(person)->long();
  ob = first_inventory(environment(person));
  while (ob) {
    string sh;
    sh=ob->short();
    if(sh) write(sh + ".\n");
    ob=next_inventory(ob);
  }
  return 1;
}

escort(str)  {
  object person;
  if(!str) {
    write("Usage: escort <living>\n");
    return 1;
  }
  person=find_player(str);
  if(!person)
    person=find_living(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  if(shield) shields();
  tell_room(environment(person), 
"A giant dragon swoops down and snatches "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s workroom.\n");
  tell_room(this_object(),
   "A giant dragon flies in and deposits "+capitalize(str)+" on the floor, then\n"+
    "glides back out.\n"
  );
  return 1;
}

/* Exits */
teleport(str) {
  string dest;
  if(!str) {
    write(
    "You may "+HIW+"tp"+NORM+" to: "+HIW+"church"+NORM+", "+HIW+"post"+NORM+", "+HIW+"portal"+NORM+", "+HIR+"docks"+NORM+", "+HIR+"templar"+NORM+", "+HIW+"shrine"+NORM+", "+HIR+"inner"+NORM+", "+HIR+"necro"+NORM+".\n"
    );
    return 1;
  }
  if(locked) {
    write("You bounce off of the blue portal.\n");
    say(this_player()->query_name()+" bounces off of the blue portal.\n");
    return 1;
  }
  switch(str) {
    case "church": dest="room/church"; break;
    case "inner": if(this_player()->query_level() > 20) { 
                    dest="room/adv_inner"; 
                    break;
                  }
    case "post": dest="room/post"; break;
    case "docks": dest="players/jara/area1/docks/room/walk3"; break;
    case "templar": dest="players/jaraxle/templar/rooms/adv_inner"; break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
   write("You step through the "+HIB+"azure"+NORM+" portal and think, '"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIB+"azure portal"+NORM+"#"+dest);
  return 1;
}
