inherit "obj/weapon";
int count, wait, no_hit;
init() {
   add_action("add","add");
   add_action("shoot","shoot");
   add_action("help","help");
   ::init();
}
reset(arg) {
::reset(arg);
   if(arg) return;
   count=10;
   wait=5;
   no_hit = time();
   set_name("A Cartoon Gun");
   set_short("A Cartoon Gun");
   set_long("This is a gun from one of those saturday morning cartoons.\n"
            +"Type HELP GUN for more info on it.\n");
   set_class(13);
   set_alias("gun");
   set_weight(3);
   set_value(1000);
}

shoot(str)  {
  object ob;
  if (!str && !this_player()->query_attack()) {
    write("Shoot who?\n");
    return 1;
   } else
   if (!this_player()->query_attack() && !present(str,environment(this_player()))) {
      write("That is not here!\n");
      return 1;
    } else {
  if(!str) ob = this_player()->query_attack();
  else
        ob = present(str,environment(this_player()));
  if(!this_player()->valid_attack(ob)) write("Cant do it man\n");
  else {
     if (count>0) {
        weapon_hit(ob);
       }
     else
       { write("The Cartoon Gun is out of bullets.\n"); }
  }
   return 1;
 }
  }

weapon_hit(str) {
if (no_hit>=time()) {
  write("The Gun is cooling down.\n");
 } else {
  say(this_player()->query_name()+" shoots "+
  capitalize(str->query_name())+".\n");
  write("You shoot "+capitalize(str->query_name())+" in the butt.\n");
  no_hit = wait + time();
   if(present(str,environment(this_player()))) str->hit_player(5);
  count--;
  }
  return 1;
  }

help(str) {
  if (str=="gun" || str=="cartoon gun" || str=="cartoon") {
write("This is a gun from one of those saturday morning cartoons.\n"+
"To use it you need to SHOOT <Target>.  Of course it has bullets so\n"+
"when you are out you will need to ADD BULLETS (after you find some).\n");
    return 1;
  }
}

bullet(str) {
  object bullet;
  bullet = first_inventory(this_player());
  while (bullet) {
    if (call_other(bullet,"id",str)) return bullet;
    bullet = next_inventory(bullet);
  }
  return 0;
}

add(str) {
  object bull;
  if (str=="bullet") {
     bull = bullet(str);
     if (bull) {
     if (count<10) {
       count++;
       destruct(bull);
       write("You put a new bullet in the gun.\n");
     } else {
      write("The gun is full of bullets.\n");
    }
   } else {
     write("You don't have any bullets.\n");
   }
  } else {
    write("What do you want to add?\n");
   }
  return 1;
}
