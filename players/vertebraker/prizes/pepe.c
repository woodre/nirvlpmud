#include <ansi.h>

#define bp bodyparts[random(sizeof(bodyparts))]

static string *bodyparts;

inherit "/obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return;
  
  bodyparts=({
    RED+"head"+NORM,HIW+"neck"+NORM,RED+"torso"+NORM,
    RED+"leg"+NORM,HIW+"armbone"+NORM,HIW+"spine"+NORM,
    HIW+"shoulderblade"+NORM,RED+"hand"+NORM,HIW+"ribs"+NORM,
    RED+"calf"+NORM,RED+"thigh"+NORM,RED+"hamstring"+NORM,
    HIW+"collarbone"+NORM, RED+"cheek"+NORM,
  });
  set_name("A Hattori Hanzo Sword");
  set_alias("hanzo sword");
  set_type("sword");
  set_short("A Hanzo sword");
  set_long("\
A 27\" long blade hewn from the finest stainless Japanese steel,\n\
tamahagane, by the master craftsman, Hattori Hanzo. It has been\n\
stamped with a golden lion tempered into its hard, kawagane\n\
jacketed steel.\n\
This is a priceless item.\n");
  set_class(19);
  set_message_hit(({
   HIR+"RENDED"+NORM, "'s flesh from bone", /* mas */
   RED+"chopped"+NORM, " into thick gashes", /* smash */
   HIY+"minced"+NORM, " into tiny pieces", /* vh */
   YEL+"lacerated"+NORM, " deeply", /* hh */
   GRN+"hacked"+NORM+" into","", /* h */
   "scored a deep line across", "'s torso",
   "pierced","'s armor",
   }));
   set_hit_func(this_object());
   set_weight(2);
   set_value(0); /* priceless */
}

int two_handed(){
  return 1;
}

query_message_hit(tmp) {
  string *mess;
    mess = ({"'s "+bp,message_hit[0]});
  if (tmp < 40) {
    mess = ({"'s "+bp,message_hit[2]});
  }
  if (tmp < 35) {
    mess = ({"'s "+bp,HIK+"sliced"+NORM,});
  }
  if(tmp < 30) {
    mess = ({"'s "+bp,RED+"cut"+NORM,});
  }
  if (tmp < 25) {
    mess = ({"'s "+bp,message_hit[4]});
  }
  if (tmp < 20) {
    mess = ({"'s "+bp,YEL+"filleted"+NORM });
  }
  if (tmp < 15) {
    mess = ({"'s "+bp,message_hit[6]});
  }
  if (tmp < 10) {
    mess = ({"'s "+bp,message_hit[8]});
  }
  if(tmp < 7) {
    mess = ({"'s "+bp,"delicately traced a jagged line across"});
  }
  if (tmp < 4) {
    mess = ({"'s "+bp,message_hit[10]});
  }
  if (tmp == 1) {
    mess = ({"'s "+bp,message_hit[12]});
  }
  return mess;
}

id(str){
  if(wielded && caller() && caller()->query_type()=="shield"){
    write("You may not wear a shield while wielding this weapon.\n");
    return str == "notarmor";
  }
  if(str == "notweapon")

  {
    object *inv;
    int s;
    inv=all_inventory(environment());
    s=sizeof(inv);
    while(s--)
      if(inv[s]->query_type()=="shield" && inv[s]->query_worn())
      {
        write("You may not wield this weapon while wearing a shield.\n");
        return 1;
      }
  }

  return ::id(str) || str == "hattori hanzo sword";
}

short(){
  if(wielded_by){
    if(this_player()==wielded_by){
      return "Your Hanzo sword (wielded in both hands)";
    }
    else
      return wielded_by->query_name()+"'s Hanzo sword (wielded in both hands)";
  }
  else {
    return ::short();
  }
}

wield(str){
  int t;
  
  if(this_player() && this_player()->query_real_name() != "pepe") return;
  if(!wielded && id(str)){
    t= ::wield(str);
    if(wielded) {
      write("You wield the Hanzo sword in both hands.\n");
    }
    return t;
  }
  else return ::wield(str);
}

get_style(){
  string typ;
    switch(random(14)){
      case 0:
        typ = "Muso Jikiden Eishin Ryu";
        break;
      case 1:
        typ = "Omori Ryu";
        break;
      case 2:
        typ = "Iaido";
        break;
      case 3:
        typ = "Iaijitsu";
        break;
      case 4:
        typ = "Tenshin Shoden Katori Shinto Ryu";
        break;
      case 5:
        typ = "Muso Ryu of Hayashizaki Jinsuke Shigenobu";
        break;
      case 6:
        typ = "Shinkendo";
        break;
      case 7:
        typ = "Tameshi-giri";
        break;
      case 8:
        typ = "Dai Nihon Batto Ho";
        break;
      case 9:
        typ = "Nakanishi-ha Itto Ryu";
        break;
      case 10:
        typ = "Abe Ryu";
        break;
      case 11:
        typ = "Yagyu Shinkage";
        break;
      case 12:
        typ = "Niten Ichi";
        break;
      case 13:
        typ = "Yagyu Shingan";
        break;
    }
    return typ;
}  

