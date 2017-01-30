/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.
                                      Feldegast

Modified for personal use 11/18/00 - Softly
*/

#include "/players/feldegast/closed/ansi.h"

#define OWNER "softly"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
"  This is a back room in "+capitalize(OWNER)+"'s legendary "+HIB+"Blue Parrot "+HIW+ "Cafe"+NORM+".\n"+
"Books spill out of the bookshelves covering one wall.  Beneath the rear\n"+
"window is a small desk laden with papers and scribblings. On its far\n"+
"corner sits a large crystal sphere.  Against the opposite wall are\n"+
"two overstuffed chairs. The table between them is covered with food\n"+
"and drink.  Nearby a small alcove holds a red and gold Wurlitzer.\n"+
"Beyond the alcove is an archway encasing an silver portal.\n";
  items=({
    "Wurlitzer","An ornately lighted red and gold juke box.  It holds 12 selections.\n",
    "wurlitzer","An ornately lighted red and gold juke box.  It holds 12 selections.\n",
    "portal","A swirling silver gateway through which you can travel.\n"+
             "Type 'tp' for help",
    "sphere",
"A crystal clear orb sitting on a desk.  If you had the\n"+
"proper knowledge, you could see things in it",

"A crystal clear orb sitting on a desk.  If you had the\n"+
"proper knowledge, you could see things in it",
    "books","The bookshelves include:\n"+
            " Beloved by Toni Morrison\n"+
            " Foucault's Pendulum by Umberto Eco\n"+
            " The Prince by Niccolo Machiavelli\n"+
            " A Voyage to Arcturus by David Lindsay\n"+
            " The Crucible by Arthur Miller\n"+
            " Lilith's Brood by Octavia Butler\n",
    "desk",
            "The desk is a jumble of papers including heavy reports\n"+
            "and hastily scribbled notes. A number of shiny disk-like\n"+
            "objects are scattered about. A large quartz sphere sits\n"+
            "in the far corner.",
    "selections","An eclectic collection including:\n"+
            " Softly, As In A Morning Sunrise by Eric Dolphy Quartet\n"+
            " I Put a Spell On You by Screamin' Jay Hawkins\n"+
            " 'Round Midnight by Miles Davis\n"+
            " Got My Mojo Working by Muddy Waters\n"+
            " Voodoo Chile by Stevie Ray Vaughan\n"+
            " Night and Day by Billie Holliday\n",            
    "bookshelves",
            "The bookshelves overflow with books, papers,\n"+
            "and a collection of mementos, including pen\n"+
            "and ink sketches of people and places unknown.",
  });
  dest_dir=({
  });
}

cmd_smell(str) {
  write("The scents of oranges, jasmine, and summer fill the air.\n");
  return 1;
}

cmd_listen(str) {
  write("Muted piano music plays softly in the background.\n");
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
    /*    switch(random(6)) {    */
    /*   case 0: str=HIW; break; */
    /*  case 1: str=HIB; break;  */
    /*  case 2: str=BLU; break;  */
    /*  case 3: str=BOLD; break; */
    /*  case 4: str=BOLD+BLK; break; */
    /*  case 5: str=HIR; break;  */
    /*  default: str=HIB; break; */
    /*    }                      */
    /*   return str+"("+NORM+capitalize(OWNER)+"'s Tower"+str+")"+NORM;  */
        return HIB+"Blue Parrot " +HIW+"Cafe"+NORM;
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
  say(this_player()->query_name()+" gazes into the sphere.\n");
  write("You gaze into the sphere and see: \n");
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
  say(this_player()->query_name()+" gazes into the sphere.\n");
  write("You gaze into the sphere and see: \n");
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
"A "+HIR+"flaming demon"+NORM+" swoops down and lifts "+capitalize(str)+" from the ground.\n"
  );
  move_object(person,this_object());
  tell_object(person,"You have been taken to "+capitalize(OWNER)+"'s workroom.\n");
  tell_room(this_object(),
  "A "+HIR+"flaming demon"+NORM+" flies in and deposits "+capitalize(str)+" on the floor,\n then slips away.\n"
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
    write("You bounce off of the silver portal.\n");
    say(this_player()->query_name()+" bounces off of the silver portal.\n");
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
  write("You step through the "+HIW+"silver"+NORM+" portal and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIW+"silver portal"+NORM+"#"+dest);
  return 1;
}
