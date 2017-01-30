init() {
   add_action("drop", "drop");
   add_action("drop", "kill");
   add_action("drop", "missile");
   add_action("drop", "shock");
   add_action("drop", "fireball");
}

int age;

id(str) { return (str=="wasp" || str=="maggots"); }

long() {
   write("Nasty revolting wasp-like insects.\n");
}

reset(arg) {
   if (arg) return;
   set_heart_beat(1);
}

heart_beat() {
string mess;
age +=1;

   mess="";
   if (age==5) mess="A black wasp crawls up your leg.";
   if (age==10) mess="A black wasp crawls into your clothes.";
   if (age==15) mess="A black wasp drills a hole into your stomach.";
   if (age==20) mess="A black wasp lays eggs in your stomach.";
   if (age==22) mess="The black wasp flies away.";
   if (age==26) mess="Black maggots are beginning to crawl inside you.";
   if (age==30) mess="Black maggots are eating you from inside.";
   if (age==35) mess="You start bleeding from your ears and eyes.";
   if (age==40) mess="Black maggots are crawling out through your nose.";
   if (age==45) mess="Black maggots turn into wasps and flies away.";
   if (strlen(mess)>0) tell_object(environment(),mess+"\n");
   if(age==45) destruct(this_object());
}

get() { return 1; }
drop(str) {
   if (!id(str)) return 0;
   write("It's much to fast.\n");
   say(call_other(this_player(),"query_name")+" tries to kill an insect but fails.\n");
   return 1;
}
