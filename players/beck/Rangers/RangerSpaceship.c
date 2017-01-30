string items;
status beacon;
status Hover;
#define ROOM_OB present(str,environment(this_object()))
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
reset(){
   items =
   ({ 
         "console","The main console with the controls to guide the ship",
   });
   enable_commands();
}

id(str){
   int i;
   if(this_player()){
      if(present(this_player(),this_object())){
         while(i<sizeof(items)){
            if(items[i] == str){
               return 1;
            }
            i +=2;
         }
         return 0;
      }  
   }
   if(Hover)
      return str == "megaship" || str == "astro" || str == "astro megaship";
   else
      return str == "my secret ship";
}

query_ghost(){ return 1; }
custom_clean(){ return 0; }
catch_tell (string str){
   if(Hover){
      if(this_player() != this_object()){
         if(!this_player() || !present(this_player(), this_object()))
            tell_room(this_object(), "Below the Megaship: "+str);
         return 1;
      }
   }
   return 1;
}

short(){
   if(Hover)
      return "The Astro Megaship";
   else{
      if(query_verb() == "look" || query_verb() == "l")
         return;
      else if(PO == TP)
         return;
      else
         return "The Astro Megaship";
   }
}

long(str){
   int i;
   if(present(this_player(),this_object())){
      if(!str){
         write("You are inside the Power Ranger Astro Megaship.\n"+
            "In front of you is a computer control panel.  It seems very complex.\n"+
            "For a list of availible command type 'Commands'.\n"+
            "");
         if(Hover)
            write("The ship is Hovering close to the ground.\n");
         return 1;
      }
      i = 0;
      while(i<sizeof(items)){
         if(items[i] == str){
            write(items[i+1]+ ".\n");
            return;
            }
         i +=2;
      }
   }
   if(Hover){
      write("A giant megaship used by the Space Rangers.  \n"+
      "");
   }
   else return;
   return 1;
}
realm(){ 
   if(TP)
   if(TP->query_guild_name() != "rangers" || TP->GLEVEL < 70)
      return "NT";
   else
      return;
}

init(){
   if(!ENV(TO)){
      move_object(TO,"/players/beck/room/mountain1");
   }
   if(present(this_player(),this_object())){
      if(TP->GLEVEL > 69){     
         add_action("headlights","beacon");
         add_action("soar","soar");
         add_action("intercom","intercom");
         add_action("dt","dt");
         add_action("hover","hover");
         add_action("ranger_blast","destroy");
      }
      add_action("lookout","lookout");
      add_action("descend","descend");
      add_action("Commands","Commands");
   }
   if(TPRNAME == "beck")
      add_action("beam","beamup");
}

Commands(){
   if(TP->GLEVEL > 69){
      write(""+
         "soar      1 PP Move the Starcraft in common direction\n"+
         "hover     5 PP Move the Starcraft lower to the ground or up in the air [toggled]\n"+
         "beacon         Light up the land below you (only in hover mode)\n"+
         "intercom       Communicate to those outside the ship (only in hover mode)\n"+
         "destroy          Blast objects off the ground for guild power.\n"+
         "");
   }
   write(""+
      "lookout   Look at the world outside the ship\n"+
      "descend   Leave the ship to the ground below you (only in hover mode)\n"+
      "");
   return 1;
}
hover(){
   if(MASTER->QPowerPoints("Power Ranger") < 5){
      write("There is not enough power to move the ship.\n");
      return 1;
   }
   if(Hover){
      if(beacon){
         beacon = 0;
         write("You turn the beacon off.\n");
         set_light(-1);
      }
      tell_room(TO,"The Astro Megaship rises high above the ground.\n");
      tell_room(ENV(TO),"The Astro Megaship rises high above the ground.\n");
      Hover = 0;
      MASTER->APowerPoints(-5,"Power Ranger");
      return 1;
   }
   else{
      tell_room(TO,"The Astro Megaship drops and hovers less than 100 feet from the ground.\n");
      tell_room(ENV(TO),"The Astro Megaship drops and hovers less than 100 feet from the ground.\n");
      Hover = 1;
      MASTER->APowerPoints(-5,"Power Ranger");
      return 1;
   }
   return;
}

descend(str){
   if(!Hover){
      write("You can't descend from this high up.\n");
      return 1;
   }
   if(!str){
      move_object(TP,ENVOB);
      tell_room(TO,TPNAME+" descends to the ground.\n");
      tell_room(ENVTP,TPNAME+" descends from the Astro Megaship in a beam of White Light.\n");
      command("look",TP);
      return 1;
   }
   else{
      write("That is not a descend order.\n");
      return 1;
   }
   return;
}
beam(){
   move_object(this_player(),this_object());
   return 1;
}

