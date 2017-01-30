inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("dragon helm");
   set_alias("helm");
   set_short("Dragon Helm");
   set_long("One of the legendary helmets of the lost dragon lords.\n"+
           "The helmet has been carved from the bones of an ancient\n"+
           "blue dragon, and is inlaid with silver runes of enchantment.\n"+
           "Beware the power of the dragon lords!\n");
   set_type("helmet");
   set_ac(2);
   set_weight(2);
   set_value(2000);
  call_out("dragon_talk",120);
}

dragon_talk()  {
int chance;
string chat;
object ob;

  ob = environment(this_object());
if(!ob) return 1;
  if(living(ob)) {

  if(random(10) > 6)  {

  chance = random(8);

  if(chance == 0) chat = "You feel a strange power invade your mind and scan your thoughts";
  if(chance == 1) chat = "You hear the flapping of mighty wings";
  if(chance == 2) chat = "You see the brief image of a dragon before you";
  if(chance == 3) chat = "You feel a cold wind race past your skin";
  if(chance == 4) {  chat = "Feelings of ancient power surge through you, and then are gone";  environment(this_object())->heal_self(random(10));  }
  if(chance == 5) chat = "You feel a yearning for dragon gold";
  if(chance == 6) chat = "Lightning flashes overhead";
  if(chance == 7) {  chat = "The power of the dragon lords saps your strength";
        environment(this_object())->heal_self(-random(10));
        }

  tell_object(ob, chat+".\n");
   }
  call_out("dragon_talk",random(280));
  return 1;
        }
  call_out("dragon_talk",random(280));
        }
