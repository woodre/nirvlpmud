inherit "obj/treasure";

reset(arg) {if(arg) return ; }
    
init() {
::init();
add_action("trap","say");            /*  plain say          */
#ifndef __LDMUD__
add_action("trap");add_xverb("'");   /*  plain say          */
add_action("trap");add_xverb("\"");  /*  plain say          */
add_action("trap");add_xverb("c");   /*  chatter box        */
#else
add_action("trap", "'", 3);   /*  plain say          */
add_action("trap", "\"", 3);  /*  plain say          */
add_action("trap", "c", 3);   /*  chatter box        */
#endif
add_action("trap","tell");           /*  plain tells        */
add_action("trap","ring");           /*  wedding rings      */
add_action("trap","gossip");         /*  gossip             */
add_action("trap","shout");          /*  shout              */
add_action("trap","risque");         /*  risque             */
add_action("trap","junk");           /*  junk               */
add_action("trap","equip");          /*  equip              */ 
add_action("trap","msg");            /*  msg                */
add_action("trap","babble");         /*  babble             */
add_action("trap","farem");          /*  emote from afar    */
add_action("trap","emote");          /*  emote              */
add_action("trap","emto");           /*  secret emote       */
add_action("trap","farem");          /*  emote from afar    */
add_action("trap","star");           /*  star channel       */
add_action("trap","tempt");          /*  succubus           */
add_action("trap","tempte");         /*  succubus           */
add_action("trap","meow");           /*  feline             */
add_action("trap","meowe");          /*  feline             */
add_action("trap","?");              /*  poet channel       */
add_action("trap","brag");           /*  blades             */
add_action("trap","brage");          /*  blades             */
add_action("trap","chat");           /*  larn               */
add_action("trap","chate");          /*  larn               */
add_action("trap","recite");         /*  gothic             */
add_action("trap","recitee");        /*  gothic             */
add_action("trap","tale");           /*  kender             */
add_action("trap","talee");          /*  kender             */
add_action("trap","rt");             /*  rangers            */
add_action("trap","rte");            /*  rangers            */
add_action("trap","ht");             /*  healers            */
add_action("trap","hte");            /*  healers            */
add_action("trap","tc");             /*  knights            */
add_action("trap","tce");            /*  knights            */
add_action("trap","vibe");           /*  polymorphs         */
add_action("trap","speak");          /*  fallen             */
add_action("trap","sp");             /*  fallen             */
add_action("trap","net");            /*  cyberninja         */
add_action("trap","nem");            /*  cyberninja         */
add_action("trap","dt");             /*  dmages             */
add_action("trap","dte");            /*  dmages             */
add_action("trap","derv");           /*  dervish            */  
add_action("trap","derve");          /*  dervish            */
add_action("","");                   /*  symbiotes          */
add_action("","");                   /*  symbiotes          */
add_action("trap","necro");          /*  necromancers       */
add_action("trap","nc");             /*  necromancers       */
add_action("trap","party");          /*  parties            */
add_action("trap","newbie");         /*  newbie channel     */
                                     /*  this last command  */
                                     /*  traps also any     */
                                     /*  other command      */
                                     /*  starting with a 'c'*/
                                     /*  a further drawback */
}

id(str) { return str == "silent" ; }

get(str) { return 0; }

trap(str){write("Eh..... it would be nice to be able to talk, wouldnt it?\n"); return 1;}

