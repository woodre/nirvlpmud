/* cahnged the random to 1/3
   and made sure it dont save
   -mythos <5-15-96>
 */

inherit "obj/weapon";
int att;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("sword");
   set_short("The Sword of Soth");
   set_alias("sword");
   set_long("The sword of the Death Knight, Lord Soth.  It is said that\n")
           +("whosoever is evil enough to use it will find treasure and\n")
           +("glory......and death.\n");
   set_hit_func(this_object());
   set_class(18);
   set_weight(3);
   set_value(5500);
   call_other(this_object(),"set_save_flag",0);
}

query_save_flag() { return ; }
weapon_hit(attacker) {
   if(random(100) < (30)) {
       write("The sword draws the life essence from the body of your opponent\n");
       say(this_player()->query_name() + "'s weapon shoots a cone of \n")
          +("netherstuff which seems to drain energy from the opponent!\n");
       return 15;
}
   return 0;
}
