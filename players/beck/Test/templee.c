inherit "room/room";

#include "/players/dragnar/std/std.h"
#define TIME 200

int Present;     /* Is Shang here? */
object Quest;    /* The MK invitation */
object Who;      /* Person requesting to be in the tournament */
status Struck;   /* Can only strike gong every 2 mins */

init() {
	::init();
	add_action("strike","strike");
	add_action("Look","look");
	add_action("Kill","kill");
  add_action("Out","out");
	this_player()->set_fight_area();
	enable_commands();
}
reset(arg) {
	if(arg) return;
set_light(1);
call_out("HB",random(TIME));
short_desc=("Temple of Mortal Kombat");
long_desc=
"You enter the temple and notice that it is lighted by torches on the wall.\n" +
"This room seems to be small, even though the temple looked huge from\n" +
"the outside. In the center of the room is a large depression in the floor.\n"+
"Within the depression a gong sits on a type of table.\n",

items=
({"torches","Simple wooden torches held in place by an iron clamp",
"torch","A simple wooden torch held in place by an iron clamp",
"depression","It seems to be an outline of a symbol, but it not familiar to you",
"table","It is actually part of the floor, and on a second look seems to be an\n"+
   "altar.  There seems to be a type of mallet laying on the altar you did\n"+
   "not notice before",
"mallet","It has a wooden handle, and is padded on both ends.  The mallet must be\n"+
   "used to 'strike' the gong, and the padding protects the malleable gold", 
"gong","A gold, metal disk that sparkles in the light of the torches.  For some\n"+
   "reason, the sight of it causes pure fear to grab hold of your heart",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/island2.c","out",
});
}


HB() {
  tell_room(this_object(), "The flickering of the light makes your shadow dance on the wall.\n");
  call_out("HB",random(TIME));
}

strike(string str) {
  Who = this_player();
  if(!str) return 0;
  if(str == "gong") {
    Quest = present("mkquest", this_player());
    if(!Quest || Struck) {
      write("You hit the gong, but for some reason no sound is produced.\n");
      say(CAP+" hits the gong, but it doesn't make a sound.\n", this_player());
	  return 1;
	}
    write("You strike the gong with the mallet, and a loud sonorous tone\n"+
      "fills the temple.");
    say(CAP+" strikes the gong with the mallet, and a loud sonorous tone\n"+
      "fills the temple.", this_player());
    Struck = 1;
    TR(TO, "  The sound fills your head and chills your heart.\n");
    call_out("Message",6,0);
     call_out("ResetStruck",120);
    return 1;
  }
}

Look(string str) {
  if(str == "at shang" || str == "at Shang" || str == "at Shang Tsung" 
    || str == "at shang tsung") {
	if(Present) {
	  write("He seems to be an old man, about 700 years old.  He has not been\n"+
        "defeated in his 500 years as champion of Mortal Kombat.  Even Goro\n"+
        "bows to the master.  If you defeat him you will be crowned the victor.\n");
	  return 1;
	}
  }
}

Kill(string str) {
  if(str == "shang" || str == "Shang" || str == "Shang Tsung" 
                    || str == "shang tsung") {
    if(Present) {
	  write("You may only defeat Shang Tsung in Mortal Kombat.\n");
	  return 1;
	}
  }
}

Out() {
  if(Present) {
    write("The presence of Shang Tsung keeps you from leaving the temple.\n");
    return 1;
  }
}
Message(int x) {
  switch(x) {
  case 0:
    TR(TO, "\nThe sound of the gong finially stops resonating in the temple.\n");
	call_out("Message",random(6)+2,1);
    break;
  case 1:
	TR(TO, "\nThere is a bright flash of light.  Shang Tsung has arrived.\n");
	Present = 1;
	call_out("Message",random(6)+2,2);
    break;
  case 2:
    tell_object(Who, "\nShang Tsung says: I see you have an invitation to the tournament.\n"+
	  "Say your code, and I shall grant you the right to enter Mortal Kombat.\n");
    call_out("TimeOut",60);
    break;
  case 3:
    tell_object(Who, "\nShang Tsung says: You do not have the correct Code, and I will not let you\n"+
    " enter the tournament until you have proven yourself worthy.\n");
	call_out("Message",random(6)+2,4);
	break;
  case 4:
    TR(TO, "\nThere is a bright flash of light.  Once your eyes adjust to the darkness\n"+
      "you see that Shang Tsung is gone.\n");
	Present = 0;
	break;
  }
}

catch_tell(string str) {
  string who,what,junk;
  string *List;
  int i;
  
  if(!Who || !Quest) return;
  if(sscanf(str, "%s says: %s\n",who, what) == 2) {
    remove_call_out("TimeOut");
    List = Quest->QQuestKey();
	junk = "";
	for(i=0; i < sizeof(List); i++) {
	  junk += List[i];
	  if(i != sizeof(List)-1) junk += " ";
	}
	if(who == (string) Who->query_name() && what == junk && Present) {
	  if(sizeof(List) < 20) {
        call_out("Message",2,3);
	    return 1;
	  }
	  call_out("Approval",2);         
    return 1;
    }
  else {
    if(who == (string) Who->query_name() && Present) {
    write("Did not match:\n"+
    "Code: "+junk+"\n"+
    "You said: "+what+"\n");
  }
  }
  }
}

Approval() {
  if(!Who) return;
  if(!Quest) return;
  tell_object(Who, "Shang Tsung says: I give you approval to enter the tournament.\n");
  move_object(clone_object("players/dragnar/MKScar/scar.c"), Who);
  Quest->QuestOver();
  destruct(Quest);
  Who = 0;
  Quest = 0;
  Struck = 0;
  call_out("Message",2,4);
}
ResetStruck() {
  Struck = 0;
  Who = 0;
  Quest = 0;
}
  
TimeOut() {
  Message(4);
}
