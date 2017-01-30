id(str) { return str == "helicopter"; }
short() { return "A helicopter"; }
int key;
int engine;
int elevation;
int xdir;
int zdir;
int ydir;
int x;
int y;
int z;
int yyy;
int xxx;
int zzz;
string items;
string str;
init(){
   if(present(this_player(),this_object())){
add_action("monn","monn");
add_action("land","land");
add_action("takeoff","takeoff");
add_action("forward","forward");
add_action("lifters","lifters");
add_action("turning","turn");
add_action("down","down");
add_action("hspace","hyperspace");
add_action("xmove","xmove");
add_action("ymove","ymove");
add_action("zmove","zmove");
   }
   add_action("climb","climb");
}

xmove() {
x = x += xdir;
return 1; 
}
hspace(string str) {

    if(sscanf(str, "%d %d %d", x, y, z) != 3) {
return 0;
}
if(x < 0 || x > 9999 || y < 0 || y > 9999 || z < 0 || z > 9999) {
write (" Unknown territory: Aborting HyperSpace \n");
return 1; }
write("Inputting coordinates: "+x+" "+y+" "+z+".\n");

xxx = (x);
yyy = (y);
zzz = (z);
    
return 1; 
}

  

monn() {
     
     write(
"----------------------Ship Details----------------------\n"+
"--------------------------------------------------------\n"+
"Forward Velocity: "+ydir+"\n"+
"X-Velocity: "+xdir+"\n"+
"Lift Velocity: "+zdir+"\n"+
"Coordinates: "+x+" "+y+" "+z+"\n");

say(this_player()->query_name() + " looks at the ships details.\n");
return 1; }


forward(str) {
     int ydir;
   string power_level;
   power_level = ({"-5","-4","-3","-2","-1","0","1","2","3","4","5"});

   if(member_array(str,power_level) !=-1){

	write("Forward power set to " + str + ".\n");
	say("Forward power set to " + str + ".\n");
       
     ydir = (str);
  
      return 1;
   }
   write("That is not a power level.\n");
   return 1;
}



lifters(str){
   
   string power_level;
   power_level = ({"-5","-4","-3","-2","-1","0","1","2","3","4","5"});

   if(member_array(str,power_level) !=-1){

	write("Lifters set to " + str + ".\n");
	say("Lifters set to " + str + ".\n");
       
     zdir = (str);
return 1;
   }
   write("That is not a power level.\n");
   return 1;
}

turning(str){

   string power_level;
   power_level = ({"-5","-4","-3","-2","-1","0","1","2","3","4","5"});

   if(member_array(str,power_level) !=-1){

	write("Turning set to " + str + ".\n");
	say("Turning set to " + str + ".\n");
       
     xdir = (str);
return 1;
   }
   write("That is not a power level.\n");
   return 1;
}
climb(arg){
   if(!arg){ write("What do you want to climb?\n"); return 1; }
if(elevation == 1) {
     write("You need to wait for the Helicopter to land!\n");
    return 1;
}
   if(present(this_player(),this_object())){
    if(engine == 1){
     write("You are still flying!\n");
     return 1;
    }
      if(arg == "down"){
         move_object(this_player(),environment(this_object()));
         command("look",this_player());
         return 1;
      }
      write("You can only climb down from here.\n");
      return 1;
   }
   if(arg == "ladder"){
      move_object(this_player(),this_object());
say(capitalize(this_player()->query_real_name())+" climbs the ladder into the Helicopter.\n");
      return 1;
   }
write("You may only climb the ladder of the Helicopter.\n");
   return 1;
}
start(){
   if(engine == 1){
     write("The props are already turning at full velocity.\n");
      return 1;
   }
   if(key == 0){
     write("You need to push the button to begin the ignition sequence.\n");
      return 1;
   }
    write("Ignition Complete.  Propellers at full velocity!\n");
   engine = 1;
elevation = 1;
this_object()->short("A Helicopter [hovering]");
   return 1;
}
land(){
    if(!environment()->query_launch_pad()) {
write("You need to land on a landing platform.\n");
return 1;
}
write("You land the Helicopter and turn off the engine.\n");
 engine = 0;
elevation = 0;
return 1;
}
takeoff() {
     if(!environment()->query_launch_pad()) {
     write("You can only take off on a launchpad.\n");
   return 1;
   }
write("You slowly pull back on the wheel.  The helicopter lifts off the ground.\n");
 elevation = 1;
  return 1;
   }
drive(str){
   object ob;
   string directions;
   directions = ({"east","west","southeast","southwest","northeast","northwest","north","south",});
   if(engine == 0){
write("No ignition sequence detected.\n");
      return 1;
   }
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
   write("That is not a place you can drive.\n");
   return 1;
}
lower(str){
if(!str){ write("What do you want to push?\n"); return 1; }
if(str == "button") {
write("You push the button to start the ignition sequence.  Now 'start'\n"+
"the engine.\n");
      key = 1;
      return 1;
   }
write("You can only push the button.\n");
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
   return 1;
}
lookout(){
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
query_launcher() { return 1; }

query_copter() { return 1; }
