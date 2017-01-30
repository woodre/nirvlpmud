/*
* refreshes clan objects on players.
*/

#define C_OBJ present("clan_object",this_player())
#define CLAN_DIR "/players/mokri/clans/"

cmd_update_clan(string str)
{
   string clan;

   clan = this_player()->query_clan_name();
   if( !clan ) return 0;
   if(C_OBJ) destruct(C_OBJ);
   
   /** For the Jedi guild **/
   if( clan == "jedi" )
    return 0; 
   move_object(clone_object(CLAN_DIR + "object"),this_player());
   write("Clan object refreshed.\n");
   return 1;
}
