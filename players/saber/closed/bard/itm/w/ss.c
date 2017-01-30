
/*
 *  Songs as a weapon for the Bards of Ryllian.
 *  The wc increases with the Bard Level of the Bard, and requires a constant
 *    expenditure of sp to use its special abilities.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

/*
 *  Max weapon class = 18  (must be bard level 13+)
 *
 *  Max return = 8 (if 20 wil and int), (happens int + wil out of 130)
 *
 *  Special attacks = drain spell points over time - when have enough
 *   for 'spell', they are used.  Use/gain one per attack -> therefore
 *   a 20 sp spell takes 20 turns to cast.  Disadvantage offset slightly
 *   by getting 1 'free' POWER (sp for weapon) ever 30 hb.
 *
 *  Must have summoned storm (30 sp) to use.  If not in storm, lose
 *   POWER points at one per 30 hb.
 *
 *  Must have summoned stormsong (75 sp).
 *
 *  Special spell attacks never do 'killing' damage, therefore it is 
 *   possible to 'waste' POWER points.
 *
 *  Attacks happen over multiple rounds, and once started can't be
 *   stopped.  Therefore possible to waste special attacks if monster
 *   dies in the middle of a sequence.
 *
 *  Max POWER stored = bard level.  Extra gathered after that is wasted.
 *
 *  No automatic special attacks if spell points < 1, even if the Bard
 *   has enough POWER to use it.
 *
 *  Advantage = pay 4 sp for every 5 POWER points.
 *
 */



#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

#define TP this_player()
#define tp this_player()->query_name()
#define TO this_object()
#define ENV environment(this_player())

inherit "obj/weapon.c";

int POWER,        /* Used instead of sp */
    COUNT,        /* For when to use special abilities */
    STORM,        /* Boolean - is there a storm in the area? */
    DOING,        /* Boolean - are we doing a special attack? */
    HURRICANE,    /* Boolean - is there a hurricane going on? */
    AUTO,         /* Boolean - should I do automatic attacks? */
    AUTO_MATCH,   /* Checking the power to see if I do an automatic attack */
    EXTRA,        /* The amount of extra damage done attacking */
    WC,           /* The weapon class of the weapon */
    RETURN,       /* How much damage the weapon returns with a special attack */
    AHP,          /* Attacker's hit points */
    BASE,         /* Base damage done with a special attack */
    DAMAGE,       /* Damage done with a special attack */ 
    MAX;          /* Max POWER that can be stored */
int A, X, Y, Z, V, W;
      
string TYPE,       /* Type of special attack to use */
       MESSAGE,    /* Special attack message */
       ATTACKER,   /* Capitalize attacker    */
       TEMP,       /* Temporary string for message */
       TEMP1, TEMP2, TEMP3, TEMP4, TEMP5, TEMP6;
       
object INSTR, ATTACK;


reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("storm_song");
    set_short();
    set_long("You can't look at a song, now can you?\n");
    set_read("You read into the pattern of the storm and see the meaning"+
             "within the song.\n");
    set_class(4);
    set_weight(0);
    set_value(1);
    set_hit_func(this_object());
    
    call_out("check_storm", 30);
        }


  drop()  { return 1; }
  get()   { return 1; }
  can_put_and_get()  { return 0; }


weapon_hit(attacker)  {
  
  ATTACKER = capitalize(attacker->query_real_name());
  ATTACK = attacker;

if(STORM)  {
   
   if(TP->query_sp() > 1)  { POWER++;    COUNT++; }
   
   if(COUNT > 5)  {
      call_other(TP, "add_spell_point", -4);     
      COUNT = 0;
            
     if(AUTO)  {
      if(POWER > AUTO_MATCH)  { command("storm");  }
               }

          }
         }

  sing();
   
  if(random(130) < RETURN)  {          /* Return = wil + int */ 
    return (RETURN/5); 
        }
        
        }


init()  {
  ::init();
  add_action("attune","attune");
  add_action("storm","storm");
  add_action("a_storm","a_storm");
  add_action("auto_storm","auto_storm");
         }


a_storm(str)  {                     /* A 'cheat' for testing purposes */
int ark;  
    sscanf(str, "%d", ark);  { POWER = ark;  }
    write("POWER now = "+str+".\n");
    return 1;  
        }


