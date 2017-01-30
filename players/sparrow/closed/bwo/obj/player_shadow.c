/* 3/26/2011 03:41 Sparrow: Modified Dodge, added messages, fixed some logic errors ;) */
#include <ansi.h>

object shadowee;

void start_shadow(object ob)
{
  shadowee=ob;
  if(!ob) return;
  shadow(ob, 1);
}

void end_shadow()
{
  shadow(shadowee, 0);
  destruct(this_object());
}

status query_bwo_shadow() { return 1; }

varargs int do_damage(int *damarr, string *typearr)
{
  int weight_pct;
  int guild_rank;
  object room;
  int pct;
  int dex, luck, intel;
  string *dodgeMess;
  string *dodgeMess2;
  string *dodgeMess3;
  string myDodge;
  string myDodge2;
  string myDodge3;
  string percMess;

  if(!caller() || !living(caller())) {
    return (int)shadowee->do_damage(damarr, typearr);
  }
  room = environment(shadowee);
  guild_rank = (int)shadowee->query_guild_rank();
  dex = (int)shadowee->query_attrib("dex");
  luck = (int)shadowee->query_attrib("luc");
  intel = (int)shadowee->query_attrib("int");

  weight_pct = (int)shadowee->query_pct_weight();

  if(weight_pct < 100) {
    pct = ((100 - weight_pct) / 3);
    pct += (guild_rank * 2);
    pct += ((dex + luck + intel) / 6);
  }

  if(pct > random(100)) {
    int x, y;
    int light_level;
    int resist;

    /* I moved the tell_object and tell_room after the resist calculation so I can
       give messages based on the amount of damage avoided. Yeah I know I rock.
       -Sparrow
    */

    light_level = (int)room->query_light();
    if(light_level < -5) light_level = -5;
    /* I changed this line, not because it doesn't work, I just don't want to penalize.
       even more in a lighted room. Pretty much 40% of the block is from their ability
       [random] and 60% of it from darkness. I don't want to eat away at their random
       (or pure acrobatic) dodge because of light. They just don't get a bonus -Sparrow
    if(light_level > 5) light_level = 5;
    */
    if(light_level > 0) light_level = 0;
    /* We actually need to shift the light level down 1. I think we were forgetting
       that light level 0 IS dark and should give us a bonus to damage reduction.
       currently it gives us nil. I will shift the <light_level> down 1 (+5%) and
       reduce the random aspect 5% so we still max out at 50%. -Sparrow
    */
    light_level = light_level - 1;
    y = sizeof(damarr);
    /* array of dodge messages */
    dodgeMess = ({"executed a back handspring", "dove to the side", "dove into a shadow",
      "dropped to the ground in a split", "feigned right then dove left", "feigned left then dove right",
      "feigned forward then lurched backwards", "feigned backwards then sprang forward", "twisted to the side",
      "bridged backwards", "ducked low", "cart-wheeled left", "cart-wheeled right", "jumped straight up",
	  "flipped backwards", "flipped forward"});
      for(x=0; x < y; x ++)
    {
      /* Modified this line to bring max dodge damage reduction back down to 50%.
         Sparrow
      resist = ((light_level * -5) + random(26));
      */
      resist = ((light_level * -5) + random(21));
      if(resist < 1) resist = 1;
      /* string based on the amount of damage dodged */
      switch(resist) {
        case 0..3:
          percMess = "nearly none of the";
        break;
        case 4..10:
          percMess = "barely any of the";
        break;
        case 11..20:
          percMess = "a fraction of the";
        break;
        case 21..30:
          percMess = "a good bit of the";
        break;
        case 31..40:
          percMess = "a large chunk of the";
        break;
        case 41..99:
          percMess = "almost all of the";
        break;
        default:
          percMess = "the entirety of the";
      }
      dodgeMess2 = ({"avoiding", "eluding", "escaping", "diverting", "deflecting", "dodging", "evading",
	                 "shaking", "shirking", "shunning", "warding", "averting"});
	  dodgeMess3 = ({"damage", "attack", "blow", "maneuver", "onslaught", "danger", "barrage", "strike"});

      /* Build dodge messages - Since we are generating resistance for each element in
         the damarr then we must have a block for each element in the damarr. If that
         ends up being too much I may move the whole thing outside of the loop and
         calculate damage resistance once and apply it to each element*/
      /* first the basic type of dodge randomized from the array */
      myDodge = dodgeMess[random(sizeof(dodgeMess))];
      myDodge2 = dodgeMess2[random(sizeof(dodgeMess2))];
      myDodge3 = dodgeMess3[random(sizeof(dodgeMess3))];	  
	  tell_object(shadowee, HIC+"["+HIK+"DODGE"+HIC+"]"+NORM+BOLD+" You "+myDodge+" ...\n\t... "+myDodge2+" "+percMess+" "+myDodge3+"! "+HIC+"["+HIK+"DODGE"+HIC+"]\n"+NORM);
      if(room=environment(shadowee)) {
        tell_room(room, HIC+"["+HIK+"DODGE"+HIC+"] "+NORM+BOLD+shadowee->query_name()+" "+myDodge+" ...\n\t..."+myDodge2+" "+percMess+" "+myDodge3+"! "+HIC+"["+HIK+"DODGE"+HIC+"]\n"+NORM, ({shadowee}));
      }
	  tell_object(shadowee, "\t-=[ dodge: "+resist+" % ]=-\n");
      resist = damarr[x] * resist / 100;
      tell_object(shadowee, "\t-=[ dodge: "+resist+" HP ]=-\n");
      damarr[x] = (damarr[x] - resist);
    }
  }
  return (int)shadowee->do_damage(damarr, typearr);
}
