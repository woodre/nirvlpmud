inherit "obj/monster";
#include "../def.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Belle Morte");
  set_race("vampire");
  set_gender("female");
  SetMultipleIds( ({ "woman","belle" }) );
  set_short("A pale, curvy woman in a skin-tight leather jumpsuit");
  set_long("\
Though she might be a little short, especially without her heels, this\n\
woman radiates absolute self-confidence.  A tiny smile plays at the corners\n\
of her full, red lips, as if life itself amuses her.  Her smooth alabaster\n\
skin is framed by cascades of thick, silky ebony hair which freely tumbles\n\
loose to her tiny waist.  She is clad in a black kid-glove leather \n\
jumpsuit that hugs her ample curves like a second skin clear down to her\n\
black stiletto-heeled leather boots.\n");

  set_level(25);
  set_al(-1000);
  set_hp(5000);
  set_wc(40);
  set_ac(40);
  add_money(5000+random(5000));
  set_chat_chance(1);
  set_a_chat_chance(7);
  set_dead_ob(this_object());
  add_spell("backhand",
    "#MN# backhands you hard across your face!\n",
    "$#MN# backhands #TN# hard across #TP# face!\n",
    10,
    "30-50");
  add_spell("grind",
    "#MN# slides inside your guard with inhuman speed, and locks her arms around your neck.  Holding you close, she grinds her crotch against your thigh, her eyes half-closed in pleasure.\n\nWhen she slips away, you feel $R$blood$N$ flowing down the back of your neck....\n",
    "#MN# slides inside #TN#'s guard with inhuman speed, and grinds her crotch against\n #TN#'s thigh.\n\nWhen #MN# slips away, you see $R$blood$N$ flowing down the back of #TN#'s neck....\n",
    10,
    "30-60");
  add_spell("crop",
    "#MN# slides the end of her bloody riding crop deep into her mouth, and swallows hard.  When she pulls it free, it glistens slightly, sucked completely clean of blood.\n",
    "#MN# slides the end of her bloody riding crop deep into her mouth, and swallows hard.  When she pulls it free, it glistens slightly, sucked completely clean of blood.\n",
    10, 0, 0, 0, "crop_heal");
  add_spell("gaze",
    "#MN# sways in close to you, and stares deep into your eyes, her pupils completely consumed by impossibly brilliant sapphire blue.\nYou drop to your knees, paralyzed by fear and desire.\n",
    "#MN# sways in close to #TN#, and stares deep into #TP# eyes.\n#TN# drops to #TP# knees, #TP# his face slack.\n",
    10, 0, 0, 0, "gaze_fun");
  add_spell("boot",
    "In a blindingly fast strike, #MN# knocks you flat on the ground, the impact driving all breath from your lungs.  Before you can move, her black leather boot descends on your chest, its stiletto heel piercing your flesh as she grinds it into you.\n",
    "In a blindingly fast strike, #MN# knocks #TN# flat on the ground.  Before #TN# can move, #MN#'s black leather boot descends on #TN#'s chest, its stiletto heel piercing deep into #TP# flesh.\n",
    10, "30-60");
  add_spell("kiss",
    "#MN# seizes you by the neck, and slams you into a wall with stunning force.  Before you can move, she presses her body against you, and kisses you violently.\n",
    "#MN# seizes #TN# by the throat, and slams #TO# into a wall, then presses herself into #TP#'s body and kisses #TO# violently.\n",
    10, "20-50");
  
  set_armor_special("armor_special");
  
  set_wc_bonus(15); /* for the deathblow and stun */
  
  set_a_chat_chance(8);
}

long()
{
  ::long();
  if(!attacker_ob || !present(attacker_ob, environment()))
    call_out("look_respond", 2, TP);
}

monster_died() {
  object c;
  tell_room(environment(),"\
Belle Morte whispers, \"You have pleased me well, mortal.  I grant you a\n\
gift...  the use of my favorite toy.\"\n\
Her body turns into mist and vanishes into the cathedral floor, leaving\n\
behind only her bloody riding crop.\n");
  c = present("corpse",environment());
  if(c) destruct(c);
  c = present("head",environment());
  if(c) destruct(c);
  return 1;
}

look_respond(ob)
{
  if(ob && present(ob, environment()))
  {
    tell_object(ob,"\n\
Belle Morte returns your scrutiny, her sapphire eyes seeming to pierce\n\
your very soul.  After looking you up and down, she smiles faintly and\n\
licks her lips in anticipation.\n");
    tell_room(environment(), format("\
Belle Morte looks "+ob->query_name()+" up and down, then licks her lips in anticipation.\n"),
    ({ob}));
  }
}

armor_special(ob, dam) {
  string *messages;
  messages = ({});
  if(TP && random(dam) > random(100)) {
     switch(hit_point)
    {
      case 4000..6000:
        messages=
          ({ NAME(TO)+" moans softly.",
             NAME(TO)+" shivers in delight.",
             NAME(TO)+" licks a drop of her own blood from her finger, her eyes half-closed.",
             NAME(TO)+" cries out hoarsely, \"More!  More!!\"", 
          });
      break;
      case 3000..3999:
        messages=
          ({ NAME(TO)+" moans.",
             NAME(TO)+" growls deep in her throat.",
             NAME(TO)+" whispers, \"Mmmm....  do that again.\"",
                NAME(TO)+" laughs in evident delight, the sound warm and distracting.", 
          });
      break;
      case 2000..2999:
        messages=
          ({ NAME(TO)+" moans loudly.",
             NAME(TO)+" shudders, and runs her hands lasciviously down her body.",
             NAME(TO)+" demands, \"Harder!  Hit me harder!\"",
          });
      break;
      case 1000..1999:
        messages=
          ({ NAME(TO)+" groans loudly.",
             NAME(TO)+" cries, \"Don't stop!  Don't stop!\"",
             NAME(TO)+" wipes her own blood from one of her wounds, then licks her hand clean.",
          });
      break;
      case 0..999:
        messages=
          ({ NAME(TO)+" screams, \"YES!!  YES!!\"",
             NAME(TO)+" writhes in absolute ecstasy.",
             NAME(TO)+" breathes, \"I want you, mortal…. \"",
             NAME(TO)+" cries out incoherently.", 
            });
      
    }
    if(sizeof(messages))
      tell_room(ETO, format(messages[random(sizeof(messages))]), ({TO}));
  }
}

crop_heal()
{
  hit_point+=50;
  set_hp_bonus(query_hp_bonus()+50);
}

gaze_fun(victim, room)
{
  object stun;
  stun = clone_object(OBJ+"stun.c");
  stun->inflict_stun(victim, 6);
}

attack() 
{
  ::attack();
  if(attacker_ob && present(attacker_ob,environment())
    && attacker_ob->is_player() && attacker_ob->query_hp() < attacker_ob->query_mhp() / 10)
  {
    tell_object(attacker_ob,
NAME(TO)+" sinks her fangs deep into your throat, draining \
every drop of your blood before it can cool.  With a soft, sated moan, \
she withdraws, drawing her tongue over the puncture marks in a sensual \
caress, before discarding your lifeless shell.\n");
    tell_room(environment(),
NAME(TO)+" sinks her fangs deep into "+NAME(attacker_ob)+"'s throat, draining \
every drop of "+attacker_ob->query_possessive()+" blood before it can cool.  With a soft, sated moan, \
she withdraws, drawing her tongue over the puncture marks in a sensual \
caress, before discarding the lifeless shell.\n", ({attacker_ob}));    
  attacker_ob->death();
  }  
}