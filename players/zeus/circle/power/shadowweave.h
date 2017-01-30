/*  This version of shadowweave takes the original weapon, keeps its
   original features intact, and makes it a shadow wep.
   I like this, because it encourages them to get good weps,
   rather than always get a bloodlust or phbs to weave.

   Shadows the wep to add new features to it. - added 6/22/00

*/

shadowweave(string str){
  object item, nitem, comp, shadow;
  string y, z;	
  if(!PO->query_skills("weave")) return 0;
  if(PO->light_check()) return 1;
  if(!str)  return 0;
  comp = present("guild_comp_pouch", User);
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_sgem())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  item = present(str, environment(previous_object()));
  if(!item && str == "illusion")
  {
    object *a, tgt, illusion, i_shadow;
    int b,c;
    string d,e,f;
    a = all_inventory(User);
    b = 0;
    c = sizeof(a);
    while(b < c && !tgt)
    {
      if(a[b]->query_info() == "csw")
        tgt = a[b];
      else
        b++;
    }
    if(!tgt)
    {
      TOU"You do not have a weaved weapon to make an illusion of.\n");
      return 1;
    }

    if(tgt->query_illusioned())
    {
      TOU"An illusion has already been formed from this weapon.\n");
      return 1;
    }

    d = file_name(tgt);
    sscanf(d,"%s#%s",e,f);

    if(e == "obj/weapon")
    {
      tell_object(USER, tgt->short()+
        " is too generic to make an illusion of.\n");
	    return 0;
    }

    tgt->set_illusioned(1);
    illusion = clone_object("/"+e);
    illusion -> set_value(0);
    illusion -> set_class(0);
    i_shadow = clone_object("/players/zeus/circle/OBJ/illusion_shadow.c");
    i_shadow->set_illusion_shadow(illusion);
    move_object(illusion, User);

    TOU "You take the shadow gem in your hand and squeeze it...\n"+
      BOLD+BLK+"You weave an illusion of "+tgt->query_name()+".\n"+NORM);

    if(!random(6))
    {
      TOU "The shadow gem melts into your hand and is gone.\n");
      comp->use_sgem();
    }
    else
      TOU "You place the shadow gem back into your pouch.\n");

    TRU User->QN+" folds the shadows together to create something new.\n",
      ({User}));
    
    User->add_spell_point((-(User->query_msp())+20)/2);
    PO->add_endurance(-20);
    PO->energy_check();

    return 1;
  }
  if(!item)
  {
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(item && item->weapon_class() && item->query_value() > 0)
  {
    if(item->query_wielded())
    {
      TOU"You must unwield it first.\n");
      return 1;
    }
    if(!PO->spell_failure(3)) return 1;
    if(PO->casting_check()) return 1;

    TOU
      "You weave the shadows into the "+item->QN+"...\n"+
      "Folding shadow upon shadow, the "+item->QN+" begins to change...\n\n"+
      BOLD+BLK+"You enshroud the "+item->QN+" in a mass of shadows.\n"+NORM);
    TRU User->QN+" folds a shadow around "+User->POS+" "+item->QN+".\n", 
      ({User}));
    User->add_spell_point(-(User->query_msp())+20);
    User->add_hit_point(-100);
/*
    sscanf(file_name(item),"%s#%s",y,z);
*/
    PO->set_weave(1);
/*
    nitem = clone_object(y);
    nitem->set_info("csw");
    nitem->set_read(BOLD+BLK+"The weapon is cloaked in a dark shadow.\n"+NORM);
    nitem->set_info("csw");
    nitem->set_save_flag(1);
    nitem->set_value(1);
    nitem->set_weight(1);
    destruct(item);
    move_object(nitem, User);
*/
    comp->use_sgem();
    PO->add_endurance(-50);
    PO->energy_check();
    shadow = clone_object("/players/zeus/circle/OBJ/wep_shadow.c");
    shadow->set_fallen_shadow(item);
    return 1;
  }
  else
  {
    TOU"You can't weave that.\n");
    return 1;
  }
}