attune(str)  {            /* Sets the weapon to the Bard */
object NEW_SONG;
int TEMP_POWER;

INSTR = present("instrument", TP);

  if(TO->query_wear() > 10)  {
    NEW_SONG = clone_object("/players/saber/closed/bard/itm/w/ss.c");
    move_object(NEW_SONG, TP);
    command("attune "+str, TP);
    TEMP_POWER = TO->query_power();
    NEW_SONG->set_power(TEMP_POWER);
    destruct(this_object());
    return 1;
        }
  
  if(!str)  {
    write("No weather type specified, default set to < hail >.\n");
    str = "hail";
        }
  
  if(wielded) {  command("unwield storm_song", TP);  }

  if(str == "hail"   ||  str == "thunder"   ||  str == "lightning"  ||
     str == "wind"   ||  str == "tornado"   ||  str == "hurricane"  ||
     str == "ice")  {
  
  TYPE = str;
  WC = (INSTR->query_bard_level() / 2) + 11; 
    if(WC > 18)  WC = 18; 
  this_object()->set_class(WC);            /*  Weapon class = bard lvl divided by 2 + 11 */
  MAX = INSTR->query_bard_level() * 10;    /*  Max POWER that can be stored        */
  EXTRA = INSTR->query_bard_level() / 7;   /*  Sets the extra damage by level      */
  RETURN = TP->query_attrib("int") + TP->query_attrib("wil");  /*  return damage   */
  BASE = (TP->query_attrib("int") + TP->query_attrib("wil")) / 2;  
                                           /*  Base damage for  special attacks    */

  if(str == "hail")        AUTO_MATCH = 10;
  if(str == "thunder")     AUTO_MATCH = 20;
  if(str == "wind")        AUTO_MATCH = 30;
  if(str == "ice")         AUTO_MATCH = 40;
  if(str == "lightning")   AUTO_MATCH = 50;
  if(str == "hurricane")   AUTO_MATCH = 75;
  if(str == "tornado")     AUTO_MATCH = 100;
  
  write("You merge your consciousness with the storm and begin to sing.\n");
  command("wield storm_song", TP);
  return 1;
  
        }

  write("That is not a viable choice (you typed \""+str+"\")\n");
  write("Syntax: lore attune\n");
  return 1;

        }
        

auto_storm()  {             /* Use special attack automaticially */

  AUTO = 1;
  
  write("You have activated the automatic special attack sequence.\n"+
        "You will automaticially use a "+TYPE+" attack when you\n"+
        "have gathered enough storm mana.\n");
  return 1;
  
        }


check_storm()  {     /*  Check to see if there is a storm  in the area   */
                     /*  Add POWER if there is, subtract if there is not */

 if(!find_object("storm"), environment(ENV))  STORM = 0; else STORM = 1; 
 
 write(BOLD+"]Power["+NORM + HIB + POWER + NORM + BOLD+"]"+NORM+"\n");
 
 if(STORM) POWER++; else POWER--;
 call_out("check_storm", 30);
        
        }
 

storm(str)  {
  
  if(!str)   { str = TYPE; }

  if(!TP->query_attack())  {  
    write("You must be attacking a target before you can 'storm' them.\n");
    return 1;
       }

  if(DOING < 1) {

                        /* what attack to use */

       if(str == "hail"      || str == "1")     hail();
  else if(str == "thunder"   || str == "2")     thunder();
  else if(str == "wind"      || str == "3")     wind();
  else if(str == "ice"       || str == "4")     ice();
  else if(str == "lightning" || str == "5")     lightning();
  else if(str == "hurricane" || str == "6")     hurricane();
  else if(str == "tornado"   || str == "7")     tornado();

  return 1;
  
        }
        }


no_power(str)  {

  write("\nYou don't have enough power to summon "+BOLD+""+(str)+""+NORM+" from the storm.\n\n");
  return 1;
  
        }
         

