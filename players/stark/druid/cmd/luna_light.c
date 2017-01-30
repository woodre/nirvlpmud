/* if you're using a standard guild object with functions all
   in it, this stuff goes right smack in it */

#define SHADOW "/players/stark/druid/obj/luna_light.c"

int luna_light_on;

status luna_light(string str)
{
    object shadow;
    if(str) return 0;
    if(luna_light_on)
    {
      notify_fail("You are currently enjoying the powers of this spell...\n");
      return 0;
    }
    write("You cast a spell of Light...\n");
    tell_room(environment(this_player()),
     (string)this_player()->query_name() + " casts a spell of Light...\n", ({ this_player() }));
    shadow = clone_object(SHADOW);
    shadow->start_shadow(this_player());
    luna_light_on = 1;
    return 1;
}

mixed luna_light_on(int x)
{
    if(!x) return luna_light_on;
    luna_light_on = x;
}
