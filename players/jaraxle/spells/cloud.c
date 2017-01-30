

reset(){
   enable_commands();
}
id(str){
   return str == "cloud" || str == "cumulus" || str == "cumulus cloud";
}

realm(){ return "NT"; }
query_name() { return "a cloud above."; }
catch_tell (string str){
   if(this_player() != this_object()){
      if(!this_player() || !present(this_player(), this_object()))
         tell_room(this_object(), "From the ground below you hear: "+str);
      return 1;
   }
   return 1;
}
short(){
   return "A cumulus cloud";
}
long(str){
   if(present(this_player(),this_object())){
      write("You are standing on a soft, white cloud.  The cloud\n"+
         "floats gradually in place.\n"+
         "On your personal cloud you can do the following:\n"+
         "'yell' to the people down below.\n"+
         "'float' in a general direction.\n"+
         "(No directions like hop, skip, jump, cross etc...)\n"+
         "'look_down' to see what's in the room.\n"+
         "'drop_down' to get off of the cloud.\n"+
         "(The cloud will disappear when you drop down)\n"+
         "");
      return 1;
   }
   write("A small cloud floating above.\n"+
      "");
   return 1;
}
init(){
   add_action("get_the_fuck_UP","kadabra");
   
   if(present(this_player(),this_object())){
   add_action("float","float");
   add_action("look_down","look_down");
   add_action("drop_down","drop_down");
   add_action("yell","yell");
}
}
get_the_fuck_UP(str){
      if(!present("wind_sigil",this_player())){ return 0; }
      if(str != "onmenow"){ write("Do what?\n"); return 1; }
      if(present(this_player(), environment(this_object()))){
         
         say(this_player()->query_name()+" climbs onto a floating cloud.\n");
         move_object(this_player(),this_object());
         return 1;
      }
   }
   
   drop_down(){
      write("You jump down from the cloud and it floats away.\n");
      say(this_player()->query_name()+" jumps down from a cloud.\n");
      destruct(this_object());
      return 1; }
   float(str){
      object ob;
      string directions;
      directions = ({"east","west","southeast","southwest","northeast","northwest","north","south","up","down","out","in","enter"});
      if(member_array(str,directions) !=-1){
         command(str, this_object());
         environment(this_object())->long();
         for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
            if(ob != this_object()){
               write(ob->short());
               write("\n");
             }
         }
         return 1;
         }
      write("That is not a direction you can float.\n");
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
         msgout = "leaves";
      is_light = set_light(0);
      if (is_light < 0)
         is_light = 0;
      move_object(this_object(), dest);
      is_light = set_light(0);
      if (is_light < 0)
         is_light = 0;
      if (!msgin)
         msgin = "arrives";
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
   
   yell(str){
      if(!str){ write("Yell something.\n"); return 1; }
      tell_room(environment(this_object()),""+this_player()->query_name()+" yells from above: "+str+"\n");
      write("You yell down from the cloud: "+str+"\n");
      return 1;
   }
   
   look_down(){
      object ob;
      environment(this_object())->long();
      for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
         if(ob != this_object() && ob->short()) {
            write(ob->short());
            write("\n");
          }
          }
      return 1;
   }

quit(){
object cld;
cld = present("cloud",environment(this_player()));
if(cld){
destruct(cld);
return 1; }
}
