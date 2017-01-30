inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

int R;
string shortdesc;
R = random(5);
  if(R == 0) shortdesc = "A cute Seal Pup";
  if(R == 1) shortdesc = "An innocent Seal Pup";
  if(R == 2) shortdesc = "A beautiful Seal Pup";
  if(R == 3) shortdesc = "A drowsy Seal Pup";
  if(R == 4) shortdesc = "A bright-eyed Seal Pup";
 
     set_name("seal pup");
     set_short(shortdesc);
     set_race( "seal");
     set_alias("pup");
     set_long(
"This is a beautiful, snow-white baby seal with large blue eyes.\n"+
"It peers at you curiously and innocently.\n");
     set_level(1);
     set_ac(1+ random(3));
     set_wc(3 + random(5));
     set_hp(20 + random(20));
     set_al(800);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(
"The seal pup nuzzles your leg.\n");
     load_chat(
"The seal pup rolls over to get its belly rubbed.\n");
     load_a_chat(
"The seal pup cries out in pain!\n");
   }
}
 
