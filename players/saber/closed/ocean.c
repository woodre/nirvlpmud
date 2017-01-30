#define tp this_player()->query_name()
#define CAP capitalize(str)

inherit "room/room";

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int t, shield, NUMBER, wave_check, wave_yes;
string WAVES;

reset(int arg){

if(!arg){
  set_light(1);
  short_desc="Inside the Sunset";
  long_desc=
"\n"+
""+HIY+"       "+HBBLU+"       .                    .                 .             "+NORM+"\n"+
""+HIY+"       "+HBBLU+"                                                       .    "+NORM+"\n"+
""+HIY+"       "+HBBLU+"                .       "+HBYEL+" "+BRED+"    "+HBYEL+"   "+HBBLU+"             .              "+NORM+"\n"+
""+HIY+"       "+HBBLU+"                     "+HBYEL+" "+BRED+"          "+HBYEL+" "+HBBLU+"                           "+NORM+"\n"+
""+HIY+"       "+HBBLU+"    .               "+HBYEL+" "+BRED+"            "+HBYEL+" "+HBBLU+" .                        "+NORM+"\n"+
""+HIY+"       "+HBBLU+"                  "+HBYEL+"  "+HBRED+"               "+HBYEL+"  "+HBBLU+"                  .    "+NORM+"\n"+
"       "+HBCYN+"              "+BMAG+"      "+HBRED+" "+HBMAG+" "+HBRED+" "+HBMAG+" "+HBRED+"        "+HBMAG+" "+HBRED+" "+BMAG+"            "+HBCYN+"              "+NORM+"\n"+
"       "+HBCYN+"           "+HBMAG+"          "+BRED+"         "+HBMAG+" "+HBRED+"  "+BMAG+"               "+HBCYN+"            "+NORM+"\n"+
"       "+HBCYN+"            "+HBMAG+"          "+BRED+"  "+HBMAG+" "+HBRED+"     "+BMAG+"  "+BRED+" "+BMAG+"         "+HBMAG+"      "+BCYN+"            "+NORM+"\n"+
"       "+HBCYN+"            "+HBMAG+"          "+BMAG+"     "+BRED+" "+BMAG+"                       "+HBCYN+"         "+NORM+"\n"+
"       "+HBCYN+"                 "+HBMAG+"                              "+HBCYN+"             "+NORM+"\n"+
"You are in a small cove.  In the distance is the eternally setting sun.\n"+
"The air is warm and gentle against your skin.\n";

items=({
 "cove","You're in a small cove",
 "sun","You shouldn't stare directly into the sun",
 "sunset","You have never seen a sunset so beautiful",
 "air","The air is warm and gentle against your skin",
 "water","The ocean looks warm and inviting.\n"+
         "You could <dive> in, <walk> in or simply <wade> in the water.\n"+
         "You can also <splash> somebody, or <bathe> in the ocean", 
 });

  dest_dir=({
 "/players/saber/workroom.c","leave",
           });
} }

init(){
 ::init();
  add_action("search","search");
  add_action("dive_in","dive");
  add_action("walk_in","walk");
  add_action("wade_in","wade");
  add_action("splash","splash");
  add_action("bathe","bathe");
  add_action("on","ON");
  add_action("off","OFF");
  add_action("waves","waves");
  
if(this_player()->query_real_name() !="saber" && shield == 1) {
 write("You get the faint image of a stunning sunset as\n");
 write("you rebound off of a circle of warding.\n");
 this_player()->move_player("off the shields#room/church");
}
}

static on() {
   shield = 1;
   write("Circle of warding activated.\n");
   return 1;
}

static off() {
   if (call_other(this_player(), "query_real_name", 0) !="saber") {
   write("You have not yet aquired the power to raise the circle of warding.\n");
   return 1;
   }
  shield = 0;
  write("Circle of Warding removed.\n");
  return 1;
   }

search() {
  write("You find lots of sand!\n");
  say(tp+" searches the area.\n");
  return 1;  
         }
         
dive_in() {
  write("You dive into the ocean and begin to swim around.\n"+
        "The warm water feels good against your skin.\n");
  say(tp+" dives into the ocean and begins to swim around.\n");
 return 1;  }
 
walk_in() {
  write("You slowly walk into the ocean.\n"+
        "The warm water feels good against your skin.\n");
 say(tp+" walks slowly into the ocean.\n");
return 1;   }

wade_in() {
  write("You wade knee deep into the ocean.\n"+
        "The warm water feels good against your feet.\n");
  say(tp+" wades knee deep into the ocean.\n");
 return 1;  }

splash(str) {
object ob;
string PLACE, PLACE2;
int WHERE;
if(!str)  {
  write("You splash about in the ocean.\n"+
        "Hay, this is fun!\n");
  say(tp+" splashes about in the ocean.\n"+
        "That looks like fun.\n");
  return 1;
         }
  if(!(ob = present(str), environment(this_player())))  {
    write(CAP+" is not here to splash...\n");
    return 1;
         } 
  WHERE = random(5);
    if(WHERE == 0)  {  PLACE  = " in the face.";                PLACE2 = PLACE;  }
    if(WHERE == 1)  {  PLACE  = " with a huge wave of water.";  PLACE2 = PLACE;  }
    if(WHERE == 2)  {  PLACE  = " many times.";                 PLACE2 = PLACE;  }
    if(WHERE == 3)  {  PLACE  = " several times and then dunks "+ob->query_objective()+".";
                       PLACE2 = " several times and then dunks you.";  }
    if(WHERE == 4)  {  PLACE  = ", sending water everywhere!";  PLACE2 = PLACE;  }
  write("You splash "+CAP+""+PLACE+"\n");
  say(tp+" splashes "+CAP+""+PLACE+"\n", ob);
  tell_object(ob,
      tp+" splashes you"+PLACE2+"\n");
 return 1;  }
 
bathe(str)  {
object ob;
if(!str)  {
  write("You strip off your clothing and begin to bathe in the ocean!\n"+
        "The water feels wonderful against your skin.\n");
  say(tp+" strips off "+this_player()->query_possessive()+" clothing and begins to"+
      " bath "+this_player()->query_objective()+" in the ocean.\n"+
        "Yow!\n");
  return 1;
         }
  if(!(ob = present(str), environment(this_player())))  {
    write(CAP+" is not here to bathe...\n");
    return 1;
         } 
  write("You grab "+CAP+", dunk "+ob->query_objective()+" in the ocean and begin to "+
        "bathe "+ob->query_objective()+".\n");
  say(tp+" grabs "+CAP+", dunks "+ob->query_objective()+" in the ocean and begins to "+
        "bathe "+ob->query_objective()+".\n", ob);
  tell_object(ob,
      tp+" grabs you, dunks you in the ocean and begins to bathe you!\n");
 return 1;  }
 
 waves()  {
   if(wave_yes > 0)  {
     wave_yes = 0;
     remove_call_out("wave_check");
     write("The waves have stopped.\n");
     return 1;
         }
   wave_check = 1;
   write("You hear the surf crash upon the shore.\n");
   call_out("wave_check",random(20));
   return 1;
         }
         
wave_check()  {
  NUMBER = random(4);
  if(NUMBER == 0) WAVES = "The warm ocean wind blows gently against your skin";
  if(NUMBER == 1) WAVES = "The waves crash gently against the beach";
  if(NUMBER == 2) WAVES = "The low, rhythmic roar of the surf fills your ears";
  if(NUMBER == 3) WAVES = "The ocean water shimmers under the setting sun";
  tell_room(this_object(),
    "\n"+WAVES+".\n\n");
  call_out("wave_check", 100 + random(75));
  return 1;
         }
