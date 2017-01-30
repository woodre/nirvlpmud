#define maker "sado"

#define START_ENERGY 5

inherit "obj/treasure";

object target,master;
int energy,ran;

init()
{
   ::init();
   add_action("attack","pester");
   add_action("eradicate","kill");
   add_action("byebye","sell");
}

set_owner(ob) { master = ob; } /* verte 6.15.01 */

reset(arg)
{
   if(!arg) {
      set_id("chihuahua");
      set_short("A ferocious little chihuahua");
      set_long("You know chihuahuas.  They're small, they yip, they snap at your\n" +
         "ankles, they pee on your feet, and they're generally just obnoxious\n" +
         "little fiends.  This one has a cute pink bow wrapped around it's neck.\n" +
         "You could probably convince it to 'pester <someone>'.\n");
      set_alias("dog");
      set_value(500);
      energy=START_ENERGY;
      master=this_player();
      set_heart_beat(1);
   }
}

query_price() { return 500; }

get() { return 0;}  /*Can't pick up the doggie*/

query_energy()
{
   return energy;
}

attack(str)
{
   if(!str) write("You need to tell the doggie who to pester.\n");
   else if(str==maker) write("I don't think so!\n");
   else if(!(target=find_player(str))) write("Couldn't find that player on the MUD!\n");
   else if(target->query_level()>19 && master->query_real_name()!=maker) write("Even the chihuahua isn't stupid enough to pester a wizard!\n");
   else {
      if(!present(this_object(),target)) {
         say("The little Chihuahua tears off after a sworn enemy.\n");
         write("The little Chihuahua tears off after "+target->query_name()+".\n");
         move_object(this_object(),environment(target));
         tell_room(environment(target),"A little Chihuahua comes waddling into the room, at an unbelievable pace.\n");
         tell_object(target,"It looks up at you as it enters, and decides to pick on you.  Uh-oh.\n");
      }
      do_attack();
   }
   return 1;
}

do_attack()
{
   int i;
   
   if(--energy) {
      i=random(3);
      if(i==0)  pee();
      if(i==1)  yip();
      if(i==2)  bite();
   } else {
      tell_room(environment(target),"Suddenly, the Chihuahua freezes, wobbles a bit, then keels over.  These\n"
         + "little guys are not too tough, and it seems that this one just had a\n"
         + "massive coronary.  Someone sure is lucky.\n");
      tell_object(master,"The doggie fails to return to you after its last attack.\n");
      tell_object(master,"Something must have happened to it.\n");
      destruct(this_object());
   }
}
pee()
{
   tell_object(target,"The little Chihuahua relieves itself on your foot.  It's amazing\n" +
      "how much urine such a small body can hold.\n");
   tell_room(environment(target),"The Chihuahua pisses on "+target->query_name()+"'s foot.\n");
   return 1;
}

yip()
{
   tell_room(environment(target),"The little Chihuahua runs around "+target->query_name()+"'s feet, yipping like crazy.\n");
   tell_object(target,"The little Chihuahua runs around your feet, yipping like crazy.\n");
   return 1;
}

bite()
{
   tell_object(target,"The little Chihuahua bites you on the ankle!  It draws blood.\nOUCH!\n");
   tell_room(environment(target),"The little Chihuahua bites "+target->query_name()+" on the ankle.  It draws blood.\n");
   return 1;
}

byebye(str)
{
   if(id(str))
      {
      write("You can't sell loyalty!\n");
      return 1;
   }
}

eradicate(str)
{
   if(!id(str)) return 0;
   if(this_player()!=master) {write("That's not your dog!\n"); return 1;}
   write("The dog pulls a large gun out from beneath its fur, and blows its own head\n");
   write("off at your command.  A small demon from Sado's shop comes in and sweeps up\n");
   write("the debris, for recycling as oreo cookies.\n");
   say("You hear a loud BANG, and turn around just in time to see a small demon\n");
   say("running off with the remains of a little chihuahua in a dustpan.\n");
   destruct(this_object());
   return 1;
}

heart_beat()
{
   if(!master) { destruct(this_object()); return; }
    if(!environment(this_object())) { set_heart_beat(0); return; }
   if(environment(this_object())!=environment(master))
      {
      say("The little doggie heads off back to its owner.\n");
      tell_room(environment(master),"A little chihuahua comes in and goes over to "+master->query_name()+".\n");
      transfer(this_object(),environment(master));
   }
}

query_master() {return master;}