sing()  {
  
  A = random(7);        V = random(16);        W = random(6); 
  X = random(15);       Y = random(14);        Z = random(16);
  
  if(V == 0)   TEMP4 = "pure";            if(V == 1)   TEMP4 = "dissonant";
  if(V == 2)   TEMP4 = "euphonious";      if(V == 3)   TEMP4 = "disharmonious";
  if(V == 4)   TEMP4 = "harmonic";        if(V == 5)   TEMP4 = "unearthly";
  if(V == 6)   TEMP4 = "melodious";       if(V == 7)   TEMP4 = "ear-splitting";
  if(V == 8)   TEMP4 = "heavenly";        if(V == 9)   TEMP4 = "merciless";
  if(V == 10)  TEMP4 = "euphonic";        if(V == 11)  TEMP4 = "discordant";
  if(V == 12)  TEMP4 = "mellifluous";     if(V == 13)  TEMP4 = "unforgiving";
  if(V == 14)  TEMP4 = "harmonious";      if(V == 15)  TEMP4 = "brutal";
  
  if(W == 0)   TEMP5 = "sound";       if(W == 1)   TEMP5 = "tunes";
  if(W == 2)   TEMP5 = "noise";       if(W == 3)   TEMP5 = "tones";
  if(W == 4)   TEMP5 = "music";       if(W == 5)   TEMP5 = "sound";

  if(X == 0)  { TEMP = "sing";       TEMP1 = "sings ";      }
  if(X == 1)  { TEMP = "warble";     TEMP1 = "warbles ";    }
  if(X == 2)  { TEMP = "chant";      TEMP1 = "chants ";     }
  if(X == 3)  { TEMP = "intone";     TEMP1 = "intones ";    }
  if(X == 4)  { TEMP = "hum";        TEMP1 = "hums ";       }
  if(X == 5)  { TEMP = "shriek";     TEMP1 = "shrieks ";    }
  if(X == 6)  { TEMP = "vocalize";   TEMP1 = "vocalizes ";  }
  if(X == 7)  { TEMP = "descant";    TEMP1 = "descants ";   }
  if(X == 8)  { TEMP = "troll";      TEMP1 = "trolls ";     }
  if(X == 9)  { TEMP = "croon";      TEMP1 = "croons ";     }
  if(X == 10) { TEMP = "roar";       TEMP1 = "roars ";      }
  if(X == 11) { TEMP = "singsong";   TEMP1 = "singsongs ";   }
  if(X == 12) { TEMP = "sing";       TEMP1 = "sings ";      }
  if(X == 13) { TEMP = "cantillate"; TEMP1 = "cantillates "; }
  if(X == 14) { TEMP = "lull";       TEMP1 = "lulls ";       }

  if(A == 0)   TEMP6 = "A";          if(A == 1)  TEMP6 = "B";
  if(A == 2)   TEMP6 = "C";          if(A == 3)  TEMP6 = "D";
  if(A == 4)   TEMP6 = "E";          if(A == 5)  TEMP6 = "F";
  if(A == 6)   TEMP6 = "G";
  
  if(Y == 0)   TEMP2 = " harsh "+TEMP6+" minor scale";       
  if(Y == 1)   TEMP2 = " quick "+TEMP6+" minor scale";
  if(Y == 2)   TEMP2 = " sharp "+TEMP6+" 5th scale";      
  if(Y == 3)   TEMP2 = " series of high "+TEMP6+"'s";
  if(Y == 4)   TEMP2 = " series of low "+TEMP6+"'s";        
  if(Y == 5)   TEMP2 = " low "+TEMP6;
  if(Y == 6)   TEMP2 = " high "+TEMP6;   
  if(Y == 7)   TEMP2 = "n intense "+TEMP6+" 7th scale";
  if(Y == 8)   TEMP2 = " low "+TEMP6+" scale";      
  if(Y == 9)   TEMP2 = " high "+TEMP6+" scale";
  if(Y == 10)  TEMP2 = "n augmented "+TEMP6+" scale";       
  if(Y == 11)  TEMP2 = "n inspired "+TEMP6+" 9th scale";
  if(Y == 12)  TEMP2 = " diminished "+TEMP6+" scale";
  if(Y == 13)  TEMP2 = " single "+TEMP6+" note";

  if(Z == 0)   TEMP3 = "blasting";       if(Z == 1)   TEMP3 = "mesmerizing";
  if(Z == 2)   TEMP3 = "stunning";       if(Z == 3)   TEMP3 = "entrancing";
  if(Z == 4)   TEMP3 = "enthralling";    if(Z == 5)   TEMP3 = "slamming";
  if(Z == 6)   TEMP3 = "smothering";     if(Z == 7)   TEMP3 = "paralyzing";
  if(Z == 8)   TEMP3 = "dazzling";       if(Z == 9)   TEMP3 = "dazing";
  if(Z == 10)  TEMP3 = "engulfing";      if(Z == 11)  TEMP3 = "lambasting";
  if(Z == 12)  TEMP3 = "smashing";       if(Z == 13)  TEMP3 = "hammering";
  if(Z == 14)  TEMP3 = "buffeting";      if(Z == 15)  TEMP3 = "battering";

  write("You "+TEMP+" a"+TEMP2+", "+TEMP3+" "+ATTACKER+" with "+TEMP4+" "+TEMP5+".\n");
  say(tp+" "+TEMP1+"a"+TEMP2+", "+TEMP3+" "+ATTACKER+" with "+TEMP4+" "+TEMP5+".\n");
  
        }
        
  
 /* BASE = int + wil /2 = 20 (All special attacks assume a 20 int and 20 wil) */
 
 /* BASE/4 (5) + d10 for 10 POWER points */

