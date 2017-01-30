/*
Carried by /pl/s/MONSTERS/efreeti.c
This weapon burns the wielder for damage 3/4 of the time +
  it returns 5+random(7) 1/2 time (player is always hurt when return)
Has a weight of 12...
*/
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("scimitar of flame");
    set_alias("scimitar");
    set_short("A huge scimitar of flame");
   set_type("sword");
    set_long(
"This is a huge, wickedly curved blade with fire burning up and down its \n"+
"length. The fabled weapon of the Efreet, it is as wicked as they.\n");
    set_class(18);
    set_weight(12);
    set_value(8000);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(16);
  if(W > 4) {
    write("Your scimitar burns your hand!\n");
call_other(this_player(),"hit_player",2);
  }
  if(W > 7)  {
  say("The scimitar sends tendrils of fire burning across its foe.\n");
  write("Your scimitar sends tendrils of fire burning through your foe.\n" +
           "Your enemy screams in pain as its body smokes.\n");
return (5 + random(7));
 
   }
       return;
}
 
