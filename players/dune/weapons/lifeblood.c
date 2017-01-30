 /* WHOA!
  * Before you start tearing this weapon apart because it returns 7
  * and has a special hit, realize that it totally drains the user
  * of all sps during combat.
  * It is also non-storeable.
  * It also is pretty heavy.
  */
 inherit "obj/weapon.c";

 id(str)  {
  return str == "Lifeblood" || str == "sword" || str == "lifeblood";
 }

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("lifeblood");
    set_alias("lifeblood");
    set_short("Lifeblood, the long sword");
    set_long("Lifeblood is an ancient rune-sword that was\n"+
           "lost long ago.  It has been rediscovered, and\n"+
           "its powers are those of mystic destruction.\n"+
           "Lifeblood has a laced silver and gold hilt, with\n"+
           "a gleaming runed blade.\n");
    set_read("This blade was forged by Dune.\n");
    set_class(20);
    set_weight(6);
    set_value(40000);
  /* Illarion
    set_hit_func(this_object());
*/
  set_params("magical",0,"magic_hit");
}

magic_hit(attacker){
 int num;
 int targnum;
 num = this_player()->query_spell_point();
 targnum = (this_player()->query_attack())->query_spell_point();
 /*  Added by Fred */
 if(this_player()->query_attack()->query_guild_name() == "fallen") targnum = 20;
 /* Finish Additions */
/*  Note: I added in the random(3)==0 part to make it legal.. all weapons must have a 1 in 3 or so for the 
  special to go off....    -mythos <1-15-96>
*/
if(random(3) == 0) {
 if ((num <= 2) && (targnum <= 2)) {
   say("THRASH\n");
   write("THRASH\n");
   say("Lifeblood wants revenge and sucks its foe dry.\n");
   write("Lifeblood wants revenge and sucks its foe dry.\n");
   return 7;}
 targnum -= 3;
 num -=3;
 /* don't drain to zero. -Bp */
 call_other(this_player()->query_attack(),"add_spell_point",-targnum);
 call_other(this_player()->query_attack(), "heal_self", 5);
 call_other(this_player(),"add_spell_point", -num);
 call_other(this_player(),"heal_self",5);
 say("CLANG!!!!!\n");
 write("CLANG!!!!!\n");
 say("Lifeblood trembles violently with soul power.\n");
 write("Lifeblood trembles violently with soul power.\n");
 write("You feel empty inside, but your opponent does too.\n");
 return 5;
}
return 0;
}

