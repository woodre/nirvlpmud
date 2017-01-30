#include "../defs.h"
#include "/players/forbin/closed/dm/inherits/color_string.h"

int la, stare;
object gob, who;

void set_who(object player)
{
	who = player;
	gob = present("forbin_dm_object", player);
}

void reset(int x)
{
  if(x) return;
  la = 0;
  stare = 0;
}

id(str) { return (str == "stone"); }

int query_weight() { return 100000000; }
status get() { return 1; }

short() { return HIK+"A large, oval stone"+NORM; }

long()
{
  if(this_player())
  {
    tell_object(this_player(),
      "The large oval stone is almost solid black, so much so that it\n"+
      "seems to suck in what little light surrounds it.  The only spot\n"+
      "not black is a small white symbol of some sort which glows with\n"+
      "an unearthly blue hue.\n");
    if(this_player() == who && !la)
    {
      call_out("called_lookedat", 10);      
      la = 1;
    }
  }
}

void init()
{
	if(this_player() == who)
	  add_action("cmd_stare", "stare");
}

void called_lookedat()
{
	if(who && present(who, environment(this_object())))
	{
		tell_room(environment(this_object()),
		  (string)who->QN+" seems spooked.\n", ({ who }) );
		tell_object(who,
		  "A warm sensation passes by the back of your neck...\n"+
		  "You feel some...thing...breathing on you...\n"+
		  "A hoarse voice whispers:\n"+
		  "     "+HIW+"\"Stare at me and leave not until\n"+
		  "      what must be done is done...\""+NORM+"\n\n"+
		  "Then there is nothing but silence...\n");
	}	
}

status cmd_stare(string arg)
{
	if((arg == "at symbol" || arg == "symbol") && !stare)
	{
	  tell_room(environment(this_object()),
	    (string)who->QN+
	    " looks at the stone with careful consideration.\n", ({ who }) );
	  tell_object(who,
	    "You stare carefully at the small white symbol.\n");
	  call_out("called_stare1", 4);
	  stare = 1;
	  return 1;
	}
}

void called_stare1()
{
  if(who)
  {
    if(present(who, environment(this_object())))
    {	
	    tell_room(environment(this_object()),
	      "Dark strands of swirling colors surround "+
  	    (string)who->QN+".\n"+
	      (string)who->QN+"'s head and limbs snap back.\n"+
	      (string)who->QPN+" looks paralyzed.\n", ({ who }) );  
  	  tell_object(who, "\n"+
	      "Dark strands of "+color_string("earth fae")+
	      " swirl up from the ground and cascade over\n"+
	      "your body.  Your head and limbs snap violently back as you feel your\n"+
	      "eyes roll back into your head.  You feel paralzyed.\n");
	    call_out("called_stare2", 10);
	  }
	}
}

void called_stare2()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }
	tell_object(who, "\n"+
	  "Slowly, a vison forms in your mind...\n");
	call_out("called_stare3", 3);
}

void called_stare3()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
	  BLU+"  * *"+NORM+" You see a small room.  Candles toss a dim light\n"+
	  BLU+"  * *"+NORM+" across piles of papers and arcane relics.  The\n"+
	  BLU+"  * *"+NORM+" scents of sweat and fear assault your senses,\n"+
	  BLU+"  * *"+NORM+" yet, eerily, the air is still as death.\n");
	  call_out("called_stare4", 10);
}

void called_stare4()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
	  RED+"  * *"+NORM+" A man steps out from the shadows.  Tall, with dark\n"+
	  RED+"  * *"+NORM+" brown hair, handsome features, and a strong, lean\n"+
	  RED+"  * *"+NORM+" body, he carries about him the look of a king.\n"+
	  RED+"  * *"+NORM+" His head tilts upward, and slowly he turns to meet\n"+
	  RED+"  * *"+NORM+" your gaze.\n"+
	  RED+"  * *"+NORM+" The main points at you.  Fear grips you.\n");
	  call_out("called_stare5", 13);
}

