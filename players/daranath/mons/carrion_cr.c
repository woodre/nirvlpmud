inherit "players/mythos/amon/forest/monster1";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("crawler");
     set_alias("carrion");
     set_short("A Carrion Crawler");
     set_race("scavenger");
     set_gender("creature");
     set_long("The crawler looks like a cross between a giant green\n"+
              "cutworm and a centipede. The monster's head sprouts eight\n"+
              "slender, writhing tentacles. The monster is a dull yellow\n"+
              "color and is accompanied by a rank, fetid odor.\n");
     set_level(8);
     set_ac(7);
     set_wc(12);
     set_hp(120 + random(40));
     set_al(-350);
     set_aggressive(0);

     set_a_chat_chance(25);
     load_a_chat("You feel a numbing feeling seeping into your body.\n");
     load_a_chat("Paralizing poison flows throughout your body, slowing your reflexes.\n");
     load_a_chat("The tentacles writhe with a life all thier own.\n");

     set_mult(4);
     set_mult_chance(25);
     set_mult_dam1(5);
     set_mult_dam2(5);

     call_out("shriek",random(100));
   }
}

shriek() {
int hh,kk; 
object obt;
if(query_attack()) {
hh = kk = 0;
  obt = all_inventory(environment(this_object()));
    while(kk<sizeof(obt) && !hh) {
      if(obt[kk]->is_player()) hh = 1; 
      kk++; }
  if(hh) {
  tell_room(environment(this_object()),"A severed length of tentacle falls to the ground.\n");
   move_object(clone_object("/players/daranath/items/tentacle.c"),
       environment(this_object())); 
  } 
  call_out("shriek",random(100) + 100); }
  else call_out("shriek",20);
return 1; }
