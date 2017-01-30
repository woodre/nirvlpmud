/*************************************
*    wc 20 nonsavable nice return
*    is the twin to nodachi except
*    this is wc 18 and a paladin 
*    two-handed
*    weapon  taken off benkei.c
*    special querys str (random(50) and
*    a random 50% chance is given
*
*      approved by saber
**************************************/
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
int w;
 inherit "players/sandman/paladin/obj/2weapon";
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
    set_class(18);
    set_extra_damage(3);
    set_weapon_type("sword");
    set_weight(5);
    set_value(8000);
    set_hit_func(this_object());
    call_out("check",3);
}
weapon_hit(attacker){
if(call_other(this_player(),"query_attrib","str") > random(50))
 {
  int a;
  a=random(10);
  if(a >= 5) {
    write(BOLD+"\nYou swing the NODACHI and you feel the sickening crunch \n"+
    "of metal cutting into bone.\n"+NORM+HIR+"\n\t     BLOOD gushes forth\n"+
    "\t          and\n"+"\tDEATH's AURA hovers in the air!\n"+NORM);
    write("\n");
    say(BOLD+tp+" swings the GREAT KATANA.  You hear a sickening *CRUNCH* \n"+
    "as metal bites into bone\n"+NORM+HIR+"\n\t     BLOOD gushes forth\n"+
    "\t          and\n"+"\tDEATH's AURA hovers in the air!\n"+NORM);
    say("\n");
    call_other(attacker,"add_spell_point",-5);
    call_other(this_player(),"add_hit_point",-random(4));
    return 3;
    }
    return;
}
}

init() {
 ::init();
 if(environment(this_object()) == this_player()) {
  if(!broke) {
  if(environment(this_object())->query_guild_name() != "paladin") {
    object ob;
    ob=clone_object("/players/mythos/awep/forest/nodachi.c");
    move_object(ob, environment(this_object()));
    destruct(this_object());
    return 1;}
   }
 }}
query_save_flag()  { return 1; }
