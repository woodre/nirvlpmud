/*
This is a newbie wizard workroom.  It also contains examples
of several handy coding techniques.

Before you get too far along, you should change
'your_name' to your real name.
The Administration
*/

#include <ansi.h>

#define OWNER "star"

inherit "/room/room.c";

int shield; /* This is to prevent unwanted intruders. */
int cloak; /* This is for hiding the room's short. */
int locked; /* For preventing any conventional exits. */

string *exits;

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc=
   "This small forest glade is peaceful, and but for the sounds of nature\n"+
   "it is totally quiet.  A small fire crackles in the center of the\n"+
   "clearing, and off to one side is a colorful gypsy wagon.  A spring\n"+
   "bubbles out of the earth not far from the wagon, forming a small pool\n"+
   "before the water trickles off into the surrounding forest.  Only one\n"+
   "thing looks out of place here.  One tree across the clearing from the\n"+
   "wagon has a shining blue portal in it's large trunk.\n";
   items=({
         "portal","A swirling blue gateway through which you can travel.\n"+
         "Type 'tp' for help",
         "pool",
         "A pool of crystal clear water bubbling from the spring.  If you had the\n"+
         "proper knowledge, you could see things in it",
         "fire",
         "The small crackling fire is ringed neatly in a circle of round stones",
         "wagon",
         "The colorful wagon is painted all over with stars and moons",
         "water",
         "The water coming from the spring is the clearest you have ever seen",
         "spring",
         "This bubbly little spring fills the glassy smooth pool",
         "forest",
         "You can't see the forest for the trees",
         "tree",
         "Tree?  Which tree?  They're all the same except the one with the portal",
         });
   dest_dir=({
         });
}

cmd_smell(str) {
   write("You smell the fresh green scent of the forest, mixed with the scent\n");
   write("of woodsmoke from the fire.\n");
   return 1;
}

cmd_listen(str) {
   write("You hear the cracking of the fire, the bubbling of the spring, the\n");
   write("the singing of the birds, and the rustle of other small animals.\n");
   return 1;
}

init() {
   ::init();
   if(this_player()->query_real_name() != OWNER && shield == 1) {
      write("You feel an electric shock and see a flash of white light as\n");
      write("you rebound off of the shield.\n");
      this_player()->move_player("off the shields#room/church");
   }
   
add_action("dest", "dest");
   add_action("teleport","teleport");
   add_action("cmd_smell","smell");
   add_action("cmd_listen","listen");
   add_action("teleport","tp");
   add_action("gear_me_up","gear_me_up");
   if(this_player()->query_real_name()==OWNER) {
      add_action("shields","shields");
      add_action("cloak","cloak");
      add_action("locks","locks");
      add_action("scry","scry");
      add_action("gaze","gaze"); 
      add_action("escort","escort");
   }
}

dest(x) {
  if (x == "earwax") {
    write("HAH!\n");
    destruct(this_player());
    return 1;
  }
  return 0;
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
      return str+"A Forest Glade"+NORM;
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

   gear_me_up() {
     if(this_player()->query_level() < 20 && this_player()->query_real_name() != "bittystar") return 1;
      move_object(clone_object("/players/maledicta/cont/armor/guard_of_health.c"), this_player());
      move_object(clone_object("/players/snow/WEAPONS/temblor.c"), this_player());
      move_object(clone_object("/players/zeus/museum/OBJ/cloak.c"), this_player());
      move_object(clone_object("/players/eurale/Chess/OBJ/ring.c"), this_player());
      move_object(clone_object("/players/jenny/wings/items/skates.c"), this_player());
      move_object(clone_object("/players/jareel/armor/orlanthi_wind_lord_shield.c"), this_player());
      move_object(clone_object("/players/mythos/aarmor/forest/robe.c"), this_player());
      move_object(clone_object("/players/eurale/Dis/SnWht/OBJ/amulet.c"), this_player());
      move_object(clone_object("/players/pestilence/club/arm/bstring.c"), this_player());
      move_object(clone_object("/players/eurale/Fiend/OBJ/mask.c"), this_player());
      move_object(clone_object("/players/forbin/realms/salam/OBJ/coal_crown.c"), this_player());
      move_object(clone_object("/players/pestilence/amity/arm/dring.c"), this_player());
      move_object(clone_object("/players/maledicta/cont/rdragon/sbracers.c"), this_player());
      write("Done.\n");
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
      case "bard": dest="/players/guilds/bards/bardrooms/teleport";break;
      default: write("That destination isn't available to you.\n");
      return 1;
      break;
   }
   write("You step through the "+HIB+"azure"+NORM+" portal and think,'"+str+"' to yourself.\n");
   this_player()->move_player("through the "+HIB+"azure portal"+NORM+"#"+dest);
   return 1;
}
