/***********************************************************************
| custom object for "immortal" monsters, to set up
| the "body" after they die
| set_immortal(1); must be used in reset()
| set_chat_response("key","text"); will cause "text" to be printed to
| the room if the monster sees "key"
| set_chat_response("key","$function$"); will pass the first word
| of the string the monster just got to function in this_object();
| (usually the first word will be the player's name)
| set_attacks(x); will cause the monster to attack x times/round
| set_x_attack_chance(x); (1-100) sets the chance the monster has of
| getting off each extra attack
| set_multi_attack(x); will make the monster hit ALL present attackers
|                      1 = 1 attack each
|                      2 = until attacks from set_attacks are exausted
| set_dodge_chance(x); (1-100) chance to dodge physical damage
| set_counter_chance(x); (1-100) chance to counter physical damage
| set_attack_weakest(x) (0 or 1) always attack the weakest attacker
| set_deathblow_chance(x); (1-100) chance of scoring a deathblow on a
|                                  weakened target
| set_deathblow_health(x); (1-100) percent of health the target must be
|                                  below before a deathblow is attempted
|    (deathblows are wc*4 physical damage)
| add_emote(type,target,room); see below
| set_bounce_tank_chance(x); (1-100) set the chance the tank will be "bounced"
|     from the room, one one of the locations from:
| add_bounce_location(string) add a possible location for the tank to be
|     bounced to.  If there's more than 1, one is picked randomly
| remove_bounce_location(string) remove a location
| Thanks to Khrell for the grabbing bags idea
| set_grab_bag(x) (0 or 1) 1 means the monster will pick up any non-living
| containers (can_put_and_get() returns 1) dropped in its room.
| set_grab_chance(x) (1-100) chance of picking up a bag or is_heal() item each hb
|                            defaults to 100
| set_use_heals(x) (0 or 1) monster will check for is_heal() items in its inventory
|                       when injured and attempt to use them.
| set_use_heals_health(x) (1-99) how much a monster must be injured before it looks
|                       for and attempts to use a heal.
| set_healing_factor(x) (0-100) monster will heal x% of its health for each
|                       hb it is not in combat
|
***********************************************************************/

#include "/players/illarion/dfns.h"
inherit "obj/monster";
int immortal;
string *keys; string *chats;
string weapon_path;
int weapon_drawn;
int mon_attacks;
int multi_attack;
int ex_att_chance;
int dodge_chance;
int counter_chance;
status attack_weakest;
int deathblow_chance;
int deathblow_health;
int bounce_tank_chance;
int healing_factor;
string *bounce_locations;
mapping emotes;
status grab_bag;
int grab_chance;
status use_heals;
int use_heals_health;
object cur_att;
mixed *backup_spells;

#define NONPHYS 30000/20000

