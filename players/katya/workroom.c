#include <ansi.h>

#define OWNER "katya"

inherit "room/room.c";

int shield;
int cloak; 
int locked;

string *exits;
      
reset(arg) {

if(!present("notice")) {
move_object(clone_object("players/llew/Other/misc/obituary.c"),this_object());
}


  if(arg) return;

  set_light(1);

  long_desc=
        "Katya's room is quite plan.  The walls are all painted\n"+
        "an off white color and there is nothing placed upon them.\n"+
        "There is a beautiful rug placed on the hard wood floor in \n"+
        "the center of the room.  An oak desk has been put kitty-\n"+
        "cornered on the far side of the room.  Behind the desk along\n"+
        "the wall there are many shelves with books.  Near that is an \n"+
        "archway containing an azure portal.  In the middle of the \n"+
        "chamber is a marble reflecting pool.\n";
   items=({
	"rug",
	   "A hand woven oriental rug.",
	"desk",
	   "An antique oak desk, that is at least 100 years old",
	"walls",
	   "The walls are quite plan, so nothing distracts her from doing her job",
	"shelves",
	   "The shelves are made of solid oak",
	"books",
	   "The old books are scattered upon the shelves",
        "portal",
	   "A swirling blue gateway through which you can travel.\n"+
           "Type 'tp' for help",
	"pool",
	   "A pool of crystal clear water in a marble basin.  If you had the\n"+
	   "proper knowledge, you could see things in it",
   });

   dest_dir=({
        "/room/vill_green","green",
        "/room/adv_inner","wizhall",
        "/players/katya/area/mountain/r/m1","mountain",
        "/players/guilds/bards/bardrooms/teleport","bards",
        "/players/katya/area/esquire/r/entrance.c","esquire",
        "/room/post","post",
 	   });
}
cmd_smell(str) {
  write("There is a sweet scent of potpourri.\n");
  return 1;
}

cmd_listen(str) {
  write("You hear children playing in the green.\n");
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
    switch(random(7)) {
      case 0: str="Village church"; break;
      case 1: str="Village green [n,w,e]"; break;
      case 2: str="Village road [w,n,s,e]"; break;
      case 3: str="The adventurers guild"; break;
      case 4: str="Black Chamber []"; break;
      case 5: str="Chamber of Realms [many exits]"; break;
      case 6: str="Unknown"; break;
      case 7: str="Wall of Passage [pass,w]"; break;
      default: str="Village church";
    }
    return str;
  }
  else {
    switch(random(7)) {
      case 0: str=HIW; break;
      case 1: str=HIB; break;
      case 2: str=BLU; break;
      case 3: str=BOLD; break;
      case 4: str=BOLD+BLK; break;
      case 5: str=HIR; break;
      case 6: str=HIM; break;
      case 7: str=MAG; break;
      default: str=HIB; break;
    }
    return str+"{*} "+NORM+capitalize(OWNER)+"'s Room"+str+" {*}"+NORM;
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
"A ladybug flitters down and snatches "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s tower.\n");
  tell_room(this_object(),
  "A ladybug flitters in and deposits "+capitalize(str)+" on the floor,\n then flutters back out.\n"
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
