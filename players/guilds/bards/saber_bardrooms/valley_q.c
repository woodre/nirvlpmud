#define tp this_player()->query_name()
#define ACE find_living("GIANT")
#define ROM tell_room(environment(ACE), "\nGiant speaks:\n 
inherit "room/room";
int t, count, count2, count3;
object ob2;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Valley of Rock";
long_desc=
 "You stand in the Valley of Rock, a desolate crevice sunk down into the depths\n"+
 "of the Spine of the Moon.  Above you looms the dull mass towering mountains.\n"+
 "Nature seems to have constructed this valley entirely from loose stones.\n";

items=({
 "valley","You are in the Valley of Rock",
 "mountains","Yout are in the Spine of the Moon",
 "stones","There are a LOT of loose stones about",
 "ground","The ground is covered with loose stones",
 });

  dest_dir=({
 "/players/saber/ryllian/mountain2.c","east",
           });

  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("begin","yell");
  add_action("block","bte");
  add_action("block","bt");
  add_action("block","alt");
  add_action("block","ale");
  add_action("block","succor");
  add_action("block","goportal");
  add_action("block","word");
  add_action("block","tell");
  add_action("new_say","say");
  add_action("new_say","'");
  add_action("new_say",";");
  add_action("check_it","sing");
  add_action("check_it","play");
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
object ob;
  ob = present("instrument",this_player());
  if(!present("instrument",this_player()))  {
    write("You are not a bard!\n");
  return 1;
        }
  if(ob->query_approval() != 6){
    write("You must have approval to do this task.\n");
    return 1;
    }
  if((this_player()->query_level()) < 12)  {
    write("You must be at least lvl 12 to do that.\n");
    return 1;
        }
  if(ob->query_bard_level() !=5)  {
    write("You must be bard level 5 to do that.\n");
  return 1;
        }
if(count < 1)  {
count = count + 1;
move_object(clone_object("/players/saber/monsters/giant_q.c"),environment(this_player()));
call_out("intro",3);
return 1;
         }
         }

intro()  {
 tell_room(environment(ACE),
     "\nA HUGE giant lumbers into view.\n");
 call_out("intro2",2); return 1;  }

intro2()  {
 ROM \"\AARRGGGGG!\n"+
   "  Tell me why I shouldn't pound you into the ground for disturbing me...\"\n");
 call_out("intro3",6);  return 1;  }

intro3()  {
 ROM \"\<Say> what you will give to me, or I shall eat you!\"\n");
  return 1;  }

quest1()  {
 ROM \"\HURMMM.\"\n"+
   "\nThe giant sits down, causing the ground to tremble.\n\n");
  call_out("quest2",5);  return 1;  }

quest2()  {
 ROM \"\I am so very tired.  I wish that this burden could\n"+
   "  be taken from me...\"\n\n");
  call_out("quest3",6);  return 1;  }

quest3()  {
 ROM \"\I wish that I could once again dance.\n"+
   "  I have not danced in so very long...\"\n");
  call_out("quest4",6);  return 1;  }

quest4()  {
 ROM \"\I would like to dance a jig.\"\n");
  call_out("quest5",3);  return 1;  }

quest5()  {
 ROM \"\Minstrel, play me a jig.\"\n");
  return 1;  }

quest6()  {
 tell_room(environment(ACE),
   "The giant begins to dance.\n");
  call_out("quest7",2);  return 1;  }

quest7()  {
 tell_room(environment(ACE),
   "The giant dances.\n");
  call_out("quest8",2);  return 1;  }

quest8()  {
  tell_room(environment(ACE),
   "\nThe giant thunders \"\YES!\"\n"+
   "\"\This is what I need!\"\n");
  call_out("quest9",4);  return 1;  }

quest9()  {
  tell_room(environment(ACE),
   "The giant danced faster and faster.\n\n"+
   "The stones around you begin to shake.\n\n");
  call_out("quest10",4);  return 1;  }

quest10()  {
 tell_room(environment(ACE),
  "The rocks bounce in rythum to the with the giant.\n"+
   "It almost appears the the rocks are dancing...\n\n");
  call_out("quest11",5);  return 1;  }

quest11()  {
 tell_room(environment(ACE),
   "The giant stops dancing and looks at you.\n");
 ROM \"\That was very good.\n"+
   "  But now I am tired.  Play me a song...\"\n");
  call_out("quest12",5);  return 1;  }

quest12()  {
 ROM \"\Sing me a love song...\"\n");
  return 1;  }

quest20()  {
 ROM \"\Ahhh...That is nice...\"\n"+
   "\nThe giant sighs in bliss.\n\n");
  call_out("quest21",5);  return 1;  }

quest21()  {
 tell_room(environment(ACE),
   "The giant begins to cry.\n");
  call_out("quest22",2);  return 1;  }

quest22()  {
 tell_room(environment(ACE),
   "Huge tears stream down the giants face and drip onto the stones.\n\n"+
   "Say, it almost looks like the stones are crying...\n\n");
  call_out("quest23",5);  return 1;  }

quest23()  {
 ROM \"\That was very good!\n"+
   "  You are not just a minstrel!\n\n"+
   "  You are a BARD!!!\n\n");
  call_out("finish",2);  return 1;  }


new_say(str)  {
string temp, temp2;
object OB;

  /* next ln by verte */
   if(!str) return 0;
ob2 = present("instrument",this_player());

if(sscanf(str, "%s", temp) == 1)  {

if(present(temp,this_player()))  {
OB = present(temp,this_player());
if((OB->query_value()) < 500)  {
  tell_room(environment(ACE), "\nThe giant glares at you.\n"+
    "The giant slaps you!\n");
  ROM \"\A "+capitalize(temp)+" is not good enough!\"\n");
  return 1;
        }
destruct(OB);
 ROM \"\Very well, I accept the "+capitalize(temp)+".\n"+
   "  It will make a nice snack.\"\n"+
   "\nThe giant eats the "+capitalize(temp)+".\n\n");
if(count2 == 0)  { 
  correct();
  remove_call_out("quest1");
  call_out("quest1",2);
  return 1;
        }
        }
        }
        }


check_it(str)  {
string temp;

if(!str)  {
    write("Sing what?\n");
    return 1;
        }
if(sscanf(str,"%s",temp) == 1)  {
 if(temp == "jig")  {
if(count2 == 1)  {
  correct();
  tell_room(environment(ACE),  "\nYou play a jig.\n");
    call_out("quest6",2);
    return 1;
        }
        }
if(temp == "love song")  {
if(count2 == 2)  {
  correct();
  tell_room(environment(ACE), "You play a love song.\n");
  call_out("quest20",2);
  return 1;
        }
        }
        }
        }


correct()  {
  count2 = count2 + 1;
        }

finish()  {
 tell_room(environment(ACE),
   "The giant sits down in silent meditation.\n"+
   "\nYour soul feels different...\n"+
   "You feel like...\n\n"+
   "A BARD!!!\n\n");
 destruct(ACE);
  ob2->set_bard_level("6");
  ob2->set_bard_xp("32000");
  return 1;
        }

realm()  { return "NT"; }
