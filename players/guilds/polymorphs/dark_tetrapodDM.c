#define ENV environment(this_object())

id(str) { return str == "matrix"; }
short() { return "The Dark Tetrapod Matrix [1.0]"; }

reset()
{
   move_object(this_object(), "/players/mizan/core/02h/room04.c");
}

dark_tetrapod_roomscan()
{
    object room;
    room = environment(this_player());

    write(calculate_weakest(room));
    return 1;
}

calculate_weakest(arg)
{
   object ob, strongest, weakest;
   string temp;
   int i, hp, strong_hp, weak_hp;
   
   if(!arg) return 0;
   
   strong_hp = this_player()->query_hp();
   weak_hp = this_player()->query_hp();
   strongest = this_player();
   weakest = this_player();
   
   ob = all_inventory(arg);
   for(i = 0; i < sizeof(ob); i ++)
   {
      if(living(ob[i]) && !ob[i]->query_invis())
      {
         hp = ob[i]->query_hp();
         /* Gather the strongest hp */
         if(hp > strong_hp)
         {
            strong_hp = hp;
            strongest = ob[i];
         }

         /* Gather the weakest hp */
         if(hp < weak_hp)
         {
            weak_hp = hp;
            weakest = ob[i];
         }
      }
   }
   
   remote_say((this_player()->query_name()) + " scans the surrounding creatures carefully.\n");
   
   if(strongest == ENV) temp = "You sense that you are the strongest creature present.\n";
   else temp = "You sense that " + (strongest->query_name()) + " is the strongest creature present.\n";
   
   if(weakest == ENV) temp = temp + "You also sense that you are the weakest creature present.\n";
   else temp = temp + "You also sense that " + (weakest->query_name()) + " is the weakest creature present.\n";
   
   return temp;      
   
}


remote_say(str) 
{
  if(!str) return 1;
  if(this_player())
   this_player()->remote_say(str);
   return 1;
}