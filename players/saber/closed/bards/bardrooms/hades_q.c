#define tp this_player()->query_name()
#define ACE find_living("rizrakah")
#define ROM tell_room(environment(ACE), "\nDemon speaks:\n 
#define ROM2 tell_room(environment(ACE), "\nCrysea whispers:\n
#define ROM3 tell_room(environment(ACE), "\nCrysea whispers to you:\n
inherit "room/room";
int t, count, count2, count3, check_it;
object ob2, GAG;
string NAME, GENDER;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Hades Circle";
long_desc=
"You stand in a chamber of flames.  The burning walls around you shimmer with\n"+
"bright crimson tongues of fire, breathing out smoke in what seems the rhythm\n"+
"of a perverse heart beat.  In the center of the chamber is an inverted black\n"+
"pentagram.\n";

items=({
 "chamber","You stand in Hades Circle",
 "walls","The walls of the chamber are made of fire",
 "fire","Fires rage throughout the room",
 "smoke","The room is full of smoke",
 "pentagram","There is an inverted black pentagram is the middle of the chamber",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/teleport.c","out",
           });

  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("block","bte");
  add_action("block","bt");
  add_action("block","bsing");
  add_action("block","bising");
  add_action("block","word");
  add_action("block","tell");
  add_action("new_say","say");
  add_action("new_say","'");
  add_action("new_say",";");
   add_action("stop_it","stop");
   add_action("begin","begin");
   add_action("end_it_it","truename");
}

block()  {
  write("You cannot do that here...\n");
  return 1;
        }

end_it_it()  {
  ROM \"\CHECK ONE\"\n");
  ob2->set_bard_level("9");
  ROM \"\CHECK FIRST\"\n");
  command("true_name demon", this_player());
  ROM \"\CHECK TWO\"\n");
  destruct(ACE);
  destruct(GAG);
  call_out("finish",5);
  remove_call_out("e3");
  remove_call_out("oh_oh");
  return 1;
        }

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

begin()  {
object ob;
ob2 = present("instrument",this_player());
 NAME = this_player()->query_name();
 GENDER = this_player()->query_objective();
if(count < 1)  {
count = count + 1;
move_object(clone_object("/players/saber/monsters/demon_q.c"),environment(this_player()));
call_out("intro",3);
return 1;
         }
         }

intro()  {
 tell_room(environment(ACE),
   "\nAn evil looking Demon with dark wings steps from the flames.\n\n");
 call_out("intro2",2); return 1;  }

intro2()  {
 ROM \"\Gotcha...\"\n");
call_out("a1",3); return 1;  }

a1()  {
 ROM \"\Saber's not in right now mortal, so it looks like you're going\n"+
    "   to have to deal with me...\"\n");
call_out("a2",5);  return 1;  }

a2()  {
 ROM \"\Now, as I see it, you want to know the Words of Power.\"\n"+
  "  \"\I just happen to know them....but I'm not so sure that I\n"+
  "   want to teach you.\"\n");
call_out("a3",8);  return 1;  }

a3()  {
 ROM \"\Lets see here...\"\n");
 tell_room(environment(ACE), "\nThe Demon thinks.\n\n");
 ROM \"\Ahhh...I know.  I'll test your puny little mortal virtues.\"\n");
call_out("a4",6);  return 1;  }

a4()  {
 ROM \"\Lets see if you have courage, mortal scum.\n"+
  "   I'm going to hurt you.  All that you have to do is <say stop>\n"+
  "   and I will stop.\"\n");
call_out("a5",7);  return 1;  }

a5()  {
 ROM \"\But that is the way of the coward.\n"+
   "   I want to see if you have the courage to withstand my powers...\"\n");
call_out("a6",5);  return 1;  }

a6()  {
 tell_room(environment(ACE), "\nA pale sphere of light floats into the chamber.\n"+
   "\nThe sphere materializes into the goddess Crysea.\n\n");
 tell_room(environment(ACE), "The Demon blinks.\n\n");
call_out("a7",8);  return 1;  }

a7()  {
 ROM \"\What are you doing here Cyrsea?  This mortal is MINE\"\n");
 ROM2 \"\I am here to ensure that this is a fair contest.\"\n");
call_out("a8",6);  return 1;  }

a8()  {
 ROM \"\Fair?  Fair?  This contest will be no such thing.\n"+
  "   I am going to hurt "+NAME+" here.  I am going to make "+GENDER+"\n"+
  "   scream for mercy.\"\n");
call_out("a9",7);  return 1;  }

a9()  {
 tell_room(environment(ACE), "\nCrysea glares at the Demon.\n\n");
 ROM2 \"\Well, I am here to make sure that you do not kill "+GENDER+".\n"+
  "   By the rules of this contest you may do anything else that you\n"+
  "   like to "+GENDER+", but you may NOT kill "+GENDER+".\"\n");
call_out("b1",8);  return 1;  }

