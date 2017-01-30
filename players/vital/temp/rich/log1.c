id(str)
{
if ( str == "log" || str == "captain`s log" || str == "captain" ) return 1;
return 0;
}

short()
{
return "The Captain`s Log";
}

long()
{
write("This is the Captain`s Log if you are not authorized to use this...\n");
write("it would be a VERY good idea not to use it.\n");
}

query_value() { return 5000; }


get () {
if (call_other(this_player(),"query_level")<=21) {
write("Only a wizard may pick up the captain`s log,\n");
 return 0;
 }
return 1;

}
query_weight() { return 3; }

init() {
  if (call_other(this_player(), "query_level")>=21) {
    add_action("target", "target");
    add_action("drop", "drop");
    add_action("zap","zap");
    add_action("phaser", "phaser");
    add_action("trace", "trace");
    add_action("trans", "trans");
    add_action("force", "force");
    add_action("torpedo","torpedo");
    add_action("heal", "heal");
   add_action("beam", "beam");
}
 }

target(str) {
string me,target;
int hp,dam,damage;
    object ob;

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
/*
    write( call_other( ob, "query_name", 0 ) + "\n");
    write("Level:\t" + call_other( ob, "query_level", 0) + "\n");
    write("MAX HP:\t" + call_other( ob, "query_max_hp", 0) + "\n");
   write( "AC:\t" + call_other(  ob, "query_ac", 0  ) + "\n");
    write("WC:\t" + call_other(  ob, "query_wc", 0 ) + "\n");
*/
    hp=call_other(ob,"query_hp",0);
    dam = 3*hp;
    damage = dam/4;
    write("The torpedo locks on its target,your key glows brightly,\n");
    write("You hear the torpedo begin its launch sequence\n");
    tell_object(ob,"You get the feeling that something has locked onto you.\n");
    call_out("timeout",3);
    tell_object(ob,"You hear a boom from the direction of the Enterprise.\n");
    tell_object(ob,"You get a feeling of dread at this sound like if you`re fighting\n");
    tell_object(ob,"you had better get out of battle QUICK!!!!\n");
    call_out("timeout",7);
    tell_object(ob,"You see a torpedo fly over your head.\n");
    tell_object(ob,"But you see the torpedo loop back and head in your direction.\n");
    call_out("timeout",7);
    tell_object(ob,"You see a cloud of debris fly into the air as the photon torpedo...\n");
    tell_object(ob,"EXPLODES on its target!!!\n");
    tell_object(ob,"unfortunately that target was you,you might want to check your score.\n");
call_other(ob,"hit_player",damage);
 
    return 1;
}

drop(str) {
 if (str=="log"  || str =="all" ) {
   destruct(this_object());
  }
 return 1;
 }
zap(str) {
  object liv;
   liv=find_living(str);
    if(liv==0) {
      write("No such person is functioning at this time.\n");
      return 1;
      }
   tell_object(liv,"You see a phaser beam lance across the sky.\n");
   tell_object(liv,"You hear an immense crash as the phaser strike hits its target!!!\n");
   tell_object(liv,"Unfortunately you were the target.\n");
   call_other(liv,"hit_player",100000);
   write("zap done.\n");
   return 1;
 }
phaser(str) {
  object liv;
   liv=find_living(str);
    if(liv==0) {
      write("No such person is functioning at this time.\n");
      return 1;
     }
tell_object(liv,"You see a phaser beam lance across the sky.\n");
tell_object(liv,"You hear a rumble as the phaser strike DESTROYS its target!!!!\n");
tell_object(liv,"Unfortunately you were the target.\n");
destruct(liv);
write(str + " is destroyed.\n");
return 1;
}
trace(str) {
  object ob;
    ob=find_living(str);
   if(ob==0) {
     write("Nothing buy that name is currently functioning.\n");
     return 1;
     }
    write(ob);
    write("\n");
 return 1;
 }
trans(str) {
  object ob;
    ob=find_living(str);
      if(ob==0) {
        write("Nothing by that name is currently functioning.\n");
        return 1;
      }
  tell_object(ob,"You get a strange feeling in your stomach.\n");
  tell_object(ob,"You feel as if your body is splitting into a million pieces.\n");
  tell_object(ob,"You have been beamed up by rich.\n");
  tell_object(ob,"You rematerialize.\n");
  say(str + " disappears in a blinding flash of light and sound.\n");
  move_object(ob,environment(this_player()));
  return 1;
 }
heal(str) {
  object ob;
   ob=find_living(str);
    if (ob==0) {
     write("Nothing buy that name is currently functioning.\n");
     return 1;
     }
  call_other(ob,"add_hit_point",100000);
  return 1;
}
force(str) {
 string me,target;
  object ob;
    sscanf(str, "%s %s",me,target);
     ob=find_living(me);
/*
      if(ob==0) {
       write("Nothing by that name is currently functioning.\n");
       return 1;
       }
*/
    call_other(ob,"force_us",target);
    write("You forced " + me + " to " + target + "\n");
    return 1;
  }
beam(str) {
   object liv;
      liv=find_living(str);
       if(liv==0) {
         write("Nothing by that name is currently functioning.\n");
         return 1;
        }
      tell_object(liv,"You have a strange feeling....\n");
      tell_object(liv,"You see your body from above....\n");
      tell_object(liv,"You have been beamed out by rich.\n");
      tell_object(liv,"You rematerialize.\n");
      move_object(liv,"players/rich/lower/atrans.c");
      return 1;
   }
reset(arg) {}
