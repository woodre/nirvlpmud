/* Fishnugget emote generator
 */

string msg;

id(str) { return str == "dispenser"; }
short() { return "A fishnugget dispenser"; }
long() {
  write("This is a useless piece of machinery, which is being used as a\n"+
  "doorstop at the current moment.\n");
}

fishnugget_emote(object oc, int oe) {
  string temp;
  object ob;
  int age;
  
  ob = oc;
  age = oe;
  if(!msg) {
    msg = ({
     "quivers uncontrollably.\n",
     "barks loudly!\n",
     "screams at you!\n",
     "says: Don't eat me, you fool!\n",
     "screams: AAAAAAAUGH!\n",
     "says:I taste like chicken.\n",
     "thinks hard.\n",
     "pokes you in the ribs.\n",
     "does the polka.\n",
     "ponders thoughtfully.\n",
     "says: Your lucky number is 15.\n",
     "says: No, I don't taste like Spam [tm].\n",
     "threatens you with a spray of bread crumbs.\n",
     "mocks your intelligence by reciting Pi to the 300,005th decimal place.\n",
     "goes: Wheeeeee!\n",
     "lusts hungrily for you.\n",
     "yawns widely.\n",
     "grins biggly.\n",
     "goes: Nice hat.\n",
     "hums merrily.\n",
     "giggles inanely.\n",
     "growls.\n",
     "gropes itself.\n",
     "says: Milk. It does a body good.\n",
     "squishes about the room sloppily.\n",
     "refuses to fear you.\n",
     
   });
  }
  if(age >= 100) temp = "A frozen fishnugget";
  else if(age < 100 && age >= 50) temp = "A fishnugget";
  else if(age < 50) temp = "A soggy fishnugget";
  
  if(!ob) return 0;
  else tell_room(environment(ob), temp + " " + msg[random(sizeof(msg))]);
  return 1;
}
  
