
/*
 * RANDOM MONSTER GENERATOR
 */

#define PATH "players/molasar/rowan/monsters/wand/"


reset(arg) {
   if(arg)
     return;
   extra_reset();
}

/* set up arrays */
object *monster1, *monster2, *undead1, *undead2;

extra_reset() {
   monster1 = allocate(8);
   monster1 = ({ "anhkheg", "beetle", "cent", "dog", "rat",
                  "scorpion", "spider", "p_worm" });
   monster2 = allocate(4);
   monster2 = ({ "bugbear", "gnoll", "hgoblin", "ogre" });
   undead1 = allocate(1);
   undead1 = ({ "skeleton" });
   undead2 = allocate(2);
   undead2 = ({ "gargoyle" });
}

object monster;

get_monster1(amt) {
   int i, n;

   i = 0;
   if(!amt) amt = 1;
   n = random(8);
   while(i < amt) {
     monster = clone_object(PATH+monster1[n]);
     move_object(monster, previous_object());
     i++;
   }
}

get_monster2(amt) {
   int i, n;

   if(!amt) amt = 1;
   i = 0;
   n = random(4);
   while(i < amt) {
     monster = clone_object(PATH+monster2[n]);
     move_object(monster, previous_object());
     i++;
   }
}

get_undead1(amt) {
   int i, n;

   if(!amt) amt = 1;
   i = 0;
   n = random(1);
   while(i < amt) {
     monster = clone_object(PATH+undead1[n]);
     move_object(monster, previous_object());
     i++;
   }
}

get_undead2(amt) {
   int i, n;

   if(!amt) amt = 1;
   i = 0;
   n = random(1);
   while(i < amt) {
     monster = clone_object(PATH+undead2[n]);
     move_object(monster, previous_object());
     i++;
   }
}

