#include "../defs.h"

inherit SPELL;

void reset(int x)
{
  if(x) return;
  set_spell(
    "Symbol: Pain", /* spell name */
    0,              /* hp cost */
    0,              /* sp cost */
    3000,           /* sac cost */
    1,              /* fae req */
    1,              /* glevel req */
  );
}

varargs status main(string str, object gob, object player)
{
  object targ;
  int dam;
  if(!(targ = spell_ok(0,"attack:player",str)))
    return 1;

  if((int)gob->query_symbol_pain())
    return 1;

  dam = 10 + random(21);
  if((int)gob->query_talent())
    dam += 5 + random(11);
  switch((int)gob->query_glevel())
  {
  	case 0..1: break;
  	case 2:    dam += 1+random(2); break;
  	case 3:    dam += 1+random(3); break;
  	case 4:    dam += 1+random(4); break;
  	case 5:    dam += 1+random(5); break;
  	case 6:    dam += 2+random(4); break;
  	case 7:    dam += 2+random(6); break;
  	case 8:    dam += 3+random(9); break;
  	default:   break;
  }
  switch((int)gob->query_fae())
  {
  	case 0:      break;
  	case 1..5:   dam += 1+random(2); break;
    case 6..10:  dam += 1+random(3); break;  
    case 11..15: dam += 1+random(4); break;
    case 16..20: dam += 2+random(5); break;
    case 21..23: dam += 2+random(6); break;
    case 24..26: dam += 3+random(8); break;
    case 27..29: dam += 4+random(10); break;
    case 30:     dam += 6+random(13); break; 
    default:     break;
  								
  }
  tell_object(player,
    "You quickly trace the symbol of PAIN in the air\n"+
    "before "+(string)targ->QN+".\n");
    
  learned_say(
    (string)player->QN+" quickly traces the symbol of PAIN in the\n"+
    "air before "+(string)targ->QN+".\n");
    
  other_say(
    (string)player->QN+" quickly traces a strange symbol in the\n"+
    "air before "+(string)targ->QN+".\n");
    
  tell_room(environment(player),
    (string)targ->QN+" clutches at "+(string)targ->QP+" head in pain.\n");
  
  if(query_ip_number(targ))
    dam /= 4;
  else
    dam /= 2;
    
  targ->hit_player(dam, "other|ice");  
  targ->hit_player(dam, "magical");
  gob->set_symbol_pain(1);
  
  if(!(targ->query_attack())) 
    targ->attack_object(player);
    
  return 1;
}

