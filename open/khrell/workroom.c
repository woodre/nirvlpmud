#include <ansi.h>

#define OWNER "khrell"

inherit "/room/room.c";

int shield; 
int cloak; 
int locked; 

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
"  This is the top chamber of the Fortress-Monastery of the lost \n"+
"Legiones Astartes Angelus Mortis, or Death Angels.  It's gothic \n"+
"cathedrial roof towers high above.  A great many bookshelves line\n"+
"the walls and the contant humming sound of a deep generator echoes\n"+
"all over.  Great banners and tapestries speak of the great history\n"+
"of this lost chapter and their exploits during the great crusade and\n"+
"their battles since that long departed age.  In the center of the\n"+
"room rests a viewing holo-globe, it flickers and pulses as it's old\n"+
"machine spirit awaits for the time when it is awoken to perform it's\n"+
"duty.  Far off on the opposite side of the room rests a small teleport\n"+
"pad.  This machine seems to be well maintained and vibrates silently.\n"+
"Stained Glass windows cast colorful images of saints and heroes from\n"+
"past, preserved forever in this great shrine.\n";
  items=({
    "teleporter","A humming shadowed platform from which you can travel.\n"+
             "Type 'tp' for help",
    "holo-globe",
"A machine of old technology, that which can no longer be made.  If you had the\n"+
"proper knowledge, you could see things in it",
        "books","You read a few titles from the bookshelf:\n"+
            " Art of Warfare by Lion El'Johnson\n"+
            " Index Astartes by Roboute Guillman\n"+
            " Art of Siegecraft by Perturabo\n"+
            " Codex Arcanium by Magnus the Red\n"+
            " The Nature of Chaos by Warmaster Horus\n",
    "bookshelves",
            "The bookshelves are filled to overflowing with numerous\n"+
            "leatherbound tomes, yellowed parchments, and antiquated\n"+
            "folios that predate the Imperium of mankind.",
  });
  dest_dir=({
	  "players/khrell/area/home/entrance.c", "north"
  });
}

cmd_smell(str) {
  write("You smell oils, insence and a metallic tang in the air.\n");
  return 1;
}

cmd_listen(str) {
  write("The room hums from hidden machines.\n");
  return 1;
}

init() {
  ::init();
   add_action("teleport","teleport");
   add_action("cmd_smell","smell");
   add_action("cmd_listen","listen");
   add_action("teleport","tp");

   if(this_player()->query_real_name() != OWNER && shield == 1) {
   write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off of the shield.\n");
    this_player()->move_player("off the shields#room/church");
  }

  
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
    switch(random(8)) {
      case 0: str="Armory"; break;
      case 1: str="Apothecary"; break;
      case 2: str="Temple"; break;
      case 3: str="Reclimat"; break;
      case 4: str="Motor Pool"; break;
      case 5: str="Mess Hall"; break;
      case 6: str="Engineering Bay"; break;
      case 7: str="Barracks"; break;
      case 8: str="Dark room"; break;
      default: str="Dark room";
    }
    return str;
  }
  else {
    switch(random(6)) {
      case 0: str=HIW; break;
      case 1: str=HIB; break;
      case 2: str=RED; break;
      case 3: str=BOLD; break;
      case 4: str=BOLD+BLK; break;
      case 5: str=HIR; break;
      default: str=HIB; break;
    }
    return str+"The Fortress-Monastery"+str+NORM;
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
  say(this_player()->query_name()+" gazes at the globe.\n");
  write("You gaze into the globe and see: \n");
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
  say(this_player()->query_name()+" stares into the globe.\n");
  write("You stare into the globe and see: \n");
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
  "A"+HIC+" teleporter"+NORM+" beam surrounds "+capitalize(str)+", who vanishes, leaving only a faint smell of ozone behind.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s chambers.\n");
  tell_room(this_object(),
  "The "+HIC+"teleporter"+NORM+" deposits "+capitalize(str)+" on the pad.\n"
  );
  return 1;
}

teleport(str) {
  string dest;
  if(!str) {
    write(
"You may teleport to: church, post, portal, goblin, underways\n"
    );
    return 1;
  }
  if(locked) {
    write("You bounce off of the black portal.\n");
    say(this_player()->query_name()+" bounces off of the black portal.\n");
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
    case "goblin": dest="players/khrell/area/goblins/gobrm1";break;
    case "underways": dest="players/khrell/area/underways/undermdh1.c";break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You step onto the "+HIC+"teleporter"+NORM+" pad and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIC+"teleport beam"+NORM+"#"+dest);
  return 1;
}
