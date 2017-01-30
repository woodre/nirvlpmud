#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
        int damage, damage2, cost, ranhammer, chance;
        object attacker;
        object target;
        object victim;
        string msg1, msg2, msg3, tname;
        
        damage2 = 0;
        ranhammer = random(5);
        chance = random(100);
        
        if(PO->query_suspend())
        {
                write(YEL+"Aeolos"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
                return 1;
        }
        
        if(PO->query_AIR() < 2)
        {
                write(YEL+"Aeolos"+NORM+" says: You have not learned that ability yet!\n");
                return 1;
        }
        
        if(User->query_ghost()){
                return 1;
        }
        
        if(User->query_spell_dam()){
                write(YEL+"Aeolos"+NORM+" says: Slow down. You cannot attack again just yet!\n");
                return 1;
        }
        
        if(!str && !User->query_attack()){
                write(YEL+"Aeolos"+NORM+" says: I'm sorry but who are you attacking again?\n");
                return 1;
        }
        
        if(!str){
                attacker = (object)User->query_attack(); }
        if(!attacker){
                attacker = present(str, environment(User)); }
        if(!attacker || !present(attacker, environment(User))){
                write(YEL+"Aeolos"+NORM+" says: I'm sorry but there is no "+RED+str+NORM+" here.\n");
                return 1;
        }
        if(!living(attacker)){
                write(YEL+"Aeolos"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
                return 1;
        }
        
        switch(PO->query_lhammer()){
                case 400..500:
                damage = 35 + random(20);
                cost = 45;
                break;
                case 300..399:
                damage = 25 + random(15);
                cost = 33;
                break;
                case 200..299:
                damage = 20 + random(10);
                cost = 25;
                break;
                case 100..199:
                damage = 10 + random(5);
                cost = 13;
                break;
                default:
                damage = 10;
                cost = 10;
                break;
        }
        
                
        if(User->query_sp() < cost){
                write(YEL+"Aeolos"+NORM+" says: You are too drained to attempt this!\n");
                return 1;
        }
        

     tname = (string)attacker->query_name();
        switch(PO->query_lhammer()){
                case 400..500:
                msg1 = "raise your hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them, "+HIR+"A N N I H I L A T I N G"+NORM+" them into ash";
                msg2 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on you "+HIY+" Electrifying"+NORM+" you, "+HIR+"A N N I H I L A T I N G"+NORM+" them into ash";
                msg3 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying "+NORM+tname+HIR+" A N N I H I L A T I N G"+NORM+" them into ash";
                break;
                case 300..399:
                msg1 = "raise your hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them, "+YEL+"flesh "+NORM+"and "+HIW+"bone "+NORM+"explode everywhere";
                msg2 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on you "+HIY+"Electrifying"+NORM+" you, "+YEL+"flesh "+NORM+"and "+HIW+"bone "+NORM+"explode everywhere";
                msg3 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them, "+YEL+"flesh "+NORM+"and "+HIW+"bone "+NORM+"explode everywhere";
                break;
                case 200..299:
                msg1 = "raise your hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them as they fall down in complete "+HIR+"agony "+NORM+"";
                msg2 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on you "+HIY+"Electrifying"+NORM+" you as you fall down in complete "+HIR+"agony "+NORM+"";
                msg3 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them as they fall down in complete "+HIR+"agony "+NORM+"";
                break;
                case 100..199:
                msg1 = "raise your hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them as they smoke and smolder";
                msg2 = " raises "+User->query_possessive()+" hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on you "+HIY+"Electrifying"+NORM+" you as you smoke and smolder";
                msg3 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+ HIY+" Electrifying"+NORM+" them as they smoke and smolder";
                break;
                default:
                msg1 = "raise your hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+", slightly grazing them";
                msg2 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on you, slightly grazing you";
                msg3 = " raises "+User->query_possessive()+"  hands to the clouds calling forth a"+YEL+" hammer "+NORM+"of "+HIY+"lightning"+NORM+" as it crashes down on "+tname+", slightly grazing them";
                break;
        }
        
        if(PO->query_airbond())
        {
                damage *= 4;
                damage /= 3;
        }
        
        if(attacker->is_sprayed())
        {
                damage /= 5;
                damage *= 6;
        }
    
        if(damage > 50)
        {
           damage2 = damage - 50;
           damage = 50;
        }
      victim = (object)this_player()->query_attack();
      this_player()->set_spell_dam(1);
      this_player()->add_spell_point(-cost);
      write("You "+msg1+"!\n");
      say(User->query_name()+msg3+"!\n");
      attacker->do_damage(({damage}), ({"other|air"}));
  if(victim) attacker->do_damage(({damage2}), ({"other|air"}));
/*
      attacker->hit_player(damage, "other|air");
      attacker->hit_player(damage2, "other|air");

        User->spell_object(attacker, "lhammer", damage, cost, "You "+msg1+".\n", User->query_name()+msg2+".\n", User->query_name()+msg3+".\n");
        User->set_spell_dtype("other|air");
       attacker->do_damage(({damage2}), ({"other|air"}));
*/

        if(PO->query_airshroud())
        {
                if(chance < 15)
                {
                        write(YEL+"\n\nAeolos grants you the energy to attack again!\n\n"+NORM);
                        User->set_spell_dam(0);
                }
        }

        
        switch(ranhammer){
                case 0..1:
                       if(PO->query_lhammer() < 500){
                               PO->add_lhammer(1);
                        }
                break;
                case 3..4:
                        if(PO->query_lhammer() < 500){
                               PO->add_lhammer(2);
                        }
                break;
                default:
                        if(PO->query_lhammer() < 500){
                               PO->add_lhammer(3);
                        }
                break;
        }
                
        return 1;
}