void called_stare5()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
	  BLU+"  * *"+NORM+" Pale blue eyes look you over.  A level of indifference\n"+
	  BLU+"  * *"+NORM+" you have never experienced before stares out from this\n"+
	  BLU+"  * *"+NORM+" man's emotionless eyes.  He smiles...a grim, forboding\n"+
	  BLU+"  * *"+NORM+" grin that soon fades as he slowly speaks:\n"+
	  BLU+"  * *"+NORM+"      "+HIW+"\"I see.  Another one who has awakened their power.\""+NORM+"\n"+
	  BLU+"  * *"+NORM+" Laughter fills your head as he quietly chuckles.\n");	
	  call_out("called_stare6", 16);
}

void called_stare6()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
      RED+"  * *"+NORM+" The man stares at you for a few moments before continuing:\n"+
 	  RED+"  * *"+NORM+"      "+HIW+"\"Though it seems you have power, you do not see"+NORM+"\n"+
 	  RED+"  * *"+NORM+"      "+HIW+"as I do....you do not know the true night!  Nor can"+NORM+"\n"+
 	  RED+"  * *"+NORM+"      "+HIW+"you understand its true price.\""+NORM+"\n"+
 	  RED+"  * *"+NORM+" He pauses.\n"+
 	  RED+"  * *"+NORM+"      "+HIW+"\"Your first lesson..."+NORM+"\n"+
 	  RED+"  * *"+NORM+"                "+HIW+"Always honor your elders!\""+NORM+"\n"+
 	  RED+"  * *"+NORM+" The man gestures at you.  You feel your will bend to his.\n"+
 	  RED+"  * *"+NORM+"\n"+
 	  RED+"  * *"+NORM+" You drop to your knees and grovel in awe of his power.\n");
 	tell_room(environment(who),
 	  (string)who->QN+" drops to "+(string)who->QP+" knees and begins to grovel.\n", ({ who }) );
  call_out("called_stare7", 20);
}

void called_stare7()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
    BLU+"  * *"+NORM+" The man nods, knowing that you realize his power.\n"+
    BLU+"  * *"+NORM+"      "+HIW+"\"Much better.  Now for you second lesson.\""+NORM+"\n"+
    BLU+"  * *"+NORM+" He starts toward you, quickly crossing the space that\n"+
    BLU+"  * *"+NORM+" was between you and he.  Before you can react, he places\n"+
    BLU+"  * *"+NORM+" his hand on your forehead.\n");
  call_out("called_stare8", 13);
}

void called_stare8()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
	  RED+"  * *"+NORM+" Suddenly, the darkness of the night explodes into a dance\n"+
	  RED+"  * *"+NORM+" of colors.  The "+color_string("fae")+" ripples and moves about; the delicate\n"+
	  RED+"  * *"+NORM+" strands of absolute power dance along, over, and through\n"+
	  RED+"  * *"+NORM+" everything in sight.  The "+color_string("fae")+" constantly shifts, its varying\n"+
	  RED+"  * *"+NORM+" hues choreographed to an ancient rhythm that you can now\n"+
	  RED+"  * *"+NORM+" palpably hear and feel...a meter that for time immemorial\n"+
	  RED+"  * *"+NORM+" has linked universe and soul.\n");
  call_out("called_stare9", 20);
}

void called_stare9()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
    BLU+"  * *"+NORM+" This music fills the air.  It is a sound so intimate, so\n"+
    BLU+"  * *"+NORM+" full of power and beauty.  It washes over you, entering\n"+
    BLU+"  * *"+NORM+" your body through every pore and every hair, filling your\n"+
    BLU+"  * *"+NORM+" soul.  You are awash with passions and wants...with both\n"+
    BLU+"  * *"+NORM+" needs and hunger.\n");
  call_out("called_stare10", 17);
}

void called_stare10()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
    RED+"  * *"+NORM+" The main smiles faintly as he watches your amazement at\n"+
    RED+"  * *"+NORM+" your new found world.  He opens not his mouth, yet you hear\n"+
    RED+"  * *"+NORM+" his voice more clear than ever.\n"+
    RED+"  * *"+NORM+"      "+HIW+"\"This is the true night.  This is the world unseen..."+NORM+"\n"+
    RED+"  * *"+NORM+"      "+HIW+"the world others fear.  Forever it shall be yours to"+NORM+"\n"+
    RED+"  * *"+NORM+"      "+HIW+"know and hold.  This is the domanin of fear and hunger."+NORM+"\n"+
    RED+"  * *"+NORM+"      "+HIW+"The path not to magic, but to true power and sorcery."+NORM+"\n"+
    RED+"  * *"+NORM+"      "+HIW+"Though the sun may kill, the darkness soothes...\""+NORM+"\n"+
    RED+"  * *"+NORM+"\n"+
    RED+"  * *"+NORM+"      "+HIW+"\"But there is a price!"+NORM+"\n");
  call_out("called_stare11", 25);
}

