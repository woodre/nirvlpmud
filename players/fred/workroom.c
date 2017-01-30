/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.
                                      Feldegast
*/

#include "/players/feldegast/closed/ansi.h"

#define OWNER "fred"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
"I Like Spoons.\n\tSpoons Are Sexy.\n\t\tGive Me Spoons.";
/*
"  This is the top chamber of "+capitalize(OWNER)+"'s tower.  It is lined with\n"+
"bookshelves containing esoteric texts from distant lands.  Against\n"+
"one wall is an antique mahogany desk piled with ancient scrolls and\n"+
"stacks of reports.  Against the wall opposite that is a crackling\n"+
"fireplace.  Near that is an archway containing an azure portal.  In\n"+
"the middle of the chamber is a marble reflecting pool.\n";
*/
  items=({
    "portal","A swirling blue gateway through which you can travel.\n"+
             "Type 'tp' for help",
    "pool",
"A pool of crystal clear water in a marble basin.  If you had the\n"+
"proper knowledge, you could see things in it",
    "basin",
"A pool of crystal clear water in a marble basin.  If you had the\n"+
"proper knowledge, you could see things in it",
    "books","You read a few titles from the bookshelf:\n"+
            " The Count of Monte Cristo by Alexandre Dumas\n"+
            " Magician: Master by Raymond E. Feist\n"+
            " The Prince by Niccolo Machiavelli\n"+
            " Unearthed Arcana of the Majiri by Bedira the Watcher\n"+
            " The Conquest of Chalynsta by Nakros the Elder\n",
    "bookshelves",
            "The bookshelves are filled to overflowing with numerous\n"+
            "leatherbound tomes, yellowed parchments, and antiquated\n"+
            "folios that predate the fall of magic",
  });
  dest_dir=({
  });
}

cmd_smell(str) {
  write("You smell old book leather, mint, and scented candles.\n");
  return 1;
}

cmd_listen(str) {
  write("The tower top is completely silent.\n");
  return 1;
}

init() {
  ::init();
  if(this_player()->query_real_name() != OWNER && shield == 1) {
    write("Knock first you heathen!!!\n");
    write("A group of ferrets escorts you to the Church.\n");
    this_player()->move_player("off the doors#room/church");
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
  return "Spoons 'R Me";
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
   if(!person || !environment(person)) {
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
  person=find_living(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  if(shield) shields();
  tell_room(environment(person), 
"A pack of Woodchucks rush into the room and grab "+capitalize(str)+" off\n"+
"of "+person->query_possessive()+" feet and carry "+person->query_objective()+" away.\n");
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s tower.\n");
  tell_room(this_object(),
  "The Woodchucks run into the room gently set "+capitalize(str)+" on the\n"+
  "floor, and excitedly run out.\n" 
  );
  return 1;
}

/* Exits */
teleport(str) {
  string dest;
  if(!str) {
    write(
"You may teleport to: church, post, portal, hall, inner, haven, meeting.\n"
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
    case "portal": dest="players/saber/ryllian/portal";break;
    case "hall": dest="/players/snow/dervish/hall/hall";break;
    case "haven": dest="players/fred/mages/rooms/haven"; break;
    case "meeting": dest = "players/fred/closed/bloodfist/r/meeting"; break;
     case "center": dest ="players/guilds/Rangers/CommandCenter/CommandCenter"; break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You step through the "+HIB+"azure"+NORM+" portal and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIB+"azure portal"+NORM+"#"+dest);
  return 1;
}
