/****************************************
*     The random attack was taken almost
*     verbatim from Mythos' shurato
*******************************************/

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

#define tp this_player()->query_name()

inherit "obj/weapon.c";

int Y;

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("deathmaster");
  set_alt_name("sword");
  set_alias("demon");
  set_short(BLU+"Deathmaster"+NORM);
  set_long("     An ebon blade sparkles from a pitch black hilt formed\n\
of some dark leather. The quillons is a straight piece of\n\
equally dark metal capped by a large polished piece of black\n\
obsidian on either end. There are some runes on the blade\n\
that are barely discernable. The counterweight rops off the\n\
hilt: A grinning face of a demon, teeth filling its horrific\n\
maw, slavering tongue lolling.\n");
  set_class(18);
  set_weight(4);
  set_value(1500);
  set_hit_func(this_object());
  call_out("check",100);
  Y = 1;
}

weapon_hit(attacker)
{
  int X;
  int Z;
  int A;
  if(9 < random(15))
  {
    if(this_player()->query_alignment()<1)
    {
      X = random(100);
      Z = random(10);
      A = random(5);
      this_player()->add_spell_point(-A);
      if(Y>50) { Y = 50; }
      if(X<11)
      {
        say(BLU + "Deathmaster" + NORM +
            " sucks the life from its opponent for strength!\n");
        write(BLU + "Deathmaster" + NORM +
              " sucks the life from your opponent for strength!\n");
        attacker->heal_self(-Z);
        Y += Z;
        return 4;
      }
      if(11<=X && X<=31)
      {
        say(BLU+"Deathmaster"+NORM+" drains the enemy!\n");
        write(BLU+"Deathmaster"+NORM+
              " pulls life from the enemy's body into yours!\n");
        attacker->heal_self(-Z);
        this_player()->add_hit_point(Z);
        this_player()->add_spell_point(Z);
        return 2;
      }
      if(31<X && X<51)
      {
        say(BLU+"Deathmaster"+NORM+" cleaves into its foe!\n");
        write(BLU+"Deathmaster"+NORM+" rips your foe's flesh!\n");
        return 6;
      }
      if(51<=X && X<=71)
      {
        say(BLU+"Deathmaster"+NORM+" slashes deep!\n");
        write(BLU+"Deathmaster"+NORM+" slams forcefully into your foe!\n");
        return 7;
      }
      if(71<X && X<81)
      {
        say(BLU+"Deathmaster"+NORM+" hums as it drains energy!\n");
        write(BLU+"Deathmaster"+NORM+
              " hums as it drains your foe using your energy!\n");
        attacker->heal_self(-Z);
        this_player()->heal_self(-Z);
        Y += Z;
        Y += Z;
        return 3;
      }
      if(81<=X && X<=91)
      {
        say(BLU+"Deathmaster"+NORM+" gouges flesh!\n");
        write(BLU+"Deathmaster"+NORM+" slices deeply, crunching bone!\n");
        return Z;
      }
      if(X>91)
      {
        say(BLU+"Deathmaster"+NORM+
          " releases its stored energy in a ferocious blast!\n");
        write(BLU+"Deathmaster"+NORM+
          " blasts into your enemy with its stored power!\n"+BLU+"\
          ###    #####   ###   #####  #   # \n\
          #  #   #      #   #    #    #   # \n\
          #   #  ####   #####    #    ##### \n\
          #  #   #      #   #    #    #   # \n\
          ###    #####  #   #    #    #   # \n"+NORM+"\
          Rains down in a screaming torrent!\n");
        attacker->heal_self(-Y);
        Y=1;
        return Z;
      }
    }
  }
}

init()
{
  ::init();
}

query_save_flag()  { return 1; }

check()
{
  object target;
  if(environment(this_object()))
  {
    if(environment(environment(this_object())))
    {
      target=first_inventory(environment(environment(this_object())));
      if(living(environment(this_object())))
      {
        if(environment(this_object())->query_npc() !=1)
        {
          if(call_other(environment(this_object()),"query_attrib","pie") <
             random(40))
          {
            tell_object(environment(this_object()),"Deathmaster whispers"+
                        " to you of death, and you feel compelled!\n");
            while(target)
            {
              if(target->query_npc())
              {
                environment(this_object())->attack_object(target);
                return 1;
              }
              target=next_inventory(target);
            }
            remove_call_out("check");
            call_out("check",300);
            return 1;
          }
          tell_object(environment(this_object()),"A desire to take a life "+
                      "fills you.\n");
          remove_call_out("check");
          call_out("check",100);
          return 1;
        }
      }
    }
  }
  remove_call_out("check");
  call_out("check",100);
  return 1;
}
