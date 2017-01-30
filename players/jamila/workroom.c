/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.

Before you get too far along, you should change
'Jamila' to your real name.
                The Administration
*/

#include <ansi.h>

#define OWNER "Jamila"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
"  This is a large "+HIC+"air"+NORM+" pocket inside of a "+HIY+"giant sponge"+NORM+".  The pocket is\n"+
"strangely decorated with paintings covering many of the smaller\n"+
""+HIC+"air"+NORM+" valves.  The larger "+HIC+"air"+NORM+" valves leading out of the pocket have\n"+
"large doors blocking them.  On the far side there is a large desk\n"+
"cluttered with paperwork.  Next to the desk is a large bookshelf\n"+
"that seems as disorganized as the desk.  To your right you notice a\n"+
"small cot folded up beside a small fireplace.  It appears as if this\n"+
"part of the room is where "+HIB+capitalize(OWNER)+NORM+" sleeps when she's not working\n"+
"Behind you there is a large archway containing an azure portal and\n"+
"directly in front of you is a large marble reflecting pool.\n";
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
	  "/players/jamila/sponge.c","sponge",
	  "/players/jamila/ocean/oc1.c","ocean",
  });
}

cmd_smell(str) {
  write("The room smells surprisingly pleasant like a deserted beach.\n");
  return 1;
}

cmd_listen(str) {
  write("Far in the distance you can hear waves crashing.\n");
  return 1;
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
    return HIB+str+"**("+NORM+HIC+capitalize(OWNER)+"'s Air Pocket"+HIB+str+")**"+NORM;
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
"A giant eagle swoops down and snatches "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s tower.\n");
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
"You may teleport to: church, post, portal, shrine\n"
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
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You step through the "+HIB+"azure"+NORM+" portal and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIB+"azure portal"+NORM+"#"+dest);
  return 1;
}
