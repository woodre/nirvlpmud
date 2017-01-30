/* Version 1.0 of the Druid Decorpse
   Gives back the heal value of a corpse, plus 1/5th of the time, adds a
   Touch of Nature point to the Druid */

druid_decorpse(str)  {
object corpse, ob;
int heal; 

ob = present("druid_ob",this_player());

heal = 0;

if(!str) {write("What you do want to give the Death's Kiss blessing to?\n");
  return 1; }
corpse = present(str,environment(this_player()));
if(!corpse)  {
 corpse = present(str,this_player()); }
if(!corpse)  {
  write("There is no corpse here to process.\n");
  return 1; }

heal = corpse->heal_value();
call_other(this_player(),"heal_self",heal);

if(random(5) == 0) {ob->add_touch(1); }

write("You bend over and whisper a quick prayer over the corpse.\n"+
      "The spirit of the corpse flies off into the sky...\n");
say(tp+" says a quick prayer over the corpse, sending its\n"+
     "spirit on its way...\n");
   destruct(corpse);
 }

