/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.
                                      Feldegast
*/

#include "/players/feldegast/closed/ansi.h"

#define OWNER "catacomb"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  if(!present("table"))
	  move_object(clone_object("/players/catacomb/toys/pooltable.c"),
	    this_object());
  long_desc=
"  This is "+capitalize(OWNER)+"'s Tav on the Peak.  The bar is along\n"+
"the east wall.  In the back of the room is a pool table to pass\n"+
"the time.  To the west of the pool table are some pinball machines.\n"+
"There is a large stage in the front of the bar equiped with several\n"+
"amplifiers and various musical instruments.  The restrooms are in the \n"+
"right corner of the room.\n";
  items=({
    "bar","A fully stocked bar with any kind of alcohol you can think of.\n"+
             "Type 'tp' for help",
    "stage",
"The stage is set for a concert, but no bands can be seen anywhere,\n"+
"Catacomb couldn't play all of these instruments, or could he?",
    "restroom",
"When you gotta go you gotta go.\n",
    "machine",
		"Several different titles catch your eye.\n",
    "amplifiers",
            "The amplifiers are simply huge, you haven't ever seen any\n"+
            "as large as these.\n",
    "instruments",
            "There is a bass guitar, a 5-string guitar, and a set of drums.\n",
  });
  dest_dir=({
    "/players/catacomb/cave.c","cave",
    "/players/catacomb/Cavern/rooms/ground.c","sgloom"
  });
}

cmd_smell(str) {
  write("You smell the combination of cigarette smoke and alcohol.\n");
  return 1;
}

cmd_listen(str) {
  write("You can hear the beeps and whistles of the pinball machine.\n");
  return 1;
}

init() {
  ::init();
  if(this_player()->query_real_name() != OWNER && shield == 1) {
    write("You run off in pain from the loud music coming from the Tav on the Peak.\n");
    this_player()->move_player("off the shields#room/church");
  }

  add_action("orderDrink","order");
  add_action("teleport","teleport");
  add_action("cmd_smell","smell");
  add_action("cmd_listen","listen");
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
    switch(random(6)) {
      case 0: str=HIW; break;
      case 1: str=HIB; break;
      case 2: str=BLU; break;
      case 3: str=BOLD; break;
      case 4: str=BOLD+BLK; break;
      case 5: str=HIR; break;
      default: str=HIB; break;
    }
    return str+BLINK+"Tav on the Peak"+NORM;
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
  say(this_player()->query_name()+" gazes into the whiskey coke.\n");
  write("You gaze into the whiskey coke and see: \n");
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
  say(this_player()->query_name()+" gazes into the bottle of beer.\n");
  write("You gaze into the bottle of beer and see: \n");
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
"A hypnotizing beat carries "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"A hypnotizing beat carries you to "+capitalize(OWNER)+"'s Tav on the Peak.\n");
  tell_room(this_object(),
  "The beats carry away "+capitalize(str)+".\n"
  );
  return 1;
}

/* Exits */
teleport(str) {
  string dest;
  if(!str) {
    write(
"You may teleport to: church, post, portal, shrine\n"
    );
    return 1;
  }
  if(locked) {
    write("The bouncer tells you the club is full.\n");
    say(this_player()->query_name()+" is told the club is full by the bouncer.\n");
    return 1;
  }
  switch(str) {
    case "church": dest="room/church"; break;
    case "inner": if(this_player()->query_level() > 20) { 
                    dest="room/adv_inner"; 
                    break;
                  }
    case "post": dest="room/post"; break;
    case "portal": dest="players/saber/ryllian/portal";break;
    case "shrine": dest="/players/feldegast/shrine";break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You step through the "+HIB+"azure"+NORM+" portal and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIB+"azure portal"+NORM+"#"+dest);
  return 1;
}

orderDrink(str)
{
  string drink;
  drink = str;
  write("The bartender mixes up the "+drink+".\n");
  write("Then she puts in some "+HIW+"Ice cubes"+NORM+" .\n");
  write("She hands over the "+BRED+HIW+drink+NORM+".\n");
  say("The bartender mixes up the "+drink+".\n");
  say("Then she puts in some "+HIW+"Ice cubes"+NORM+".\n");
  say("She hands over the "+BRED+HIW+drink+NORM+".\n");
  return 1;
}