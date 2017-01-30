/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.

Before you get too far along, you should change
'your_name' to your real name.
                The Administration
*/

#include <ansi.h>

#define OWNER "Aingeal"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
"  This is the innermost room of "+capitalize(OWNER)+"'s Cloud.  It is lined with mahogany\n"+
"bookshelves containing esoteric texts from distant lands.  Against\n"+
"one wall is an antique mahogany desk neatly stacked with ancient scrolls.\n"+
"A large brick fireplace dominates the opposite wall, its broad, polished\n"+
"stone mantle supporting a magnificent crystal longsword that glitters\n"+
"brilliantly with the red and gold reflections of the merry fire as it dances\n"+
"in the hearth.  Two overstuffed leather armchairs of deepest ebony\n"+
"rest comfortably before the fireplace, separated by a small mahogany end\n"+
"table.  A plush, wooly rug of light beige warms itself upon the floor before\n"+
"the fireplace.  In the relative shadows to the east of the fireplace rests\n"+
"a long couch, matching the leather chairs in every detail.  To the west\n"+
"is the cool expanse of a picture window, complete with padded window\n"+
"seat, that looks out upon the countryside below.  Tucked away in one\n"+
"corner is hidden an azure portal, and the center of the room holds a \n"+
"mirror-like reflecting pool that is as smooth and still as glass.\n";
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
   "fireplace",
      "The dark brick fireplace dominates the wall it rests within,\n"+
      "its polished stone mantle stretching across at nearly eye level.  The\n"+
      "merry blaze in its hearth casts light in warm hues of gold, tangerine,\n"+
      "and ruby across the objects closest to it in the cozy room",
     "fire",
        "A merry fire dances in the hearth, bathing the room in warm\n"+
        "shades of gold, tangerine, and ruby",
     "mantle",
        "The broad stone mantle is polished to a reflective sheen.  Upon its center\n"+
        "rests a magnificent crystal broadsword, glowing softly in the reflected\n"+
        "firelight from the hearth beneath it",
      "longsword",
        "The magnificent crystal longsword stretches nearly five feet across\n"+
        "the top of the fireplace mantle, glowing softly in the reflected firelight",
     "sword",
        "The magnificent crystal longsword stretches nearly five feet across\n"+
        "the top of the fireplace mantle, glowing softly in the reflected firelight",
     "hearth",
        "A merry fire dances in the hearth, bathing the room in warm\n"+
        "shades of gold, tangerine, and ruby",
     "chair",
        "The black, overstuffed leather armchair appears enticingly comfortable",
     "armchair",
        "The black, overstuffed leather armchair appears enticingly comfortable",
     "table",
        "The small, round end table is of dark mahogany, polished to\n"+
        "a mirror sheen.  A tidy tiffany lamp glows from the center of the table",
     "rug",
        "A deep rug of wooly beige warms itself before the fireplace",
     "couch",
        "The black, overstuffed leather couch appears to be\n"+
        "enticingly comfortable",
     "window",
        "Rolling hills interrupted by tidy clusters of buildings lie below the\n"+
        "cool glass of the picture window.  The window is at such a height, all\n"+
        "below appears somehow peaceful and distant",
     "seat",
        "The padded window seat beckons, promising a moment of peaceful solitude",
     "window seat",
        "The padded window seat beckons, promising a moment of peaceful solitude",
  });
  dest_dir=({
  });
}

cmd_smell(str) {
  write("You smell old book leather, mint, and scented candles.\n");
  return 1;
}

cmd_listen(str) {
  write("The soothing, dulcet tones of new age music play softly in the background.\n");
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
    return str+"("+NORM+capitalize(OWNER)+"'s Cloud"+str+")"+NORM;
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
"A trio of cherubs float down, laughing, and gently lifts "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s Cloud.\n");
  tell_room(this_object(),
  "A trio of cherubs float down, laughing, and gently deposit "+capitalize(str)+" on the floor,\n then float back out.\n"
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
