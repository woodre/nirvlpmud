/*
 * darken command for the Shardak guild (renew guild object)
 * by Dragnar and Balowski
 * verte updated the boring message
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
inherit CMD;

status
main()
{
    object      scar,
                drag, track, dragon;    /* old values saved */

    write("You extend your right hand in front of you and hold it out.\n"+
          "You cut deeply into the Mark... until blood flows...\n"+
          "Tracing the edge of the Mark with your blood, you feel\n"+
          "Shardak's unholy smile befall you from afar.\n");
    say(this_player()->query_name() +" extends "+ possessive(this_player())
         + " right hand in front of "+ objective(this_player()) +" and holds it out.\n"+
         "Digging deeply, cutting into the Mark, "+ subjective(this_player()) 
         +" drips blood openly.\n");
    drag = (object) previous_object()->Drag();
    track = (object) previous_object()->Track();
    dragon = (object) previous_object()->Dragon();
    previous_object()->remove();
    destruct(previous_object());
    scar = clone_object(GUILDOBJ);
    scar->Drag(drag);
    scar->Track(track);
    scar->Dragon(dragon);
    move_object(scar, this_player());
    return 1;
}
