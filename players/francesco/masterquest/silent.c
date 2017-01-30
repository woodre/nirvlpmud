inherit "obj/treasure";

reset(arg) {if(arg) return ; }
    
init() {

add_action("trap","say");            /*  plain say          */
#ifndef __LDMUD__
add_action("trap");add_xverb("'");   /*  plain say          */
add_action("trap");add_xverb("c");   /*  chatter box        */
#else
add_action("trap","'", 3);   /*  plain say          */
add_action("trap","c", 3);   /*  chatter box        */
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
add_action("trap","star");           /*  star chanel        */
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
add_action("trap","gpt");            /*  shardaks           */
add_action("trap","gt");             /*  shardaks           */
add_action("trap","at");             /*  shardaks           */
add_action("trap","ae");             /*  shardaks           */
add_action("","");                   /*  symbiotes          */
add_action("","");                   /*  symbiotes          */
add_action("trap","nc");             /*  necromancers       */
add_action("trap","nce");            /*  necromancers       */
add_action("trap","bt");             /*  bards              */
add_action("trap","bte");            /*  bards              */
add_action("trap","farsong");        /*  bards              */
add_action("trap","farsonge");       /*  bards              */
add_action("trap","att");            /*  alliance           */
add_action("trap","ate");            /*  alliance           */
add_action("trap","party");          /*  parties            */
                                     /*  this last command  */
                                     /*  traps also any     */
                                     /*  other command      */
                                     /*  starting with a 'c'*/
                                     /*  a further drawback */
}

id(str) { return str == "silent" ; }

get(str) { return 0; }

trap(str){write("You better concentrate on the mastermind.\n"); return 1;}

