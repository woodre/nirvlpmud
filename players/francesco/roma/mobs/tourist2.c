#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  ::reset();
  if(arg) return;
   set_name("tourist");
   set_race("human");
   set_alias("tourist");
      set_short("Visiting tourist");
     set_long("The tourist is dressed with very comfortable items.  He is wearing\n"+
              "sandals, large shorts and an armless top with several patch pockets.\n"+
              "He is carrying a backpack on his shoulders, a camera held on his \n"+
              "neck with a thin belt, a foldable map in his left hand and a walking\n"+
              "cane on his right one.  Notwithstanding his age, he still looks very\n"+
              "healthy: his movements are fast, his cane is continuosly waved around\n"+
              "like a brandished weapon. Also his gaze is menacing, like if he wanted\n"+
              "to fear people off himself. Definately, he wants only to go wandering\n"+
              "around the world, he does not want to be diverted from his goal, beware.\n");

   set_level(20);
   set_hp(650);
   set_wc(32);
   set_ac(19);
   set_chat_chance(10);
   load_chat("The tourist readies his camera and takes a picture of the surroundings.\n"); 

}
