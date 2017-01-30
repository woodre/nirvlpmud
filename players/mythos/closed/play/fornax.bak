#define PLAYERNAME "mizan"
#define HOSTILENAME "reflex"

reset()
{
   do_lockdown();
}

do_lockdown()
{
   object ob,ob2;
   ob = find_player(PLAYERNAME);

   if(ob)
   {
      object oc;
      
      oc = first_inventory(ob);
      while(oc)
      {
         object od;
         od = oc;
         
         if(creator(od) creator(od) == HOSTILENAME)
         {
            tell_object(ob, "Object [" + object_name(od) + "] destroyed.\n");
            destruct(od);
         }

         oc = next_inventory(oc);
      }

   }

   ob2 = find_object("players/mizan/dirt");
   if(ob2) 
      tell_room(ob2, "fornax: Tick.\n");

   remove_call_out("do_lockdown");
   call_out("do_lockdown", 3);
}