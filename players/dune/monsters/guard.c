inherit "obj/monster";


int once;
object gold, more;
int a;
string gName, gname;  /* changed to 'g' names - 'name' interferes with
                       * obj/monster - Rumplemintz - Dec-11-2009 */
/* string Name, name; */


id(str)
{
  return str == "guard" || str == gname || str == gName;
}


reset(arg)
{
   once = 0;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) gname = "simon";
   if (a == 2) gname = "malachias";
   if (a == 3) gname = "groomshu";
   if (a == 4) gname = "jiriki";
   if (a == 5) gname = "hubert";
   if (a == 6) gname = "molgar";
   if (a == 7) gname = "shanker";
   if (a == 8) gname = "pryrates";
   if (a == 9) gname = "isgrimnur";
   set_name(gname);
   set_race("human");
   set_alias(name);
   gName = capitalize(gname);
   set_short(gName+", the Tower guard");
   set_long(gName+" has long served as stairwell guard for\n"+
         "the Tower ever since he was a wee little kid. He\n"+
         "trained and worked hard to tone his skills up.\n"+
         "However, he looks like he will never be\n"+
         "the warrior he always wanted to be.\n");
   set_level(5);
   set_hp(random(10)+70);
   set_al(0);
   set_wc(9);
   set_ac(5);
   set_whimpy();
   gold=clone_object("obj/money");
   gold->set_money(random(100)+50);
   move_object(gold,this_object());
}


heart_beat()
{
  if (this_object()->query_attack() &&
      this_object()->query_hit_point() < 40 &&
      once == 0)
  {
     more=clone_object("/players/dune/monsters/otherguard.c");
     move_object(more, environment(this_object()));
     tell_room(environment(this_object()), 
       gName+" SHOUTS FOR HELP, and another guard answers!\n"+
       "A big burly man comes running down the stairs.\n"+
       "The man comes to a halt when he reaches the bottom\n"+
       "and shouts, 'Hey YOU, leave "+gName+" alone!\n");
     once = 1;
  }
  ::heart_beat();
}
