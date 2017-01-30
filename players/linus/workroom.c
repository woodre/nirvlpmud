/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.
                                      Feldegast
*/

#include "/players/feldegast/closed/ansi.h"
#include "/players/linus/def.h"

#define OWNER "linus"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int locked;

int x;
string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
long_desc = "Linus' workroom, nothing to see here!\n";
/*
*/
  items=({
"quads","Various ATVs that Linus works on in his spare time",
"workbench","A workbench holding all of Linus' tools.  There is\n"+
 "also a copy of 'Coding for Dummies' there\n",
 "window","A small window looking out to the lands of Nirvana",
  });
 dest_dir = ({ "/players/linus/broom.c","north",
        "/players/linus/HH/heaven/r2.c","east",
          "/players/earwax/closed/shardak/room/magusroom.c","down",
     "/room/south/sforst10","west",
});
}

cmd_smell(str) {
  write("You smell exhaust fumes, used motor oil, and freshly welded metal.\n");
  return 1;
}

cmd_listen(str) {
  write("Engine noise, and metal on metal resonate throughout the garage.\n");
  return 1;
}
short() {
switch(random(16)) {
 case 0..3: return "The "+HIR+"Honda"+NORM+" Shop";break;
 case 4..6: return "Broome-Tioga"; break;
 case 7..9: return "The "+HIR+"Red Riders"+NORM; break;
 case 10..12: return ""+BLU+"Chicago"+RED+" Bears"+NORM+""; break;
 case 13..15: return(TP?TPN+"'s":"Someone's")+" back pocket"; break; /* modded by verte */
}
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
  add_action("enter_energy","enter");
  
  if(this_player()->query_real_name()==OWNER) {
    add_action("shields","shields");
    add_action("locks","locks");
    add_action("scry","scry");
    add_action("gaze","gaze"); 
    add_action("escort","escort");
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
  case "pooh" :dest= "/players/linus/Newbie/room/n1.c"; break;
 case "shardak" :dest="/players/earwax/closed/shardak/room/grotto.c"; break;
   case "castle" :dest="/room/south/sforst10.c"; break;
    case "portal": dest="players/saber/ryllian/portal";break;
    case "chamber" : dest="/players/mythos/enterance";break;
    case "templar": dest="/players/jaraxle/templar/rooms/adv_inner";break;
 case "north": dest="/players/linus/Plains/room/p1";break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You open the "+HIR+"garage door"+NORM+" and say,'"+str+"' out loud.\n");
  this_player()->move_player("through the "+HIR+"garage door"+NORM+"#"+dest);
  return 1;
}
lookhere(object linus_is_a_fool) { command("look",linus_is_a_fool); }
enter_energy(string str){
        if(!str){ write("Enter what?\n"); return 1; }
        
        if(str == "light"){
          write("\n\nYou are blinded as you take a step forward into the bright\n");
          write("light.  A rush of sound and energy fills your head, making you\n");
          write("dizzy.  Eventually you regain control of your senses, and find\n");
          write("yourself someplace else.\n\n\n");  
          say(TPN+" steps into the light and dissappears.\n");
         move_object(TP, "/players/linus/Area/room/h1.c");
          tell_room(environment(TP), TPN+" steps out of the portal of light.\n", ({TP}));
        call_out("lookhere",3,TP);
          return 1;
        }
        write("What is it you are trying to do?\n");
        return 1;
        }
