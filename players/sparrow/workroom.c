#include <ansi.h>
#define OWNER "sparrow"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc=
    "A large oak desk dominates the center of the room. A white leather chair\n"+
    "is tucked under the far lip of the desk. Flanking the chair on either side is\n"+
    "a large cinema display flashing images of the realms in a rapid succession.\n"+
    "Large windows overlook the beauty of the beach; bright rays of sunshine\n"+
    "flood into the room. A thick woven rug covers the interior of the light oak\n"+
    "floor. On the far corner of the floor is a brushed aluminum plate.\n";
  items=({
    "desk",
      "The large oak desk dominates the center of the room. A 30 inch Apple\n"+
      "Cinema Display rests in the center of the desk in front of the chair. A\n"+
      "G5 Quad-Core PowerMac hums beside the screen", 
    "plate",
      "This pressure plate allows you to travel from place to place in Nirvana.\n"+
             "Type 'plate' for details",
    "chair",
      "This large white leather desk chair swivels back and forth with ease. \n"+
      "A small control panel is embedded into the left arm rest while a micro\n"+
      "trackball device protrudes from the right",
    "display",
      "Large LCD displays are mounted on the wall showing various spots in\n"+
      "the realms of Sparrow",
    "windows",
      "The large windows are open, allowing the fresh sea breeze into the room.\n"+
      "Warm rays of light beam into the room lighting larges squares on the floor",
    "window",
      "The large windows are open, allowing the fresh sea breeze into the room.\n"+
      "Warm rays of light beam into the room lighting larges squares on the floor",
    "rug",
      "The thick rugs covers the center of the floor, resting on top is a large desk",
    "floor",
      "The oak parque floor is covered in a unique design",
    "design",
    "                              ,a              .Z7MMMM\n"+      
    "                             :MMM;            ZM0MXM0\n"+       
    "                             MMM           .MMM a7SM\n"+        
    "                          2MMBM           .M X@ M M\n"+         
    "                         rM2SM           MrM;7M M:M\n"+         
    "                   8M8MMM@aB;M          ZMZiM.M WaM\n"+         
    "              MMMMMMW0a20MXBiM          M XBB8@aBaM\n"+         
    "              MS :SWMMW8Z0W0iM        MMMMr70WS0BZM\n"+         
    "                     .M@Sa8BrM       2MW7XMXa0880XM\n"+         
    "                       2MSSWX8M    ZMM0;aWSWS0880MM\n"+         
    "                        iMXXSXMM 2MM@Ba0B20Z0BMMMM\n"+          
    "                         M0222XWMM8S2XZ0aB8MWWMMX\n"+           
    "                         M0222X77ZWBa80ZWW22MM\n"+              
    "                        rM;W2a2XXXr8@2a@r,aM\n"+                
    "                        ;M,@S2aa2SXXZ@WMa0M;\n"+                
    "                         M,ZS7X7SXX7aW2X7rSWMM\n"+              
    "                        MM8@WWW0aSXX27SXa887rWM\n"+             
    "                       MWZ2Z2S8BWW0ZX72W0r0MaZM@\n"+            
    "                      aMa88Za8BZa80WMMMr.:,7XZ  MM\n"+          
    "                      MBZ88Z808Z@@8@@Z7:rXXXMMMMMM\n"+          
    "                    ,MMZ88Z88W@0XX07 ,rS8@MMM\n"+               
    "                0ZMM@S280Z80W0;2MMMMMMMMM2\n"+                  
    "           aMMMMMM8Saa8aaZ800 ZM.\n"+                           
    "          :M;,:i;rSZ0BB8ZZ8@20M\n"+                             
    "        iaMMBW@W@BW0aSSZ000@0M\n"+                              
    "      MM@X;72ZB08aaZZ0808BWWM\n"+                               
    "     MZ7MMM@8a228WMMMMMMMMM8\n"+                                
    "    8MMZ              .7r\n"+                                   
    "  ;MM\n",                         
  });
  dest_dir=({
  });
}

cmd_smell(str) {
  write("The fresh sea air fills the room.\n");
  return 1;
}

cmd_listen(str) {
  write("The crashing of the waves thunders in through the open windows.\n");
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
  add_action("teleport","plate");
  add_action("shadow_cont","shadow");
  
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
    return str+OWNER+"'s Office"+str+NORM;
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
  say(this_player()->query_name()+" pulls up an image on his display.\n");
  write("You stare into the monitor: \n");
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
  say(this_player()->query_name()+" pulls up an image on his display.\n");
  write("You stare into the monitor: \n");
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
    capitalize(str)+"'s form is shrouded in light.\n"+
    capitalize(str)+"disappears!\n"  
  );
  move_object(person,this_object());
  tell_object(person,"You have been transported to "+capitalize(OWNER)+"'s office.\n");
  tell_room(this_object(),
  "A bright light envelops the plate.\n"+
  capitalize(str)+" appears in a flash!\n"
  );
  return 1;
}

/* Exits */
teleport(str) {
  string dest;
  if(!str) {
    write(
"You may teleport to: church, post, portal, shrine, "+HIG+"enclave\n"+NORM
    );
    return 1;
  }
  if(locked) {
    write("Nothing happens.\n");
    say(this_player()->query_name()+" looks silly standing on the aluminum plate.\n");
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
    case "enclave": dest="/players/sparrow/areas/bwo/rms/BW1-20";break;
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You utter the word: '"+HIB+str+NORM+"'\n"+
          "A bright light envelopes you!\n");
  this_player()->move_player("teleports "+NORM+"#"+dest);
  return 1;
}

shadow_cont(){
  object ob;
  ob = clone_object("/players/sparrow/areas/shadow_cont/rooms/sc_room.c");
  ob->initialize_room_from_map(7,7);
  move_object(this_player(),ob);
  return;
}
