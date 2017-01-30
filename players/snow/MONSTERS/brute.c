inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {


string shortdesc;

int color;
  color = random(10);
  if(color == 0) shortdesc = "laughing";
  if(color == 1) shortdesc = "fierce";
  if(color == 2) shortdesc = "fat";
  if(color == 3) shortdesc = "short";
  if(color == 4) shortdesc = "strong";
  if(color == 5) shortdesc = "tall";
  if(color == 6) shortdesc = "weak";
  if(color == 7) shortdesc = "thin";
  if(color == 8) shortdesc = "smelly";
  if(color == 9) shortdesc = "frowning";
  if(color == 10) shortdesc = "handsome";
  if(color == 11) shortdesc = "hairy";
  if(color == 12) shortdesc = "bald";
  if(color == 13) shortdesc = "drooling";
  if(color == 14) shortdesc = "snarling";
 
     set_name("brute");
     set_short("A "+shortdesc+" brute");
     set_race("man");
     set_alias("ruffian");
     set_long("A savage ruffian in the service of Sir Garl.\n");
     set_level(12 + random(4));
    set_ac(8+random(6));
    set_wc(14+random(8));
    set_hp(180+random(80));
     set_al(-800);
     set_aggressive(1);
     set_whimpy();
     set_chat_chance(2);
     set_a_chat_chance(2);
     load_chat("The brute says: Look what we have here..\n");
     load_chat("The brute says: Ain't they ripe for the pickins..\n");
     load_a_chat(
"The brute says: After I'm through with you I'll bring your innards \n"+
                          "to your mother and shove them up her..\n");
     load_a_chat("The brute grins as he readies another strike.\n");
    money = random(400)+550;
   }
}

heart_beat() {
  object ob, ob2;
 ::heart_beat();
 if(!environment()) return;
  ob = present("garl", environment(this_object()));
  if(ob) {
    ob2 = ob->query_attack();
    if(ob2 && !this_object()->query_attack()) {
      if(present(ob2, environment(this_object())))
        this_object()->attack_object(ob2);
} } }
