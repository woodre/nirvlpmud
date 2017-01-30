#include "/players/feldegast/defines.h"
inherit ROOM;

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

reset(arg) {
  if(arg) return;
  set_light(1);
  if(find_player("feldegast") && file_size("/players/feldegast/log/messages.log") > 1) {
    tell_object(find_player("feldegast"),"Danath tells you: There's a new message for you on your desk, sir.\n");}
  long_desc=
"  This is a perfectly circular room in the topmost chamber of the\n\
wizard Feldegast's tower.  A swirling portal of blue light is in the\n\
west wall.  A magnificent pool of crystal clear water is in a marble\n\
basin in the center of the room.  Rows and rows of books fill the\n\
bookshelves on the east wall.  A strong oak door leads south.\n";
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
    "door","The border of this thick ironbound door is intricately carved\n"+
           "with spidery runes\n",
    "runes","They appear to be protective runes, but you could be wrong"

  });
  dest_dir=({
    "/players/feldegast/closed/tower/tower3","south"
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
  if(this_player()->query_real_name() != "feldegast" && shield == 1) {
    write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off of the shield.\n");
    this_player()->move_player("off the shields#players/feldegast/closed/tower/outside");
  }
  add_action("teleport","teleport");
  add_action("teleport","tp");
  
  if(this_player()->query_real_name()!="feldegast") return;
  
  add_action("shields","shields");
  add_action("cloak","cloak");
  add_action("locks","locks");
  add_action("scry","scry");
  add_action("gaze","gaze"); 
  add_action("escort","escort");
  add_action("detain","detain");

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
  return "The "+str+"Crystal"+NORM+" Tower";
  }
}
realm() {
  if(locked) return "NT";
}
query_prevent_shadow()
{
  return 1;
}
shields() {
  if(this_player()->query_real_name()!="feldegast")
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
  if(this_player()->query_real_name()!="feldegast")
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
  if(this_player()->query_real_name()!="feldegast")
    return 0;
  if(locked) {
    write("You unlock the exits.\n");
    dest_dir=({
     "/players/feldegast/closed/tower/tower3","south",
    });
    locked=0;
    return 1;
  }
  else {
    write("You lock the exits.\n");
    dest_dir=({});
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
  say(TPN+" gazes into the pool.\n");
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
  say(TPN+" gazes into the pool.\n");
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
  tell_object(person,"You have been taken to Feldegast's tower.\n");
  tell_room(this_object(),
  "A giant eagle flies in and deposits "+capitalize(str)+" on the floor,\n then glides back out.\n"
  );
  return 1;
}
detain(string str) {
  object person;
  if(!str) {
    write("Usage: detain <player>.\n");
    return 1;
  }
  person=find_player(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  write("You send a pair of guards to take "+person->query_name()+
        " to the dungeon.\n");
  tell_room(environment(person),
    "A pair of guards arrive and take "+person->query_name()+
    " away.\n");
  tell_object(person,
"The guards take you to the Crystal Tower and throw you in a dungeon.\n");
  move_object(person,"/players/feldegast/closed/tower/dungeon");
  return 1;
}

wizzes() {
  object list;
  int i, level, invis;
  string name,ed,tab;
  list = users();
  write("Name"+"\t\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
  write("=======================================\n");
  for(i=0; i <sizeof(list); i++)     {
    name=list[i]->query_name();
    level = list[i]->query_level();
    invis = list[i]->query_invis();
    if(invis>999) {invis = 999;}
    ed = "  ";
    if (in_editor(list[i])){
      ed= "Ed";
    }
    if (level > 19)   {
      write(name[0..10]+"\t\t"+level+"\t"+invis+"\t"+ed+"\n"); }
  }
  return 1;
}


/* Exits */
teleport(str) {
  string dest;
  if(!str) {
    write(
"You may teleport to: church, post, portal, shrine, beach, arena\n"+
"                     city, cottage, trix\n"
    );
    return 1;
  }
  if(locked) {
    write("You bounce off of the blue portal.\n");
    say(TPN+" bounches off of the blue portal.\n");
    return 1;
  }
  switch(str) {
    case "church": dest="room/church"; break;
    case "inner": if(TP->query_level()>20) { 
                    dest="room/adv_inner"; 
                    break;
                  }
    case "post": dest="room/post"; break;
    case "portal": dest="players/saber/ryllian/portal";break;
    case "shrine": dest="/players/feldegast/shrine";break;
    case "arena": dest="players/feldegast/arena/rooms/foyer";break;
    case "beach": dest="players/feldegast/island/beach1";break;    
    case "city": dest="/players/feldegast/movies/DarkCity/street2";break;
    case "cottage": dest="/players/feldegast/realm/cottage1";break;
    case "trix": dest="/players/trix/castle/center.c";break;
    case "guild": dest = "/players/feldegast/healers/rooms/hall"; break;
    case "healers": dest="/players/mythos/healerguild/room/hall.c"; break;
   case "crypt": dest="/players/wocket/necro/room/necro2.c"; break;
    case "assembly": if (this_player()->query_real_name()=="feldegast") {
                       dest="players/mythos/closed/guild/assembly";
                       break;
                     }
    default: write("That destination isn't available to you.\n");
             return 1;
             break;
  }
  write("You step through the "+HIB+"azure"+NORM+" portal and think,'"+str+"' to yourself.\n");
  this_player()->move_player("through the "+HIB+"azure portal"+NORM+"#"+dest);
  return 1;
}
