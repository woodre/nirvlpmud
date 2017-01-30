
/*
 * SPARRING SCROLL (2/10/94)
 * Given to people challenged to a sparring match
 */

#define SPARRM "/players/molasar/sparring/sp_rm"
#define SPARDIR "/players/molasar/sparring/"

string challenger;
int lvl;

set_challenger(c) { challenger = c; }
set_level(l) { lvl = l; }

id(str) { return str == "scroll" || str == "sparring_scroll"; }

short() { return "A sparring scroll"; }

long() {
   write("You have been challenged to a sparring match by: ");
   write(capitalize(challenger)+" Level: "+lvl+"\n");
   write("You cannot be killed, it is just a test of skill and strength.\n");
   write("A running record of wins and loses will be kept for each\n");
   write("player. Could you be the best? If you accept\n");
   write("you will be healed completely and transported to the\n");
   write("sparring room. You will automatically get first hit.\n");
   write("COMMANDS: rules, help, accept/decline\n");
}

init() {
   add_action("accept","accept");
   add_action("decline","decline");
   add_action("rules","rules");
   add_action("help","help");
}

rules() {
   cat(SPARDIR+"RULES");
   return 1;
}

help() {
   cat(SPARDIR+"HELP");
   return 1;
}

accept() {
   object who;
   
   write("You accept the challenge.\n");
   write("You have been healed!\n");
   write("Moving to sparring room.....\n");
   this_player()->heal_self(10000);
   move_object(this_player(), SPARRM);
   SPARRM->set_challenged(0);
   who = present(challenger, environment(this_player()));
   if(who)
     this_player()->attack_object(who);
   destruct(this_object());
   return 1;
}

decline() {
   object who;

   write("You decline the challenge.\n");
   who = find_player(challenger);
   if(who)
     tell_object(who, capitalize(this_player()->query_real_name())+
         " has declined your challenge.\n");
   SPARRM->set_challenged(0);
   destruct(this_object());
   return 1;
}

drop() {
   decline();
   return 1;
}



