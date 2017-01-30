inherit "players/mizan/closed/RandomRoom.c";
#define MASTER_R "/players/mizan/closed/DescMasterDM.c"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc=MASTER_R->build_description();
}

extra_reset() {
  object_names=MASTER_R->build_object_list();

  object_names += ({ "players/mizan/etheriel/environs/steamroller.c", });

  ::extra_reset();
}
