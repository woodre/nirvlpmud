/* Thanks Maledicta */
#include "/players/zeus/closed/all.h"

string awho;
object bweapon, gob, USER;
int vigor_bonus = 0;
int illusioned = 0;

set_fallen_shadow(object obj){
  bweapon = obj;
  USER = environment(obj);
  gob = present("circle_object", USER);
  if(!gob)
  {
    write("Error\n");
    return;
  }
  shadow(bweapon,1);
}

remove_fallen_shadow(){
  shadow(bweapon,0);
  destruct(this_object());
  return 1;
}

query_fallen_shadow(){ return 1; }

set_illusioned(x){ illusioned = x; }
query_illusioned(){ return illusioned; }

wield(str){
  if(this_player()->query_guild_name() != "fallen")
  {
    write("The shadows make it impossible for you to use this weapon.\n");
    return 1;
  }
  if(bweapon->wield(str))
    return 1;
  return 0;
}


bonus(type, atk, nm, nmy, wn, tog){
  int f;
  string B, a,b, his, him, spc;
  his = atk->query_possessive();
  him = atk->query_objective();
  spc = "  ";
  f = random(6);
  if(tog == 1)
    B = BOLD+BLK;
  else if(tog == 2)
    B = HIY;
  switch(f)
  {
    case 0:
      a = "You leap into the air...\n"+spc;
      b = nm+" leaps into the air...\n"+spc;
      break;
    case 1:
      a = "You swiftly dodge to the left...\n"+spc;
      b = nm+" swiftly dodges to the left...\n"+spc;
      break;
    case 2:
      a = "You swiftly dodge to the right...\n"+spc;
      b = nm+" swiftly dodges to the right...\n"+spc;
      break;
    case 3:
      a = "You charge forward at "+nmy+"...\n"+spc;
      b = nm+" charges forward at "+nmy+"...\n"+spc;
      break;
    case 4:
      a = "You lean back then jump at "+nmy+"...\n"+spc;
      b = nm+" leans back then jumps at "+nmy+"...\n"+spc;
      break;
    case 5:
      a = "You spin swiftly through "+nmy+"'s attack...\n"+spc;
      b = nm+" spins swiftly through "+nmy+"'s attack...\n"+spc;
      break;
  }

  if(type == "sword" || type == "dagger" || type == "blade" ||
    type == "katana" || type == "swords" || type == "blades")
  {
    f = random(6);
    switch(f)
    {
      case 0:
        a += "You"+B+" slash "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" slashes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 1:
        a += "You drive your "+wn+" into "+nmy+".\n";
        b += nm+" drives "+his+" "+wn+" into "+nmy+".\n";
        break;
      case 2:
        a += "You"+B+" stab "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" stabs "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 3:
        a += "You"+B+" cleave "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" cleaves "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 4:
        a += "You bring your "+wn+" down into "+nmy+".\n";
        b += nm+" brings "+his+" "+wn+" down into "+nmy+".\n";
        break;
      case 5:
        a += "You plunge your "+wn+" into "+nmy+".\n";
        b += nm+" plunges "+his+" "+wn+" into "+nmy+".\n";
        break;
    }
  } /* end blade type wep */

  else if(type == "axe" || type == "club" || type == "hammer" ||
    type == "mace" || type == "morningstar")
  {
    f = random(7);
    switch(f)
    {
      case 0:
        a += "You"+B+" crush "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" crushes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 1:
        a += "You"+B+" smash "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" smashes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 2:
        a += "You"+B+" bash "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" bashes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 3:
        a += "You bring your "+wn+B+" smashing "+NORM+"down into "+nmy+".\n";
        b += nm+" brings "+his+" "+wn+B+" smashing "+NORM+
          "down into "+nmy+".\n";
        break;
      case 4:
        a += "You bring your "+wn+B+" crashing "+NORM+"into "+nmy+".\n";
        b += nm+" brings "+his+" "+wn+B+" crashing "+NORM+
          "into "+nmy+".\n";
        break;
      case 5:
        a += "You send "+nmy+" flying with your "+wn+".\n";
        b += nm+" sends "+nmy+" flying with "+his+" "+wn+".\n";
        break;
      case 6:
        a += "You knock "+nmy+" back with your "+wn+".\n";
        b += nm+" knocks "+nmy+" back with "+his+" "+wn+".\n";
        break;
    }
  } /* end club type wep */

  else if(type == "trident" || type == "pole" || type == "pike" ||
    type == "spear" || type == "polearm" || type == "stick")
  {
    f = random(5);
    switch(f)
    {
      case 0:
        a += "You"+B+" impale "+NORM+nmy+" on your "+wn+".\n";
        b += nm+B+" impales "+NORM+nmy+" on "+his+" "+wn+".\n";
        break;
      case 1:
        a += "You"+B+" drive "+NORM+"your "+wn+" into "+nmy+".\n";
        b += nm+B+" drives "+NORM+his+" "+wn+" into "+nmy+".\n";
        break;
      case 2:
        a += "You"+B+" slam "+NORM+"your "+wn+" into "+nmy+".\n";
        b += nm+B+" slams "+NORM+his+" "+wn+" into "+nmy+".\n";
        break;
      case 3:
        a += "You"+B+" ram "+NORM+" your "+wn+" into "+nmy+".\n";
        b += nm+B+" rams "+NORM+his+" "+wn+" into "+nmy+".\n";
        break;
      case 4:
        a += "You"+B+" stick "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" sticks "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
    }
  } /* end spear type wep */

  else
  {
    f = random(4);
    switch(f)
    {
      case 0:
        a += "You"+B+" crush "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" crushes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 1:
        a += "You"+B+" smash "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" smashes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 2:
        a += "You"+B+" bash "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" bashes "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
      case 3:
        a += "You"+B+" hit "+NORM+nmy+" with your "+wn+".\n";
        b += nm+B+" hits "+NORM+nmy+" with "+his+" "+wn+".\n";
        break;
    }
  } /* end other types of weps */

  tell_object(USER, "  "+a+"\n");
  tell_room(environment(USER), "  "+b+"\n", ({ USER }));
}