hail()  {

  if(POWER < 10) { no_power("Hail");  return 1; }
  
  DAMAGE = (BASE/4) + (random(10+1));
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  
  
  X = random(4);  Y = random(4);  Z = random(4);  V = random(2);
 
  if(X == 0) TEMP = "Huge chunks";    if(X == 1) TEMP = "Large stones";
  if(X == 2) TEMP = "Sharp rocks";    if(X == 3) TEMP = "Jagged chips";

  if(Y == 0) TEMP1 = "fall from the sky, ";    if(Y == 1) TEMP1 = "plummet from above, ";
  if(Y == 2) TEMP1 = "rain from the storm, ";  if(Y == 3) TEMP1 = "fall from the clouds, ";

  if(Z == 0) TEMP2 = "smashing ";         if(Z == 1) TEMP2 = "slaming ";
  if(Z == 2) TEMP2 = "crushing ";         if(Z == 3) TEMP2 = "knocking ";  

  if(V == 0) TEMP3 = " to the ground";     if(V == 1) TEMP3 = " with deadly force";

   MESSAGE = TEMP+" of hail "+TEMP1 + TEMP2 + ATTACKER + TEMP3;
  
  tell_room(ENV, "\n"+MESSAGE+".\n\n");
  
  POWER = POWER - 10;
  return 1;
  
        }


 /* BASE/2 (10) + d10 and miss next attack or 2 for 20 POWER points */

thunder() {

  if(POWER < 20) { no_power("Thunder");  return 1; }
  
  DAMAGE = (BASE/2) + (random(10)+1);   
 
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  
  ATTACK->hit_player(DAMAGE);

  X = random(4);  Y = random(4);
 
  if(X == 0) TEMP = "Raging";     if(X == 1) TEMP = "Crashing";
  if(X == 2) TEMP = "Deafening";  if(X == 3) TEMP = "Booming";

  if(Y == 0) TEMP1 = " staggers backwards, flailing wildly";     
  if(Y == 1) TEMP1 = " falls to the ground, dazed and confused";
  if(Y == 2) TEMP1 = " is knocked back a step, stunned"; 
  if(Y == 3) TEMP1 = " staggers and falls";

   MESSAGE = TEMP+" thunder explodes upon "+ATTACKER+".\n"+ATTACKER + TEMP1;
  
  tell_room(ENV, "\n"+MESSAGE+".\n\n");
  
  /* clone obj and make them attack it */
  
  POWER = POWER - 20;
  return 1;
  
        }


 /* BASE/4 (5) + d10 for 30 POWER points */
 /*        followed 2 hb later by        */
 /* BASE/2 (10) + d20   (total ave 30)   */

wind()  {

  if(POWER < 30) { no_power("Wind");  return 1; }
  
  DAMAGE = (BASE/4) + (random(10)+1);
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  
  
  X = random(4);  Y = random(4);  Z = random(4);
 
  if(X == 0) TEMP = "A large gust of wind";    if(X == 1) TEMP = "A mighty wind";
  if(X == 2) TEMP = "A strong gust of wind";   if(X == 3) TEMP = "A small tornado";

  if(Y == 0) TEMP1 = " lifts ";    if(Y == 1) TEMP1 = " throws ";
  if(Y == 2) TEMP1 = " hurls ";    if(Y == 3) TEMP1 = " sucks ";

  if(Z == 0) TEMP2 = " high into the air";   if(Z == 1) TEMP2 = " up into the storm";
  if(Z == 2) TEMP2 = " up into the sky";     if(Z == 3) TEMP2 = " high into the storm";  

   MESSAGE = TEMP + TEMP1 + ATTACKER + TEMP2;
  
  tell_room(ENV, "\n"+MESSAGE+".\n\n");
  
  DOING = 1;
  POWER = POWER - 30;
  call_out("wind2", 2);
  return 1;
  
        }


