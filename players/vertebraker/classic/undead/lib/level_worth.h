int level_worth(int level, int extra_level, int guild_level) {
  return (level / 2 + extra_level / 5 + guild_level * 2);
}
