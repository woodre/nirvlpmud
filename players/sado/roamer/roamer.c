#define MOVE_DELAY 5
object where;

short()
{
   return "A roaming Sadodroid";
}

long()
{
   write("An experimental hunter-killer device being tested by Sadolabs, inc.\n");
   return 1;
}

id(str) { return str == "roamer" || str == "sadodroid"; }

reset(arg)
{
   if(arg) return;
   if(root()) return;
   tell_object(find_player("sado"),"Ok, roaming commencing...\n");
}

look_and_move()
{
   string *exits;
   int i,j;
   j=0;
   where=environment(this_object());
   exits = where->query_dest_dir();
   tell_object(find_player("sado"),"I'm in " + where->short() + " which seems to have " + sizeof(exits) + " exits\n");
   if(sizeof(exits)==0) return bail();
   if(non_standard()) return;
   tell_object(find_player("sado"),"In: "+where->short()+"\n");
   j = sizeof(exits)/2;
   i=random(j);
   tell_object(find_player("sado"),"Ok, j="+j+" i="+i+"\n");
   tell_object(find_player("sado"),exits[i*2+1]+"\n");
   tell_object(find_player("sado"),"Moving "+exits[i*2+1]+" to "+exits[i*2]+"\n");
   move_object(this_object(),exits[i*2]);
   call_out("look_and_move",MOVE_DELAY);
}

activate()
{
   call_out("look_and_move",MOVE_DELAY);
}

deactivate()
{
   remove_call_out("look_and_move");
}

non_standard()
{
   object *a;
   string p,who,what;
   int i;
   a=all_inventory(where);
   for(i=0;i<sizeof(a);i++)
   {
      if(sscanf(file_name(a[i]),"%s/%s/%s",p,who,what) == 3)
         {
         if(what=="castle"  &&  random(4)==1)
            {
            tell_object(find_player("sado"),"Entering castle of "+who+"\n");
            move_object(this_object(),a[i]);
            call_out("look_and_move",MOVE_DELAY);
            return 1;
         }
       }
   }
}

bail()
{
   tell_object(find_player("sado"),"Bailing...\n");
   move_object(this_object(),"/room/vill_green");
   call_out("look_and_move",MOVE_DELAY);
}

move_to(str)
{
   move_object(this_object(),str);
}