hit(atk){
  int one,two,three,four, r, base, tog, end;
  string nm, nm2, msg1, msg2, nmy, nmy2, nmo;
  string nmp, blah, wn, type, msg, more;
  USER = environment(bweapon);
  if(!gob)
    gob = present("circle_object", USER);
  if(!gob)
    gob = present("circle_object", environment(USER));
  if(gob)
    end = (int)gob->query_endurance();
  else
  {
    tell_object(USER, "This weapon has errored, please contact Zeus.\n");
    return 0;
  }
  vigor_bonus = gob->query_vigor_bonus();
  base = 0;
  tog = 0;

  if(end < 0)  /* sps drain if negative endurance */
    USER->add_spell_point(-1);

/*  if there is light and endurance is positive */
  if(!gob->light_check() && end > 0)
  {

    one = random(4);     /* basic messages */
    two = random(7);     /* wep related msgs */
/*
    three = random(10);
    four = random(14);
*/
    nm2 = (string)USER->query_real_name();
    nmo = (string)USER->query_possessive();
    nmp = (string)USER->query_objective();
    blah = (string)USER->query_pronoun();
    wn = (string)bweapon->query_type();
    if(!wn)
      wn = (string)bweapon->query_name();
    type = (string)bweapon->query_type();
    nm = capitalize(nm2);
    if(atk)
    {
      nmy = (string)atk->query_name();
      nmy2 = (string)atk->query_objective();
    }
    else
    {
      nmy = nmo+" enemy";
      nm2 = "him";
    }

    /* low armor increases fighting ability and sp regen */
    if(random((int)USER->query_ac()) == 0)
    {
      USER->add_spell_point(1);
      base += 2;
    }

    /* if focused whlie wielding a wep get wc bonus based on duration */
    if((r = gob->query_focus()) > 0)
    {
      base += (r + 2);
      r = random(8);
      switch(r)
      {
        case 0:
          msg1 = "Shadows surge down "+nm+"'s arms and into "+nmo+" "+wn+".\n";
          msg2 = "Shadows surge down your arms and into your "+wn+".\n";
          break;
        case 1:
          msg1 = nm+"'s focus causes shadows to ripple across "+nmo+" "+wn+".\n";
          msg2 = "Your focus causes shadows to ripple across your "+wn+".\n";
          break;
        case 2:
          msg1 = nm+"'s focus of the shadows drives "+nmp+" to fight harder.\n";
          msg2 = "Your focus of the shadows drives you to fight harder.\n";
          break;
        case 3:
          msg1 = nm+" seems one with "+nmo+" "+wn+".\n";
          msg2 = "Your focus of the shadows makes you feel one with your "+wn+".\n";
          break;
        case 4..7:
          break;
      }
      if(r < 4)
      {
        tell_room(environment(USER), BOLD+BLK+msg1+NORM, ({ USER }));
        tell_object(USER, BOLD+BLK+msg2+NORM);
      }
    }

    if(!one)
    {
      r = random(17);
      switch(r)
      {
        case 0:
          msg1 = "Dark shadows swirl around "+nm+".\n";
          msg2 = "Dark shadows swirl around you.\n";
          break;
        case 1:
          msg1 = "Dark shadows rise up around "+nm+".\n";
          msg2 = "Dark shadows rise up around you.\n";
          break;
        case 2:
          msg1 = "Dark shadows flit across the room.\n";
          msg2 = msg1;
          break;
        case 3:
          msg1 = "Dark shadows dance across "+nm+".\n";
          msg2 = "Dark shadows dance across you.\n";
          break;
        case 4:
          msg1 = nm+" beckons as the shadows come alive.\n";
          msg2 = "You beckon as the shadows come alive.\n";
          break;
        case 5:
          msg1 = nm+" waves a hand as shadows rise up.\n";
          msg2 = "You wave a hand as shadows rise up.\n";
          break;
        case 6:
          msg1 = "A dark shadow drifts through the room.\n";
          msg2 = msg1;
          break;
        case 7:
          msg1 = nm+" grins as shadows rise up around "+nmp+".\n";
          msg2 = "You grin as shadows rise up around you.\n";
          break;
        case 8:
          msg1 = nm+" casts a wave of shadows over the room.\n";
          msg2 = "You cast a wave of shadows over the room.\n";
          break;
        case 9:
          msg1 = "Light and darkness swirl around "+nm+".\n";
          msg2 = "Light and darkness swirl around you.\n";
          break;
        case 10:
          msg1 = nm+" beckons as light and darkness envelop "+nmp+".\n";
          msg2 = "You beckon as light and darkness envelop you.\n";
          break;
        case 11:
          msg1 = "Light and darkness cascade over "+nm+".\n";
          msg2 = "Light and darkness cascade over you.\n";
          break;
        case 12:
          msg1 = "Shadows pulsate over "+nm+"'s body.\n";
          msg2 = "Shadows pulsate over your body.\n";
          break;
        case 13:
          msg1 = "The shadows pulse violently.\n";
          msg2 = msg1;
          break;
        case 14:
          msg1 = nm+" is lifted up by the shadows as "+blah+" fights.\n";
          msg2 = "As you fight you are lifted up by the shadows.\n";
          break;
        case 15:
          msg1 = nm+" bows "+nmo+" head and whispers softly...\n"+
            "The shadows converge on "+nmy+", weakening "+nmy2+".\n"; 
          msg2 = "You bow your head and whisper softly...\n"+
            "The shadows converge on "+nmy+", weakening "+nmy2+".\n"; 
          break;
        case 16:
          msg1 = nm+" cackles as the shadows encircle "+nmp+".\n";
          msg2 = "You cackle as the shadows encircle you.\n";
          break;
      }
      if(!random(2))
      {
        tell_room(environment(USER), BOLD+BLK+msg1+NORM, ({ USER }));
        tell_object(USER, BOLD+BLK+msg2+NORM);
      }
      else
      {
        tell_room(environment(USER), msg1, ({ USER }));
        tell_object(USER, msg2);
      }
    } /* end if not one */
  
    else if(!random(two))
    {
      if(!random(2))  /* shadow msgs */
      {
        more = BOLD+BLK+"Shadows "+NORM;
        tog = 1;
        r = random(6);
      }
      else            /* light msgs */
      {
        more = HIY+"Beams of light "+NORM;
        tog = 2;
        r = 4+random(4);
      }
      base += 1;  /* bonus for wep special */

      switch(r)
      {
        case 0:        msg = "writhe along";         break;
        case 1:        msg = "dance along";          break;
        case 2:        msg = "seem to cling to";     break;
        case 3:        msg = "drift over";           break;
        case 4:        msg = "explode from";         break;
        case 5:        msg = "emanate from";         break;
        case 6:        msg = "glisten along";        break;
        case 7:        msg = "burn along";           break;
      }

      if(type == "sword" || type == "dagger" || type == "blade" ||
        type == "katana" || type == "swords" || type == "blades")
      {
        msg1 = more+msg+" the blade of "+nm+"'s "+wn+".\n";
        msg2 = more+msg+" the blade of your "+wn+".\n";
      }
      else if(type == "axe" || type == "club" || type == "hammer" ||
        type == "mace" || type == "morningstar")
      {
        msg1 = more+msg+" the head of "+nm+"'s "+wn+".\n";
        msg2 = more+msg+" the head of your "+wn+".\n";
      }
      else if(type == "trident" || type == "pole" || type == "pike" ||
        type == "spear" || type == "polearm" || type == "stick")
      {
        msg1 = more+msg+" the length of "+nm+"'s "+wn+".\n";
        msg2 = more+msg+" the length of your "+wn+".\n";
      }
      else
      {
        msg1 = "  "+more+msg+" "+nm+"'s "+wn+".\n";
        msg2 = "  "+more+msg+" your "+wn+".\n";
      }

      tell_room(environment(USER), "\n"+msg1+"\n", ({ USER }));
      tell_object(USER, "\n"+msg2+"\n");

      if(!random(3))
      {
        base += 1;  /* bonus for wep special */
        bonus(type, atk, nm, nmy, wn, tog);
      }

    } /* end if not two */
/*
    else if(!random(three))
    {
    }
*/
    if(present("weaken_counter", atk) && (!one || !two && !random(3)))
      gob->wfmsgs(atk);

    if(gob->query_vigor())
      gob->vigor_msgs();

    if(present("weaken_counter", atk) && gob->query_vigor())
      base += 1;

  } /* end if light and pos endurance */

/* This checks if there is a special in the wep already, if so, do it */
  if(bweapon->query_hit_func())
  /* changed from weapon_hit to hit by illarion to make sure it's compatible
     with all weapons - may 2005 */
    return (base + call_other(bweapon, "hit", atk) + vigor_bonus);

  return base + vigor_bonus;
}

/* Add to the short */
short(){ 
  return bweapon->short()+BOLD+BLK+" [Wrapped in a Shadow]"+NORM;
}

/* Additions to the long. */
long(){ 
  bweapon->long(); 
  write(BOLD+BLK+"The "+bweapon->query_name()+
    " is cloaked in a dark shadow.\n"+NORM);
}


query_weight(){  return 1; }    /* shadows make it lighter */

query_info(){ return "csw"; }   /* used in wielding */

query_value(){ return 1; }      /* almost worthless */

query_save_flag(){ return 1; }  /* does not save */
