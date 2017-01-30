#include <ansi.h>

#define OWNER "angel"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
""+YEL+"   You have just steped into "+capitalize(OWNER)+"'s Realm. Off to the right it\n"+
"appears to be an old distressed "+HIW+"white"+NORM+""+YEL+" farm house. It appears to be\n"+
"three stories tall with closed "+CYN+"black"+NORM+""+YEL+" shutters. When looking around\n"+ 
"the house you get an eerie feeling. All around the house there are\n"+
"large "+HIY+"corn"+NORM+""+YEL+" stalks. As the wind flows briskly across your face, the\n"+
""+HIY+"corn"+NORM+""+YEL+" stalks appear to be bending. Between the "+HIY+"corn"+NORM+""+YEL+" there is a plat\n"+
"form in the middle of the field where the "+HIB+"stargate"+NORM+""+YEL+" is located. Past\n"+
"the "+HIB+"stargate"+NORM+""+YEL+" is a clear lake."+NORM+"\n";
  items=
    ({
      "stargate",
      "A swirling blue gateway through which you can travel.\n"+
      "Type 'tp' for help",
      "lake",
      "A lake with crystal clear water that you can see the fish below swimming. If you had the\n"+
      "proper knowledge, you could see things in it",
      "fish",
      "Giant 6 feet channel cats glare above",
      "corn stalks",
      "You see the bright green husk that cover the corn:\n"+
      "You see the stalks swaying back and forth",
    });
  dest_dir=
    ({
    });
}

init() {
  ::init();
  if(this_player()->query_real_name() != OWNER && shield == 1) {
    write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off of the shield.\n");
    this_player()->move_player("off the shields#room/church");
  }

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

cmd_smell(str) {
  write("You smell clean fresh farm life.\n");
  return 1;
}

cmd_listen(str) {
  write("The wind whisles and zings as the wind blows through.\n");
  return 1;
}

short() {
  string str;
  if(cloak) {
    switch(random(6)) {
      case 0: str="Gas City"; break;
      case 1: str="Nox HomeWorld"; break;
      case 2: str="Stargate Atlantis"; break;
      case 3: str="Stargate /-\\"; break;
      case 4: str="Masons Pub"; break;
      case 5: str="Thanagar"; break;
      default: str="Thanagar";
    }
    return str;
  }
  else {
    switch(random(6)) {
      case 0: str=HIR; break;
      case 1: str=HIY; break;
      case 2: str=BLU; break;
      case 3: str=BOLD; break;
      case 4: str=HIR; break;
      case 5: str=HIY; break;
      default: str=HIR; break;
    }
    return BOLD+">|:|<"+str+capitalize(OWNER)+"'s Realm"+NORM+BOLD+">|:|<"+NORM;
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
  say(this_player()->query_name()+" gazes into the lake.\n");
  write("You gaze into the lake and see: \n");
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
  say(this_player()->query_name()+" gazes into the lake.\n");
  write("You gaze into the lake and see: \n");
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
"A giant eagle swoops down and snatches "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s compound.\n");
  tell_room(this_object(),
  "A giant eagle flies in and deposits "+capitalize(str)+" on the floor,\n then glides back out.\n"
  );
  return 1;
}

/* Exits */
teleport(str) {
  string dest;
  if(!str) {
    write(
"You may teleport to: church, post, portal, shrine, gate\n"
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
    case "shrine": dest="/players/feldegast/shrine";break;
    case "gate": dest="/players/angel/area/stargate/room/sg1";break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You step through the "+HIB+"stargate"+NORM+" and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIB+"stargate"+NORM+"#"+dest);
  return 1;
}