/* First room attempt. First piece of code actually.
 * Hopefully will turn into a spiffy workroom.
 * Include some extra books, and EvilOverlord List on a poster
 * Derived heavily from the ryllian.c, valley.c, and Feld's example room,
 * and the starting workroom.c
 * Aerie or Lair
 */


#include "/open/ansi.h"
#define TP this_player()
#define NAME "wren"

inherit "/room/room.c";
int shield;
int cloak;
int locked;


reset(arg) {

string *exits; 

  if(arg) return;



long_desc = 
	"The exact location cannot be surmised but you have a suspicion \n"+
	"that you are outside the realm of normal space time. The walls are \n"+ 
	"paneled in smooth dark marble. Hickory logs crackle and pop in the \n"+
	"large hearth that is situated in the center of the east wall. \n"+
 	"Large redwood shelves stand on either side of the cheery blaze. \n"+
	"Leather bound tomes and folios mingle with busts of literary figures. \n"+
	"Before the fire are two well upolstered chairs for light reading. \n"+
	" \n"+
	"A massive oak desk extends from the west wall into the center of \n"+
	"the room with scrolls covering every flat surface. Weapons hang \n"+
	"above on ornate hardwood racks. Diagrams on old parchment of various \n"+
	"strikes and katas are tacked to the wall.Firelight glints off metal \n"+
	"in several locations around the room.   \n"+
	" \n"+
	"Above the door you notice astrange metal portcullis. \n"+
	"In the shadowy northwest corner a rift pulses and swirls. \n";

set_light(1);

items = ({
	"rift","Mystic energy swirls and coaleses. A wrinkle in space time or something else",
	"hearth","The large fireplace seems to naturally flow from the marble walls around it",
	"busts","The faces of Homer, Shakespeare, and Mark Twain",
	"glint","Several heavy crossbows are mounted in the walls. Armed and rigged to fire it seems",
	"portcullis","It is built like a cage and could probably serve in that function",
	"books","Vast and various titles of sci fi, fantasy, and classical works scattered about the shelves",
	"folios","You see one of the rare original folios of Shakespeare and Chaucer",
	"shakespeare","Something seems special",
});

dest_dir = ({
	"room/adv_inner.c","up",
});

}

init() {
    ::init();

add_action("church","church");
add_action("on");add_verb("on");
add_action("off");add_verb("off");
add_action("post");add_verb("post");

if(TP->query_real_name() != NAME && shield==1) {
    write("You feel an eletric shock and see a FLASH of white light \n");
    write("as you rebound off some defensive shield. \n");
TP->move_player("off the shields#room/church");
return 1; 
}


if(TP->query_real_name()==NAME) {
   add_action("rift","rift");
   add_action("cloak","cloak");
   add_action("locks","locks");
   add_action("scry","scry");
   add_action("gaze","gaze");
   add_action("fetch","fetch");
   add_action("shakespeare","shakespeare");
   }
} 


church()  {
   TP->move_player("church#room/church.c");
   command("look",this_player());
   return 1; }

static on()  {
   write("You"+BOLD+" activate "+NORM+"the shield. \n");
   shield = 1;
   return 1; }

static off()  {
   if(TP->query_real_name() !=NAME)  {
   write("Access denied.\n");
   return 1;  }
   write("You"+BOLD+" deactivate "+NORM+"the shield. \n");
   shield = 0;
   return 1; }

post() {
   TP->move_player("post office#room/post.c");
   return 1; }	

short() {
   string str;
   if(cloak) {
    switch(random(5)) {
      case 0: str="Village church"; break;
      case 1: str="Village green [n,w,e]"; break;
      case 2: str="Village road [w,n,s,e]"; break;
      case 3: str="The adventurers guild"; break;
      case 4: str="Black Chamber[]"; break;
      case 5: str="Right Behind You [No escape]"; break;
      default: str ="Village church";
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
   return str+"("+NORM+capitalize(NAME)+"'s Lair"+str+")"+NORM;
         }
}


realm() {
  if(locked) return "NT";
        }


cloak() {
   if(TP->query_real_name()!=NAME)
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

/*
locks() {
    if(TP->query_real_name()!=NAME)
      return 0;
    if(locked) {
      write("You raise the portcullis allowing egress.\n");
      dest_dir=exits;
      locked=0;
      return 1;
               }
    else {
      write("You drop the portcullis sealing the exits.\n");
      exits=dest_dir;
      dest_dir=({ });
      locked=1;
      return 1;
         }
}
*/
scry(string str) {
   object person,ob,special;
   if(!str) {
      write("Usage: scry <living>. \n");
      return 1;
     }
   person=find_player(str);
   if(!person)
     person=find_living(str);
   if(!person)  {
     write(str+" cannot be found.\n");
     return 1;
     }
   say(TP->query_name()+" gazes into the rift.\n");
   write("You gaze into the rift and see: \n");
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
     ob=next_inventory(ob);
     }
    return 1;
   }


gaze(string str) {
    object person;
    object ob;
    
    if(!str) {
       write("Usage: gaze <living> \n");
       return 1;
     }
    person=find_player(str);
    if(!person)
      person=find_living(str);
    if(!person) {
       write(str+" cannot be found.\n");
       return 1;
     }
    say(TP->query_name()+" gazes into the swirling depths. \n");
    write("You gaze into the swirling rift and see: \n");
    environment(person)->long();
    ob=first_inventory(environment(person));
    while (ob) {
       string sh;
       sh=ob->short();
       if(sh) write(sh +".\n");
       ob=next_inventory(ob);
     }
    return 1;
   }


fetch(str)  {
    object person;
    if(!str) {
       write("Usage: fetch <living> \n");
       return 1;
    }
    person=find_player(str);
    if(!person)
      person=find_living(str);
    if(!person)  {
      write(str+" cannot be found. \n");
      return 1;
    }
    if(shield) shields();
    tell_room(environment(person),
    "A flock of sparrows flutter in obscuring "+capitalize(str)+" then fly away.\n");
    move_object(person,this_object());
    tell_object(person,"You have been taken to "+capitalize(NAME)+"'s lair.\n");
    tell_room(this_object(),"A flock of sparrows flitter in and deposit "+capitalize(str)+" on the floor,\n"+ 
               "then vanish in a cloud of glittering motes. \n");
    return 1;
   }


/* EXITS */

rift(str) {
    string dest;
    if(!str) {
        write("You may rift to church,post,portal,shrine,castle.\n");
        return 1;
        }
    if(locked) {
       write("The rift darkens and you are unable to leave.\n");
       say(TP->query_name()+" stands confused before the darkened rift.\n");
       return 1;
        }

switch(str)  {

  case "portal": dest="players/saber/ryllian/portal"; break;
  case "shrine": dest="players/feldegast/shrine"; break;
  case "castle": dest="players/wren/castle"; break;
  default: write("That destination isn't available to you. \n");
    return 1;
    break ;

     }
  write("You step through the "+BOLD+" rift"+NORM+" and think, "+str+"' to yourself\n");
  TP->move_player("through the "+BOLD+" rift"+NORM+"#"+dest);
  return 1;
}
  
shakespeare(str)  { 
     if(!str) {
        write("These commands are available here: \n");
        write("rift,fetch,cloak,gaze,scry,locks,on,off,church,post. \n");
        return 1;
              }
}
