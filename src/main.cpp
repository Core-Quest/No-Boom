#include "main.hpp"
#include "GlobalNamespace/BombExplosionEffect.hpp"

using namespace GlobalNamespace;

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

void write_info(FILE* fp, std::string str) {
    getLogger().debug("%s", str.data());
    fwrite((str + "\n").data(), str.length() + 1, 1, fp);
}




MAKE_HOOK_MATCH(
    BombExplosionEffect_SpawnExplosion, 
    &GlobalNamespace::BombExplosionEffect::SpawnExplosion, 
    void, GlobalNamespace::BombExplosionEffect* self, 
    UnityEngine::Vector3 pos
) {
    
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load(); // Load the config file
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing hooks...");

    INSTALL_HOOK(getLogger(), BombExplosionEffect_SpawnExplosion);
    // Install our hooks (none defined yet)
    getLogger().info("Installed all hooks!");
}