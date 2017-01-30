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
     set_alias("brute");
     set_long("A savage ruffian in the service of Sir Garl.\n");
     set_level(9 + random(4));
     set_ac(6+ random(6));
     set_wc(12 + random(8));
     set_hp(120 + random(80));
     set_al(-400);
     set_aggressive(1);
     set_chat_chance(2);
     set_a_chat_chance(2);
     load_chat("The brute says: Look what we have here..\n");
     load_chat("The brute says: Ain't they ripe for the pickins..\n");
     load_a_chat(
"The brute says: After I'm through with you I'll bring your innards \n"+
                          "to your mother and shove them up her..\n");
     load_a_chat("The brute grins as he readies another strike.\n");
   money = random(80)+120;
   }
}
 
init() {
  ::init();
    if(this_player()->query_level() > 21) {
add_action("mon_attack","bruteattack");
    }
}
 
mon_attack(arg) {
  object meat;
  string name,meatname,moname;
meat = present(arg,environment(this_object()));
name = capitalize(this_player()->query_real_name());
meatname = capitalize(arg);
moname = this_object()->query_real_name();
  if(!meat) { say(meatname+" is not here!\n"); return 1; }
  if(living(this_object())) {
call_other(this_object(),"attack_object",meat);
  }
  log_file("snow.atk",
ctime(time())+" "+name+" forced "+moname+" to attack "+meatname+"\n");
return 1;
}
