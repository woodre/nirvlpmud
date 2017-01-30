#define tp this_player()->query_name()
#define ACE find_living("selsase")
#define ROM tell_room(environment(ACE), "\nSelsase whispers:\n 
inherit "room/room";
int t, count, count2, count3;
object ob2;
reset(int arg){
if(!present("selsase"))  {
move_object(clone_object("/players/saber/closed/bards/selsase.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Mountain Clearing";
long_desc=
 "You stand in a stark clearing of dark rock and stone.  Above you looms the\n"+
 "massive bulk of mountains of the Spine of the Moon, while below you the face\n"+
 "of the mountain descends thousands of feet straight down.  In the center of\n"+
 "the clearing is a small circle of stones.\n";

items=({
 "stars","Softly gleaming stars are visible overhead",
 "mountain","Massive crags of towering rock loom over you",
 "mountains","Massive crags of towering rock loom over you",
 "rock","Massive crags of towering rock loom over you",
 "stone","Massive crags of towreing rock loom over you",
 "clearing","You stand in a clearing",
 "circle","A small circle of stones.  There's something funny about the\n"+
   "way that they have been arranged",
 });

  dest_dir=({
 "/players/saber/ryllian/mountain2.c","west",
           });

  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("begin","begin");
  add_action("block","bte");
  add_action("block","bt");
  add_action("block","word");
  add_action("block","tell");
  add_action("new_say","say");
  add_action("block","alt");
  add_action("block","ale");
  add_action("new_say","'");
  add_action("new_say",";");
  add_action("new_say","answer");
}

block()  {
  write("You cannot do that here...\n");
  return 1;
        }

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

begin()  {
if(!present("selsase"))  {
move_object(clone_object("/players/saber/closed/bards/selsase.c"),this_object());  }
if(count < 1)  {
count = count + 1;
call_out("intro",3);
return 1;
         }
         }

intro()  {
 ROM \"\I am Selsase, once of the Bardic Guild of Ryllian.\n"+
   " I was once master of the flute, and aspired to be Song Master\n"+
   " of the Bards...\"\n");
 call_out("intro2",9); return 1;  }

intro2()  {
 ROM \"\But in my quest for power I lost sight of the true spirit of\n"+
   " the bardic tradition.  I betrayed the Bards Guild, and was slain\n"+
   " in single combat by Harper.\"\n");
 call_out("intro3",9);  return 1;  }

intro3()  {
 ROM \"\As punishment for my betrayal I have been imprisoned within\n"+
   " this circle for stones for the next three hundred years.  It is my\n"+
   " task to test aspiring bards to see if they are worthy.\"\n");
 call_out("intro4",9);  return 1;  }

intro4()  {
 ROM \"\It is not my task to be nice, it is not my position to be kind.\n"+
   " I will ask you a question.  It is your task to respond to my\n"+
   " questions.  If you have studied your lore and are worthy, you\n"+
   " shall have no problems with my questions.\"\n");
 call_out("intro5",9);  return 1;  }

intro5()  {
 ROM \"\If not, than you shall most likely die...\"\n\n");
  ROM \"\Use the action of [answer] to answer my questions.\"\n\n");
  call_out("quest1",9);  return 1;  }

quest1()  {
 ROM \"\You must answer seven questions correctly.  We shall begin\n"+
   "  with an easy one.\"\n");
 ROM \"\I am <what>.  Servant and master am I; servant of the dead,\n"+
   "  and master of the living.  Through me spirits immortal speak\n"+
   "  the messages that make the world weep, and laugh and wonder\n"+
   "  and worship.\"\n");
  call_out("blast",60); call_out("quest2",62);  return 1;  }

quest2()  {
 ROM \"\What is the nickname of the founder of the\n"+
   "  Bards Guild of the city of Ryllian.\"\n");
 call_out("blast",61); call_out("quest3",62);  return 1;  }

quest3()  {
 ROM \"\What is the name of the goddess of the Moon\n"+
   "  who watches over the Bards Guild?\"\n");
 call_out("blast",61); call_out("quest4",60);  return 1;  }

