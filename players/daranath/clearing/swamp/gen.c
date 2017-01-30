id(str)  { return str == "generator" || "spec_monster_generator";  }

short()  { return "A monster generator"; }

long()  {
     write("This is Saber and Daranath's Monster generator.\n  Don't touch.\n");
         }

get()   {
     return 0;
        }

drop()  { return 1; }


make_monster()  {

int monster_number;
object monster;

  monster_number = random(5);

  if(monster_number == 0)  {
    monster = clone_object("/players/daranath/dar/ogre.c");
    monster->set_aggressive(1);
        }
  if(monster_number == 1)  {
    monster = clone_object("/players/daranath/dar/giant1.c");
    monster->set_aggressive(1);
        }
  if(monster_number == 2)  {
    monster = clone_object("/players/daranath/dar/giant2.c");
    monster->set_aggressive(1);
        }
  if(monster_number == 3)  {
    monster = clone_object("/players/daranath/dar/giant3.c");
    monster->set_aggressive(1);
        }
  if(monster_number == 4)  {
    monster = clone_object("/players/daranath/dar/orc.c");
        }

  write("You summon a monster.\n");
  monster->set_alt_name("summon_me");
  move_object(monster, "/players/daranath/dar/rooms/teleport.c");
  write("check 2.\n");
  return 1;
        }

init()  {
  add_action("make_monster","summon_monster");
        }
