
/*
 * Shadow Master (3/5/94)
 * Objects which are allowed to shadow any object that has
 * query_limited_shadow() { return 1; } is stored here.
 * master.c checks this file each shadowing attempt
 */


string *shadows;

reset(arg) {
   if(arg) 
     return;
   shadows = ({ 
                "players/sandman/paladin/obj/pr_evil",
             });
}

query_shadows() { return shadows; }