monster_died() {
  object ob;
  if(!immortal) return 0;
  tell_room(environment(this_object()),
    query_name()+" dies very slowly, "+query_possessive()+" weapon slipping "+
    "to the ground.\n");
  ob=clone_object(HOBJ+"imm_body.c");
  ob->set_name(query_name());
  move_object(ob,environment(this_object()));
  destruct(present("corpse",environment(this_object())));
  return 0;
}
set_immortal(x) {
  immortal=x;
  set_dead_ob(this_object());
}
set_multi_attack(x) {
  multi_attack=x;
  calc_wc_bonus();
}
query_immortal() { return immortal; }
set_attacks(int x) {
  if(x>1) mon_attacks = x;
  else mon_attacks = 1;
}
set_x_attack_chance(int x) {
  if(x<1) x=0;
  if(x>100) x=100;
  ex_att_chance=x;
}
set_attack_weakest(status arg) {
  if(arg)
    attack_weakest=1;
  else
    attack_weakest=0;
}
set_bounce_tank_chance(int x) {
  if(x<0) x=0;
  if(x>100) x=100;
  bounce_tank_chance=x;
}
add_bounce_location(string loc) {
  if(!bounce_locations) bounce_locations=({});
  bounce_locations+=({loc});
}
remove_bounce_location(string loc) {
  if(!bounce_locations) return;
  if(member_array(loc,bounce_locations)!=-1)
    bounce_locations-=({loc});
}
set_deathblow_chance(int x) {
  if(x<1) x=0;
  if(x>100) x=100;
  deathblow_chance=x;
}
set_deathblow_health(int x) {
  if(x<1) x=1;
  if(x>100) x=100;
  deathblow_health=x;
}
set_dodge_chance(int x) {
  if(x<1) x=0;
  if(x>100) x=100;
  dodge_chance=x;
  /*
  RegisterArmor(this_object(),({"physical",pac,0,"dodge_and_counter"}));
  */
  set_armor_params("physical",pac,0,"dodge_and_counter");
}
set_counter_chance(int x) {
  if(x<1) x=0;
  if(x>100) x=100;
  counter_chance=x;
  set_armor_params("physical",pac,0,"dodge_and_counter");
  /*
  RegisterArmor(this_object(),({"physical",pac,0,"dodge_and_counter"}));
  */
}
set_grab_bag(x) {
  grab_bag= !(!x);
}
set_grab_chance(x) {
  if(x>100 || x<1)
    x=100;
  grab_chance=x;
}
set_use_heals(x) {
  use_heals= !(!x);
}
set_use_heals_health(x) {
  if(x>99) x=99;
  else if(x<1) x=1;
  use_heals_health=x;
}
set_healing_factor(x) {
  if(x<1) x=0;
  if(x>100) x=100;
  healing_factor=x;
}
add_chat_response(string key,string response) {
  if(!keys) keys=({});
  if(!chats) chats=({});
  keys+= ({key});
  chats+= ({response});
}
do_say(string stuff) {
  string func;
  string by;
  int ind;
  sscanf(stuff,"%d:%s",ind,by);
  if(sscanf(chats[ind],"$%s$",func))
    call_other(this_object(),func,by);
  else
    tell_room(environment(),chats[ind],({this_object()}));
}
check_match(string in,string by) {
  string tmp;
  int x,size;
  size=sizeof(keys);
  for(x=0;x<size;x++)
  if(sscanf(in,"%s"+keys[x]+"%s",tmp,tmp)) {
    call_out("do_say",2,x+":"+by);
    break;
  }
}
attacking_me(object ob) {
  return (ob->query_attack()==this_object());
}

attempt_deathblow(object who) {
  int chp,mhp;
  chp=(int)who->query_hp();
  mhp=(int)who->query_mhp();
  if(!mhp) mhp=100;
  if(chp * 100 / mhp < deathblow_health && random(100) < deathblow_chance) {
    do_emote("deathblow",who,environment());
    who->do_damage(({pwc*4}),({"physical"}));
  }    
}
/* Monsters don't have these functions normally so they're needed for
 using heals to work for them.  intox is simply ignored in the interest
 of being nasty
*/
add_hit_point(int x) {
  if(x>0)
    hit_point+=x;
  if(hit_point>max_hp)
    hit_point=max_hp;
}
/* For now this will do nothing.  It could trigger spells, however...

add_spell_point(int x) {
}
*/
use_a_heal() {
  object *inv;
  int x;
  inv=deep_inventory(this_object());
  x=sizeof(inv);
  while(x--) {
    if(inv[x]->is_heal()) {
      string *cmd;
      if(environment(inv[x]) != this_object() && transfer(inv[x],this_object()))
        return;
      cmd=inv[x]->query_cmds();
      if(sizeof(cmd)) {
        command(cmd[0]+" "+inv[x]->query_name(),TO);
        return;
      }
    }
  }
}

