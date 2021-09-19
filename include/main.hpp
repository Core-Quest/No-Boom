#pragma once



#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "modloader/shared/modloader.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp" 
#include "beatsaber-hook/shared/utils/typedefs.h"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

// Define these functions here so that we can easily read configuration and log information from other files
Configuration& getConfig();
Logger& getLogger();