b1()  {
 ROM2 \"\ "+NAME+", the rules of this contest are simple.\n"+
  "   You loose the contest by <say>ing <stop>.  All that you have to do\n"+
  "   is <say> <stop>.  This will restore you to the way you were before\n"+
  "   the start of this contest.\"\n");
call_out("b2",7);  return 1;  }

b2()  {
 ROM2 \"\You must make it through without saying stop to win.\"\n");
call_out("b3",4);  return 1;  }

b3()  {
 ROM \"\Enough of this talk.  I want some action.\"\n");
 ROM3 \"\Courage "+NAME+".\"\n");
call_out("b4",4);  return 1;  }

b4()  {
 tell_room(environment(ACE), "The Demon binds you in Crimson Magic.\n\n");
 GAG = clone_object("/players/saber/closed/ngag.c");
  move_object(GAG,environment(ob2));
call_out("b5",4);  return 1;  }

b5()  {
 ROM \"\Much better...\"\n");
 tell_room(environment(ACE), "\nThe Demon slaps you.\n");
 ROM \"\ Oh, a spirited little thing, aren't you...\n"+
  "   I think I can fix that.\"\n");
call_out("b6",6);  return 1;  }

b6()  {
tell_room(environment(ACE), "\nThe Demon produces a wicked looking knife.\n\n");
 ROM \"\Now lets see...\"\n");
 tell_room(environment(ACE), "\nThe Demon fingers his knife...\n");
call_out("b7",6);  return 1;  }

b7()  {
 tell_room(environment(ACE), "\nThe Demon stabs you in the stomach.\n"+
  "You feel the knife slide through your internal organs.\n"+
  "A chill passes through you.\n\nYou feel ill.\n");
call_out("b8",6);  return 1;  }

b8()  {
 tell_room(environment(ACE), "\nThe Demon cackles wickedly.\n\n"+
  "You begin to bleed.\n\nThe Demon licks the blood off of the knife.\n\n");
call_out("b9",6);  return 1;  }

b9()  {
 tell_room(environment(ACE), "\nYou bleed.\n\n");
call_out("c3",2);  return 1;  }

c1()  {
 tell_room(environment(ACE), "\nThe Demon cackles at you.\n\n");
 ROM \"\Try this than...\"\n");
 tell_room(environment(ACE), "The Demon reaches INTO you and pulls something out.\n\n"+
  "You feel your magic aptitude decrease.\n\n"+
  "Your magic score is now 8.\n\n");
call_out("c2",7);  return 1;  }

c2()  {
tell_room(environment(ACE), "\nThe Demon laughs.\n\n");
 ROM \"\Just say stop.  Give me your soul!!!\"\n");
 ROM2 \"\That is not within your rules.  You have no claim to "+NAME+"'s soul.\"\n");
call_out("c3",6);  return 1;  }

c3()  {
 ROM \"\You're in my realm.  I MAKE the rules.  If "+NAME+" here says\n"+
  "   stop, I release "+GENDER+" unharmed.  But I get to keep "+GENDER+" soul.\"\n");
 ROM3 \"\I will try to protect your soul if I can.\"\n");
 ROM \"\You're MINE "+NAME+".\n\n");
call_out("c4",7);  return 1;  }

c4()  {
 tell_room(environment(ACE), "\nThe Demon laughs.\n\n"+
  "The Demon reaches INTO you and pulls something out.\n\n"+
  "You feel your strength decrease.\n\n"+
  "Your strength is now 8.\n\n");
call_out("c5",7);  return 1;  }

c5()  {
tell_room(environment(ACE), "\nThe Demon howls with laughter.\n\n"+
  "The Demon taunts you \"\Say stop, just say it...\"\n");
 ROM3 \"\Courage "+NAME+".\"\n");
call_out("c6",6);  return 1;  }

c6()  {
 tell_room(environment(ACE), "\nThe Demon yells \"\More more more!!!\"\n"+
  "\nThe Demon reaches INTO you and pulls something out.\n\n"+
  "You feel your stamina decrease.\n\n"+
  "Your stamina is now 8.\n\n"+
  "The demon grins evilly.\n");
call_out("c7",7);  return 1;  }

c7()  {
 ROM \"\ Say stop "+NAME+", say it now or it will get BAD.\"\n");
 tell_room(environment(ACE), "\nCrysea looks worried.\n\n");
call_out("c8",5);  return 1;  }

c8()  {
 ROM \"\Fine than!\"\n");
 tell_room(environment(ACE), "The Demon grins.\n\n"+
  "The Demon grabs you and kisses you.  You feel its slimy tongue probe your mouth.\n\n"+
  "You feel drained.\n\n"+
  "You are now level 14.\n\n"+
  "The Demon laughs.\n");
call_out("c9",7);  return 1;  }

c9()  {
 ROM \"\You taste great "+NAME+".\n"+
  "   Want to stop?\"\n");
call_out("d1",3);  return 1;  }

d1()  {
 ROM \"\No?  Fine than...\"\n");
