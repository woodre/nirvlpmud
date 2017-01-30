
#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
object cave;

if(!gob->query_lair()) return;
if(player->query_level() < 16) return;
if(player->query_ghost()) return;
if(gob->query_lair() == 1){
 tell_object(player, "You need to place it first!\n");
 return 1;
 }

if(present("symbiote_cave", environment(player))){
  if(present("symbiote_cave", environment(player))->query_cave_owner() == player->query_real_name()){
     tell_room(environment(player),
     player->query_name()+" disappears suddenly.\n", ({ player }));
     tell_object(player, "You enter your lair.\n");
     move_object(player, present("symbiote_cave", environment(player)));
     command("look", player);
     return 1;
     }
  }
if(file_name(environment(player)) == gob->query_lair()){	
     cave = clone_object("/players/chip/venom2/OBJ/cave");
     cave->set_cave_owner(player->query_real_name());
     move_object(cave, environment(player));
     tell_room(environment(player),
     player->query_name()+" disappears suddenly.\n", ({ player }));
     tell_object(player, "You enter your lair.\n");
     move_object(player, cave);
     command("look", player);
     return 1;
     }   
else{
     tell_object(player, "This isn't where your lair is located!\n");
     return 1;
     }
return;
}