void called_stare11()
{
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
	tell_object(who, "\n"+
    BLU+"  * *"+NORM+"      "+HIW+"\"For every instance of power, something must be given"+NORM+"\n"+
    BLU+"  * *"+NORM+"      "+HIW+"up for it - a sacrifice.  The greather the sacrifice,"+NORM+"\n"+
    BLU+"  * *"+NORM+"      "+HIW+"the greater the power, and inversely the same holds"+NORM+"\n"+
    BLU+"  * *"+NORM+"      "+HIW+"true.\""+NORM+"\n"+
    BLU+"  * *"+NORM+" He smiles for the last time.\n"+
    BLU+"  * *"+NORM+"      "+HIW+"\"And for every gift, there must be a gift in return."+NORM+"\n"+
    BLU+"  * *"+NORM+"      "+HIW+"For my gifting of sight, I will take what I wish!\""+NORM+"\n"+
    BLU+"  * *"+NORM+" The man uplifts his hands and the "+color_string("fae")+" surges into you.  You\n"+
    BLU+"  * *"+NORM+" feel your insides begin to twist and wrenching in your soul.\n\n");
  call_out("called_stare12", 3);
}

void called_stare12()
{
  int num;
  if(!present(who, environment(this_object())))
  {		
    call_out("called_punish", 3);
    return;
  }	
  
  tell_object(who,
    "Your mastery of the "+color_string("fae")+" is enchanced.\n");
  gob->set_glevel(1);
  
  num = 1;
  if(gob->query_talent())
    num += 1;
  if(!random(4))
    num += 1;
  if(!random(10))
    num += 1+random(2);
  switch(num)
  {
    case 1:  tell_object(who,
               "Your control of the "+color_string("fae")+" increases.\n");
             gob->add_fae(1);
             break;
    case 2:  tell_object(who,
               "Your control of the "+color_string("fae")+" increases.\n");
             gob->add_fae(2);
             break;
    case 3:  tell_object(who,
               "The power of the "+color_string("fae")+" overwhelms you.\n"+
               "Your control of the "+color_string("fae")+" increases.\n");
             gob->add_fae(3);
             break;
    case 4:  tell_object(who,
               "You feel the power of the "+color_string("fae")+" course through you.\n"+ 
               "Your control of the "+color_string("fae")+" increases greatly.\n");
             gob->add_fae(4);
             break;
   default:  tell_object(who,
               "You feel a surge of absolute power from the "+color_string("fae")+".\n"+
               "Your control of the "+color_string("fae")+" increases greatly.\n");
             gob->add_fae(5);
             break;                                                    
  }

  gob->add_sacrifice(1000); 
  gob->update_gob();
  who->lower_attrib();
  who->lower_attrib();
  who->lower_attrib();
  who->lower_attrib();
  if(!random(2))
    who->lower_attrib();
  if(!random(4))
    who->lower_attrib();
  if(!random(6))
    who->lower_attrib();
  who->save_me(); 
  who->add_hit_point(-(((int)who->query_hp() - 25)));
  who->add_spell_point(-((int)who->query_sp()));  
	tell_object(who, "\n"+
    RED+"  * *"+NORM+" Laughing a final time, the man's image vanishes.  You awake.\n\n");
  tell_room(environment(who),
    (string)who->QN+" stands.  "+capitalize((string)who->QPN)+" seems visibly shaken.\n", ({ who }));
  stare = 0;
  destruct(this_object());
}

void called_punish()
{
	tell_object(who,
    "\nA nameless voice thunders in your head:  "+HIR+"\"DO NOT DISOBEY US AGAIN!\""+NORM+"\n\n");
  who->lower_attrib();
  who->lower_attrib();
  who->lower_attrib();
  who->lower_attrib();
  if(!random(2))
    who->lower_attrib();
  if(!random(4))
    who->lower_attrib();
  if(!random(6))
    who->lower_attrib();
  who->save_me();     
  who->death("Unknown");  
  stare = 0;
  destruct(this_object());
}