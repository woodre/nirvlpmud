/*
 *  Wielded by the Meduas in the Tower of the Hero
 *  Not saveable
 *
 */

#define tp this_player()->query_name()
#define ATT attacker->query_name()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("longbow of speed");
   set_alias("longbow");
    set_type("bow");         /* set type added by Pavlik */
   set_alt_name("bow");
   set_short("The Longbow of Speed");
   set_long("The famed longbow of speed.\n"+
       "This longbow was once carried by Christopher the Ghost \n"+
       "Dancer before he lost it was lost in the Tower of the Hero.\n");
   set_class(19);
   set_weight(3);
   set_value(2000);
   set_hit_func(this_object());
   set_save_flag(1);
}


weapon_hit(attacker){
int w, x, y;
int NUM;

   x = random(100);
   y = random(20);

if(y < 4)  {
  say(tp+" missed "+ATT+".\n");
  write("You missed.\n");
  NUM = 1;  }
if(y > 3 && y < 7)  {
  say(tp+" hit "+ATT+".\n");
  write("You hit "+ATT+".\n");
  NUM = 3;  }
if(y > 6 && y < 11)  {
  say(tp+" hit "+ATT+" very hard.\n");
  write("You hit "+ATT+" very hard.\n");
  NUM = 5;  }
  if(y > 10 && y < 15)  {
  say(tp+" smashed "+ATT+" with a bone crushing sound.\n");
  write("You smashed "+ATT+" with a bone crushing sound.\n");
  NUM = 8;  }
if(y > 14 && y < 18)  {
  say(tp+" massacres "+ATT+" to small fragments.\n");
  write("You massacre "+ATT+" to small fragments.\n");
  NUM = 10;  }
  if(y > 17)  {
  say(tp+" tickled "+ATT+" in the stomach.\n");
  write("You tickled "+ATT+" in the stomach.\n");
  NUM = 2;  }

  if(x == 90)  {
  write("You fire an extra shot off.\n");
  say(tp+" fires off an extra shot.\n");
  NUM = NUM + 2;  }
if(x == 91)  {
  write("You hit "+ATT+" between the eyes!\n");
  say(tp+" places an arrow between "+ATT+"'s eyes.\n");
  NUM = ((NUM * 3) / 2);  }
if(x == 92)  {
  write("You bury an arrow deep within "+ATT+"'s chest.\n");
  say(tp+" buries an arrow deep with "+ATT+"'s chest.\n");
  NUM = NUM + random(8);  }
if(x == 93)  {
  write("Your arrow veers slightly off target.\n");
  say(tp+"'s arrow veers slightly off target.\n");
  NUM = NUM - 2;  }
if(x == 94)  {
  write("You place an arrow into "+ATT+"'s eye!\n");
  say(tp+" places an arrow into "+ATT+"'s eye!\n");
  NUM = ((NUM * 5) / 3);  }
if(x == 95)  {
  write("You place an arrow into "+ATT+"'s foot.\n");
  say(tp+" shoots "+ATT+" in the foot.\n");
  NUM = NUM + 1;  }
if(x == 96)  {
  write("You shoot "+ATT+" in the leg.\n");
  say(tp+" shoots "+ATT+" in the leg.\n");
  NUM = NUM + random(6);  }
if(x == 97)  {
  write("You shoots "+ATT+" in the neck.\n");
  say(tp+" shoots "+ATT+" in the neck.\n");
  NUM = ((NUM * 5) / 3);  }
if(x == 97)  {
  write("You bounce an arrow off the ground an into "+ATT+"'s leg.\n");
  say(tp+" bounces an arrow off the ground an into "+ATT+"'s leg.\n");
  NUM = NUM + random(6);  }
if(x == 98)  {
  write("You bury an arrow deep into "+ATT+"'s chest.\n");
  say(tp+" buries an arrow deep into "+ATT+"'s chest.\n");
  NUM = NUM + 5;  }
if(x == 99)  {
  write("You place an arrow into "+ATT+"'s arm.\n");
  say(tp+" places an arrow deep into "+ATT+"'s arm.\n");
  NUM = NUM + 1;  }

  return NUM;
}