deathblow(atk){

  string msg;
  
  switch(random(4)){
    case 0:
      msg = atk->query_name()
      +" is cut at every joint at once... and falls to the ground.\n"+
      atk->query_name()+"'s neck is slashed almost in half... making\n"+
      "a puppet of "+objective(atk)+".\n"+
      capitalize(possessive(atk))+" torso is cleaved in two... and drops"+
      " to the ground in defeat.\n";
      break;
    case 1:
      msg = "The blade of "+wielded_by->query_name()+"'s Hanzo sword flashes\n"+
      "silver and "+atk->query_name()+"'s head falls backwards on the ground.\n";
      break;
    case 2:
      msg = wielded_by->query_name()+" dips his Hanzo sword in a final, fatal salute.\n"+
      atk->query_name()+"'s head falls and rolls across the ground.\n";
      break;
    case 3:
      msg = "The Hanzo sword weaves an intricate pattern on "+atk->query_name()
      +"'s abdomen.\n"+
      "Entrails spill to the ground.\n"+
      atk->query_name()+"'s head splits like a melon left in the sun.\n"+
      atk->query_name()+" drops like a sack.\n";
      break;
  }
  
  tell_room(environment(atk),
    "\n"+BOLD+msg+NORM+"\n");
    
  {
    object obj;
    obj = clone_object("/obj/treasure");
    obj->set_id("head of "+lower_case(atk->query_name()));
    obj->set_alias("head");
    obj->set_short("The Head of "+atk->query_name());
    obj->set_long("\
A bloody, decapitated head.\n");
    move_object(obj, environment(atk));
  }
    
  atk->death();
}

weapon_hit(object atk){
  if(wielded_by->query_attrib("dex") > random(50)){
    string typ;
    int    ret;
    int    spec;
    int    times;
    
    if(atk->query_hp() <= (atk->query_mhp() / 10)){
      deathblow(atk);
      return;
    }
   
    times = 1 + random(this_player()->query_attrib("dex") / 10);
    
    while(times-- && atk)
    {
      string *mess;
      spec = 1 + random(this_player()->query_attrib("str") + 10);
      mess = query_message_hit(spec);
      
      typ = get_style();
      tell_room(environment(atk),
        wielded_by->query_name()+" invokes the Style of "+
        BOLD+typ+NORM+".\n",
      ({ wielded_by }));
      tell_object(wielded_by,
      "You invoke the Style of "+BOLD+typ+NORM+".\n");
      
      write("You "+mess[1]+" "+atk->query_name()+mess[0]+".\n");
      say(this_player()->query_name()+" "+mess[1]+" "+
        atk->query_name()+mess[0]+".\n");
      
      if(!random(4)){
        string msg;  
        switch(random(4))
        {
          case 0: 
            msg = "Particles of "+HIR+"flesh"+NORM
            +" float in the air like "+HIW+"Snow"+NORM+"!\n";
            break;
          case 1:
            msg = RED+"BLOOD"+NORM+" pools at the feet of "+
            atk->query_name()+".\n";
            break;
          case 2:
            msg = "Shards of "+HIW+"bone"+NORM+" shatter and "+
            "fall to the floor.\n";
            break;
          case 3:
            msg = "Minute pieces of "+YEL+"scalp"+NORM+" and "+
            BOLD+"hair"+NORM+" fly into the air!\n";
            break;
        }
        tell_room(environment(atk), msg);
      }
        
        
      atk->hit_player(1 + (spec * 4 / 3), "other|dark");
    }
    if (atk)
    {
      object wep;
      if((wep = atk->query_weapon()) ||
         (atk->is_npc() && (wep=present("weapon", atk))))
      {
        tell_object(wielded_by,
          "Your Hanzo sword clashes against "+atk->query_name()
          +"'s "+wep->query_short()+"!\n");
        tell_room(environment(wielded_by),
          wielded_by->query_name()+"'s Hanzo sword clashes against "+
          atk->query_name()+"'s "+wep->query_short()+"!\n",
          ({ wielded_by }));
        
        ret += (int)this_player()->query_attrib("str") / 3;
      }
    }
    return ret;
  }
}

add_wear(x) { return; }

count_misses() { return 1; }
count_hit_made() { return 1; }

get()
{
  if(this_player() && this_player()->query_real_name() == "pepe")
  {
    return 1;
  }
  else
    return 0;
}



