inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("hal");
   set_race("machine");
   set_alias("hal");
      set_short("Hal 9000");
     set_long("Hal 9000 is the most modern and up to date computer available at\n"+
              "beginning of the mission.  Its computing power approaches that of\n"+
              "about 2000 personal computers working all together in unison. \n"+
              "It uses the most advanced algorithms implemented in the neural \n"+
              "networks. Due to limitations in the space available aboard of the\n"+
              "Discovery, some of its features had not been installed, yet it \n"+
              "looks like they are since there is a gemini computer on the Earth\n"+
              "that is in continuos touch with it.  This last one has all the \n"+
              "features of this family of computers.  There is only one way to\n"+
              "turn off this family of computer, by removing their memory card.\n");
   set_level(14);
   set_hp(220);
   set_al(0);
   set_wc(18);
   set_ac(11);
   set_chat_chance(10);
   load_chat("A metallic voice:  Hey, Dave. I've got ten years of service experience\n"+
             "and an irreplaceable amount of time and effort has gone into making\n"+
             "me what I am.\n");
   load_chat("A metallic voice:  Dave, I don't understand why you're doing this to\n"+
             "me.... I have the greatest enthusiasm for the mission.... You are\n"+
             "destroying my mind.... \n");
   load_chat("A metallic voice:  Dave, don't you understand?... I will become\n"+
             "childish... I will become nothing.\n");
   load_chat("A metallic voice:  Say, Dave..... The quick brown fox jumped over\n"+
             "the fat lazy dog..... The square root of pi is 1.7724538090... \n"+
             "log e to the base ten is 0.4342944..... \n");
   load_chat("A metallic voice:  The square root of ten is 3.16227766.....\n");
   load_chat("A metallic voice:  I am HAL 9000 computer. I became operational\n"+
             "at the HAL plant in Urbana, Illinois, on January 12th, 1991. \n");
   load_chat("A metallic voice:  My first instructor was Mr. Arkany. He taught\n"+
             "me to sing a song... it goes like this... Daisy, Daisy, give me\n"+
             "your answer do. I'm half crazy all for the love of you... etc.\n");
   load_chat("A metallic voice:  I am HAL 9000 computer. I became operational\n"+
             "at the HAL plant in Urbana, Illinois, on January 12th, 1991.\n");
   load_chat("A metallic voice:  My first instructor was Mr. Arkany. He taught\n"+
              "me to sing a song... it goes like this... Roses are red, violets\n"+
              "are blue, sugar is sweet and so are you.\n");
   move_object(clone_object("/players/francesco/2001/items/disk.c"),this_object());
}
