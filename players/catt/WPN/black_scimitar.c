inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("demon scimitar");
set_alias("scimitar");
set_short("Black Scimitar");
set_long(
"This is Catt's scimitar of demon controlling... it has been passed down\n"
+ "generation by generation... It is guaranteed that you will never possess\n"
+ "this fine weapon. It glows black as it seems to hum a tune of death.\n");
set_value(300000);
set_weight(2);
set_class(13);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 100) {
write("Demons are unleashed as you strike "+attacker->query_name()+
      " down!\n");
say("DEMONS HOWL AS "+this_player()->query_name()+" STRIKES DOWN "+
    attacker->query_name()+"\n");
   return 18;
   }
return 0;
}


