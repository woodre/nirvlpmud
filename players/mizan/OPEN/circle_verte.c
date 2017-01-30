/* Circle of Flame Shadow by Vertebraker */

#pragma weak_types
#include "/players/vertebraker/ansi.h"

#define DAMAGE (5 + random(5))
#define TIME (200 + random(20))
#define QN query_name()

object shadowee;

void reset(int arg)
{
    if(arg) return;
    call_out("destruct_me", TIME);
}

void start_shadow(object ob)
{
    shadowee = ob;
    shadow(shadowee,1);
}

void end_shadow()
{
    shadow(shadowee, 0);
    shadowee = 0;
    destruct(this_object());
}

string short()
{
    return (string)shadowee->short() + RED + " (Encircled in Flame)"+NORM;
}

hit_player(stuff, stuff2, stuff3, stuff4)
{
    int          z;
    object       opponent;
    string       race, x, msg;

    opponent = previous_object();
      
    shadowee->hit_player(stuff, stuff2, stuff3, stuff4);
    if(shadowee)
    if(shadowee->query_ghost()) { end_shadow(); return; }
    if(!opponent) return;
    if(!shadowee || !environment(shadowee)) return;
    if(!present(opponent, environment(shadowee))) return;

    
    if(!random(3))
    {
      if(0 == random(3)) 
        msg = "Flames launch from around "+shadowee->QN+"...\n";
      else if(0 == random(3))
        msg = "Dark withering blasts of flame erupt around "+shadowee->QN+"...\n";
      else if(0 == random(3))
        msg = "Waves of flame roll over the area...\n";
      else if(0 == random(3))
        msg = "An explosion of flames erupts around "+shadowee->QN+"...\n";
      else msg = "Fire explodes all around you...\n";
      tell_room(environment(shadowee),RED+"\t"+msg+NORM);
       opponent->hit_player(DAMAGE, "other|fire");
    }
}

void destruct_me()
{
    if(!shadowee) return;
    tell_object(shadowee, RED+"\
The flames wrapped around you die down slowly...\n\
Finally they fade without a trace.\n"+NORM);
    if(!environment(shadowee)) return;
    tell_room(environment(shadowee), RED + "\
The flames wrapped around " + (string)shadowee->query_name() + 
" die down slowly...\n\
Finally they fade without a trace.\n" + NORM, ({ shadowee }));
    end_shadow();
    destruct(this_object());
}

status encircled_with_flame() { return 1; }
