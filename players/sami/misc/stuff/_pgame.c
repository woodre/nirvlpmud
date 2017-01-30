#define SHACK "/players/mokri/stuff/paintball/shack"
string *people;

void start_game()
{
   int x;
   
   if(SHACK->query_game_on())
      {
      write("Game in progress.\nEnd the game (goto " + SHACK + " and 'endgame') or try again later.\n");
      return;
   }
   
   for(x = 0; x < sizeof(people); x++)
   {
      write("  Adding player: " + people[x] + "\n");
      SHACK->add_player(people[x],"once");
   }
   SHACK->set_game_on(1);
   SHACK->set_starttime(time());
   SHACK->startme();
   write("Game started.\n");
   destruct(present("this",this_player()));
   move_object(clone_object("/players/mokri/obj/this"),this_player());
   
   return;
}

void add_players(string str)
{
   
   if(str == "~q")
      {
      write("Aborting.\n");
      destruct(present("this",this_player()));
      move_object(clone_object("/players/mokri/obj/this"),this_player());
      return;
   }
   
   if(str == "**")
      {
      start_game();
      return;
   }
   
   if(str && member(people,str) == -1)
      people += ({ str });
   write("Player's name (~q to abort, ** to finish): ");
   input_to("add_players");
   return;
}

int main(string str)
{
   
   people = ({ });
   write("Player's name (~q to abort, ** to finish): ");
   input_to("add_players");
   return 1;
}
