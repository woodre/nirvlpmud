inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

string fruitname;
int fruit_count;
object room;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A funky brown sphere");
   set_long_desc("You look into the sphere and see leaves and branches.\n"+
      "The sphere contains the matrix of regeneration for\n"+
      "your current polymorph as a tree.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("tree");
   set_deathtime(3000);
   set_block_wield();
   set_block_armor();
   set_block_magic();
   set_block_movement();

   if(!fruitname) 
   {
      fruitname = allocate(5);
      fruitname[0] = "banana.c";
      fruitname[1] = "orange.c";
      fruitname[2] = "raw-potato.c";
      fruitname[3] = "radish.c";
      fruitname[4] = "raw-carrot.c";
   }
   
   fruit_count = 13 + random(5);
   call_out("fruit", random(40));
   
   if(ENV) command("follow", ENV);
   call_out("roomdef", 1);
} 

extra_long() 
{
   if(ENV) return (ENV->query_name()) + " is a tree. Trees are somewhat unmovable";
}

roomdef() 
{
  if(ENV && environment(ENV)) room = environment(ENV);
}

fake_beat() 
{
   if(ENV && room && room != environment(ENV)) 
   {
      move_object(ENV, room);
      tell_object(ENV, "You roots are firmly planted elsewhere.\n");
      command("follow", ENV);
      command("party follow", ENV);
   }
   ::fake_beat();
}

fruit() 
{
  int i;
  if(ENV && environment(ENV)) 
  {
    i = random(sizeof(fruitname));
    move_object(clone_object("/players/mizan/etheriel/heals/" + fruitname[i]), environment(ENV));
    tell_object(ENV, "Something falls out of one of your branches.\n");
    tell_room(environment(ENV), "Some fruity thing falls to the ground with a soft *thud*\n");
    fruit_count --;
    if(fruit_count > 1) call_out("fruit", random(23));
    else tell_object(ENV, "Some of your leaves begin to fall, and you feel somewhat drained.\n");
  }
}



