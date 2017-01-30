object caster;
object target;

string *valid_dam_types;

reset(x) {
   if(x) return;
   valid_dam_types=({
         "physical", "magical", "other|dark", "other|light",
         "other|water", "other|fire", "other|wind", "other|earth",
         "other|ice", "other|electric", "other|laser", "other|evil",
         "other|good", "other|poison", "other|mental" });
}
void start(object ob1, object ob2)
{
   target = ob1;
   caster = ob2;
   shadow(target, 1);
}

void stop()
{
   shadow(target, 0);
   destruct(this_object());
}

/* Translate hit_player to do_damage, just like in player.c */

hit_player(dam1, type1, dam2, type2){
   return do_damage(({dam1,dam2}),({type1,type2}));
}

int do_damage(mixed dam, mixed type)
{
   int total;
   int i;
  if(!caster) stop();
 if(!present(target,environment(caster))){ caster->stop(); command("unprotect",caster); return 1; }
 if(!present(caster,environment(target))){ caster->stop(); command("unprotect",caster); return 1; }
   if(caster->query_sp() < 10){ tell_object(caster, "You do not have the spellpoints to keep protecting "+(string)target->query_name()+"\n");
      caster->stop();
      command("unprotect",caster);
      return 1; }
   
   /* Just cut all the damage in half. */
   
   for(i = 0; i < sizeof(dam); i++)
   {
      if(!type[i]) type[i]="physical";
      if(member_array(type[i], valid_dam_types) > -1)
         {
         total+=(int)target->do_damage(({dam[i]/2}),({type[i]}));
         total+=(int)caster->do_damage(({dam[i]/2}),({type[i]}));
       }
      else
         total += (int)target->do_damage(({dam[i]}),({type[i]}));
   }
   
   /* Emotes */
   
   if(!random(4))  /* Dilute the spam a little. */
      {
      tell_object(caster, "You try to block some of the blow!\n");
      tell_object(target, (string)caster->query_name()
         +" blocks some of the blow!\n");
      tell_room(environment(caster), (string)caster->query_name() + 
         " tries to protect "+
         (string)target->query_name()+"!\n",
         ({ caster, target }));
   }
   caster->add_spell_point(-10);
   return total;  /* from return dam; */
}


void heal_self(int x)
{
   if(x < 0)
      {
      if(!caster) stop();
      target->heal_self(x/2);
      caster->heal_self(x/2);
      if(!random(4))  /* Dilute the spam a little. */
         {
         tell_object(caster, "You try to block some of the blow!\n");
         tell_object(target, (string)caster->query_name()+
            " blocks some of the blow!\n");
         tell_room(environment(), (string)caster->query_name()+
            " tries to protect "+(string)target->query_name()+"!\n",
            ({ caster, target }));
      }
   }
   /* verte */
   
   else target->heal_self(x);
}

query_shield_shadowed() { return 1; }