wind2()  {

  if(present(ATTACK->query_real_name(), environment(environment(TO))))  {
  DAMAGE = (BASE/2) + (random(20)+1);
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  


  X = random(4);  Y = random(4);
 
  if(X == 0) TEMP = " falls from the sky";      
  if(X == 1) TEMP = " falls screaming from the storm";
  if(X == 2) TEMP = " plummets from the clouds and slams to the ground"; 
  if(X == 3) TEMP = " plumments from the sky like a stone";

  if(Y == 0) TEMP2 = "S P L A T";    if(Y == 1) TEMP2 = "T H U D";
  if(Y == 2) TEMP2 = "B O O M";      if(Y == 3) TEMP2 = "S P L U C K";  
  
   MESSAGE = ATTACKER + TEMP+".\n > > "+ TEMP2;
  
  tell_room(environment(environment(TO)), "\n"+MESSAGE+" < <.\n\n");

  DOING = 0;
  return 1;
        }
  DOING = 0;
  return 1;
        }


 /* BASE/2 (10) + d30 for 40 POWER points */
 /*        followed 2 hb later by        */
 /* BASE/2 (5) +  d20   (total ave 40)   */

ice()  {

  if(POWER < 40) { no_power("Ice");  return 1; }
  
  DAMAGE = (BASE/2) + (random(30)+1);
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  
  
  X = random(4);  Y = random(4);  Z = random(4);
  
  if(X == 0) TEMP = "A strong northern wind";             if(X == 1) TEMP = "Gusting sleet";
  if(X == 2) TEMP = "A sudden downpour of freezing rain"; if(X == 3) TEMP = "An icy wind";

  if(Y == 0) TEMP1 = " traps ";     if(Y == 1) TEMP1 = " entombs ";
  if(Y == 2) TEMP1 = " buries ";    if(Y == 3) TEMP1 = " entraps ";

  if(Z == 0) TEMP2 = " under a thin sheet of ice"; if(Z == 1) TEMP2 = " under a large drift of snow";
  if(Z == 2) TEMP2 = " within a block of ice";     if(Z == 3) TEMP2 = " within a snowy drift";  

   MESSAGE = TEMP + TEMP1 + ATTACKER + TEMP2;
  
  tell_room(ENV, "\n"+MESSAGE+".\n\n");
  
  DOING = 1;
  POWER = POWER - 40;
  call_out("ice2", random(2)+1);
  return 1;
  
        }


ice2()  {

  if(present(ATTACK->query_real_name(), environment(environment(TO))))  {
  
  DAMAGE = (BASE/4) + (random(20)+1);
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  

  X = random(3);
 
  if(X == 0) TEMP = " breaks free from the ice and snow";      
  if(X == 1) TEMP = " struggles free from the ice";
  if(X == 2) TEMP = " breaks free from the icy prison"; 
  
  MESSAGE = ATTACKER + TEMP;
  
  tell_room(environment(environment(TO)), "\n"+MESSAGE+".\n\n");

  DOING = 0;
  return 1;
        }
  DOING = 0;
  return 1;
        }
        

 /* BASE/2 (10) + d10 and miss next attack or 2 for 50 POWER points */
 /*                   followed 2 hb later by                        */
 /* BASE   (20) + d20   (total ave 45)                              */
       
lightning()  {

  if(POWER < 50) { no_power("Lightning");  return 1; }
  
  thunder();
  DOING = 1;
  call_out("lightning2", random(3)+1);
  return 1;
        }


