#include "/players/hippo/rvd.h"
id(str) {return str=="note";}
get() {return 1;}
drop(str) {return 0;}
short() {return("This Weeks Puzzle Note!");}
long()
{ write("This note has been send to you to get your attention for a new\n"+
        "feature in Nirvana: PUZZLES. Francesco and Hippo thought that\n"+
        "Nirvana needs some extra challenge, which resulted in This Weeks\n"+
        "Puzzles. Every week from now on there will be a nice puzzle available\n"+
        "which you can solve (or can't?). Once in a while some prizes might\n"+
        "be given away for the best puzzlers, but even without these prizes,\n"+
        "the puzzles are worth the effort of solving. Let your brains work\n"+
        "a bit harder and try to solve them! At least get one and have a\n"+
        "look before you decide it's too hard for you.\n\n"+
        "You can find the puzzles in the game_machine in Hippo's body, which\n"+
        "you reach from church: s, 8e, shake hand, nose.\n");
	if(CTP=="Francesco" || CTP=="Hippo")
	{ write("Receive another copy by typing 'multi'.\n"+
    "To send this note type 'sendnote <name>'.\n");
   }
  return 1;
}
init() 
{ 
	add_action("multi","multi");
   add_action("sendnote","sendnote");
}
multi() 
{ 
	if(CTP=="Hippo" || CTP=="Francesco")
	{	write("You receive another copy of This Weeks Puzzle Note.\n");
move_object(clone_object("/players/hippo/games/puzzle_note.c"),this_player());
		return 1;
	}
}
sendnote(arg)
{string name;
int tmp;
multi();
tmp=sscanf(arg,"%s",name);
      if(find_living(lower_case(name)))
    { move_object(this_object(),find_living(lower_case(name)));
			write("Note was sent to "+capitalize(name)+".\n");
tell_object(find_living(lower_case(name)),"You receive a note from "+CTP+".\n");
			return 1;
		}
		write(capitalize(name)+" is not a living person!\n");
		return 1;
	}
