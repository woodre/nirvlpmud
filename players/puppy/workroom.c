#include "/players/puppy/define.h"
#define NAME "Puppy"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if (!present("terminal"))
      {
      move_object(clone_object("/players/dune/closed/guild/boards/guildboard.c"), this_object());
   }
   
   /* Since wiz tools cannot auto-load, give Puppy his tool when logging in */
    if ((string)this_player()->query_real_name() == "puppy")
   {      if (!present("bone", this_player()))
    move_object(clone_object("/players/puppy/closed/bone.c"), this_player());
	}
   
   
   
   if(arg) return;
   
   set_long(
      "As you look around you notice that there isn't much to\n"+
      "this room.  It's actually rather secluded from the rest\n"+
      "of the mud.  Perhaps this is why Puppy decided to make\n"+
      "it his home.  Everything in the room seems quite bland\n"+
      "except for a tattered blanket on one side of the room\n"+
      "and a small bowl that you should not touch.  You see a\n"+
      "small stream of water trickling down the wall.\n");
   set_light(1);
   
   add_listen("main", "The only thing making a sound is the water trickling down the walls.");
   add_smell("main", "You smell wet dog hair.");
   items = ({
         "tattered blanket","A tattered blanket covered in fur",
         "blanket","A tattered blanket covered in fur",
         "small bowl","A small bowl used for feeding animals that you should not touch",
         "bowl","A small bowl used for feeding animals that you should not touch",
         "small stream","A stream of water running down the wall",
         "stream","A stream of water running down the wall",
         "wall","The sides of the den look quite bland"});
}

init() {
   ::init();
   add_action("raider", "raider");
   add_action("bowl", "touch");
   add_action("bring", "bring");
   add_action("church","church");
   add_action("post","post");
   add_action("green","green");
   add_action("bank","bank");
}

church(string str) {
   if (!str || str != "church"){
      notify_fail("Where would you like to go?\n");
      write("You leave the den\n");
      say(this_player()->query_name()+" runs off to the church.\n");
      move_object(this_player(),"/room/church.c");
      command("look",this_player());
      return 1;}
}

post(string str) {
   if (!str || str != "post"){
      notify_fail("Where would you like to go?\n");
      write("You leave the den\n");
      say(this_player()->query_name()+" runs off to the post office.\n");
      move_object(this_player(),"/room/post.c");
      command("look",this_player());
      return 1;}
}

green(string str) {
   if (!str || str != "green"){
      notify_fail("Where would you like to go?\n");
      write("You leave the den\n");
      say(this_player()->query_name()+" runs off to the green.\n");
      move_object(this_player(),"/room/vill_green.c");
      command("look",this_player());
      return 1;}
}

bank(string str) {
   if (!str || str != "bank"){
      notify_fail("Where would you like to go?\n");
      write("You leave the den\n");
      say(this_player()->query_name()+" runs off to stony pond.\n");
      move_object(this_player(),"/players/puppy/EX/color.c");
      command("look",this_player());
      return 1;}
}
raider(string str) {
   if (!str || str != "raider"){
      notify_fail("Where would you like to go?\n");
      write("You leave the den\n");
      say(this_player()->query_name()+" runs off to watch the Raiders.\n");
      move_object(this_player(),"/players/puppy/raider.c");
      command("look",this_player());
      return 1;}
}


bowl(str){
   if(!str){ notify_fail("Wh...What?\n"); return 0; }
   if(str == "bowl") {
      write("What part of "+RED+"DO NOT TOUCH"+NORM+" did you not understand?\n\t");
      write("       Puppy "+RED+"GLARES"+NORM+" at you!!!\n\t");
      write("       Puppy "+RED+"GROWLS"+NORM+" at you!!!\n\t");
   }
   tell_object(find_player("puppy"), this_player()->query_name()+" TOUCHED THE BOWL!!!!!\n");
   return 1;}


bring(str)  {
   object person;
   if(!str) {
      write("Usage: bring <living>\n");
      return 1;
   }
   person = find_living(str);
   if(!person) {
      write(str+" can not be found.\n");
      return 1;
   }
   tell_room(environment(person), 
      "A pack of puppys rush into the room and grab "+capitalize(str)+" off\n"+
      "of "+person->query_possessive()+" feet and lope away.\n");
   tell_room(this_object(),
      "The Puppys lope into the room and drop "+capitalize(str)+" on the floor.\n");
   move_object(person,this_object());
   tell_object(person,"You have been taken to Puppy's Den.\n");
   return 1;
}
short() { int a; a = random(15);
   if (a==0) return ""+HIB+"Puppy's Den"+NORM+"";
   if (a==1) return ""+HIM+"Puppy's Den"+NORM+"";
   if (a==2) return ""+HIW+"Puppy's Den"+NORM+"";
   if (a==3) return ""+HIY+"Puppy's Den"+NORM+"";
   if (a==4) return ""+HIG+"Puppy's Den"+NORM+"";
   if (a==5) return ""+HIR+"Puppy's Den"+NORM+"";
   if (a==7) return ""+RED+"Puppy's Den"+NORM+"";
   if (a==8) return ""+GRN+"Puppy's Den"+NORM+"";
   if (a==9) return ""+YEL+"Puppy's Den"+NORM+"";
   if (a==10) return ""+BLU+"Puppy's Den"+NORM+"";
   if (a==11) return ""+MAG+"Puppy's Den"+NORM+"";
   if (a==12) return ""+CYN+"Puppy's Den"+NORM+"";
   if (a==13) return ""+WHT+"Puppy's Den"+NORM+"";
   if (a==14) return "Stony pond";
   if (a==6) return "The pound";
}