call_out("d2",3);  return 1;  }

d2()  {
 tell_room(environment(ACE), "\nThe Demon grabs you and pulls you close.\n"+
  "\nYou feel its foul breath warm against your face.\n"+
  "\nThe Demon kisses you deeply as it fondles your chest.\n\n"+
  "You feel drained.\n\n"+
  "You are now level 8.\n\n");
call_out("d3",6);  return 1;  }

d3()  {
 ROM \"\Yum yum yum.\n"+
  "   I want some more...\"\n");
call_out("d4",5);  return 1;  }

d4()  {
 ROM \"\You're mine!\"\n");
 tell_room(environment(ACE),
   "\nThe Demon grabs you and pushes your mouth to his.\n"+
   "\nThe Demon gives you one final kiss.\n\n"+
   "You feel drained.\n\n"+
   "You are now level 1.\n\n");
call_out("d5",8);  return 1;  }

d5()  {
 tell_room(environment(ACE), "\nThe Demon laughs.\n\n");
 ROM \"\An utter novice!\n   How rich!\n"+
  "   How tough are you now "+NAME+"?\nOh, how the mighty have fallen!\"\n");
 ROM3 \"\Courage...\"\n");
call_out("d6",7);  return 1;  }

d6()  {
 ROM \"\Oh, yes, courage "+NAME+".\n"+
  "   Let me do MORE!\n"+
  "   I can't kill you yet, but by all means, let me do more.\n"+
  "   Or do you want me to stop?\"\n");
call_out("d7",5);  return 1;  }

d7()  {
 tell_room(environment(ACE),
 "\n\nThe Demon summons a SOULBLADE.\n\n"+
  "The Demon looks over and you and smiles evilly.\n\n");
call_out("d8",4);  return 1;  }

d8()  {
 ROM \"\I'm hungry.  Time to eat.\"\n\n");
 tell_room(environment(ACE), "Demon wields SOULBLADE.\n\n");
 ROM2 \"\The SOULBLADE?  Demon, you break the rules.\"\n\n");
call_out("d9",5);  return 1;  }

d9()  {
 ROM \"\Rules?  Rules?  Who needs rules?\"\n");
 tell_room(environment(ACE), "\nThe Demon walks over to you.\n\n"+
  "The Demon swings the SOULBLADE.\n\n");
call_out("e1",5);  return 1;  }

e1()  {
 tell_room(environment(ACE),
  "The SOULBLADE bounces off a mystic blue shield inches before you...\n\n");
call_out("e2",3);  return 1;  }

e2()  {
 ROM2 \"\I think not!\"\n\n");
 ROM \"\This is my realm, you can not touch me here Crysea!\"\n\n");
 ROM2 \"\True...but...\"\n\n");
 ROM3 \"\ Say <truename demon>.  Quickly!\"\n\n");
call_out("e3",15);  return 1;  }

e3()  {
 tell_room(environment(ACE),
 "The Demon lifts his SOULBLADE and looks at you.\n\n");
 ROM3 \"\Say <truename demon>.  Say it!!!\"\n\n");
call_out("oh_oh",15); return 1;  }


new_say(str)  {
string temp, temp2;
object OB;

ob2 = present("instrument",this_player());

if(sscanf(str, "%s", temp) == 1)  {
if(temp == "stop")  {
  call_out("bad",1);
  return 1;
        }
        }
        }

bad()  {
 tell_room(environment(ACE), "\nThe demon laughs.\n\n"+
    "Cyrsea shakes her head...\n\n");
  ROM2 \"\We had such high hopes for you, but you have failed...\"\n");
  tell_room(environment(ACE), "\n\nYou are somewhere new...\n\n");
  move_object(environment(ob2),"/players/saber/closed/bards/bardrooms/teleport.c");
  count = 0;
 destruct(GAG);
  return 1;
        }


finish()  {
 tell_object(environment(ob2),
 "\nCrysea whispers:\n"+
 "\"\Very well done "+NAME+".\"\n"+
  "   You have proved your courage today in the face of great danger.\n"+
  "   It is my honor to promote you.\"\n\n");
 tell_object(environment(ob2),
 "\nYou are now Bard Level 9.\n\nCrysea teaches you the WORDS OF POWER.\n\n"+
 "\nCrysea nods, and than is gone.\n\n");
  count = 0;
 return 1;
        }

oh_oh()  {
 tell_room(environment(ACE),
 "\n\nThe Demon smites you with the SOULBLADE.\n\n"+
 "\nEverything goes black.\n\n");
 move_object(environment(ob2),"/players/saber/closed/bards/bardrooms/teleport.c");
 check_it = environment(ob2)->query_hp();
 check_it = check_it - 20;
 environment(ob2)->heal_self(-check_it);
  ob2->set_bard_level("8");
  ob2->set_bard_xp("64000");
  destruct(GAG);
  count = 0;
  return 1;
        }

realm()  { return "NT"; }
