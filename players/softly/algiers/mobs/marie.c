#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

string fortune, who, what;
object seeker;
int cost;

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("marie");
  set_alt_name("fortune teller");   
  set_alias("woman");
  set_long("\nMarie is a small older woman with a peaceful yet distant\n"+
	   "look about her.  Her soft grey hair is held together at the\n"+
	   "nape of her neck with an ornament.  She wears an ordinary\n"+
	   "pale green dress with tiny figures on it.  Her sturdy shoes\n"+
	   "are somewhat worn.  Her long thin fingers are interlaced in\n"+
	   "her lap except when she speaks, and then they animate the air\n"+
	   "around her as her eyes dance.\n\n"+
	   "Suddenly you hear a distant voice as if coming from the inside\n"+
	   "of your head.  It sounds like you imagine Marie might sound.\n\n"+
	   "\tPeople around here think I can help\n"+
	   "\tthem with the important things they\n"+
	   "\twant to know about life.  So, for a\n"+
	   "\tsmall fee, I have agreed to try\ to\n"+
	   "\ttell them what they wish to know about\n"+
	   "\tthemselves or their future.  If you\n"+
	   "\twould like me to tell your fortune\n"+
	   "\tthe cost will be 250 coins.  Just say\n"+
	   "\tthe word 'fortune' to me.\n\n");     
  set_short("Marie");
  set_race("human");
  set_gender("female");
  set_level(14);
  set_attrib("pie", 20);
  set_attrib("wil", 20);
  set_attrib("int", 20);
  set_al(0);
  set_aggressive(0);
  add_money(600+random(150));
}

void catch_tell(string str)
{
  if (sscanf(str, "%s says: %s\n", who, what) == 2) 
    {
      what = lower_case(what);
      if (sscanf(what, "%sfortune", who))
	{
	  seeker = this_player();
	  call_out("tell_fortune",2,seeker);
	}
    }
}

