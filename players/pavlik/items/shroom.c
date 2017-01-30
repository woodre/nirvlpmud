#define EN environment()


int eaten,num;


id(str) { if (!eaten) 
   return str == "mushroom" || str == "green mushroom";
   return 0;
}
short() { if (!eaten)
   return "A green mushroom";
   return 0;
}
long() {  
   write("A small green mushroom.\n");
   return 1;
}
get() { return 1; }

drop() { if (!eaten) return 0;
   return 1;
}

reset(arg) {
   if (!arg) 
   {
      eaten = 0;
      num = 0;
   }
}
init() {
   
   add_action("eat","eat");
}

eat(str) {
   if (eaten)
   return 0;
   if (!str)
   return 0;
   str = lower_case(str);
   if (str == "green mushroom" || str == "mushroom") {
      eaten = 1;
      call_out("pick_random",60);
      write("You eat the green mushroom.  It tastes a bit strange.\n");
      say(this_player()->query_name()+" eats a green mushroom.\n");
      
      return 1;
   }
   return 0;
}

pick_random() {
   int i,ran;
   
   if (!environment())
   return;
   if (num == 20) {
      destruct(this_object());
      return;
   }
   num++;
   ran = random(300)+60;
   i = random(10);
   
   if (i == 0)  
   pink();
   
   if (i == 1)
   kt();
   
   if (i == 2)
   tt();
   
   if (i==3)
   head();
   
   if (i==4)
   butterflies();
   
   if (i==5)
   Tell();
   
   if (i==6)
   Whisper();
   
   if (i==7)
   clock();
   
   if (i==8)
   dissolve();
   
   if (i==9)
   earthquake();
   
   call_out("pick_random",ran);
   return;
}

earthquake() {
   
   tell_object(EN, 
      "The earth trembles beneath you feet and a large roar fills the air.\n"+
      "Several nearby structures crumble to the ground!\n");
   return;
}

dissolve() {
   tell_object(EN,
      "Suddenly everything you carry starts to melt into a big blob at your feet!\n");
   return;
}

Tell() {
   tell_object(EN,
      "Ground tells you: Hey!  Get off me!\n");
   return;
}

Whisper() {
   tell_object(EN,
      "Wind whispers: Blow away with me!\n");
   return;
}

clock() {
   tell_object(EN,
      "You hear the gong of a large clock off in the distance.\n");
   return;
}

butterflies() {
   tell_object(EN,
      "A bunch of Monarch Butterflies flutters through the room.\n");
   return;
}

head() {
   tell_object(EN,
      "Your head suddenly starts spinning about on your shoulders!  It finally\n"+
      "stops, but is pointing backwards!\n");
   return;
}

pink() {
   tell_object(EN,
      "A large pink elephant wearing a tutu waltzes through the room, stepping on\n"+
      "your foot!  Ouch!\n");
   return;
}

tt() {
   tell_object(EN,
      "You hear Garion laughing at you.\n");
   return;
}

kt() {
   tell_object(EN,
      "GoK/God: Wilt thou repent your sins my child?\n");
   return 1;
}
query_num() {
   write("The poor fool has "+20-num+" halucinations left.\n");
   return;
}

query_value() { return 10; }
