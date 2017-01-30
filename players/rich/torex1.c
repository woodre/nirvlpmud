id(str)
{
if ( str == "75" || str == "photon torpedo key" || str == "key" ) return 1;
return 0;
}

short()
{
return "A photon torpedo key";
}

long()
{
write( "This is a photon torpedo key,it is a VERY powerful object.\n");
write( "Aren't you lucky!\n" );
write( "To use the torpedo key type `target player name'\n");
}

query_value() { return 5000; }


get() { return 1; }

query_weight() { return 3; }

init() {
    add_action("target", "target");
}

target(str) {
string me,target;
int hp,dam,damage;
    object ob,play;

/*
    sscanf( str, "%s %s", me,target );
    if ( !id( me ) ) return 0;
*/
/*
    if ( onword != "on" )
      {
      write( "target torpedo on something.\n" );
      return 0;
      }
*/
    if ( str == 0 )
      {
      write ( "You must target SOMETHING.\n" );
      return 0;
      }
    ob = find_player( str );
     if (ob== 0){
      write("Nothing by that name is functioning at this time.\n");
      return 1;
     }
    play=call_other(this_player(),"query_name");
/*
    write( call_other( ob, "query_name", 0 ) + "\n");
    write("Level:\t" + call_other( ob, "query_level", 0) + "\n");
    write("MAX HP:\t" + call_other( ob, "query_max_hp", 0) + "\n");
   write( "AC:\t" + call_other(  ob, "query_ac", 0  ) + "\n");
    write("WC:\t" + call_other(  ob, "query_wc", 0 ) + "\n");
*/
    hp=call_other(ob,"query_hp",0);
    damage = 3*hp/4;
    write("The torpedo locks on its target,your key glows brightly,\n");
    write("You hear the torpedo begin its launch sequence\n");
    tell_object(ob,"You get the feeling that something has locked onto you.\n");
    call_out("timeout",10);
    shout("You hear a boom from the direction of the Enterprise.\n");
    tell_object(ob,"You get a feeling of dread at this sound like if you`re fighting\n");
    tell_object(ob,"you had better get out of battle QUICK!!!!\n");
    call_out("timeout",17);
    shout("You see a torpedo fly over your head.\n");
    tell_object(ob,"But you see the torpedo loop back and head in your direction.\n");
    call_out("timeout",17);
    shout("You see a cloud of debris fly into the air as the photon torpedo...\n");
    shout("EXPLODES on its target!!!\n");
   if (present("ttoy",ob)) {
      object sh;
         sh=(present("ttoy",ob));
       write("Unfortunately that player was wearing a Torpedo Shield,\n");
       write("and the torpedo bounced off.However in the process the shield\n");
       write("was destroyed.\n");
       destruct(sh);
       tell_object(ob,"You were the Target but your shield protected you \n");
       tell_object(ob,"from damage.However the shield was destroyed so you might\n");
       tell_object(ob," want to think about getting a replacement.\n");
       destruct(this_object());
       return 0;
     }
    tell_object(ob,"unfortunately that target was you,you might want to check your score.\n");
    tell_object(ob,"You were hit by ");
    tell_object(ob,play);
    tell_object(ob,"\n");
call_other(ob,"hit_player",damage);
destruct(present("75",this_player()));
log_file("TORPEDO",this_player()->query_real_name() + " torpedoed " + ob->query_real_name());
log_file("TORPEDO","\n");
 
    return 1;
}

reset(arg) {}