attack() {
  int x;
  object *ppl;
  object orig_att;
  int n,size;
  int cast_spells;
  int min_diff,s;
  
  if(grab_bag && environment() && (grab_chance==0 || random(100) < grab_chance)) {
    ppl=all_inventory(environment());
    x=sizeof(ppl);
    while(x--) {
      if(!living(ppl[x]) && (ppl[x]->can_put_and_get() || ppl[x]->is_heal()))
        if(!transfer(ppl[x],this_object())) {
          string bname;
          bname=NAME(ppl[x]);
          if(!bname)
            bname=ppl[x]->short();
          if(bname)
            tell_room(ENV(TO),cap_name+" takes "+bname+".\n",({TO}));
          x=0;
        }
    }
  }
  if(healing_factor && (!attacker_ob || !present(attacker_ob,environment())) && hit_point < max_hp) {
    do_emote("healing_factor",TO,ENV(TO));
    hit_point+=max_hp*healing_factor/100;
    if(hit_point > max_hp)
      hit_point=max_hp;
  }
  if(use_heals && max_hp && ((!use_heals_health && hit_point<max_hp) || hit_point*100/max_hp < use_heals_health)) {
    use_a_heal();
  }
  if(attacker_ob && weapon_path && !weapon_drawn) {
    object wob;
    weapon_drawn=1;
    wob=clone_object(weapon_path);
    if(environment(this_object())) tell_room(environment(this_object()),
      "As "+query_pronoun()+" is attacked, "+query_name()+
      " pulls a weapon from nowhere!\n",({this_object()}));
    move_object(wob,this_object());
    command("wield "+wob->query_name());
  }
  if(mon_attacks <= 0) mon_attacks = 1;
  if(ex_att_chance <=0) ex_att_chance=100;
  x=mon_attacks-1;

  if(attack_weakest) {
    object new_targ;
    ppl=filter_array(all_inventory(environment(this_object())),"attacking_me",this_object());
    s=sizeof(ppl);
    if(s>1) {
      min_diff=50000;
      while(s--) {
        int new_diff;
        new_diff=((int)ppl[s]->query_ac()+1)*((int)ppl[s]->query_hp());
        if(new_diff<min_diff) {
          new_targ=ppl[s];
          min_diff=new_diff;
        }
      }      
      if(new_targ && new_targ != attacker_ob) {
        do_emote("change_attack",new_targ,environment());
        attacker_ob=new_targ;
      }
    }
  }
  if(multi_attack == 2) {
    ppl=all_inventory(ETO);
    ppl=filter_array(ppl,"attacking_me",TO);
    size=sizeof(ppl);
    x++; /* all attacks hit a random target */
    if(size)
      while(x && (ex_att_chance==100 || random(100) <= ex_att_chance)) {
        x--;
        already_fight=0;
        attacker_ob=ppl[random(size)];
        ::attack();
        if(!cast_spells) {
          cast_spells=1;
          backup_spells=spells;
          spells=0;
        }
      }
  } else {
    ::attack();
    cast_spells=1;
    backup_spells=spells;
    spells=0;
    if(!attacker_ob || !present(attacker_ob,environment())) return;
    while(x && (ex_att_chance==100 || random(100) <= ex_att_chance)) {
      x--;
      already_fight=0;
      ::attack();
    }
    if(multi_attack == 1) {
      ppl=all_inventory(environment(this_object()));
      ppl=filter_array(ppl,"attacking_me",this_object());
      ppl-=({attacker_ob});
      size=sizeof(ppl);
      ::attack();
      cast_spells=1;
      backup_spells=spells;
      spells=0;
      if((size=sizeof(ppl))) {
        orig_att=attacker_ob;
        say(query_name()+" spins around, attacking at blinding speed.\n");
        for(n=0;n<size;n++) {
          already_fight=0;
          attacker_ob=ppl[n];
          ::attack();
        }
        attacker_ob=orig_att;
      }
    }
  }
  if(cast_spells) {
    spells=backup_spells;
  }
  if(deathblow_chance) {
    if(multi_attack) {
      ppl=filter_array(all_inventory(environment(this_object())),"attacking_me",this_object());
      s=sizeof(ppl);
      while(s--)
        attempt_deathblow(ppl[s]);    
    } else {
      attempt_deathblow(attacker_ob);        
    }
  } 
  if(bounce_tank_chance && bounce_locations && random(100)< bounce_tank_chance) {
    string loc,msgin;
    loc=bounce_locations[random(sizeof(bounce_locations))];
    do_emote("bounce",attacker_ob,environment());
    transfer(attacker_ob,loc);
    command("look",attacker_ob);
    do_emote("bounce_arrive",attacker_ob,loc);
  }
}
catch_tell(string in) {
  string temp1,temp2;
  int x;
  ::catch_tell(in);
  if(attacker_ob || alt_attacker_ob || cur_att) return;
  sscanf(in,"%s %s",temp1,temp2);
  if(temp2 && temp1)
    check_match(lower_case(temp2),temp1);
}
set_weapon_path(str) {
  weapon_path=str;
}

/* Here's the code that calculates the extra worth.  basically each
 * additional attack depends on the one before it being successful
 */