soar(str){
   object ob;
   object room;
   string directions;
   if(MASTER->QPowerPoints("Power Ranger") < 1){
      write("There is not enough power to move the ship.\n");
      return 1;
   }
   directions = ({"east","west","southeast","southwest","northeast","northwest","north","south",
      "snow","warp","pass","park","e","w","s","n","out","enter",});
   if(member_array(str,directions) !=-1){
      if(str == "e") str = "east";
      if(str == "n") str = "north";
      if(str == "w") str = "west";
      if(str == "s") str = "south";
      if(str == "ne") str = "northeast";
      if(str == "nw") str = "northwest";
      if(str == "se") str = "southeast";
      if(str == "sw") str = "southwest";
      room = environment(this_object());
      if(command(str, this_object())){
         if(environment(this_object())->realm() == "NT"){
            move_object(this_object(), room);
            write("You cannot move into that area.\n");
            return 1;
         }
         MASTER->APowerPoints(-1,"Power Ranger");
         tell_room(ENVTP,"The Ship moves "+str+"\n");
         environment(this_object())->long();
         for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
            if(ob != this_object()){
               if(ob->short()){
                  write(ob->short());
                  write("\n");
               }
            }
         }
      }
      else
          write("The ship did not move.\n");
      return 1;
   }
   write("That is not a place you can soar.\n");
   return 1;
}


/*
* This routine is called from objects that moves the player.
* Special: direction "X" means teleport.
*/
move_player(dir_dest)
{
   string msgout, msgin;
   string dir, dest;
   object ob;
   int is_light;
   
   if(!dir_dest)
      return 0;
   
   if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
      tell_object(this_object(), "Move to bad dir/dest\n");
      return;
   }
   if (!msgout)
      msgout = "flies away";
   is_light = set_light(0);
   if (is_light < 0)
      is_light = 0;
   if(Hover)
      tell_room(ENVOB,"The Astro Megaship flies away.\n");
   move_object(this_object(), dest);
   if(Hover)
      tell_room(ENVOB,"The Astro Megaship hovers above.\n");
   is_light = set_light(0);
   if (is_light < 0)
      is_light = 0;
   if (!msgin)
      msgin = "hovers above";
   if (!is_light) {
      write("A dark room.\n");
      return;
   }
   ob = environment(this_object());
   call_other(ob, "long", 0);
   ob = first_inventory(ob);
   while(ob) {
      if (ob != this_object()) {
         string short_str;
         short_str = call_other(ob, "short");
         if (short_str)
            write(short_str + ".\n");
         }
      ob = next_inventory(ob);
   }
}

headlights(){
   if(beacon == 0){
      if(!Hover){
         write("The beacon is useless this high above the ground.\n");
         return 1;
      }
      write("You turn the beacon on.\n");
      beacon = 1;
      set_light(1);
      return 1;
   }
   if(beacon == 1){
      beacon = 0;
      write("You turn the beacon off.\n");
      set_light(-1);
      return 1;
   }
   return 1;
}

intercom(str){
   if(!Hover){
      write("Nobody can hear you from this high up.\n");
      return 1;
   }
   if(!str){ write("Say something.\n"); return 1; }
   tell_room(environment(this_object()),"The Astro Megaship's intercom says: "+str+"\n");
   write("You say over the intercom: "+str+"\n");
   return 1;
}

dt(str){
   string msg;
   msg = "[From the Astro Megaship] "+capitalize(this_player()->query_real_name())+" gossips: "+str+
   "\n";
   if(!str){ write("Say something.\n"); return 1; }
   if(MASTER->QPowerPoints("Power Ranger") < 5){
      write("There is not enough power remaining to do this.\n");
      return 1;
   }
   MASTER->APowerPoints(-5,"Power Ranger");
   "obj/user/one_chan.c"->chan_msg(msg,"gossip");
   return 1;
}

lookout(){
   object ob;
   write("__________________________________________\n");
   environment(this_object())->long();
   for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
      if(ob != this_object()){
         write(ob->short());
         write("\n");
       }
   }
   write("__________________________________________\n");
   return 1;
}

ranger_blast(str){
   object ob;
   int val;
   int val2;
   if(!Hover){
      write("You are too far away to blast anything.\n");
      return 1;
   }
   if(!str){
      write("What do you want to blast?\n");
      return 1;
   }
   if(!ROOM_OB){
      write("That is not present to be blasted.\n");
      return 1;
   }
   if(this_player()->query_level() > 19 && this_player()->is_player()){
      write("Stop trying to help the players.\n");
      return 1;
   }
   if(!ROOM_OB->get() || living(ROOM_OB)){
      write("You can't blast that!\n");
      return 1;
   }
   if(ROOM_OB->query_weight() > 100){
      write("You can't blast that!\n");
      return 1;
   }
   ob = ROOM_OB;
   val = ob->query_value();
   if(val > 2000){
      val = 2000;
   }
   val2 = ((val)/20);
   val2 += random((val)/20);
   if(val2 < 5){
      val2 = 5;
   }
   if(val == 0){ val2 = 0; }
   if(str == "corpse"){ val2 = 15; }
   MASTER->APowerPoints(val2,"Power Ranger");
   COMM->ASkillExp(3);
   tell_room(ENV(TO),"A beam of White Light pulses out of the Astro Megaship\n"+
      "and disintegrates the "+str+" instantly\n"+
      "");
   tell_room(TO,"A beam of White Light pulses out of the Astro Megaship\n"+
      "and disintegrates the "+str+" instantly\n"+
      val2+" Power Points have been donated to the Guild.\n"+
      "");
   destruct(ob);
   return 1;
}