lightning2() {

  if(present(ATTACK->query_real_name(), environment(environment(TO))))  {

  DAMAGE = BASE + (random(20)+1);
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  
  
  X = random(4);  Y = random(6);  Z = random(4);  V = random(2);
 
  if(X == 0) TEMP = "A large bolt of";    
  if(X == 1) TEMP = "A jagged arc of";
  if(X == 2) TEMP = "Pure white";    
  if(X == 3) TEMP = "A sudden shock of";

   MESSAGE = TEMP+" lightning surges from ";

  if(V == 0) TEMP = "the storm. ";    if(V == 1) TEMP = "the clouds. ";

   MESSAGE = MESSAGE + TEMP+".\n"+ATTACKER+" is ";

  if(Y == 0) TEMP = "blasted by";    if(Y == 1) TEMP = "smote by";
  if(Y == 2) TEMP = "engulfed in";   if(Y == 3) TEMP = "struck by";
  if(Y == 4) TEMP = "consumed by";   if(Y == 5) TEMP = "surrounded in";

   MESSAGE = MESSAGE + TEMP;

  if(Z == 0) TEMP = " blazing currents of angry lightning";   
  if(Z == 1) TEMP = " an electric inferno of white lightning";
  if(Z == 2) TEMP = " raging electric fury";        
  if(Z == 3) TEMP = " a crescendo of scintillating lightning";  

   MESSAGE = MESSAGE + TEMP;
  
  tell_room(environment(environment(TO)), "\n"+MESSAGE+".\n\n");
  
  DOING = 0;
  POWER = POWER - 30;
  return 1;
  
        }
  DOING = 0;
  return 1;
        }


 /* BASE/2 (10) + d30 for 75 POWER points          */
 /* + same attack done twice more 3 and 5 hb later */
 /* (total ave 75)                                 */


hurricane()  {

  if(!HURRICANE)  {
    if(POWER < 75) { no_power("Hurricane");  return 1; }
        }
  
  if(HURRICANE)  {
   if(!present(ATTACK->query_real_name(), environment(environment(TO)))) 
       { DOING = 0; return 1; }
        }

  DAMAGE = (BASE/2) + (random(30)+1);
  
  AHP = ATTACK->query_hp();    if(DAMAGE > AHP) DAMAGE = AHP - 1;
  ATTACK->hit_player(DAMAGE);  
  
  X = random(8);  Y = random(7);  Z = random(8);
    
  if(X == 0) TEMP = "Shrieking hurricane winds"; if(X == 1) TEMP = "Furious hurricane winds";
  if(X == 2) TEMP = "Howling hurricane winds";   if(X == 3) TEMP = "Deadly hurricane winds";
  if(X == 4) TEMP = "Screaming hurricane winds"; if(X == 5) TEMP = "Rabid hurricane winds";
  if(X == 6) TEMP = "Frenzied hurricane winds";  if(X == 7) TEMP = "Wild hurricane winds";

  if(Y == 0) TEMP1 = " flay the flesh from ";   
  if(Y == 1) TEMP1 = " rip into ";
  if(Y == 2) TEMP1 = " hurl jagged icy shards into ";
  if(Y == 3) TEMP1 = " tear the flesh from ";
  if(Y == 4) TEMP1 = " slam rugged chunks of ice into ";
  if(Y == 5) TEMP1 = " spew a torrent of icy splinters into ";
  if(Y == 6) TEMP1 = " slam "+ATTACKER+" up into the air.\n"+ATTACKER+" falls screaming"+
                    "to the ground.\nA large chunk of ice falls from the sky and slams into ";

  if(Z == 0) TEMP2 = " starts to bleed";   
  if(Z == 1) TEMP2 = " staggers backwards";
  if(Z == 2) TEMP2 = " staggers and falls";
  if(Z == 3) TEMP2 = " is blown to the ground";
  if(Z == 4) TEMP2 = " slips and falls to the ground";
  if(Z == 5) TEMP2 = " blinks";
  if(Z == 6) TEMP2 = " spins and staggers from the force of the blow";
  if(Z == 7) TEMP2 = " begins bleeding from a multitude of tiny cuts";

   MESSAGE = TEMP + TEMP1 + ATTACKER +".\n"+ATTACKER + TEMP2;
  
  tell_room(environment(environment(TO)), "\n"+MESSAGE+".\n\n");
  
  if(!HURRICANE)  {
    DOING = 1;
    POWER = POWER - 75;
    HURRICANE = 1;
    call_out("hurricane", random(3)+1);
    call_out("hurricane", random(4)+4);
    return 1;
        }
  
  DOING = 0;
  return 1;
  
        }

query_power()	              { return POWER; }

set_power(str) { 
  int ark;  
  if(sscanf(str, "%d", ark))  { POWER = ark;  }  
        }