void calc_wc_bonus() {
  int x,eff_wc,total_wc,y;
  int s;
  s=sizeof(weapon_params);
  if(s) {
    for(y=0;y<s;y+=3) {
      if( weapon_params[y]=="physical" )
        eff_wc+=weapon_params[y+1];
      else
        eff_wc+=weapon_params[y+1] * NONPHYS;
    }
  } else {
    eff_wc=pwc;
  }
  total_wc=0;  /* TODO: make this calculate all wc instead */
  if(pwc==0 || mon_attacks <= 1) return;
  for(x=2;x<=mon_attacks;x++) {
      eff_wc = eff_wc*ex_att_chance/100;
      total_wc+=eff_wc;
  }
  /* Treat the bonus for extra attacks like spell damage
     and use the average, not the full damage potential
     
  */
  /* This seems a bit light...  slightly more than half might be better
  total_wc/=2;
  */
  total_wc = (total_wc * 3) / 5;
  /* Add in a bit extra for counter-attacks */
  total_wc+=pwc*counter_chance/200;
  set_wc_bonus(total_wc);
}
/* Bonus for dodge chance and healing
*/
void calc_ac_bonus() {
  /* I'm pretty sure this isn't enough of a bonus for the monster
     being totally immune to physical damage a percentage of the
     time.  Recalulating as though it has an ac of 100 when it
     dodges
  set_ac_bonus((pac*dodge_chance/100)+healing_factor/2);
  */
  
  set_ac_bonus( (healing_factor/2) + dodge_chance);
}

calculate_worth() {
  calc_wc_bonus();
  calc_ac_bonus();
  return ::calculate_worth();
}

/*
 This can be used to quickly add emotes for certain situations.
 There are two messages, one for the target and one for the room
 passing a 0 or "" will result in that message being igmored.
 There are codes for the names and pronouns that change:
 monster: $MN$-name $MP$-possessive $MR$-pronoun $MO$-objective
 target: $TN$ $TP$ $TR$ $TO$

 Simple example:
 add_emotes("dodge",
            "$MN$ dodges your attack.",
            "$MN$ dodges $TN$'s attack.");

 You can add more than one emote for the same event.  One will
 be picked at random.

 If you're specifying emotes for a case when there is no target
 be careful not to use target codes

 The following emotes are implemented by other parts of the code:
 counter - when the monster launches a counter-attack
 dodge   - when the monster completely avoids physical damage
   (coming soon - dodge for other damage types)
 

 change_attack - when the monster switches to attacking its weakest
                 antagonist.  the target codes apply to the monster's
                 new victim
                 
 bounce - when the tank is ejected from the room
 bounce_arrive - displayed to the tank's new room

 healing_factor - message displayed during out-of-combat healing
  */

add_emote(type,target,room) {
  if(!emotes) emotes=([]);
  if(member(emotes,type))
    emotes[type]+=({target,room});
  else
    emotes += ([type:({target,room})]);
}

code_resolve(string code, object a) {
  string ret,tmp;
  status cap;
  if(sscanf(code,"C%s",tmp)) {
    cap=1;
    code=tmp;
  }
  switch(code) {
    case "MN": ret=query_name(); break;
    case "MP": ret=query_possessive(); break;
    case "MR": ret=query_pronoun(); break;
    case "MO": ret=query_objective(); break;
    case "TN": ret=(a?a->query_name():""); break;
    case "TP": ret=(a?a->query_possessive():""); break;
    case "TR": ret=(a?a->query_pronoun():""); break;
    case "TO": ret=(a?a->query_objective():""); break;
    default: ret=code;
  }
  return (cap?capitalize(ret):ret);
}

string parse_emote(string str, object a) {
  string before,mid,after;
  while(sscanf(str,"%s$%s$%s",before,mid,after)>=2)
    str=(before?before:"")+code_resolve(mid,a)+(after?after:"");
  return ansi_format(str,70);
}

do_emote(string type,object att,object room) {
  int x;
  string *messages;
  if(!emotes || !member(emotes,type))
    return;
  messages=emotes[type];
  x=sizeof(messages)/2;
  x=random(x)*2;
  if(att && messages[x] && messages[x]!="")
    tell_object(att,parse_emote(messages[x],att));
  if(room && messages[x+1] && messages[x+1]!="")
    tell_room(room,parse_emote(messages[x+1],att),
              att?({this_object(),att}):({this_object()})
             );
}

attacked_by(ob) {
  cur_att=ob;
  ::attacked_by(ob);
}

dodge_and_counter() {
  object att,room;
  room=environment();
  att=cur_att;
  if(!att) att=this_player();
  if(!att) return 0;
  if(random(100) < dodge_chance) {
    if(room)
      do_emote("dodge",att,room);
    return 10000;
  }
  if(!att || !room || !present(att,room)) return 0;
  if(random(100) < counter_chance) {
    object orig_att;
    orig_att=attacker_ob;
    attacker_ob=att;
    already_fight=0;
    do_emote("counter",att,room);
    ::attack();
    attacker_ob=orig_att;
  }
}