tell_fortune(object seeker)
{
  if(!seeker) return;
  cost = 250;
    if(seeker->query_money() <cost) {
      tell_object(seeker, "\nMarie quietly says, It seems you do not have\n\
enough coins.  Please come back another time.\n");
      return 1;
    }
  seeker->add_money(-(cost));
  switch(random(31))
    {
      case 0: fortune ="\n\n"+
	 "People surrounded by mystical spirits are the\n"+
	 "to get on with over the next couple of weeks.\n"+ 
	 "One encounter in particular will give you a\n"+
	 "lot to think about and may result in a big\n"+
	 "change in one area of your life.\n\n";
	 break;
      
    case 1: fortune ="\n\n"+
	      "Your sense of adventure is at a low ebb\n"+
	      "and you are content to be carried along\n"+
	      "by life. This phase will continue for some\n"+ 
	      "time and will give you a chance to consolidate\n"+ 
	      "recent changes in your life.\n\n";
    break;
 
    case 2: fortune ="\n\n"+
	    "You may meet up with an old friend unexpectedly\n"+
	    "this week. Spend some time together and enjoy\n"+
	    "each other's company. It will be a long\n"+
	    "time before the two of you meet up again.\n\n";
  break;
  
  case 3: fortune ="\n\n"+
	    "Blue mystical spirits are the ones to be\n"+
	    "around right now. Everything they do will\n"+
	    "work with your own colour. Results could be\n"+
	    "spectacular but don't get carried away,\n"+
	    "these good times won't last for ever.\n\n";
  break;
  
  case 4: fortune ="\n\n"+
	    "You will have a memorable and enjoyable\n"+ 
	    "week with many friends sharing experiences\n"+ 
	    "with you. Enjoy this situation as it will\n"+ 
	    "not last long and at the moment life generally\n"+ 
	    "is running along a rough track.\n\n";
  break;

  case 5: fortune ="\n\n"+
	    "You seem to be stuck in a rut and wasting\n"+ 
	    "time on dead-end activities now. Snap out\n"+ 
	    "of this as soon as you can and get down to\n"+ 
	    "some hard work and achieve results.\n\n";
  break;
  
  case 6: fortune ="\n\n"+
	    "You don't know which way to turn at the\n"+ 
	    "moment. Everyone seems to be advising you\n"+
	    "to do things their way but none of them feel\n"+ 
	    "right to you. Take a balanced view before\n"+
	    "making up your mind.\n\n";
  break;
  
  case 7: fortune ="\n\n"+
	    "Co-operation is vitally important with other\n"+ 
	    "people in all you activities. If you make\n"+
	    "allowances for their shortcomings they will\n"+ 
	    "respond in a similar manner to yours. The\n"+
	    "end result of this will be success and\n"+
	    "satisfaction for everyone.\n\n";
  break;
  
  case 8: fortune ="\n\n"+
	    "You feel like you are swimming against the\n"+
	    "tide and nothing is going right. Things are\n"+ 
	    "not really as bad as they seem and should\n"+ 
	    "improve soon. You will need to be patient\n"+ 
	    "for a little while yet.\n\n";
  break;
  
  case 9: fortune ="\n\n"+
	    "Changes at home seem to be getting out of\n"+
	    "control. While it is nice to have and do\n"+
	    "new things, you need some time for yourself\n"+ 
	    "and your family to adjust to new circumstances.\n"+
	    "Slow things down a bit and enjoy your life\n"+
	    "as it is for a while.\n\n";
  break;

  case 10: fortune ="\n\n"+
	     "You may have to fight for your rights in a\n"+ 
	     "difficult situation. For most readers this\n"+
	     "will be a minor dispute such as a complaint\n"+
	     "in a shop but for some it could involve a\n"+
	     "more serious legal matter.\n\n";
  break;

  case 11: fortune ="\n\n"+
	     "Hard work and effort over a long period is\n"+  
	     "now paying off and you can take it easy. Slow\n"+ 
	     "down, take a break or give yourself a treat.\n"+ 
	     "Enjoy the rewards you have earned.\n\n";
  break;

  case 12: fortune ="\n\n"+
	     "You're feeling full of energy and are ready\n"+ 
	     "for anything. Put this to good use by helping\n"+  
	     "someone to complete a task they have been\n"+ 
	     "struggling with. However, you may not receive\n"+ 
	     "full recognition for your help.\n\n";
  break;
  
  case 13: fortune ="\n\n"+
	     "You need to re-evaluate your personal financial\n"+ 
	     "circumstances and build a firm foundation for\n"+ 
	     "the future. Although a small windfall is due,\n"+ 
	     "you should not rely on this as it will disappear\n"+ 
	     "as quickly as it came.\n\n";
  break;
  
  case 14: fortune ="\n\n"+
	     "At work there will be some conflict with a\n"+ 
	     "fellow employee. This will not lead to a long\n"+ 
	     "term problem and should produce some worthwhile\n"+ 
	     "results which will be of benefit to everyone\n"+ 
	     "involved.\n\n";
  break;
  
  case 15: fortune ="\n\n"+
	     "You will need to make an important decision\n"+ 
	     "this week. Take your time over this as it\n"+ 
	     "will have a long term impact on many aspects\n"+ 
	     "of your life. A wrong decision made now will\n"+ 
	     "be difficult to reverse in the future.\n\n";
  break;
  
  case 16: fortune ="\n\n"+
	     "It is important that you communicate clearly\n"+ 
	     "with people close to you. Misunderstanding can\n"+ 
	     "cause friction between everyone involved and\n"+ 
	     "in the worst case could mean the break up of\n"+ 
	     "long established partnerships.\n\n";
  break;
  
  case 17: fortune ="\n\n"+
	     "Don't be put off doing something you really\n"+ 
	     "want to even if others aren't very enthusiastic.\n"+ 
	     "You are quite entitled to ignore their views\n"+ 
	     "if what you are doing has no direct effect on them.\n\n";
  break;

  case 18: fortune ="\n\n"+
	     "You seem to be running into obstacles in almost\n"+ 
	     "everything you try to do. Be ready for more of\n"+ 
	     "the same for a few weeks at least. In particular,\n"+ 
	     "avoid any major changes in your life, they are\n"+ 
	     "unlikely to be very successful.\n\n";
  break; 

  case 19: fortune ="\n\n"+
	     "You are likely to find yourself among crowds on\n"+ 
	     "more than one occasion this week. Make the most\n"+ 
	     "of this opportunity to find some new friends who\n"+ 
	     "could help you at some time in the future.\n\n";
  break;

  case 20: fortune ="\n\n"+
	     "Today you are emotionally expressive and generous.\n"+
	     "Assume the lead in relationships. Your ideas and\n"+
	     "presence impress others. Use this power to share\n"+
	     "love and joy with those around you rather than to\n"+ 
	     "dominate or manipulate them.\n\n";
  break;

  case 21: fortune ="\n\n"+
	     "Your mood is one of inspiration and clarity. This\n"+
	     "is a special day for you. Relax and immerse yourself\n"+ 
	     "in the experience and the sheer joy of living.\n\n";
  break;
  
  case 22: fortune ="\n"+
	     "You are much more likely to regret things not done\n"+
	     "than things done.  Take the opportunities that are\n"+
	     "presented to you, and don't be afraid.  You do not\n"+
	     "know when you will have another chance to climb this\n"+
	     "mountain.\n\n";
  break;
  
  case 23: fortune ="\n\n"+
	     "Just because you can't push the river doesn't mean\n"+
	     "you can't paddle your canoe.  Challenges come at the\n"+ 
	     "right moments to help you learn, and if you approach\n"+
	     "them with a good heart all will go well.\n\n";
  break;
  
  case 24: fortune ="\n\n"+
	     "Today your mind needs time to digest new information.\n"+
	     "There is much input from others and you absorb rather\n"+
	     "than express. Communication should be slow, deliberate.\n"+
	     "Listen carefully. You should wait to make important or\n"+
	     "critical decisions because some information is missing.\n\n";
  break;  

  case 25: fortune ="\n\n"+
	     "Today you may long for a quiet, reflective hideaway.\n"+
	     "You are receptive, intuitive and inspired and your\n"+
	     "ideas will be especially inventive. You are ready to\n"+
	     "communicate with sensitive people. Your true desire is\n"+
	     "to remain quietly alone.\n\n";
  break;
  
  case 26: fortune ="\n\n"+
	     "When you have to make a decision, and are unsure of\n"+
	     "the direction to take, move out of your head and into\n"+
	     "your heart. Don't try to be logical; don't try to be\n"+
	     "practical; don't weigh the pros and cons.  Move into\n"+
	     "that quiet place within yourself and do what you know\n"+
	     "is right.\n\n";
  break;
  
  case 27: fortune ="\n\n"+
	     "Today you exude a mysterious and renewing energy. Self\n"+
	     "control and a detached approach will overcome insecurity\n"+
	     "and negative thoughts. Searching inward will help you to\n"+
	     "discover and affirm your faith.\n\n";
  break;
  
  case 28: fortune ="\n\n"+
	     "Financial security is important today. Review your coin\n"+
	     "balance.  Organised activities are most profitable to you\n"+
	     "today.  Remain flexible and don't come to a standstill\n"+
	     "because of a stubborn attitude.\n\n";
  break;
  
  case 29: fortune ="\n\n"+
	     "Your business sense is at peak. Buying and selling should\n"+
	     "be profitable today and your investment ideas are sound.\n"+
	     "Seasonal patterns may affect you however.  Remember to watch\n"+
	     "out for you health to ensure your long term success.\n\n";
  break;
  
  case 30: fortune ="\n\n"+
     "You are unusually sensitive to your emotional environment\n"+
     "and you tend to 'role play' to hide your true feelings.  Be\n"+
     "more open with those you are close to.  Avoid excessively\n"+
     "dominant or submissive roles.\n\n";
     break;  
    }
  tell_object(seeker, fortune);
}




