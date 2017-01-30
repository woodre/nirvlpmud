/*************************************
*    wc 20 nonsavable nice return
*    is the twin to pnodachi except
*    this is wc 20 and a non-paladin
*    weapon  taken off benkei.c
*    special querys str (random(50) and
*    a random 50% chance is given
*
*    approved by saber
**************************************/

#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("nodachi");
    set_alt_name("sword");
    set_alias("katana");
    set_short(BOLD+"Nodachi"+NORM);
    set_long("This is the dreaded Nodachi- "+BOLD+"THE GREAT KATANA"+NORM+".\n"+
    "It is a blade of exquisite beauty and make.  The light\n"+
    "shimmers accross its sharp edge and you shiver.  Dark red\n"+
    "letters run along it.\n");
    set_read(HIR+"Where I go, DEATH shall follow.....\n"+"\t\t\t\- Hunter\n"+NORM);
    set_class(20);
    set_weight(5);
    set_value(8000);
    set_type("sword");
  /* this is now the preferred way for unblockable damage <illarion
    set_hit_func(this_object());
  */
    set_params("other|mythos",0,"mythos_hit");
/* since paladin's no longer exist... i have taken the callout out - mythos <9-1-96>
    call_out("check",3);
*/
}
mythos_hit(attacker){
 if(this_player())
if(call_other(this_player(),"query_attrib","str") > random(50))
 {
  int a;
  a=random(10);
  if(a >= 5) {
    write(BOLD+"\nYou swing the NODACHI and you feel the sickening crunch \n"+
    "of metal cutting into bone.\n"+NORM+HIR+"\n\t     BLOOD gushes forth\n"+
    "\t            and\n"+"\tDEATH's AURA hovers in the air!\n"+NORM);
    write("\n");
    say(BOLD+tp+" swings the GREAT KATANA.  You hear a sickening *CRUNCH* \n"+
    "as metal bites into bone\n"+NORM+HIR+"\n\t     BLOOD gushes forth\n"+
    "\t            and\n"+"\tDEATH's AURA hovers in the air!\n"+NORM);
    say("\n");
   /* old direct damage
    attacker->heal_self(-random(10));
  */
    this_player()->add_hit_point(-random(4));
    /* new direct damage */
    return 10;  /* auto-randomized by weapon code */
    }
    return 2;
}
}

init() {
 ::init();
/*
 if(environment(this_object()) == this_player()) {
  if(!broke) {
  if(environment(this_object())->query_guild_name() == "paladin") {
    object ob;
    ob=clone_object("/players/mythos/awep/forest/pnodachi.c");
    move_object(ob, environment(this_object()));
    destruct(this_object());
    return 1;}
   }
} */ }
/* Make save. -Bp 
   5-dec-02
query_save_flag()  { return 1; }
*/
