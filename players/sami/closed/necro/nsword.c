inherit "obj/weapon.c";
#define tp this_player()->query_name()
#include "/sys/lib.h"
#include <ansi.h>
int light;
int bladesharp;
int energize;
int moonglow;
int MAGIC;
int w;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("necro sword");
  set_alias("bonecleaver");
  set_type("sword");
  set_short(BOLD+"Bonecleaver"+NORM+", the"+HIW+" Legendary "+HIK+"Necromancer"+HIR+" Longsword"+NORM);
  set_long("A large sword Forged from "+RED+"blood"+NORM+" and "+BOLD+"bone"+NORM+". An Ancient\n"+
          "necromancer once forged this blade in the dark flames; comprised.\n"+
          "of the very essences of his opponents; Blood, Spine, Soul, Heart.\n");
  set_class(18);
  set_weight(2);
  set_value(5000);
  set_hit_func(this_object());
}
              powers() {
  write("**********~~~~~~~~~P O W E R S~~~~~~~~~~~~~~~**********\n");
  write(""+BOLD+MAG+"bladesharp"+NORM+"         50sp\n"+
        ""+BOLD+BLU+"lightning"+NORM+"           10sp\n");
	
  write("**********~~~~~~~~~P O W E R S~~~~~~~~~~~~~~~~**********\n");
return 1; }
        
        lightning_hit(attacker){
                int i;
                if(energize != 1){
                        return 0;
                }
                
                i = random(14);
                if(i<5){
                        tell_room(environment(this_player()),
                                "\n\n"+
                        HIR+BLINK+" B L O O D L U S T"+NORM+" consumes the blade.\n\n");
                        return 2;
                }
                
        }
        init(){
                ::init();
                add_action("LIGHTNING","lightning");
                add_action("bladesharp","bladesharp");
				add_action("powers","powers");
        }
        
        check_wielded(){
                if(this_player()->query_weapon() == this_object()){
                        return 1;
                }
                else {
                        notify_fail(BOLD+"You must be wielding the sword to use its powers.\n"+NORM);
                        return 0;
        }}
        
        check_magic(){
                int i;
                i = this_player()->query_attrib("int");
                if(i > 20) i = 20;
                if(i < 0) i = 0;
                return i;
        }
        
        bladesharp(){
                int time;
                MAGIC = check_magic();
                if(check_wielded() == 0) return 0;
                if(this_player()->query_spell_point() < 50){
                        notify_fail(BOLD+"You lack the energy to charge the sword.\n"+NORM);
                        return 0;
                }
                
                this_player()->add_spell_point(-50);
                energize = 1;
                get_short();
                time = ((500+random(500))*MAGIC)/20;
                call_out("remove_energy",time);
                write("\nYou invoke the bladesharp matrix.\n\n"+
                "        "+CYN+BLINK+"E N E R G Y "+NORM+"flows over your blade.\n\n");
                return 1;
        }
        
        remove_energy(){
                write("The sword's glow fades.\n");
                say("The glow from the sword fades.\n");
                energize = 0;
                get_short();
                return 1;
        }
		LIGHTNING(){
                int time;
                MAGIC = check_magic();
                if(check_wielded() == 0) return 0;
                if(this_player()->query_sp() < 10){
                        notify_fail("You lack energy to use this power.\n");
                        return 0;
                }
                
                this_player()->add_spell_point(-10);
                write("Lightning flows over the bastard sword\n");
                say("Lightning leaps over the blade.\n");
                time = (1200*MAGIC)/20;
                call_out("light_stop",time);
                light = 1;
                get_short();
                return 1;
        }
        
        light_stop(){
                write("The "+BOLD+BLU+BLINK+"Lightning"+NORM+" dissipates from the blade.\n");
                say("The "+BOLD+BLU+BLINK+"Lightning"+NORM+" disapates of the blade.\n");
                light = 0;
                get_short();
        }
        
        get_short(){
                string str;
                str = ""BOLD+"Bonecleaver"+NORM+", the"+HIW+" Legendary "+HIK+"Necromancer"+HIR+" Longsword"+NORM"";
                
                if(light == 1){
                        str += ""+NORM+BOLD+"  ("+BOLD+BLU+" Lightning Charged "+NORM+BOLD+")"+NORM+"";
                }
                
                if(energize == 1){
                        str += ""+CYN+" [ "+HIR+" BLOODLUST "+CYN+" ]"+NORM+"";
                        
                }
                set_short(str);
        }
weapon_hit(attacker){
  if(call_other(this_player(), "query_attrib", "wil") > random (50)) {
    write("The sword "+BOLD+"vibrates"+NORM+" violently as it "+HIY+"cleaves"+NORM+" into " +attacker->query_name()+".\n"+RED+"\
ssssss      ll       IIIII     CCCCCCC    EEEEEE !!!\n\
ss          ll        III     CCC         E      !!!\n\
ssssss      ll        III     CCC         EEEEEE !!!\n\
    ss      ll        III     CCC         E      !!!\n\
ssssss      lllll    IIIII     CCCCCCC    EEEEEE !!!\n"+NORM);
    say("The sword "+BOLD+"vibrates"+NORM+" violently as it "+HIY+"cleaves"+NORM+" into " +attacker->query_name()+".\n"+NORM);
say(""+RED+"ssssss      ll       IIIII     CCCCCCC    EEEEEE !!!\n"+NORM);
say(""+RED+"ss          ll        III     CCC         E      !!!\n"+NORM);
say(""+RED+"ssssss      ll        III     CCC         EEEEEE !!!\n"+NORM);
say(""+RED+"    ss      ll        III     CCC         E      !!!\n"+NORM);
say(""+RED+"ssssss      lllll    IIIII     CCCCCCC    EEEEEE !!!\n"+NORM);
    if(attacker->query_hp() > 13) 
      attacker->hit_player(13,"magical");
    return 7;
  }
  return;
}
