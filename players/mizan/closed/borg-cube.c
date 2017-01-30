#define DUST "players/mizan/etheriel/environs/dustpile"
#define SURGE "players/mizan/etheriel/environs/exploder.c"

int invis_tl;

id(str) { 
   if(invis_tl) { return 0;
   } else return str == "cube";
}

short() {
   if(invis_tl) {
      return 0;
   } else return "The Borg cube";
}

long() {
   write("Faintly visible because it is cloaked in a strange, blurring\n"+
      "kind of light, the cube must be somewhat far away, because it's every\n"+
      "movement creates a heck of a current surge, and takes a bit of time\n"+
      "in reaching you. A strange, ominous and terrifying emotion rockets up\n"+
      "your spine as you stare at the cube. It seems to be fear, in it's purest\n"+
      "and most frightening form.\n");
}

reset(arg) 
{
   string testog;
   testog=call_other("players/mizan/closed/RandomRoomDM.c","one_random");
   move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + testog);
   if(arg) return;
   call_out("fake_heart_beat", 1);
}

init() 
{
   add_action("enter_cube","enter");
   add_action("envir_cube","ec");
}

query_where_the_heck() 
{
   return(object_name(environment(this_object())));
}

envir_cube() 
{
   if(environment(this_object())) return 0;
   move_object(this_player(), environment(this_object()));
   return 1;
}

enter_cube(str) 
{
   if(str && str == "cube") 
      {
      write("That would be an incredibly stupid idea.\n");
      return 1;
   }
}

fake_heart_beat() 
{
   object room;
   int i;
   room = environment(this_object());

   if(!room) return 1;

   i=random(7);

   if(i==1 && !invis_tl) {
      object ob;
      ob=first_inventory(room);
      if(ob && living(ob) && ob->is_player()) {
         if(ob->query_level() > 15 && ob->query_level() < 21 &&
               1==random(2) && ob->query_real_name() != "mizan") 
         {
            tell_room(room, "A plasma discharge erupts from the Borg cube.\n");
            tell_room(room, (ob->query_name()) + " is blown to bits.\n");
            tell_object(ob, "You get a tingly feeling as a pulsewave from the Borg cube zaps you to bits.\n");

                log_file("mizan.borgcube",
              "[" + ctime() + "] " + ob->query_name() + " was zapped to bits by the Borg Cube.\n");

            if(ob) call_other(ob, "transfer_all_to", this_object());
            if(ob) call_other(ob, "quit");
            if(ob) call_other(ob, "do_quit");
            
            move_object(clone_object(DUST), room);
         }
         else 
         {
            tell_room(room, (ob->query_name()) + " is analyzed by the Borg cube.\n");
            tell_object(ob, "You feel as your mind was emptied and your every move was being watched.\n");
         }
      }
   }
   
   if(i==2 && !invis_tl) 
   {
      tell_room(room, "The Borg cube drifts by at a steady pace and vector.\n");
   }
   
   if(i==3 && !invis_tl) 
   {
      tell_room(room, "You feel as if everything you do is being watched.\n");
   }
   
   if(i ==4 && !invis_tl && 1 == random(100))
      {
      object ob2;
      tell_room(room, "The Borg cube accelerates hard, then suddenly stops.\n");
      ob2=clone_object(SURGE);
      move_object(ob2, environment(this_object()));
      ob2->init();
   }
   
   if(i==5 && !invis_tl)
      {
      tell_room(room, "The Borg cube fades from view.\n");
      call_out("visible", random(50));
      invis_tl=1;
   }
   
   if(i=6 && 1==random(5)) 
      {
      string mover;
      mover = call_other("players/mizan/closed/RandomRoomDM.c", "one_random");
      this_object()->move_me(mover);
   }
   
   remove_call_out("fake_heart_beat");  
   call_out("fake_heart_beat", 3);
}

visible() 
{
   object room;
   room=environment(this_object());
   tell_room(room, "The Borg cube fades into view.\n");
   invis_tl=0;
   return 1;
}

move_me(str) 
{
   object room;
   room = environment(this_object());
   if(!room) return 1;
   if(!str) return 0;
   
   if(!invis_tl) 
      {
      tell_room(room, "The Borg cube drifts " + str + ".\n");
   }
   
   call_other("players/mizan/etheriel/ROOMS/" + str, "???");
  if(this_object())
   move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + str);
   
   if(!invis_tl) 
      {
      tell_room("/players/mizan/etheriel/ROOMS/" + str, "The Borg cube drifts into view.\n");
   }
   return 1;
}

test_if_any_here() 
   {
   object ob;
   ob = environment();
   if(!ob) return;
   ob = first_inventory(environment());
   while(ob) {
      if(ob != this_object() && living(ob) && !call_other(ob, "query_npc")) return 1;
      ob = next_inventory(ob);
   }
   return 0;
}

