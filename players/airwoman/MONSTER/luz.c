/* Changed level from 18 to 12, unset hps to 120 (high stats) -Snow */
inherit "obj/monster";
reset(arg){
    ::reset(arg);
        if (!arg){
   set_name("luz");
     set_short("Luz--THE SNOTHEAD!");
     set_alias("loser");
     set_long ("Luz is the worst roommate you've ever known.  She\n"+
        "likes rap music and her fat boyfriend.  Airwoman likes to \n"+
        "call her LOSER when she's talking on the phone late at \n"+
        "night while she's trying to get some sleep.\n");
        set_level(12);
        set_hp(120)
        set_ac(15);
        set_al(250);
        set_wc(26);
        set_aggressive(0);
        set_a_chat_chance(40);
        set_chat_chance(40);
        load_chat("Loser sings: I missed the bus.  You lose!  You "+
                   "lose!\n");
        load_chat("Loser says: CHECK YOU OUT!!\n"); 
        load_chat("Loser says: I am so RUDEEEEEEE!!\n");
        load_a_chat("Loser says:  AHHHH hit me hit me."+
                     "That feels so good...\n");  
        load_a_chat("Loser screams:  Please hit me more!  *moan*\n");
}
}
   
