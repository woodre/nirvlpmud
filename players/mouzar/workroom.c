#include "/players/mouzar/misc/roomt.h"
inherit "room/room";
string invader;
string invited;
int alarm;
int secure;
int lock;
 
init(){
  ::init();
    add_action("invite","invite");
    add_action("force","invite!");
    add_action("alarm","alarm");
    add_action("secure","secure");
    add_action("stat","ck");
    add_action("dest","dest");
    add_action("church","church");
    add_action("vampire","vampire");
    add_action("undermouz","undermouz");
  invader = this_player()->query_real_name();
  if (secure == 0 && invader !=invited && invader !="mouzar")  {
   say("ROOM: " + invader + " has bounced off your shields and now is in waiting.\n");
   write("Were you invited?!?...I don't think so!\n");
   write("You are now in Mouzar's Waiting Room.\n");
   transfer(this_player(),  "players/mouzar/waiting");
   return 1;
  }
  if (this_player()->is_invis() > 0 && invader !="mouzar")  {
   this_player()->force_us("vis");
  }
  if(secure == 1 && alarm == 0)  {
     say("ROOM: " + invader + " has entered the room.\n");
     return 1;
  }
  return 1;
}
dest()  {
   if(call_other(this_player(),"query_real_name",0) !="mouzar")  {
     write("ROOM: You may not do that to Mouzar while he is under my protection!\n");
     tell_object("mouzar","ROOM: Someone tried to dest you!\n");
     return 1;  
   }
   return 0;  
}
 
is_castle() { return 1;}
exit() {
  if(alarm == 0)  {
  invader = this_player()->query_real_name();
  say("ROOM: "+invader + " gets the hell out.\n");
  return 1;
  }
  return 1;
}
 
invite(str)  {
  if(!str)  {
  invited = "";
  return 1;
  }
  invited = str;
  write("ROOM: "+invited + " has been invited!\n");
  return 1;
}
 
force(str)  {
  object person;
 
  if(!str)  {
    write("ROOM: You must tell me who!\n");
    return 1;
  }
  person = find_player(str);
  if (!person)
    person = find_living(str);
  if (!person)  {
    write("ROOM: "+str+" isn't on the MUD!\n");
    return 1;
  }
  invited =str;
  tell_object(person,"You are swallowed up by the shadows and taken to Mouzar's Hideout...\n");
  transfer(person,this_object());
  write("ROOM: "+str + " arrives as command\n");
  return 1;
}
 
alarm()  {
 
  if(alarm == 0)  {
    alarm = 1;
    write("ROOM: Alarm off\n");
  return 1;
  }
  alarm = 0;
  write("ROOM: Alarm on\n");
  return 1;
}
undermouz() {
  say(RN +" enters the gate to Mouzar's Undermouz.\n");    
  write("You enter the gate that leads to the Undermouz.\n");
  move_object(ME,"players/mouzar/castle/under/under1");
  command("look",ME);
  return 1;
}
 
church() {
  say(RN +" enters the gate to the church.\n");    
  write("You enter the gate that leads to the church.\n");
  move_object(ME,"room/church");
  command("look",ME);
  return 1;
}
vampire() {
  say(RN +" enters the gate to the Vampire Guild.\n");    
  write("You enter the gate that leads to the Vampire Guild.\n");
  move_object(ME,"players/eurale/VAMPIRES/RMS/vguild_hall");
  command("look",ME);
  return 1;
}
 
secure()  {
  if(secure == 1)  {
    secure = 0;
    write("ROOM: Secure on\n");
    return 1;
  }
 
  secure = 1;
  write("ROOM: Secure off\n");
  return 1;
}
 
stat(str)  {
  if(!str || str != "room")
    return 0;
  if(alarm == 0)
    write("Alarm on\n");
  else
    write("Alarm off\n");
  if(secure == 0)
    write("Room secured\n");
  else
    write("Room open\n");
 
  if(invited == "" || invited == 0)
    write("Nobody is invited into the room\n");
  else
    write(invited + " is invited into the room\n");
  return 1;
}
 
