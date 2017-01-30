/*   Bar Area-  jaraxle [01.06.01] */



#include "../define.h"

inherit ROOM;



int fireplace;



reset(arg) {

 if(!present("patron", this_object())){

   MO(CO("/players/jaraxle/ares/mobs/bpatron"), this_object());

   MO(CO("/players/jaraxle/ares/mobs/bpatron"), this_object());

   }

   if(arg) return;

   set_short("The Dangerous Blade [Bar]");

   set_light(1);

   set_long(

"  You stand before a large fireplace that is made of stone and\n"+

"built directly into the wall. A few tables are nearby in front\n"+

"of the fireplace. The entrance lies to the north and east with\n"+

"the bar directly to the east.\n");

   add_item(

      "smoke", 

      "A thick whispy smoke that makes your eyes water and your throat raw\n");

   add_item(

      "fire", 

      "A low fire that sends out smoke into the room. You notice something\n"+

      "gleaming beneath it. You can't quite be sure though\n");

   add_item(

      "tables",

      "Large wooden tables that are crudely crafted and are probably\n"+

      "deemed of 'throwaway' quality");

   add_item(

      "chairs",

      "Simple wooden benches that are made of poor quality wood. Most\n"+

      "of them look as though they have been put together hurriedly and\n"+

      "are designed to be thrown away");

   add_item(

      "bar",

      "A large wooden bar that spans the back of the room. From there\n"+

      "you may be served");

   add_item(

      "fireplace",

      "A large stone fireplace that spits out a small amount of heat and\n"+

      "just enough smoke to make the air thick. As you stand near it you\n"+

      "can now tell that it is probably a terrible fire hazzard with so\n"+

      "much soot built up inside of it");

   add_item(

      "ceiling",

      "The ceiling is made of large wooden beams and is very low");

   add_item(

      "air",

      "A thick odorous air that makes you want to crawl on the floor to\n"+

      "avoid its pungent sickness. You especially have trouble breathing\n"+

      "so close to the fire");

   add_smell("main", "You take a long wiff of the smoke coming from the fire and\n"+

                     "begin to choke. A patron laughs at you from the other side\n"+

                     "of the room.\n");



   set_chance(12);

   add_msg("You hear the sounds of people chatting at the tables.");

   add_msg("You hear the sounds of people chatting at the tables.");

   add_msg("The sound of breaking glass can be heard nearby.");

   add_msg("The sounds of an argument can be heard somewhere in a corner.");

   add_msg("The fireplace crackles and sputters.");

   add_msg("A log in the fireplace tips over and sends embers onto the floor.");

   add_msg("A burning ember glows on the floor beside your foot.");

   add_msg("*POP* The fire sputters.");

   add_msg("Smoke swirls up out of the fireplace.");

   add_msg("A draft comes from the fireplace and blows smoke in your face.");

   add_msg("A customer throws a coin in the fire and makes a wish.");

   add_msg("Something glitters in the fire.");

   add_exit(ROOMS+"bar2","north");

   add_exit(ROOMS+"bar4","east");

   }



cmd_search(str){

  object glob;

  if(!str){ write("You search generally, but find nothing.\n"); return 1; }

  if(str == "fire" || str == "fireplace"){

   if(!fireplace){

   glob = clone_object("/obj/treasure");

   glob->set_id("glob");

   glob->set_alias("coins");

   glob->set_weight(1);

   glob->set_short("A glob of melted gold coins");

   glob->set_long(

   "This is a small glob of golden coins that have melted together\n"+

   "in the fire. They were put there by patrons who believe that it\n"+

   "might bring them luck. It seems you were the lucky one.\n");

   glob->set_value(100 + random(50));

   move_object(glob, this_object());

   tell_object(this_player(), 

   "You search around in the fire with a stick and push a glob of glowing\n"+

   "gold onto the floor.\n");

   say(TPN+" pulls something out of the fire.\n");      

   fireplace = 1;

   return 1;

   }

  else{ 

   write("You search the "+str+", but find nothing.\n");

   say(TPN+" searches the area.\n");

   return 1;

   }

  write("You search the "+str+", but find nothing.\n");

  say(TPN+" searches the area.\n");

  return 1;

  }

  write("You search the "+str+", but find nothing.\n");

  say(TPN+" searches the area.\n");

  return 1;

  }