quest4()  {
ROM \"\Who is the goddess of music?\"\n");
 call_out("blast",61); call_out("quest5",60);  return 1;  }

quest5()  {
 ROM \"\What type of soul do I have?\"\n");
 call_out("blast",61); call_out("quest6",60);  return 1;  }

quest6()  {
 ROM \"\What is the color of the day of the Unicorn?\"\n");
 call_out("blast",61); call_out("quest7",60);  return 1;  }

quest7()  {
 ROM \"\What is the day of the musical note G?\"\n");
 call_out("blast",61);  call_out("end_it",63);  return 1;  }

blast()  {
object ob;
string temp;
  count2 = count2 + 1;
  ob = first_inventory(environment(ACE));
  while(ob)  {
    if(living(ob))  {
   temp = ob->query_hp();
   if(temp < 60)  {
    move_object(ob,"/rooms/church");
        }
   ob->hit_player(60);
        }
  ob = next_inventory(ob);
  say("You are blasted by a mental bolt from the ghost.\n");
  return 0;
        }
        }


new_say(str)  {
  ob2 = present("instrument",this_player());
  if(!str) {
    write("Syntax: answer <what>\n");
    return 1;
  }
  if(str == "music" && count2 == 0) {
    correct();
    remove_call_out("quest2");
    call_out("quest2",2);
    return 1;
  }

  if(str == "harper" && count2 == 1)  {
    correct();
    remove_call_out("quest3");
    call_out("quest3",2);
    return 1;
  }

  if(str == "crysea" && count2 == 2)  {
    correct();
    remove_call_out("quest4");
    call_out("quest4",2);
    return 1;
  }
  if(str == "hadinea" && count2 == 3)  {
    correct();
    remove_call_out("quest5");
    call_out("quest5",2);
    return 1;
  }

  if(str == "evil" && count2 == 4)  {
    correct();
    remove_call_out("quest6");
    call_out("quest6",2);
    return 1;
  }
  if(str == "violet" && count2 == 5)  {
    correct();
    remove_call_out("quest7");
    call_out("quest7",2);
    return 1;
  }
  if(str == "dragon" && count2 == 6)  {
    correct();
    remove_call_out("end_it");
    call_out("end_it",2);
    return 1;
  }
  ROM \"\Wrong. Try again.\"\n\n");
  return 1;
}


correct()  {
  count2 = count2 + 1;
  count3 = count3 + 1;
  remove_call_out("blast");
  ROM \"\Correct.\"\n\n");
        }

end_it()  {
  ROM \"\These have been my questions seven, to match the\n"+
     "  seven circles of the bardic tradition.\"\n");
  if(count3 > 6)  {
  ROM \"\You have answered my questions correctly.\n"+
   "  I deem that you are worthy of progressing.\n"+
   "\n  You are now Bard Level 4!\"\n\n");
   call_out("end_it2",4);
  count2 = 0;
  count = 0;
  count3 = 0;
   return 1;
        }
  ROM \"\You have not correctly answered all of my questions.\n"+
   "  I deem that you are not worthy of progressing.\n"+
   "  You must study more before you try again.\"\n\n");
  count2 = 0;
  count = 0;
  count3 = 0;
  destruct(find_living("selsase"));
  return 1;
        }

end_it2()  {
string NAME, abil, tempy;
  ROM \"\You deserve a small rewards.\"\n\n"+
     "Selsase floats gently over and places and ice cold kiss upon your forehead.\n"+
     "Your soul feels strong.\n");
  destruct(find_living("selsase"));
  ob2->set_bard_level("4");
  ob2->set_bard_xp("8000");
  NAME = (environment(ob2)->query_real_name());
  tempy = find_player(NAME)->query_attrib("mag");
  if(tempy < 20)  tempy = tempy + 1;
  abil = find_player(NAME)->set_attrib("mag",tempy);
  count = 0; count3 = 0; count2 = 0;
  return 1;
        }

realm()  { return "NT"; }
