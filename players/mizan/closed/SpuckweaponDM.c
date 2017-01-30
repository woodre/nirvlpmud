/* SpuckweaponDM.c [Version 1.1]
 *
 * Counts up total damage done by bonus hits of weapons used by
 * players. Good for determining whether or not the values used
 * in extra returns are legal/fair.
 *
 */

#define HOME "/players/mizan/core/02h/room04.c"
#define STATFILE "players/mizan/closed/SpuckStats"

int sb_pistol_dam;
int sb_pistol_rounds;
int sb_rifle_dam;
int sb_rifle_rounds;
int sb_shotgun_dam;
int sb_shotgun_rounds;
int sb_cannon_dam;
int sb_cannon_rounds;
int sb_blaster_dam;
int sb_blaster_rounds;
int sb_minigun_dam;
int sb_minigun_rounds;
int sb_flexgun_dam;
int sb_flexgun_rounds;
int sb_sg_dam;
int sb_sg_rounds;
int sb_sg_power;
int sb_sg_load_avg;

reset(arg) {
  move_object(this_object(), HOME);
  if(!arg) restore_object(STATFILE);
  else save_object(STATFILE);
}

id(str) { return str == "counter"; }

short() {
  return "The Spuckweapon bonus damage counter [Version 1.1]";
}

long() {

    if(this_player()->query_level() < 20)
    {
        write("You see nothing special.\n");
        return 1;
    }

  write("This is a funky looking thing that looks like a paperweight.\n"+
  "A series of numbers are written on it, and they seem to have no\n"+
  "importance whatsoever.\n");
  write("Weapon type\tDam [t]\tRds [t]\tD/Rds\tAvg setting\n");
  write(">>------------------------------------------------<<\n");
  if(sb_pistol_rounds) { 
    write("pistol\t\t" + sb_pistol_dam + "\t" + sb_pistol_rounds + "\t[" +
    (sb_pistol_dam / sb_pistol_rounds) + "]\t-\n");
  }   
  if(sb_rifle_rounds) { 
    write("rifle\t\t" + sb_rifle_dam + "\t" + sb_rifle_rounds + "\t[" +
    (sb_rifle_dam / sb_rifle_rounds) + "]\t-\n");
  }   
  if(sb_shotgun_rounds) { 
    write("shotgun\t\t" + sb_shotgun_dam + "\t" + sb_shotgun_rounds + "\t[" +
    (sb_shotgun_dam / sb_shotgun_rounds) + "]\t-\n");
  }   
  if(sb_cannon_rounds) { 
    write("cannon\t\t" + sb_cannon_dam + "\t" + sb_cannon_rounds + "\t[" +
    (sb_cannon_dam / sb_cannon_rounds) + "]\t-\n");
  }   
  if(sb_blaster_rounds) { 
    write("blaster\t\t" + sb_blaster_dam + "\t" + sb_blaster_rounds + "\t[" +
    (sb_blaster_dam / sb_blaster_rounds) + "]\t-\n");
  }   
  if(sb_minigun_rounds) { 
    write("minigun\t\t" + sb_minigun_dam + "\t" + sb_minigun_rounds + "\t[" +
    (sb_minigun_dam / sb_minigun_rounds) + "]\t-\n");
  }   
  if(sb_flexgun_rounds) { 
    write("flexgun\t\t" + sb_flexgun_dam + "\t" + sb_flexgun_rounds + "\t[" +
    (sb_flexgun_dam / sb_flexgun_rounds) + "]\t-\n");
  }   
  if(sb_sg_rounds) { 
    write("supergun\t\t" + sb_sg_dam + "\t" + sb_sg_rounds + "\t[" +
    (sb_sg_dam / sb_sg_rounds) + "]\t" + sb_sg_power + "\n");
  }   
  write(">>------------------------------------------------<<\n");
}

reg_pistol_hit(arg) {
  sb_pistol_dam = sb_pistol_dam + arg;
  sb_pistol_rounds = sb_pistol_rounds + 1;
  return 1;
}

reg_rifle_hit(arg) {
  sb_rifle_dam = sb_rifle_dam + arg;
  sb_rifle_rounds = sb_rifle_rounds + 1;
  return 1;
}

reg_cannon_hit(arg) {
  sb_cannon_dam = sb_cannon_dam + arg;
  sb_cannon_rounds = sb_cannon_rounds + 1;
  return 1;
}

reg_blaster_hit(arg) {
  sb_blaster_dam = sb_blaster_dam + arg;
  sb_blaster_rounds = sb_blaster_rounds + 1;
  return 1;
}

reg_shotgun_hit(arg) {
  sb_shotgun_dam = sb_shotgun_dam + arg;
  sb_shotgun_rounds = sb_shotgun_rounds + 1;
  return 1;
}

reg_minigun_hit(arg) {
  sb_minigun_dam = sb_minigun_dam + arg;
  sb_minigun_rounds = sb_minigun_rounds + 1;
  return 1;
}

reg_flexgun_hit(arg) {
  sb_flexgun_dam = sb_flexgun_dam + arg;
  sb_flexgun_rounds = sb_flexgun_rounds + 1;
  return 1;
}

reg_supergun_hit(arg) {
  sb_sg_dam = sb_sg_dam + arg;
  sb_sg_rounds = sb_sg_rounds + 1;
  return 1;
}

add_supergun_avg(arg) {
  sb_sg_power = sb_sg_power + arg;
  sb_sg_load_avg = sb_sg_load_avg / sb_sg_power;
}
