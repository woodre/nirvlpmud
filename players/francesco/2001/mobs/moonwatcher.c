inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("ape");
   set_race("humanoid");
   set_alias("moonwatcher");
      set_short("Moonwatcher");
     set_long("Among his kind, Moonwatcher is almost a giant. He is nearly\n"+
              "five feet high, and though badly undernourished, weighs over\n"+
              "a hundred pounds. His hairy, muscular body is quite man-like,\n"+
              "and his head is already nearer man than ape. The forehead is\n"+
              "low, and there are great ridges over the eye-sockets, yet he\n"+
              "unmistakably holds in his genes the promise of humanity. As\n"+
              "he looks out now upon the hostile world, there is already\n"+
              "something in his gaze beyond the grasp of any ape. In those\n"+
              "dark, deep-set eyes is a dawning awareness-the first intima-\n"+
              "tions of an intelligence which would not fulfill itself for \n"+
              "another two million years.\n");
   set_level(15);
   set_hp(250);
   set_al(-10);
   set_wc(20);
   set_ac(12);
 move_object(clone_object("/players/francesco/2001/items/tooth.c"),this_object());
}
