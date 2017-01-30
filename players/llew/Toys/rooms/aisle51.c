#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Children ricochette off one another in eagerness to reach\n"+
      "for the toys splayed out before them.  Soft squishy objects\n"+
      "are held in each of the hands of the children.  The Nerf equipment \n"+
      "is a safe and fun exercise for the young athletes, whose\n"+
      "heros dress in uniform to swing bats or pass the balls.  An\n"+
      "orange football sails through the air banging off the inter-\n"+
      "cepting head of an adult, who quickly laughs it off and tosses\n"+
      "the soft ball back.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle41","north",
      "/players/llew/Toys/rooms/aisle52","west",
      "/players/llew/Toys/rooms/aisle61","south",
   });
   items=({
      "children",
         "The small children run in glee playing their favorite sport",
      "toys",
         "The tender squishy balls of leisure sail through the air",
      "equipment",
         "Footballs, basketballs, soft baseballs and even entertaining\n"+
         "weapons or any sort of sport is recognized by the soft foam",
      "football",
         "The orange spiril of doom shoots toward it's target",
      "adult",
         "Sure the adult is having as much fun as the children",
   });
}