reset(arg) {
object wb;
if(arg) return ;
wb=clone_object("/players/mouzar/misc/wboard");
move_object(wb,this_object());
short_desc="Somewhere Not Here";
long_desc="This is a rather neat room.  There are shelves lining the walls where Mouzar\n"+
          "keeps all of his important books of spells and of creation.  You can smell\n"+
          "incense burning and the sound of The Black Crowes is playing in the background.\n"+
          "Mouzar's desk is placed in front of the only window so that he can keep an\n"+
          "eye on what is happening on Nirvana while he works.  Set up around a fireplace\n"+
          "is a sofa, love seat, and a Lazy-Boy.  There is a staircase going down and some\n"+
          "gateways that will teleport you to:  Church, Vampire, Undermouz.\n";
dest_dir=({"players/mouzar/waiting","down",});
items=({ "shelves" , "There are tons of books here and most of them probally are not all\n"+
                     "all that important.  Some are about adventures that have taken place\n"+
                     "here on Nirvana.  Some are about adventurers, adventuresses, and wizzes.\n"+
                     "You see one that is a dark red with gold trim labeled 'The Tales of\n"+
                     "Grimm'.  Others are on magic and monsters",
         "books" , "There are books of all colors, sizes, and languages.  You see out some\n"+
                   "that are in a language that you can read: Adventures of Mouzar, Doings of\n"+
		   "Grimm, Life as a Doppleganger, How to Kill Monks, A Crazy Wiz Named Scooter,\n"+
		   "The Younger Days of Nirvana,  The God Named Sandman,  The Days of Sheep\n"+
		   "and Strange Noises,  The Old Vampires, The Legacy of Sweetness, The rise\n"+
		   "and Fall of Hawkeye The Great Cut & Paste Master, Nights with Persephone,\n"+
                   "The Greatly Loved Bagera, Mizan The King Of Jello, Poppy The Famed Player,\n"+
		   "The Man Saber.  Those are just a few that catch your eyes.  There are many\n"+
                   "other that are in a language other than the ones you can read",
         "desk" , "This desk looks as though it has been here many years.  There are papers\n"+
                  "neatly arranged upon it.  There is a feather pen sitting in a little\n"+
                  "jar of ink always ready to write down a new spell, monster, or event\n"+
                  "that needs to be recorded.  You see a crystal ball sitting on the side\n"+
		  "of the desk to see far off lands",
         "crystal ball" , "As you gaze into the crystal ball you see a far off forest where\n"+
         		  "trees grow tall and proud, flowers litter the forest floor, lakes\n"+
			  "and streams are crystal blue, and unicorns roam free from harm",
         "papers" , "The hand writing on these papers seem to move with a life of their\n"+
                    "own making it totally unreadable to untrained eyes",
         "gateways" , "The gateways line the west wall of Mouzar's Workroom.  They are a\n"+
                      "deep blue in color and put off a slight humming noise",
         "window" , "As you peer out the window the view of Nirvana just leaves you in awe.\n"+
                    "You can see everything from this view point high on a dark mountain\n"+
                    "range.  You can see volcanos, forests, castles, unexplored places, and\n"+
                    "adventure",
         "staircase" , "A spiral staircase leading down into Mouzar's Waiting Room",
         "love seat" , "A black love seat with huge fluffy cushions waiting for a\n"+
		       "for a loving couple to plop down on them",
         "sofa" , "An inviting black sofa with fluffy cusions.  Looks like it has\n"+
		  "been broken in a little by a lazy wiz that lives here",
	 "lazy-boy" , "A Black lazy-boy waiting for a tired adventurer to put his\n"+
		      "or her feet up on it and get some well deserved rest"});
set_light(1);
}
